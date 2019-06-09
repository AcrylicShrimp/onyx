
/*
	2019.06.09
	Created by AcrylicShrimp.
*/

namespace Onyx::Transform
{
	template<class T> Mat42<T>::Mat42() :
		tX{Vec2<T>::zero()},
		tY{Vec2<T>::zero()},
		tZ{Vec2<T>::zero()},
		tW{Vec2<T>::zero()}
	{
		//Empty.
	}

	template<class T> Mat42<T>::Mat42(Vec2<T> tX, Vec2<T> tY, Vec2<T> tZ, Vec2<T> tW) :
		tX{tX},
		tY{tY},
		tZ{tZ},
		tW{tW}
	{
		//Empty.
	}

	template<class T> Mat42<T>::Mat42(T tXX, T tXY, T tYX, T tYY, T tZX, T tZY, T tWX, T tWY) :
		tX{tXX, tXY},
		tY{tYX, tYY},
		tZ{tZX, tZY},
		tW{tWX, tWY}
	{
		//Empty.
	}

	template<class T> Vec2<T> &Mat42<T>::operator[](std::size_t nIndex)
	{
		switch (nIndex)
		{
		case 0:
			return this->tX;

		case 1:
			return this->tY;
		
		case 2:
			return this->tZ;

		default:
			return this->tW;
		}
	}

	template<class T> const Vec2<T> &Mat42<T>::operator[](std::size_t nIndex) const
	{
		switch (nIndex)
		{
		case 0:
			return this->tX;

		case 1:
			return this->tY;

		case 2:
			return this->tZ;

		default:
			return this->tW;
		}
	}

	template<class T> Mat42<T> Mat42<T>::operator+() const
	{
		return *this;
	}

	template<class T> Mat42<T> Mat42<T>::operator-() const
	{
		return {-this->tX, -this->tY, -this->tZ, -this->tW};
	}

	template<class T> Mat42<T> &Mat42<T>::operator++()
	{
		++this->tX;
		++this->tY;
		++this->tZ;
		++this->tW;

		return *this;
	}

	template<class T> Mat42<T> Mat42<T>::operator++(int)
	{
		auto tResult{*this};

		++this->tX;
		++this->tY;
		++this->tZ;
		++this->tW;

		return tResult;
	}

	template<class T> Mat42<T> &Mat42<T>::operator--()
	{
		--this->tX;
		--this->tY;
		--this->tZ;
		--this->tW;

		return *this;
	}

	template<class T> Mat42<T> Mat42<T>::operator--(int)
	{
		auto tResult{*this};

		--this->tX;
		--this->tY;
		--this->tZ;
		--this->tW;

		return tResult;
	}

	template<class T> template<class U> Mat42<T> &Mat42<T>::operator+=(U uScalar)
	{
		auto tScalar{static_cast<T>(uScalar)};

		this->tX += tScalar;
		this->tY += tScalar;
		this->tZ += tScalar;
		this->tW += tScalar;

		return *this;
	}

	template<class T> template<class U> Mat42<T> &Mat42<T>::operator+=(const Vec2<U> &uVec2)
	{
		auto tVec2{static_cast<Vec2<T>>(uVec2)};

		this->tX += tVec2;
		this->tY += tVec2;
		this->tZ += tVec2;
		this->tW += tVec2;

		return *this;
	}

	template<class T> template<class U> Mat42<T> &Mat42<T>::operator+=(const Mat42<U> &uMat42)
	{
		this->tX += uMat42.tX;
		this->tY += uMat42.tY;
		this->tZ += uMat42.tZ;
		this->tW += uMat42.tW;

		return *this;
	}

	template<class T> template<class U> Mat42<T> &Mat42<T>::operator-=(U uScalar)
	{
		auto tScalar{static_cast<T>(uScalar)};

		this->tX -= tScalar;
		this->tY -= tScalar;
		this->tZ -= tScalar;
		this->tW -= tScalar;

		return *this;
	}

	template<class T> template<class U> Mat42<T> &Mat42<T>::operator-=(const Vec2<U> &uVec2)
	{
		auto tVec2{static_cast<Vec2<T>>(uVec2)};

		this->tX -= tVec2;
		this->tY -= tVec2;
		this->tZ -= tVec2;
		this->tW -= tVec2;

		return *this;
	}

	template<class T> template<class U> Mat42<T> &Mat42<T>::operator-=(const Mat42<U> &uMat42)
	{
		this->tX -= uMat42.tX;
		this->tY -= uMat42.tY;
		this->tZ -= uMat42.tZ;
		this->tW -= uMat42.tW;

		return *this;
	}

	template<class T> template<class U> Mat42<T> &Mat42<T>::operator*=(U uScalar)
	{
		auto tScalar{static_cast<T>(uScalar)};

		this->tX *= tScalar;
		this->tY *= tScalar;
		this->tZ *= tScalar;
		this->tW *= tScalar;

		return *this;
	}

	template<class T> template<class U> Mat42<T> &Mat42<T>::operator*=(const Vec2<U> &uVec2)
	{
		auto tVec2{static_cast<Vec2<T>>(uVec2)};

		this->tX *= tVec2;
		this->tY *= tVec2;
		this->tZ *= tVec2;
		this->tW *= tVec2;

		return *this;
	}

	template<class T> template<class U> Mat42<T> &Mat42<T>::operator*=(const Mat42<U> &uMat42)
	{
		this->tX *= uMat42.tX;
		this->tY *= uMat42.tY;
		this->tZ *= uMat42.tZ;
		this->tW *= uMat42.tW;

		return *this;
	}

	template<class T> template<class U> Mat42<T> &Mat42<T>::operator/=(U uScalar)
	{
		auto tScalar{static_cast<T>(uScalar)};

		this->tX /= tScalar;
		this->tY /= tScalar;
		this->tZ /= tScalar;
		this->tW /= tScalar;

		return *this;
	}

	template<class T> template<class U> Mat42<T> &Mat42<T>::operator/=(const Vec2<U> &uVec2)
	{
		auto tVec2{static_cast<Vec2<T>>(uVec2)};

		this->tX /= tVec2;
		this->tY /= tVec2;
		this->tZ /= tVec2;
		this->tW /= tVec2;

		return *this;
	}

	template<class T> template<class U> Mat42<T> &Mat42<T>::operator/=(const Mat42<U> &uMat42)
	{
		this->tX /= uMat42.tX;
		this->tY /= uMat42.tY;
		this->tZ /= uMat42.tZ;
		this->tW /= uMat42.tW;

		return *this;
	}

	template<class T> template<class U> bool Mat42<T>::operator==(U uScalar) const
	{
		auto tScalar{static_cast<T>(uScalar)};

		return
			this->tX == tScalar &&
			this->tY == tScalar &&
			this->tZ == tScalar &&
			this->tW == tScalar;
	}

	template<class T> template<class U> bool Mat42<T>::operator==(const Vec2<U> &uVec2) const
	{
		auto tVec2{static_cast<Vec2<T>>(uVec2)};

		return
			this->tX == tVec2 &&
			this->tY == tVec2 &&
			this->tZ == tVec2 &&
			this->tW == tVec2;
	}

	template<class T> template<class U> bool Mat42<T>::operator==(const Mat42<U> &uMat42) const
	{
		return
			this->tX == uMat42.tX &&
			this->tY == uMat42.tY &&
			this->tZ == uMat42.tZ &&
			this->tW == uMat42.tW;
	}

	template<class T> template<class U> bool Mat42<T>::operator!=(U uScalar) const
	{
		auto tScalar{static_cast<T>(uScalar)};

		return
			this->tX != tScalar ||
			this->tY != tScalar ||
			this->tZ != tScalar ||
			this->tW != tScalar;
	}

	template<class T> template<class U> bool Mat42<T>::operator!=(const Vec2<U> &uVec2) const
	{
		auto tVec2{static_cast<Vec2<T>>(uVec2)};

		return
			this->tX != tVec2 ||
			this->tY != tVec2 ||
			this->tZ != tVec2 ||
			this->tW != tVec2;
	}

	template<class T> template<class U> bool Mat42<T>::operator!=(const Mat42<U> &uMat42) const
	{
		return
			this->tX != uMat42.tX ||
			this->tY != uMat42.tY ||
			this->tZ != uMat42.tZ ||
			this->tW != uMat42.tW;
	}

	template<class T> template<class U> Mat42<T>::operator Mat42<U>() const
	{
		return {static_cast<Vec2<U>>(this->tX), static_cast<Vec2<U>>(this->tY), static_cast<Vec2<U>>(this->tZ), static_cast<Vec2<U>>(this->tW)};
	}

	template<class T> Mat24<T> Mat42<T>::transposed() const
	{
		return
		{
			{this->tX.tX, this->tY.tX, this->tZ.tX, this->tW.tX},
			{this->tX.tY, this->tY.tY, this->tZ.tY, this->tW.tY}
		};
	}

	template<class T> Mat42<T> Mat42<T>::zero()
	{
		return {Vec2<T>::zero(), Vec2<T>::zero(), Vec2<T>::zero(), Vec2<T>::zero()};
	}

	template<class T> Mat42<T> Mat42<T>::one()
	{
		return {Vec2<T>::one(), Vec2<T>::one(), Vec2<T>::one(), Vec2<T>::one()};
	}

	template<class T, class U> Mat42<T> operator+(const Mat42<T> &tMat42, U uScalar)
	{
		auto tScalar{static_cast<T>(uScalar)};

		return {tMat42.tX + tScalar, tMat42.tY + tScalar, tMat42.tZ + tScalar, tMat42.tW + tScalar};
	}

	template<class T, class U> Mat42<U> operator+(T tScalar, const Mat42<U> &uMat42)
	{
		auto uScalar{static_cast<U>(tScalar)};

		return {uScalar + uMat42.tX, uScalar + uMat42.tY, uScalar + uMat42.tZ, uScalar + uMat42.tW};
	}

	template<class T, class U> Mat42<T> operator+(const Mat42<T> &tMat42, const Vec2<U> &uVec2)
	{
		auto tVec2{static_cast<Vec2<T>>(uVec2)};

		return {tMat42.tX + tVec2, tMat42.tY + tVec2, tMat42.tZ + tVec2, tMat42.tW + tVec2};
	}

	template<class T, class U> Mat42<U> operator+(const Vec2<T> &tVec2, const Mat42<U> &uMat42)
	{
		auto uVec2{static_cast<Vec2<U>>(tVec2)};

		return {uVec2 + uMat42.tX, uVec2 + uMat42.tY, uVec2 + uMat42.tZ, uVec2 + uMat42.tW};
	}

	template<class T> Mat42<T> operator+(const Mat42<T> &tLeft, const Mat42<T> &tRight)
	{
		return {tLeft.tX + tRight.tX, tLeft.tY + tRight.tY, tLeft.tZ + tRight.tZ, tLeft.tW + tRight.tW};
	}

	template<class T, class U> Mat42<T> operator-(const Mat42<T> &tMat42, U uScalar)
	{
		auto tScalar{static_cast<T>(uScalar)};

		return {tMat42.tX - tScalar, tMat42.tY - tScalar, tMat42.tZ - tScalar, tMat42.tW - tScalar};
	}

	template<class T, class U> Mat42<U> operator-(T tScalar, const Mat42<U> &uMat42)
	{
		auto uScalar{static_cast<U>(tScalar)};

		return {uScalar - uMat42.tX, uScalar - uMat42.tY, uScalar - uMat42.tZ, uScalar - uMat42.tW};
	}

	template<class T, class U> Mat42<T> operator-(const Mat42<T> &tMat42, const Vec2<U> &uVec2)
	{
		auto tVec2{static_cast<Vec2<T>>(uVec2)};

		return {tMat42.tX - tVec2, tMat42.tY - tVec2, tMat42.tZ - tVec2, tMat42.tW - tVec2};
	}

	template<class T, class U> Mat42<U> operator-(const Vec2<T> &tVec2, const Mat42<U> &uMat42)
	{
		auto uVec2{static_cast<Vec2<U>>(tVec2)};

		return {uVec2 - uMat42.tX, uVec2 - uMat42.tY, uVec2 - uMat42.tZ, uVec2 - uMat42.tW};
	}

	template<class T> Mat42<T> operator-(const Mat42<T> &tLeft, const Mat42<T> &tRight)
	{
		return {tLeft.tX - tRight.tX, tLeft.tY - tRight.tY, tLeft.tZ - tRight.tZ, tLeft.tW - tRight.tW};
	}

	template<class T, class U> Mat42<T> operator*(const Mat42<T> &tMat42, U uScalar)
	{
		auto tScalar{static_cast<T>(uScalar)};

		return {tMat42.tX * tScalar, tMat42.tY * tScalar, tMat42.tZ * tScalar, tMat42.tW * tScalar};
	}

	template<class T, class U> Mat42<U> operator*(T tScalar, const Mat42<U> &uMat42)
	{
		auto uScalar{static_cast<U>(tScalar)};

		return {uScalar * uMat42.tX, uScalar * uMat42.tY, uScalar * uMat42.tZ, uScalar * uMat42.tW};
	}

	template<class T, class U> Mat42<T> operator*(const Mat42<T> &tMat42, const Vec2<U> &uVec2)
	{
		auto tVec2{static_cast<Vec2<T>>(uVec2)};

		return {tMat42.tX * tVec2, tMat42.tY * tVec2, tMat42.tZ * tVec2, tMat42.tW * tVec2};
	}

	template<class T, class U> Mat42<U> operator*(const Vec2<T> &tVec2, const Mat42<U> &uMat42)
	{
		auto uVec2{static_cast<Vec2<U>>(tVec2)};

		return {uVec2 * uMat42.tX, uVec2 * uMat42.tY, uVec2 * uMat42.tZ, uVec2 * uMat42.tW};
	}

	template<class T> Mat42<T> operator*(const Mat42<T> &tLeft, const Mat42<T> &tRight)
	{
		return {tLeft.tX * tRight.tX, tLeft.tY * tRight.tY, tLeft.tZ * tRight.tZ, tLeft.tW * tRight.tW};
	}

	template<class T, class U> Mat42<T> operator/(const Mat42<T> &tMat42, U uScalar)
	{
		auto tScalar{static_cast<T>(uScalar)};

		return {tMat42.tX / tScalar, tMat42.tY / tScalar, tMat42.tZ / tScalar, tMat42.tW / tScalar};
	}

	template<class T, class U> Mat42<U> operator/(T tScalar, const Mat42<U> &uMat42)
	{
		auto uScalar{static_cast<U>(tScalar)};

		return {uScalar / uMat42.tX, uScalar / uMat42.tY, uScalar / uMat42.tZ, uScalar / uMat42.tW};
	}

	template<class T, class U> Mat42<T> operator/(const Mat42<T> &tMat42, const Vec2<U> &uVec2)
	{
		auto tVec2{static_cast<Vec2<T>>(uVec2)};

		return {tMat42.tX / tVec2, tMat42.tY / tVec2, tMat42.tZ / tVec2, tMat42.tW / tVec2};
	}

	template<class T, class U> Mat42<U> operator/(const Vec2<T> &tVec2, const Mat42<U> &uMat42)
	{
		auto uVec2{static_cast<Vec2<U>>(tVec2)};

		return {uVec2 / uMat42.tX, uVec2 / uMat42.tY, uVec2 / uMat42.tZ, uVec2 / uMat42.tW};
	}

	template<class T> Mat42<T> operator/(const Mat42<T> &tLeft, const Mat42<T> &tRight)
	{
		return {tLeft.tX / tRight.tX, tLeft.tY / tRight.tY, tLeft.tZ / tRight.tZ, tLeft.tW / tRight.tW};
	}

	template<class T, class U> Vec4<T> operator%(const Mat42<T> &tMat42, const Vec2<U> &uVec2)
	{
		auto tVec2{static_cast<Vec2<T>>(uVec2)};

		return
		{
			Vec2<T>::dot(tMat42.tX, tVec2),
			Vec2<T>::dot(tMat42.tY, tVec2),
			Vec2<T>::dot(tMat42.tZ, tVec2),
			Vec2<T>::dot(tMat42.tW, tVec2)
		};
	}

	template<class T, class U> Vec2<U> operator%(const Vec4<T> &tVec4, const Mat42<U> &uMat42)
	{
		auto uVec4{static_cast<Vec4<U>>(tVec4)};

		return
		{
			uVec4.tX * uMat42.tX.tX + uVec4.tY * uMat42.tY.tX + uVec4.tZ * uMat42.tZ.tX + uVec4.tZ * uMat42.tW.tX,
			uVec4.tX * uMat42.tX.tY + uVec4.tY * uMat42.tY.tY + uVec4.tZ * uMat42.tZ.tY + uVec4.tZ * uMat42.tW.tY
		};
	}
}