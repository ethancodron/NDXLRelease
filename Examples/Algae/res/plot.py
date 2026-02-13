import matplotlib.pyplot as plt
import numpy as np
import re
import os

os.makedirs("dists", exist_ok=True)
datfile = open("dist.csv", 'r')
data = [re.sub("[\\r\\n]+", "", f) for f in datfile.readlines()]
datfile.close()
data = data[1:]
bins = [0.1 * i for i in range(64)]
fig, ax = plt.subplots(2, 4, sharex=True, sharey=True, figsize=(16, 8))
i, j = 0, 0

for line in data:
	time, *counts = line.split(',')
	if time in ("28.8", "29.2", "29.6", "29.9", "30.3", "30.7", "31.1", "31.4"):
		counts = [float(cnt) for cnt in counts]
		ax[i][j].bar(bins, counts, width=np.diff(bins)[0], align='edge', label="$t=" + str(time) + "~{\\rm d}$")
		ax[i][j].legend(loc="upper right")
		j += 1
		if j == 4:
			j = 0
			i += 1

fig.supxlabel("Phase, $\\theta$", x=0.5135, y=0.03, ha='center', va='center', fontsize=18)
fig.supylabel("Distribution, $p(\\theta,~t)$", x=0.015, y=0.525, ha='center', va='center', fontsize=18)
fig.tight_layout()
plt.show()