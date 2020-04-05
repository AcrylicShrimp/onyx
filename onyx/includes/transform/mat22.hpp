
#ifndef _ONYX_TRANSFORM_MAT22_HPP

#define _ONYX_TRANSFORM_MAT22_HPP

namespace onyx::transform {
	template<class T>
	Mat22<T>::Mat22() noexcept : tX{Vec2<T>::zero()}, tY{Vec2<T>::zero()}
	{
		// Empty.
	}

	template<class T>
	Mat22<T>::Mat22(Vec2<T> tX, Vec2<T> tY) noexcept : tX{tX}, tY{tY}
	{
		// Empty.
	}

	template<class T>
	Mat22<T>::Mat22(T tXX, T tXY, T tYX, T tYY) noexcept : tX{tXX, tXY}, tY{tYX, tYY}
	{
		// Empty.
	}

	template<class T>
	Vec2<T> &Mat22<T>::operator[](std::size_t nIndex) noexcept
	{
		switch (nIndex) {
		case 0: return this->tX;

		default: return this->tY;
		}
	}

	template<class T>
	const Vec2<T> &Mat22<T>::operator[](std::size_t nIndex) const noexcept
	{
		switch (nIndex) {
		case 0: return this->tX;

		default: return this->tY;
		}
	}

	template<class T>
	Mat22<T> Mat22<T>::operator+() const noexcept
	{
		return *this;
	}

	template<class T>
	Mat22<T> Mat22<T>::operator-() const noexcept
	{
		return {-this->tX, -this->tY};
	}

	template<class T>
	Mat22<T> &Mat22<T>::operator++() noexcept
	{
		++this->tX;
		++this->tY;

		return *this;
	}

	template<class T>
	Mat22<T> Mat22<T>::operator++(int) noexcept
	{
		auto tResult{*this};

		++this->tX;
		++this->tY;

		return tResult;
	}

	template<class T>
	Mat22<T> &Mat22<T>::operator--() noexcept
	{
		--this->tX;
		--this->tY;

		return *this;
	}

	template<class T>
	Mat22<T> Mat22<T>::operator--(int) noexcept
	{
		auto tResult{*this};

		--this->tX;
		--this->tY;

		return tResult;
	}

	template<class T>
	template<class U>
	Mat22<T> &Mat22<T>::operator+=(U uRhs) noexcept
	{
		auto tRhs{static_cast<T>(uRhs)};

		this->tX += tRhs;
		this->tY += tRhs;

		return *this;
	}

	template<class T>
	template<class U>
	Mat22<T> &Mat22<T>::operator+=(const Vec2<U> &uRhs) noexcept
	{
		auto tRhs{static_cast<Vec2<T>>(uRhs)};

		this->tX += tRhs;
		this->tY += tRhs;

		return *this;
	}

	template<class T>
	template<class U>
	Mat22<T> &Mat22<T>::operator+=(const Mat22<U> &uRhs) noexcept
	{
		this->tX += uRhs.tX;
		this->tY += uRhs.tY;

		return *this;
	}

	template<class T>
	template<class U>
	Mat22<T> &Mat22<T>::operator-=(U uRhs) noexcept
	{
		auto tRhs{static_cast<T>(uRhs)};

		this->tX -= tRhs;
		this->tY -= tRhs;

		return *this;
	}

	template<class T>
	template<class U>
	Mat22<T> &Mat22<T>::operator-=(const Vec2<U> &uRhs) noexcept
	{
		auto tRhs{static_cast<Vec2<T>>(uRhs)};

		this->tX -= tRhs;
		this->tY -= tRhs;

		return *this;
	}

	template<class T>
	template<class U>
	Mat22<T> &Mat22<T>::operator-=(const Mat22<U> &uRhs) noexcept
	{
		this->tX -= uRhs.tX;
		this->tY -= uRhs.tY;

		return *this;
	}

	template<class T>
	template<class U>
	Mat22<T> &Mat22<T>::operator*=(U uRhs) noexcept
	{
		auto tRhs{static_cast<T>(uRhs)};

		this->tX *= tRhs;
		this->tY *= tRhs;

		return *this;
	}

	template<class T>
	template<class U>
	Mat22<T> &Mat22<T>::operator*=(const Vec2<U> &uRhs) noexcept
	{
		auto tRhs{static_cast<Vec2<T>>(uRhs)};

		this->tX *= tRhs;
		this->tY *= tRhs;

		return *this;
	}

	template<class T>
	template<class U>
	Mat22<T> &Mat22<T>::operator*=(const Mat22<U> &uRhs) noexcept
	{
		this->tX *= uRhs.tX;
		this->tY *= uRhs.tY;

		return *this;
	}

	template<class T>
	template<class U>
	Mat22<T> &Mat22<T>::operator/=(U uRhs) noexcept
	{
		auto tRhs{static_cast<T>(uRhs)};

		this->tX /= tRhs;
		this->tY /= tRhs;

		return *this;
	}

	template<class T>
	template<class U>
	Mat22<T> &Mat22<T>::operator/=(const Vec2<U> &uRhs) noexcept
	{
		auto tRhs{static_cast<Vec2<T>>(uRhs)};

		this->tX /= tRhs;
		this->tY /= tRhs;

		return *this;
	}

	template<class T>
	template<class U>
	Mat22<T> &Mat22<T>::operator/=(const Mat22<U> &uRhs) noexcept
	{
		this->tX /= uRhs.tX;
		this->tY /= uRhs.tY;

		return *this;
	}

	template<class T>
	template<class U>
	bool Mat22<T>::operator==(U uRhs) const noexcept
	{
		auto tRhs{static_cast<T>(uRhs)};

		return this->tX == tRhs && this->tY == tRhs;
	}

	template<class T>
	template<class U>
	bool Mat22<T>::operator==(const Vec2<U> &uRhs) const noexcept
	{
		auto tRhs{static_cast<Vec2<T>>(uRhs)};

		return this->tX == tRhs && this->tY == tRhs;
	}

	template<class T>
	template<class U>
	bool Mat22<T>::operator==(const Mat22<U> &uRhs) const noexcept
	{
		return this->tX == uRhs.tX && this->tY == uRhs.tY;
	}

	template<class T>
	template<class U>
	bool Mat22<T>::operator!=(U uRhs) const noexcept
	{
		auto tRhs{static_cast<T>(uRhs)};

		return this->tX != tRhs || this->tY != tRhs;
	}

	template<class T>
	template<class U>
	bool Mat22<T>::operator!=(const Vec2<U> &uRhs) const noexcept
	{
		auto tRhs{static_cast<Vec2<T>>(uRhs)};

		return this->tX != tRhs || this->tY != tRhs;
	}

	template<class T>
	template<class U>
	bool Mat22<T>::operator!=(const Mat22<U> &uRhs) const noexcept
	{
		return this->tX != uRhs.tX || this->tY != uRhs.tY;
	}

	template<class T>
	template<class U>
	Mat22<T>::operator Mat22<U>() const noexcept
	{
		return {static_cast<Vec2<U>>(this->tX), static_cast<Vec2<U>>(this->tY)};
	}

	template<class T>
	Mat22<T> Mat22<T>::transposed() const noexcept
	{
		return {{this->tX.tX, this->tY.tX}, {this->tX.tY, this->tY.tY}};
	}

	template<class T>
	Mat22<T> Mat22<T>::zero() noexcept
	{
		return {Vec2<T>::zero(), Vec2<T>::zero()};
	}

	template<class T>
	Mat22<T> Mat22<T>::one() noexcept
	{
		return {Vec2<T>::one(), Vec2<T>::one()};
	}

	template<class T>
	Mat22<T> Mat22<T>::identity() noexcept
	{
		return {Vec2<T>{static_cast<T>(1), static_cast<T>(0)}, Vec2<T>{static_cast<T>(0), static_cast<T>(1)}};
	}

	template<class T, class U>
	Mat22<T> operator+(const Mat22<T> &tLhs, U uRhs) noexcept
	{
		auto tRhs{static_cast<T>(uRhs)};

		return {tLhs.tX + tRhs, tLhs.tY + tRhs};
	}

	template<class T, class U>
	Mat22<U> operator+(T tLhs, const Mat22<U> &uRhs) noexcept
	{
		auto uLhs{static_cast<U>(tLhs)};

		return {uLhs + uRhs.tX, uLhs + uRhs.tY};
	}

	template<class T, class U>
	Mat22<T> operator+(const Mat22<T> &tLhs, const Vec2<U> &uRhs) noexcept
	{
		auto tRhs{static_cast<Vec2<T>>(uRhs)};

		return {tLhs.tX + tRhs, tLhs.tY + tRhs};
	}

	template<class T, class U>
	Mat22<U> operator+(const Vec2<T> &tLhs, const Mat22<U> &uRhs) noexcept
	{
		auto uLhs{static_cast<Vec2<U>>(tLhs)};

		return {uLhs + uRhs.tX, uLhs + uRhs.tY};
	}

	template<class T>
	Mat22<T> operator+(const Mat22<T> &tLhs, const Mat22<T> &tRhs) noexcept
	{
		return {tLhs.tX + tRhs.tX, tLhs.tY + tRhs.tY};
	}

	template<class T, class U>
	Mat22<T> operator-(const Mat22<T> &tLhs, U uRhs) noexcept
	{
		auto tRhs{static_cast<T>(uRhs)};

		return {tLhs.tX - tRhs, tLhs.tY - tRhs};
	}

	template<class T, class U>
	Mat22<U> operator-(T tLhs, const Mat22<U> &uRhs) noexcept
	{
		auto uLhs{static_cast<U>(tLhs)};

		return {uLhs - uRhs.tX, uLhs - uRhs.tY};
	}

	template<class T, class U>
	Mat22<T> operator-(const Mat22<T> &tLhs, const Vec2<U> &uRhs) noexcept
	{
		auto tLhs{static_cast<Vec2<T>>(uRhs)};

		return {tLhs.tX - tLhs, tLhs.tY - tLhs};
	}

	template<class T, class U>
	Mat22<U> operator-(const Vec2<T> &tLhs, const Mat22<U> &uRhs) noexcept
	{
		auto uLhs{static_cast<Vec2<U>>(tLhs)};

		return {uLhs - uRhs.tX, uLhs - uRhs.tY};
	}

	template<class T>
	Mat22<T> operator-(const Mat22<T> &tLhs, const Mat22<T> &tRhs) noexcept
	{
		return {tLhs.tX - tRhs.tX, tLhs.tY - tRhs.tY};
	}

	template<class T, class U>
	Mat22<T> operator*(const Mat22<T> &tLhs, U uRhs) noexcept
	{
		auto tRhs{static_cast<T>(uRhs)};

		return {tLhs.tX * tRhs, tLhs.tY * tRhs};
	}

	template<class T, class U>
	Mat22<U> operator*(T tLhs, const Mat22<U> &uRhs) noexcept
	{
		auto uLhs{static_cast<U>(tLhs)};

		return {uLhs * uRhs.tX, uLhs * uRhs.tY};
	}

	template<class T, class U>
	Mat22<T> operator*(const Mat22<T> &tLhs, const Vec2<U> &uRhs) noexcept
	{
		auto tRhs{static_cast<Vec2<T>>(uRhs)};

		return {tLhs.tX * tRhs, tLhs.tY * tRhs};
	}

	template<class T, class U>
	Mat22<U> operator*(const Vec2<T> &tLhs, const Mat22<U> &uRhs) noexcept
	{
		auto uLhs{static_cast<Vec2<U>>(tLhs)};

		return {uLhs * uRhs.tX, uLhs * uRhs.tY};
	}

	template<class T>
	Mat22<T> operator*(const Mat22<T> &tLhs, const Mat22<T> &tRhs) noexcept
	{
		return {tLhs.tX * tRhs.tX, tLhs.tY * tRhs.tY};
	}

	template<class T, class U>
	Mat22<T> operator/(const Mat22<T> &tLhs, U uRhs) noexcept
	{
		auto tRhs{static_cast<T>(uRhs)};

		return {tLhs.tX / tRhs, tLhs.tY / tRhs};
	}

	template<class T, class U>
	Mat22<U> operator/(T tLhs, const Mat22<U> &uRhs) noexcept
	{
		auto uLhs{static_cast<U>(tLhs)};

		return {uLhs / uRhs.tX, uLhs / uRhs.tY};
	}

	template<class T, class U>
	Mat22<T> operator/(const Mat22<T> &tLhs, const Vec2<U> &uRhs) noexcept
	{
		auto tRhs{static_cast<Vec2<T>>(uRhs)};

		return {tLhs.tX / tRhs, tLhs.tY / tRhs};
	}

	template<class T, class U>
	Mat22<U> operator/(const Vec2<T> &tLhs, const Mat22<U> &uRhs) noexcept
	{
		auto uLhs{static_cast<Vec2<U>>(tLhs)};

		return {uLhs / uRhs.tX, uLhs / uRhs.tY};
	}

	template<class T>
	Mat22<T> operator/(const Mat22<T> &tLhs, const Mat22<T> &tRhs) noexcept
	{
		return {tLhs.tX / tRhs.tX, tLhs.tY / tRhs.tY};
	}

	template<class T, class U>
	Vec2<T> operator%(const Mat22<T> &tLhs, const Vec2<U> &uRhs) noexcept
	{
		auto tRhs{static_cast<Vec2<T>>(uRhs)};

		return {Vec2<T>::dot(tLhs.tX, tRhs), Vec2<T>::dot(tLhs.tY, tRhs)};
	}

	template<class T, class U>
	Vec2<U> operator%(const Vec2<T> &tLhs, const Mat22<U> &uRhs) noexcept
	{
		auto uLhs{static_cast<Vec2<U>>(tLhs)};

		return {uLhs.tX * uRhs.tX.tX + uLhs.tY * uRhs.tY.tX, uLhs.tX * uRhs.tX.tY + uLhs.tY * uRhs.tY.tY};
	}
}	 // namespace onyx::transform

#endif