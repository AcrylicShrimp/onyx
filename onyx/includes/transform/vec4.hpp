
#ifndef _ONYX_TRANSFORM_VEC4_HPP

#define _ONYX_TRANSFORM_VEC4_HPP

#include <cmath>

namespace onyx::transform {
	template<class T>
	Vec4<T>::Vec4() noexcept :
		tX{static_cast<T>(0)},
		tY{static_cast<T>(0)},
		tZ{static_cast<T>(0)},
		tW{static_cast<T>(0)}
	{
		// Empty.
	}

	template<class T>
	Vec4<T>::Vec4(T tX, T tY, T tZ, T tW) noexcept : tX{tX}, tY{tY}, tZ{tZ}, tW{tW}
	{
		// Empty.
	}

	template<class T>
	T &Vec4<T>::operator[](std::size_t nIndex) noexcept
	{
		switch (nIndex) {
		case 0: return this->tX;
		case 1: return this->tY;
		case 2: return this->tZ;
		default: return this->tW;
		}
	}

	template<class T>
	const T &Vec4<T>::operator[](std::size_t nIndex) const noexcept
	{
		switch (nIndex) {
		case 0: return this->tX;
		case 1: return this->tY;
		case 2: return this->tZ;
		default: return this->tW;
		}
	}

	template<class T>
	Vec4<T> Vec4<T>::operator+() const noexcept
	{
		return *this;
	}

	template<class T>
	Vec4<T> Vec4<T>::operator-() const noexcept
	{
		return {-this->tX, -this->tY, -this->tZ, -this->tW};
	}

	template<class T>
	Vec4<T> &Vec4<T>::operator++() noexcept
	{
		++this->tX;
		++this->tY;
		++this->tZ;
		++this->tW;

		return *this;
	}

	template<class T>
	Vec4<T> Vec4<T>::operator++(int) noexcept
	{
		auto tResult{*this};

		++this->tX;
		++this->tY;
		++this->tZ;
		++this->tW;

		return tResult;
	}

	template<class T>
	Vec4<T> &Vec4<T>::operator--() noexcept
	{
		--this->tX;
		--this->tY;
		--this->tZ;
		--this->tW;

		return *this;
	}

	template<class T>
	Vec4<T> Vec4<T>::operator--(int) noexcept
	{
		auto tResult{*this};

		--this->tX;
		--this->tY;
		--this->tZ;
		--this->tW;

		return tResult;
	}

	template<class T>
	template<class U>
	Vec4<T> &Vec4<T>::operator+=(U uRhs) noexcept
	{
		auto tScalar{static_cast<T>(uRhs)};

		this->tX += tScalar;
		this->tY += tScalar;
		this->tZ += tScalar;
		this->tW += tScalar;

		return *this;
	}

	template<class T>
	template<class U>
	Vec4<T> &Vec4<T>::operator+=(const Vec4<U> &uRhs) noexcept
	{
		this->tX += static_cast<T>(uRhs.tX);
		this->tY += static_cast<T>(uRhs.tY);
		this->tZ += static_cast<T>(uRhs.tZ);
		this->tW += static_cast<T>(uRhs.tW);

		return *this;
	}

	template<class T>
	template<class U>
	Vec4<T> &Vec4<T>::operator-=(U uRhs) noexcept
	{
		auto tScalar{static_cast<T>(uRhs)};

		this->tX -= tScalar;
		this->tY -= tScalar;
		this->tZ -= tScalar;
		this->tW -= tScalar;

		return *this;
	}

	template<class T>
	template<class U>
	Vec4<T> &Vec4<T>::operator-=(const Vec4<U> &uRhs) noexcept
	{
		this->tX -= static_cast<T>(uRhs.tX);
		this->tY -= static_cast<T>(uRhs.tY);
		this->tZ -= static_cast<T>(uRhs.tZ);
		this->tW -= static_cast<T>(uRhs.tW);

		return *this;
	}

	template<class T>
	template<class U>
	Vec4<T> &Vec4<T>::operator*=(U uRhs) noexcept
	{
		auto tScalar{static_cast<T>(uRhs)};

		this->tX *= tScalar;
		this->tY *= tScalar;
		this->tZ *= tScalar;
		this->tW *= tScalar;

		return *this;
	}

	template<class T>
	template<class U>
	Vec4<T> &Vec4<T>::operator*=(const Vec4<U> &uRhs) noexcept
	{
		this->tX *= static_cast<T>(uRhs.tX);
		this->tY *= static_cast<T>(uRhs.tY);
		this->tZ *= static_cast<T>(uRhs.tZ);
		this->tW *= static_cast<T>(uRhs.tW);

		return *this;
	}

	template<class T>
	template<class U>
	Vec4<T> &Vec4<T>::operator/=(U uRhs) noexcept
	{
		auto tScalar{static_cast<T>(uRhs)};

		this->tX /= tScalar;
		this->tY /= tScalar;
		this->tZ /= tScalar;
		this->tW /= tScalar;

		return *this;
	}

	template<class T>
	template<class U>
	Vec4<T> &Vec4<T>::operator/=(const Vec4<U> &uRhs) noexcept
	{
		this->tX /= static_cast<T>(uRhs.tX);
		this->tY /= static_cast<T>(uRhs.tY);
		this->tZ /= static_cast<T>(uRhs.tZ);
		this->tW /= static_cast<T>(uRhs.tW);

		return *this;
	}

	template<class T>
	template<class U>
	bool Vec4<T>::operator==(U uRhs) const noexcept
	{
		return this->tX == uRhs && this->tY == uRhs && this->tZ == uRhs && this->tW == uRhs;
	}

	template<class T>
	template<class U>
	bool Vec4<T>::operator==(const Vec4<U> &uRhs) const noexcept
	{
		return this->tX == uRhs.tX && this->tY == uRhs.tY && this->tZ == uRhs.tZ && this->tW == uRhs.tW;
	}

	template<class T>
	template<class U>
	bool Vec4<T>::operator!=(U uRhs) const noexcept
	{
		return this->tX != uRhs || this->tY != uRhs || this->tZ != uRhs || this->tW != uRhs;
	}

	template<class T>
	template<class U>
	bool Vec4<T>::operator!=(const Vec4<U> &uRhs) const noexcept
	{
		return this->tX != uRhs.tX || this->tY != uRhs.tY || this->tZ != uRhs.tZ || this->tW != uRhs.tW;
	}

	template<class T>
	template<class U>
	Vec4<T>::operator Vec4<U>() const noexcept
	{
		return {static_cast<U>(this->tX), static_cast<U>(this->tY), static_cast<U>(this->tZ), static_cast<U>(this->tW)};
	}

	template<class T>
	T Vec4<T>::length() const
	{
		return static_cast<T>(std::sqrt(this->lengthSquare()));
	}

	template<class T>
	T Vec4<T>::lengthSquare() const noexcept
	{
		return this->tX * this->tX + this->tY * this->tY + this->tZ * this->tZ + this->tW * this->tW;
	}

	template<class T>
	Vec4<T> Vec4<T>::normalized() const
	{
		return (*this) / this->length();
	}

	template<class T>
	Vec4<T> Vec4<T>::zero() noexcept
	{
		return {static_cast<T>(0), static_cast<T>(0), static_cast<T>(0), static_cast<T>(0)};
	}

	template<class T>
	Vec4<T> Vec4<T>::one() noexcept
	{
		return {static_cast<T>(1), static_cast<T>(1), static_cast<T>(1), static_cast<T>(1)};
	}

	template<class T>
	Vec4<T> Vec4<T>::up() noexcept
	{
		return {static_cast<T>(0), static_cast<T>(1), static_cast<T>(0), static_cast<T>(0)};
	}

	template<class T>
	Vec4<T> Vec4<T>::down() noexcept
	{
		return {static_cast<T>(0), static_cast<T>(-1), static_cast<T>(0), static_cast<T>(0)};
	}

	template<class T>
	Vec4<T> Vec4<T>::left() noexcept
	{
		return {static_cast<T>(-1), static_cast<T>(0), static_cast<T>(0), static_cast<T>(0)};
	}

	template<class T>
	Vec4<T> Vec4<T>::right() noexcept
	{
		return {static_cast<T>(1), static_cast<T>(0), static_cast<T>(0), static_cast<T>(0)};
	}

	template<class T>
	Vec4<T> Vec4<T>::front() noexcept
	{
		return {static_cast<T>(0), static_cast<T>(0), static_cast<T>(-1), static_cast<T>(0)};
	}

	template<class T>
	Vec4<T> Vec4<T>::back() noexcept
	{
		return {static_cast<T>(0), static_cast<T>(0), static_cast<T>(1), static_cast<T>(0)};
	}

	template<class T>
	T Vec4<T>::dot(const Vec4<T> &tLhs, const Vec4<T> &tRhs) noexcept
	{
		return tLhs.tX * tRhs.tX + tLhs.tY * tRhs.tY + tLhs.tZ * tRhs.tZ + tLhs.tW * tRhs.tW;
	}

	template<class T, class U>
	Vec4<T> operator+(const Vec4<T> &tLhs, U uRhs) noexcept
	{
		auto tRhs{static_cast<T>(uRhs)};

		return {tLhs.tX + tRhs, tLhs.tY + tRhs, tLhs.tZ + tRhs, tLhs.tW + tRhs};
	}

	template<class T, class U>
	Vec4<U> operator+(T tLhs, const Vec4<U> &uRhs) noexcept
	{
		auto uLhs{static_cast<U>(tLhs)};

		return {uLhs + uRhs.tX, uLhs + uRhs.tY, uLhs + uRhs.tZ, uLhs + uRhs.tW};
	}

	template<class T>
	Vec4<T> operator+(const Vec4<T> &tLhs, const Vec4<T> &tRhs) noexcept
	{
		return {tLhs.tX + tRhs.tX, tLhs.tY + tRhs.tY, tLhs.tZ + tRhs.tZ, tLhs.tW + tRhs.tW};
	}

	template<class T, class U>
	Vec4<T> operator-(const Vec4<T> &tLhs, U uRhs) noexcept
	{
		auto tRhs{static_cast<T>(uRhs)};

		return {tLhs.tX - tRhs, tLhs.tY - tRhs, tLhs.tZ - tRhs, tLhs.tW - tRhs};
	}

	template<class T, class U>
	Vec4<U> operator-(T tLhs, const Vec4<U> &uRhs) noexcept
	{
		auto uLhs{static_cast<U>(tLhs)};

		return {uLhs - uRhs.tX, uLhs - uRhs.tY, uLhs - uRhs.tZ, uLhs - uRhs.tW};
	}

	template<class T>
	Vec4<T> operator-(const Vec4<T> &tLhs, const Vec4<T> &tRhs) noexcept
	{
		return {tLhs.tX - tRhs.tX, tLhs.tY - tRhs.tY, tLhs.tZ - tRhs.tZ, tLhs.tW - tRhs.tW};
	}

	template<class T, class U>
	Vec4<T> operator*(const Vec4<T> &tLhs, U uRhs) noexcept
	{
		auto tRhs{static_cast<T>(uRhs)};

		return {tLhs.tX * tRhs, tLhs.tY * tRhs, tLhs.tZ * tRhs, tLhs.tW * tRhs};
	}

	template<class T, class U>
	Vec4<U> operator*(T tLhs, const Vec4<U> &uRhs) noexcept
	{
		auto uLhs{static_cast<U>(tLhs)};

		return {uLhs * uRhs.tX, uLhs * uRhs.tY, uLhs * uRhs.tZ, uLhs * uRhs.tW};
	}

	template<class T>
	Vec4<T> operator*(const Vec4<T> &tLhs, const Vec4<T> &tRhs) noexcept
	{
		return {tLhs.tX * tRhs.tX, tLhs.tY * tRhs.tY, tLhs.tZ * tRhs.tZ, tLhs.tW * tRhs.tW};
	}

	template<class T, class U>
	Vec4<T> operator/(const Vec4<T> &tLhs, U uRhs) noexcept
	{
		auto tRhs{static_cast<T>(uRhs)};

		return {tLhs.tX / tRhs, tLhs.tY / tRhs, tLhs.tZ / tRhs, tLhs.tW / tRhs};
	}

	template<class T, class U>
	Vec4<U> operator/(T tLhs, const Vec4<U> &uRhs) noexcept
	{
		auto uLhs{static_cast<U>(tLhs)};

		return {uLhs / uRhs.tX, uLhs / uRhs.tY, uLhs / uRhs.tZ, uLhs / uRhs.tW};
	}

	template<class T>
	Vec4<T> operator/(const Vec4<T> &tLhs, const Vec4<T> &tRhs) noexcept
	{
		return {tLhs.tX / tRhs.tX, tLhs.tY / tRhs.tY, tLhs.tZ / tRhs.tZ, tLhs.tW / tRhs.tW};
	}

}	 // namespace onyx::transform

#endif