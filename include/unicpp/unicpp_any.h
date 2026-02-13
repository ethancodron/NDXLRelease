//--------------------------------------\\
// C++ version-independent any storage	\\
// Ethan Codron 2025					\\
// GNU GPL-3.0							\\
//--------------------------------------\\
// Header file providing any class for	\\
// all versions of C++.					\\
//--------------------------------------\\

#ifndef _UNICPP_ANY_
#define _UNICPP_ANY_

#include "unicpp_core.h"

#ifdef __cplusplus

#include <functional>
#include <memory>
#include <utility>

class any
{
protected:
	class _Any_storage
	{
	public:
		template <typename _Ty>
		inline constexpr _Any_storage(const _Ty& _Val) noexcept
		{
			this->_My_val = new _Ty();
			*(_Ty*)(this->_My_val) = _Val;
			this->_CopyFn = [this](void** _Ptr) { *_Ptr = new _Ty(); *(_Ty*)*_Ptr = *(_Ty*)(this->_My_val); };
			this->_MoveFn = [this](void** _Ptr) { *_Ptr = this->_My_val; this->_My_val = nullptr; };
			this->_DestroyFn = [this]() { (*(_Ty*)(this->_My_val)).~_Ty(); };
		}

		template <typename _Ty>
		inline constexpr _Any_storage(_Ty&& _Val) noexcept
		{
			this->_My_val = new _Ty();
			*(_Ty*)(this->_My_val) = std::move(_Val);
			this->_CopyFn = [this](void** _Ptr) { *_Ptr = new _Ty(); *(_Ty*)*_Ptr = *(_Ty*)(this->_My_val); };
			this->_MoveFn = [this](void** _Ptr) { *_Ptr = this->_My_val; this->_My_val = nullptr; };
			this->_DestroyFn = [this]() { (*(_Ty*)(this->_My_val)).~_Ty(); };
		}

		inline _Any_storage(const _Any_storage& _Other) noexcept
		{
			_Other._CopyFn(&this->_My_val);
			this->_CopyFn = _Other._CopyFn;
			this->_MoveFn = _Other._MoveFn;
			this->_DestroyFn = _Other._DestroyFn;
		}

		inline _Any_storage(_Any_storage&& _Other) noexcept
		{
			_Other._MoveFn(&this->_My_val);
			this->_CopyFn = std::move(_Other._CopyFn);
			this->_MoveFn = std::move(_Other._MoveFn);
			this->_DestroyFn = std::move(_Other._DestroyFn);
		}

		inline _Any_storage() noexcept : _My_val(nullptr) {}
		inline ~_Any_storage() noexcept { this->clear(); }

	private:
		void* _My_val;
		std::function<void(void**)> _CopyFn;
		std::function<void(void**)> _MoveFn;
		std::function<void()> _DestroyFn;

	public:
		inline _Any_storage& clear() noexcept
		{
			if (this->_My_val)
			{
				this->_DestroyFn();
				free(this->_My_val);
				this->_My_val = nullptr;
			}
			return *this;
		}

		template <typename _Ty>
		inline constexpr _Ty& value() const noexcept { return *(_Ty*)(this->_My_val); }

		template <typename _Ty>
		inline constexpr _Any_storage& operator=(const _Ty& _Val) noexcept
		{
			this->clear();
			this->_My_val = new _Ty();
			*(_Ty*)(this->_My_val) = _Val;
			this->_DestroyFn = [this]() { (*(_Ty*)(this->_My_val)).~_Ty(); };
			return *this;
		}

		template <typename _Ty>
		inline constexpr _Any_storage& operator=(_Ty&& _Val) noexcept
		{
			this->clear();
			this->_My_val = new _Ty();
			*(_Ty*)(this->_My_val) = std::move(_Val);
			this->_DestroyFn = [this]() { (*(_Ty*)(this->_My_val)).~_Ty(); };
			return *this;
		}

		inline _Any_storage& operator=(const _Any_storage& _Other) noexcept
		{
			this->clear();
			_Other._CopyFn(&this->_My_val);
			this->_CopyFn = _Other._CopyFn;
			this->_MoveFn = _Other._MoveFn;
			this->_DestroyFn = _Other._DestroyFn;
			return *this;
		}

		inline _Any_storage& operator=(_Any_storage&& _Other) noexcept
		{
			this->clear();
			_Other._MoveFn(&this->_My_val);
			this->_CopyFn = std::move(_Other._CopyFn);
			this->_MoveFn = std::move(_Other._MoveFn);
			this->_DestroyFn = std::move(_Other._DestroyFn);
			return *this;
		}
	};

public:
	template <typename _Ty, std::enable_if_t<!std::is_same_v<_Ty, any>, bool> = false>
	inline constexpr any(const _Ty& _Val) noexcept : _My_storage(_Val) {}

	template <typename _Ty, std::enable_if_t<!std::is_same_v<_Ty, any&>, bool> = false>
	inline constexpr any(_Ty&& _Val) noexcept : _My_storage(std::move(_Val)) {}

	inline any(const any& _Other) noexcept : _My_storage(_Other._My_storage) {}
	inline any(any&& _Other) noexcept : _My_storage(std::move(_Other._My_storage)) {}

	inline any() noexcept {}
	inline ~any() noexcept { this->_My_storage.~_Any_storage(); }

protected:
	_Any_storage _My_storage;

public:
	template <typename _Ty>
	inline constexpr operator _Ty& () const noexcept { return this->_My_storage.value<_Ty>(); }

	template <typename _Ty>
	inline constexpr any& operator=(const _Ty& _Val) noexcept
	{
		this->_My_storage = _Val;
		return *this;
	}

	template <typename _Ty>
	inline constexpr any& operator=(_Ty&& _Val) noexcept
	{
		this->_My_storage = std::move(_Val);
		return *this;
	}

	inline any& operator=(const any& _Other) noexcept
	{
		this->_My_storage = _Other._My_storage;
		return *this;
	}

	inline any& operator=(any&& _Other) noexcept
	{
		this->_My_storage = std::move(_Other._My_storage);
		return *this;
	}
};

#endif // __cplusplus

#endif // _UNICPP_ANY_