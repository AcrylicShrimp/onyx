
#ifndef _ONYX_TRANSFORM_MAT44_HPP

#define _ONYX_TRANSFORM_MAT44_HPP

namespace onyx::transform {
	template<class T>
	Mat44<T>::Mat44() noexcept : tX{Vec4<T>::zero()}, tY{Vec4<T>::zero()}, tZ{Vec4<T>::zero()}, tW{Vec4<T>::zero()}
	{
		// Empty.
	}

	template<class T>
	Mat44<T>::Mat44(Vec4<T> tX, Vec4<T> tY, Vec4<T> tZ, Vec4<T> tW) noexcept : tX{tX}, tY{tY}, tZ{tZ}, tW{tW}
	{
		// Empty.
	}

	template<class T>
	Mat44<T>::Mat44(
		T tXX,
		T tXY,
		T tXZ,
		T tXW,
		T tYX,
		T tYY,
		T tYZ,
		T tYW,
		T tZX,
		T tZY,
		T tZZ,
		T tZW,
		T tWX,
		T tWY,
		T tWZ,
		T tWW) noexcept :
		tX{tXX, tXY, tXZ, tXW},
		tY{tYX, tYY, tYZ, tYW},
		tZ{tZX, tZY, tZZ, tZW},
		tW{tWX, tWY, tWZ, tWW}
	{
		// Empty.
	}

	template<class T>
	Vec4<T> &Mat44<T>::operator[](std::size_t nIndex) noexcept
	{
		switch (nIndex) {
		case 0: return this->tX;

		case 1: return this->tY;

		case 2: return this->tZ;

		default: return this->tW;
		}
	}

	template<class T>
	const Vec4<T> &Mat44<T>::operator[](std::size_t nIndex) const noexcept
	{
		switch (nIndex) {
		case 0: return this->tX;

		case 1: return this->tY;

		case 2: return this->tZ;

		default: return this->tW;
		}
	}

	template<class T>
	Mat44<T> Mat44<T>::operator+() const noexcept
	{
		return *this;
	}

	template<class T>
	Mat44<T> Mat44<T>::operator-() const noexcept
	{
		return {-this->tX, -this->tY, -this->tZ, -this->tW};
	}

	template<class T>
	Mat44<T> &Mat44<T>::operator++() noexcept
	{
		++this->tX;
		++this->tY;
		++this->tZ;
		++this->tW;

		return *this;
	}

	template<class T>
	Mat44<T> Mat44<T>::operator++(int) noexcept
	{
		auto tResult{*this};

		++this->tX;
		++this->tY;
		++this->tZ;
		++this->tW;

		return tResult;
	}

	template<class T>
	Mat44<T> &Mat44<T>::operator--() noexcept
	{
		--this->tX;
		--this->tY;
		--this->tZ;
		--this->tW;

		return *this;
	}

	template<class T>
	Mat44<T> Mat44<T>::operator--(int) noexcept
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
	Mat44<T> &Mat44<T>::operator+=(U uRhs) noexcept
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
	Mat44<T> &Mat44<T>::operator+=(const Vec4<U> &uRhs) noexcept
	{
		auto tRhs{static_cast<Vec4<T>>(uRhs)};

		this->tX += tRhs;
		this->tY += tRhs;
		this->tZ += tRhs;
		this->tW += tRhs;

		return *this;
	}

	template<class T>
	template<class U>
	Mat44<T> &Mat44<T>::operator+=(const Mat44<U> &uRhs) noexcept
	{
		this->tX += uRhs.tX;
		this->tY += uRhs.tY;
		this->tZ += uRhs.tZ;
		this->tW += uRhs.tW;

		return *this;
	}

	template<class T>
	template<class U>
	Mat44<T> &Mat44<T>::operator-=(U uRhs) noexcept
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
	Mat44<T> &Mat44<T>::operator-=(const Vec4<U> &uRhs) noexcept
	{
		auto tRhs{static_cast<Vec4<T>>(uRhs)};

		this->tX -= tRhs;
		this->tY -= tRhs;
		this->tZ -= tRhs;
		this->tW -= tRhs;

		return *this;
	}

	template<class T>
	template<class U>
	Mat44<T> &Mat44<T>::operator-=(const Mat44<U> &uRhs) noexcept
	{
		this->tX -= uRhs.tX;
		this->tY -= uRhs.tY;
		this->tZ -= uRhs.tZ;
		this->tW -= uRhs.tW;

		return *this;
	}

	template<class T>
	template<class U>
	Mat44<T> &Mat44<T>::operator*=(U uRhs) noexcept
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
	Mat44<T> &Mat44<T>::operator*=(const Vec4<U> &uRhs) noexcept
	{
		auto tRhs{static_cast<Vec4<T>>(uRhs)};

		this->tX *= tRhs;
		this->tY *= tRhs;
		this->tZ *= tRhs;
		this->tW *= tRhs;

		return *this;
	}

	template<class T>
	template<class U>
	Mat44<T> &Mat44<T>::operator*=(const Mat44<U> &uRhs) noexcept
	{
		this->tX *= uRhs.tX;
		this->tY *= uRhs.tY;
		this->tZ *= uRhs.tZ;
		this->tW *= uRhs.tW;

		return *this;
	}

	template<class T>
	template<class U>
	Mat44<T> &Mat44<T>::operator/=(U uRhs) noexcept
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
	Mat44<T> &Mat44<T>::operator/=(const Vec4<U> &uRhs) noexcept
	{
		auto tRhs{static_cast<Vec4<T>>(uRhs)};

		this->tX /= tRhs;
		this->tY /= tRhs;
		this->tZ /= tRhs;
		this->tW /= tRhs;

		return *this;
	}

	template<class T>
	template<class U>
	Mat44<T> &Mat44<T>::operator/=(const Mat44<U> &uRhs) noexcept
	{
		this->tX /= uRhs.tX;
		this->tY /= uRhs.tY;
		this->tZ /= uRhs.tZ;
		this->tW /= uRhs.tW;

		return *this;
	}

	template<class T>
	template<class U>
	bool Mat44<T>::operator==(U uRhs) const noexcept
	{
		auto tRhs{static_cast<T>(uRhs)};

		return this->tX == tRhs && this->tY == tRhs && this->tZ == tRhs && this->tW == tRhs;
	}

	template<class T>
	template<class U>
	bool Mat44<T>::operator==(const Vec4<U> &uRhs) const noexcept
	{
		auto tRhs{static_cast<Vec4<T>>(uRhs)};

		return this->tX == tRhs && this->tY == tRhs && this->tZ == tRhs && this->tW == tRhs;
	}

	template<class T>
	template<class U>
	bool Mat44<T>::operator==(const Mat44<U> &uRhs) const noexcept
	{
		return this->tX == uRhs.tX && this->tY == uRhs.tY && this->tZ == uRhs.tZ && this->tW == uRhs.tW;
	}

	template<class T>
	template<class U>
	bool Mat44<T>::operator!=(U uRhs) const noexcept
	{
		auto tRhs{static_cast<T>(uRhs)};

		return this->tX != tRhs || this->tY != tRhs || this->tZ != tRhs || this->tW != tRhs;
	}

	template<class T>
	template<class U>
	bool Mat44<T>::operator!=(const Vec4<U> &uRhs) const noexcept
	{
		auto tRhs{static_cast<Vec4<T>>(uRhs)};

		return this->tX != tRhs || this->tY != tRhs || this->tZ != tRhs || this->tW != tRhs;
	}

	template<class T>
	template<class U>
	bool Mat44<T>::operator!=(const Mat44<U> &uRhs) const noexcept
	{
		return this->tX != uRhs.tX || this->tY != uRhs.tY || this->tZ != uRhs.tZ || this->tW != uRhs.tW;
	}

	template<class T>
	template<class U>
	Mat44<T>::operator Mat44<U>() const noexcept
	{
		return {static_cast<Vec4<U>>(this->tX),
				static_cast<Vec4<U>>(this->tY),
				static_cast<Vec4<U>>(this->tZ),
				static_cast<Vec4<U>>(this->tW)};
	}

	template<class T>
	Mat44<T> Mat44<T>::transposed() const noexcept
	{
		return {{this->tX.tX, this->tY.tX, this->tZ.tX, this->tW.tX},
				{this->tX.tY, this->tY.tY, this->tZ.tY, this->tW.tY},
				{this->tX.tZ, this->tY.tZ, this->tZ.tZ, this->tW.tZ},
				{this->tX.tW, this->tY.tW, this->tZ.tW, this->tW.tW}};
	}

	template<class T>
	Mat44<T> Mat44<T>::zero() noexcept
	{
		return {Vec4<T>::zero(), Vec4<T>::zero(), Vec4<T>::zero(), Vec4<T>::zero()};
	}

	template<class T>
	Mat44<T> Mat44<T>::one() noexcept
	{
		return {Vec4<T>::one(), Vec4<T>::one(), Vec4<T>::one(), Vec4<T>::one()};
	}

	template<class T>
	Mat44<T> Mat44<T>::identity() noexcept
	{
		return {Vec4<T>{static_cast<T>(1), static_cast<T>(0), static_cast<T>(0), static_cast<T>(0)},
				Vec4<T>{static_cast<T>(0), static_cast<T>(1), static_cast<T>(0), static_cast<T>(0)},
				Vec4<T>{static_cast<T>(0), static_cast<T>(0), static_cast<T>(1), static_cast<T>(0)},
				Vec4<T>{static_cast<T>(0), static_cast<T>(0), static_cast<T>(0), static_cast<T>(1)}};
	}

	template<class T, class U>
	Mat44<T> operator+(const Mat44<T> &tLhs, U uRhs) noexcept
	{
		auto tRhs{static_cast<T>(uRhs)};

		return {tLhs.tX + tRhs, tLhs.tY + tRhs, tLhs.tZ + tRhs, tLhs.tW + tRhs};
	}

	template<class T, class U>
	Mat44<U> operator+(T tLhs, const Mat44<U> &uRhs) noexcept
	{
		auto uLhs{static_cast<U>(tLhs)};

		return {uLhs + uRhs.tX, uLhs + uRhs.tY, uLhs + uRhs.tZ, uLhs + uRhs.tW};
	}

	template<class T, class U>
	Mat44<T> operator+(const Mat44<T> &tLhs, const Vec4<U> &uRhs) noexcept
	{
		auto tRhs{static_cast<Vec4<T>>(uRhs)};

		return {tLhs.tX + tRhs, tLhs.tY + tRhs, tLhs.tZ + tRhs, tLhs.tW + tRhs};
	}

	template<class T, class U>
	Mat44<U> operator+(const Vec4<T> &tLhs, const Mat44<U> &uRhs) noexcept
	{
		auto uLhs{static_cast<Vec4<U>>(tLhs)};

		return {uLhs + uRhs.tX, uLhs + uRhs.tY, uLhs + uRhs.tZ, uLhs + uRhs.tW};
	}

	template<class T>
	Mat44<T> operator+(const Mat44<T> &tLhs, const Mat44<T> &tRhs) noexcept
	{
		return {tLhs.tX + tRhs.tX, tLhs.tY + tRhs.tY, tLhs.tZ + tRhs.tZ, tLhs.tW + tRhs.tW};
	}

	template<class T, class U>
	Mat44<T> operator-(const Mat44<T> &tLhs, U uRhs) noexcept
	{
		auto tRhs{static_cast<T>(uRhs)};

		return {tLhs.tX - tRhs, tLhs.tY - tRhs, tLhs.tZ - tRhs, tLhs.tW - tRhs};
	}

	template<class T, class U>
	Mat44<U> operator-(T tLhs, const Mat44<U> &uRhs) noexcept
	{
		auto uLhs{static_cast<U>(tLhs)};

		return {uLhs - uRhs.tX, uLhs - uRhs.tY, uLhs - uRhs.tZ, uLhs - uRhs.tW};
	}

	template<class T, class U>
	Mat44<T> operator-(const Mat44<T> &tLhs, const Vec4<U> &uRhs) noexcept
	{
		auto tRhs{static_cast<Vec4<T>>(uRhs)};

		return {tLhs.tX - tRhs, tLhs.tY - tRhs, tLhs.tZ - tRhs, tLhs.tW - tRhs};
	}

	template<class T, class U>
	Mat44<U> operator-(const Vec4<T> &tLhs, const Mat44<U> &uRhs) noexcept
	{
		auto uLhs{static_cast<Vec4<U>>(tLhs)};

		return {uLhs - uRhs.tX, uLhs - uRhs.tY, uLhs - uRhs.tZ, uLhs - uRhs.tW};
	}

	template<class T>
	Mat44<T> operator-(const Mat44<T> &tLhs, const Mat44<T> &tRhs) noexcept
	{
		return {tLhs.tX - tRhs.tX, tLhs.tY - tRhs.tY, tLhs.tZ - tRhs.tZ, tLhs.tW - tRhs.tW};
	}

	template<class T, class U>
	Mat44<T> operator*(const Mat44<T> &tLhs, U uRhs) noexcept
	{
		auto tRhs{static_cast<T>(uRhs)};

		return {tLhs.tX * tRhs, tLhs.tY * tRhs, tLhs.tZ * tRhs, tLhs.tW * tRhs};
	}

	template<class T, class U>
	Mat44<U> operator*(T tLhs, const Mat44<U> &uRhs) noexcept
	{
		auto uLhs{static_cast<U>(tLhs)};

		return {uLhs * uRhs.tX, uLhs * uRhs.tY, uLhs * uRhs.tZ, uLhs * uRhs.tW};
	}

	template<class T, class U>
	Mat44<T> operator*(const Mat44<T> &tLhs, const Vec4<U> &uRhs) noexcept
	{
		auto tRhs{static_cast<Vec4<T>>(uRhs)};

		return {tLhs.tX * tRhs, tLhs.tY * tRhs, tLhs.tZ * tRhs, tLhs.tW * tRhs};
	}

	template<class T, class U>
	Mat44<U> operator*(const Vec4<T> &tLhs, const Mat44<U> &uRhs) noexcept
	{
		auto uLhs{static_cast<Vec4<U>>(tLhs)};

		return {uLhs * uRhs.tX, uLhs * uRhs.tY, uLhs * uRhs.tZ, uLhs * uRhs.tW};
	}

	template<class T>
	Mat44<T> operator*(const Mat44<T> &tLhs, const Mat44<T> &tRhs) noexcept
	{
		return {tLhs.tX * tRhs.tX, tLhs.tY * tRhs.tY, tLhs.tZ * tRhs.tZ, tLhs.tW * tRhs.tW};
	}

	template<class T, class U>
	Mat44<T> operator/(const Mat44<T> &tLhs, U uRhs) noexcept
	{
		auto tRhs{static_cast<T>(uRhs)};

		return {tLhs.tX / tRhs, tLhs.tY / tRhs, tLhs.tZ / tRhs, tLhs.tW / tRhs};
	}

	template<class T, class U>
	Mat44<U> operator/(T tLhs, const Mat44<U> &uRhs) noexcept
	{
		auto uLhs{static_cast<U>(tLhs)};

		return {uLhs / uRhs.tX, uLhs / uRhs.tY, uLhs / uRhs.tZ, uLhs / uRhs.tW};
	}

	template<class T, class U>
	Mat44<T> operator/(const Mat44<T> &tLhs, const Vec4<U> &uRhs) noexcept
	{
		auto tRhs{static_cast<Vec4<T>>(uRhs)};

		return {tLhs.tX / tRhs, tLhs.tY / tRhs, tLhs.tZ / tRhs, tLhs.tW / tRhs};
	}

	template<class T, class U>
	Mat44<U> operator/(const Vec4<T> &tLhs, const Mat44<U> &uRhs) noexcept
	{
		auto uLhs{static_cast<Vec4<U>>(tLhs)};

		return {uLhs / uRhs.tX, uLhs / uRhs.tY, uLhs / uRhs.tZ, uLhs / uRhs.tW};
	}

	template<class T>
	Mat44<T> operator/(const Mat44<T> &tLhs, const Mat44<T> &tRhs) noexcept
	{
		return {tLhs.tX / tRhs.tX, tLhs.tY / tRhs.tY, tLhs.tZ / tRhs.tZ, tLhs.tW / tRhs.tW};
	}

	template<class T, class U>
	Vec4<T> operator%(const Mat44<T> &tLhs, const Vec4<U> &uRhs) noexcept
	{
		auto tRhs{static_cast<Vec4<T>>(uRhs)};

		return {Vec4<T>::dot(tLhs.tX, tRhs),
				Vec4<T>::dot(tLhs.tY, tRhs),
				Vec4<T>::dot(tLhs.tZ, tRhs),
				Vec4<T>::dot(tLhs.tW, tRhs)};
	}

	template<class T, class U>
	Vec4<U> operator%(const Vec4<T> &tLhs, const Mat44<U> &uRhs) noexcept
	{
		auto uLhs{static_cast<Vec4<U>>(tLhs)};

		return {uLhs.tX * uRhs.tX.tX + uLhs.tY * uRhs.tY.tX + uLhs.tZ * uRhs.tZ.tX + uLhs.tZ * uRhs.tW.tX,
				uLhs.tX * uRhs.tX.tY + uLhs.tY * uRhs.tY.tY + uLhs.tZ * uRhs.tZ.tY + uLhs.tZ * uRhs.tW.tY,
				uLhs.tX * uRhs.tX.tZ + uLhs.tY * uRhs.tY.tZ + uLhs.tZ * uRhs.tZ.tZ + uLhs.tZ * uRhs.tW.tZ,
				uLhs.tX * uRhs.tX.tW + uLhs.tY * uRhs.tY.tW + uLhs.tZ * uRhs.tZ.tW + uLhs.tZ * uRhs.tW.tW};
	}
}	 // namespace onyx::transform

#endif