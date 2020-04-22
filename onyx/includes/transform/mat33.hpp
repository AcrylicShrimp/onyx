
#ifndef _ONYX_TRANSFORM_MAT33_HPP

#define _ONYX_TRANSFORM_MAT33_HPP

namespace onyx::transform {
	template<class T>
	Mat33<T>::Mat33() noexcept : tX{Vec3<T>::zero()}, tY{Vec3<T>::zero()}, tZ{Vec3<T>::zero()}
	{
		// Empty.
	}

	template<class T>
	Mat33<T>::Mat33(Vec3<T> tX, Vec3<T> tY, Vec3<T> tZ) noexcept : tX{tX}, tY{tY}, tZ{tZ}
	{
		// Empty.
	}

	template<class T>
	Mat33<T>::Mat33(T tXX, T tXY, T tXZ, T tYX, T tYY, T tYZ, T tZX, T tZY, T tZZ) noexcept :
		tX{tXX, tXY, tXZ},
		tY{tYX, tYY, tYZ},
		tZ{tZX, tZY, tZZ}
	{
		// Empty.
	}

	template<class T>
	Vec3<T> &Mat33<T>::operator[](std::size_t nIndex) noexcept
	{
		switch (nIndex) {
		case 0: return this->tX;

		case 1: return this->tY;

		default: return this->tZ;
		}
	}

	template<class T>
	const Vec3<T> &Mat33<T>::operator[](std::size_t nIndex) const noexcept
	{
		switch (nIndex) {
		case 0: return this->tX;

		case 1: return this->tY;

		default: return this->tZ;
		}
	}

	template<class T>
	Mat33<T> Mat33<T>::operator+() const noexcept
	{
		return *this;
	}

	template<class T>
	Mat33<T> Mat33<T>::operator-() const noexcept
	{
		return {-this->tX, -this->tY, -this->tZ};
	}

	template<class T>
	Mat33<T> &Mat33<T>::operator++() noexcept
	{
		++this->tX;
		++this->tY;
		++this->tZ;

		return *this;
	}

	template<class T>
	Mat33<T> Mat33<T>::operator++(int) noexcept
	{
		auto tResult{*this};

		++this->tX;
		++this->tY;
		++this->tZ;

		return tResult;
	}

	template<class T>
	Mat33<T> &Mat33<T>::operator--() noexcept
	{
		--this->tX;
		--this->tY;
		--this->tZ;

		return *this;
	}

	template<class T>
	Mat33<T> Mat33<T>::operator--(int) noexcept
	{
		auto tResult{*this};

		--this->tX;
		--this->tY;
		--this->tZ;

		return tResult;
	}

	template<class T>
	template<class U>
	Mat33<T> &Mat33<T>::operator+=(U uRhs) noexcept
	{
		auto tRhs{static_cast<T>(uRhs)};

		this->tX += tRhs;
		this->tY += tRhs;
		this->tZ += tRhs;

		return *this;
	}

	template<class T>
	template<class U>
	Mat33<T> &Mat33<T>::operator+=(const Vec3<U> &uRhs) noexcept
	{
		auto tRhs{static_cast<Vec3<T>>(uRhs)};

		this->tX += tRhs;
		this->tY += tRhs;
		this->tZ += tRhs;

		return *this;
	}

	template<class T>
	template<class U>
	Mat33<T> &Mat33<T>::operator+=(const Mat33<U> &uRhs) noexcept
	{
		this->tX += uRhs.tX;
		this->tY += uRhs.tY;
		this->tZ += uRhs.tZ;

		return *this;
	}

	template<class T>
	template<class U>
	Mat33<T> &Mat33<T>::operator-=(U uRhs) noexcept
	{
		auto tRhs{static_cast<T>(uRhs)};

		this->tX -= tRhs;
		this->tY -= tRhs;
		this->tZ -= tRhs;

		return *this;
	}

	template<class T>
	template<class U>
	Mat33<T> &Mat33<T>::operator-=(const Vec3<U> &uRhs) noexcept
	{
		auto tRhs{static_cast<Vec3<T>>(uRhs)};

		this->tX -= tRhs;
		this->tY -= tRhs;
		this->tZ -= tRhs;

		return *this;
	}

	template<class T>
	template<class U>
	Mat33<T> &Mat33<T>::operator-=(const Mat33<U> &uRhs) noexcept
	{
		this->tX -= uRhs.tX;
		this->tY -= uRhs.tY;
		this->tZ -= uRhs.tZ;

		return *this;
	}

	template<class T>
	template<class U>
	Mat33<T> &Mat33<T>::operator*=(U uRhs) noexcept
	{
		auto tRhs{static_cast<T>(uRhs)};

		this->tX *= tRhs;
		this->tY *= tRhs;
		this->tZ *= tRhs;

		return *this;
	}

	template<class T>
	template<class U>
	Mat33<T> &Mat33<T>::operator*=(const Vec3<U> &uRhs) noexcept
	{
		auto tRhs{static_cast<Vec3<T>>(uRhs)};

		this->tX *= tRhs;
		this->tY *= tRhs;
		this->tZ *= tRhs;

		return *this;
	}

	template<class T>
	template<class U>
	Mat33<T> &Mat33<T>::operator*=(const Mat33<U> &uRhs) noexcept
	{
		this->tX *= uRhs.tX;
		this->tY *= uRhs.tY;
		this->tZ *= uRhs.tZ;

		return *this;
	}

	template<class T>
	template<class U>
	Mat33<T> &Mat33<T>::operator/=(U uRhs) noexcept
	{
		auto tRhs{static_cast<T>(uRhs)};

		this->tX /= tRhs;
		this->tY /= tRhs;
		this->tZ /= tRhs;

		return *this;
	}

	template<class T>
	template<class U>
	Mat33<T> &Mat33<T>::operator/=(const Vec3<U> &uRhs) noexcept
	{
		auto tRhs{static_cast<Vec3<T>>(uRhs)};

		this->tX /= tRhs;
		this->tY /= tRhs;
		this->tZ /= tRhs;

		return *this;
	}

	template<class T>
	template<class U>
	Mat33<T> &Mat33<T>::operator/=(const Mat33<U> &uRhs) noexcept
	{
		this->tX /= uRhs.tX;
		this->tY /= uRhs.tY;
		this->tZ /= uRhs.tZ;

		return *this;
	}

	template<class T>
	template<class U>
	bool Mat33<T>::operator==(U uRhs) const noexcept
	{
		auto tRhs{static_cast<T>(uRhs)};

		return this->tX == tRhs && this->tY == tRhs && this->tZ == tRhs;
	}

	template<class T>
	template<class U>
	bool Mat33<T>::operator==(const Vec3<U> &uRhs) const noexcept
	{
		auto tRhs{static_cast<Vec3<T>>(uRhs)};

		return this->tX == tRhs && this->tY == tRhs && this->tZ == tRhs;
	}

	template<class T>
	template<class U>
	bool Mat33<T>::operator==(const Mat33<U> &uRhs) const noexcept
	{
		return this->tX == uRhs.tX && this->tY == uRhs.tY && this->tZ == uRhs.tZ;
	}

	template<class T>
	template<class U>
	bool Mat33<T>::operator!=(U uRhs) const noexcept
	{
		auto tRhs{static_cast<T>(uRhs)};

		return this->tX != tRhs || this->tY != tRhs || this->tZ != tRhs;
	}

	template<class T>
	template<class U>
	bool Mat33<T>::operator!=(const Vec3<U> &uRhs) const noexcept
	{
		auto tRhs{static_cast<Vec3<T>>(uRhs)};

		return this->tX != tRhs || this->tY != tRhs || this->tZ != tRhs;
	}

	template<class T>
	template<class U>
	bool Mat33<T>::operator!=(const Mat33<U> &uRhs) const noexcept
	{
		return this->tX != uRhs.tX || this->tY != uRhs.tY || this->tZ != uRhs.tZ;
	}

	template<class T>
	template<class U>
	Mat33<T>::operator Mat33<U>() const noexcept
	{
		return {static_cast<Vec3<U>>(this->tX), static_cast<Vec3<U>>(this->tY), static_cast<Vec3<U>>(this->tZ)};
	}

	template<class T>
	Mat33<T> Mat33<T>::transposed() const noexcept
	{
		return {{this->tX.tX, this->tY.tX, this->tZ.tX},
				{this->tX.tY, this->tY.tY, this->tZ.tY},
				{this->tX.tZ, this->tY.tZ, this->tZ.tZ}};
	}

	template<class T>
	Mat33<T> Mat33<T>::zero() noexcept
	{
		return {Vec3<T>::zero(), Vec3<T>::zero(), Vec3<T>::zero()};
	}

	template<class T>
	Mat33<T> Mat33<T>::one() noexcept
	{
		return {Vec3<T>::one(), Vec3<T>::one(), Vec3<T>::one()};
	}

	template<class T>
	Mat33<T> Mat33<T>::identity() noexcept
	{
		return {Vec3<T>{static_cast<T>(1), static_cast<T>(0), static_cast<T>(0)},
				Vec3<T>{static_cast<T>(0), static_cast<T>(1), static_cast<T>(0)},
				Vec3<T>{static_cast<T>(0), static_cast<T>(0), static_cast<T>(1)}};
	}

	template<class T, class U>
	Mat33<T> operator+(const Mat33<T> &tLhs, U uRhs) noexcept
	{
		auto tRhs{static_cast<T>(uRhs)};

		return {tLhs.tX + tRhs, tLhs.tY + tRhs, tLhs.tZ + tRhs};
	}

	template<class T, class U>
	Mat33<U> operator+(T tLhs, const Mat33<U> &uRhs) noexcept
	{
		auto uLhs{static_cast<U>(tLhs)};

		return {uLhs + uRhs.tX, uLhs + uRhs.tY, uLhs + uRhs.tZ};
	}

	template<class T, class U>
	Mat33<T> operator+(const Mat33<T> &tLhs, const Vec3<U> &uRhs) noexcept
	{
		auto tRhs{static_cast<Vec3<T>>(uRhs)};

		return {tLhs.tX + tRhs, tLhs.tY + tRhs, tLhs.tZ + tRhs};
	}

	template<class T, class U>
	Mat33<U> operator+(const Vec3<T> &tLhs, const Mat33<U> &uRhs) noexcept
	{
		auto uLhs{static_cast<Vec3<U>>(tLhs)};

		return {uLhs + uRhs.tX, uLhs + uRhs.tY, uLhs + uRhs.tZ};
	}

	template<class T>
	Mat33<T> operator+(const Mat33<T> &tLhs, const Mat33<T> &tRhs) noexcept
	{
		return {tLhs.tX + tRhs.tX, tLhs.tY + tRhs.tY, tLhs.tZ + tRhs.tZ};
	}

	template<class T, class U>
	Mat33<T> operator-(const Mat33<T> &tLhs, U uRhs) noexcept
	{
		auto tRhs{static_cast<T>(uRhs)};

		return {tLhs.tX - tRhs, tLhs.tY - tRhs, tLhs.tZ - tRhs};
	}

	template<class T, class U>
	Mat33<U> operator-(T tLhs, const Mat33<U> &uRhs) noexcept
	{
		auto uLhs{static_cast<U>(tLhs)};

		return {uLhs - uRhs.tX, uLhs - uRhs.tY, uLhs - uRhs.tZ};
	}

	template<class T, class U>
	Mat33<T> operator-(const Mat33<T> &tLhs, const Vec3<U> &uRhs) noexcept
	{
		auto tRhs{static_cast<Vec3<T>>(uRhs)};

		return {tLhs.tX - tRhs, tLhs.tY - tRhs, tLhs.tZ - tRhs};
	}

	template<class T, class U>
	Mat33<U> operator-(const Vec3<T> &tLhs, const Mat33<U> &uRhs) noexcept
	{
		auto uLhs{static_cast<Vec3<U>>(tLhs)};

		return {uLhs - uRhs.tX, uLhs - uRhs.tY, uLhs - uRhs.tZ};
	}

	template<class T>
	Mat33<T> operator-(const Mat33<T> &tLhs, const Mat33<T> &tRhs) noexcept
	{
		return {tLhs.tX - tRhs.tX, tLhs.tY - tRhs.tY, tLhs.tZ - tRhs.tZ};
	}

	template<class T, class U>
	Mat33<T> operator*(const Mat33<T> &tLhs, U uRhs) noexcept
	{
		auto tRhs{static_cast<T>(uRhs)};

		return {tLhs.tX * tRhs, tLhs.tY * tRhs, tLhs.tZ * tRhs};
	}

	template<class T, class U>
	Mat33<U> operator*(T tLhs, const Mat33<U> &uRhs) noexcept
	{
		auto uLhs{static_cast<U>(tLhs)};

		return {uLhs * uRhs.tX, uLhs * uRhs.tY, uLhs * uRhs.tZ};
	}

	template<class T, class U>
	Mat33<T> operator*(const Mat33<T> &tLhs, const Vec3<U> &uRhs) noexcept
	{
		auto tRhs{static_cast<Vec3<T>>(uRhs)};

		return {tLhs.tX * tRhs, tLhs.tY * tRhs, tLhs.tZ * tRhs};
	}

	template<class T, class U>
	Mat33<U> operator*(const Vec3<T> &tLhs, const Mat33<U> &uRhs) noexcept
	{
		auto uLhs{static_cast<Vec3<U>>(tLhs)};

		return {uLhs * uRhs.tX, uLhs * uRhs.tY, uLhs * uRhs.tZ};
	}

	template<class T>
	Mat33<T> operator*(const Mat33<T> &tLhs, const Mat33<T> &tRhs) noexcept
	{
		return {tLhs.tX * tRhs.tX, tLhs.tY * tRhs.tY, tLhs.tZ * tRhs.tZ};
	}

	template<class T, class U>
	Mat33<T> operator/(const Mat33<T> &tLhs, U uRhs) noexcept
	{
		auto tRhs{static_cast<T>(uRhs)};

		return {tLhs.tX / tRhs, tLhs.tY / tRhs, tLhs.tZ / tRhs};
	}

	template<class T, class U>
	Mat33<U> operator/(T tLhs, const Mat33<U> &uRhs) noexcept
	{
		auto uLhs{static_cast<U>(tLhs)};

		return {uLhs / uRhs.tX, uLhs / uRhs.tY, uLhs / uRhs.tZ};
	}

	template<class T, class U>
	Mat33<T> operator/(const Mat33<T> &tLhs, const Vec3<U> &uRhs) noexcept
	{
		auto tRhs{static_cast<Vec3<T>>(uRhs)};

		return {tLhs.tX / tRhs, tLhs.tY / tRhs, tLhs.tZ / tRhs};
	}

	template<class T, class U>
	Mat33<U> operator/(const Vec3<T> &tLhs, const Mat33<U> &uRhs) noexcept
	{
		auto uLhs{static_cast<Vec3<U>>(tLhs)};

		return {uLhs / uRhs.tX, uLhs / uRhs.tY, uLhs / uRhs.tZ};
	}

	template<class T>
	Mat33<T> operator/(const Mat33<T> &tLhs, const Mat33<T> &tRhs) noexcept
	{
		return {tLhs.tX / tRhs.tX, tLhs.tY / tRhs.tY, tLhs.tZ / tRhs.tZ};
	}

	template<class T, class U>
	Vec3<T> operator%(const Mat33<T> &tLhs, const Vec3<U> &uRhs) noexcept
	{
		auto tRhs{static_cast<Vec3<T>>(uRhs)};

		return {Vec3<T>::dot(tLhs.tX, tRhs), Vec3<T>::dot(tLhs.tY, tRhs), Vec3<T>::dot(tLhs.tZ, tRhs)};
	}

	template<class T, class U>
	Vec3<U> operator%(const Vec3<T> &tLhs, const Mat33<U> &uRhs) noexcept
	{
		auto uLhs{static_cast<Vec3<U>>(tLhs)};

		return {uLhs.tX * uRhs.tX.tX + uLhs.tY * uRhs.tY.tX + uLhs.tZ * uRhs.tZ.tX,
				uLhs.tX * uRhs.tX.tY + uLhs.tY * uRhs.tY.tY + uLhs.tZ * uRhs.tZ.tY,
				uLhs.tX * uRhs.tX.tZ + uLhs.tY * uRhs.tY.tZ + uLhs.tZ * uRhs.tZ.tZ};
	}
}	 // namespace onyx::transform

#endif