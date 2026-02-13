# Massie et al. full PDE with correct division boundary condition
# ---------------------------------------------------------------
# Implements:
#   - Non-periodic boundary
#   - Division flux: J(0) = nu * J(2π)
#   - 3rd order upwind (interior)
#   - 2nd order central diffusion (interior)
#   - Constant diffusion (as in main script)
#   - BDF time integration

import numpy as np
from scipy.integrate import solve_ivp
import matplotlib.pyplot as plt

# -----------------------------
# PARAMETERS
# -----------------------------

nu = 4
theta0 = 0.1 * np.pi
thetac = 0.9 * np.pi
chi = 0.018
K_N = 350
omega = 5.88 * np.pi
nu_m = 1.74e-4
delta = 0.81
N_i = 160

# Grid
Ngrid = 200
L = 2*np.pi
theta = np.linspace(0, L, Ngrid, endpoint=False)
dtheta = theta[1] - theta[0]

# -----------------------------
# Switching functions (exact logistic form)
# -----------------------------

def F(theta, center):
	return 1.0 / (1.0 + np.exp((theta - center)/(0.02*np.pi)))

def g(theta, N):
	term1 = omega * (1 - N/(K_N + N)) * (1 + F(theta, theta0) - F(theta, thetac))
	term2 = omega * N/(K_N + N)
	return term1 + term2

# -----------------------------
# RHS system
# -----------------------------

def rhs(t, state):
	delta = 0.81 if (t < 20. or t > 25.) else 0.
	p = state[:-1]
	Nval = state[-1]

	vel = g(theta, Nval)
	D = chi * vel * vel
	dpdt = np.zeros_like(p)
	dpdt[0] = (p[1] - p[0]) / dtheta
	dpdt[-1] = (p[1] - p[-2]) / dtheta
	dpdt[1:-1] = (p[2:] - p[:-2]) / (2. * dtheta)
	Ddpdt = D * dpdt
	gp = vel * p
	J = gp - Ddpdt
	J[0] = nu * J[-1]

	pout = np.zeros_like(p)
	pout[1:-1] = -(J[2:] - J[:-2]) / (2. * dtheta) - delta * p[1:-1]
	pout[0] = -(J[1] - J[0]) / dtheta - delta * p[0]
	pout[-1] = -(J[-1] - J[-2]) / dtheta - delta * p[-1]

	# Nutrient equation
	P = np.trapz(p, theta)
	dNdt = delta * (N_i - Nval) - nu_m * Nval / (K_N + Nval) * P

	return np.concatenate([pout, [dNdt]])

# -----------------------------
# Initial conditions
# -----------------------------

p0 = np.ones(Ngrid) / (2*np.pi)
state0 = np.concatenate([p0, [0.]])

# -----------------------------
# Integrate
# -----------------------------

samples = (28.8, 29.2, 29.6, 29.9, 30.3, 30.7, 31.1, 31.4)

sol = solve_ivp(
	rhs,
	(0., 32.),
	state0,
	method="BDF",
	rtol=1e-10,
	atol=1e-10,
	max_step=8.615746908e-3,
	t_eval=samples
)

p_final = sol.y[:-1, -1]
N_final = sol.y[-1, -1]

print("Final nutrient:", N_final)
print("Total biomass P:", np.trapz(p_final, theta))
print("Minimum p:", p_final.min())

# -----------------------------
# Plot Distributions
# -----------------------------

fig, ax = plt.subplots(2, 4, sharex=True, sharey=True, figsize=(16, 8))
ax[0][0].plot(theta, sol.y[:-1, 0], label="$t=28.8~{\\rm d}$")
ax[0][0].legend(loc="upper right")
ax[0][1].plot(theta, sol.y[:-1, 1], label="$t=29.2~{\\rm d}$")
ax[0][1].legend(loc="upper right")
ax[0][2].plot(theta, sol.y[:-1, 2], label="$t=29.6~{\\rm d}$")
ax[0][2].legend(loc="upper right")
ax[0][3].plot(theta, sol.y[:-1, 3], label="$t=29.9~{\\rm d}$")
ax[0][3].legend(loc="upper right")
ax[1][0].plot(theta, sol.y[:-1, 4], label="$t=30.3~{\\rm d}$")
ax[1][0].legend(loc="upper right")
ax[1][1].plot(theta, sol.y[:-1, 5], label="$t=30.7~{\\rm d}$")
ax[1][1].legend(loc="upper right")
ax[1][2].plot(theta, sol.y[:-1, 6], label="$t=31.1~{\\rm d}$")
ax[1][2].legend(loc="upper right")
ax[1][3].plot(theta, sol.y[:-1, 7], label="$t=31.4~{\\rm d}$")
ax[1][3].legend(loc="upper right")
fig.supxlabel("Phase, $\\theta$", x=0.5135, y=0.03, ha='center', va='center')
fig.supylabel("Distribution, $p(\\theta,~t)$", x=0.015, y=0.525, ha='center', va='center')
fig.tight_layout()
plt.show()