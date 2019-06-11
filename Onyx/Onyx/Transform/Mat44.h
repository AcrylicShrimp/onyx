
/*
	2019.06.09
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_ONYX_TRANSFORM_MAT44_H

#define _CLASS_ONYX_TRANSFORM_MAT44_H

namespace Onyx::Transform
{
	template<class T> class alignas(sizeof(T) * 4) Mat44 final
	{
	public:
		Vec4<T> tX;
		Vec4<T> tY;
		Vec4<T> tZ;
		Vec4<T> tW;
		
	public:
		Mat44();
		Mat44(Vec4<T> tX, Vec4<T> tY, Vec4<T> tZ, Vec4<T> tW);
		Mat44(T tXX, T tXY, T tXZ, T tXW, T tYX, T tYY, T tYZ, T tYW, T tZX, T tZY, T tZZ, T tZW, T tWX, T tWY, T tWZ, T tWW);
		Mat44(const Mat44 &sSrc) = default;
		~Mat44() = default;
		
	public:
		Mat44 &operator=(const Mat44 &sSrc) = default;
		
	public:
		Vec4<T> &operator[](std::size_t nIndex);
		const Vec4<T> &operator[](std::size_t nIndex) const;
		Mat44 operator+() const;
		Mat44 operator-() const;
		Mat44 &operator++();
		Mat44 operator++(int);
		Mat44 &operator--();
		Mat44 operator--(int);
		template<class U> Mat44 &operator+=(U uScalar);
		template<class U> Mat44 &operator+=(const Vec4<U> & uVec4);
		template<class U> Mat44 &operator+=(const Mat44<U> & uMat44);
		template<class U> Mat44 &operator-=(U uScalar);
		template<class U> Mat44 &operator-=(const Vec4<U> & uVec4);
		template<class U> Mat44 &operator-=(const Mat44<U> & uMat44);
		template<class U> Mat44 &operator*=(U uScalar);
		template<class U> Mat44 &operator*=(const Vec4<U> & uVec4);
		template<class U> Mat44 &operator*=(const Mat44<U> & uMat44);
		template<class U> Mat44 &operator/=(U uScalar);
		template<class U> Mat44 &operator/=(const Vec4<U> & uVec4);
		template<class U> Mat44 &operator/=(const Mat44<U> & uMat44);
		template<class U> bool operator==(U uScalar) const;
		template<class U> bool operator==(const Vec4<U> & uVec4) const;
		template<class U> bool operator==(const Mat44<U> & uMat44) const;
		template<class U> bool operator!=(U uScalar) const;
		template<class U> bool operator!=(const Vec4<U> & uVec4) const;
		template<class U> bool operator!=(const Mat44<U> & uMat44) const;
		template<class U> operator Mat44<U>() const;

	public:
		Mat44<T> transposed() const;
		static Mat44 zero();
		static Mat44 one();
		static Mat44 identity();
	};

	template<class T, class U> Mat44<T> operator+(const Mat44<T> &tMat44, U uScalar);
	template<class T, class U> Mat44<U> operator+(T tScalar, const Mat44<U> &uMat44);
	template<class T, class U> Mat44<T> operator+(const Mat44<T> &tMat44, const Vec4<U> &uVec4);
	template<class T, class U> Mat44<U> operator+(const Vec4<T> &tVec4, const Mat44<U> &uMat44);
	template<class T> Mat44<T> operator+(const Mat44<T> &tLeft, const Mat44<T> &tRight);
	template<class T, class U> Mat44<T> operator-(const Mat44<T> &tMat44, U uScalar);
	template<class T, class U> Mat44<U> operator-(T tScalar, const Mat44<U> &uMat44);
	template<class T, class U> Mat44<T> operator-(const Mat44<T> &tMat44, const Vec4<U> &uVec4);
	template<class T, class U> Mat44<U> operator-(const Vec4<T> &tVec4, const Mat44<U> &uMat44);
	template<class T> Mat44<T> operator-(const Mat44<T> &tLeft, const Mat44<T> &tRight);
	template<class T, class U> Mat44<T> operator*(const Mat44<T> &tMat44, U uScalar);
	template<class T, class U> Mat44<U> operator*(T tScalar, const Mat44<U> &uMat44);
	template<class T, class U> Mat44<T> operator*(const Mat44<T> &tMat44, const Vec4<U> &uVec4);
	template<class T, class U> Mat44<U> operator*(const Vec4<T> &tVec4, const Mat44<U> &uMat44);
	template<class T> Mat44<T> operator*(const Mat44<T> &tLeft, const Mat44<T> &tRight);
	template<class T, class U> Mat44<T> operator/(const Mat44<T> &tMat44, U uScalar);
	template<class T, class U> Mat44<U> operator/(T tScalar, const Mat44<U> &uMat44);
	template<class T, class U> Mat44<T> operator/(const Mat44<T> &tMat44, const Vec4<U> &uVec4);
	template<class T, class U> Mat44<U> operator/(const Vec4<T> &tVec4, const Mat44<U> &uMat44);
	template<class T> Mat44<T> operator/(const Mat44<T> &tLeft, const Mat44<T> &tRight);
	template<class T, class U> Vec4<T> operator%(const Mat44<T> &tMat44, const Vec4<U> &uVec4);
	template<class T, class U> Vec4<U> operator%(const Vec4<T> &tVec4, const Mat44<U> &uMat44);

	using Mat44i = Mat44<std::int32_t>;
	using Mat44u = Mat44<std::uint32_t>;
	using Mat44f = Mat44<float>;
	using Mat44d = Mat44<double>;
}

#endif