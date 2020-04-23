
#ifndef _ONYX_TRANSFORM_MAT42_HPP

#define _ONYX_TRANSFORM_MAT42_HPP

namespace onyx::transform {
	template<class T>
	Mat42<T>::Mat42() noexcept : tX{Vec2<T>::zero()}, tY{Vec2<T>::zero()}, tZ{Vec2<T>::zero()}, tW{Vec2<T>::zero()}
	{
		// Empty.
	}

	template<class T>
	Mat42<T>::Mat42(Vec2<T> tX, Vec2<T> tY, Vec2<T> tZ, Vec2<T> tW) noexcept : tX{tX}, tY{tY}, tZ{tZ}, tW{tW}
	{
		// Empty.
	}

	template<class T>
	Mat42<T>::Mat42(T tXX, T tXY, T tYX, T tYY, T tZX, T tZY, T tWX, T tWY) noexcept :
		tX{tXX, tXY},
		tY{tYX, tYY},
		tZ{tZX, tZY},
		tW{tWX, tWY}
	{
		// Empty.
	}

	template<class T>
	Vec2<T> &Mat42<T>::operator[](std::size_t nIndex) noexcept
	{
		switch (nIndex) {
		case 0: return this->tX;

		case 1: return this->tY;

		case 2: return this->tZ;

		default: return this->tW;
		}
	}

	template<class T>
	const Vec2<T> &Mat42<T>::operator[](std::size_t nIndex) const noexcept
	{
		switch (nIndex) {
		case 0: return this->tX;

		case 1: return this->tY;

		case 2: return this->tZ;

		default: return this->tW;
		}
	}

	template<class T>
	Mat42<T> Mat42<T>::operator+() const noexcept
	{
		return *this;
	}

	template<class T>
	Mat42<T> Mat42<T>::operator-() const noexcept
	{
		return {-this->tX, -this->tY, -this->tZ, -this->tW};
	}

	template<class T>
	Mat42<T> &Mat42<T>::operator++() noexcept
	{
		++this->tX;
		++this->tY;
		++this->tZ;
		++this->tW;

		return *this;
	}

	template<class T>
	Mat42<T> Mat42<T>::operator++(int) noexcept
	{
		auto tResult{*this};

		++this->tX;
		++this->tY;
		++this->tZ;
		++this->tW;

		return tResult;
	}

	template<class T>
	Mat42<T> &Mat42<T>::operator--() noexcept
	{
		--this->tX;
		--this->tY;
		--this->tZ;
		--this->tW;

		return *this;
	}

	template<class T>
	Mat42<T> Mat42<T>::operator--(int) noexcept
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
	Mat42<T> &Mat42<T>::operator+=(U uRhs) noexcept
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
	Mat42<T> &Mat42<T>::operator+=(const Vec2<U> &uRhs) noexcept
	{
		auto tRhs{static_cast<Vec2<T>>(uRhs)};

		this->tX += tRhs;
		this->tY += tRhs;
		this->tZ += tRhs;
		this->tW += tRhs;

		return *this;
	}

	template<class T>
	template<class U>
	Mat42<T> &Mat42<T>::operator+=(const Mat42<U> &uRhs) noexcept
	{
		this->tX += uRhs.tX;
		this->tY += uRhs.tY;
		this->tZ += uRhs.tZ;
		this->tW += uRhs.tW;

		return *this;
	}

	template<class T>
	template<class U>
	Mat42<T> &Mat42<T>::operator-=(U uRhs) noexcept
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
	Mat42<T> &Mat42<T>::operator-=(const Vec2<U> &uRhs) noexcept
	{
		auto tRhs{static_cast<Vec2<T>>(uRhs)};

		this->tX -= tRhs;
		this->tY -= tRhs;
		this->tZ -= tRhs;
		this->tW -= tRhs;

		return *this;
	}

	template<class T>
	template<class U>
	Mat42<T> &Mat42<T>::operator-=(const Mat42<U> &uRhs) noexcept
	{
		this->tX -= uRhs.tX;
		this->tY -= uRhs.tY;
		this->tZ -= uRhs.tZ;
		this->tW -= uRhs.tW;

		return *this;
	}

	template<class T>
	template<class U>
	Mat42<T> &Mat42<T>::operator*=(U uRhs) noexcept
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
	Mat42<T> &Mat42<T>::operator*=(const Vec2<U> &uRhs) noexcept
	{
		auto tRhs{static_cast<Vec2<T>>(uRhs)};

		this->tX *= tRhs;
		this->tY *= tRhs;
		this->tZ *= tRhs;
		this->tW *= tRhs;

		return *this;
	}

	template<class T>
	template<class U>
	Mat42<T> &Mat42<T>::operator*=(const Mat42<U> &uRhs) noexcept
	{
		this->tX *= uRhs.tX;
		this->tY *= uRhs.tY;
		this->tZ *= uRhs.tZ;
		this->tW *= uRhs.tW;

		return *this;
	}

	template<class T>
	template<class U>
	Mat42<T> &Mat42<T>::operator/=(U uRhs) noexcept
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
	Mat42<T> &Mat42<T>::operator/=(const Vec2<U> &uRhs) noexcept
	{
		auto tRhs{static_cast<Vec2<T>>(uRhs)};

		this->tX /= tRhs;
		this->tY /= tRhs;
		this->tZ /= tRhs;
		this->tW /= tRhs;

		return *this;
	}

	template<class T>
	template<class U>
	Mat42<T> &Mat42<T>::operator/=(const Mat42<U> &uRhs) noexcept
	{
		this->tX /= uRhs.tX;
		this->tY /= uRhs.tY;
		this->tZ /= uRhs.tZ;
		this->tW /= uRhs.tW;

		return *this;
	}

	template<class T>
	template<class U>
	bool Mat42<T>::operator==(U uRhs) const noexcept
	{
		auto tRhs{static_cast<T>(uRhs)};

		return this->tX == tRhs && this->tY == tRhs && this->tZ == tRhs && this->tW == tRhs;
	}

	template<class T>
	template<class U>
	bool Mat42<T>::operator==(const Vec2<U> &uRhs) const noexcept
	{
		auto tRhs{static_cast<Vec2<T>>(uRhs)};

		return this->tX == tRhs && this->tY == tRhs && this->tZ == tRhs && this->tW == tRhs;
	}

	template<class T>
	template<class U>
	bool Mat42<T>::operator==(const Mat42<U> &uRhs) const noexcept
	{
		return this->tX == uRhs.tX && this->tY == uRhs.tY && this->tZ == uRhs.tZ && this->tW == uRhs.tW;
	}

	template<class T>
	template<class U>
	bool Mat42<T>::operator!=(U uRhs) const noexcept
	{
		auto tRhs{static_cast<T>(uRhs)};

		return this->tX != tRhs || this->tY != tRhs || this->tZ != tRhs || this->tW != tRhs;
	}

	template<class T>
	template<class U>
	bool Mat42<T>::operator!=(const Vec2<U> &uRhs) const noexcept
	{
		auto tRhs{static_cast<Vec2<T>>(uRhs)};

		return this->tX != tRhs || this->tY != tRhs || this->tZ != tRhs || this->tW != tRhs;
	}

	template<class T>
	template<class U>
	bool Mat42<T>::operator!=(const Mat42<U> &uRhs) const noexcept
	{
		return this->tX != uRhs.tX || this->tY != uRhs.tY || this->tZ != uRhs.tZ || this->tW != uRhs.tW;
	}

	template<class T>
	template<class U>
	Mat42<T>::operator Mat42<U>() const noexcept
	{
		return {static_cast<Vec2<U>>(this->tX),
				static_cast<Vec2<U>>(this->tY),
				static_cast<Vec2<U>>(this->tZ),
				static_cast<Vec2<U>>(this->tW)};
	}

	template<class T>
	Mat24<T> Mat42<T>::transposed() const noexcept
	{
		return {{this->tX.tX, this->tY.tX, this->tZ.tX, this->tW.tX},
				{this->tX.tY, this->tY.tY, this->tZ.tY, this->tW.tY}};
	}

	template<class T>
	Mat42<T> Mat42<T>::zero() noexcept
	{
		return {Vec2<T>::zero(), Vec2<T>::zero(), Vec2<T>::zero(), Vec2<T>::zero()};
	}

	template<class T>
	Mat42<T> Mat42<T>::one() noexcept
	{
		return {Vec2<T>::one(), Vec2<T>::one(), Vec2<T>::one(), Vec2<T>::one()};
	}

	template<class T, class U>
	Mat42<T> operator+(const Mat42<T> &tLhs, U uRhs) noexcept
	{
		auto tRhs{static_cast<T>(uRhs)};

		return {tLhs.tX + tRhs, tLhs.tY + tRhs, tLhs.tZ + tRhs, tLhs.tW + tRhs};
	}

	template<class T, class U>
	Mat42<U> operator+(T tLhs, const Mat42<U> &uRhs) noexcept
	{
		auto uLhs{static_cast<U>(tLhs)};

		return {uLhs + uRhs.tX, uLhs + uRhs.tY, uLhs + uRhs.tZ, uLhs + uRhs.tW};
	}

	template<class T, class U>
	Mat42<T> operator+(const Mat42<T> &tLhs, const Vec2<U> &uRhs) noexcept
	{
		auto tRhs{static_cast<Vec2<T>>(uRhs)};

		return {tLhs.tX + tRhs, tLhs.tY + tRhs, tLhs.tZ + tRhs, tLhs.tW + tRhs};
	}

	template<class T, class U>
	Mat42<U> operator+(const Vec2<T> &tLhs, const Mat42<U> &uRhs) noexcept
	{
		auto uLhs{static_cast<Vec2<U>>(tLhs)};

		return {uLhs + uRhs.tX, uLhs + uRhs.tY, uLhs + uRhs.tZ, uLhs + uRhs.tW};
	}

	template<class T>
	Mat42<T> operator+(const Mat42<T> &tLhs, const Mat42<T> &tRhs) noexcept
	{
		return {tLhs.tX + tRhs.tX, tLhs.tY + tRhs.tY, tLhs.tZ + tRhs.tZ, tLhs.tW + tRhs.tW};
	}

	template<class T, class U>
	Mat42<T> operator-(const Mat42<T> &tLhs, U uRhs) noexcept
	{
		auto tRhs{static_cast<T>(uRhs)};

		return {tLhs.tX - tRhs, tLhs.tY - tRhs, tLhs.tZ - tRhs, tLhs.tW - tRhs};
	}

	template<class T, class U>
	Mat42<U> operator-(T tLhs, const Mat42<U> &uRhs) noexcept
	{
		auto uLhs{static_cast<U>(tLhs)};

		return {uLhs - uRhs.tX, uLhs - uRhs.tY, uLhs - uRhs.tZ, uLhs - uRhs.tW};
	}

	template<class T, class U>
	Mat42<T> operator-(const Mat42<T> &tLhs, const Vec2<U> &uRhs) noexcept
	{
		auto tRhs{static_cast<Vec2<T>>(uRhs)};

		return {tLhs.tX - tRhs, tLhs.tY - tRhs, tLhs.tZ - tRhs, tLhs.tW - tRhs};
	}

	template<class T, class U>
	Mat42<U> operator-(const Vec2<T> &tLhs, const Mat42<U> &uRhs) noexcept
	{
		auto uLhs{static_cast<Vec2<U>>(tLhs)};

		return {uLhs - uRhs.tX, uLhs - uRhs.tY, uLhs - uRhs.tZ, uLhs - uRhs.tW};
	}

	template<class T>
	Mat42<T> operator-(const Mat42<T> &tLhs, const Mat42<T> &tRhs) noexcept
	{
		return {tLhs.tX - tRhs.tX, tLhs.tY - tRhs.tY, tLhs.tZ - tRhs.tZ, tLhs.tW - tRhs.tW};
	}

	template<class T, class U>
	Mat42<T> operator*(const Mat42<T> &tLhs, U uRhs) noexcept
	{
		auto tRhs{static_cast<T>(uRhs)};

		return {tLhs.tX * tRhs, tLhs.tY * tRhs, tLhs.tZ * tRhs, tLhs.tW * tRhs};
	}

	template<class T, class U>
	Mat42<U> operator*(T tLhs, const Mat42<U> &uRhs) noexcept
	{
		auto uLhs{static_cast<U>(tLhs)};

		return {uLhs * uRhs.tX, uLhs * uRhs.tY, uLhs * uRhs.tZ, uLhs * uRhs.tW};
	}

	template<class T, class U>
	Mat42<T> operator*(const Mat42<T> &tLhs, const Vec2<U> &uRhs) noexcept
	{
		auto tRhs{static_cast<Vec2<T>>(uRhs)};

		return {tLhs.tX * tRhs, tLhs.tY * tRhs, tLhs.tZ * tRhs, tLhs.tW * tRhs};
	}

	template<class T, class U>
	Mat42<U> operator*(const Vec2<T> &tLhs, const Mat42<U> &uRhs) noexcept
	{
		auto uLhs{static_cast<Vec2<U>>(tLhs)};

		return {uLhs * uRhs.tX, uLhs * uRhs.tY, uLhs * uRhs.tZ, uLhs * uRhs.tW};
	}

	template<class T>
	Mat42<T> operator*(const Mat42<T> &tLhs, const Mat42<T> &tRhs) noexcept
	{
		return {tLhs.tX * tRhs.tX, tLhs.tY * tRhs.tY, tLhs.tZ * tRhs.tZ, tLhs.tW * tRhs.tW};
	}

	template<class T, class U>
	Mat42<T> operator/(const Mat42<T> &tLhs, U uRhs) noexcept
	{
		auto tRhs{static_cast<T>(uRhs)};

		return {tLhs.tX / tRhs, tLhs.tY / tRhs, tLhs.tZ / tRhs, tLhs.tW / tRhs};
	}

	template<class T, class U>
	Mat42<U> operator/(T tLhs, const Mat42<U> &uRhs) noexcept
	{
		auto uLhs{static_cast<U>(tLhs)};

		return {uLhs / uRhs.tX, uLhs / uRhs.tY, uLhs / uRhs.tZ, uLhs / uRhs.tW};
	}

	template<class T, class U>
	Mat42<T> operator/(const Mat42<T> &tLhs, const Vec2<U> &uRhs) noexcept
	{
		auto tRhs{static_cast<Vec2<T>>(uRhs)};

		return {tLhs.tX / tRhs, tLhs.tY / tRhs, tLhs.tZ / tRhs, tLhs.tW / tRhs};
	}

	template<class T, class U>
	Mat42<U> operator/(const Vec2<T> &tLhs, const Mat42<U> &uRhs) noexcept
	{
		auto uLhs{static_cast<Vec2<U>>(tLhs)};

		return {uLhs / uRhs.tX, uLhs / uRhs.tY, uLhs / uRhs.tZ, uLhs / uRhs.tW};
	}

	template<class T>
	Mat42<T> operator/(const Mat42<T> &tLhs, const Mat42<T> &tRhs) noexcept
	{
		return {tLhs.tX / tRhs.tX, tLhs.tY / tRhs.tY, tLhs.tZ / tRhs.tZ, tLhs.tW / tRhs.tW};
	}

	template<class T, class U>
	Vec4<T> operator%(const Mat42<T> &tLhs, const Vec2<U> &uRhs) noexcept
	{
		auto tRhs{static_cast<Vec2<T>>(uRhs)};

		return {Vec2<T>::dot(tLhs.tX, tRhs),
				Vec2<T>::dot(tLhs.tY, tRhs),
				Vec2<T>::dot(tLhs.tZ, tRhs),
				Vec2<T>::dot(tLhs.tW, tRhs)};
	}

	template<class T, class U>
	Vec2<U> operator%(const Vec4<T> &tLhs, const Mat42<U> &uRhs) noexcept
	{
		auto uLhs{static_cast<Vec4<U>>(tLhs)};

		return {uLhs.tX * uRhs.tX.tX + uLhs.tY * uRhs.tY.tX + uLhs.tZ * uRhs.tZ.tX + uLhs.tZ * uRhs.tW.tX,
				uLhs.tX * uRhs.tX.tY + uLhs.tY * uRhs.tY.tY + uLhs.tZ * uRhs.tZ.tY + uLhs.tZ * uRhs.tW.tY};
	}
}	 // namespace onyx::transform

#endif