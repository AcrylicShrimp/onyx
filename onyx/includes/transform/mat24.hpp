
#ifndef _ONYX_TRANSFORM_MAT24_HPP

#define _ONYX_TRANSFORM_MAT24_HPP

namespace onyx::transform {
	template<class T>
	Mat24<T>::Mat24() noexcept : tX{Vec4<T>::zero()}, tY{Vec4<T>::zero()}
	{
		// Empty.
	}

	template<class T>
	Mat24<T>::Mat24(Vec4<T> tX, Vec4<T> tY) noexcept : tX{tX}, tY{tY}
	{
		// Empty.
	}

	template<class T>
	Mat24<T>::Mat24(T tXX, T tXY, T tXZ, T tXW, T tYX, T tYY, T tYZ, T tYW) noexcept :
		tX{tXX, tXY, tXZ, tXW},
		tY{tYX, tYY, tYZ, tYW}
	{
		// Empty.
	}

	template<class T>
	Vec4<T> &Mat24<T>::operator[](std::size_t nIndex) noexcept
	{
		switch (nIndex) {
		case 0: return this->tX;

		default: return this->tY;
		}
	}

	template<class T>
	const Vec4<T> &Mat24<T>::operator[](std::size_t nIndex) const noexcept
	{
		switch (nIndex) {
		case 0: return this->tX;

		default: return this->tY;
		}
	}

	template<class T>
	Mat24<T> Mat24<T>::operator+() const noexcept
	{
		return *this;
	}

	template<class T>
	Mat24<T> Mat24<T>::operator-() const noexcept
	{
		return {-this->tX, -this->tY};
	}

	template<class T>
	Mat24<T> &Mat24<T>::operator++() noexcept
	{
		++this->tX;
		++this->tY;

		return *this;
	}

	template<class T>
	Mat24<T> Mat24<T>::operator++(int) noexcept
	{
		auto tResult{*this};

		++this->tX;
		++this->tY;

		return tResult;
	}

	template<class T>
	Mat24<T> &Mat24<T>::operator--() noexcept
	{
		--this->tX;
		--this->tY;

		return *this;
	}

	template<class T>
	Mat24<T> Mat24<T>::operator--(int) noexcept
	{
		auto tResult{*this};

		--this->tX;
		--this->tY;

		return tResult;
	}

	template<class T>
	template<class U>
	Mat24<T> &Mat24<T>::operator+=(U uRhs) noexcept
	{
		auto tRhs{static_cast<T>(uRhs)};

		this->tX += tRhs;
		this->tY += tRhs;

		return *this;
	}

	template<class T>
	template<class U>
	Mat24<T> &Mat24<T>::operator+=(const Vec4<U> &uRhs) noexcept
	{
		auto tRhs{static_cast<Vec4<T>>(uRhs)};

		this->tX += tRhs;
		this->tY += tRhs;

		return *this;
	}

	template<class T>
	template<class U>
	Mat24<T> &Mat24<T>::operator+=(const Mat24<U> &uRhs) noexcept
	{
		this->tX += uRhs.tX;
		this->tY += uRhs.tY;

		return *this;
	}

	template<class T>
	template<class U>
	Mat24<T> &Mat24<T>::operator-=(U uRhs) noexcept
	{
		auto tRhs{static_cast<T>(uRhs)};

		this->tX -= tRhs;
		this->tY -= tRhs;

		return *this;
	}

	template<class T>
	template<class U>
	Mat24<T> &Mat24<T>::operator-=(const Vec4<U> &uRhs) noexcept
	{
		auto tRhs{static_cast<Vec4<T>>(uRhs)};

		this->tX -= tRhs;
		this->tY -= tRhs;

		return *this;
	}

	template<class T>
	template<class U>
	Mat24<T> &Mat24<T>::operator-=(const Mat24<U> &uRhs) noexcept
	{
		this->tX -= uRhs.tX;
		this->tY -= uRhs.tY;

		return *this;
	}

	template<class T>
	template<class U>
	Mat24<T> &Mat24<T>::operator*=(U uRhs) noexcept
	{
		auto tRhs{static_cast<T>(uRhs)};

		this->tX *= tRhs;
		this->tY *= tRhs;

		return *this;
	}

	template<class T>
	template<class U>
	Mat24<T> &Mat24<T>::operator*=(const Vec4<U> &uRhs) noexcept
	{
		auto tRhs{static_cast<Vec4<T>>(uRhs)};

		this->tX *= tRhs;
		this->tY *= tRhs;

		return *this;
	}

	template<class T>
	template<class U>
	Mat24<T> &Mat24<T>::operator*=(const Mat24<U> &uRhs) noexcept
	{
		this->tX *= uRhs.tX;
		this->tY *= uRhs.tY;

		return *this;
	}

	template<class T>
	template<class U>
	Mat24<T> &Mat24<T>::operator/=(U uRhs) noexcept
	{
		auto tRhs{static_cast<T>(uRhs)};

		this->tX /= tRhs;
		this->tY /= tRhs;

		return *this;
	}

	template<class T>
	template<class U>
	Mat24<T> &Mat24<T>::operator/=(const Vec4<U> &uRhs) noexcept
	{
		auto tRhs{static_cast<Vec4<T>>(uRhs)};

		this->tX /= tRhs;
		this->tY /= tRhs;

		return *this;
	}

	template<class T>
	template<class U>
	Mat24<T> &Mat24<T>::operator/=(const Mat24<U> &uRhs) noexcept
	{
		this->tX /= uRhs.tX;
		this->tY /= uRhs.tY;

		return *this;
	}

	template<class T>
	template<class U>
	bool Mat24<T>::operator==(U uRhs) const noexcept
	{
		auto tScalar{static_cast<T>(uRhs)};

		return this->tX == tScalar && this->tY == tScalar;
	}

	template<class T>
	template<class U>
	bool Mat24<T>::operator==(const Vec4<U> &uRhs) const noexcept
	{
		auto tRhs{static_cast<Vec4<T>>(uRhs)};

		return this->tX == tRhs && this->tY == tRhs;
	}

	template<class T>
	template<class U>
	bool Mat24<T>::operator==(const Mat24<U> &uRhs) const noexcept
	{
		return this->tX == uRhs.tX && this->tY == uRhs.tY;
	}

	template<class T>
	template<class U>
	bool Mat24<T>::operator!=(U uRhs) const noexcept
	{
		auto tRhs{static_cast<T>(uRhs)};

		return this->tX != tRhs || this->tY != tRhs;
	}

	template<class T>
	template<class U>
	bool Mat24<T>::operator!=(const Vec4<U> &uRhs) const noexcept
	{
		auto tRhs{static_cast<Vec4<T>>(uRhs)};

		return this->tX != tRhs || this->tY != tRhs;
	}

	template<class T>
	template<class U>
	bool Mat24<T>::operator!=(const Mat24<U> &uRhs) const noexcept
	{
		return this->tX != uRhs.tX || this->tY != uRhs.tY;
	}

	template<class T>
	template<class U>
	Mat24<T>::operator Mat24<U>() const noexcept
	{
		return {static_cast<Vec4<U>>(this->tX), static_cast<Vec4<U>>(this->tY)};
	}

	template<class T>
	Mat42<T> Mat24<T>::transposed() const noexcept
	{
		return {{this->tX.tX, this->tY.tX},
				{this->tX.tY, this->tY.tY},
				{this->tX.tZ, this->tY.tZ},
				{this->tX.tW, this->tY.tW}};
	}

	template<class T>
	Mat24<T> Mat24<T>::zero() noexcept
	{
		return {Vec4<T>::zero(), Vec4<T>::zero()};
	}

	template<class T>
	Mat24<T> Mat24<T>::one() noexcept
	{
		return {Vec4<T>::one(), Vec4<T>::one()};
	}

	template<class T, class U>
	Mat24<T> operator+(const Mat24<T> &tLhs, U uRhs) noexcept
	{
		auto tRhs{static_cast<T>(uRhs)};

		return {tLhs.tX + tRhs, tLhs.tY + tRhs};
	}

	template<class T, class U>
	Mat24<U> operator+(T tLhs, const Mat24<U> &uRhs) noexcept
	{
		auto uLhs{static_cast<U>(tLhs)};

		return {uLhs + uRhs.tX, uLhs + uRhs.tY};
	}

	template<class T, class U>
	Mat24<T> operator+(const Mat24<T> &tLhs, const Vec4<U> &uRhs) noexcept
	{
		auto tRhs{static_cast<Vec4<T>>(uRhs)};

		return {tLhs.tX + tRhs, tLhs.tY + tRhs};
	}

	template<class T, class U>
	Mat24<U> operator+(const Vec4<T> &tLhs, const Mat24<U> &uRhs) noexcept
	{
		auto uLhs{static_cast<Vec4<U>>(tLhs)};

		return {uLhs + uRhs.tX, uLhs + uRhs.tY};
	}

	template<class T>
	Mat24<T> operator+(const Mat24<T> &tLhs, const Mat24<T> &tRhs) noexcept
	{
		return {tLhs.tX + tRhs.tX, tLhs.tY + tRhs.tY};
	}

	template<class T, class U>
	Mat24<T> operator-(const Mat24<T> &tLhs, U uRhs) noexcept
	{
		auto tRhs{static_cast<T>(uRhs)};

		return {tLhs.tX - tRhs, tLhs.tY - tRhs};
	}

	template<class T, class U>
	Mat24<U> operator-(T tLhs, const Mat24<U> &uRhs) noexcept
	{
		auto uLhs{static_cast<U>(tLhs)};

		return {uLhs - uRhs.tX, uLhs - uRhs.tY};
	}

	template<class T, class U>
	Mat24<T> operator-(const Mat24<T> &tLhs, const Vec4<U> &uRhs) noexcept
	{
		auto tRhs{static_cast<Vec4<T>>(uRhs)};

		return {tLhs.tX - tRhs, tLhs.tY - tRhs};
	}

	template<class T, class U>
	Mat24<U> operator-(const Vec4<T> &tLhs, const Mat24<U> &uRhs) noexcept
	{
		auto uLhs{static_cast<Vec4<U>>(tLhs)};

		return {uLhs - uRhs.tX, uLhs - uRhs.tY};
	}

	template<class T>
	Mat24<T> operator-(const Mat24<T> &tLeft, const Mat24<T> &tRight) noexcept
	{
		return {tLeft.tX - tRight.tX, tLeft.tY - tRight.tY};
	}

	template<class T, class U>
	Mat24<T> operator*(const Mat24<T> &tLhs, U uRhs) noexcept
	{
		auto tRhs{static_cast<T>(uRhs)};

		return {tLhs.tX * tRhs, tLhs.tY * tRhs};
	}

	template<class T, class U>
	Mat24<U> operator*(T tLhs, const Mat24<U> &uRhs) noexcept
	{
		auto uLhs{static_cast<U>(tLhs)};

		return {uLhs * uRhs.tX, uLhs * uRhs.tY};
	}

	template<class T, class U>
	Mat24<T> operator*(const Mat24<T> &tLhs, const Vec4<U> &uRhs) noexcept
	{
		auto tRhs{static_cast<Vec4<T>>(uRhs)};

		return {tLhs.tX * tRhs, tLhs.tY * tRhs};
	}

	template<class T, class U>
	Mat24<U> operator*(const Vec4<T> &tLhs, const Mat24<U> &uRhs) noexcept
	{
		auto uLhs{static_cast<Vec4<U>>(tLhs)};

		return {uLhs * uRhs.tX, uLhs * uRhs.tY};
	}

	template<class T>
	Mat24<T> operator*(const Mat24<T> &tLhs, const Mat24<T> &tRhs) noexcept
	{
		return {tLhs.tX * tRhs.tX, tLhs.tY * tRhs.tY};
	}

	template<class T, class U>
	Mat24<T> operator/(const Mat24<T> &tLhs, U uRhs) noexcept
	{
		auto tRhs{static_cast<T>(uRhs)};

		return {tLhs.tX / tRhs, tLhs.tY / tRhs};
	}

	template<class T, class U>
	Mat24<U> operator/(T tLhs, const Mat24<U> &uRhs) noexcept
	{
		auto uLhs{static_cast<U>(tLhs)};

		return {uLhs / uRhs.tX, uLhs / uRhs.tY};
	}

	template<class T, class U>
	Mat24<T> operator/(const Mat24<T> &tLhs, const Vec4<U> &uRhs) noexcept
	{
		auto tRhs{static_cast<Vec4<T>>(uRhs)};

		return {tLhs.tX / tRhs, tLhs.tY / tRhs};
	}

	template<class T, class U>
	Mat24<U> operator/(const Vec4<T> &tLhs, const Mat24<U> &uRhs) noexcept
	{
		auto uLhs{static_cast<Vec4<U>>(tLhs)};

		return {uLhs / uRhs.tX, uLhs / uRhs.tY};
	}

	template<class T>
	Mat24<T> operator/(const Mat24<T> &tLhs, const Mat24<T> &tRhs) noexcept
	{
		return {tLhs.tX / tRhs.tX, tLhs.tY / tRhs.tY};
	}

	template<class T, class U>
	Vec2<T> operator%(const Mat24<T> &tLhs, const Vec4<U> &uRhs) noexcept
	{
		auto tRhs{static_cast<Vec4<T>>(uRhs)};

		return {Vec4<T>::dot(tLhs.tX, tRhs), Vec4<T>::dot(tLhs.tY, tRhs)};
	}

	template<class T, class U>
	Vec4<U> operator%(const Vec2<T> &tLhs, const Mat24<U> &uRhs) noexcept
	{
		auto uLhs{static_cast<Vec2<U>>(tLhs)};

		return {uLhs.tX * uRhs.tX.tX + uLhs.tY * uRhs.tY.tX,
				uLhs.tX * uRhs.tX.tY + uLhs.tY * uRhs.tY.tY,
				uLhs.tX * uRhs.tX.tZ + uLhs.tY * uRhs.tY.tZ,
				uLhs.tX * uRhs.tX.tW + uLhs.tY * uRhs.tY.tW};
	}
}	 // namespace onyx::transform

#endif