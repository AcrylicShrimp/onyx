
/*
	2019.06.01
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_ONYX_TRANSFORM_VEC3_H

#define _CLASS_ONYX_TRANSFORM_VEC3_H

#include <cmath>
#include <cstddef>
#include <cstdint>

namespace Onyx::Transform
{
	template<class T> class alignas(sizeof(T) * 4) Vec3 final
	{
	public:
		T tX;
		T tY;
		T tZ;
		
	public:
		Vec3();
		Vec3(T tX, T tY, T tZ);
		Vec3(const Vec3 &sSrc) = default;
		~Vec3() = default;
		
	public:
		Vec3 &operator=(const Vec3 &sSrc) = default;
		T &operator[](std::size_t nIndex);
		const T &operator[](std::size_t nIndex) const;
		Vec3 operator+() const;
		Vec3 operator-() const;
		Vec3 &operator++();
		Vec3 operator++(int);
		Vec3 &operator--();
		Vec3 operator--(int);
		template<class U> Vec3 &operator+=(U uScalar);
		template<class U> Vec3 &operator+=(const Vec3<U> &uVec3);
		template<class U> Vec3 &operator-=(U uScalar);
		template<class U> Vec3 &operator-=(const Vec3<U> &uVec3);
		template<class U> Vec3 &operator*=(U uScalar);
		template<class U> Vec3 &operator*=(const Vec3<U> &uVec3);
		template<class U> Vec3 &operator/=(U uScalar);
		template<class U> Vec3 &operator/=(const Vec3<U> &uVec3);
		template<class U> bool operator==(U uScalar) const;
		template<class U> bool operator==(const Vec3<U> & uVec3) const;
		template<class U> bool operator!=(U uScalar) const;
		template<class U> bool operator!=(const Vec3<U> & uVec3) const;
		template<class U> operator Vec3<U>() const;
		
	public:
		T length() const;
		T lengthSquare() const;
		Vec3 normalized() const;
		static Vec3 zero();
		static Vec3 one();
		static Vec3 up();
		static Vec3 down();
		static Vec3 left();
		static Vec3 right();
		static Vec3 front();
		static Vec3 back();
		static T dot(const Vec3<T> & tLeft, const Vec3<T> & tRight);
		static Vec3<T> cross(const Vec3<T> & tLeft, const Vec3<T> & tRight);
	};

	template<class T, class U> Vec3<T> operator+(const Vec3<T> &tVec3, U uScalar);
	template<class T, class U> Vec3<U> operator+(T tScalar, const Vec3<U> &uVec3);
	template<class T> Vec3<T> operator+(const Vec3<T> &tLeft, const Vec3<T> &tRight);
	template<class T, class U> Vec3<T> operator-(const Vec3<T> &tVec3, U uScalar);
	template<class T, class U> Vec3<U> operator-(T tScalar, const Vec3<U> &uVec3);
	template<class T> Vec3<T> operator-(const Vec3<T> &tLeft, const Vec3<T> &tRight);
	template<class T, class U> Vec3<T> operator*(const Vec3<T> &tVec3, U uScalar);
	template<class T, class U> Vec3<U> operator*(T tScalar, const Vec3<U> &uVec3);
	template<class T> Vec3<T> operator*(const Vec3<T> &tLeft, const Vec3<T> &tRight);
	template<class T, class U> Vec3<T> operator/(const Vec3<T> &tVec3, U uScalar);
	template<class T, class U> Vec3<U> operator/(T tScalar, const Vec3<U> &uVec3);
	template<class T> Vec3<T> operator/(const Vec3<T> &tLeft, const Vec3<T> &tRight);

	using Vec3i = Vec3<std::int32_t>;
	using Vec3u = Vec3<std::uint32_t>;
	using Vec3f = Vec3<float>;
	using Vec3d = Vec3<double>;
}

#endif