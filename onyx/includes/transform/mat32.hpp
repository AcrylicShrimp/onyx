
#ifndef _ONYX_TRANSFORM_MAT32_HPP

#define _ONYX_TRANSFORM_MAT32_HPP

namespace onyx::transform {
	template<class T>
	Mat32<T>::Mat32() noexcept : tX{Vec2<T>::zero()}, tY{Vec2<T>::zero()}, tZ{Vec2<T>::zero()}
	{
		// Empty.
	}

	template<class T>
	Mat32<T>::Mat32(Vec2<T> tX, Vec2<T> tY, Vec2<T> tZ) noexcept : tX{tX}, tY{tY}, tZ{tZ}
	{
		// Empty.
	}

	template<class T>
	Mat32<T>::Mat32(T tXX, T tXY, T tYX, T tYY, T tZX, T tZY) noexcept : tX{tXX, tXY}, tY{tYX, tYY}, tZ{tZX, tZY}
	{
		// Empty.
	}

	template<class T>
	Vec2<T> &Mat32<T>::operator[](std::size_t nIndex) noexcept
	{
		switch (nIndex) {
		case 0: return this->tX;

		case 1: return this->tY;

		default: return this->tZ;
		}
	}

	template<class T>
	const Vec2<T> &Mat32<T>::operator[](std::size_t nIndex) const noexcept
	{
		switch (nIndex) {
		case 0: return this->tX;

		case 1: return this->tY;

		default: return this->tZ;
		}
	}

	template<class T>
	Mat32<T> Mat32<T>::operator+() const noexcept
	{
		return *this;
	}

	template<class T>
	Mat32<T> Mat32<T>::operator-() const noexcept
	{
		return {-this->tX, -this->tY, -this->tZ};
	}

	template<class T>
	Mat32<T> &Mat32<T>::operator++() noexcept
	{
		++this->tX;
		++this->tY;
		++this->tZ;

		return *this;
	}

	template<class T>
	Mat32<T> Mat32<T>::operator++(int) noexcept
	{
		auto tResult{*this};

		++this->tX;
		++this->tY;
		++this->tZ;

		return tResult;
	}

	template<class T>
	Mat32<T> &Mat32<T>::operator--() noexcept
	{
		--this->tX;
		--this->tY;
		--this->tZ;

		return *this;
	}

	template<class T>
	Mat32<T> Mat32<T>::operator--(int) noexcept
	{
		auto tResult{*this};

		--this->tX;
		--this->tY;
		--this->tZ;

		return tResult;
	}

	template<class T>
	template<class U>
	Mat32<T> &Mat32<T>::operator+=(U uRhs) noexcept
	{
		auto tRhs{static_cast<T>(uRhs)};

		this->tX += tRhs;
		this->tY += tRhs;
		this->tZ += tRhs;

		return *this;
	}

	template<class T>
	template<class U>
	Mat32<T> &Mat32<T>::operator+=(const Vec2<U> &uRhs) noexcept
	{
		auto tRhs{static_cast<Vec2<T>>(uRhs)};

		this->tX += tRhs;
		this->tY += tRhs;
		this->tZ += tRhs;

		return *this;
	}

	template<class T>
	template<class U>
	Mat32<T> &Mat32<T>::operator+=(const Mat32<U> &uRhs) noexcept
	{
		this->tX += uRhs.tX;
		this->tY += uRhs.tY;
		this->tZ += uRhs.tZ;

		return *this;
	}

	template<class T>
	template<class U>
	Mat32<T> &Mat32<T>::operator-=(U uRhs) noexcept
	{
		auto tRhs{static_cast<T>(uRhs)};

		this->tX -= tRhs;
		this->tY -= tRhs;
		this->tZ -= tRhs;

		return *this;
	}

	template<class T>
	template<class U>
	Mat32<T> &Mat32<T>::operator-=(const Vec2<U> &uRhs) noexcept
	{
		auto tRhs{static_cast<Vec2<T>>(uRhs)};

		this->tX -= tRhs;
		this->tY -= tRhs;
		this->tZ -= tRhs;

		return *this;
	}

	template<class T>
	template<class U>
	Mat32<T> &Mat32<T>::operator-=(const Mat32<U> &uRhs) noexcept
	{
		this->tX -= uRhs.tX;
		this->tY -= uRhs.tY;
		this->tZ -= uRhs.tZ;

		return *this;
	}

	template<class T>
	template<class U>
	Mat32<T> &Mat32<T>::operator*=(U uRhs) noexcept
	{
		auto tRhs{static_cast<T>(uRhs)};

		this->tX *= tRhs;
		this->tY *= tRhs;
		this->tZ *= tRhs;

		return *this;
	}

	template<class T>
	template<class U>
	Mat32<T> &Mat32<T>::operator*=(const Vec2<U> &uRhs) noexcept
	{
		auto tRhs{static_cast<Vec2<T>>(uRhs)};

		this->tX *= tRhs;
		this->tY *= tRhs;
		this->tZ *= tRhs;

		return *this;
	}

	template<class T>
	template<class U>
	Mat32<T> &Mat32<T>::operator*=(const Mat32<U> &uRhs) noexcept
	{
		this->tX *= uRhs.tX;
		this->tY *= uRhs.tY;
		this->tZ *= uRhs.tZ;

		return *this;
	}

	template<class T>
	template<class U>
	Mat32<T> &Mat32<T>::operator/=(U uRhs) noexcept
	{
		auto tRhs{static_cast<T>(uRhs)};

		this->tX /= tRhs;
		this->tY /= tRhs;
		this->tZ /= tRhs;

		return *this;
	}

	template<class T>
	template<class U>
	Mat32<T> &Mat32<T>::operator/=(const Vec2<U> &uRhs) noexcept
	{
		auto tRhs{static_cast<Vec2<T>>(uRhs)};

		this->tX /= tRhs;
		this->tY /= tRhs;
		this->tZ /= tRhs;

		return *this;
	}

	template<class T>
	template<class U>
	Mat32<T> &Mat32<T>::operator/=(const Mat32<U> &uRhs) noexcept
	{
		this->tX /= uRhs.tX;
		this->tY /= uRhs.tY;
		this->tZ /= uRhs.tZ;

		return *this;
	}

	template<class T>
	template<class U>
	bool Mat32<T>::operator==(U uRhs) const noexcept
	{
		auto tRhs{static_cast<T>(uRhs)};

		return this->tX == tRhs && this->tY == tRhs && this->tZ == tRhs;
	}

	template<class T>
	template<class U>
	bool Mat32<T>::operator==(const Vec2<U> &uRhs) const noexcept
	{
		auto tRhs{static_cast<Vec2<T>>(uRhs)};

		return this->tX == tRhs && this->tY == tRhs && this->tZ == tRhs;
	}

	template<class T>
	template<class U>
	bool Mat32<T>::operator==(const Mat32<U> &uRhs) const noexcept
	{
		return this->tX == uRhs.tX && this->tY == uRhs.tY && this->tZ == uRhs.tZ;
	}

	template<class T>
	template<class U>
	bool Mat32<T>::operator!=(U uRhs) const noexcept
	{
		auto tRhs{static_cast<T>(uRhs)};

		return this->tX != tRhs || this->tY != tRhs || this->tZ != tRhs;
	}

	template<class T>
	template<class U>
	bool Mat32<T>::operator!=(const Vec2<U> &uRhs) const noexcept
	{
		auto tRhs{static_cast<Vec2<T>>(uRhs)};

		return this->tX != tRhs || this->tY != tRhs || this->tZ != tRhs;
	}

	template<class T>
	template<class U>
	bool Mat32<T>::operator!=(const Mat32<U> &uRhs) const noexcept
	{
		return this->tX != uRhs.tX || this->tY != uRhs.tY || this->tZ != uRhs.tZ;
	}

	template<class T>
	template<class U>
	Mat32<T>::operator Mat32<U>() const noexcept
	{
		return {static_cast<Vec2<U>>(this->tX), static_cast<Vec2<U>>(this->tY), static_cast<Vec2<U>>(this->tZ)};
	}

	template<class T>
	Mat23<T> Mat32<T>::transposed() const noexcept
	{
		return {{this->tX.tX, this->tY.tX, this->tZ.tX}, {this->tX.tY, this->tY.tY, this->tZ.tY}};
	}

	template<class T>
	Mat32<T> Mat32<T>::zero() noexcept
	{
		return {Vec2<T>::zero(), Vec2<T>::zero(), Vec2<T>::zero()};
	}

	template<class T>
	Mat32<T> Mat32<T>::one() noexcept
	{
		return {Vec2<T>::one(), Vec2<T>::one(), Vec2<T>::one()};
	}

	template<class T, class U>
	Mat32<T> operator+(const Mat32<T> &tLhs, U uRhs) noexcept
	{
		auto tRhs{static_cast<T>(uRhs)};

		return {tLhs.tX + tRhs, tLhs.tY + tRhs, tLhs.tZ + tRhs};
	}

	template<class T, class U>
	Mat32<U> operator+(T tLhs, const Mat32<U> &uRhs) noexcept
	{
		auto uLhs{static_cast<U>(tLhs)};

		return {uLhs + uRhs.tX, uLhs + uRhs.tY, uLhs + uRhs.tZ};
	}

	template<class T, class U>
	Mat32<T> operator+(const Mat32<T> &tLhs, const Vec2<U> &uRhs) noexcept
	{
		auto tRhs{static_cast<Vec2<T>>(uRhs)};

		return {tLhs.tX + tRhs, tLhs.tY + tRhs, tLhs.tZ + tRhs};
	}

	template<class T, class U>
	Mat32<U> operator+(const Vec2<T> &tLhs, const Mat32<U> &uRhs) noexcept
	{
		auto uLhs{static_cast<Vec2<U>>(tLhs)};

		return {uLhs + uRhs.tX, uLhs + uRhs.tY, uLhs + uRhs.tZ};
	}

	template<class T>
	Mat32<T> operator+(const Mat32<T> &tLhs, const Mat32<T> &tRhs) noexcept
	{
		return {tLhs.tX + tRhs.tX, tLhs.tY + tRhs.tY, tLhs.tZ + tRhs.tZ};
	}

	template<class T, class U>
	Mat32<T> operator-(const Mat32<T> &tLhs, U uRhs) noexcept
	{
		auto tRhs{static_cast<T>(uRhs)};

		return {tLhs.tX - tRhs, tLhs.tY - tRhs, tLhs.tZ - tRhs};
	}

	template<class T, class U>
	Mat32<U> operator-(T tLhs, const Mat32<U> &uRhs) noexcept
	{
		auto uLhs{static_cast<U>(tLhs)};

		return {uLhs - uRhs.tX, uLhs - uRhs.tY, uLhs - uRhs.tZ};
	}

	template<class T, class U>
	Mat32<T> operator-(const Mat32<T> &tLhs, const Vec2<U> &uRhs) noexcept
	{
		auto tRhs{static_cast<Vec2<T>>(uRhs)};

		return {tLhs.tX - tRhs, tLhs.tY - tRhs, tLhs.tZ - tRhs};
	}

	template<class T, class U>
	Mat32<U> operator-(const Vec2<T> &tLhs, const Mat32<U> &uRhs) noexcept
	{
		auto uLhs{static_cast<Vec2<U>>(tLhs)};

		return {uLhs - uRhs.tX, uLhs - uRhs.tY, uLhs - uRhs.tZ};
	}

	template<class T>
	Mat32<T> operator-(const Mat32<T> &tLhs, const Mat32<T> &tRhs) noexcept
	{
		return {tLhs.tX - tRhs.tX, tLhs.tY - tRhs.tY, tLhs.tZ - tRhs.tZ};
	}

	template<class T, class U>
	Mat32<T> operator*(const Mat32<T> &tLhs, U uRhs) noexcept
	{
		auto tRhs{static_cast<T>(uRhs)};

		return {tLhs.tX * tRhs, tLhs.tY * tRhs, tLhs.tZ * tRhs};
	}

	template<class T, class U>
	Mat32<U> operator*(T tLhs, const Mat32<U> &uRhs) noexcept
	{
		auto uLhs{static_cast<U>(tLhs)};

		return {uLhs * uRhs.tX, uLhs * uRhs.tY, uLhs * uRhs.tZ};
	}

	template<class T, class U>
	Mat32<T> operator*(const Mat32<T> &tLhs, const Vec2<U> &uRhs) noexcept
	{
		auto tRhs{static_cast<Vec2<T>>(uRhs)};

		return {tLhs.tX * tRhs, tLhs.tY * tRhs, tLhs.tZ * tRhs};
	}

	template<class T, class U>
	Mat32<U> operator*(const Vec2<T> &tLhs, const Mat32<U> &uRhs) noexcept
	{
		auto uLhs{static_cast<Vec2<U>>(tLhs)};

		return {uLhs * uRhs.tX, uLhs * uRhs.tY, uLhs * uRhs.tZ};
	}

	template<class T>
	Mat32<T> operator*(const Mat32<T> &tLhs, const Mat32<T> &tRhs) noexcept
	{
		return {tLhs.tX * tRhs.tX, tLhs.tY * tRhs.tY, tLhs.tZ * tRhs.tZ};
	}

	template<class T, class U>
	Mat32<T> operator/(const Mat32<T> &tLhs, U uRhs) noexcept
	{
		auto tRhs{static_cast<T>(uRhs)};

		return {tLhs.tX / tRhs, tLhs.tY / tRhs, tLhs.tZ / tRhs};
	}

	template<class T, class U>
	Mat32<U> operator/(T tLhs, const Mat32<U> &uRhs) noexcept
	{
		auto uLhs{static_cast<U>(tLhs)};

		return {uLhs / uRhs.tX, uLhs / uRhs.tY, uLhs / uRhs.tZ};
	}

	template<class T, class U>
	Mat32<T> operator/(const Mat32<T> &tLhs, const Vec2<U> &uRhs) noexcept
	{
		auto tRhs{static_cast<Vec2<T>>(uRhs)};

		return {tLhs.tX / tRhs, tLhs.tY / tRhs, tLhs.tZ / tRhs};
	}

	template<class T, class U>
	Mat32<U> operator/(const Vec2<T> &tLhs, const Mat32<U> &uRhs) noexcept
	{
		auto uLhs{static_cast<Vec2<U>>(tLhs)};

		return {uLhs / uRhs.tX, uLhs / uRhs.tY, uLhs / uRhs.tZ};
	}

	template<class T>
	Mat32<T> operator/(const Mat32<T> &tLhs, const Mat32<T> &tRhs) noexcept
	{
		return {tLhs.tX / tRhs.tX, tLhs.tY / tRhs.tY, tLhs.tZ / tRhs.tZ};
	}

	template<class T, class U>
	Vec3<T> operator%(const Mat32<T> &tLhs, const Vec2<U> &uRhs) noexcept
	{
		auto tRhs{static_cast<Vec2<T>>(uRhs)};

		return {Vec2<T>::dot(tLhs.tX, tRhs), Vec2<T>::dot(tLhs.tY, tRhs), Vec2<T>::dot(tLhs.tZ, tRhs)};
	}

	template<class T, class U>
	Vec2<U> operator%(const Vec3<T> &tLhs, const Mat32<U> &uRhs) noexcept
	{
		auto uLhs{static_cast<Vec3<U>>(tLhs)};

		return {uLhs.tX * uRhs.tX.tX + uLhs.tY * uRhs.tY.tX + uLhs.tZ * uRhs.tZ.tX,
				uLhs.tX * uRhs.tX.tY + uLhs.tY * uRhs.tY.tY + uLhs.tZ * uRhs.tZ.tY};
	}
}	 // namespace onyx::transform

#endif