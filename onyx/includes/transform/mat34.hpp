
#ifndef _ONYX_TRANSFORM_MAT34_HPP

#define _ONYX_TRANSFORM_MAT34_HPP

namespace onyx::transform {
	template<class T>
	Mat34<T>::Mat34() noexcept : tX{Vec4<T>::zero()}, tY{Vec4<T>::zero()}, tZ{Vec4<T>::zero()}
	{
		// Empty.
	}

	template<class T>
	Mat34<T>::Mat34(Vec4<T> tX, Vec4<T> tY, Vec4<T> tZ) noexcept : tX{tX}, tY{tY}, tZ{tZ}
	{
		// Empty.
	}

	template<class T>
	Mat34<T>::Mat34(T tXX, T tXY, T tXZ, T tXW, T tYX, T tYY, T tYZ, T tYW, T tZX, T tZY, T tZZ, T tZW) noexcept :
		tX{tXX, tXY, tXZ, tXW},
		tY{tYX, tYY, tYZ, tYW},
		tZ{tZX, tZY, tZZ, tZW}
	{
		// Empty.
	}

	template<class T>
	Vec4<T> &Mat34<T>::operator[](std::size_t nIndex) noexcept
	{
		switch (nIndex) {
		case 0: return this->tX;

		case 1: return this->tY;

		default: return this->tZ;
		}
	}

	template<class T>
	const Vec4<T> &Mat34<T>::operator[](std::size_t nIndex) const noexcept
	{
		switch (nIndex) {
		case 0: return this->tX;

		case 1: return this->tY;

		default: return this->tZ;
		}
	}

	template<class T>
	Mat34<T> Mat34<T>::operator+() const noexcept
	{
		return *this;
	}

	template<class T>
	Mat34<T> Mat34<T>::operator-() const noexcept
	{
		return {-this->tX, -this->tY, -this->tZ};
	}

	template<class T>
	Mat34<T> &Mat34<T>::operator++() noexcept
	{
		++this->tX;
		++this->tY;
		++this->tZ;

		return *this;
	}

	template<class T>
	Mat34<T> Mat34<T>::operator++(int) noexcept
	{
		auto tResult{*this};

		++this->tX;
		++this->tY;
		++this->tZ;

		return tResult;
	}

	template<class T>
	Mat34<T> &Mat34<T>::operator--() noexcept
	{
		--this->tX;
		--this->tY;
		--this->tZ;

		return *this;
	}

	template<class T>
	Mat34<T> Mat34<T>::operator--(int) noexcept
	{
		auto tResult{*this};

		--this->tX;
		--this->tY;
		--this->tZ;

		return tResult;
	}

	template<class T>
	template<class U>
	Mat34<T> &Mat34<T>::operator+=(U uRhs) noexcept
	{
		auto tRhs{static_cast<T>(uRhs)};

		this->tX += tRhs;
		this->tY += tRhs;
		this->tZ += tRhs;

		return *this;
	}

	template<class T>
	template<class U>
	Mat34<T> &Mat34<T>::operator+=(const Vec4<U> &uRhs) noexcept
	{
		auto tRhs{static_cast<Vec4<T>>(uRhs)};

		this->tX += tRhs;
		this->tY += tRhs;
		this->tZ += tRhs;

		return *this;
	}

	template<class T>
	template<class U>
	Mat34<T> &Mat34<T>::operator+=(const Mat34<U> &uRhs) noexcept
	{
		this->tX += uRhs.tX;
		this->tY += uRhs.tY;
		this->tZ += uRhs.tZ;

		return *this;
	}

	template<class T>
	template<class U>
	Mat34<T> &Mat34<T>::operator-=(U uRhs) noexcept
	{
		auto tRhs{static_cast<T>(uRhs)};

		this->tX -= tRhs;
		this->tY -= tRhs;
		this->tZ -= tRhs;

		return *this;
	}

	template<class T>
	template<class U>
	Mat34<T> &Mat34<T>::operator-=(const Vec4<U> &uRhs) noexcept
	{
		auto tRhs{static_cast<Vec4<T>>(uRhs)};

		this->tX -= tRhs;
		this->tY -= tRhs;
		this->tZ -= tRhs;

		return *this;
	}

	template<class T>
	template<class U>
	Mat34<T> &Mat34<T>::operator-=(const Mat34<U> &uRhs) noexcept
	{
		this->tX -= uRhs.tX;
		this->tY -= uRhs.tY;
		this->tZ -= uRhs.tZ;

		return *this;
	}

	template<class T>
	template<class U>
	Mat34<T> &Mat34<T>::operator*=(U uRhs) noexcept
	{
		auto tRhs{static_cast<T>(uRhs)};

		this->tX *= tRhs;
		this->tY *= tRhs;
		this->tZ *= tRhs;

		return *this;
	}

	template<class T>
	template<class U>
	Mat34<T> &Mat34<T>::operator*=(const Vec4<U> &uRhs) noexcept
	{
		auto tRhs{static_cast<Vec4<T>>(uRhs)};

		this->tX *= tRhs;
		this->tY *= tRhs;
		this->tZ *= tRhs;

		return *this;
	}

	template<class T>
	template<class U>
	Mat34<T> &Mat34<T>::operator*=(const Mat34<U> &uRhs) noexcept
	{
		this->tX *= uRhs.tX;
		this->tY *= uRhs.tY;
		this->tZ *= uRhs.tZ;

		return *this;
	}

	template<class T>
	template<class U>
	Mat34<T> &Mat34<T>::operator/=(U uRhs) noexcept
	{
		auto tRhs{static_cast<T>(uRhs)};

		this->tX /= tRhs;
		this->tY /= tRhs;
		this->tZ /= tRhs;

		return *this;
	}

	template<class T>
	template<class U>
	Mat34<T> &Mat34<T>::operator/=(const Vec4<U> &uRhs) noexcept
	{
		auto tRhs{static_cast<Vec4<T>>(uRhs)};

		this->tX /= tRhs;
		this->tY /= tRhs;
		this->tZ /= tRhs;

		return *this;
	}

	template<class T>
	template<class U>
	Mat34<T> &Mat34<T>::operator/=(const Mat34<U> &uRhs) noexcept
	{
		this->tX /= uRhs.tX;
		this->tY /= uRhs.tY;
		this->tZ /= uRhs.tZ;

		return *this;
	}

	template<class T>
	template<class U>
	bool Mat34<T>::operator==(U uRhs) const noexcept
	{
		auto tRhs{static_cast<T>(uRhs)};

		return this->tX == tRhs && this->tY == tRhs && this->tZ == tRhs;
	}

	template<class T>
	template<class U>
	bool Mat34<T>::operator==(const Vec4<U> &uRhs) const noexcept
	{
		auto tRhs{static_cast<Vec4<T>>(uRhs)};

		return this->tX == tRhs && this->tY == tRhs && this->tZ == tRhs;
	}

	template<class T>
	template<class U>
	bool Mat34<T>::operator==(const Mat34<U> &uRhs) const noexcept
	{
		return this->tX == uRhs.tX && this->tY == uRhs.tY && this->tZ == uRhs.tZ;
	}

	template<class T>
	template<class U>
	bool Mat34<T>::operator!=(U uRhs) const noexcept
	{
		auto tRhs{static_cast<T>(uRhs)};

		return this->tX != tRhs || this->tY != tRhs || this->tZ != tRhs;
	}

	template<class T>
	template<class U>
	bool Mat34<T>::operator!=(const Vec4<U> &uRhs) const noexcept
	{
		auto tRhs{static_cast<Vec4<T>>(uRhs)};

		return this->tX != tRhs || this->tY != tRhs || this->tZ != tRhs;
	}

	template<class T>
	template<class U>
	bool Mat34<T>::operator!=(const Mat34<U> &uRhs) const noexcept
	{
		return this->tX != uRhs.tX || this->tY != uRhs.tY || this->tZ != uRhs.tZ;
	}

	template<class T>
	template<class U>
	Mat34<T>::operator Mat34<U>() const noexcept
	{
		return {static_cast<Vec4<U>>(this->tX), static_cast<Vec4<U>>(this->tY), static_cast<Vec4<U>>(this->tZ)};
	}

	template<class T>
	Mat43<T> Mat34<T>::transposed() const noexcept
	{
		return {{this->tX.tX, this->tY.tX, this->tZ.tX},
				{this->tX.tY, this->tY.tY, this->tZ.tY},
				{this->tX.tZ, this->tY.tZ, this->tZ.tZ},
				{this->tX.tW, this->tY.tW, this->tZ.tW}};
	}

	template<class T>
	Mat34<T> Mat34<T>::zero() noexcept
	{
		return {Vec4<T>::zero(), Vec4<T>::zero(), Vec4<T>::zero()};
	}

	template<class T>
	Mat34<T> Mat34<T>::one() noexcept
	{
		return {Vec4<T>::one(), Vec4<T>::one(), Vec4<T>::one()};
	}

	template<class T>
	Mat34<T> Mat34<T>::identity() noexcept
	{
		return {Vec4<T>{static_cast<T>(1), static_cast<T>(0), static_cast<T>(0)},
				Vec4<T>{static_cast<T>(0), static_cast<T>(1), static_cast<T>(0)},
				Vec4<T>{static_cast<T>(0), static_cast<T>(0), static_cast<T>(1)}};
	}

	template<class T, class U>
	Mat34<T> operator+(const Mat34<T> &tLhs, U uRhs) noexcept
	{
		auto tRhs{static_cast<T>(uRhs)};

		return {tLhs.tX + tRhs, tLhs.tY + tRhs, tLhs.tZ + tRhs};
	}

	template<class T, class U>
	Mat34<U> operator+(T tLhs, const Mat34<U> &uRhs) noexcept
	{
		auto tLhs{static_cast<U>(tLhs)};

		return {tLhs + uRhs.tX, tLhs + uRhs.tY, tLhs + uRhs.tZ};
	}

	template<class T, class U>
	Mat34<T> operator+(const Mat34<T> &tLhs, const Vec4<U> &uRhs) noexcept
	{
		auto tRhs{static_cast<Vec4<T>>(uRhs)};

		return {tLhs.tX + tRhs, tLhs.tY + tRhs, tLhs.tZ + tRhs};
	}

	template<class T, class U>
	Mat34<U> operator+(const Vec4<T> &tLhs, const Mat34<U> &uRhs) noexcept
	{
		auto uLhs{static_cast<Vec4<U>>(tLhs)};

		return {uLhs + uRhs.tX, uLhs + uRhs.tY, uLhs + uRhs.tZ};
	}

	template<class T>
	Mat34<T> operator+(const Mat34<T> &tLhs, const Mat34<T> &tRhs) noexcept
	{
		return {tLhs.tX + tRhs.tX, tLhs.tY + tRhs.tY, tLhs.tZ + tRhs.tZ};
	}

	template<class T, class U>
	Mat34<T> operator-(const Mat34<T> &tLhs, U uRhs) noexcept
	{
		auto tRhs{static_cast<T>(uRhs)};

		return {tLhs.tX - tRhs, tLhs.tY - tRhs, tLhs.tZ - tRhs};
	}

	template<class T, class U>
	Mat34<U> operator-(T tLhs, const Mat34<U> &uRhs) noexcept
	{
		auto uLhs{static_cast<U>(tLhs)};

		return {uLhs - uRhs.tX, uLhs - uRhs.tY, uLhs - uRhs.tZ};
	}

	template<class T, class U>
	Mat34<T> operator-(const Mat34<T> &tLhs, const Vec4<U> &uRhs) noexcept
	{
		auto tRhs{static_cast<Vec4<T>>(uRhs)};

		return {tLhs.tX - tRhs, tLhs.tY - tRhs, tLhs.tZ - tRhs};
	}

	template<class T, class U>
	Mat34<U> operator-(const Vec4<T> &tLhs, const Mat34<U> &uRhs) noexcept
	{
		auto uLhs{static_cast<Vec4<U>>(tLhs)};

		return {uLhs - uRhs.tX, uLhs - uRhs.tY, uLhs - uRhs.tZ};
	}

	template<class T>
	Mat34<T> operator-(const Mat34<T> &tLhs, const Mat34<T> &tRhs) noexcept
	{
		return {tLhs.tX - tRhs.tX, tLhs.tY - tRhs.tY, tLhs.tZ - tRhs.tZ};
	}

	template<class T, class U>
	Mat34<T> operator*(const Mat34<T> &tLhs, U uRhs) noexcept
	{
		auto tRhs{static_cast<T>(uRhs)};

		return {tLhs.tX * tRhs, tLhs.tY * tRhs, tLhs.tZ * tRhs};
	}

	template<class T, class U>
	Mat34<U> operator*(T tLhs, const Mat34<U> &uRhs) noexcept
	{
		auto uLhs{static_cast<U>(tLhs)};

		return {uLhs * uRhs.tX, uLhs * uRhs.tY, uLhs * uRhs.tZ};
	}

	template<class T, class U>
	Mat34<T> operator*(const Mat34<T> &tLhs, const Vec4<U> &uRhs) noexcept
	{
		auto tRhs{static_cast<Vec4<T>>(uRhs)};

		return {tLhs.tX * tRhs, tLhs.tY * tRhs, tLhs.tZ * tRhs};
	}

	template<class T, class U>
	Mat34<U> operator*(const Vec4<T> &tLhs, const Mat34<U> &uRhs) noexcept
	{
		auto uLhs{static_cast<Vec4<U>>(tLhs)};

		return {uLhs * uRhs.tX, uLhs * uRhs.tY, uLhs * uRhs.tZ};
	}

	template<class T>
	Mat34<T> operator*(const Mat34<T> &tLhs, const Mat34<T> &tRhs) noexcept
	{
		return {tLhs.tX * tRhs.tX, tLhs.tY * tRhs.tY, tLhs.tZ * tRhs.tZ};
	}

	template<class T, class U>
	Mat34<T> operator/(const Mat34<T> &tLhs, U uRhs) noexcept
	{
		auto tRhs{static_cast<T>(uRhs)};

		return {tLhs.tX / tRhs, tLhs.tY / tRhs, tLhs.tZ / tRhs};
	}

	template<class T, class U>
	Mat34<U> operator/(T tLhs, const Mat34<U> &uRhs) noexcept
	{
		auto uLhs{static_cast<U>(tLhs)};

		return {uLhs / uRhs.tX, uLhs / uRhs.tY, uLhs / uRhs.tZ};
	}

	template<class T, class U>
	Mat34<T> operator/(const Mat34<T> &tLhs, const Vec4<U> &uRhs) noexcept
	{
		auto tRhs{static_cast<Vec4<T>>(uRhs)};

		return {tLhs.tX / tRhs, tLhs.tY / tRhs, tLhs.tZ / tRhs};
	}

	template<class T, class U>
	Mat34<U> operator/(const Vec4<T> &tLhs, const Mat34<U> &uRhs) noexcept
	{
		auto uLhs{static_cast<Vec4<U>>(tLhs)};

		return {uLhs / uRhs.tX, uLhs / uRhs.tY, uLhs / uRhs.tZ};
	}

	template<class T>
	Mat34<T> operator/(const Mat34<T> &tLhs, const Mat34<T> &tRhs) noexcept
	{
		return {tLhs.tX / tRhs.tX, tLhs.tY / tRhs.tY, tLhs.tZ / tRhs.tZ};
	}

	template<class T, class U>
	Vec3<T> operator%(const Mat34<T> &tLhs, const Vec4<U> &uRhs) noexcept
	{
		auto tRhs{static_cast<Vec4<T>>(uRhs)};

		return {Vec4<T>::dot(tLhs.tX, tRhs), Vec4<T>::dot(tLhs.tY, tRhs), Vec4<T>::dot(tLhs.tZ, tRhs)};
	}

	template<class T, class U>
	Vec4<U> operator%(const Vec3<T> &tLhs, const Mat34<U> &uRhs) noexcept
	{
		auto uLhs{static_cast<Vec3<U>>(tLhs)};

		return {uLhs.tX * uRhs.tX.tX + uLhs.tY * uRhs.tY.tX + uLhs.tZ * uRhs.tZ.tX,
				uLhs.tX * uRhs.tX.tY + uLhs.tY * uRhs.tY.tY + uLhs.tZ * uRhs.tZ.tY,
				uLhs.tX * uRhs.tX.tZ + uLhs.tY * uRhs.tY.tZ + uLhs.tZ * uRhs.tZ.tZ,
				uLhs.tX * uRhs.tX.tW + uLhs.tY * uRhs.tY.tW + uLhs.tZ * uRhs.tZ.tW};
	}
}	 // namespace onyx::transform

#endif