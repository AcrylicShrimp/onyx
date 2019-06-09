
/*
	2019.06.09
	Created by AcrylicShrimp.
*/

namespace Onyx::Transform
{
	template<class T> Mat44<T>::Mat44() :
		tX{Vec4<T>::zero()},
		tY{Vec4<T>::zero()},
		tZ{Vec4<T>::zero()},
		tW{Vec4<T>::zero()}
	{
		//Empty.
	}

	template<class T> Mat44<T>::Mat44(Vec4<T> tX, Vec4<T> tY, Vec4<T> tZ, Vec4<T> tW) :
		tX{tX},
		tY{tY},
		tZ{tZ},
		tW{tW}
	{
		//Empty.
	}

	template<class T> Mat44<T>::Mat44(T tXX, T tXY, T tXZ, T tXW, T tYX, T tYY, T tYZ, T tYW, T tZX, T tZY, T tZZ, T tZW, T tWX, T tWY, T tWZ, T tWW) :
		tX{tXX, tXY, tXZ, tXW},
		tY{tYX, tYY, tYZ, tYW},
		tZ{tZX, tZY, tZZ, tZW},
		tW{tWX, tWY, tWZ, tWW}
	{
		//Empty.
	}

	template<class T> Vec4<T> &Mat44<T>::operator[](std::size_t nIndex)
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

	template<class T> const Vec4<T> &Mat44<T>::operator[](std::size_t nIndex) const
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

	template<class T> Mat44<T> Mat44<T>::operator+() const
	{
		return *this;
	}

	template<class T> Mat44<T> Mat44<T>::operator-() const
	{
		return {-this->tX, -this->tY, -this->tZ, -this->tW};
	}

	template<class T> Mat44<T> &Mat44<T>::operator++()
	{
		++this->tX;
		++this->tY;
		++this->tZ;
		++this->tW;

		return *this;
	}

	template<class T> Mat44<T> Mat44<T>::operator++(int)
	{
		auto tResult{*this};

		++this->tX;
		++this->tY;
		++this->tZ;
		++this->tW;

		return tResult;
	}

	template<class T> Mat44<T> &Mat44<T>::operator--()
	{
		--this->tX;
		--this->tY;
		--this->tZ;
		--this->tW;

		return *this;
	}

	template<class T> Mat44<T> Mat44<T>::operator--(int)
	{
		auto tResult{*this};

		--this->tX;
		--this->tY;
		--this->tZ;
		--this->tW;

		return tResult;
	}

	template<class T> template<class U> Mat44<T> &Mat44<T>::operator+=(U uScalar)
	{
		auto tScalar{static_cast<T>(uScalar)};

		this->tX += tScalar;
		this->tY += tScalar;
		this->tZ += tScalar;
		this->tW += tScalar;

		return *this;
	}

	template<class T> template<class U> Mat44<T> &Mat44<T>::operator+=(const Vec4<U> &uVec4)
	{
		auto tVec4{static_cast<Vec4<T>>(uVec4)};

		this->tX += tVec4;
		this->tY += tVec4;
		this->tZ += tVec4;
		this->tW += tVec4;

		return *this;
	}

	template<class T> template<class U> Mat44<T> &Mat44<T>::operator+=(const Mat44<U> &uMat44)
	{
		this->tX += uMat44.tX;
		this->tY += uMat44.tY;
		this->tZ += uMat44.tZ;
		this->tW += uMat44.tW;

		return *this;
	}

	template<class T> template<class U> Mat44<T> &Mat44<T>::operator-=(U uScalar)
	{
		auto tScalar{static_cast<T>(uScalar)};

		this->tX -= tScalar;
		this->tY -= tScalar;
		this->tZ -= tScalar;
		this->tW -= tScalar;

		return *this;
	}

	template<class T> template<class U> Mat44<T> &Mat44<T>::operator-=(const Vec4<U> &uVec4)
	{
		auto tVec4{static_cast<Vec4<T>>(uVec4)};

		this->tX -= tVec4;
		this->tY -= tVec4;
		this->tZ -= tVec4;
		this->tW -= tVec4;

		return *this;
	}

	template<class T> template<class U> Mat44<T> &Mat44<T>::operator-=(const Mat44<U> &uMat44)
	{
		this->tX -= uMat44.tX;
		this->tY -= uMat44.tY;
		this->tZ -= uMat44.tZ;
		this->tW -= uMat44.tW;

		return *this;
	}

	template<class T> template<class U> Mat44<T> &Mat44<T>::operator*=(U uScalar)
	{
		auto tScalar{static_cast<T>(uScalar)};

		this->tX *= tScalar;
		this->tY *= tScalar;
		this->tZ *= tScalar;
		this->tW *= tScalar;

		return *this;
	}

	template<class T> template<class U> Mat44<T> &Mat44<T>::operator*=(const Vec4<U> &uVec4)
	{
		auto tVec4{static_cast<Vec4<T>>(uVec4)};

		this->tX *= tVec4;
		this->tY *= tVec4;
		this->tZ *= tVec4;
		this->tW *= tVec4;

		return *this;
	}

	template<class T> template<class U> Mat44<T> &Mat44<T>::operator*=(const Mat44<U> &uMat44)
	{
		this->tX *= uMat44.tX;
		this->tY *= uMat44.tY;
		this->tZ *= uMat44.tZ;
		this->tW *= uMat44.tW;

		return *this;
	}

	template<class T> template<class U> Mat44<T> &Mat44<T>::operator/=(U uScalar)
	{
		auto tScalar{static_cast<T>(uScalar)};

		this->tX /= tScalar;
		this->tY /= tScalar;
		this->tZ /= tScalar;
		this->tW /= tScalar;

		return *this;
	}

	template<class T> template<class U> Mat44<T> &Mat44<T>::operator/=(const Vec4<U> &uVec4)
	{
		auto tVec4{static_cast<Vec4<T>>(uVec4)};

		this->tX /= tVec4;
		this->tY /= tVec4;
		this->tZ /= tVec4;
		this->tW /= tVec4;

		return *this;
	}

	template<class T> template<class U> Mat44<T> &Mat44<T>::operator/=(const Mat44<U> &uMat44)
	{
		this->tX /= uMat44.tX;
		this->tY /= uMat44.tY;
		this->tZ /= uMat44.tZ;
		this->tW /= uMat44.tW;

		return *this;
	}

	template<class T> template<class U> bool Mat44<T>::operator==(U uScalar) const
	{
		auto tScalar{static_cast<T>(uScalar)};

		return
			this->tX == tScalar &&
			this->tY == tScalar &&
			this->tZ == tScalar &&
			this->tW == tScalar;
	}

	template<class T> template<class U> bool Mat44<T>::operator==(const Vec4<U> &uVec4) const
	{
		auto tVec4{static_cast<Vec4<T>>(uVec4)};

		return
			this->tX == tVec4 &&
			this->tY == tVec4 &&
			this->tZ == tVec4 &&
			this->tW == tVec4;
	}

	template<class T> template<class U> bool Mat44<T>::operator==(const Mat44<U> &uMat44) const
	{
		return
			this->tX == uMat44.tX &&
			this->tY == uMat44.tY &&
			this->tZ == uMat44.tZ &&
			this->tW == uMat44.tW;
	}

	template<class T> template<class U> bool Mat44<T>::operator!=(U uScalar) const
	{
		auto tScalar{static_cast<T>(uScalar)};

		return
			this->tX != tScalar ||
			this->tY != tScalar ||
			this->tZ != tScalar ||
			this->tW != tScalar;
	}

	template<class T> template<class U> bool Mat44<T>::operator!=(const Vec4<U> &uVec4) const
	{
		auto tVec4{static_cast<Vec4<T>>(uVec4)};

		return
			this->tX != tVec4 ||
			this->tY != tVec4 ||
			this->tZ != tVec4 ||
			this->tW != tVec4;
	}

	template<class T> template<class U> bool Mat44<T>::operator!=(const Mat44<U> &uMat44) const
	{
		return
			this->tX != uMat44.tX ||
			this->tY != uMat44.tY ||
			this->tZ != uMat44.tZ ||
			this->tW != uMat44.tW;
	}

	template<class T> template<class U> Mat44<T>::operator Mat44<U>() const
	{
		return {static_cast<Vec4<U>>(this->tX), static_cast<Vec4<U>>(this->tY), static_cast<Vec4<U>>(this->tZ), static_cast<Vec4<U>>(this->tW)};
	}

	template<class T> Mat44<T> Mat44<T>::transposed() const
	{
		return
		{
			{this->tX.tX, this->tY.tX, this->tZ.tX, this->tW.tX},
			{this->tX.tY, this->tY.tY, this->tZ.tY, this->tW.tY},
			{this->tX.tZ, this->tY.tZ, this->tZ.tZ, this->tW.tZ},
			{this->tX.tW, this->tY.tW, this->tZ.tW, this->tW.tW}
		};
	}

	template<class T> Mat44<T> Mat44<T>::zero()
	{
		return {Vec4<T>::zero(), Vec4<T>::zero(), Vec4<T>::zero(), Vec4<T>::zero()};
	}

	template<class T> Mat44<T> Mat44<T>::one()
	{
		return {Vec4<T>::one(), Vec4<T>::one(), Vec4<T>::one(), Vec4<T>::one()};
	}

	template<class T> Mat44<T> Mat44<T>::identity()
	{
		return
		{
			Vec3<T>{static_cast<T>(1), static_cast<T>(0), static_cast<T>(0), static_cast<T>(0)},
			Vec3<T>{static_cast<T>(0), static_cast<T>(1), static_cast<T>(0), static_cast<T>(0)},
			Vec3<T>{static_cast<T>(0), static_cast<T>(0), static_cast<T>(1), static_cast<T>(0)},
			Vec3<T>{static_cast<T>(0), static_cast<T>(0), static_cast<T>(0), static_cast<T>(1)}
		};
	}

	template<class T, class U> Mat44<T> operator+(const Mat44<T> &tMat44, U uScalar)
	{
		auto tScalar{static_cast<T>(uScalar)};

		return {tMat44.tX + tScalar, tMat44.tY + tScalar, tMat44.tZ + tScalar, tMat44.tW + tScalar};
	}

	template<class T, class U> Mat44<U> operator+(T tScalar, const Mat44<U> &uMat44)
	{
		auto uScalar{static_cast<U>(tScalar)};

		return {uScalar + uMat44.tX, uScalar + uMat44.tY, uScalar + uMat44.tZ, uScalar + uMat44.tW};
	}

	template<class T, class U> Mat44<T> operator+(const Mat44<T> &tMat44, const Vec4<U> &uVec4)
	{
		auto tVec4{static_cast<Vec4<T>>(uVec4)};

		return {tMat44.tX + tVec4, tMat44.tY + tVec4, tMat44.tZ + tVec4, tMat44.tW + tVec4};
	}

	template<class T, class U> Mat44<U> operator+(const Vec4<T> &tVec4, const Mat44<U> &uMat44)
	{
		auto uVec4{static_cast<Vec4<U>>(tVec4)};

		return {uVec4 + uMat44.tX, uVec4 + uMat44.tY, uVec4 + uMat44.tZ, uVec4 + uMat44.tW};
	}

	template<class T> Mat44<T> operator+(const Mat44<T> &tLeft, const Mat44<T> &tRight)
	{
		return {tLeft.tX + tRight.tX, tLeft.tY + tRight.tY, tLeft.tZ + tRight.tZ, tLeft.tW + tRight.tW};
	}

	template<class T, class U> Mat44<T> operator-(const Mat44<T> &tMat44, U uScalar)
	{
		auto tScalar{static_cast<T>(uScalar)};

		return {tMat44.tX - tScalar, tMat44.tY - tScalar, tMat44.tZ - tScalar, tMat44.tW - tScalar};
	}

	template<class T, class U> Mat44<U> operator-(T tScalar, const Mat44<U> &uMat44)
	{
		auto uScalar{static_cast<U>(tScalar)};

		return {uScalar - uMat44.tX, uScalar - uMat44.tY, uScalar - uMat44.tZ, uScalar - uMat44.tW};
	}

	template<class T, class U> Mat44<T> operator-(const Mat44<T> &tMat44, const Vec4<U> &uVec4)
	{
		auto tVec4{static_cast<Vec4<T>>(uVec4)};

		return {tMat44.tX - tVec4, tMat44.tY - tVec4, tMat44.tZ - tVec4, tMat44.tW - tVec4};
	}

	template<class T, class U> Mat44<U> operator-(const Vec4<T> &tVec4, const Mat44<U> &uMat44)
	{
		auto uVec4{static_cast<Vec4<U>>(tVec4)};

		return {uVec4 - uMat44.tX, uVec4 - uMat44.tY, uVec4 - uMat44.tZ, uVec4 - uMat44.tW};
	}

	template<class T> Mat44<T> operator-(const Mat44<T> &tLeft, const Mat44<T> &tRight)
	{
		return {tLeft.tX - tRight.tX, tLeft.tY - tRight.tY, tLeft.tZ - tRight.tZ, tLeft.tW - tRight.tW};
	}

	template<class T, class U> Mat44<T> operator*(const Mat44<T> &tMat44, U uScalar)
	{
		auto tScalar{static_cast<T>(uScalar)};

		return {tMat44.tX * tScalar, tMat44.tY * tScalar, tMat44.tZ * tScalar, tMat44.tW * tScalar};
	}

	template<class T, class U> Mat44<U> operator*(T tScalar, const Mat44<U> &uMat44)
	{
		auto uScalar{static_cast<U>(tScalar)};

		return {uScalar * uMat44.tX, uScalar * uMat44.tY, uScalar * uMat44.tZ, uScalar * uMat44.tW};
	}

	template<class T, class U> Mat44<T> operator*(const Mat44<T> &tMat44, const Vec4<U> &uVec4)
	{
		auto tVec4{static_cast<Vec4<T>>(uVec4)};

		return {tMat44.tX * tVec4, tMat44.tY * tVec4, tMat44.tZ * tVec4, tMat44.tW * tVec4};
	}

	template<class T, class U> Mat44<U> operator*(const Vec4<T> &tVec4, const Mat44<U> &uMat44)
	{
		auto uVec4{static_cast<Vec4<U>>(tVec4)};

		return {uVec4 * uMat44.tX, uVec4 * uMat44.tY, uVec4 * uMat44.tZ, uVec4 * uMat44.tW};
	}

	template<class T> Mat44<T> operator*(const Mat44<T> &tLeft, const Mat44<T> &tRight)
	{
		return {tLeft.tX * tRight.tX, tLeft.tY * tRight.tY, tLeft.tZ * tRight.tZ, tLeft.tW * tRight.tW};
	}

	template<class T, class U> Mat44<T> operator/(const Mat44<T> &tMat44, U uScalar)
	{
		auto tScalar{static_cast<T>(uScalar)};

		return {tMat44.tX / tScalar, tMat44.tY / tScalar, tMat44.tZ / tScalar, tMat44.tW / tScalar};
	}

	template<class T, class U> Mat44<U> operator/(T tScalar, const Mat44<U> &uMat44)
	{
		auto uScalar{static_cast<U>(tScalar)};

		return {uScalar / uMat44.tX, uScalar / uMat44.tY, uScalar / uMat44.tZ, uScalar / uMat44.tW};
	}

	template<class T, class U> Mat44<T> operator/(const Mat44<T> &tMat44, const Vec4<U> &uVec4)
	{
		auto tVec4{static_cast<Vec4<T>>(uVec4)};

		return {tMat44.tX / tVec4, tMat44.tY / tVec4, tMat44.tZ / tVec4, tMat44.tW / tVec4};
	}

	template<class T, class U> Mat44<U> operator/(const Vec4<T> &tVec4, const Mat44<U> &uMat44)
	{
		auto uVec4{static_cast<Vec4<U>>(tVec4)};

		return {uVec4 / uMat44.tX, uVec4 / uMat44.tY, uVec4 / uMat44.tZ, uVec4 / uMat44.tW};
	}

	template<class T> Mat44<T> operator/(const Mat44<T> &tLeft, const Mat44<T> &tRight)
	{
		return {tLeft.tX / tRight.tX, tLeft.tY / tRight.tY, tLeft.tZ / tRight.tZ, tLeft.tW / tRight.tW};
	}

	template<class T, class U> Vec4<T> operator%(const Mat44<T> &tMat44, const Vec4<U> &uVec4)
	{
		auto tVec4{static_cast<Vec4<T>>(uVec4)};

		return
		{
			Vec4<T>::dot(tMat44.tX, tVec4),
			Vec4<T>::dot(tMat44.tY, tVec4),
			Vec4<T>::dot(tMat44.tZ, tVec4),
			Vec4<T>::dot(tMat44.tW, tVec4)
		};
	}

	template<class T, class U> Vec4<U> operator%(const Vec4<T> &tVec4, const Mat44<U> &uMat44)
	{
		auto uVec4{static_cast<Vec4<U>>(tVec4)};

		return
		{
			uVec4.tX * uMat44.tX.tX + uVec4.tY * uMat44.tY.tX + uVec4.tZ * uMat44.tZ.tX + uVec4.tZ * uMat44.tW.tX,
			uVec4.tX * uMat44.tX.tY + uVec4.tY * uMat44.tY.tY + uVec4.tZ * uMat44.tZ.tY + uVec4.tZ * uMat44.tW.tY,
			uVec4.tX * uMat44.tX.tZ + uVec4.tY * uMat44.tY.tZ + uVec4.tZ * uMat44.tZ.tZ + uVec4.tZ * uMat44.tW.tZ,
			uVec4.tX * uMat44.tX.tW + uVec4.tY * uMat44.tY.tW + uVec4.tZ * uMat44.tZ.tW + uVec4.tZ * uMat44.tW.tW
		};
	}
}