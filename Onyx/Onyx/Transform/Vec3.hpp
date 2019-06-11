
/*
	2019.06.01
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_ONYX_TRANSFORM_VEC3_HPP

#define _CLASS_ONYX_TRANSFORM_VEC3_HPP

namespace Onyx::Transform
{
	template<class T> Vec3<T>::Vec3() :
		tX{static_cast<T>(0)},
		tY{static_cast<T>(0)},
		tZ{static_cast<T>(0)}
	{
		//Empty.
	}

	template<class T> Vec3<T>::Vec3(T tX, T tY, T tZ) :
		tX{tX},
		tY{tY},
		tZ{tZ}
	{
		//Empty.
	}

	template<class T> T &Vec3<T>::operator[](std::size_t nIndex)
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

	template<class T> const T &Vec3<T>::operator[](std::size_t nIndex) const
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

	template<class T> Vec3<T> Vec3<T>::operator+() const
	{
		return *this;
	}

	template<class T> Vec3<T> Vec3<T>::operator-() const
	{
		return {-this->tX, -this->tY, -this->tZ};
	}

	template<class T> Vec3<T> &Vec3<T>::operator++()
	{
		++this->tX;
		++this->tY;
		++this->tZ;

		return *this;
	}

	template<class T> Vec3<T> Vec3<T>::operator++(int)
	{
		auto tResult{*this};

		++this->tX;
		++this->tY;
		++this->tZ;

		return tResult;
	}

	template<class T> Vec3<T> &Vec3<T>::operator--()
	{
		--this->tX;
		--this->tY;
		--this->tZ;

		return *this;
	}

	template<class T> Vec3<T> Vec3<T>::operator--(int)
	{
		auto tResult{*this};

		--this->tX;
		--this->tY;
		--this->tZ;

		return tResult;
	}

	template<class T> template<class U> Vec3<T> &Vec3<T>::operator+=(U uScalar)
	{
		auto tScalar{static_cast<T>(uScalar)};

		this->tX += tScalar;
		this->tY += tScalar;
		this->tZ += tScalar;

		return *this;
	}

	template<class T> template<class U> Vec3<T> &Vec3<T>::operator+=(const Vec3<U> &uVec3)
	{
		this->tX += static_cast<T>(uVec3.tX);
		this->tY += static_cast<T>(uVec3.tY);
		this->tZ += static_cast<T>(uVec3.tZ);

		return *this;
	}

	template<class T> template<class U> Vec3<T> &Vec3<T>::operator-=(U uScalar)
	{
		auto tScalar{static_cast<T>(uScalar)};

		this->tX -= tScalar;
		this->tY -= tScalar;
		this->tZ -= tScalar;

		return *this;
	}

	template<class T> template<class U> Vec3<T> &Vec3<T>::operator-=(const Vec3<U> &uVec3)
	{
		this->tX -= static_cast<T>(uVec3.tX);
		this->tY -= static_cast<T>(uVec3.tY);
		this->tZ -= static_cast<T>(uVec3.tZ);

		return *this;
	}

	template<class T> template<class U> Vec3<T> &Vec3<T>::operator*=(U uScalar)
	{
		auto tScalar{static_cast<T>(uScalar)};

		this->tX *= tScalar;
		this->tY *= tScalar;
		this->tZ *= tScalar;

		return *this;
	}

	template<class T> template<class U> Vec3<T> &Vec3<T>::operator*=(const Vec3<U> &uVec3)
	{
		this->tX *= static_cast<T>(uVec3.tX);
		this->tY *= static_cast<T>(uVec3.tY);
		this->tZ *= static_cast<T>(uVec3.tZ);

		return *this;
	}

	template<class T> template<class U> Vec3<T> &Vec3<T>::operator/=(U uScalar)
	{
		auto tScalar{static_cast<T>(uScalar)};

		this->tX /= tScalar;
		this->tY /= tScalar;
		this->tZ /= tScalar;

		return *this;
	}

	template<class T> template<class U> Vec3<T> &Vec3<T>::operator/=(const Vec3<U> &uVec3)
	{
		this->tX /= static_cast<T>(uVec3.tX);
		this->tY /= static_cast<T>(uVec3.tY);
		this->tZ /= static_cast<T>(uVec3.tZ);

		return *this;
	}

	template<class T> template<class U> bool Vec3<T>::operator==(U uScalar) const
	{
		return
			this->tX == uScalar &&
			this->tY == uScalar &&
			this->tZ == uScalar;
	}

	template<class T> template<class U> bool Vec3<T>::operator==(const Vec3<U> &uVec3) const
	{
		return
			this->tX == uVec3.tX &&
			this->tY == uVec3.tY &&
			this->tZ == uVec3.tZ;
	}

	template<class T> template<class U> bool Vec3<T>::operator!=(U uScalar) const
	{
		return
			this->tX != uScalar ||
			this->tY != uScalar ||
			this->tZ != uScalar;
	}

	template<class T> template<class U> bool Vec3<T>::operator!=(const Vec3<U> &uVec3) const
	{
		return
			this->tX != uVec3.tX ||
			this->tY != uVec3.tY ||
			this->tZ != uVec3.tZ;
	}

	template<class T> template<class U> Vec3<T>::operator Vec3<U>() const
	{
		return {static_cast<U>(this->tX), static_cast<U>(this->tY), static_cast<U>(this->tZ)};
	}

	template<class T> T Vec3<T>::length() const
	{
		return static_cast<T>(std::sqrt(this->lengthSquare()));
	}

	template<class T> T Vec3<T>::lengthSquare() const
	{
		return this->tX * this->tX + this->tY * this->tY + this->tZ * this->tZ;
	}

	template<class T> Vec3<T> Vec3<T>::normalized() const
	{
		return (*this) / this->length();
	}

	template<class T> Vec3<T> Vec3<T>::zero()
	{
		return {static_cast<T>(0), static_cast<T>(0), static_cast<T>(0)};
	}

	template<class T> Vec3<T> Vec3<T>::one()
	{
		return {static_cast<T>(1), static_cast<T>(1), static_cast<T>(1)};
	}

	template<class T> Vec3<T> Vec3<T>::up()
	{
		return {static_cast<T>(0), static_cast<T>(1), static_cast<T>(0)};
	}

	template<class T> Vec3<T> Vec3<T>::down()
	{
		return {static_cast<T>(0), static_cast<T>(-1), static_cast<T>(0)};
	}

	template<class T> Vec3<T> Vec3<T>::left()
	{
		return {static_cast<T>(-1), static_cast<T>(0), static_cast<T>(0)};
	}

	template<class T> Vec3<T> Vec3<T>::right()
	{
		return {static_cast<T>(1), static_cast<T>(0), static_cast<T>(0)};
	}

	template<class T> Vec3<T> Vec3<T>::front()
	{
		return {static_cast<T>(0), static_cast<T>(0), static_cast<T>(1)};
	}

	template<class T> Vec3<T> Vec3<T>::back()
	{
		return {static_cast<T>(0), static_cast<T>(0), static_cast<T>(-1)};
	}

	template<class T> T Vec3<T>::dot(const Vec3<T> &tLeft, const Vec3<T> &tRight)
	{
		return tLeft.tX * tRight.tX + tLeft.tY * tRight.tY + tLeft.tZ * tRight.tZ;
	}

	template<class T> Vec3<T> Vec3<T>::cross(const Vec3<T> &tLeft, const Vec3<T> &tRight)
	{
		return
		{
			tLeft.tY * tRight.tZ - tRight.tY * tLeft.tZ,
			tLeft.tZ * tRight.tX - tRight.tZ * tLeft.tX,
			tLeft.tX * tRight.tY - tRight.tX * tLeft.tY
		};
	}

	template<class T, class U> Vec3<T> operator+(const Vec3<T> &tVec3, U uScalar)
	{
		auto tScalar{static_cast<T>(uScalar)};

		return {tVec3.tX + tScalar, tVec3.tY + tScalar, tVec3.tZ + tScalar};
	}

	template<class T, class U> Vec3<U> operator+(T tScalar, const Vec3<U> &uVec3)
	{
		auto uScalar{static_cast<U>(tScalar)};

		return {uScalar + uVec3.tX, uScalar + uVec3.tY, uScalar + uVec3.tZ};
	}

	template<class T> Vec3<T> operator+(const Vec3<T> &tLeft, const Vec3<T> &tRight)
	{
		return {tLeft.tX + tRight.tX, tLeft.tY + tRight.tY, tLeft.tZ + tRight.tZ};
	}

	template<class T, class U> Vec3<T> operator-(const Vec3<T> &tVec3, U uScalar)
	{
		auto tScalar{static_cast<T>(uScalar)};

		return {tVec3.tX - tScalar, tVec3.tY - tScalar, tVec3.tZ - tScalar};
	}

	template<class T, class U> Vec3<U> operator-(T tScalar, const Vec3<U> &uVec3)
	{
		auto uScalar{static_cast<U>(tScalar)};

		return {uScalar - uVec3.tX, uScalar - uVec3.tY, uScalar - uVec3.tZ};
	}

	template<class T> Vec3<T> operator-(const Vec3<T> &tLeft, const Vec3<T> &tRight)
	{
		return {tLeft.tX - tRight.tX, tLeft.tY - tRight.tY, tLeft.tZ - tRight.tZ};
	}

	template<class T, class U> Vec3<T> operator*(const Vec3<T> &tVec3, U uScalar)
	{
		auto tScalar{static_cast<T>(uScalar)};

		return {tVec3.tX * tScalar, tVec3.tY * tScalar, tVec3.tZ * tScalar};
	}

	template<class T, class U> Vec3<U> operator*(T tScalar, const Vec3<U> &uVec3)
	{
		auto uScalar{static_cast<U>(tScalar)};

		return {uScalar * uVec3.tX, uScalar * uVec3.tY, uScalar * uVec3.tZ};
	}

	template<class T> Vec3<T> operator*(const Vec3<T> &tLeft, const Vec3<T> &tRight)
	{
		return {tLeft.tX * tRight.tX, tLeft.tY * tRight.tY, tLeft.tZ * tRight.tZ};
	}

	template<class T, class U> Vec3<T> operator/(const Vec3<T> &tVec3, U uScalar)
	{
		auto tScalar{static_cast<T>(uScalar)};

		return {tVec3.tX / tScalar, tVec3.tY / tScalar, tVec3.tZ / tScalar};
	}

	template<class T, class U> Vec3<U> operator/(T tScalar, const Vec3<U> &uVec3)
	{
		auto uScalar{static_cast<U>(tScalar)};

		return {uScalar / uVec3.tX, uScalar / uVec3.tY, uScalar / uVec3.tZ};
	}

	template<class T> Vec3<T> operator/(const Vec3<T> &tLeft, const Vec3<T> &tRight)
	{
		return {tLeft.tX / tRight.tX, tLeft.tY / tRight.tY, tLeft.tZ / tRight.tZ};
	}
}

#endif