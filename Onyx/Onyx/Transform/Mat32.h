
/*
	2019.06.08
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_ONYX_TRANSFORM_MAT32_H

#define _CLASS_ONYX_TRANSFORM_MAT32_H

namespace Onyx::Transform
{
	template<class T> class Mat23;

	template<class T> class alignas(sizeof(T) * 2) Mat32 final
	{
	public:
		Vec2<T> tX;
		Vec2<T> tY;
		Vec2<T> tZ;
		
	public:
		Mat32();
		Mat32(Vec2<T> tX, Vec2<T> tY, Vec2<T> tZ);
		Mat32(T tXX, T tXY, T tYX, T tYY, T tZX, T tZY);
		Mat32(const Mat32 &sSrc) = default;
		~Mat32() = default;
		
	public:
		Mat32 &operator=(const Mat32 &sSrc) = default;
		
	public:
		Vec2<T> &operator[](std::size_t nIndex);
		const Vec2<T> &operator[](std::size_t nIndex) const;
		Mat32 operator+() const;
		Mat32 operator-() const;
		Mat32 &operator++();
		Mat32 operator++(int);
		Mat32 &operator--();
		Mat32 operator--(int);
		template<class U> Mat32 &operator+=(U uScalar);
		template<class U> Mat32 &operator+=(const Vec2<U> & uVec2);
		template<class U> Mat32 &operator+=(const Mat32<U> & uMat32);
		template<class U> Mat32 &operator-=(U uScalar);
		template<class U> Mat32 &operator-=(const Vec2<U> & uVec2);
		template<class U> Mat32 &operator-=(const Mat32<U> & uMat32);
		template<class U> Mat32 &operator*=(U uScalar);
		template<class U> Mat32 &operator*=(const Vec2<U> & uVec2);
		template<class U> Mat32 &operator*=(const Mat32<U> & uMat32);
		template<class U> Mat32 &operator/=(U uScalar);
		template<class U> Mat32 &operator/=(const Vec2<U> & uVec2);
		template<class U> Mat32 &operator/=(const Mat32<U> & uMat32);
		template<class U> bool operator==(U uScalar) const;
		template<class U> bool operator==(const Vec2<U> & uVec2) const;
		template<class U> bool operator==(const Mat32<U> & uMat32) const;
		template<class U> bool operator!=(U uScalar) const;
		template<class U> bool operator!=(const Vec2<U> & uVec2) const;
		template<class U> bool operator!=(const Mat32<U> & uMat32) const;
		template<class U> operator Mat32<U>() const;

	public:
		Mat23<T> transposed() const;
		static Mat32 zero();
		static Mat32 one();
	};

	template<class T, class U> Mat32<T> operator+(const Mat32<T> &tMat32, U uScalar);
	template<class T, class U> Mat32<U> operator+(T tScalar, const Mat32<U> &uMat32);
	template<class T, class U> Mat32<T> operator+(const Mat32<T> &tMat32, const Vec2<U> &uVec2);
	template<class T, class U> Mat32<U> operator+(const Vec2<T> &tVec2, const Mat32<U> &uMat32);
	template<class T> Mat32<T> operator+(const Mat32<T> &tLeft, const Mat32<T> &tRight);
	template<class T, class U> Mat32<T> operator-(const Mat32<T> &tMat32, U uScalar);
	template<class T, class U> Mat32<U> operator-(T tScalar, const Mat32<U> &uMat32);
	template<class T, class U> Mat32<T> operator-(const Mat32<T> &tMat32, const Vec2<U> &uVec2);
	template<class T, class U> Mat32<U> operator-(const Vec2<T> &tVec2, const Mat32<U> &uMat32);
	template<class T> Mat32<T> operator-(const Mat32<T> &tLeft, const Mat32<T> &tRight);
	template<class T, class U> Mat32<T> operator*(const Mat32<T> &tMat32, U uScalar);
	template<class T, class U> Mat32<U> operator*(T tScalar, const Mat32<U> &uMat32);
	template<class T, class U> Mat32<T> operator*(const Mat32<T> &tMat32, const Vec2<U> &uVec2);
	template<class T, class U> Mat32<U> operator*(const Vec2<T> &tVec2, const Mat32<U> &uMat32);
	template<class T> Mat32<T> operator*(const Mat32<T> &tLeft, const Mat32<T> &tRight);
	template<class T, class U> Mat32<T> operator/(const Mat32<T> &tMat32, U uScalar);
	template<class T, class U> Mat32<U> operator/(T tScalar, const Mat32<U> &uMat32);
	template<class T, class U> Mat32<T> operator/(const Mat32<T> &tMat32, const Vec2<U> &uVec2);
	template<class T, class U> Mat32<U> operator/(const Vec2<T> &tVec2, const Mat32<U> &uMat32);
	template<class T> Mat32<T> operator/(const Mat32<T> &tLeft, const Mat32<T> &tRight);
	template<class T, class U> Vec3<T> operator%(const Mat32<T> &tMat32, const Vec2<U> &uVec2);
	template<class T, class U> Vec2<U> operator%(const Vec3<T> &tVec3, const Mat32<U> &uMat32);

	using Mat32i = Mat32<std::int32_t>;
	using Mat32u = Mat32<std::uint32_t>;
	using Mat32f = Mat32<float>;
	using Mat32d = Mat32<double>;
}

#endif