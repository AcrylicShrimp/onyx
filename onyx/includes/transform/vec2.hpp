
#ifndef _ONYX_TRANSFORM_VEC2_HPP

#define _ONYX_TRANSFORM_VEC2_HPP

#include <cmath>
#include <cstddef>

namespace onyx::transform {
	template<class T>
	Vec2<T>::Vec2() noexcept : tX{static_cast<T>(0)}, tY{static_cast<T>(0)}
	{
		// Empty.
	}

	template<class T>
	Vec2<T>::Vec2(T tX, T tY) noexcept : tX{tX}, tY{tY}
	{
		// Empty.
	}

	template<class T>
	T &Vec2<T>::operator[](std::size_t nIndex) noexcept
	{
		switch (nIndex) {
		case 0: return this->tX;
		default: return this->tY;
		}
	}

	template<class T>
	const T &Vec2<T>::operator[](std::size_t nIndex) const noexcept
	{
		switch (nIndex) {
		case 0: return this->tX;
		default: return this->tY;
		}
	}

	template<class T>
	Vec2<T> Vec2<T>::operator+() const noexcept
	{
		return *this;
	}

	template<class T>
	Vec2<T> Vec2<T>::operator-() const noexcept
	{
		return {-this->tX, -this->tY};
	}

	template<class T>
	Vec2<T> &Vec2<T>::operator++() noexcept
	{
		++this->tX;
		++this->tY;

		return *this;
	}

	template<class T>
	Vec2<T> Vec2<T>::operator++(int) noexcept
	{
		auto tResult{*this};

		++this->tX;
		++this->tY;

		return tResult;
	}

	template<class T>
	Vec2<T> &Vec2<T>::operator--() noexcept
	{
		--this->tX;
		--this->tY;

		return *this;
	}

	template<class T>
	Vec2<T> Vec2<T>::operator--(int) noexcept
	{
		auto tResult{*this};

		--this->tX;
		--this->tY;

		return tResult;
	}

	template<class T>
	template<class U>
	Vec2<T> &Vec2<T>::operator+=(U uRhs) noexcept
	{
		auto tRhs{static_cast<T>(uRhs)};

		this->tX += tRhs;
		this->tY += tRhs;

		return *this;
	}

	template<class T>
	template<class U>
	Vec2<T> &Vec2<T>::operator+=(const Vec2<U> &uRhs) noexcept
	{
		this->tX += static_cast<T>(uRhs.tX);
		this->tY += static_cast<T>(uRhs.tY);

		return *this;
	}

	template<class T>
	template<class U>
	Vec2<T> &Vec2<T>::operator-=(U uRhs) noexcept
	{
		auto tRhs{static_cast<T>(uRhs)};

		this->tX -= tRhs;
		this->tY -= tRhs;

		return *this;
	}

	template<class T>
	template<class U>
	Vec2<T> &Vec2<T>::operator-=(const Vec2<U> &uRhs) noexcept
	{
		this->tX -= static_cast<T>(uRhs.tX);
		this->tY -= static_cast<T>(uRhs.tY);

		return *this;
	}

	template<class T>
	template<class U>
	Vec2<T> &Vec2<T>::operator*=(U uRhs) noexcept
	{
		auto tRhs{static_cast<T>(uRhs)};

		this->tX *= tRhs;
		this->tY *= tRhs;

		return *this;
	}

	template<class T>
	template<class U>
	Vec2<T> &Vec2<T>::operator*=(const Vec2<U> &uRhs) noexcept
	{
		this->tX *= static_cast<T>(uRhs.tX);
		this->tY *= static_cast<T>(uRhs.tY);

		return *this;
	}

	template<class T>
	template<class U>
	Vec2<T> &Vec2<T>::operator/=(U uRhs) noexcept
	{
		auto tRhs{static_cast<T>(uRhs)};

		this->tX /= tRhs;
		this->tY /= tRhs;

		return *this;
	}

	template<class T>
	template<class U>
	Vec2<T> &Vec2<T>::operator/=(const Vec2<U> &uRhs) noexcept
	{
		this->tX /= static_cast<T>(uRhs.tX);
		this->tY /= static_cast<T>(uRhs.tY);

		return *this;
	}

	template<class T>
	template<class U>
	bool Vec2<T>::operator==(U uRhs) const noexcept
	{
		return this->tX == uRhs && this->tY == uRhs;
	}

	template<class T>
	template<class U>
	bool Vec2<T>::operator==(const Vec2<U> &uRhs) const noexcept
	{
		return this->tX == uRhs.tX && this->tY == uRhs.tY;
	}

	template<class T>
	template<class U>
	bool Vec2<T>::operator!=(U uRhs) const noexcept
	{
		return this->tX != uRhs || this->tY != uRhs;
	}

	template<class T>
	template<class U>
	bool Vec2<T>::operator!=(const Vec2<U> &uRhs) const noexcept
	{
		return this->tX != uRhs.tX || this->tY != uRhs.tY;
	}

	template<class T>
	template<class U>
	Vec2<T>::operator Vec2<U>() const noexcept
	{
		return {static_cast<U>(this->tX), static_cast<U>(this->tY)};
	}

	template<class T>
	T Vec2<T>::length() const
	{
		return static_cast<T>(std::sqrt(this->lengthSquare()));
	}

	template<class T>
	T Vec2<T>::lengthSquare() const noexcept
	{
		return this->tX * this->tX + this->tY * this->tY;
	}

	template<class T>
	Vec2<T> Vec2<T>::normalized() const
	{
		return (*this) / this->length();
	}

	template<class T>
	Vec2<T> Vec2<T>::zero() noexcept
	{
		return {static_cast<T>(0), static_cast<T>(0)};
	}

	template<class T>
	Vec2<T> Vec2<T>::one() noexcept
	{
		return {static_cast<T>(1), static_cast<T>(1)};
	}

	template<class T>
	Vec2<T> Vec2<T>::up() noexcept
	{
		return {static_cast<T>(0), static_cast<T>(1)};
	}

	template<class T>
	Vec2<T> Vec2<T>::down() noexcept
	{
		return {static_cast<T>(0), static_cast<T>(-1)};
	}

	template<class T>
	Vec2<T> Vec2<T>::left() noexcept
	{
		return {static_cast<T>(-1), static_cast<T>(0)};
	}

	template<class T>
	Vec2<T> Vec2<T>::right() noexcept
	{
		return {static_cast<T>(1), static_cast<T>(0)};
	}

	template<class T>
	T Vec2<T>::dot(const Vec2<T> &tLhs, const Vec2<T> &tRhs) noexcept
	{
		return tLhs.tX * tRhs.tX + tLhs.tY * tRhs.tY;
	}

	template<class T, class U>
	Vec2<T> operator+(const Vec2<T> &tLhs, U uRhs) noexcept
	{
		auto tRhs{static_cast<T>(uRhs)};

		return {tLhs.tX + tRhs, tLhs.tY + tRhs};
	}

	template<class T, class U>
	Vec2<U> operator+(T tLhs, const Vec2<U> &uRhs) noexcept
	{
		auto uLhs{static_cast<U>(tLhs)};

		return {uLhs + uRhs.tX, uLhs + uRhs.tY};
	}

	template<class T>
	Vec2<T> operator+(const Vec2<T> &tLhs, const Vec2<T> &tRhs) noexcept
	{
		return {tLhs.tX + tRhs.tX, tLhs.tY + tRhs.tY};
	}

	template<class T, class U>
	Vec2<T> operator-(const Vec2<T> &tLhs, U uRhs) noexcept
	{
		auto tRhs{static_cast<T>(uRhs)};

		return {tLhs.tX - tRhs, tLhs.tY - tRhs};
	}

	template<class T, class U>
	Vec2<U> operator-(T tLhs, const Vec2<U> &uRhs) noexcept
	{
		auto uLhs{static_cast<U>(tLhs)};

		return {uLhs - uRhs.tX, uLhs - uRhs.tY};
	}

	template<class T>
	Vec2<T> operator-(const Vec2<T> &tLhs, const Vec2<T> &tRhs) noexcept
	{
		return {tLhs.tX - tRhs.tX, tLhs.tY - tRhs.tY};
	}

	template<class T, class U>
	Vec2<T> operator*(const Vec2<T> &tLhs, U uRhs) noexcept
	{
		auto tRhs{static_cast<T>(uRhs)};

		return {tLhs.tX * tRhs, tLhs.tY * tRhs};
	}

	template<class T, class U>
	Vec2<U> operator*(T tLhs, const Vec2<U> &uRhs) noexcept
	{
		auto uLhs{static_cast<U>(tLhs)};

		return {uLhs * uRhs.tX, uLhs * uRhs.tY};
	}

	template<class T>
	Vec2<T> operator*(const Vec2<T> &tLhs, const Vec2<T> &tRhs) noexcept
	{
		return {tLhs.tX * tRhs.tX, tLhs.tY * tRhs.tY};
	}

	template<class T, class U>
	Vec2<T> operator/(const Vec2<T> &tLhs, U uRhs) noexcept
	{
		auto tRhs{static_cast<T>(uRhs)};

		return {tLhs.tX / tRhs, tLhs.tY / tRhs};
	}

	template<class T, class U>
	Vec2<U> operator/(T tLhs, const Vec2<U> &uRhs) noexcept
	{
		auto uLhs{static_cast<U>(tLhs)};

		return {uLhs / uRhs.tX, uLhs / uRhs.tY};
	}

	template<class T>
	Vec2<T> operator/(const Vec2<T> &tLhs, const Vec2<T> &tRhs) noexcept
	{
		return {tLhs.tX / tRhs.tX, tLhs.tY / tRhs.tY};
	}
}	 // namespace onyx::transform

#endif