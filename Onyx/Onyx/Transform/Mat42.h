
/*
	2019.06.09
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_ONYX_TRANSFORM_MAT42_H

#define _CLASS_ONYX_TRANSFORM_MAT42_H

namespace Onyx::Transform
{
	template<class T> class Mat24;

	template<class T> class alignas(sizeof(T) * 2) Mat42 final
	{
	public:
		Vec2<T> tX;
		Vec2<T> tY;
		Vec2<T> tZ;
		Vec2<T> tW;
		
	public:
		Mat42();
		Mat42(Vec2<T> tX, Vec2<T> tY, Vec2<T> tZ, Vec2<T> tW);
		Mat42(T tXX, T tXY, T tYX, T tYY, T tZX, T tZY, T tWX, T tWY);
		Mat42(const Mat42 &sSrc) = default;
		~Mat42() = default;
		
	public:
		Mat42 &operator=(const Mat42 &sSrc) = default;
		
	public:
		Vec2<T> &operator[](std::size_t nIndex);
		const Vec2<T> &operator[](std::size_t nIndex) const;
		Mat42 operator+() const;
		Mat42 operator-() const;
		Mat42 &operator++();
		Mat42 operator++(int);
		Mat42 &operator--();
		Mat42 operator--(int);
		template<class U> Mat42 &operator+=(U uScalar);
		template<class U> Mat42 &operator+=(const Vec2<U> & uVec2);
		template<class U> Mat42 &operator+=(const Mat42<U> & uMat42);
		template<class U> Mat42 &operator-=(U uScalar);
		template<class U> Mat42 &operator-=(const Vec2<U> & uVec2);
		template<class U> Mat42 &operator-=(const Mat42<U> & uMat42);
		template<class U> Mat42 &operator*=(U uScalar);
		template<class U> Mat42 &operator*=(const Vec2<U> & uVec2);
		template<class U> Mat42 &operator*=(const Mat42<U> & uMat42);
		template<class U> Mat42 &operator/=(U uScalar);
		template<class U> Mat42 &operator/=(const Vec2<U> & uVec2);
		template<class U> Mat42 &operator/=(const Mat42<U> & uMat42);
		template<class U> bool operator==(U uScalar) const;
		template<class U> bool operator==(const Vec2<U> & uVec2) const;
		template<class U> bool operator==(const Mat42<U> & uMat42) const;
		template<class U> bool operator!=(U uScalar) const;
		template<class U> bool operator!=(const Vec2<U> & uVec2) const;
		template<class U> bool operator!=(const Mat42<U> & uMat42) const;
		template<class U> operator Mat42<U>() const;

	public:
		Mat24<T> transposed() const;
		static Mat42 zero();
		static Mat42 one();
	};

	template<class T, class U> Mat42<T> operator+(const Mat42<T> &tMat42, U uScalar);
	template<class T, class U> Mat42<U> operator+(T tScalar, const Mat42<U> &uMat42);
	template<class T, class U> Mat42<T> operator+(const Mat42<T> &tMat42, const Vec2<U> &uVec2);
	template<class T, class U> Mat42<U> operator+(const Vec2<T> &tVec2, const Mat42<U> &uMat42);
	template<class T> Mat42<T> operator+(const Mat42<T> &tLeft, const Mat42<T> &tRight);
	template<class T, class U> Mat42<T> operator-(const Mat42<T> &tMat42, U uScalar);
	template<class T, class U> Mat42<U> operator-(T tScalar, const Mat42<U> &uMat42);
	template<class T, class U> Mat42<T> operator-(const Mat42<T> &tMat42, const Vec2<U> &uVec2);
	template<class T, class U> Mat42<U> operator-(const Vec2<T> &tVec2, const Mat42<U> &uMat42);
	template<class T> Mat42<T> operator-(const Mat42<T> &tLeft, const Mat42<T> &tRight);
	template<class T, class U> Mat42<T> operator*(const Mat42<T> &tMat42, U uScalar);
	template<class T, class U> Mat42<U> operator*(T tScalar, const Mat42<U> &uMat42);
	template<class T, class U> Mat42<T> operator*(const Mat42<T> &tMat42, const Vec2<U> &uVec2);
	template<class T, class U> Mat42<U> operator*(const Vec2<T> &tVec2, const Mat42<U> &uMat42);
	template<class T> Mat42<T> operator*(const Mat42<T> &tLeft, const Mat42<T> &tRight);
	template<class T, class U> Mat42<T> operator/(const Mat42<T> &tMat42, U uScalar);
	template<class T, class U> Mat42<U> operator/(T tScalar, const Mat42<U> &uMat42);
	template<class T, class U> Mat42<T> operator/(const Mat42<T> &tMat42, const Vec2<U> &uVec2);
	template<class T, class U> Mat42<U> operator/(const Vec2<T> &tVec2, const Mat42<U> &uMat42);
	template<class T> Mat42<T> operator/(const Mat42<T> &tLeft, const Mat42<T> &tRight);
	template<class T, class U> Vec4<T> operator%(const Mat42<T> &tMat42, const Vec2<U> &uVec2);
	template<class T, class U> Vec2<U> operator%(const Vec4<T> &tVec4, const Mat42<U> &uMat42);

	using Mat42i = Mat42<std::int32_t>;
	using Mat42u = Mat42<std::uint32_t>;
	using Mat42f = Mat42<float>;
	using Mat42d = Mat42<double>;
}

#endif