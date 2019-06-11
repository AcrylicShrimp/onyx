
/*
	2019.06.08
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_ONYX_TRANSFORM_MAT34_H

#define _CLASS_ONYX_TRANSFORM_MAT34_H

namespace Onyx::Transform
{
	template<class T> class Mat43;

	template<class T> class alignas(sizeof(T) * 4) Mat34 final
	{
	public:
		Vec4<T> tX;
		Vec4<T> tY;
		Vec4<T> tZ;
		
	public:
		Mat34();
		Mat34(Vec4<T> tX, Vec4<T> tY, Vec4<T> tZ);
		Mat34(T tXX, T tXY, T tXZ, T tXW, T tYX, T tYY, T tYZ, T tYW, T tZX, T tZY, T tZZ, T tZW);
		Mat34(const Mat34 &sSrc) = default;
		~Mat34() = default;
		
	public:
		Mat34 &operator=(const Mat34 &sSrc) = default;
		
	public:
		Vec4<T> &operator[](std::size_t nIndex);
		const Vec4<T> &operator[](std::size_t nIndex) const;
		Mat34 operator+() const;
		Mat34 operator-() const;
		Mat34 &operator++();
		Mat34 operator++(int);
		Mat34 &operator--();
		Mat34 operator--(int);
		template<class U> Mat34 &operator+=(U uScalar);
		template<class U> Mat34 &operator+=(const Vec4<U> & uVec3);
		template<class U> Mat34 &operator+=(const Mat34<U> & uMat34);
		template<class U> Mat34 &operator-=(U uScalar);
		template<class U> Mat34 &operator-=(const Vec4<U> & uVec3);
		template<class U> Mat34 &operator-=(const Mat34<U> & uMat34);
		template<class U> Mat34 &operator*=(U uScalar);
		template<class U> Mat34 &operator*=(const Vec4<U> & uVec3);
		template<class U> Mat34 &operator*=(const Mat34<U> & uMat34);
		template<class U> Mat34 &operator/=(U uScalar);
		template<class U> Mat34 &operator/=(const Vec4<U> & uVec3);
		template<class U> Mat34 &operator/=(const Mat34<U> & uMat34);
		template<class U> bool operator==(U uScalar) const;
		template<class U> bool operator==(const Vec4<U> & uVec3) const;
		template<class U> bool operator==(const Mat34<U> & uMat34) const;
		template<class U> bool operator!=(U uScalar) const;
		template<class U> bool operator!=(const Vec4<U> & uVec3) const;
		template<class U> bool operator!=(const Mat34<U> & uMat34) const;
		template<class U> operator Mat34<U>() const;

	public:
		Mat43<T> transposed() const;
		static Mat34 zero();
		static Mat34 one();
		static Mat34 identity();
	};

	template<class T, class U> Mat34<T> operator+(const Mat34<T> &tMat34, U uScalar);
	template<class T, class U> Mat34<U> operator+(T tScalar, const Mat34<U> &uMat34);
	template<class T, class U> Mat34<T> operator+(const Mat34<T> &tMat34, const Vec4<U> &uVec3);
	template<class T, class U> Mat34<U> operator+(const Vec4<T> &tVec3, const Mat34<U> &uMat34);
	template<class T> Mat34<T> operator+(const Mat34<T> &tLeft, const Mat34<T> &tRight);
	template<class T, class U> Mat34<T> operator-(const Mat34<T> &tMat34, U uScalar);
	template<class T, class U> Mat34<U> operator-(T tScalar, const Mat34<U> &uMat34);
	template<class T, class U> Mat34<T> operator-(const Mat34<T> &tMat34, const Vec4<U> &uVec3);
	template<class T, class U> Mat34<U> operator-(const Vec4<T> &tVec3, const Mat34<U> &uMat34);
	template<class T> Mat34<T> operator-(const Mat34<T> &tLeft, const Mat34<T> &tRight);
	template<class T, class U> Mat34<T> operator*(const Mat34<T> &tMat34, U uScalar);
	template<class T, class U> Mat34<U> operator*(T tScalar, const Mat34<U> &uMat34);
	template<class T, class U> Mat34<T> operator*(const Mat34<T> &tMat34, const Vec4<U> &uVec3);
	template<class T, class U> Mat34<U> operator*(const Vec4<T> &tVec3, const Mat34<U> &uMat34);
	template<class T> Mat34<T> operator*(const Mat34<T> &tLeft, const Mat34<T> &tRight);
	template<class T, class U> Mat34<T> operator/(const Mat34<T> &tMat34, U uScalar);
	template<class T, class U> Mat34<U> operator/(T tScalar, const Mat34<U> &uMat34);
	template<class T, class U> Mat34<T> operator/(const Mat34<T> &tMat34, const Vec4<U> &uVec3);
	template<class T, class U> Mat34<U> operator/(const Vec4<T> &tVec3, const Mat34<U> &uMat34);
	template<class T> Mat34<T> operator/(const Mat34<T> &tLeft, const Mat34<T> &tRight);
	template<class T, class U> Vec3<T> operator%(const Mat34<T> &tMat34, const Vec4<U> &uVec4);
	template<class T, class U> Vec4<U> operator%(const Vec3<T> &tVec3, const Mat34<U> &uMat34);

	using Mat34i = Mat34<std::int32_t>;
	using Mat34u = Mat34<std::uint32_t>;
	using Mat34f = Mat34<float>;
	using Mat34d = Mat34<double>;
}

#endif