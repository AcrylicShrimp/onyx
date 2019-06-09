
/*
	2019.06.02
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_ONYX_TRANSFORM_MAT22_H

#define _CLASS_ONYX_TRANSFORM_MAT22_H

namespace Onyx::Transform
{
	template<class T> class alignas(sizeof(float) * 2) Mat22 final
	{
	public:
		Vec2<T> tX;
		Vec2<T> tY;
		
	public:
		Mat22();
		Mat22(Vec2<T> tX, Vec2<T> tY);
		Mat22(T tXX, T tXY, T tYX, T tYY);
		Mat22(const Mat22 &sSrc) = default;
		~Mat22() = default;
		
	public:
		Mat22 &operator=(const Mat22 &sSrc) = default;
		
	public:
		Vec2<T> &operator[](std::size_t nIndex);
		const Vec2<T> &operator[](std::size_t nIndex) const;
		Mat22 operator+() const;
		Mat22 operator-() const;
		Mat22 &operator++();
		Mat22 operator++(int);
		Mat22 &operator--();
		Mat22 operator--(int);
		template<class U> Mat22 &operator+=(U uScalar);
		template<class U> Mat22 &operator+=(const Vec2<U> &uVec2);
		template<class U> Mat22 &operator+=(const Mat22<U> &uMat22);
		template<class U> Mat22 &operator-=(U uScalar);
		template<class U> Mat22 &operator-=(const Vec2<U> &uVec2);
		template<class U> Mat22 &operator-=(const Mat22<U> &uMat22);
		template<class U> Mat22 &operator*=(U uScalar);
		template<class U> Mat22 &operator*=(const Vec2<U> &uVec2);
		template<class U> Mat22 &operator*=(const Mat22<U> &uMat22);
		template<class U> Mat22 &operator/=(U uScalar);
		template<class U> Mat22 &operator/=(const Vec2<U> &uVec2);
		template<class U> Mat22 &operator/=(const Mat22<U> &uMat22);
		template<class U> bool operator==(U uScalar) const;
		template<class U> bool operator==(const Vec2<U> & uVec2) const;
		template<class U> bool operator==(const Mat22<U> &uMat22) const;
		template<class U> bool operator!=(U uScalar) const;
		template<class U> bool operator!=(const Vec2<U> & uVec2) const;
		template<class U> bool operator!=(const Mat22<U> &uMat22) const;
		template<class U> operator Mat22<U>() const;

	public:
		Mat22 transposed() const;
		static Mat22 zero();
		static Mat22 one();
		static Mat22 identity();
	};

	template<class T, class U> Mat22<T> operator+(const Mat22<T> &tMat22, U uScalar);
	template<class T, class U> Mat22<U> operator+(T tScalar, const Mat22<U> &uMat22);
	template<class T, class U> Mat22<T> operator+(const Mat22<T> &tMat22, const Vec2<U> &uVec2);
	template<class T, class U> Mat22<U> operator+(const Vec2<T> &tVec2, const Mat22<U> &uMat22);
	template<class T> Mat22<T> operator+(const Mat22<T> &tLeft, const Mat22<T> &tRight);
	template<class T, class U> Mat22<T> operator-(const Mat22<T> &tMat22, U uScalar);
	template<class T, class U> Mat22<U> operator-(T tScalar, const Mat22<U> &uMat22);
	template<class T, class U> Mat22<T> operator-(const Mat22<T> &tMat22, const Vec2<U> &uVec2);
	template<class T, class U> Mat22<U> operator-(const Vec2<T> &tVec2, const Mat22<U> &uMat22);
	template<class T> Mat22<T> operator-(const Mat22<T> &tLeft, const Mat22<T> &tRight);
	template<class T, class U> Mat22<T> operator*(const Mat22<T> &tMat22, U uScalar);
	template<class T, class U> Mat22<U> operator*(T tScalar, const Mat22<U> &uMat22);
	template<class T, class U> Mat22<T> operator*(const Mat22<T> &tMat22, const Vec2<U> &uVec2);
	template<class T, class U> Mat22<U> operator*(const Vec2<T> &tVec2, const Mat22<U> &uMat22);
	template<class T> Mat22<T> operator*(const Mat22<T> &tLeft, const Mat22<T> &tRight);
	template<class T, class U> Mat22<T> operator/(const Mat22<T> &tMat22, U uScalar);
	template<class T, class U> Mat22<U> operator/(T tScalar, const Mat22<U> &uMat22);
	template<class T, class U> Mat22<T> operator/(const Mat22<T> &tMat22, const Vec2<U> &uVec2);
	template<class T, class U> Mat22<U> operator/(const Vec2<T> &tVec2, const Mat22<U> &uMat22);
	template<class T> Mat22<T> operator/(const Mat22<T> &tLeft, const Mat22<T> &tRight);
	template<class T, class U> Vec2<T> operator%(const Mat22<T> &tMat22, const Vec2<U> &uVec2);
	template<class T, class U> Vec2<U> operator%(const Vec2<T> &tVec2, const Mat22<U> &uMat22);

	using Mat22i = Mat22<std::int32_t>;
	using Mat22u = Mat22<std::uint32_t>;
	using Mat22f = Mat22<float>;
	using Mat22d = Mat22<double>;
}

#endif