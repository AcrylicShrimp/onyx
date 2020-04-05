
#ifndef _ONYX_TRANSFORM_VEC3_HPP

#define _ONYX_TRANSFORM_VEC3_HPP

#include <cmath>

namespace onyx::transform {
	template<class T>
	Vec3<T>::Vec3() noexcept : tX{static_cast<T>(0)}, tY{static_cast<T>(0)}, tZ{static_cast<T>(0)}
	{
		// Empty.
	}

	template<class T>
	Vec3<T>::Vec3(T tX, T tY, T tZ) noexcept : tX{tX}, tY{tY}, tZ{tZ}
	{
		// Empty.
	}

	template<class T>
	T &Vec3<T>::operator[](std::size_t nIndex) noexcept
	{
		switch (nIndex) {
		case 0: return this->tX;
		case 1: return this->tY;
		default: return this->tZ;
		}
	}

	template<class T>
	const T &Vec3<T>::operator[](std::size_t nIndex) const noexcept
	{
		switch (nIndex) {
		case 0: return this->tX;
		case 1: return this->tY;
		default: return this->tZ;
		}
	}

	template<class T>
	Vec3<T> Vec3<T>::operator+() const noexcept
	{
		return *this;
	}

	template<class T>
	Vec3<T> Vec3<T>::operator-() const noexcept
	{
		return {-this->tX, -this->tY, -this->tZ};
	}

	template<class T>
	Vec3<T> &Vec3<T>::operator++() noexcept
	{
		++this->tX;
		++this->tY;
		++this->tZ;

		return *this;
	}

	template<class T>
	Vec3<T> Vec3<T>::operator++(int) noexcept
	{
		auto tResult{*this};

		++this->tX;
		++this->tY;
		++this->tZ;

		return tResult;
	}

	template<class T>
	Vec3<T> &Vec3<T>::operator--() noexcept
	{
		--this->tX;
		--this->tY;
		--this->tZ;

		return *this;
	}

	template<class T>
	Vec3<T> Vec3<T>::operator--(int) noexcept
	{
		auto tResult{*this};

		--this->tX;
		--this->tY;
		--this->tZ;

		return tResult;
	}

	template<class T>
	template<class U>
	Vec3<T> &Vec3<T>::operator+=(U uRhs) noexcept
	{
		auto tRhs{static_cast<T>(uRhs)};

		this->tX += tRhs;
		this->tY += tRhs;
		this->tZ += tRhs;

		return *this;
	}

	template<class T>
	template<class U>
	Vec3<T> &Vec3<T>::operator+=(const Vec3<U> &uRhs) noexcept
	{
		this->tX += static_cast<T>(uRhs.tX);
		this->tY += static_cast<T>(uRhs.tY);
		this->tZ += static_cast<T>(uRhs.tZ);

		return *this;
	}

	template<class T>
	template<class U>
	Vec3<T> &Vec3<T>::operator-=(U uRhs) noexcept
	{
		auto tRhs{static_cast<T>(uRhs)};

		this->tX -= tRhs;
		this->tY -= tRhs;
		this->tZ -= tRhs;

		return *this;
	}

	template<class T>
	template<class U>
	Vec3<T> &Vec3<T>::operator-=(const Vec3<U> &uRhs) noexcept
	{
		this->tX -= static_cast<T>(uRhs.tX);
		this->tY -= static_cast<T>(uRhs.tY);
		this->tZ -= static_cast<T>(uRhs.tZ);

		return *this;
	}

	template<class T>
	template<class U>
	Vec3<T> &Vec3<T>::operator*=(U uRhs) noexcept
	{
		auto tRhs{static_cast<T>(uRhs)};

		this->tX *= tRhs;
		this->tY *= tRhs;
		this->tZ *= tRhs;

		return *this;
	}

	template<class T>
	template<class U>
	Vec3<T> &Vec3<T>::operator*=(const Vec3<U> &uRhs) noexcept
	{
		this->tX *= static_cast<T>(uRhs.tX);
		this->tY *= static_cast<T>(uRhs.tY);
		this->tZ *= static_cast<T>(uRhs.tZ);

		return *this;
	}

	template<class T>
	template<class U>
	Vec3<T> &Vec3<T>::operator/=(U uRhs) noexcept
	{
		auto tRhs{static_cast<T>(uRhs)};

		this->tX /= tRhs;
		this->tY /= tRhs;
		this->tZ /= tRhs;

		return *this;
	}

	template<class T>
	template<class U>
	Vec3<T> &Vec3<T>::operator/=(const Vec3<U> &uRhs) noexcept
	{
		this->tX /= static_cast<T>(uRhs.tX);
		this->tY /= static_cast<T>(uRhs.tY);
		this->tZ /= static_cast<T>(uRhs.tZ);

		return *this;
	}

	template<class T>
	template<class U>
	bool Vec3<T>::operator==(U uRhs) const noexcept
	{
		return this->tX == uRhs && this->tY == uRhs && this->tZ == uRhs;
	}

	template<class T>
	template<class U>
	bool Vec3<T>::operator==(const Vec3<U> &uRhs) const noexcept
	{
		return this->tX == uRhs.tX && this->tY == uRhs.tY && this->tZ == uRhs.tZ;
	}

	template<class T>
	template<class U>
	bool Vec3<T>::operator!=(U uRhs) const noexcept
	{
		return this->tX != uRhs || this->tY != uRhs || this->tZ != uRhs;
	}

	template<class T>
	template<class U>
	bool Vec3<T>::operator!=(const Vec3<U> &uRhs) const noexcept
	{
		return this->tX != uRhs.tX || this->tY != uRhs.tY || this->tZ != uRhs.tZ;
	}

	template<class T>
	template<class U>
	Vec3<T>::operator Vec3<U>() const noexcept
	{
		return {static_cast<U>(this->tX), static_cast<U>(this->tY), static_cast<U>(this->tZ)};
	}

	template<class T>
	T Vec3<T>::length() const
	{
		return static_cast<T>(std::sqrt(this->lengthSquare()));
	}

	template<class T>
	T Vec3<T>::lengthSquare() const noexcept
	{
		return this->tX * this->tX + this->tY * this->tY + this->tZ * this->tZ;
	}

	template<class T>
	Vec3<T> Vec3<T>::normalized() const
	{
		return (*this) / this->length();
	}

	template<class T>
	Vec3<T> Vec3<T>::zero() noexcept
	{
		return {static_cast<T>(0), static_cast<T>(0), static_cast<T>(0)};
	}

	template<class T>
	Vec3<T> Vec3<T>::one() noexcept
	{
		return {static_cast<T>(1), static_cast<T>(1), static_cast<T>(1)};
	}

	template<class T>
	Vec3<T> Vec3<T>::up() noexcept
	{
		return {static_cast<T>(0), static_cast<T>(1), static_cast<T>(0)};
	}

	template<class T>
	Vec3<T> Vec3<T>::down() noexcept
	{
		return {static_cast<T>(0), static_cast<T>(-1), static_cast<T>(0)};
	}

	template<class T>
	Vec3<T> Vec3<T>::left() noexcept
	{
		return {static_cast<T>(-1), static_cast<T>(0), static_cast<T>(0)};
	}

	template<class T>
	Vec3<T> Vec3<T>::right() noexcept
	{
		return {static_cast<T>(1), static_cast<T>(0), static_cast<T>(0)};
	}

	template<class T>
	Vec3<T> Vec3<T>::front() noexcept
	{
		return {static_cast<T>(0), static_cast<T>(0), static_cast<T>(-1)};
	}

	template<class T>
	Vec3<T> Vec3<T>::back() noexcept
	{
		return {static_cast<T>(0), static_cast<T>(0), static_cast<T>(1)};
	}

	template<class T>
	T Vec3<T>::dot(const Vec3<T> &tLhs, const Vec3<T> &tRhs) noexcept
	{
		return tLhs.tX * tRhs.tX + tLhs.tY * tRhs.tY + tLhs.tZ * tRhs.tZ;
	}

	template<class T>
	Vec3<T> Vec3<T>::cross(const Vec3<T> &tLhs, const Vec3<T> &tRhs) noexcept
	{
		return {tLhs.tY * tRhs.tZ - tRhs.tY * tLhs.tZ,
				tLhs.tZ * tRhs.tX - tRhs.tZ * tLhs.tX,
				tLhs.tX * tRhs.tY - tRhs.tX * tLhs.tY};
	}

	template<class T, class U>
	Vec3<T> operator+(const Vec3<T> &tLhs, U uRhs) noexcept
	{
		auto tRhs{static_cast<T>(uRhs)};

		return {tLhs.tX + tRhs, tLhs.tY + tRhs, tLhs.tZ + tRhs};
	}

	template<class T, class U>
	Vec3<U> operator+(T tLhs, const Vec3<U> &uRhs) noexcept
	{
		auto uLhs{static_cast<U>(tLhs)};

		return {uLhs + uRhs.tX, uLhs + uRhs.tY, uLhs + uRhs.tZ};
	}

	template<class T>
	Vec3<T> operator+(const Vec3<T> &tLhs, const Vec3<T> &tRhs) noexcept
	{
		return {tLhs.tX + tRhs.tX, tLhs.tY + tRhs.tY, tLhs.tZ + tRhs.tZ};
	}

	template<class T, class U>
	Vec3<T> operator-(const Vec3<T> &tLhs, U uRhs) noexcept
	{
		auto tRhs{static_cast<T>(uRhs)};

		return {tLhs.tX - tRhs, tLhs.tY - tRhs, tLhs.tZ - tRhs};
	}

	template<class T, class U>
	Vec3<U> operator-(T tLhs, const Vec3<U> &uRhs) noexcept
	{
		auto uLhs{static_cast<U>(tLhs)};

		return {uLhs - uRhs.tX, uLhs - uRhs.tY, uLhs - uRhs.tZ};
	}

	template<class T>
	Vec3<T> operator-(const Vec3<T> &tLhs, const Vec3<T> &tRhs) noexcept
	{
		return {tLhs.tX - tRhs.tX, tLhs.tY - tRhs.tY, tLhs.tZ - tRhs.tZ};
	}

	template<class T, class U>
	Vec3<T> operator*(const Vec3<T> &tLhs, U uRhs) noexcept
	{
		auto tRhs{static_cast<T>(uRhs)};

		return {tLhs.tX * tRhs, tLhs.tY * tRhs, tLhs.tZ * tRhs};
	}

	template<class T, class U>
	Vec3<U> operator*(T tLhs, const Vec3<U> &uRhs) noexcept
	{
		auto uLhs{static_cast<U>(tLhs)};

		return {uLhs * uRhs.tX, uLhs * uRhs.tY, uLhs * uRhs.tZ};
	}

	template<class T>
	Vec3<T> operator*(const Vec3<T> &tLhs, const Vec3<T> &tRhs) noexcept
	{
		return {tLhs.tX * tRhs.tX, tLhs.tY * tRhs.tY, tLhs.tZ * tRhs.tZ};
	}

	template<class T, class U>
	Vec3<T> operator/(const Vec3<T> &tLhs, U uRhs) noexcept
	{
		auto tRhs{static_cast<T>(uRhs)};

		return {tLhs.tX / tRhs, tLhs.tY / tRhs, tLhs.tZ / tRhs};
	}

	template<class T, class U>
	Vec3<U> operator/(T tLhs, const Vec3<U> &uRhs) noexcept
	{
		auto uLhs{static_cast<U>(tLhs)};

		return {uLhs / uRhs.tX, uLhs / uRhs.tY, uLhs / uRhs.tZ};
	}

	template<class T>
	Vec3<T> operator/(const Vec3<T> &tLhs, const Vec3<T> &tRhs) noexcept
	{
		return {tLhs.tX / tRhs.tX, tLhs.tY / tRhs.tY, tLhs.tZ / tRhs.tZ};
	}
}	 // namespace onyx::transform

#endif