
/*
	2019.06.09
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_ONYX_TRANSFORM_MAT43_H

#define _CLASS_ONYX_TRANSFORM_MAT43_H

namespace Onyx::Transform
{
	template<class T> class Mat34;

	template<class T> class alignas(sizeof(T) * 4) Mat43 final
	{
	public:
		Vec3<T> tX;
		Vec3<T> tY;
		Vec3<T> tZ;
		Vec3<T> tW;
		
	public:
		Mat43();
		Mat43(Vec3<T> tX, Vec3<T> tY, Vec3<T> tZ, Vec3<T> tW);
		Mat43(T tXX, T tXY, T tXZ, T tYX, T tYY, T tYZ, T tZX, T tZY, T tZZ, T tWX, T tWY, T tWZ);
		Mat43(const Mat43 &sSrc) = default;
		~Mat43() = default;
		
	public:
		Mat43 &operator=(const Mat43 &sSrc) = default;
		
	public:
		Vec3<T> &operator[](std::size_t nIndex);
		const Vec3<T> &operator[](std::size_t nIndex) const;
		Mat43 operator+() const;
		Mat43 operator-() const;
		Mat43 &operator++();
		Mat43 operator++(int);
		Mat43 &operator--();
		Mat43 operator--(int);
		template<class U> Mat43 &operator+=(U uScalar);
		template<class U> Mat43 &operator+=(const Vec3<U> & uVec3);
		template<class U> Mat43 &operator+=(const Mat43<U> & uMat43);
		template<class U> Mat43 &operator-=(U uScalar);
		template<class U> Mat43 &operator-=(const Vec3<U> & uVec3);
		template<class U> Mat43 &operator-=(const Mat43<U> & uMat43);
		template<class U> Mat43 &operator*=(U uScalar);
		template<class U> Mat43 &operator*=(const Vec3<U> & uVec3);
		template<class U> Mat43 &operator*=(const Mat43<U> & uMat43);
		template<class U> Mat43 &operator/=(U uScalar);
		template<class U> Mat43 &operator/=(const Vec3<U> & uVec3);
		template<class U> Mat43 &operator/=(const Mat43<U> & uMat43);
		template<class U> bool operator==(U uScalar) const;
		template<class U> bool operator==(const Vec3<U> & uVec3) const;
		template<class U> bool operator==(const Mat43<U> & uMat43) const;
		template<class U> bool operator!=(U uScalar) const;
		template<class U> bool operator!=(const Vec3<U> & uVec3) const;
		template<class U> bool operator!=(const Mat43<U> & uMat43) const;
		template<class U> operator Mat43<U>() const;

	public:
		Mat34<T> transposed() const;
		static Mat43 zero();
		static Mat43 one();
	};

	template<class T, class U> Mat43<T> operator+(const Mat43<T> &tMat43, U uScalar);
	template<class T, class U> Mat43<U> operator+(T tScalar, const Mat43<U> &uMat43);
	template<class T, class U> Mat43<T> operator+(const Mat43<T> &tMat43, const Vec3<U> &uVec3);
	template<class T, class U> Mat43<U> operator+(const Vec3<T> &tVec3, const Mat43<U> &uMat43);
	template<class T> Mat43<T> operator+(const Mat43<T> &tLeft, const Mat43<T> &tRight);
	template<class T, class U> Mat43<T> operator-(const Mat43<T> &tMat43, U uScalar);
	template<class T, class U> Mat43<U> operator-(T tScalar, const Mat43<U> &uMat43);
	template<class T, class U> Mat43<T> operator-(const Mat43<T> &tMat43, const Vec3<U> &uVec3);
	template<class T, class U> Mat43<U> operator-(const Vec3<T> &tVec3, const Mat43<U> &uMat43);
	template<class T> Mat43<T> operator-(const Mat43<T> &tLeft, const Mat43<T> &tRight);
	template<class T, class U> Mat43<T> operator*(const Mat43<T> &tMat43, U uScalar);
	template<class T, class U> Mat43<U> operator*(T tScalar, const Mat43<U> &uMat43);
	template<class T, class U> Mat43<T> operator*(const Mat43<T> &tMat43, const Vec3<U> &uVec3);
	template<class T, class U> Mat43<U> operator*(const Vec3<T> &tVec3, const Mat43<U> &uMat43);
	template<class T> Mat43<T> operator*(const Mat43<T> &tLeft, const Mat43<T> &tRight);
	template<class T, class U> Mat43<T> operator/(const Mat43<T> &tMat43, U uScalar);
	template<class T, class U> Mat43<U> operator/(T tScalar, const Mat43<U> &uMat43);
	template<class T, class U> Mat43<T> operator/(const Mat43<T> &tMat43, const Vec3<U> &uVec3);
	template<class T, class U> Mat43<U> operator/(const Vec3<T> &tVec3, const Mat43<U> &uMat43);
	template<class T> Mat43<T> operator/(const Mat43<T> &tLeft, const Mat43<T> &tRight);
	template<class T, class U> Vec4<T> operator%(const Mat43<T> &tMat43, const Vec3<U> &uVec3);
	template<class T, class U> Vec3<U> operator%(const Vec4<T> &tVec4, const Mat43<U> &uMat43);

	using Mat43i = Mat43<std::int32_t>;
	using Mat43u = Mat43<std::uint32_t>;
	using Mat43f = Mat43<float>;
	using Mat43d = Mat43<double>;
}

#endif