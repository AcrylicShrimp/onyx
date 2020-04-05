
#ifndef _ONYX_TRANSFORM_MAT23_HPP

#define _ONYX_TRANSFORM_MAT23_HPP

namespace onyx::transform {
	template<class T>
	Mat23<T>::Mat23() noexcept : tX{Vec3<T>::zero()}, tY{Vec3<T>::zero()}
	{
		// Empty.
	}

	template<class T>
	Mat23<T>::Mat23(Vec3<T> tX, Vec3<T> tY) noexcept : tX{tX}, tY{tY}
	{
		// Empty.
	}

	template<class T>
	Mat23<T>::Mat23(T tXX, T tXY, T tXZ, T tYX, T tYY, T tYZ) noexcept : tX{tXX, tXY, tXZ}, tY{tYX, tYY, tYZ}
	{
		// Empty.
	}

	template<class T>
	Vec3<T> &Mat23<T>::operator[](std::size_t nIndex) noexcept
	{
		switch (nIndex) {
		case 0: return this->tX;

		default: return this->tY;
		}
	}

	template<class T>
	const Vec3<T> &Mat23<T>::operator[](std::size_t nIndex) const noexcept
	{
		switch (nIndex) {
		case 0: return this->tX;

		default: return this->tY;
		}
	}

	template<class T>
	Mat23<T> Mat23<T>::operator+() const noexcept
	{
		return *this;
	}

	template<class T>
	Mat23<T> Mat23<T>::operator-() const noexcept
	{
		return {-this->tX, -this->tY};
	}

	template<class T>
	Mat23<T> &Mat23<T>::operator++() noexcept
	{
		++this->tX;
		++this->tY;

		return *this;
	}

	template<class T>
	Mat23<T> Mat23<T>::operator++(int) noexcept
	{
		auto tResult{*this};

		++this->tX;
		++this->tY;

		return tResult;
	}

	template<class T>
	Mat23<T> &Mat23<T>::operator--() noexcept
	{
		--this->tX;
		--this->tY;

		return *this;
	}

	template<class T>
	Mat23<T> Mat23<T>::operator--(int) noexcept
	{
		auto tResult{*this};

		--this->tX;
		--this->tY;

		return tResult;
	}

	template<class T>
	template<class U>
	Mat23<T> &Mat23<T>::operator+=(U uRhs) noexcept
	{
		auto tRhs{static_cast<T>(uRhs)};

		this->tX += tRhs;
		this->tY += tRhs;

		return *this;
	}

	template<class T>
	template<class U>
	Mat23<T> &Mat23<T>::operator+=(const Vec3<U> &uRhs) noexcept
	{
		auto tLhs{static_cast<Vec3<T>>(uRhs)};

		this->tX += tLhs;
		this->tY += tLhs;

		return *this;
	}

	template<class T>
	template<class U>
	Mat23<T> &Mat23<T>::operator+=(const Mat23<U> &uRhs) noexcept
	{
		this->tX += uRhs.tX;
		this->tY += uRhs.tY;

		return *this;
	}

	template<class T>
	template<class U>
	Mat23<T> &Mat23<T>::operator-=(U uRhs) noexcept
	{
		auto tRhs{static_cast<T>(uRhs)};

		this->tX -= tRhs;
		this->tY -= tRhs;

		return *this;
	}

	template<class T>
	template<class U>
	Mat23<T> &Mat23<T>::operator-=(const Vec3<U> &uRhs) noexcept
	{
		auto tLhs{static_cast<Vec3<T>>(uRhs)};

		this->tX -= tLhs;
		this->tY -= tLhs;

		return *this;
	}

	template<class T>
	template<class U>
	Mat23<T> &Mat23<T>::operator-=(const Mat23<U> &uRhs) noexcept
	{
		this->tX -= uRhs.tX;
		this->tY -= uRhs.tY;

		return *this;
	}

	template<class T>
	template<class U>
	Mat23<T> &Mat23<T>::operator*=(U uRhs) noexcept
	{
		auto tRhs{static_cast<T>(uRhs)};

		this->tX *= tRhs;
		this->tY *= tRhs;

		return *this;
	}

	template<class T>
	template<class U>
	Mat23<T> &Mat23<T>::operator*=(const Vec3<U> &uRhs) noexcept
	{
		auto tLhs{static_cast<Vec3<T>>(uRhs)};

		this->tX *= tLhs;
		this->tY *= tLhs;

		return *this;
	}

	template<class T>
	template<class U>
	Mat23<T> &Mat23<T>::operator*=(const Mat23<U> &uRhs) noexcept
	{
		this->tX *= uRhs.tX;
		this->tY *= uRhs.tY;

		return *this;
	}

	template<class T>
	template<class U>
	Mat23<T> &Mat23<T>::operator/=(U uRhs) noexcept
	{
		auto tRhs{static_cast<T>(uRhs)};

		this->tX /= tRhs;
		this->tY /= tRhs;

		return *this;
	}

	template<class T>
	template<class U>
	Mat23<T> &Mat23<T>::operator/=(const Vec3<U> &uRhs) noexcept
	{
		auto tLhs{static_cast<Vec3<T>>(uRhs)};

		this->tX /= tLhs;
		this->tY /= tLhs;

		return *this;
	}

	template<class T>
	template<class U>
	Mat23<T> &Mat23<T>::operator/=(const Mat23<U> &uRhs) noexcept
	{
		this->tX /= uRhs.tX;
		this->tY /= uRhs.tY;

		return *this;
	}

	template<class T>
	template<class U>
	bool Mat23<T>::operator==(U uRhs) const noexcept
	{
		auto tRhs{static_cast<T>(uRhs)};

		return this->tX == tRhs && this->tY == tRhs;
	}

	template<class T>
	template<class U>
	bool Mat23<T>::operator==(const Vec3<U> &uRhs) const noexcept
	{
		auto tLhs{static_cast<Vec3<T>>(uRhs)};

		return this->tX == tLhs && this->tY == tLhs;
	}

	template<class T>
	template<class U>
	bool Mat23<T>::operator==(const Mat23<U> &uRhs) const noexcept
	{
		return this->tX == uRhs.tX && this->tY == uRhs.tY;
	}

	template<class T>
	template<class U>
	bool Mat23<T>::operator!=(U uRhs) const noexcept
	{
		auto tRhs{static_cast<T>(uRhs)};

		return this->tX != tRhs || this->tY != tRhs;
	}

	template<class T>
	template<class U>
	bool Mat23<T>::operator!=(const Vec3<U> &uRhs) const noexcept
	{
		auto tLhs{static_cast<Vec3<T>>(uRhs)};

		return this->tX != tLhs || this->tY != tLhs;
	}

	template<class T>
	template<class U>
	bool Mat23<T>::operator!=(const Mat23<U> &uRhs) const noexcept
	{
		return this->tX != uRhs.tX || this->tY != uRhs.tY;
	}

	template<class T>
	template<class U>
	Mat23<T>::operator Mat23<U>() const noexcept
	{
		return {static_cast<Vec3<U>>(this->tX), static_cast<Vec3<U>>(this->tY)};
	}

	template<class T>
	Mat32<T> Mat23<T>::transposed() const noexcept
	{
		return {{this->tX.tX, this->tY.tX}, {this->tX.tY, this->tY.tY}, {this->tX.tZ, this->tY.tZ}};
	}

	template<class T>
	Mat23<T> Mat23<T>::zero() noexcept
	{
		return {Vec3<T>::zero(), Vec3<T>::zero()};
	}

	template<class T>
	Mat23<T> Mat23<T>::one() noexcept
	{
		return {Vec3<T>::one(), Vec3<T>::one()};
	}

	template<class T, class U>
	Mat23<T> operator+(const Mat23<T> &tLhs, U uRhs) noexcept
	{
		auto tRhs{static_cast<T>(uRhs)};

		return {tLhs.tX + tRhs, tLhs.tY + tRhs};
	}

	template<class T, class U>
	Mat23<U> operator+(T tLhs, const Mat23<U> &uRhs) noexcept
	{
		auto uLhs{static_cast<U>(tLhs)};

		return {uLhs + uRhs.tX, uLhs + uRhs.tY};
	}

	template<class T, class U>
	Mat23<T> operator+(const Mat23<T> &tLhs, const Vec3<U> &uRhs) noexcept
	{
		auto tRhs{static_cast<Vec3<T>>(uRhs)};

		return {tLhs.tX + tRhs, tLhs.tY + tRhs};
	}

	template<class T, class U>
	Mat23<U> operator+(const Vec3<T> &tLhs, const Mat23<U> &uRhs) noexcept
	{
		auto uLhs{static_cast<Vec3<U>>(tLhs)};

		return {uLhs + uRhs.tX, uLhs + uRhs.tY};
	}

	template<class T>
	Mat23<T> operator+(const Mat23<T> &tLhs, const Mat23<T> &tRhs) noexcept
	{
		return {tLhs.tX + tRhs.tX, tLhs.tY + tRhs.tY};
	}

	template<class T, class U>
	Mat23<T> operator-(const Mat23<T> &tLhs, U uRhs) noexcept
	{
		auto tLhs{static_cast<T>(uRhs)};

		return {tLhs.tX - tLhs, tLhs.tY - tLhs};
	}

	template<class T, class U>
	Mat23<U> operator-(T tLhs, const Mat23<U> &uRhs) noexcept
	{
		auto uLhs{static_cast<U>(tLhs)};

		return {uLhs - uRhs.tX, uLhs - uRhs.tY};
	}

	template<class T, class U>
	Mat23<T> operator-(const Mat23<T> &tLhs, const Vec3<U> &uRhs) noexcept
	{
		auto tRhs{static_cast<Vec3<T>>(uRhs)};

		return {tLhs.tX - tRhs, tLhs.tY - tRhs};
	}

	template<class T, class U>
	Mat23<U> operator-(const Vec3<T> &tLhs, const Mat23<U> &uRhs) noexcept
	{
		auto uRhs{static_cast<Vec3<U>>(tLhs)};

		return {uRhs - uRhs.tX, uRhs - uRhs.tY};
	}

	template<class T>
	Mat23<T> operator-(const Mat23<T> &tLhs, const Mat23<T> &tRhs) noexcept
	{
		return {tLhs.tX - tRhs.tX, tLhs.tY - tRhs.tY};
	}

	template<class T, class U>
	Mat23<T> operator*(const Mat23<T> &tLhs, U uRhs) noexcept
	{
		auto tRhs{static_cast<T>(uRhs)};

		return {tLhs.tX * tRhs, tLhs.tY * tRhs};
	}

	template<class T, class U>
	Mat23<U> operator*(T tLhs, const Mat23<U> &uRhs) noexcept
	{
		auto uLhs{static_cast<U>(tLhs)};

		return {uLhs * uRhs.tX, uLhs * uRhs.tY};
	}

	template<class T, class U>
	Mat23<T> operator*(const Mat23<T> &tLhs, const Vec3<U> &uRhs) noexcept
	{
		auto tRhs{static_cast<Vec3<T>>(uRhs)};

		return {tLhs.tX * tRhs, tLhs.tY * tRhs};
	}

	template<class T, class U>
	Mat23<U> operator*(const Vec3<T> &tLhs, const Mat23<U> &uRhs) noexcept
	{
		auto uLhs{static_cast<Vec3<U>>(tLhs)};

		return {uLhs * uRhs.tX, uLhs * uRhs.tY};
	}

	template<class T>
	Mat23<T> operator*(const Mat23<T> &tLhs, const Mat23<T> &tRhs) noexcept
	{
		return {tLhs.tX * tRhs.tX, tLhs.tY * tRhs.tY};
	}

	template<class T, class U>
	Mat23<T> operator/(const Mat23<T> &tLhs, U uRhs) noexcept
	{
		auto tRhs{static_cast<T>(uRhs)};

		return {tLhs.tX / tRhs, tLhs.tY / tRhs};
	}

	template<class T, class U>
	Mat23<U> operator/(T tLhs, const Mat23<U> &uRhs) noexcept
	{
		auto uLhs{static_cast<U>(tLhs)};

		return {uLhs / uRhs.tX, uLhs / uRhs.tY};
	}

	template<class T, class U>
	Mat23<T> operator/(const Mat23<T> &tLhs, const Vec3<U> &uRhs) noexcept
	{
		auto tRhs{static_cast<Vec3<T>>(uRhs)};

		return {tLhs.tX / tRhs, tLhs.tY / tRhs};
	}

	template<class T, class U>
	Mat23<U> operator/(const Vec3<T> &tLhs, const Mat23<U> &uRhs) noexcept
	{
		auto uLhs{static_cast<Vec3<U>>(tLhs)};

		return {uLhs / uRhs.tX, uLhs / uRhs.tY};
	}

	template<class T>
	Mat23<T> operator/(const Mat23<T> &tLhs, const Mat23<T> &tRhs) noexcept
	{
		return {tLhs.tX / tRhs.tX, tLhs.tY / tRhs.tY};
	}

	template<class T, class U>
	Vec2<T> operator%(const Mat23<T> &tLhs, const Vec3<U> &uRhs) noexcept
	{
		auto tRhs{static_cast<Vec3<T>>(uRhs)};

		return {Vec3<T>::dot(tLhs.tX, tRhs), Vec3<T>::dot(tLhs.tY, tRhs)};
	}

	template<class T, class U>
	Vec3<U> operator%(const Vec2<T> &tLhs, const Mat23<U> &uRhs) noexcept
	{
		auto uLhs{static_cast<Vec2<U>>(tLhs)};

		return {uLhs.tX * uRhs.tX.tX + uLhs.tY * uRhs.tY.tX,
				uLhs.tX * uRhs.tX.tY + uLhs.tY * uRhs.tY.tY,
				uLhs.tX * uRhs.tX.tZ + uLhs.tY * uRhs.tY.tZ};
	}
}	 // namespace onyx::transform

#endif