
/*
	2019.06.01
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_ONYX_TRANSFORM_VEC2_H

#define _CLASS_ONYX_TRANSFORM_VEC2_H

#include <cmath>
#include <cstddef>
#include <cstdint>

namespace Onyx::Transform
{
	template<class T> class alignas(sizeof(T) * 2) Vec2 final
	{
	public:
		T tX;
		T tY;
		
	public:
		Vec2();
		Vec2(T tX, T tY);
		Vec2(const Vec2 &sSrc) = default;
		~Vec2() = default;
		
	public:
		Vec2 &operator=(const Vec2 &sSrc) = default;
		T &operator[](std::size_t nIndex);
		const T &operator[](std::size_t nIndex) const;
		Vec2 operator+() const;
		Vec2 operator-() const;
		Vec2 &operator++();
		Vec2 operator++(int);
		Vec2 &operator--();
		Vec2 operator--(int);
		template<class U> Vec2 &operator+=(U uScalar);
		template<class U> Vec2 &operator+=(const Vec2<U> &uVec2);
		template<class U> Vec2 &operator-=(U uScalar);
		template<class U> Vec2 &operator-=(const Vec2<U> &uVec2);
		template<class U> Vec2 &operator*=(U uScalar);
		template<class U> Vec2 &operator*=(const Vec2<U> &uVec2);
		template<class U> Vec2 &operator/=(U uScalar);
		template<class U> Vec2 &operator/=(const Vec2<U> &uVec2);
		template<class U> bool operator==(U uScalar) const;
		template<class U> bool operator==(const Vec2<U> &uVec2) const;
		template<class U> bool operator!=(U uScalar) const;
		template<class U> bool operator!=(const Vec2<U> &uVec2) const;
		template<class U> operator Vec2<U>() const;
		
	public:
		T length() const;
		T lengthSquare() const;
		Vec2 normalized() const;
		static Vec2 zero();
		static Vec2 one();
		static Vec2 up();
		static Vec2 down();
		static Vec2 left();
		static Vec2 right();
		static T dot(const Vec2<T> &tLeft, const Vec2<T> &tRight);
	};

	template<class T, class U> Vec2<T> operator+(const Vec2<T> &tVec2, U uScalar);
	template<class T, class U> Vec2<U> operator+(T tScalar, const Vec2<U> &uVec2);
	template<class T> Vec2<T> operator+(const Vec2<T> &tLeft, const Vec2<T> &tRight);
	template<class T, class U> Vec2<T> operator-(const Vec2<T> &tVec2, U uScalar);
	template<class T, class U> Vec2<U> operator-(T tScalar, const Vec2<U> &uVec2);
	template<class T> Vec2<T> operator-(const Vec2<T> &tLeft, const Vec2<T> &tRight);
	template<class T, class U> Vec2<T> operator*(const Vec2<T> &tVec2, U uScalar);
	template<class T, class U> Vec2<U> operator*(T tScalar, const Vec2<U> &uVec2);
	template<class T> Vec2<T> operator*(const Vec2<T> &tLeft, const Vec2<T> &tRight);
	template<class T, class U> Vec2<T> operator/(const Vec2<T> &tVec2, U uScalar);
	template<class T, class U> Vec2<U> operator/(T tScalar, const Vec2<U> &uVec2);
	template<class T> Vec2<T> operator/(const Vec2<T> &tLeft, const Vec2<T> &tRight);

	using Vec2i = Vec2<std::int32_t>;
	using Vec2u = Vec2<std::uint32_t>;
	using Vec2f = Vec2<float>;
	using Vec2d = Vec2<double>;
}

#endif