
/*
	2019.06.09
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_ONYX_TRANSFORM_MAT43_HPP

#define _CLASS_ONYX_TRANSFORM_MAT43_HPP

namespace Onyx::Transform
{
	template<class T> Mat43<T>::Mat43() :
		tX{Vec3<T>::zero()},
		tY{Vec3<T>::zero()},
		tZ{Vec3<T>::zero()},
		tW{Vec3<T>::zero()}
	{
		//Empty.
	}

	template<class T> Mat43<T>::Mat43(Vec3<T> tX, Vec3<T> tY, Vec3<T> tZ, Vec3<T> tW) :
		tX{tX},
		tY{tY},
		tZ{tZ},
		tW{tW}
	{
		//Empty.
	}

	template<class T> Mat43<T>::Mat43(T tXX, T tXY, T tXZ, T tYX, T tYY, T tYZ, T tZX, T tZY, T tZZ, T tWX, T tWY, T tWZ) :
		tX{tXX, tXY, tXZ},
		tY{tYX, tYY, tYZ},
		tZ{tZX, tZY, tZZ},
		tW{tWX, tWY, tWZ}
	{
		//Empty.
	}

	template<class T> Vec3<T> &Mat43<T>::operator[](std::size_t nIndex)
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

	template<class T> const Vec3<T> &Mat43<T>::operator[](std::size_t nIndex) const
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

	template<class T> Mat43<T> Mat43<T>::operator+() const
	{
		return *this;
	}

	template<class T> Mat43<T> Mat43<T>::operator-() const
	{
		return {-this->tX, -this->tY, -this->tZ, -this->tW};
	}

	template<class T> Mat43<T> &Mat43<T>::operator++()
	{
		++this->tX;
		++this->tY;
		++this->tZ;
		++this->tW;

		return *this;
	}

	template<class T> Mat43<T> Mat43<T>::operator++(int)
	{
		auto tResult{*this};

		++this->tX;
		++this->tY;
		++this->tZ;
		++this->tW;

		return tResult;
	}

	template<class T> Mat43<T> &Mat43<T>::operator--()
	{
		--this->tX;
		--this->tY;
		--this->tZ;
		--this->tW;

		return *this;
	}

	template<class T> Mat43<T> Mat43<T>::operator--(int)
	{
		auto tResult{*this};

		--this->tX;
		--this->tY;
		--this->tZ;
		--this->tW;

		return tResult;
	}

	template<class T> template<class U> Mat43<T> &Mat43<T>::operator+=(U uScalar)
	{
		auto tScalar{static_cast<T>(uScalar)};

		this->tX += tScalar;
		this->tY += tScalar;
		this->tZ += tScalar;
		this->tW += tScalar;

		return *this;
	}

	template<class T> template<class U> Mat43<T> &Mat43<T>::operator+=(const Vec3<U> &uVec3)
	{
		auto tVec3{static_cast<Vec3<T>>(uVec3)};

		this->tX += tVec3;
		this->tY += tVec3;
		this->tZ += tVec3;
		this->tW += tVec3;

		return *this;
	}

	template<class T> template<class U> Mat43<T> &Mat43<T>::operator+=(const Mat43<U> &uMat43)
	{
		this->tX += uMat43.tX;
		this->tY += uMat43.tY;
		this->tZ += uMat43.tZ;
		this->tW += uMat43.tW;

		return *this;
	}

	template<class T> template<class U> Mat43<T> &Mat43<T>::operator-=(U uScalar)
	{
		auto tScalar{static_cast<T>(uScalar)};

		this->tX -= tScalar;
		this->tY -= tScalar;
		this->tZ -= tScalar;
		this->tW -= tScalar;

		return *this;
	}

	template<class T> template<class U> Mat43<T> &Mat43<T>::operator-=(const Vec3<U> &uVec3)
	{
		auto tVec3{static_cast<Vec3<T>>(uVec3)};

		this->tX -= tVec3;
		this->tY -= tVec3;
		this->tZ -= tVec3;
		this->tW -= tVec3;

		return *this;
	}

	template<class T> template<class U> Mat43<T> &Mat43<T>::operator-=(const Mat43<U> &uMat43)
	{
		this->tX -= uMat43.tX;
		this->tY -= uMat43.tY;
		this->tZ -= uMat43.tZ;
		this->tW -= uMat43.tW;

		return *this;
	}

	template<class T> template<class U> Mat43<T> &Mat43<T>::operator*=(U uScalar)
	{
		auto tScalar{static_cast<T>(uScalar)};

		this->tX *= tScalar;
		this->tY *= tScalar;
		this->tZ *= tScalar;
		this->tW *= tScalar;

		return *this;
	}

	template<class T> template<class U> Mat43<T> &Mat43<T>::operator*=(const Vec3<U> &uVec3)
	{
		auto tVec3{static_cast<Vec3<T>>(uVec3)};

		this->tX *= tVec3;
		this->tY *= tVec3;
		this->tZ *= tVec3;
		this->tW *= tVec3;

		return *this;
	}

	template<class T> template<class U> Mat43<T> &Mat43<T>::operator*=(const Mat43<U> &uMat43)
	{
		this->tX *= uMat43.tX;
		this->tY *= uMat43.tY;
		this->tZ *= uMat43.tZ;
		this->tW *= uMat43.tW;

		return *this;
	}

	template<class T> template<class U> Mat43<T> &Mat43<T>::operator/=(U uScalar)
	{
		auto tScalar{static_cast<T>(uScalar)};

		this->tX /= tScalar;
		this->tY /= tScalar;
		this->tZ /= tScalar;
		this->tW /= tScalar;

		return *this;
	}

	template<class T> template<class U> Mat43<T> &Mat43<T>::operator/=(const Vec3<U> &uVec3)
	{
		auto tVec3{static_cast<Vec3<T>>(uVec3)};

		this->tX /= tVec3;
		this->tY /= tVec3;
		this->tZ /= tVec3;
		this->tW /= tVec3;

		return *this;
	}

	template<class T> template<class U> Mat43<T> &Mat43<T>::operator/=(const Mat43<U> &uMat43)
	{
		this->tX /= uMat43.tX;
		this->tY /= uMat43.tY;
		this->tZ /= uMat43.tZ;
		this->tW /= uMat43.tW;

		return *this;
	}

	template<class T> template<class U> bool Mat43<T>::operator==(U uScalar) const
	{
		auto tScalar{static_cast<T>(uScalar)};

		return
			this->tX == tScalar &&
			this->tY == tScalar &&
			this->tZ == tScalar &&
			this->tW == tScalar;
	}

	template<class T> template<class U> bool Mat43<T>::operator==(const Vec3<U> &uVec3) const
	{
		auto tVec3{static_cast<Vec3<T>>(uVec3)};

		return
			this->tX == tVec3 &&
			this->tY == tVec3 &&
			this->tZ == tVec3 &&
			this->tW == tVec3;
	}

	template<class T> template<class U> bool Mat43<T>::operator==(const Mat43<U> &uMat43) const
	{
		return
			this->tX == uMat43.tX &&
			this->tY == uMat43.tY &&
			this->tZ == uMat43.tZ &&
			this->tW == uMat43.tW;
	}

	template<class T> template<class U> bool Mat43<T>::operator!=(U uScalar) const
	{
		auto tScalar{static_cast<T>(uScalar)};

		return
			this->tX != tScalar ||
			this->tY != tScalar ||
			this->tZ != tScalar ||
			this->tW != tScalar;
	}

	template<class T> template<class U> bool Mat43<T>::operator!=(const Vec3<U> &uVec3) const
	{
		auto tVec3{static_cast<Vec3<T>>(uVec3)};

		return
			this->tX != tVec3 ||
			this->tY != tVec3 ||
			this->tZ != tVec3 ||
			this->tW != tVec3;
	}

	template<class T> template<class U> bool Mat43<T>::operator!=(const Mat43<U> &uMat43) const
	{
		return
			this->tX != uMat43.tX ||
			this->tY != uMat43.tY ||
			this->tZ != uMat43.tZ ||
			this->tW != uMat43.tW;
	}

	template<class T> template<class U> Mat43<T>::operator Mat43<U>() const
	{
		return {static_cast<Vec3<U>>(this->tX), static_cast<Vec3<U>>(this->tY), static_cast<Vec3<U>>(this->tZ), static_cast<Vec3<U>>(this->tW)};
	}

	template<class T> Mat34<T> Mat43<T>::transposed() const
	{
		return
		{
			{this->tX.tX, this->tY.tX, this->tZ.tX, this->tW.tX},
			{this->tX.tY, this->tY.tY, this->tZ.tY, this->tW.tY},
			{this->tX.tZ, this->tY.tZ, this->tZ.tZ, this->tW.tZ}
		};
	}

	template<class T> Mat43<T> Mat43<T>::zero()
	{
		return {Vec3<T>::zero(), Vec3<T>::zero(), Vec3<T>::zero(), Vec3<T>::zero()};
	}

	template<class T> Mat43<T> Mat43<T>::one()
	{
		return {Vec3<T>::one(), Vec3<T>::one(), Vec3<T>::one(), Vec3<T>::one()};
	}

	template<class T, class U> Mat43<T> operator+(const Mat43<T> &tMat43, U uScalar)
	{
		auto tScalar{static_cast<T>(uScalar)};

		return {tMat43.tX + tScalar, tMat43.tY + tScalar, tMat43.tZ + tScalar, tMat43.tW + tScalar};
	}

	template<class T, class U> Mat43<U> operator+(T tScalar, const Mat43<U> &uMat43)
	{
		auto uScalar{static_cast<U>(tScalar)};

		return {uScalar + uMat43.tX, uScalar + uMat43.tY, uScalar + uMat43.tZ, uScalar + uMat43.tW};
	}

	template<class T, class U> Mat43<T> operator+(const Mat43<T> &tMat43, const Vec3<U> &uVec3)
	{
		auto tVec3{static_cast<Vec3<T>>(uVec3)};

		return {tMat43.tX + tVec3, tMat43.tY + tVec3, tMat43.tZ + tVec3, tMat43.tW + tVec3};
	}

	template<class T, class U> Mat43<U> operator+(const Vec3<T> &tVec3, const Mat43<U> &uMat43)
	{
		auto uVec3{static_cast<Vec3<U>>(tVec3)};

		return {uVec3 + uMat43.tX, uVec3 + uMat43.tY, uVec3 + uMat43.tZ, uVec3 + uMat43.tW};
	}

	template<class T> Mat43<T> operator+(const Mat43<T> &tLeft, const Mat43<T> &tRight)
	{
		return {tLeft.tX + tRight.tX, tLeft.tY + tRight.tY, tLeft.tZ + tRight.tZ, tLeft.tW + tRight.tW};
	}

	template<class T, class U> Mat43<T> operator-(const Mat43<T> &tMat43, U uScalar)
	{
		auto tScalar{static_cast<T>(uScalar)};

		return {tMat43.tX - tScalar, tMat43.tY - tScalar, tMat43.tZ - tScalar, tMat43.tW - tScalar};
	}

	template<class T, class U> Mat43<U> operator-(T tScalar, const Mat43<U> &uMat43)
	{
		auto uScalar{static_cast<U>(tScalar)};

		return {uScalar - uMat43.tX, uScalar - uMat43.tY, uScalar - uMat43.tZ, uScalar - uMat43.tW};
	}

	template<class T, class U> Mat43<T> operator-(const Mat43<T> &tMat43, const Vec3<U> &uVec3)
	{
		auto tVec3{static_cast<Vec3<T>>(uVec3)};

		return {tMat43.tX - tVec3, tMat43.tY - tVec3, tMat43.tZ - tVec3, tMat43.tW - tVec3};
	}

	template<class T, class U> Mat43<U> operator-(const Vec3<T> &tVec3, const Mat43<U> &uMat43)
	{
		auto uVec3{static_cast<Vec3<U>>(tVec3)};

		return {uVec3 - uMat43.tX, uVec3 - uMat43.tY, uVec3 - uMat43.tZ, uVec3 - uMat43.tW};
	}

	template<class T> Mat43<T> operator-(const Mat43<T> &tLeft, const Mat43<T> &tRight)
	{
		return {tLeft.tX - tRight.tX, tLeft.tY - tRight.tY, tLeft.tZ - tRight.tZ, tLeft.tW - tRight.tW};
	}

	template<class T, class U> Mat43<T> operator*(const Mat43<T> &tMat43, U uScalar)
	{
		auto tScalar{static_cast<T>(uScalar)};

		return {tMat43.tX * tScalar, tMat43.tY * tScalar, tMat43.tZ * tScalar, tMat43.tW * tScalar};
	}

	template<class T, class U> Mat43<U> operator*(T tScalar, const Mat43<U> &uMat43)
	{
		auto uScalar{static_cast<U>(tScalar)};

		return {uScalar * uMat43.tX, uScalar * uMat43.tY, uScalar * uMat43.tZ, uScalar * uMat43.tW};
	}

	template<class T, class U> Mat43<T> operator*(const Mat43<T> &tMat43, const Vec3<U> &uVec3)
	{
		auto tVec3{static_cast<Vec3<T>>(uVec3)};

		return {tMat43.tX * tVec3, tMat43.tY * tVec3, tMat43.tZ * tVec3, tMat43.tW * tVec3};
	}

	template<class T, class U> Mat43<U> operator*(const Vec3<T> &tVec3, const Mat43<U> &uMat43)
	{
		auto uVec3{static_cast<Vec3<U>>(tVec3)};

		return {uVec3 * uMat43.tX, uVec3 * uMat43.tY, uVec3 * uMat43.tZ, uVec3 * uMat43.tW};
	}

	template<class T> Mat43<T> operator*(const Mat43<T> &tLeft, const Mat43<T> &tRight)
	{
		return {tLeft.tX * tRight.tX, tLeft.tY * tRight.tY, tLeft.tZ * tRight.tZ, tLeft.tW * tRight.tW};
	}

	template<class T, class U> Mat43<T> operator/(const Mat43<T> &tMat43, U uScalar)
	{
		auto tScalar{static_cast<T>(uScalar)};

		return {tMat43.tX / tScalar, tMat43.tY / tScalar, tMat43.tZ / tScalar, tMat43.tW / tScalar};
	}

	template<class T, class U> Mat43<U> operator/(T tScalar, const Mat43<U> &uMat43)
	{
		auto uScalar{static_cast<U>(tScalar)};

		return {uScalar / uMat43.tX, uScalar / uMat43.tY, uScalar / uMat43.tZ, uScalar / uMat43.tW};
	}

	template<class T, class U> Mat43<T> operator/(const Mat43<T> &tMat43, const Vec3<U> &uVec3)
	{
		auto tVec3{static_cast<Vec3<T>>(uVec3)};

		return {tMat43.tX / tVec3, tMat43.tY / tVec3, tMat43.tZ / tVec3, tMat43.tW / tVec3};
	}

	template<class T, class U> Mat43<U> operator/(const Vec3<T> &tVec3, const Mat43<U> &uMat43)
	{
		auto uVec3{static_cast<Vec3<U>>(tVec3)};

		return {uVec3 / uMat43.tX, uVec3 / uMat43.tY, uVec3 / uMat43.tZ, uVec3 / uMat43.tW};
	}

	template<class T> Mat43<T> operator/(const Mat43<T> &tLeft, const Mat43<T> &tRight)
	{
		return {tLeft.tX / tRight.tX, tLeft.tY / tRight.tY, tLeft.tZ / tRight.tZ, tLeft.tW / tRight.tW};
	}

	template<class T, class U> Vec4<T> operator%(const Mat43<T> &tMat43, const Vec3<U> &uVec3)
	{
		auto tVec3{static_cast<Vec3<T>>(uVec3)};

		return
		{
			Vec3<T>::dot(tMat43.tX, tVec3),
			Vec3<T>::dot(tMat43.tY, tVec3),
			Vec3<T>::dot(tMat43.tZ, tVec3),
			Vec3<T>::dot(tMat43.tW, tVec3)
		};
	}

	template<class T, class U> Vec3<U> operator%(const Vec4<T> &tVec4, const Mat43<U> &uMat43)
	{
		auto uVec4{static_cast<Vec4<U>>(tVec4)};

		return
		{
			uVec4.tX * uMat43.tX.tX + uVec4.tY * uMat43.tY.tX + uVec4.tZ * uMat43.tZ.tX + uVec4.tZ * uMat43.tW.tX,
			uVec4.tX * uMat43.tX.tY + uVec4.tY * uMat43.tY.tY + uVec4.tZ * uMat43.tZ.tY + uVec4.tZ * uMat43.tW.tY,
			uVec4.tX * uMat43.tX.tZ + uVec4.tY * uMat43.tY.tZ + uVec4.tZ * uMat43.tZ.tZ + uVec4.tZ * uMat43.tW.tZ
		};
	}
}

#endif