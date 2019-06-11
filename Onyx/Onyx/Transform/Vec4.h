
/*
	2019.06.01
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_ONYX_TRANSFORM_VEC4_H

#define _CLASS_ONYX_TRANSFORM_VEC4_H

#include <cmath>
#include <cstddef>
#include <cstdint>

namespace Onyx::Transform
{
	template<class T> class alignas(sizeof(T) * 4) Vec4 final
	{
	public:
		T tX;
		T tY;
		T tZ;
		T tW;
		
	public:
		Vec4();
		Vec4(T tX, T tY, T tZ, T tW);
		Vec4(const Vec4 &sSrc) = default;
		~Vec4() = default;
		
	public:
		Vec4 &operator=(const Vec4 &sSrc) = default;
		T &operator[](std::size_t nIndex);
		const T &operator[](std::size_t nIndex) const;
		Vec4 operator+() const;
		Vec4 operator-() const;
		Vec4 &operator++();
		Vec4 operator++(int);
		Vec4 &operator--();
		Vec4 operator--(int);
		template<class U> Vec4 &operator+=(U uScalar);
		template<class U> Vec4 &operator+=(const Vec4<U> &uVec4);
		template<class U> Vec4 &operator-=(U uScalar);
		template<class U> Vec4 &operator-=(const Vec4<U> &uVec4);
		template<class U> Vec4 &operator*=(U uScalar);
		template<class U> Vec4 &operator*=(const Vec4<U> &uVec4);
		template<class U> Vec4 &operator/=(U uScalar);
		template<class U> Vec4 &operator/=(const Vec4<U> &uVec4);
		template<class U> bool operator==(U uScalar) const;
		template<class U> bool operator==(const Vec4<U> & uVec4) const;
		template<class U> bool operator!=(U uScalar) const;
		template<class U> bool operator!=(const Vec4<U> & uVec4) const;
		template<class U> operator Vec4<U>() const;
		
	public:
		T length() const;
		static Vec4 zero();
		static Vec4 one();
		static Vec4 up();
		static Vec4 down();
		static Vec4 left();
		static Vec4 right();
		static Vec4 front();
		static Vec4 back();
		static T dot(const Vec4<T> & tLeft, const Vec4<T> & tRight);
	};

	template<class T, class U> Vec4<T> operator+(const Vec4<T> &tVec4, U uScalar);
	template<class T, class U> Vec4<U> operator+(T tScalar, const Vec4<U> &uVec4);
	template<class T> Vec4<T> operator+(const Vec4<T> &tLeft, const Vec4<T> &tRight);
	template<class T, class U> Vec4<T> operator-(const Vec4<T> &tVec4, U uScalar);
	template<class T, class U> Vec4<U> operator-(T tScalar, const Vec4<U> &uVec4);
	template<class T> Vec4<T> operator-(const Vec4<T> &tLeft, const Vec4<T> &tRight);
	template<class T, class U> Vec4<T> operator*(const Vec4<T> &tVec4, U uScalar);
	template<class T, class U> Vec4<U> operator*(T tScalar, const Vec4<U> &uVec4);
	template<class T> Vec4<T> operator*(const Vec4<T> &tLeft, const Vec4<T> &tRight);
	template<class T, class U> Vec4<T> operator/(const Vec4<T> &tVec4, U uScalar);
	template<class T, class U> Vec4<U> operator/(T tScalar, const Vec4<U> &uVec4);
	template<class T> Vec4<T> operator/(const Vec4<T> &tLeft, const Vec4<T> &tRight);

	using Vec4i = Vec4<std::int32_t>;
	using Vec4u = Vec4<std::uint32_t>;
	using Vec4f = Vec4<float>;
	using Vec4d = Vec4<double>;
}

#endif