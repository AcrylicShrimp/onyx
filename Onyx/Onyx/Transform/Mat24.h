
/*
	2019.06.06
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_ONYX_TRANSFORM_MAT24_H

#define _CLASS_ONYX_TRANSFORM_MAT24_H

namespace Onyx::Transform
{
	template<class T> class Mat42;

	template<class T> class alignas(sizeof(float) * 2) Mat24 final
	{
	public:
		Vec4<T> tX;
		Vec4<T> tY;

	public:
		Mat24();
		Mat24(Vec4<T> tX, Vec4<T> tY);
		Mat24(T tXX, T tXY, T tXZ, T tXW, T tYX, T tYY, T tYZ, T tYW);
		Mat24(const Mat24 & sSrc) = default;
		~Mat24() = default;

	public:
		Mat24 &operator=(const Mat24 & sSrc) = default;

	public:
		Vec4<T> &operator[](std::size_t nIndex);
		const Vec4<T> &operator[](std::size_t nIndex) const;
		Mat24 operator+() const;
		Mat24 operator-() const;
		Mat24 &operator++();
		Mat24 operator++(int);
		Mat24 &operator--();
		Mat24 operator--(int);
		template<class U> Mat24 &operator+=(U uScalar);
		template<class U> Mat24 &operator+=(const Vec4<U> & uVec4);
		template<class U> Mat24 &operator+=(const Mat24<U> & uMat24);
		template<class U> Mat24 &operator-=(U uScalar);
		template<class U> Mat24 &operator-=(const Vec4<U> & uVec4);
		template<class U> Mat24 &operator-=(const Mat24<U> & uMat24);
		template<class U> Mat24 &operator*=(U uScalar);
		template<class U> Mat24 &operator*=(const Vec4<U> & uVec4);
		template<class U> Mat24 &operator*=(const Mat24<U> & uMat24);
		template<class U> Mat24 &operator/=(U uScalar);
		template<class U> Mat24 &operator/=(const Vec4<U> & uVec4);
		template<class U> Mat24 &operator/=(const Mat24<U> & uMat24);
		template<class U> bool operator==(U uScalar) const;
		template<class U> bool operator==(const Vec4<U> & uVec4) const;
		template<class U> bool operator==(const Mat24<U> & uMat24) const;
		template<class U> bool operator!=(U uScalar) const;
		template<class U> bool operator!=(const Vec4<U> & uVec4) const;
		template<class U> bool operator!=(const Mat24<U> & uMat24) const;
		template<class U> operator Mat24<U>() const;

	public:
		Mat42<T> transposed() const;
		static Mat24 zero();
		static Mat24 one();
	};

	template<class T, class U> Mat24<T> operator+(const Mat24<T> &tMat24, U uScalar);
	template<class T, class U> Mat24<U> operator+(T tScalar, const Mat24<U> &uMat24);
	template<class T, class U> Mat24<T> operator+(const Mat24<T> &tMat24, const Vec4<U> &uVec4);
	template<class T, class U> Mat24<U> operator+(const Vec4<T> &tVec4, const Mat24<U> &uMat24);
	template<class T> Mat24<T> operator+(const Mat24<T> &tLeft, const Mat24<T> &tRight);
	template<class T, class U> Mat24<T> operator-(const Mat24<T> &tMat24, U uScalar);
	template<class T, class U> Mat24<U> operator-(T tScalar, const Mat24<U> &uMat24);
	template<class T, class U> Mat24<T> operator-(const Mat24<T> &tMat24, const Vec4<U> &uVec4);
	template<class T, class U> Mat24<U> operator-(const Vec4<T> &tVec4, const Mat24<U> &uMat24);
	template<class T> Mat24<T> operator-(const Mat24<T> &tLeft, const Mat24<T> &tRight);
	template<class T, class U> Mat24<T> operator*(const Mat24<T> &tMat24, U uScalar);
	template<class T, class U> Mat24<U> operator*(T tScalar, const Mat24<U> &uMat24);
	template<class T, class U> Mat24<T> operator*(const Mat24<T> &tMat24, const Vec4<U> &uVec4);
	template<class T, class U> Mat24<U> operator*(const Vec4<T> &tVec4, const Mat24<U> &uMat24);
	template<class T> Mat24<T> operator*(const Mat24<T> &tLeft, const Mat24<T> &tRight);
	template<class T, class U> Mat24<T> operator/(const Mat24<T> &tMat24, U uScalar);
	template<class T, class U> Mat24<U> operator/(T tScalar, const Mat24<U> &uMat24);
	template<class T, class U> Mat24<T> operator/(const Mat24<T> &tMat24, const Vec4<U> &uVec4);
	template<class T, class U> Mat24<U> operator/(const Vec4<T> &tVec4, const Mat24<U> &uMat24);
	template<class T> Mat24<T> operator/(const Mat24<T> &tLeft, const Mat24<T> &tRight);
	template<class T, class U> Vec2<T> operator%(const Mat24<T> &tMat24, const Vec4<U> &uVec4);
	template<class T, class U> Vec4<U> operator%(const Vec2<T> &tVec2, const Mat24<U> &uMat24);

	using Mat24i = Mat24<std::int32_t>;
	using Mat24u = Mat24<std::uint32_t>;
	using Mat24f = Mat24<float>;
	using Mat24d = Mat24<double>;
}

#endif