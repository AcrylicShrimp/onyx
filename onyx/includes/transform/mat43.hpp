
#ifndef _ONYX_TRANSFORM_MAT43_HPP

#define _ONYX_TRANSFORM_MAT43_HPP

namespace onyx::transform {
	template<class T>
	Mat43<T>::Mat43() noexcept : tX{Vec3<T>::zero()}, tY{Vec3<T>::zero()}, tZ{Vec3<T>::zero()}, tW{Vec3<T>::zero()}
	{
		// Empty.
	}

	template<class T>
	Mat43<T>::Mat43(Vec3<T> tX, Vec3<T> tY, Vec3<T> tZ, Vec3<T> tW) noexcept : tX{tX}, tY{tY}, tZ{tZ}, tW{tW}
	{
		// Empty.
	}

	template<class T>
	Mat43<T>::Mat43(T tXX, T tXY, T tXZ, T tYX, T tYY, T tYZ, T tZX, T tZY, T tZZ, T tWX, T tWY, T tWZ) noexcept :
		tX{tXX, tXY, tXZ},
		tY{tYX, tYY, tYZ},
		tZ{tZX, tZY, tZZ},
		tW{tWX, tWY, tWZ}
	{
		// Empty.
	}

	template<class T>
	Vec3<T> &Mat43<T>::operator[](std::size_t nIndex) noexcept
	{
		switch (nIndex) {
		case 0: return this->tX;

		case 1: return this->tY;

		case 2: return this->tZ;

		default: return this->tW;
		}
	}

	template<class T>
	const Vec3<T> &Mat43<T>::operator[](std::size_t nIndex) const noexcept
	{
		switch (nIndex) {
		case 0: return this->tX;

		case 1: return this->tY;

		case 2: return this->tZ;

		default: return this->tW;
		}
	}

	template<class T>
	Mat43<T> Mat43<T>::operator+() const noexcept
	{
		return *this;
	}

	template<class T>
	Mat43<T> Mat43<T>::operator-() const noexcept
	{
		return {-this->tX, -this->tY, -this->tZ, -this->tW};
	}

	template<class T>
	Mat43<T> &Mat43<T>::operator++() noexcept
	{
		++this->tX;
		++this->tY;
		++this->tZ;
		++this->tW;

		return *this;
	}

	template<class T>
	Mat43<T> Mat43<T>::operator++(int) noexcept
	{
		auto tResult{*this};

		++this->tX;
		++this->tY;
		++this->tZ;
		++this->tW;

		return tResult;
	}

	template<class T>
	Mat43<T> &Mat43<T>::operator--() noexcept
	{
		--this->tX;
		--this->tY;
		--this->tZ;
		--this->tW;

		return *this;
	}

	template<class T>
	Mat43<T> Mat43<T>::operator--(int) noexcept
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
	Mat43<T> &Mat43<T>::operator+=(U uRhs) noexcept
	{
		auto tRhs{static_cast<T>(uRhs)};

		this->tX += tRhs;
		this->tY += tRhs;
		this->tZ += tRhs;
		this->tW += tRhs;

		return *this;
	}

	template<class T>
	template<class U>
	Mat43<T> &Mat43<T>::operator+=(const Vec3<U> &uRhs) noexcept
	{
		auto tRhs{static_cast<Vec3<T>>(uRhs)};

		this->tX += tRhs;
		this->tY += tRhs;
		this->tZ += tRhs;
		this->tW += tRhs;

		return *this;
	}

	template<class T>
	template<class U>
	Mat43<T> &Mat43<T>::operator+=(const Mat43<U> &uRhs) noexcept
	{
		this->tX += uRhs.tX;
		this->tY += uRhs.tY;
		this->tZ += uRhs.tZ;
		this->tW += uRhs.tW;

		return *this;
	}

	template<class T>
	template<class U>
	Mat43<T> &Mat43<T>::operator-=(U uRhs) noexcept
	{
		auto tRhs{static_cast<T>(uRhs)};

		this->tX -= tRhs;
		this->tY -= tRhs;
		this->tZ -= tRhs;
		this->tW -= tRhs;

		return *this;
	}

	template<class T>
	template<class U>
	Mat43<T> &Mat43<T>::operator-=(const Vec3<U> &uRhs) noexcept
	{
		auto tRhs{static_cast<Vec3<T>>(uRhs)};

		this->tX -= tRhs;
		this->tY -= tRhs;
		this->tZ -= tRhs;
		this->tW -= tRhs;

		return *this;
	}

	template<class T>
	template<class U>
	Mat43<T> &Mat43<T>::operator-=(const Mat43<U> &uRhs) noexcept
	{
		this->tX -= uRhs.tX;
		this->tY -= uRhs.tY;
		this->tZ -= uRhs.tZ;
		this->tW -= uRhs.tW;

		return *this;
	}

	template<class T>
	template<class U>
	Mat43<T> &Mat43<T>::operator*=(U uRhs) noexcept
	{
		auto tRhs{static_cast<T>(uRhs)};

		this->tX *= tRhs;
		this->tY *= tRhs;
		this->tZ *= tRhs;
		this->tW *= tRhs;

		return *this;
	}

	template<class T>
	template<class U>
	Mat43<T> &Mat43<T>::operator*=(const Vec3<U> &uRhs) noexcept
	{
		auto tRhs{static_cast<Vec3<T>>(uRhs)};

		this->tX *= tRhs;
		this->tY *= tRhs;
		this->tZ *= tRhs;
		this->tW *= tRhs;

		return *this;
	}

	template<class T>
	template<class U>
	Mat43<T> &Mat43<T>::operator*=(const Mat43<U> &uRhs) noexcept
	{
		this->tX *= uRhs.tX;
		this->tY *= uRhs.tY;
		this->tZ *= uRhs.tZ;
		this->tW *= uRhs.tW;

		return *this;
	}

	template<class T>
	template<class U>
	Mat43<T> &Mat43<T>::operator/=(U uRhs) noexcept
	{
		auto tRhs{static_cast<T>(uRhs)};

		this->tX /= tRhs;
		this->tY /= tRhs;
		this->tZ /= tRhs;
		this->tW /= tRhs;

		return *this;
	}

	template<class T>
	template<class U>
	Mat43<T> &Mat43<T>::operator/=(const Vec3<U> &uRhs) noexcept
	{
		auto tRhs{static_cast<Vec3<T>>(uRhs)};

		this->tX /= tRhs;
		this->tY /= tRhs;
		this->tZ /= tRhs;
		this->tW /= tRhs;

		return *this;
	}

	template<class T>
	template<class U>
	Mat43<T> &Mat43<T>::operator/=(const Mat43<U> &uRhs) noexcept
	{
		this->tX /= uRhs.tX;
		this->tY /= uRhs.tY;
		this->tZ /= uRhs.tZ;
		this->tW /= uRhs.tW;

		return *this;
	}

	template<class T>
	template<class U>
	bool Mat43<T>::operator==(U uRhs) const noexcept
	{
		auto tRhs{static_cast<T>(uRhs)};

		return this->tX == tRhs && this->tY == tRhs && this->tZ == tRhs && this->tW == tRhs;
	}

	template<class T>
	template<class U>
	bool Mat43<T>::operator==(const Vec3<U> &uRhs) const noexcept
	{
		auto tRhs{static_cast<Vec3<T>>(uRhs)};

		return this->tX == tRhs && this->tY == tRhs && this->tZ == tRhs && this->tW == tRhs;
	}

	template<class T>
	template<class U>
	bool Mat43<T>::operator==(const Mat43<U> &uRhs) const noexcept
	{
		return this->tX == uRhs.tX && this->tY == uRhs.tY && this->tZ == uRhs.tZ && this->tW == uRhs.tW;
	}

	template<class T>
	template<class U>
	bool Mat43<T>::operator!=(U uRhs) const noexcept
	{
		auto tRhs{static_cast<T>(uRhs)};

		return this->tX != tRhs || this->tY != tRhs || this->tZ != tRhs || this->tW != tRhs;
	}

	template<class T>
	template<class U>
	bool Mat43<T>::operator!=(const Vec3<U> &uRhs) const noexcept
	{
		auto tRhs{static_cast<Vec3<T>>(uRhs)};

		return this->tX != tRhs || this->tY != tRhs || this->tZ != tRhs || this->tW != tRhs;
	}

	template<class T>
	template<class U>
	bool Mat43<T>::operator!=(const Mat43<U> &uRhs) const noexcept
	{
		return this->tX != uRhs.tX || this->tY != uRhs.tY || this->tZ != uRhs.tZ || this->tW != uRhs.tW;
	}

	template<class T>
	template<class U>
	Mat43<T>::operator Mat43<U>() const noexcept
	{
		return {static_cast<Vec3<U>>(this->tX),
				static_cast<Vec3<U>>(this->tY),
				static_cast<Vec3<U>>(this->tZ),
				static_cast<Vec3<U>>(this->tW)};
	}

	template<class T>
	Mat34<T> Mat43<T>::transposed() const noexcept
	{
		return {{this->tX.tX, this->tY.tX, this->tZ.tX, this->tW.tX},
				{this->tX.tY, this->tY.tY, this->tZ.tY, this->tW.tY},
				{this->tX.tZ, this->tY.tZ, this->tZ.tZ, this->tW.tZ}};
	}

	template<class T>
	Mat43<T> Mat43<T>::zero() noexcept
	{
		return {Vec3<T>::zero(), Vec3<T>::zero(), Vec3<T>::zero(), Vec3<T>::zero()};
	}

	template<class T>
	Mat43<T> Mat43<T>::one() noexcept
	{
		return {Vec3<T>::one(), Vec3<T>::one(), Vec3<T>::one(), Vec3<T>::one()};
	}

	template<class T, class U>
	Mat43<T> operator+(const Mat43<T> &tLhs, U uRhs) noexcept
	{
		auto tRhs{static_cast<T>(uRhs)};

		return {tLhs.tX + tRhs, tLhs.tY + tRhs, tLhs.tZ + tRhs, tLhs.tW + tRhs};
	}

	template<class T, class U>
	Mat43<U> operator+(T tLhs, const Mat43<U> &uRhs) noexcept
	{
		auto uLhs{static_cast<U>(tLhs)};

		return {uLhs + uRhs.tX, uLhs + uRhs.tY, uLhs + uRhs.tZ, uLhs + uRhs.tW};
	}

	template<class T, class U>
	Mat43<T> operator+(const Mat43<T> &tLhs, const Vec3<U> &uRhs) noexcept
	{
		auto tRhs{static_cast<Vec3<T>>(uRhs)};

		return {tLhs.tX + tRhs, tLhs.tY + tRhs, tLhs.tZ + tRhs, tLhs.tW + tRhs};
	}

	template<class T, class U>
	Mat43<U> operator+(const Vec3<T> &tLhs, const Mat43<U> &uRhs) noexcept
	{
		auto uLhs{static_cast<Vec3<U>>(tLhs)};

		return {uLhs + uRhs.tX, uLhs + uRhs.tY, uLhs + uRhs.tZ, uLhs + uRhs.tW};
	}

	template<class T>
	Mat43<T> operator+(const Mat43<T> &tLhs, const Mat43<T> &tRhs) noexcept
	{
		return {tLhs.tX + tRhs.tX, tLhs.tY + tRhs.tY, tLhs.tZ + tRhs.tZ, tLhs.tW + tRhs.tW};
	}

	template<class T, class U>
	Mat43<T> operator-(const Mat43<T> &tLhs, U uRhs) noexcept
	{
		auto tRhs{static_cast<T>(uRhs)};

		return {tLhs.tX - tRhs, tLhs.tY - tRhs, tLhs.tZ - tRhs, tLhs.tW - tRhs};
	}

	template<class T, class U>
	Mat43<U> operator-(T tLhs, const Mat43<U> &uRhs) noexcept
	{
		auto uLhs{static_cast<U>(tLhs)};

		return {uLhs - uRhs.tX, uLhs - uRhs.tY, uLhs - uRhs.tZ, uLhs - uRhs.tW};
	}

	template<class T, class U>
	Mat43<T> operator-(const Mat43<T> &tLhs, const Vec3<U> &uRhs) noexcept
	{
		auto tRhs{static_cast<Vec3<T>>(uRhs)};

		return {tLhs.tX - tRhs, tLhs.tY - tRhs, tLhs.tZ - tRhs, tLhs.tW - tRhs};
	}

	template<class T, class U>
	Mat43<U> operator-(const Vec3<T> &tLhs, const Mat43<U> &uRhs) noexcept
	{
		auto uLhs{static_cast<Vec3<U>>(tLhs)};

		return {uLhs - uRhs.tX, uLhs - uRhs.tY, uLhs - uRhs.tZ, uLhs - uRhs.tW};
	}

	template<class T>
	Mat43<T> operator-(const Mat43<T> &tLhs, const Mat43<T> &tRhs) noexcept
	{
		return {tLhs.tX - tRhs.tX, tLhs.tY - tRhs.tY, tLhs.tZ - tRhs.tZ, tLhs.tW - tRhs.tW};
	}

	template<class T, class U>
	Mat43<T> operator*(const Mat43<T> &tLhs, U uRhs) noexcept
	{
		auto tRhs{static_cast<T>(uRhs)};

		return {tLhs.tX * tRhs, tLhs.tY * tRhs, tLhs.tZ * tRhs, tLhs.tW * tRhs};
	}

	template<class T, class U>
	Mat43<U> operator*(T tLhs, const Mat43<U> &uRhs) noexcept
	{
		auto uLhs{static_cast<U>(tLhs)};

		return {uLhs * uRhs.tX, uLhs * uRhs.tY, uLhs * uRhs.tZ, uLhs * uRhs.tW};
	}

	template<class T, class U>
	Mat43<T> operator*(const Mat43<T> &tLhs, const Vec3<U> &uRhs) noexcept
	{
		auto tRhs{static_cast<Vec3<T>>(uRhs)};

		return {tLhs.tX * tRhs, tLhs.tY * tRhs, tLhs.tZ * tRhs, tLhs.tW * tRhs};
	}

	template<class T, class U>
	Mat43<U> operator*(const Vec3<T> &tLhs, const Mat43<U> &uRhs) noexcept
	{
		auto uLhs{static_cast<Vec3<U>>(tLhs)};

		return {uLhs * uRhs.tX, uLhs * uRhs.tY, uLhs * uRhs.tZ, uLhs * uRhs.tW};
	}

	template<class T>
	Mat43<T> operator*(const Mat43<T> &tLhs, const Mat43<T> &tRhs) noexcept
	{
		return {tLhs.tX * tRhs.tX, tLhs.tY * tRhs.tY, tLhs.tZ * tRhs.tZ, tLhs.tW * tRhs.tW};
	}

	template<class T, class U>
	Mat43<T> operator/(const Mat43<T> &tLhs, U uRhs) noexcept
	{
		auto tRhs{static_cast<T>(uRhs)};

		return {tLhs.tX / tRhs, tLhs.tY / tRhs, tLhs.tZ / tRhs, tLhs.tW / tRhs};
	}

	template<class T, class U>
	Mat43<U> operator/(T tLhs, const Mat43<U> &uRhs) noexcept
	{
		auto uLhs{static_cast<U>(tLhs)};

		return {uLhs / uRhs.tX, uLhs / uRhs.tY, uLhs / uRhs.tZ, uLhs / uRhs.tW};
	}

	template<class T, class U>
	Mat43<T> operator/(const Mat43<T> &tLhs, const Vec3<U> &uRhs) noexcept
	{
		auto tRhs{static_cast<Vec3<T>>(uRhs)};

		return {tLhs.tX / tRhs, tLhs.tY / tRhs, tLhs.tZ / tRhs, tLhs.tW / tRhs};
	}

	template<class T, class U>
	Mat43<U> operator/(const Vec3<T> &tLhs, const Mat43<U> &uRhs) noexcept
	{
		auto uLhs{static_cast<Vec3<U>>(tLhs)};

		return {uLhs / uRhs.tX, uLhs / uRhs.tY, uLhs / uRhs.tZ, uLhs / uRhs.tW};
	}

	template<class T>
	Mat43<T> operator/(const Mat43<T> &tLhs, const Mat43<T> &tRhs) noexcept
	{
		return {tLhs.tX / tRhs.tX, tLhs.tY / tRhs.tY, tLhs.tZ / tRhs.tZ, tLhs.tW / tRhs.tW};
	}

	template<class T, class U>
	Vec4<T> operator%(const Mat43<T> &tLhs, const Vec3<U> &uRhs) noexcept
	{
		auto tRhs{static_cast<Vec3<T>>(uRhs)};

		return {Vec3<T>::dot(tLhs.tX, tRhs),
				Vec3<T>::dot(tLhs.tY, tRhs),
				Vec3<T>::dot(tLhs.tZ, tRhs),
				Vec3<T>::dot(tLhs.tW, tRhs)};
	}

	template<class T, class U>
	Vec3<U> operator%(const Vec4<T> &tLhs, const Mat43<U> &uRhs) noexcept
	{
		auto uLhs{static_cast<Vec4<U>>(tLhs)};

		return {uLhs.tX * uRhs.tX.tX + uLhs.tY * uRhs.tY.tX + uLhs.tZ * uRhs.tZ.tX + uLhs.tZ * uRhs.tW.tX,
				uLhs.tX * uRhs.tX.tY + uLhs.tY * uRhs.tY.tY + uLhs.tZ * uRhs.tZ.tY + uLhs.tZ * uRhs.tW.tY,
				uLhs.tX * uRhs.tX.tZ + uLhs.tY * uRhs.tY.tZ + uLhs.tZ * uRhs.tZ.tZ + uLhs.tZ * uRhs.tW.tZ};
	}
}	 // namespace onyx::transform

#endif