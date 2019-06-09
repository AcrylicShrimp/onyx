
/*
	2019.06.08
	Created by AcrylicShrimp.
*/

namespace Onyx::Transform
{
	template<class T> Mat33<T>::Mat33() :
		tX{Vec3<T>::zero()},
		tY{Vec3<T>::zero()},
		tZ{Vec3<T>::zero()}
	{
		//Empty.
	}

	template<class T> Mat33<T>::Mat33(Vec3<T> tX, Vec3<T> tY, Vec3<T> tZ) :
		tX{tX},
		tY{tY},
		tZ{tZ}
	{
		//Empty.
	}

	template<class T> Mat33<T>::Mat33(T tXX, T tXY, T tXZ, T tYX, T tYY, T tYZ, T tZX, T tZY, T tZZ) :
		tX{tXX, tXY, tXZ},
		tY{tYX, tYY, tYZ},
		tZ{tZX, tZY, tZZ}
	{
		//Empty.
	}

	template<class T> Vec3<T> &Mat33<T>::operator[](std::size_t nIndex)
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

	template<class T> const Vec3<T> &Mat33<T>::operator[](std::size_t nIndex) const
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

	template<class T> Mat33<T> Mat33<T>::operator+() const
	{
		return *this;
	}

	template<class T> Mat33<T> Mat33<T>::operator-() const
	{
		return {-this->tX, -this->tY, -this->tZ};
	}

	template<class T> Mat33<T> &Mat33<T>::operator++()
	{
		++this->tX;
		++this->tY;
		++this->tZ;

		return *this;
	}

	template<class T> Mat33<T> Mat33<T>::operator++(int)
	{
		auto tResult{*this};

		++this->tX;
		++this->tY;
		++this->tZ;

		return tResult;
	}

	template<class T> Mat33<T> &Mat33<T>::operator--()
	{
		--this->tX;
		--this->tY;
		--this->tZ;

		return *this;
	}

	template<class T> Mat33<T> Mat33<T>::operator--(int)
	{
		auto tResult{*this};

		--this->tX;
		--this->tY;
		--this->tZ;

		return tResult;
	}

	template<class T> template<class U> Mat33<T> &Mat33<T>::operator+=(U uScalar)
	{
		auto tScalar{static_cast<T>(uScalar)};

		this->tX += tScalar;
		this->tY += tScalar;
		this->tZ += tScalar;

		return *this;
	}

	template<class T> template<class U> Mat33<T> &Mat33<T>::operator+=(const Vec3<U> &uVec3)
	{
		auto tVec3{static_cast<Vec3<T>>(uVec3)};

		this->tX += tVec3;
		this->tY += tVec3;
		this->tZ += tVec3;

		return *this;
	}

	template<class T> template<class U> Mat33<T> &Mat33<T>::operator+=(const Mat33<U> &uMat33)
	{
		this->tX += uMat33.tX;
		this->tY += uMat33.tY;
		this->tZ += uMat33.tZ;

		return *this;
	}

	template<class T> template<class U> Mat33<T> &Mat33<T>::operator-=(U uScalar)
	{
		auto tScalar{static_cast<T>(uScalar)};

		this->tX -= tScalar;
		this->tY -= tScalar;
		this->tZ -= tScalar;

		return *this;
	}

	template<class T> template<class U> Mat33<T> &Mat33<T>::operator-=(const Vec3<U> &uVec3)
	{
		auto tVec3{static_cast<Vec3<T>>(uVec3)};

		this->tX -= tVec3;
		this->tY -= tVec3;
		this->tZ -= tVec3;

		return *this;
	}

	template<class T> template<class U> Mat33<T> &Mat33<T>::operator-=(const Mat33<U> &uMat33)
	{
		this->tX -= uMat33.tX;
		this->tY -= uMat33.tY;
		this->tZ -= uMat33.tZ;

		return *this;
	}

	template<class T> template<class U> Mat33<T> &Mat33<T>::operator*=(U uScalar)
	{
		auto tScalar{static_cast<T>(uScalar)};

		this->tX *= tScalar;
		this->tY *= tScalar;
		this->tZ *= tScalar;

		return *this;
	}

	template<class T> template<class U> Mat33<T> &Mat33<T>::operator*=(const Vec3<U> &uVec3)
	{
		auto tVec3{static_cast<Vec3<T>>(uVec3)};

		this->tX *= tVec3;
		this->tY *= tVec3;
		this->tZ *= tVec3;

		return *this;
	}

	template<class T> template<class U> Mat33<T> &Mat33<T>::operator*=(const Mat33<U> &uMat33)
	{
		this->tX *= uMat33.tX;
		this->tY *= uMat33.tY;
		this->tZ *= uMat33.tZ;

		return *this;
	}

	template<class T> template<class U> Mat33<T> &Mat33<T>::operator/=(U uScalar)
	{
		auto tScalar{static_cast<T>(uScalar)};

		this->tX /= tScalar;
		this->tY /= tScalar;
		this->tZ /= tScalar;

		return *this;
	}

	template<class T> template<class U> Mat33<T> &Mat33<T>::operator/=(const Vec3<U> &uVec3)
	{
		auto tVec3{static_cast<Vec3<T>>(uVec3)};

		this->tX /= tVec3;
		this->tY /= tVec3;
		this->tZ /= tVec3;

		return *this;
	}

	template<class T> template<class U> Mat33<T> &Mat33<T>::operator/=(const Mat33<U> &uMat33)
	{
		this->tX /= uMat33.tX;
		this->tY /= uMat33.tY;
		this->tZ /= uMat33.tZ;

		return *this;
	}

	template<class T> template<class U> bool Mat33<T>::operator==(U uScalar) const
	{
		auto tScalar{static_cast<T>(uScalar)};

		return
			this->tX == tScalar &&
			this->tY == tScalar &&
			this->tZ == tScalar;
	}

	template<class T> template<class U> bool Mat33<T>::operator==(const Vec3<U> &uVec3) const
	{
		auto tVec3{static_cast<Vec3<T>>(uVec3)};

		return
			this->tX == tVec3 &&
			this->tY == tVec3 &&
			this->tZ == tVec3;
	}

	template<class T> template<class U> bool Mat33<T>::operator==(const Mat33<U> &uMat33) const
	{
		return
			this->tX == uMat33.tX &&
			this->tY == uMat33.tY &&
			this->tZ == uMat33.tZ;
	}

	template<class T> template<class U> bool Mat33<T>::operator!=(U uScalar) const
	{
		auto tScalar{static_cast<T>(uScalar)};

		return
			this->tX != tScalar ||
			this->tY != tScalar ||
			this->tZ != tScalar;
	}

	template<class T> template<class U> bool Mat33<T>::operator!=(const Vec3<U> &uVec3) const
	{
		auto tVec3{static_cast<Vec3<T>>(uVec3)};

		return
			this->tX != tVec3 ||
			this->tY != tVec3 ||
			this->tZ != tVec3;
	}

	template<class T> template<class U> bool Mat33<T>::operator!=(const Mat33<U> &uMat33) const
	{
		return
			this->tX != uMat33.tX ||
			this->tY != uMat33.tY ||
			this->tZ != uMat33.tZ;
	}

	template<class T> template<class U> Mat33<T>::operator Mat33<U>() const
	{
		return {static_cast<Vec3<U>>(this->tX), static_cast<Vec3<U>>(this->tY), static_cast<Vec3<U>>(this->tZ)};
	}

	template<class T> Mat33<T> Mat33<T>::transposed() const
	{
		return
		{
			{this->tX.tX, this->tY.tX, this->tZ.tX},
			{this->tX.tY, this->tY.tY, this->tZ.tY},
			{this->tX.tZ, this->tY.tZ, this->tZ.tZ}
		};
	}

	template<class T> Mat33<T> Mat33<T>::zero()
	{
		return {Vec3<T>::zero(), Vec3<T>::zero(), Vec3<T>::zero()};
	}

	template<class T> Mat33<T> Mat33<T>::one()
	{
		return {Vec3<T>::one(), Vec3<T>::one(), Vec3<T>::one()};
	}

	template<class T> Mat33<T> Mat33<T>::identity()
	{
		return
		{
			Vec3<T>{static_cast<T>(1), static_cast<T>(0), static_cast<T>(0)},
			Vec3<T>{static_cast<T>(0), static_cast<T>(1), static_cast<T>(0)},
			Vec3<T>{static_cast<T>(0), static_cast<T>(0), static_cast<T>(1)}
		};
	}

	template<class T, class U> Mat33<T> operator+(const Mat33<T> &tMat33, U uScalar)
	{
		auto tScalar{static_cast<T>(uScalar)};

		return {tMat33.tX + tScalar, tMat33.tY + tScalar, tMat33.tZ + tScalar};
	}

	template<class T, class U> Mat33<U> operator+(T tScalar, const Mat33<U> &uMat33)
	{
		auto uScalar{static_cast<U>(tScalar)};

		return {uScalar + uMat33.tX, uScalar + uMat33.tY, uScalar + uMat33.tZ};
	}

	template<class T, class U> Mat33<T> operator+(const Mat33<T> &tMat33, const Vec3<U> &uVec3)
	{
		auto tVec3{static_cast<Vec3<T>>(uVec3)};

		return {tMat33.tX + tVec3, tMat33.tY + tVec3, tMat33.tZ + tVec3};
	}

	template<class T, class U> Mat33<U> operator+(const Vec3<T> &tVec3, const Mat33<U> &uMat33)
	{
		auto uVec3{static_cast<Vec3<U>>(tVec3)};

		return {uVec3 + uMat33.tX, uVec3 + uMat33.tY, uVec3 + uMat33.tZ};
	}

	template<class T> Mat33<T> operator+(const Mat33<T> &tLeft, const Mat33<T> &tRight)
	{
		return {tLeft.tX + tRight.tX, tLeft.tY + tRight.tY, tLeft.tZ + tRight.tZ};
	}

	template<class T, class U> Mat33<T> operator-(const Mat33<T> &tMat33, U uScalar)
	{
		auto tScalar{static_cast<T>(uScalar)};

		return {tMat33.tX - tScalar, tMat33.tY - tScalar, tMat33.tZ - tScalar};
	}

	template<class T, class U> Mat33<U> operator-(T tScalar, const Mat33<U> &uMat33)
	{
		auto uScalar{static_cast<U>(tScalar)};

		return {uScalar - uMat33.tX, uScalar - uMat33.tY, uScalar - uMat33.tZ};
	}

	template<class T, class U> Mat33<T> operator-(const Mat33<T> &tMat33, const Vec3<U> &uVec3)
	{
		auto tVec3{static_cast<Vec3<T>>(uVec3)};

		return {tMat33.tX - tVec3, tMat33.tY - tVec3, tMat33.tZ - tVec3};
	}

	template<class T, class U> Mat33<U> operator-(const Vec3<T> &tVec3, const Mat33<U> &uMat33)
	{
		auto uVec3{static_cast<Vec3<U>>(tVec3)};

		return {uVec3 - uMat33.tX, uVec3 - uMat33.tY, uVec3 - uMat33.tZ};
	}

	template<class T> Mat33<T> operator-(const Mat33<T> &tLeft, const Mat33<T> &tRight)
	{
		return {tLeft.tX - tRight.tX, tLeft.tY - tRight.tY, tLeft.tZ - tRight.tZ};
	}

	template<class T, class U> Mat33<T> operator*(const Mat33<T> &tMat33, U uScalar)
	{
		auto tScalar{static_cast<T>(uScalar)};

		return {tMat33.tX * tScalar, tMat33.tY * tScalar, tMat33.tZ * tScalar};
	}

	template<class T, class U> Mat33<U> operator*(T tScalar, const Mat33<U> &uMat33)
	{
		auto uScalar{static_cast<U>(tScalar)};

		return {uScalar * uMat33.tX, uScalar * uMat33.tY, uScalar * uMat33.tZ};
	}

	template<class T, class U> Mat33<T> operator*(const Mat33<T> &tMat33, const Vec3<U> &uVec3)
	{
		auto tVec3{static_cast<Vec3<T>>(uVec3)};

		return {tMat33.tX * tVec3, tMat33.tY * tVec3, tMat33.tZ * tVec3};
	}

	template<class T, class U> Mat33<U> operator*(const Vec3<T> &tVec3, const Mat33<U> &uMat33)
	{
		auto uVec3{static_cast<Vec3<U>>(tVec3)};

		return {uVec3 * uMat33.tX, uVec3 * uMat33.tY, uVec3 * uMat33.tZ};
	}

	template<class T> Mat33<T> operator*(const Mat33<T> &tLeft, const Mat33<T> &tRight)
	{
		return {tLeft.tX * tRight.tX, tLeft.tY * tRight.tY, tLeft.tZ * tRight.tZ};
	}

	template<class T, class U> Mat33<T> operator/(const Mat33<T> &tMat33, U uScalar)
	{
		auto tScalar{static_cast<T>(uScalar)};

		return {tMat33.tX / tScalar, tMat33.tY / tScalar, tMat33.tZ / tScalar};
	}

	template<class T, class U> Mat33<U> operator/(T tScalar, const Mat33<U> &uMat33)
	{
		auto uScalar{static_cast<U>(tScalar)};

		return {uScalar / uMat33.tX, uScalar / uMat33.tY, uScalar / uMat33.tZ};
	}

	template<class T, class U> Mat33<T> operator/(const Mat33<T> &tMat33, const Vec3<U> &uVec3)
	{
		auto tVec3{static_cast<Vec3<T>>(uVec3)};

		return {tMat33.tX / tVec3, tMat33.tY / tVec3, tMat33.tZ / tVec3};
	}

	template<class T, class U> Mat33<U> operator/(const Vec3<T> &tVec3, const Mat33<U> &uMat33)
	{
		auto uVec3{static_cast<Vec3<U>>(tVec3)};

		return {uVec3 / uMat33.tX, uVec3 / uMat33.tY, uVec3 / uMat33.tZ};
	}

	template<class T> Mat33<T> operator/(const Mat33<T> &tLeft, const Mat33<T> &tRight)
	{
		return {tLeft.tX / tRight.tX, tLeft.tY / tRight.tY, tLeft.tZ / tRight.tZ};
	}

	template<class T, class U> Vec3<T> operator%(const Mat33<T> &tMat33, const Vec3<U> &uVec3)
	{
		auto tVec3{static_cast<Vec3<T>>(uVec3)};

		return
		{
			Vec3<T>::dot(tMat33.tX, tVec3),
			Vec3<T>::dot(tMat33.tY, tVec3),
			Vec3<T>::dot(tMat33.tZ, tVec3)
		};
	}

	template<class T, class U> Vec3<U> operator%(const Vec3<T> &tVec3, const Mat33<U> &uMat33)
	{
		auto uVec3{static_cast<Vec3<U>>(tVec3)};

		return
		{
			uVec3.tX * uMat33.tX.tX + uVec3.tY * uMat33.tY.tX + uVec3.tZ * uMat33.tZ.tX,
			uVec3.tX * uMat33.tX.tY + uVec3.tY * uMat33.tY.tY + uVec3.tZ * uMat33.tZ.tY,
			uVec3.tX * uMat33.tX.tZ + uVec3.tY * uMat33.tY.tZ + uVec3.tZ * uMat33.tZ.tZ
		};
	}
}