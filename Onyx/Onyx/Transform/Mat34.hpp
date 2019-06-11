
/*
	2019.06.08
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_ONYX_TRANSFORM_MAT34_HPP

#define _CLASS_ONYX_TRANSFORM_MAT34_HPP

namespace Onyx::Transform
{
	template<class T> Mat34<T>::Mat34() :
		tX{Vec4<T>::zero()},
		tY{Vec4<T>::zero()},
		tZ{Vec4<T>::zero()}
	{
		//Empty.
	}

	template<class T> Mat34<T>::Mat34(Vec4<T> tX, Vec4<T> tY, Vec4<T> tZ) :
		tX{tX},
		tY{tY},
		tZ{tZ}
	{
		//Empty.
	}

	template<class T> Mat34<T>::Mat34(T tXX, T tXY, T tXZ, T tXW, T tYX, T tYY, T tYZ, T tYW, T tZX, T tZY, T tZZ, T tZW) :
		tX{tXX, tXY, tXZ, tXW},
		tY{tYX, tYY, tYZ, tYW},
		tZ{tZX, tZY, tZZ, tZW}
	{
		//Empty.
	}

	template<class T> Vec4<T> &Mat34<T>::operator[](std::size_t nIndex)
	{
		switch (nIndex)
		{
		case 0:
			return this->tX;

		case 1:
			return this->tY;

		default:
			return this->tZ;
		}
	}

	template<class T> const Vec4<T> &Mat34<T>::operator[](std::size_t nIndex) const
	{
		switch (nIndex)
		{
		case 0:
			return this->tX;

		case 1:
			return this->tY;

		default:
			return this->tZ;
		}
	}

	template<class T> Mat34<T> Mat34<T>::operator+() const
	{
		return *this;
	}

	template<class T> Mat34<T> Mat34<T>::operator-() const
	{
		return {-this->tX, -this->tY, -this->tZ};
	}

	template<class T> Mat34<T> &Mat34<T>::operator++()
	{
		++this->tX;
		++this->tY;
		++this->tZ;

		return *this;
	}

	template<class T> Mat34<T> Mat34<T>::operator++(int)
	{
		auto tResult{*this};

		++this->tX;
		++this->tY;
		++this->tZ;

		return tResult;
	}

	template<class T> Mat34<T> &Mat34<T>::operator--()
	{
		--this->tX;
		--this->tY;
		--this->tZ;

		return *this;
	}

	template<class T> Mat34<T> Mat34<T>::operator--(int)
	{
		auto tResult{*this};

		--this->tX;
		--this->tY;
		--this->tZ;

		return tResult;
	}

	template<class T> template<class U> Mat34<T> &Mat34<T>::operator+=(U uScalar)
	{
		auto tScalar{static_cast<T>(uScalar)};

		this->tX += tScalar;
		this->tY += tScalar;
		this->tZ += tScalar;

		return *this;
	}

	template<class T> template<class U> Mat34<T> &Mat34<T>::operator+=(const Vec4<U> &uVec3)
	{
		auto tVec3{static_cast<Vec4<T>>(uVec3)};

		this->tX += tVec3;
		this->tY += tVec3;
		this->tZ += tVec3;

		return *this;
	}

	template<class T> template<class U> Mat34<T> &Mat34<T>::operator+=(const Mat34<U> &uMat34)
	{
		this->tX += uMat34.tX;
		this->tY += uMat34.tY;
		this->tZ += uMat34.tZ;

		return *this;
	}

	template<class T> template<class U> Mat34<T> &Mat34<T>::operator-=(U uScalar)
	{
		auto tScalar{static_cast<T>(uScalar)};

		this->tX -= tScalar;
		this->tY -= tScalar;
		this->tZ -= tScalar;

		return *this;
	}

	template<class T> template<class U> Mat34<T> &Mat34<T>::operator-=(const Vec4<U> &uVec3)
	{
		auto tVec3{static_cast<Vec4<T>>(uVec3)};

		this->tX -= tVec3;
		this->tY -= tVec3;
		this->tZ -= tVec3;

		return *this;
	}

	template<class T> template<class U> Mat34<T> &Mat34<T>::operator-=(const Mat34<U> &uMat34)
	{
		this->tX -= uMat34.tX;
		this->tY -= uMat34.tY;
		this->tZ -= uMat34.tZ;

		return *this;
	}

	template<class T> template<class U> Mat34<T> &Mat34<T>::operator*=(U uScalar)
	{
		auto tScalar{static_cast<T>(uScalar)};

		this->tX *= tScalar;
		this->tY *= tScalar;
		this->tZ *= tScalar;

		return *this;
	}

	template<class T> template<class U> Mat34<T> &Mat34<T>::operator*=(const Vec4<U> &uVec3)
	{
		auto tVec3{static_cast<Vec4<T>>(uVec3)};

		this->tX *= tVec3;
		this->tY *= tVec3;
		this->tZ *= tVec3;

		return *this;
	}

	template<class T> template<class U> Mat34<T> &Mat34<T>::operator*=(const Mat34<U> &uMat34)
	{
		this->tX *= uMat34.tX;
		this->tY *= uMat34.tY;
		this->tZ *= uMat34.tZ;

		return *this;
	}

	template<class T> template<class U> Mat34<T> &Mat34<T>::operator/=(U uScalar)
	{
		auto tScalar{static_cast<T>(uScalar)};

		this->tX /= tScalar;
		this->tY /= tScalar;
		this->tZ /= tScalar;

		return *this;
	}

	template<class T> template<class U> Mat34<T> &Mat34<T>::operator/=(const Vec4<U> &uVec3)
	{
		auto tVec3{static_cast<Vec4<T>>(uVec3)};

		this->tX /= tVec3;
		this->tY /= tVec3;
		this->tZ /= tVec3;

		return *this;
	}

	template<class T> template<class U> Mat34<T> &Mat34<T>::operator/=(const Mat34<U> &uMat34)
	{
		this->tX /= uMat34.tX;
		this->tY /= uMat34.tY;
		this->tZ /= uMat34.tZ;

		return *this;
	}

	template<class T> template<class U> bool Mat34<T>::operator==(U uScalar) const
	{
		auto tScalar{static_cast<T>(uScalar)};

		return
			this->tX == tScalar &&
			this->tY == tScalar &&
			this->tZ == tScalar;
	}

	template<class T> template<class U> bool Mat34<T>::operator==(const Vec4<U> &uVec3) const
	{
		auto tVec3{static_cast<Vec4<T>>(uVec3)};

		return
			this->tX == tVec3 &&
			this->tY == tVec3 &&
			this->tZ == tVec3;
	}

	template<class T> template<class U> bool Mat34<T>::operator==(const Mat34<U> &uMat34) const
	{
		return
			this->tX == uMat34.tX &&
			this->tY == uMat34.tY &&
			this->tZ == uMat34.tZ;
	}

	template<class T> template<class U> bool Mat34<T>::operator!=(U uScalar) const
	{
		auto tScalar{static_cast<T>(uScalar)};

		return
			this->tX != tScalar ||
			this->tY != tScalar ||
			this->tZ != tScalar;
	}

	template<class T> template<class U> bool Mat34<T>::operator!=(const Vec4<U> &uVec3) const
	{
		auto tVec3{static_cast<Vec4<T>>(uVec3)};

		return
			this->tX != tVec3 ||
			this->tY != tVec3 ||
			this->tZ != tVec3;
	}

	template<class T> template<class U> bool Mat34<T>::operator!=(const Mat34<U> &uMat34) const
	{
		return
			this->tX != uMat34.tX ||
			this->tY != uMat34.tY ||
			this->tZ != uMat34.tZ;
	}

	template<class T> template<class U> Mat34<T>::operator Mat34<U>() const
	{
		return {static_cast<Vec4<U>>(this->tX), static_cast<Vec4<U>>(this->tY), static_cast<Vec4<U>>(this->tZ)};
	}

	template<class T> Mat43<T> Mat34<T>::transposed() const
	{
		return
		{
			{this->tX.tX, this->tY.tX, this->tZ.tX},
			{this->tX.tY, this->tY.tY, this->tZ.tY},
			{this->tX.tZ, this->tY.tZ, this->tZ.tZ},
			{this->tX.tW, this->tY.tW, this->tZ.tW}
		};
	}

	template<class T> Mat34<T> Mat34<T>::zero()
	{
		return {Vec4<T>::zero(), Vec4<T>::zero(), Vec4<T>::zero()};
	}

	template<class T> Mat34<T> Mat34<T>::one()
	{
		return {Vec4<T>::one(), Vec4<T>::one(), Vec4<T>::one()};
	}

	template<class T> Mat34<T> Mat34<T>::identity()
	{
		return
		{
			Vec4<T>{static_cast<T>(1), static_cast<T>(0), static_cast<T>(0)},
			Vec4<T>{static_cast<T>(0), static_cast<T>(1), static_cast<T>(0)},
			Vec4<T>{static_cast<T>(0), static_cast<T>(0), static_cast<T>(1)}
		};
	}

	template<class T, class U> Mat34<T> operator+(const Mat34<T> &tMat34, U uScalar)
	{
		auto tScalar{static_cast<T>(uScalar)};

		return {tMat34.tX + tScalar, tMat34.tY + tScalar, tMat34.tZ + tScalar};
	}

	template<class T, class U> Mat34<U> operator+(T tScalar, const Mat34<U> &uMat34)
	{
		auto uScalar{static_cast<U>(tScalar)};

		return {uScalar + uMat34.tX, uScalar + uMat34.tY, uScalar + uMat34.tZ};
	}

	template<class T, class U> Mat34<T> operator+(const Mat34<T> &tMat34, const Vec4<U> &uVec3)
	{
		auto tVec3{static_cast<Vec4<T>>(uVec3)};

		return {tMat34.tX + tVec3, tMat34.tY + tVec3, tMat34.tZ + tVec3};
	}

	template<class T, class U> Mat34<U> operator+(const Vec4<T> &tVec3, const Mat34<U> &uMat34)
	{
		auto uVec3{static_cast<Vec4<U>>(tVec3)};

		return {uVec3 + uMat34.tX, uVec3 + uMat34.tY, uVec3 + uMat34.tZ};
	}

	template<class T> Mat34<T> operator+(const Mat34<T> &tLeft, const Mat34<T> &tRight)
	{
		return {tLeft.tX + tRight.tX, tLeft.tY + tRight.tY, tLeft.tZ + tRight.tZ};
	}

	template<class T, class U> Mat34<T> operator-(const Mat34<T> &tMat34, U uScalar)
	{
		auto tScalar{static_cast<T>(uScalar)};

		return {tMat34.tX - tScalar, tMat34.tY - tScalar, tMat34.tZ - tScalar};
	}

	template<class T, class U> Mat34<U> operator-(T tScalar, const Mat34<U> &uMat34)
	{
		auto uScalar{static_cast<U>(tScalar)};

		return {uScalar - uMat34.tX, uScalar - uMat34.tY, uScalar - uMat34.tZ};
	}

	template<class T, class U> Mat34<T> operator-(const Mat34<T> &tMat34, const Vec4<U> &uVec3)
	{
		auto tVec3{static_cast<Vec4<T>>(uVec3)};

		return {tMat34.tX - tVec3, tMat34.tY - tVec3, tMat34.tZ - tVec3};
	}

	template<class T, class U> Mat34<U> operator-(const Vec4<T> &tVec3, const Mat34<U> &uMat34)
	{
		auto uVec3{static_cast<Vec4<U>>(tVec3)};

		return {uVec3 - uMat34.tX, uVec3 - uMat34.tY, uVec3 - uMat34.tZ};
	}

	template<class T> Mat34<T> operator-(const Mat34<T> &tLeft, const Mat34<T> &tRight)
	{
		return {tLeft.tX - tRight.tX, tLeft.tY - tRight.tY, tLeft.tZ - tRight.tZ};
	}

	template<class T, class U> Mat34<T> operator*(const Mat34<T> &tMat34, U uScalar)
	{
		auto tScalar{static_cast<T>(uScalar)};

		return {tMat34.tX * tScalar, tMat34.tY * tScalar, tMat34.tZ * tScalar};
	}

	template<class T, class U> Mat34<U> operator*(T tScalar, const Mat34<U> &uMat34)
	{
		auto uScalar{static_cast<U>(tScalar)};

		return {uScalar * uMat34.tX, uScalar * uMat34.tY, uScalar * uMat34.tZ};
	}

	template<class T, class U> Mat34<T> operator*(const Mat34<T> &tMat34, const Vec4<U> &uVec3)
	{
		auto tVec3{static_cast<Vec4<T>>(uVec3)};

		return {tMat34.tX * tVec3, tMat34.tY * tVec3, tMat34.tZ * tVec3};
	}

	template<class T, class U> Mat34<U> operator*(const Vec4<T> &tVec3, const Mat34<U> &uMat34)
	{
		auto uVec3{static_cast<Vec4<U>>(tVec3)};

		return {uVec3 * uMat34.tX, uVec3 * uMat34.tY, uVec3 * uMat34.tZ};
	}

	template<class T> Mat34<T> operator*(const Mat34<T> &tLeft, const Mat34<T> &tRight)
	{
		return {tLeft.tX * tRight.tX, tLeft.tY * tRight.tY, tLeft.tZ * tRight.tZ};
	}

	template<class T, class U> Mat34<T> operator/(const Mat34<T> &tMat34, U uScalar)
	{
		auto tScalar{static_cast<T>(uScalar)};

		return {tMat34.tX / tScalar, tMat34.tY / tScalar, tMat34.tZ / tScalar};
	}

	template<class T, class U> Mat34<U> operator/(T tScalar, const Mat34<U> &uMat34)
	{
		auto uScalar{static_cast<U>(tScalar)};

		return {uScalar / uMat34.tX, uScalar / uMat34.tY, uScalar / uMat34.tZ};
	}

	template<class T, class U> Mat34<T> operator/(const Mat34<T> &tMat34, const Vec4<U> &uVec3)
	{
		auto tVec3{static_cast<Vec4<T>>(uVec3)};

		return {tMat34.tX / tVec3, tMat34.tY / tVec3, tMat34.tZ / tVec3};
	}

	template<class T, class U> Mat34<U> operator/(const Vec4<T> &tVec3, const Mat34<U> &uMat34)
	{
		auto uVec3{static_cast<Vec4<U>>(tVec3)};

		return {uVec3 / uMat34.tX, uVec3 / uMat34.tY, uVec3 / uMat34.tZ};
	}

	template<class T> Mat34<T> operator/(const Mat34<T> &tLeft, const Mat34<T> &tRight)
	{
		return {tLeft.tX / tRight.tX, tLeft.tY / tRight.tY, tLeft.tZ / tRight.tZ};
	}

	template<class T, class U> Vec3<T> operator%(const Mat34<T> &tMat34, const Vec4<U> &uVec4)
	{
		auto tVec4{static_cast<Vec4<T>>(uVec4)};

		return
		{
			Vec4<T>::dot(tMat34.tX, tVec4),
			Vec4<T>::dot(tMat34.tY, tVec4),
			Vec4<T>::dot(tMat34.tZ, tVec4)
		};
	}

	template<class T, class U> Vec4<U> operator%(const Vec3<T> &tVec3, const Mat34<U> &uMat34)
	{
		auto uVec3{static_cast<Vec3<U>>(tVec3)};

		return
		{
			uVec3.tX * uMat34.tX.tX + uVec3.tY * uMat34.tY.tX + uVec3.tZ * uMat34.tZ.tX,
			uVec3.tX * uMat34.tX.tY + uVec3.tY * uMat34.tY.tY + uVec3.tZ * uMat34.tZ.tY,
			uVec3.tX * uMat34.tX.tZ + uVec3.tY * uMat34.tY.tZ + uVec3.tZ * uMat34.tZ.tZ,
			uVec3.tX * uMat34.tX.tW + uVec3.tY * uMat34.tY.tW + uVec3.tZ * uMat34.tZ.tW
		};
	}
}

#endif