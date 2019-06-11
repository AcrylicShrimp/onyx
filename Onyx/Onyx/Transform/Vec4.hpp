
/*
	2019.06.01
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_ONYX_TRANSFORM_VEC4_HPP

#define _CLASS_ONYX_TRANSFORM_VEC4_HPP

namespace Onyx::Transform
{
	template<class T> Vec4<T>::Vec4() :
		tX{static_cast<T>(0)},
		tY{static_cast<T>(0)},
		tZ{static_cast<T>(0)},
		tW{static_cast<T>(0)}
	{
		//Empty.
	}

	template<class T> Vec4<T>::Vec4(T tX, T tY, T tZ, T tW) :
		tX{tX},
		tY{tY},
		tZ{tZ},
		tW{tW}
	{
		//Empty.
	}

	template<class T> T &Vec4<T>::operator[](std::size_t nIndex)
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

	template<class T> const T &Vec4<T>::operator[](std::size_t nIndex) const
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

	template<class T> Vec4<T> Vec4<T>::operator+() const
	{
		return *this;
	}

	template<class T> Vec4<T> Vec4<T>::operator-() const
	{
		return {-this->tX, -this->tY, -this->tZ, -this->tW};
	}

	template<class T> Vec4<T> &Vec4<T>::operator++()
	{
		++this->tX;
		++this->tY;
		++this->tZ;
		++this->tW;

		return *this;
	}

	template<class T> Vec4<T> Vec4<T>::operator++(int)
	{
		auto tResult{*this};

		++this->tX;
		++this->tY;
		++this->tZ;
		++this->tW;

		return tResult;
	}

	template<class T> Vec4<T> &Vec4<T>::operator--()
	{
		--this->tX;
		--this->tY;
		--this->tZ;
		--this->tW;

		return *this;
	}

	template<class T> Vec4<T> Vec4<T>::operator--(int)
	{
		auto tResult{*this};

		--this->tX;
		--this->tY;
		--this->tZ;
		--this->tW;

		return tResult;
	}

	template<class T> template<class U> Vec4<T> &Vec4<T>::operator+=(U uScalar)
	{
		auto tScalar{static_cast<T>(uScalar)};

		this->tX += tScalar;
		this->tY += tScalar;
		this->tZ += tScalar;
		this->tW += tScalar;

		return *this;
	}

	template<class T> template<class U> Vec4<T> &Vec4<T>::operator+=(const Vec4<U> &uVec4)
	{
		this->tX += static_cast<T>(uVec4.tX);
		this->tY += static_cast<T>(uVec4.tY);
		this->tZ += static_cast<T>(uVec4.tZ);
		this->tW += static_cast<T>(uVec4.tW);

		return *this;
	}

	template<class T> template<class U> Vec4<T> &Vec4<T>::operator-=(U uScalar)
	{
		auto tScalar{static_cast<T>(uScalar)};

		this->tX -= tScalar;
		this->tY -= tScalar;
		this->tZ -= tScalar;
		this->tW -= tScalar;

		return *this;
	}

	template<class T> template<class U> Vec4<T> &Vec4<T>::operator-=(const Vec4<U> &uVec4)
	{
		this->tX -= static_cast<T>(uVec4.tX);
		this->tY -= static_cast<T>(uVec4.tY);
		this->tZ -= static_cast<T>(uVec4.tZ);
		this->tW -= static_cast<T>(uVec4.tW);

		return *this;
	}

	template<class T> template<class U> Vec4<T> &Vec4<T>::operator*=(U uScalar)
	{
		auto tScalar{static_cast<T>(uScalar)};

		this->tX *= tScalar;
		this->tY *= tScalar;
		this->tZ *= tScalar;
		this->tW *= tScalar;

		return *this;
	}

	template<class T> template<class U> Vec4<T> &Vec4<T>::operator*=(const Vec4<U> &uVec4)
	{
		this->tX *= static_cast<T>(uVec4.tX);
		this->tY *= static_cast<T>(uVec4.tY);
		this->tZ *= static_cast<T>(uVec4.tZ);
		this->tW *= static_cast<T>(uVec4.tW);

		return *this;
	}

	template<class T> template<class U> Vec4<T> &Vec4<T>::operator/=(U uScalar)
	{
		auto tScalar{static_cast<T>(uScalar)};

		this->tX /= tScalar;
		this->tY /= tScalar;
		this->tZ /= tScalar;
		this->tW /= tScalar;

		return *this;
	}

	template<class T> template<class U> Vec4<T> &Vec4<T>::operator/=(const Vec4<U> &uVec4)
	{
		this->tX /= static_cast<T>(uVec4.tX);
		this->tY /= static_cast<T>(uVec4.tY);
		this->tZ /= static_cast<T>(uVec4.tZ);
		this->tW /= static_cast<T>(uVec4.tW);

		return *this;
	}

	template<class T> template<class U> bool Vec4<T>::operator==(U uScalar) const
	{
		return
			this->tX == uScalar &&
			this->tY == uScalar &&
			this->tZ == uScalar &&
			this->tW == uScalar;
	}

	template<class T> template<class U> bool Vec4<T>::operator==(const Vec4<U> &uVec4) const
	{
		return
			this->tX == uVec4.tX &&
			this->tY == uVec4.tY &&
			this->tZ == uVec4.tZ &&
			this->tW == uVec4.tW;
	}

	template<class T> template<class U> bool Vec4<T>::operator!=(U uScalar) const
	{
		return
			this->tX != uScalar ||
			this->tY != uScalar ||
			this->tZ != uScalar ||
			this->tW != uScalar;
	}

	template<class T> template<class U> bool Vec4<T>::operator!=(const Vec4<U> &uVec4) const
	{
		return
			this->tX != uVec4.tX ||
			this->tY != uVec4.tY ||
			this->tZ != uVec4.tZ ||
			this->tW != uVec4.tW;
	}

	template<class T> template<class U> Vec4<T>::operator Vec4<U>() const
	{
		return {static_cast<U>(this->tX), static_cast<U>(this->tY), static_cast<U>(this->tZ), static_cast<U>(this->tW)};
	}

	template<class T> T Vec4<T>::length() const
	{
		return static_cast<T>(std::sqrt(this->tX * this->tX + this->tY * this->tY + this->tZ * this->tZ + this->tW * this->tW));
	}

	template<class T> Vec4<T> Vec4<T>::zero()
	{
		return {static_cast<T>(0), static_cast<T>(0), static_cast<T>(0), static_cast<T>(0)};
	}

	template<class T> Vec4<T> Vec4<T>::one()
	{
		return {static_cast<T>(1), static_cast<T>(1), static_cast<T>(1), static_cast<T>(1)};
	}

	template<class T> Vec4<T> Vec4<T>::up()
	{
		return {static_cast<T>(0), static_cast<T>(1), static_cast<T>(0), static_cast<T>(0)};
	}

	template<class T> Vec4<T> Vec4<T>::down()
	{
		return {static_cast<T>(0), static_cast<T>(-1), static_cast<T>(0), static_cast<T>(0)};
	}

	template<class T> Vec4<T> Vec4<T>::left()
	{
		return {static_cast<T>(-1), static_cast<T>(0), static_cast<T>(0), static_cast<T>(0)};
	}

	template<class T> Vec4<T> Vec4<T>::right()
	{
		return {static_cast<T>(1), static_cast<T>(0), static_cast<T>(0), static_cast<T>(0)};
	}

	template<class T> Vec4<T> Vec4<T>::front()
	{
		return {static_cast<T>(0), static_cast<T>(0), static_cast<T>(1), static_cast<T>(0)};
	}

	template<class T> Vec4<T> Vec4<T>::back()
	{
		return {static_cast<T>(0), static_cast<T>(0), static_cast<T>(-1), static_cast<T>(0)};
	}

	template<class T> T Vec4<T>::dot(const Vec4<T> &tLeft, const Vec4<T> &tRight)
	{
		return tLeft.tX * tRight.tX + tLeft.tY * tRight.tY + tLeft.tZ * tRight.tZ + tLeft.tW * tRight.tW;
	}

	template<class T, class U> Vec4<T> operator+(const Vec4<T> &tVec4, U uScalar)
	{
		auto tScalar{static_cast<T>(uScalar)};

		return {tVec4.tX + tScalar, tVec4.tY + tScalar, tVec4.tZ + tScalar, tVec4.tW + tScalar};
	}

	template<class T, class U> Vec4<U> operator+(T tScalar, const Vec4<U> &uVec4)
	{
		auto uScalar{static_cast<U>(tScalar)};

		return {uScalar + uVec4.tX, uScalar + uVec4.tY, uScalar + uVec4.tZ, uScalar + uVec4.tW};
	}

	template<class T> Vec4<T> operator+(const Vec4<T> &tLeft, const Vec4<T> &tRight)
	{
		return {tLeft.tX + tRight.tX, tLeft.tY + tRight.tY, tLeft.tZ + tRight.tZ, tLeft.tW + tRight.tW};
	}

	template<class T, class U> Vec4<T> operator-(const Vec4<T> &tVec4, U uScalar)
	{
		auto tScalar{static_cast<T>(uScalar)};

		return {tVec4.tX - tScalar, tVec4.tY - tScalar, tVec4.tZ - tScalar, tVec4.tW - tScalar};
	}

	template<class T, class U> Vec4<U> operator-(T tScalar, const Vec4<U> &uVec4)
	{
		auto uScalar{static_cast<U>(tScalar)};

		return {uScalar - uVec4.tX, uScalar - uVec4.tY, uScalar - uVec4.tZ, uScalar - uVec4.tW};
	}

	template<class T> Vec4<T> operator-(const Vec4<T> &tLeft, const Vec4<T> &tRight)
	{
		return {tLeft.tX - tRight.tX, tLeft.tY - tRight.tY, tLeft.tZ - tRight.tZ, tLeft.tW - tRight.tW};
	}

	template<class T, class U> Vec4<T> operator*(const Vec4<T> &tVec4, U uScalar)
	{
		auto tScalar{static_cast<T>(uScalar)};

		return {tVec4.tX * tScalar, tVec4.tY * tScalar, tVec4.tZ * tScalar, tVec4.tW * tScalar};
	}

	template<class T, class U> Vec4<U> operator*(T tScalar, const Vec4<U> &uVec4)
	{
		auto uScalar{static_cast<U>(tScalar)};

		return {uScalar * uVec4.tX, uScalar * uVec4.tY, uScalar * uVec4.tZ, uScalar * uVec4.tW};
	}

	template<class T> Vec4<T> operator*(const Vec4<T> &tLeft, const Vec4<T> &tRight)
	{
		return {tLeft.tX * tRight.tX, tLeft.tY * tRight.tY, tLeft.tZ * tRight.tZ, tLeft.tW * tRight.tW};
	}

	template<class T, class U> Vec4<T> operator/(const Vec4<T> &tVec4, U uScalar)
	{
		auto tScalar{static_cast<T>(uScalar)};

		return {tVec4.tX / tScalar, tVec4.tY / tScalar, tVec4.tZ / tScalar, tVec4.tW / tScalar};
	}

	template<class T, class U> Vec4<U> operator/(T tScalar, const Vec4<U> &uVec4)
	{
		auto uScalar{static_cast<U>(tScalar)};

		return {uScalar / uVec4.tX, uScalar / uVec4.tY, uScalar / uVec4.tZ, uScalar / uVec4.tW};
	}

	template<class T> Vec4<T> operator/(const Vec4<T> &tLeft, const Vec4<T> &tRight)
	{
		return {tLeft.tX / tRight.tX, tLeft.tY / tRight.tY, tLeft.tZ / tRight.tZ, tLeft.tW / tRight.tW};
	}
}

#endif