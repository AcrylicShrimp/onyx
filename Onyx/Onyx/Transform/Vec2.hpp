
/*
	2019.06.01
	Created by AcrylicShrimp.
*/

namespace Onyx::Transform
{
	template<class T> Vec2<T>::Vec2() :
		tX{static_cast<T>(0)},
		tY{static_cast<T>(0)}
	{
		//Empty.
	}

	template<class T> Vec2<T>::Vec2(T tX, T tY) :
		tX{tX},
		tY{tY}
	{
		//Empty.
	}

	template<class T> T &Vec2<T>::operator[](std::size_t nIndex)
	{
		switch (nIndex)
		{
		case 0:
			return this->tX;

		default:
			return this->tY;
		}
	}

	template<class T> const T &Vec2<T>::operator[](std::size_t nIndex) const
	{
		switch (nIndex)
		{
		case 0:
			return this->tX;

		default:
			return this->tY;
		}
	}

	template<class T> Vec2<T> Vec2<T>::operator+() const
	{
		return *this;
	}

	template<class T> Vec2<T> Vec2<T>::operator-() const
	{
		return {-this->tX, -this->tY};
	}

	template<class T> Vec2<T> &Vec2<T>::operator++()
	{
		++this->tX;
		++this->tY;

		return *this;
	}

	template<class T> Vec2<T> Vec2<T>::operator++(int)
	{
		auto tResult{*this};

		++this->tX;
		++this->tY;

		return tResult;
	}

	template<class T> Vec2<T> &Vec2<T>::operator--()
	{
		--this->tX;
		--this->tY;

		return *this;
	}

	template<class T> Vec2<T> Vec2<T>::operator--(int)
	{
		auto tResult{*this};

		--this->tX;
		--this->tY;

		return tResult;
	}

	template<class T> template<class U> Vec2<T> &Vec2<T>::operator+=(U uScalar)
	{
		auto tScalar{static_cast<T>(uScalar)};

		this->tX += tScalar;
		this->tY += tScalar;

		return *this;
	}

	template<class T> template<class U> Vec2<T> &Vec2<T>::operator+=(const Vec2<U> &uVec2)
	{
		this->tX += static_cast<T>(uVec2.tX);
		this->tY += static_cast<T>(uVec2.tY);

		return *this;
	}

	template<class T> template<class U> Vec2<T> &Vec2<T>::operator-=(U uScalar)
	{
		auto tScalar{static_cast<T>(uScalar)};

		this->tX -= tScalar;
		this->tY -= tScalar;

		return *this;
	}

	template<class T> template<class U> Vec2<T> &Vec2<T>::operator-=(const Vec2<U> &uVec2)
	{
		this->tX -= static_cast<T>(uVec2.tX);
		this->tY -= static_cast<T>(uVec2.tY);

		return *this;
	}

	template<class T> template<class U> Vec2<T> &Vec2<T>::operator*=(U uScalar)
	{
		auto tScalar{static_cast<T>(uScalar)};

		this->tX *= tScalar;
		this->tY *= tScalar;

		return *this;
	}

	template<class T> template<class U> Vec2<T> &Vec2<T>::operator*=(const Vec2<U> &uVec2)
	{
		this->tX *= static_cast<T>(uVec2.tX);
		this->tY *= static_cast<T>(uVec2.tY);

		return *this;
	}

	template<class T> template<class U> Vec2<T> &Vec2<T>::operator/=(U uScalar)
	{
		auto tScalar{static_cast<T>(uScalar)};

		this->tX /= tScalar;
		this->tY /= tScalar;

		return *this;
	}

	template<class T> template<class U> Vec2<T> &Vec2<T>::operator/=(const Vec2<U> &uVec2)
	{
		this->tX /= static_cast<T>(uVec2.tX);
		this->tY /= static_cast<T>(uVec2.tY);

		return *this;
	}

	template<class T> template<class U> bool Vec2<T>::operator==(U uScalar) const
	{
		return
			this->tX == uScalar &&
			this->tY == uScalar;
	}

	template<class T> template<class U> bool Vec2<T>::operator==(const Vec2<U> &uVec2) const
	{
		return
			this->tX == uVec2.tX &&
			this->tY == uVec2.tY;
	}

	template<class T> template<class U> bool Vec2<T>::operator!=(U uScalar) const
	{
		return
			this->tX != uScalar ||
			this->tY != uScalar;
	}

	template<class T> template<class U> bool Vec2<T>::operator!=(const Vec2<U> &uVec2) const
	{
		return
			this->tX != uVec2.tX ||
			this->tY != uVec2.tY;
	}

	template<class T> template<class U> Vec2<T>::operator Vec2<U>() const
	{
		return {static_cast<U>(this->tX), static_cast<U>(this->tY)};
	}

	template<class T> T Vec2<T>::length() const
	{
		return static_cast<T>(std::sqrt(this->tX * this->tX + this->tY * this->tY));
	}

	template<class T> Vec2<T> Vec2<T>::zero()
	{
		return {static_cast<T>(0), static_cast<T>(0)};
	}

	template<class T> Vec2<T> Vec2<T>::one()
	{
		return {static_cast<T>(1), static_cast<T>(1)};
	}

	template<class T> Vec2<T> Vec2<T>::up()
	{
		return {static_cast<T>(0), static_cast<T>(1)};
	}

	template<class T> Vec2<T> Vec2<T>::down()
	{
		return {static_cast<T>(0), static_cast<T>(-1)};
	}

	template<class T> Vec2<T> Vec2<T>::left()
	{
		return {static_cast<T>(-1), static_cast<T>(0)};
	}

	template<class T> Vec2<T> Vec2<T>::right()
	{
		return {static_cast<T>(1), static_cast<T>(0)};
	}

	template<class T> T Vec2<T>::dot(const Vec2<T> &tLeft, const Vec2<T> &tRight)
	{
		return tLeft.tX * tRight.tX + tLeft.tY * tRight.tY;
	}

	template<class T, class U> Vec2<T> operator+(const Vec2<T> &tVec2, U uScalar)
	{
		auto tScalar{static_cast<T>(uScalar)};

		return {tVec2.tX + tScalar, tVec2.tY + tScalar};
	}

	template<class T, class U> Vec2<U> operator+(T tScalar, const Vec2<U> &uVec2)
	{
		auto uScalar{static_cast<U>(tScalar)};

		return {uScalar + uVec2.tX, uScalar + uVec2.tY};
	}

	template<class T> Vec2<T> operator+(const Vec2<T> &tLeft, const Vec2<T> &tRight)
	{
		return {tLeft.tX + tRight.tX, tLeft.tY + tRight.tY};
	}

	template<class T, class U> Vec2<T> operator-(const Vec2<T> &tVec2, U uScalar)
	{
		auto tScalar{static_cast<T>(uScalar)};

		return {tVec2.tX - tScalar, tVec2.tY - tScalar};
	}

	template<class T, class U> Vec2<U> operator-(T tScalar, const Vec2<U> &uVec2)
	{
		auto uScalar{static_cast<U>(tScalar)};

		return {uScalar - uVec2.tX, uScalar - uVec2.tY};
	}

	template<class T> Vec2<T> operator-(const Vec2<T> &tLeft, const Vec2<T> &tRight)
	{
		return {tLeft.tX - tRight.tX, tLeft.tY - tRight.tY};
	}

	template<class T, class U> Vec2<T> operator*(const Vec2<T> &tVec2, U uScalar)
	{
		auto tScalar{static_cast<T>(uScalar)};

		return {tVec2.tX * tScalar, tVec2.tY * tScalar};
	}

	template<class T, class U> Vec2<U> operator*(T tScalar, const Vec2<U> &uVec2)
	{
		auto uScalar{static_cast<U>(tScalar)};

		return {uScalar * uVec2.tX, uScalar * uVec2.tY};
	}

	template<class T> Vec2<T> operator*(const Vec2<T> &tLeft, const Vec2<T> &tRight)
	{
		return {tLeft.tX * tRight.tX, tLeft.tY * tRight.tY};
	}

	template<class T, class U> Vec2<T> operator/(const Vec2<T> &tVec2, U uScalar)
	{
		auto tScalar{static_cast<T>(uScalar)};

		return {tVec2.tX / tScalar, tVec2.tY / tScalar};
	}

	template<class T, class U> Vec2<U> operator/(T tScalar, const Vec2<U> &uVec2)
	{
		auto uScalar{static_cast<U>(tScalar)};

		return {uScalar / uVec2.tX, uScalar / uVec2.tY};
	}

	template<class T> Vec2<T> operator/(const Vec2<T> &tLeft, const Vec2<T> &tRight)
	{
		return {tLeft.tX / tRight.tX, tLeft.tY / tRight.tY};
	}
}