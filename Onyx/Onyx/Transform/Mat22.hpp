
/*
	2019.06.01
	Created by AcrylicShrimp.
*/

namespace Onyx::Transform
{
	template<class T> Mat22<T>::Mat22() :
		tX{Vec2<T>::zero()},
		tY{Vec2<T>::zero()}
	{
		//Empty.
	}

	template<class T> Mat22<T>::Mat22(Vec2<T> tX, Vec2<T> tY) :
		tX{tX},
		tY{tY}
	{
		//Empty.
	}

	template<class T> Mat22<T>::Mat22(T tXX, T tXY, T tYX, T tYY) :
		tX{tXX, tXY},
		tY{tYX, tYY}
	{
		//Empty.
	}

	template<class T> Vec2<T> &Mat22<T>::operator[](std::size_t nIndex)
	{
		switch (nIndex)
		{
		case 0:
			return this->tX;

		default:
			return this->tY;
		}
	}

	template<class T> const Vec2<T> &Mat22<T>::operator[](std::size_t nIndex) const
	{
		switch (nIndex)
		{
		case 0:
			return this->tX;

		default:
			return this->tY;
		}
	}

	template<class T> Mat22<T> Mat22<T>::operator+() const
	{
		return *this;
	}

	template<class T> Mat22<T> Mat22<T>::operator-() const
	{
		return {-this->tX, -this->tY};
	}

	template<class T> Mat22<T> &Mat22<T>::operator++()
	{
		++this->tX;
		++this->tY;

		return *this;
	}

	template<class T> Mat22<T> Mat22<T>::operator++(int)
	{
		auto tResult{*this};

		++this->tX;
		++this->tY;

		return tResult;
	}

	template<class T> Mat22<T> &Mat22<T>::operator--()
	{
		--this->tX;
		--this->tY;

		return *this;
	}

	template<class T> Mat22<T> Mat22<T>::operator--(int)
	{
		auto tResult{*this};

		--this->tX;
		--this->tY;

		return tResult;
	}

	template<class T> template<class U> Mat22<T> &Mat22<T>::operator+=(U uScalar)
	{
		auto tScalar{static_cast<T>(uScalar)};

		this->tX += tScalar;
		this->tY += tScalar;

		return *this;
	}

	template<class T> template<class U> Mat22<T> &Mat22<T>::operator+=(const Vec2<U> &uVec2)
	{
		auto tVec2{static_cast<Vec2<T>>(uVec2)};

		this->tX += tVec2;
		this->tY += tVec2;

		return *this;
	}

	template<class T> template<class U> Mat22<T> &Mat22<T>::operator+=(const Mat22<U> &uMat22)
	{
		this->tX += uMat22.tX;
		this->tY += uMat22.tY;

		return *this;
	}

	template<class T> template<class U> Mat22<T> &Mat22<T>::operator-=(U uScalar)
	{
		auto tScalar{static_cast<T>(uScalar)};

		this->tX -= tScalar;
		this->tY -= tScalar;

		return *this;
	}

	template<class T> template<class U> Mat22<T> &Mat22<T>::operator-=(const Vec2<U> &uVec2)
	{
		auto tVec2{static_cast<Vec2<T>>(uVec2)};

		this->tX -= tVec2;
		this->tY -= tVec2;

		return *this;
	}

	template<class T> template<class U> Mat22<T> &Mat22<T>::operator-=(const Mat22<U> &uMat22)
	{
		this->tX -= uMat22.tX;
		this->tY -= uMat22.tY;

		return *this;
	}

	template<class T> template<class U> Mat22<T> &Mat22<T>::operator*=(U uScalar)
	{
		auto tScalar{static_cast<T>(uScalar)};

		this->tX *= tScalar;
		this->tY *= tScalar;

		return *this;
	}

	template<class T> template<class U> Mat22<T> &Mat22<T>::operator*=(const Vec2<U> &uVec2)
	{
		auto tVec2{static_cast<Vec2<T>>(uVec2)};

		this->tX *= tVec2;
		this->tY *= tVec2;

		return *this;
	}

	template<class T> template<class U> Mat22<T> &Mat22<T>::operator*=(const Mat22<U> &uMat22)
	{
		this->tX *= uMat22.tX;
		this->tY *= uMat22.tY;

		return *this;
	}

	template<class T> template<class U> Mat22<T> &Mat22<T>::operator/=(U uScalar)
	{
		auto tScalar{static_cast<T>(uScalar)};

		this->tX /= tScalar;
		this->tY /= tScalar;

		return *this;
	}
	
	template<class T> template<class U> Mat22<T> &Mat22<T>::operator/=(const Vec2<U> &uVec2)
	{
		auto tVec2{static_cast<Vec2<T>>(uVec2)};

		this->tX /= tVec2;
		this->tY /= tVec2;

		return *this;
	}

	template<class T> template<class U> Mat22<T> &Mat22<T>::operator/=(const Mat22<U> &uMat22)
	{
		this->tX /= uMat22.tX;
		this->tY /= uMat22.tY;

		return *this;
	}

	template<class T> template<class U> bool Mat22<T>::operator==(U uScalar) const
	{
		auto tScalar{static_cast<T>(uScalar)};

		return
			this->tX == tScalar &&
			this->tY == tScalar;
	}

	template<class T> template<class U> bool Mat22<T>::operator==(const Vec2<U> &uVec2) const
	{
		auto tVec2{static_cast<Vec2<T>>(uVec2)};

		return
			this->tX == tVec2 &&
			this->tY == tVec2;
	}

	template<class T> template<class U> bool Mat22<T>::operator==(const Mat22<U> &uMat22) const
	{
		return
			this->tX == uMat22.tX &&
			this->tY == uMat22.tY;
	}

	template<class T> template<class U> bool Mat22<T>::operator!=(U uScalar) const
	{
		auto tScalar{static_cast<T>(uScalar)};

		return
			this->tX != tScalar ||
			this->tY != tScalar;
	}
	
	template<class T> template<class U> bool Mat22<T>::operator!=(const Vec2<U> &uVec2) const
	{
		auto tVec2{static_cast<Vec2<T>>(uVec2)};

		return
			this->tX != tVec2 ||
			this->tY != tVec2;
	}

	template<class T> template<class U> bool Mat22<T>::operator!=(const Mat22<U> &uMat22) const
	{
		return
			this->tX != uMat22.tX ||
			this->tY != uMat22.tY;
	}

	template<class T> template<class U> Mat22<T>::operator Mat22<U>() const
	{
		return {static_cast<Vec2<U>>(this->tX), static_cast<Vec2<U>>(this->tY)};
	}

	template<class T> Mat22<T> Mat22<T>::transposed() const
	{
		return
		{
			{this->tX.tX, this->tY.tX},
			{this->tX.tY, this->tY.tY}
		};
	}

	template<class T> Mat22<T> Mat22<T>::zero()
	{
		return {Vec2<T>::zero(), Vec2<T>::zero()};
	}

	template<class T> Mat22<T> Mat22<T>::one()
	{
		return {Vec2<T>::one(), Vec2<T>::one()};
	}

	template<class T> Mat22<T> Mat22<T>::identity()
	{
		return
		{
			Vec2<T>{static_cast<T>(1), static_cast<T>(0)},
			Vec2<T>{static_cast<T>(0), static_cast<T>(1)}
		};
	}

	template<class T, class U> Mat22<T> operator+(const Mat22<T> &tMat22, U uScalar)
	{
		auto tScalar{static_cast<T>(uScalar)};

		return {tMat22.tX + tScalar, tMat22.tY + tScalar};
	}
	
	template<class T, class U> Mat22<U> operator+(T tScalar, const Mat22<U> &uMat22)
	{
		auto uScalar{static_cast<U>(tScalar)};

		return {uScalar + uMat22.tX, uScalar + uMat22.tY};
	}

	template<class T, class U> Mat22<T> operator+(const Mat22<T> &tMat22, const Vec2<U> &uVec2)
	{
		auto tVec2{static_cast<Vec2<T>>(uVec2)};

		return {tMat22.tX + tVec2, tMat22.tY + tVec2};
	}

	template<class T, class U> Mat22<U> operator+(const Vec2<T> &tVec2, const Mat22<U> &uMat22)
	{
		auto uVec2{static_cast<Vec2<U>>(tVec2)};

		return {uVec2 + uMat22.tX, uVec2 + uMat22.tY};
	}

	template<class T> Mat22<T> operator+(const Mat22<T> &tLeft, const Mat22<T> &tRight)
	{
		return {tLeft.tX + tRight.tX, tLeft.tY + tRight.tY};
	}

	template<class T, class U> Mat22<T> operator-(const Mat22<T> &tMat22, U uScalar)
	{
		auto tScalar{static_cast<T>(uScalar)};

		return {tMat22.tX - tScalar, tMat22.tY - tScalar};
	}

	template<class T, class U> Mat22<U> operator-(T tScalar, const Mat22<U> &uMat22)
	{
		auto uScalar{static_cast<U>(tScalar)};

		return {uScalar - uMat22.tX, uScalar - uMat22.tY};
	}

	template<class T, class U> Mat22<T> operator-(const Mat22<T> &tMat22, const Vec2<U> &uVec2)
	{
		auto tVec2{static_cast<Vec2<T>>(uVec2)};

		return {tMat22.tX - tVec2, tMat22.tY - tVec2};
	}

	template<class T, class U> Mat22<U> operator-(const Vec2<T> &tVec2, const Mat22<U> &uMat22)
	{
		auto uVec2{static_cast<Vec2<U>>(tVec2)};

		return {uVec2 - uMat22.tX, uVec2 - uMat22.tY};
	}

	template<class T> Mat22<T> operator-(const Mat22<T> &tLeft, const Mat22<T> &tRight)
	{
		return {tLeft.tX - tRight.tX, tLeft.tY - tRight.tY};
	}

	template<class T, class U> Mat22<T> operator*(const Mat22<T> &tMat22, U uScalar)
	{
		auto tScalar{static_cast<T>(uScalar)};

		return {tMat22.tX * tScalar, tMat22.tY * tScalar};
	}

	template<class T, class U> Mat22<U> operator*(T tScalar, const Mat22<U> &uMat22)
	{
		auto uScalar{static_cast<U>(tScalar)};

		return {uScalar * uMat22.tX, uScalar * uMat22.tY};
	}

	template<class T, class U> Mat22<T> operator*(const Mat22<T> &tMat22, const Vec2<U> &uVec2)
	{
		auto tVec2{static_cast<Vec2<T>>(uVec2)};

		return {tMat22.tX * tVec2, tMat22.tY * tVec2};
	}

	template<class T, class U> Mat22<U> operator*(const Vec2<T> &tVec2, const Mat22<U> &uMat22)
	{
		auto uVec2{static_cast<Vec2<U>>(tVec2)};

		return {uVec2 * uMat22.tX, uVec2 * uMat22.tY};
	}

	template<class T> Mat22<T> operator*(const Mat22<T> &tLeft, const Mat22<T> &tRight)
	{
		return {tLeft.tX * tRight.tX, tLeft.tY * tRight.tY};
	}

	template<class T, class U> Mat22<T> operator/(const Mat22<T> &tMat22, U uScalar)
	{
		auto tScalar{static_cast<T>(uScalar)};

		return {tMat22.tX / tScalar, tMat22.tY / tScalar};
	}

	template<class T, class U> Mat22<U> operator/(T tScalar, const Mat22<U> &uMat22)
	{
		auto uScalar{static_cast<U>(tScalar)};

		return {uScalar / uMat22.tX, uScalar / uMat22.tY};
	}

	template<class T, class U> Mat22<T> operator/(const Mat22<T> &tMat22, const Vec2<U> &uVec2)
	{
		auto tVec2{static_cast<Vec2<T>>(uVec2)};

		return {tMat22.tX / tVec2, tMat22.tY / tVec2};
	}

	template<class T, class U> Mat22<U> operator/(const Vec2<T> &tVec2, const Mat22<U> &uMat22)
	{
		auto uVec2{static_cast<Vec2<U>>(tVec2)};

		return {uVec2 / uMat22.tX, uVec2 / uMat22.tY};
	}

	template<class T> Mat22<T> operator/(const Mat22<T> &tLeft, const Mat22<T> &tRight)
	{
		return {tLeft.tX / tRight.tX, tLeft.tY / tRight.tY};
	}

	template<class T, class U> Vec2<T> operator%(const Mat22<T> &tMat22, const Vec2<U> &uVec2)
	{
		auto tVec2{static_cast<Vec2<T>>(uVec2)};

		return
		{
			Vec2<T>::dot(tMat22.tX, tVec2),
			Vec2<T>::dot(tMat22.tY, tVec2)
		};
	}

	template<class T, class U> Vec2<U> operator%(const Vec2<T> &tVec2, const Mat22<U> &uMat22)
	{
		auto uVec2{static_cast<Vec2<U>>(tVec2)};

		return
		{
			uVec2.tX * uMat22.tX.tX + uVec2.tY * uMat22.tY.tX,
			uVec2.tX * uMat22.tX.tY + uVec2.tY * uMat22.tY.tY
		};
	}
}