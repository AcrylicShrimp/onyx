
/*
	2019.06.08
	Created by AcrylicShrimp.
*/

namespace Onyx::Transform
{
	template<class T> Mat24<T>::Mat24() :
		tX{Vec4<T>::zero()},
		tY{Vec4<T>::zero()}
	{
		//Empty.
	}

	template<class T> Mat24<T>::Mat24(Vec4<T> tX, Vec4<T> tY) :
		tX{tX},
		tY{tY}
	{
		//Empty.
	}

	template<class T> Mat24<T>::Mat24(T tXX, T tXY, T tXZ, T tXW, T tYX, T tYY, T tYZ, T tYW) :
		tX{tXX, tXY, tXZ, tXW},
		tY{tYX, tYY, tYZ, tYW}
	{
		//Empty.
	}

	template<class T> Vec4<T> &Mat24<T>::operator[](std::size_t nIndex)
	{
		switch (nIndex)
		{
		case 0:
			return this->tX;

		default:
			return this->tY;
		}
	}

	template<class T> const Vec4<T> &Mat24<T>::operator[](std::size_t nIndex) const
	{
		switch (nIndex)
		{
		case 0:
			return this->tX;

		default:
			return this->tY;
		}
	}

	template<class T> Mat24<T> Mat24<T>::operator+() const
	{
		return *this;
	}

	template<class T> Mat24<T> Mat24<T>::operator-() const
	{
		return {-this->tX, -this->tY};
	}

	template<class T> Mat24<T> &Mat24<T>::operator++()
	{
		++this->tX;
		++this->tY;

		return *this;
	}

	template<class T> Mat24<T> Mat24<T>::operator++(int)
	{
		auto tResult{*this};

		++this->tX;
		++this->tY;

		return tResult;
	}

	template<class T> Mat24<T> &Mat24<T>::operator--()
	{
		--this->tX;
		--this->tY;

		return *this;
	}

	template<class T> Mat24<T> Mat24<T>::operator--(int)
	{
		auto tResult{*this};

		--this->tX;
		--this->tY;

		return tResult;
	}

	template<class T> template<class U> Mat24<T> &Mat24<T>::operator+=(U uScalar)
	{
		auto tScalar{static_cast<T>(uScalar)};

		this->tX += tScalar;
		this->tY += tScalar;

		return *this;
	}

	template<class T> template<class U> Mat24<T> &Mat24<T>::operator+=(const Vec4<U> &uVec4)
	{
		auto tVec4{static_cast<Vec4<T>>(uVec4)};

		this->tX += tVec4;
		this->tY += tVec4;

		return *this;
	}

	template<class T> template<class U> Mat24<T> &Mat24<T>::operator+=(const Mat24<U> &uMat24)
	{
		this->tX += uMat24.tX;
		this->tY += uMat24.tY;

		return *this;
	}

	template<class T> template<class U> Mat24<T> &Mat24<T>::operator-=(U uScalar)
	{
		auto tScalar{static_cast<T>(uScalar)};

		this->tX -= tScalar;
		this->tY -= tScalar;

		return *this;
	}

	template<class T> template<class U> Mat24<T> &Mat24<T>::operator-=(const Vec4<U> &uVec4)
	{
		auto tVec4{static_cast<Vec4<T>>(uVec4)};

		this->tX -= tVec4;
		this->tY -= tVec4;

		return *this;
	}

	template<class T> template<class U> Mat24<T> &Mat24<T>::operator-=(const Mat24<U> &uMat24)
	{
		this->tX -= uMat24.tX;
		this->tY -= uMat24.tY;

		return *this;
	}

	template<class T> template<class U> Mat24<T> &Mat24<T>::operator*=(U uScalar)
	{
		auto tScalar{static_cast<T>(uScalar)};

		this->tX *= tScalar;
		this->tY *= tScalar;

		return *this;
	}

	template<class T> template<class U> Mat24<T> &Mat24<T>::operator*=(const Vec4<U> &uVec4)
	{
		auto tVec4{static_cast<Vec4<T>>(uVec4)};

		this->tX *= tVec4;
		this->tY *= tVec4;

		return *this;
	}

	template<class T> template<class U> Mat24<T> &Mat24<T>::operator*=(const Mat24<U> &uMat24)
	{
		this->tX *= uMat24.tX;
		this->tY *= uMat24.tY;

		return *this;
	}

	template<class T> template<class U> Mat24<T> &Mat24<T>::operator/=(U uScalar)
	{
		auto tScalar{static_cast<T>(uScalar)};

		this->tX /= tScalar;
		this->tY /= tScalar;

		return *this;
	}

	template<class T> template<class U> Mat24<T> &Mat24<T>::operator/=(const Vec4<U> &uVec4)
	{
		auto tVec4{static_cast<Vec4<T>>(uVec4)};

		this->tX /= tVec4;
		this->tY /= tVec4;

		return *this;
	}

	template<class T> template<class U> Mat24<T> &Mat24<T>::operator/=(const Mat24<U> &uMat24)
	{
		this->tX /= uMat24.tX;
		this->tY /= uMat24.tY;

		return *this;
	}

	template<class T> template<class U> bool Mat24<T>::operator==(U uScalar) const
	{
		auto tScalar{static_cast<T>(uScalar)};

		return
			this->tX == tScalar &&
			this->tY == tScalar;
	}

	template<class T> template<class U> bool Mat24<T>::operator==(const Vec4<U> &uVec4) const
	{
		auto tVec4{static_cast<Vec4<T>>(uVec4)};

		return
			this->tX == tVec4 &&
			this->tY == tVec4;
	}

	template<class T> template<class U> bool Mat24<T>::operator==(const Mat24<U> &uMat24) const
	{
		return
			this->tX == uMat24.tX &&
			this->tY == uMat24.tY;
	}

	template<class T> template<class U> bool Mat24<T>::operator!=(U uScalar) const
	{
		auto tScalar{static_cast<T>(uScalar)};

		return
			this->tX != tScalar ||
			this->tY != tScalar;
	}

	template<class T> template<class U> bool Mat24<T>::operator!=(const Vec4<U> &uVec4) const
	{
		auto tVec4{static_cast<Vec4<T>>(uVec4)};

		return
			this->tX != tVec4 ||
			this->tY != tVec4;
	}

	template<class T> template<class U> bool Mat24<T>::operator!=(const Mat24<U> &uMat24) const
	{
		return
			this->tX != uMat24.tX ||
			this->tY != uMat24.tY;
	}

	template<class T> template<class U> Mat24<T>::operator Mat24<U>() const
	{
		return {static_cast<Vec4<U>>(this->tX), static_cast<Vec4<U>>(this->tY)};
	}

	template<class T> Mat42<T> Mat24<T>::transposed() const
	{
		return
		{
			{this->tX.tX, this->tY.tX},
			{this->tX.tY, this->tY.tY},
			{this->tX.tZ, this->tY.tZ},
			{this->tX.tW, this->tY.tW}
		};
	}

	template<class T> Mat24<T> Mat24<T>::zero()
	{
		return {Vec4<T>::zero(), Vec4<T>::zero()};
	}

	template<class T> Mat24<T> Mat24<T>::one()
	{
		return {Vec4<T>::one(), Vec4<T>::one()};
	}

	template<class T, class U> Mat24<T> operator+(const Mat24<T> &tMat24, U uScalar)
	{
		auto tScalar{static_cast<T>(uScalar)};

		return {tMat24.tX + tScalar, tMat24.tY + tScalar};
	}

	template<class T, class U> Mat24<U> operator+(T tScalar, const Mat24<U> &uMat24)
	{
		auto uScalar{static_cast<U>(tScalar)};

		return {uScalar + uMat24.tX, uScalar + uMat24.tY};
	}

	template<class T, class U> Mat24<T> operator+(const Mat24<T> &tMat24, const Vec4<U> &uVec4)
	{
		auto tVec4{static_cast<Vec4<T>>(uVec4)};

		return {tMat24.tX + tVec4, tMat24.tY + tVec4};
	}

	template<class T, class U> Mat24<U> operator+(const Vec4<T> &tVec4, const Mat24<U> &uMat24)
	{
		auto uVec4{static_cast<Vec4<U>>(tVec4)};

		return {uVec4 + uMat24.tX, uVec4 + uMat24.tY};
	}

	template<class T> Mat24<T> operator+(const Mat24<T> &tLeft, const Mat24<T> &tRight)
	{
		return {tLeft.tX + tRight.tX, tLeft.tY + tRight.tY};
	}

	template<class T, class U> Mat24<T> operator-(const Mat24<T> &tMat24, U uScalar)
	{
		auto tScalar{static_cast<T>(uScalar)};

		return {tMat24.tX - tScalar, tMat24.tY - tScalar};
	}

	template<class T, class U> Mat24<U> operator-(T tScalar, const Mat24<U> &uMat24)
	{
		auto uScalar{static_cast<U>(tScalar)};

		return {uScalar - uMat24.tX, uScalar - uMat24.tY};
	}

	template<class T, class U> Mat24<T> operator-(const Mat24<T> &tMat24, const Vec4<U> &uVec4)
	{
		auto tVec4{static_cast<Vec4<T>>(uVec4)};

		return {tMat24.tX - tVec4, tMat24.tY - tVec4};
	}

	template<class T, class U> Mat24<U> operator-(const Vec4<T> &tVec4, const Mat24<U> &uMat24)
	{
		auto uVec4{static_cast<Vec4<U>>(tVec4)};

		return {uVec4 - uMat24.tX, uVec4 - uMat24.tY};
	}

	template<class T> Mat24<T> operator-(const Mat24<T> &tLeft, const Mat24<T> &tRight)
	{
		return {tLeft.tX - tRight.tX, tLeft.tY - tRight.tY};
	}

	template<class T, class U> Mat24<T> operator*(const Mat24<T> &tMat24, U uScalar)
	{
		auto tScalar{static_cast<T>(uScalar)};

		return {tMat24.tX * tScalar, tMat24.tY * tScalar};
	}

	template<class T, class U> Mat24<U> operator*(T tScalar, const Mat24<U> &uMat24)
	{
		auto uScalar{static_cast<U>(tScalar)};

		return {uScalar * uMat24.tX, uScalar * uMat24.tY};
	}

	template<class T, class U> Mat24<T> operator*(const Mat24<T> &tMat24, const Vec4<U> &uVec4)
	{
		auto tVec4{static_cast<Vec4<T>>(uVec4)};

		return {tMat24.tX * tVec4, tMat24.tY * tVec4};
	}

	template<class T, class U> Mat24<U> operator*(const Vec4<T> &tVec4, const Mat24<U> &uMat24)
	{
		auto uVec4{static_cast<Vec4<U>>(tVec4)};

		return {uVec4 * uMat24.tX, uVec4 * uMat24.tY};
	}

	template<class T> Mat24<T> operator*(const Mat24<T> &tLeft, const Mat24<T> &tRight)
	{
		return {tLeft.tX * tRight.tX, tLeft.tY * tRight.tY};
	}

	template<class T, class U> Mat24<T> operator/(const Mat24<T> &tMat24, U uScalar)
	{
		auto tScalar{static_cast<T>(uScalar)};

		return {tMat24.tX / tScalar, tMat24.tY / tScalar};
	}

	template<class T, class U> Mat24<U> operator/(T tScalar, const Mat24<U> &uMat24)
	{
		auto uScalar{static_cast<U>(tScalar)};

		return {uScalar / uMat24.tX, uScalar / uMat24.tY};
	}

	template<class T, class U> Mat24<T> operator/(const Mat24<T> &tMat24, const Vec4<U> &uVec4)
	{
		auto tVec4{static_cast<Vec4<T>>(uVec4)};

		return {tMat24.tX / tVec4, tMat24.tY / tVec4};
	}

	template<class T, class U> Mat24<U> operator/(const Vec4<T> &tVec4, const Mat24<U> &uMat24)
	{
		auto uVec4{static_cast<Vec4<U>>(tVec4)};

		return {uVec4 / uMat24.tX, uVec4 / uMat24.tY};
	}

	template<class T> Mat24<T> operator/(const Mat24<T> &tLeft, const Mat24<T> &tRight)
	{
		return {tLeft.tX / tRight.tX, tLeft.tY / tRight.tY};
	}

	template<class T, class U> Vec2<T> operator%(const Mat24<T> &tMat24, const Vec4<U> &uVec4)
	{
		auto tVec4{static_cast<Vec4<T>>(uVec4)};

		return
		{
			Vec4<T>::dot(tMat24.tX, tVec4),
			Vec4<T>::dot(tMat24.tY, tVec4)
		};
	}

	template<class T, class U> Vec4<U> operator%(const Vec2<T> &tVec2, const Mat24<U> &uMat24)
	{
		auto uVec2{static_cast<Vec2<U>>(tVec2)};

		return
		{
			uVec2.tX * uMat24.tX.tX + uVec2.tY * uMat24.tY.tX,
			uVec2.tX * uMat24.tX.tY + uVec2.tY * uMat24.tY.tY,
			uVec2.tX * uMat24.tX.tZ + uVec2.tY * uMat24.tY.tZ,
			uVec2.tX * uMat24.tX.tW + uVec2.tY * uMat24.tY.tW
		};
	}
}