
/*
	2019.06.08
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_ONYX_TRANSFORM_MAT32_HPP

#define _CLASS_ONYX_TRANSFORM_MAT32_HPP

namespace Onyx::Transform
{
	template<class T> Mat32<T>::Mat32() :
		tX{Vec2<T>::zero()},
		tY{Vec2<T>::zero()},
		tZ{Vec2<T>::zero()}
	{
		//Empty.
	}

	template<class T> Mat32<T>::Mat32(Vec2<T> tX, Vec2<T> tY, Vec2<T> tZ) :
		tX{tX},
		tY{tY},
		tZ{tZ}
	{
		//Empty.
	}

	template<class T> Mat32<T>::Mat32(T tXX, T tXY, T tYX, T tYY, T tZX, T tZY) :
		tX{tXX, tXY},
		tY{tYX, tYY},
		tZ{tZX, tZY}
	{
		//Empty.
	}

	template<class T> Vec2<T> &Mat32<T>::operator[](std::size_t nIndex)
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

	template<class T> const Vec2<T> &Mat32<T>::operator[](std::size_t nIndex) const
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

	template<class T> Mat32<T> Mat32<T>::operator+() const
	{
		return *this;
	}

	template<class T> Mat32<T> Mat32<T>::operator-() const
	{
		return {-this->tX, -this->tY, -this->tZ};
	}

	template<class T> Mat32<T> &Mat32<T>::operator++()
	{
		++this->tX;
		++this->tY;
		++this->tZ;

		return *this;
	}

	template<class T> Mat32<T> Mat32<T>::operator++(int)
	{
		auto tResult{*this};

		++this->tX;
		++this->tY;
		++this->tZ;

		return tResult;
	}

	template<class T> Mat32<T> &Mat32<T>::operator--()
	{
		--this->tX;
		--this->tY;
		--this->tZ;

		return *this;
	}

	template<class T> Mat32<T> Mat32<T>::operator--(int)
	{
		auto tResult{*this};

		--this->tX;
		--this->tY;
		--this->tZ;

		return tResult;
	}

	template<class T> template<class U> Mat32<T> &Mat32<T>::operator+=(U uScalar)
	{
		auto tScalar{static_cast<T>(uScalar)};

		this->tX += tScalar;
		this->tY += tScalar;
		this->tZ += tScalar;

		return *this;
	}

	template<class T> template<class U> Mat32<T> &Mat32<T>::operator+=(const Vec2<U> &uVec2)
	{
		auto tVec2{static_cast<Vec2<T>>(uVec2)};

		this->tX += tVec2;
		this->tY += tVec2;
		this->tZ += tVec2;

		return *this;
	}

	template<class T> template<class U> Mat32<T> &Mat32<T>::operator+=(const Mat32<U> &uMat32)
	{
		this->tX += uMat32.tX;
		this->tY += uMat32.tY;
		this->tZ += uMat32.tZ;

		return *this;
	}

	template<class T> template<class U> Mat32<T> &Mat32<T>::operator-=(U uScalar)
	{
		auto tScalar{static_cast<T>(uScalar)};

		this->tX -= tScalar;
		this->tY -= tScalar;
		this->tZ -= tScalar;

		return *this;
	}

	template<class T> template<class U> Mat32<T> &Mat32<T>::operator-=(const Vec2<U> &uVec2)
	{
		auto tVec2{static_cast<Vec2<T>>(uVec2)};

		this->tX -= tVec2;
		this->tY -= tVec2;
		this->tZ -= tVec2;

		return *this;
	}

	template<class T> template<class U> Mat32<T> &Mat32<T>::operator-=(const Mat32<U> &uMat32)
	{
		this->tX -= uMat32.tX;
		this->tY -= uMat32.tY;
		this->tZ -= uMat32.tZ;

		return *this;
	}

	template<class T> template<class U> Mat32<T> &Mat32<T>::operator*=(U uScalar)
	{
		auto tScalar{static_cast<T>(uScalar)};

		this->tX *= tScalar;
		this->tY *= tScalar;
		this->tZ *= tScalar;

		return *this;
	}

	template<class T> template<class U> Mat32<T> &Mat32<T>::operator*=(const Vec2<U> &uVec2)
	{
		auto tVec2{static_cast<Vec2<T>>(uVec2)};

		this->tX *= tVec2;
		this->tY *= tVec2;
		this->tZ *= tVec2;

		return *this;
	}

	template<class T> template<class U> Mat32<T> &Mat32<T>::operator*=(const Mat32<U> &uMat32)
	{
		this->tX *= uMat32.tX;
		this->tY *= uMat32.tY;
		this->tZ *= uMat32.tZ;

		return *this;
	}

	template<class T> template<class U> Mat32<T> &Mat32<T>::operator/=(U uScalar)
	{
		auto tScalar{static_cast<T>(uScalar)};

		this->tX /= tScalar;
		this->tY /= tScalar;
		this->tZ /= tScalar;

		return *this;
	}

	template<class T> template<class U> Mat32<T> &Mat32<T>::operator/=(const Vec2<U> &uVec2)
	{
		auto tVec2{static_cast<Vec2<T>>(uVec2)};

		this->tX /= tVec2;
		this->tY /= tVec2;
		this->tZ /= tVec2;

		return *this;
	}

	template<class T> template<class U> Mat32<T> &Mat32<T>::operator/=(const Mat32<U> &uMat32)
	{
		this->tX /= uMat32.tX;
		this->tY /= uMat32.tY;
		this->tZ /= uMat32.tZ;

		return *this;
	}

	template<class T> template<class U> bool Mat32<T>::operator==(U uScalar) const
	{
		auto tScalar{static_cast<T>(uScalar)};

		return
			this->tX == tScalar &&
			this->tY == tScalar &&
			this->tZ == tScalar;
	}

	template<class T> template<class U> bool Mat32<T>::operator==(const Vec2<U> &uVec2) const
	{
		auto tVec2{static_cast<Vec2<T>>(uVec2)};

		return
			this->tX == tVec2 &&
			this->tY == tVec2 &&
			this->tZ == tVec2;
	}

	template<class T> template<class U> bool Mat32<T>::operator==(const Mat32<U> &uMat32) const
	{
		return
			this->tX == uMat32.tX &&
			this->tY == uMat32.tY &&
			this->tZ == uMat32.tZ;
	}

	template<class T> template<class U> bool Mat32<T>::operator!=(U uScalar) const
	{
		auto tScalar{static_cast<T>(uScalar)};

		return
			this->tX != tScalar ||
			this->tY != tScalar ||
			this->tZ != tScalar;
	}

	template<class T> template<class U> bool Mat32<T>::operator!=(const Vec2<U> &uVec2) const
	{
		auto tVec2{static_cast<Vec2<T>>(uVec2)};

		return
			this->tX != tVec2 ||
			this->tY != tVec2 ||
			this->tZ != tVec2;
	}

	template<class T> template<class U> bool Mat32<T>::operator!=(const Mat32<U> &uMat32) const
	{
		return
			this->tX != uMat32.tX ||
			this->tY != uMat32.tY ||
			this->tZ != uMat32.tZ;
	}

	template<class T> template<class U> Mat32<T>::operator Mat32<U>() const
	{
		return {static_cast<Vec2<U>>(this->tX), static_cast<Vec2<U>>(this->tY), static_cast<Vec2<U>>(this->tZ)};
	}

	template<class T> Mat23<T> Mat32<T>::transposed() const
	{
		return
		{
			{this->tX.tX, this->tY.tX, this->tZ.tX},
			{this->tX.tY, this->tY.tY, this->tZ.tY}
		};
	}

	template<class T> Mat32<T> Mat32<T>::zero()
	{
		return {Vec2<T>::zero(), Vec2<T>::zero(), Vec2<T>::zero()};
	}

	template<class T> Mat32<T> Mat32<T>::one()
	{
		return {Vec2<T>::one(), Vec2<T>::one(), Vec2<T>::one()};
	}

	template<class T, class U> Mat32<T> operator+(const Mat32<T> &tMat32, U uScalar)
	{
		auto tScalar{static_cast<T>(uScalar)};

		return {tMat32.tX + tScalar, tMat32.tY + tScalar, tMat32.tZ + tScalar};
	}

	template<class T, class U> Mat32<U> operator+(T tScalar, const Mat32<U> &uMat32)
	{
		auto uScalar{static_cast<U>(tScalar)};

		return {uScalar + uMat32.tX, uScalar + uMat32.tY, uScalar + uMat32.tZ};
	}

	template<class T, class U> Mat32<T> operator+(const Mat32<T> &tMat32, const Vec2<U> &uVec2)
	{
		auto tVec2{static_cast<Vec2<T>>(uVec2)};

		return {tMat32.tX + tVec2, tMat32.tY + tVec2, tMat32.tZ + tVec2};
	}

	template<class T, class U> Mat32<U> operator+(const Vec2<T> &tVec2, const Mat32<U> &uMat32)
	{
		auto uVec2{static_cast<Vec2<U>>(tVec2)};

		return {uVec2 + uMat32.tX, uVec2 + uMat32.tY, uVec2 + uMat32.tZ};
	}

	template<class T> Mat32<T> operator+(const Mat32<T> &tLeft, const Mat32<T> &tRight)
	{
		return {tLeft.tX + tRight.tX, tLeft.tY + tRight.tY, tLeft.tZ + tRight.tZ};
	}

	template<class T, class U> Mat32<T> operator-(const Mat32<T> &tMat32, U uScalar)
	{
		auto tScalar{static_cast<T>(uScalar)};

		return {tMat32.tX - tScalar, tMat32.tY - tScalar, tMat32.tZ - tScalar};
	}

	template<class T, class U> Mat32<U> operator-(T tScalar, const Mat32<U> &uMat32)
	{
		auto uScalar{static_cast<U>(tScalar)};

		return {uScalar - uMat32.tX, uScalar - uMat32.tY, uScalar - uMat32.tZ};
	}

	template<class T, class U> Mat32<T> operator-(const Mat32<T> &tMat32, const Vec2<U> &uVec2)
	{
		auto tVec2{static_cast<Vec2<T>>(uVec2)};

		return {tMat32.tX - tVec2, tMat32.tY - tVec2, tMat32.tZ - tVec2};
	}

	template<class T, class U> Mat32<U> operator-(const Vec2<T> &tVec2, const Mat32<U> &uMat32)
	{
		auto uVec2{static_cast<Vec2<U>>(tVec2)};

		return {uVec2 - uMat32.tX, uVec2 - uMat32.tY, uVec2 - uMat32.tZ};
	}

	template<class T> Mat32<T> operator-(const Mat32<T> &tLeft, const Mat32<T> &tRight)
	{
		return {tLeft.tX - tRight.tX, tLeft.tY - tRight.tY, tLeft.tZ - tRight.tZ};
	}

	template<class T, class U> Mat32<T> operator*(const Mat32<T> &tMat32, U uScalar)
	{
		auto tScalar{static_cast<T>(uScalar)};

		return {tMat32.tX * tScalar, tMat32.tY * tScalar, tMat32.tZ * tScalar};
	}

	template<class T, class U> Mat32<U> operator*(T tScalar, const Mat32<U> &uMat32)
	{
		auto uScalar{static_cast<U>(tScalar)};

		return {uScalar * uMat32.tX, uScalar * uMat32.tY, uScalar * uMat32.tZ};
	}

	template<class T, class U> Mat32<T> operator*(const Mat32<T> &tMat32, const Vec2<U> &uVec2)
	{
		auto tVec2{static_cast<Vec2<T>>(uVec2)};

		return {tMat32.tX * tVec2, tMat32.tY * tVec2, tMat32.tZ * tVec2};
	}

	template<class T, class U> Mat32<U> operator*(const Vec2<T> &tVec2, const Mat32<U> &uMat32)
	{
		auto uVec2{static_cast<Vec2<U>>(tVec2)};

		return {uVec2 * uMat32.tX, uVec2 * uMat32.tY, uVec2 * uMat32.tZ};
	}

	template<class T> Mat32<T> operator*(const Mat32<T> &tLeft, const Mat32<T> &tRight)
	{
		return {tLeft.tX * tRight.tX, tLeft.tY * tRight.tY, tLeft.tZ * tRight.tZ};
	}

	template<class T, class U> Mat32<T> operator/(const Mat32<T> &tMat32, U uScalar)
	{
		auto tScalar{static_cast<T>(uScalar)};

		return {tMat32.tX / tScalar, tMat32.tY / tScalar, tMat32.tZ / tScalar};
	}

	template<class T, class U> Mat32<U> operator/(T tScalar, const Mat32<U> &uMat32)
	{
		auto uScalar{static_cast<U>(tScalar)};

		return {uScalar / uMat32.tX, uScalar / uMat32.tY, uScalar / uMat32.tZ};
	}

	template<class T, class U> Mat32<T> operator/(const Mat32<T> &tMat32, const Vec2<U> &uVec2)
	{
		auto tVec2{static_cast<Vec2<T>>(uVec2)};

		return {tMat32.tX / tVec2, tMat32.tY / tVec2, tMat32.tZ / tVec2};
	}

	template<class T, class U> Mat32<U> operator/(const Vec2<T> &tVec2, const Mat32<U> &uMat32)
	{
		auto uVec2{static_cast<Vec2<U>>(tVec2)};

		return {uVec2 / uMat32.tX, uVec2 / uMat32.tY, uVec2 / uMat32.tZ};
	}

	template<class T> Mat32<T> operator/(const Mat32<T> &tLeft, const Mat32<T> &tRight)
	{
		return {tLeft.tX / tRight.tX, tLeft.tY / tRight.tY, tLeft.tZ / tRight.tZ};
	}

	template<class T, class U> Vec3<T> operator%(const Mat32<T> &tMat32, const Vec2<U> &uVec2)
	{
		auto tVec2{static_cast<Vec2<T>>(uVec2)};

		return
		{
			Vec2<T>::dot(tMat32.tX, tVec2),
			Vec2<T>::dot(tMat32.tY, tVec2),
			Vec2<T>::dot(tMat32.tZ, tVec2)
		};
	}

	template<class T, class U> Vec2<U> operator%(const Vec3<T> &tVec3, const Mat32<U> &uMat32)
	{
		auto uVec3{static_cast<Vec3<U>>(tVec3)};

		return
		{
			uVec3.tX * uMat32.tX.tX + uVec3.tY * uMat32.tY.tX + uVec3.tZ * uMat32.tZ.tX,
			uVec3.tX * uMat32.tX.tY + uVec3.tY * uMat32.tY.tY + uVec3.tZ * uMat32.tZ.tY
		};
	}
}

#endif