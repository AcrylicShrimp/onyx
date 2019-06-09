
/*
	2019.06.06
	Created by AcrylicShrimp.
*/

namespace Onyx::Transform
{
	template<class T> Mat23<T>::Mat23() :
		tX{Vec3<T>::zero()},
		tY{Vec3<T>::zero()}
	{
		//Empty.
	}

	template<class T> Mat23<T>::Mat23(Vec3<T> tX, Vec3<T> tY) :
		tX{tX},
		tY{tY}
	{
		//Empty.
	}

	template<class T> Mat23<T>::Mat23(T tXX, T tXY, T tXZ, T tYX, T tYY, T tYZ) :
		tX{tXX, tXY, tXZ},
		tY{tYX, tYY, tYZ}
	{
		//Empty.
	}

	template<class T> Vec3<T> &Mat23<T>::operator[](std::size_t nIndex)
	{
		switch (nIndex)
		{
		case 0:
			return this->tX;

		default:
			return this->tY;
		}
	}

	template<class T> const Vec3<T> &Mat23<T>::operator[](std::size_t nIndex) const
	{
		switch (nIndex)
		{
		case 0:
			return this->tX;

		default:
			return this->tY;
		}
	}

	template<class T> Mat23<T> Mat23<T>::operator+() const
	{
		return *this;
	}

	template<class T> Mat23<T> Mat23<T>::operator-() const
	{
		return {-this->tX, -this->tY};
	}

	template<class T> Mat23<T> &Mat23<T>::operator++()
	{
		++this->tX;
		++this->tY;

		return *this;
	}

	template<class T> Mat23<T> Mat23<T>::operator++(int)
	{
		auto tResult{*this};

		++this->tX;
		++this->tY;

		return tResult;
	}

	template<class T> Mat23<T> &Mat23<T>::operator--()
	{
		--this->tX;
		--this->tY;

		return *this;
	}

	template<class T> Mat23<T> Mat23<T>::operator--(int)
	{
		auto tResult{*this};

		--this->tX;
		--this->tY;

		return tResult;
	}

	template<class T> template<class U> Mat23<T> &Mat23<T>::operator+=(U uScalar)
	{
		auto tScalar{static_cast<T>(uScalar)};

		this->tX += tScalar;
		this->tY += tScalar;

		return *this;
	}

	template<class T> template<class U> Mat23<T> &Mat23<T>::operator+=(const Vec3<U> &uVec3)
	{
		auto tVec3{static_cast<Vec3<T>>(uVec3)};

		this->tX += tVec3;
		this->tY += tVec3;

		return *this;
	}

	template<class T> template<class U> Mat23<T> &Mat23<T>::operator+=(const Mat23<U> &uMat23)
	{
		this->tX += uMat23.tX;
		this->tY += uMat23.tY;

		return *this;
	}

	template<class T> template<class U> Mat23<T> &Mat23<T>::operator-=(U uScalar)
	{
		auto tScalar{static_cast<T>(uScalar)};

		this->tX -= tScalar;
		this->tY -= tScalar;

		return *this;
	}

	template<class T> template<class U> Mat23<T> &Mat23<T>::operator-=(const Vec3<U> &uVec3)
	{
		auto tVec3{static_cast<Vec3<T>>(uVec3)};

		this->tX -= tVec3;
		this->tY -= tVec3;

		return *this;
	}

	template<class T> template<class U> Mat23<T> &Mat23<T>::operator-=(const Mat23<U> &uMat23)
	{
		this->tX -= uMat23.tX;
		this->tY -= uMat23.tY;

		return *this;
	}

	template<class T> template<class U> Mat23<T> &Mat23<T>::operator*=(U uScalar)
	{
		auto tScalar{static_cast<T>(uScalar)};

		this->tX *= tScalar;
		this->tY *= tScalar;

		return *this;
	}

	template<class T> template<class U> Mat23<T> &Mat23<T>::operator*=(const Vec3<U> &uVec3)
	{
		auto tVec3{static_cast<Vec3<T>>(uVec3)};

		this->tX *= tVec3;
		this->tY *= tVec3;

		return *this;
	}

	template<class T> template<class U> Mat23<T> &Mat23<T>::operator*=(const Mat23<U> &uMat23)
	{
		this->tX *= uMat23.tX;
		this->tY *= uMat23.tY;

		return *this;
	}

	template<class T> template<class U> Mat23<T> &Mat23<T>::operator/=(U uScalar)
	{
		auto tScalar{static_cast<T>(uScalar)};

		this->tX /= tScalar;
		this->tY /= tScalar;

		return *this;
	}

	template<class T> template<class U> Mat23<T> &Mat23<T>::operator/=(const Vec3<U> &uVec3)
	{
		auto tVec3{static_cast<Vec3<T>>(uVec3)};

		this->tX /= tVec3;
		this->tY /= tVec3;

		return *this;
	}

	template<class T> template<class U> Mat23<T> &Mat23<T>::operator/=(const Mat23<U> &uMat23)
	{
		this->tX /= uMat23.tX;
		this->tY /= uMat23.tY;

		return *this;
	}

	template<class T> template<class U> bool Mat23<T>::operator==(U uScalar) const
	{
		auto tScalar{static_cast<T>(uScalar)};

		return
			this->tX == tScalar &&
			this->tY == tScalar;
	}

	template<class T> template<class U> bool Mat23<T>::operator==(const Vec3<U> &uVec3) const
	{
		auto tVec3{static_cast<Vec3<T>>(uVec3)};

		return
			this->tX == tVec3 &&
			this->tY == tVec3;
	}

	template<class T> template<class U> bool Mat23<T>::operator==(const Mat23<U> &uMat23) const
	{
		return
			this->tX == uMat23.tX &&
			this->tY == uMat23.tY;
	}

	template<class T> template<class U> bool Mat23<T>::operator!=(U uScalar) const
	{
		auto tScalar{static_cast<T>(uScalar)};

		return
			this->tX != tScalar ||
			this->tY != tScalar;
	}

	template<class T> template<class U> bool Mat23<T>::operator!=(const Vec3<U> &uVec3) const
	{
		auto tVec3{static_cast<Vec3<T>>(uVec3)};

		return
			this->tX != tVec3 ||
			this->tY != tVec3;
	}

	template<class T> template<class U> bool Mat23<T>::operator!=(const Mat23<U> &uMat23) const
	{
		return
			this->tX != uMat23.tX ||
			this->tY != uMat23.tY;
	}

	template<class T> template<class U> Mat23<T>::operator Mat23<U>() const
	{
		return {static_cast<Vec3<U>>(this->tX), static_cast<Vec3<U>>(this->tY)};
	}

	template<class T> Mat32<T> Mat23<T>::transposed() const
	{
		return
		{
			{this->tX.tX, this->tY.tX},
			{this->tX.tY, this->tY.tY},
			{this->tX.tZ, this->tY.tZ}
		};
	}

	template<class T> Mat23<T> Mat23<T>::zero()
	{
		return {Vec3<T>::zero(), Vec3<T>::zero()};
	}

	template<class T> Mat23<T> Mat23<T>::one()
	{
		return {Vec3<T>::one(), Vec3<T>::one()};
	}

	template<class T, class U> Mat23<T> operator+(const Mat23<T> &tMat23, U uScalar)
	{
		auto tScalar{static_cast<T>(uScalar)};

		return {tMat23.tX + tScalar, tMat23.tY + tScalar};
	}

	template<class T, class U> Mat23<U> operator+(T tScalar, const Mat23<U> &uMat23)
	{
		auto uScalar{static_cast<U>(tScalar)};

		return {uScalar + uMat23.tX, uScalar + uMat23.tY};
	}

	template<class T, class U> Mat23<T> operator+(const Mat23<T> &tMat23, const Vec3<U> &uVec3)
	{
		auto tVec3{static_cast<Vec3<T>>(uVec3)};

		return {tMat23.tX + tVec3, tMat23.tY + tVec3};
	}

	template<class T, class U> Mat23<U> operator+(const Vec3<T> &tVec3, const Mat23<U> &uMat23)
	{
		auto uVec3{static_cast<Vec3<U>>(tVec3)};

		return {uVec3 + uMat23.tX, uVec3 + uMat23.tY};
	}

	template<class T> Mat23<T> operator+(const Mat23<T> &tLeft, const Mat23<T> &tRight)
	{
		return {tLeft.tX + tRight.tX, tLeft.tY + tRight.tY};
	}

	template<class T, class U> Mat23<T> operator-(const Mat23<T> &tMat23, U uScalar)
	{
		auto tScalar{static_cast<T>(uScalar)};

		return {tMat23.tX - tScalar, tMat23.tY - tScalar};
	}

	template<class T, class U> Mat23<U> operator-(T tScalar, const Mat23<U> &uMat23)
	{
		auto uScalar{static_cast<U>(tScalar)};

		return {uScalar - uMat23.tX, uScalar - uMat23.tY};
	}

	template<class T, class U> Mat23<T> operator-(const Mat23<T> &tMat23, const Vec3<U> &uVec3)
	{
		auto tVec3{static_cast<Vec3<T>>(uVec3)};

		return {tMat23.tX - tVec3, tMat23.tY - tVec3};
	}

	template<class T, class U> Mat23<U> operator-(const Vec3<T> &tVec3, const Mat23<U> &uMat23)
	{
		auto uVec3{static_cast<Vec3<U>>(tVec3)};

		return {uVec3 - uMat23.tX, uVec3 - uMat23.tY};
	}

	template<class T> Mat23<T> operator-(const Mat23<T> &tLeft, const Mat23<T> &tRight)
	{
		return {tLeft.tX - tRight.tX, tLeft.tY - tRight.tY};
	}

	template<class T, class U> Mat23<T> operator*(const Mat23<T> &tMat23, U uScalar)
	{
		auto tScalar{static_cast<T>(uScalar)};

		return {tMat23.tX * tScalar, tMat23.tY * tScalar};
	}

	template<class T, class U> Mat23<U> operator*(T tScalar, const Mat23<U> &uMat23)
	{
		auto uScalar{static_cast<U>(tScalar)};

		return {uScalar * uMat23.tX, uScalar * uMat23.tY};
	}

	template<class T, class U> Mat23<T> operator*(const Mat23<T> &tMat23, const Vec3<U> &uVec3)
	{
		auto tVec3{static_cast<Vec3<T>>(uVec3)};

		return {tMat23.tX * tVec3, tMat23.tY * tVec3};
	}

	template<class T, class U> Mat23<U> operator*(const Vec3<T> &tVec3, const Mat23<U> &uMat23)
	{
		auto uVec3{static_cast<Vec3<U>>(tVec3)};

		return {uVec3 * uMat23.tX, uVec3 * uMat23.tY};
	}

	template<class T> Mat23<T> operator*(const Mat23<T> &tLeft, const Mat23<T> &tRight)
	{
		return {tLeft.tX * tRight.tX, tLeft.tY * tRight.tY};
	}

	template<class T, class U> Mat23<T> operator/(const Mat23<T> &tMat23, U uScalar)
	{
		auto tScalar{static_cast<T>(uScalar)};

		return {tMat23.tX / tScalar, tMat23.tY / tScalar};
	}

	template<class T, class U> Mat23<U> operator/(T tScalar, const Mat23<U> &uMat23)
	{
		auto uScalar{static_cast<U>(tScalar)};

		return {uScalar / uMat23.tX, uScalar / uMat23.tY};
	}

	template<class T, class U> Mat23<T> operator/(const Mat23<T> &tMat23, const Vec3<U> &uVec3)
	{
		auto tVec3{static_cast<Vec3<T>>(uVec3)};

		return {tMat23.tX / tVec3, tMat23.tY / tVec3};
	}

	template<class T, class U> Mat23<U> operator/(const Vec3<T> &tVec3, const Mat23<U> &uMat23)
	{
		auto uVec3{static_cast<Vec3<U>>(tVec3)};

		return {uVec3 / uMat23.tX, uVec3 / uMat23.tY};
	}

	template<class T> Mat23<T> operator/(const Mat23<T> &tLeft, const Mat23<T> &tRight)
	{
		return {tLeft.tX / tRight.tX, tLeft.tY / tRight.tY};
	}

	template<class T, class U> Vec2<T> operator%(const Mat23<T> &tMat23, const Vec3<U> &uVec3)
	{
		auto tVec3{static_cast<Vec3<T>>(uVec3)};

		return
		{
			Vec3<T>::dot(tMat23.tX, tVec3),
			Vec3<T>::dot(tMat23.tY, tVec3)
		};
	}

	template<class T, class U> Vec3<U> operator%(const Vec2<T> &tVec2, const Mat23<U> &uMat23)
	{
		auto uVec2{static_cast<Vec2<U>>(tVec2)};

		return
		{
			uVec2.tX * uMat23.tX.tX + uVec2.tY * uMat23.tY.tX,
			uVec2.tX * uMat23.tX.tY + uVec2.tY * uMat23.tY.tY,
			uVec2.tX * uMat23.tX.tZ + uVec2.tY * uMat23.tY.tZ
		};
	}
}