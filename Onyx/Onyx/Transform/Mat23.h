
/*
	2019.06.02
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_ONYX_TRANSFORM_MAT23_H

#define _CLASS_ONYX_TRANSFORM_MAT23_H

namespace Onyx::Transform
{
	template<class T> class Mat32;

	template<class T> class alignas(sizeof(T) * 4) Mat23 final
	{
	public:
		Vec3<T> tX;
		Vec3<T> tY;

	public:
		Mat23();
		Mat23(Vec3<T> tX, Vec3<T> tY);
		Mat23(T tXX, T tXY, T tXZ, T tYX, T tYY, T tYZ);
		Mat23(const Mat23 & sSrc) = default;
		~Mat23() = default;

	public:
		Mat23 &operator=(const Mat23 & sSrc) = default;

	public:
		Vec3<T> &operator[](std::size_t nIndex);
		const Vec3<T> &operator[](std::size_t nIndex) const;
		Mat23 operator+() const;
		Mat23 operator-() const;
		Mat23 &operator++();
		Mat23 operator++(int);
		Mat23 &operator--();
		Mat23 operator--(int);
		template<class U> Mat23 &operator+=(U uScalar);
		template<class U> Mat23 &operator+=(const Vec3<U> & uVec3);
		template<class U> Mat23 &operator+=(const Mat23<U> & uMat23);
		template<class U> Mat23 &operator-=(U uScalar);
		template<class U> Mat23 &operator-=(const Vec3<U> & uVec3);
		template<class U> Mat23 &operator-=(const Mat23<U> & uMat23);
		template<class U> Mat23 &operator*=(U uScalar);
		template<class U> Mat23 &operator*=(const Vec3<U> & uVec3);
		template<class U> Mat23 &operator*=(const Mat23<U> & uMat23);
		template<class U> Mat23 &operator/=(U uScalar);
		template<class U> Mat23 &operator/=(const Vec3<U> & uVec3);
		template<class U> Mat23 &operator/=(const Mat23<U> & uMat23);
		template<class U> bool operator==(U uScalar) const;
		template<class U> bool operator==(const Vec3<U> & uVec3) const;
		template<class U> bool operator==(const Mat23<U> & uMat23) const;
		template<class U> bool operator!=(U uScalar) const;
		template<class U> bool operator!=(const Vec3<U> & uVec3) const;
		template<class U> bool operator!=(const Mat23<U> & uMat23) const;
		template<class U> operator Mat23<U>() const;

	public:
		Mat32<T> transposed() const;
		static Mat23 zero();
		static Mat23 one();
	};

	template<class T, class U> Mat23<T> operator+(const Mat23<T> &tMat23, U uScalar);
	template<class T, class U> Mat23<U> operator+(T tScalar, const Mat23<U> &uMat23);
	template<class T, class U> Mat23<T> operator+(const Mat23<T> &tMat23, const Vec3<U> &uVec3);
	template<class T, class U> Mat23<U> operator+(const Vec3<T> &tVec3, const Mat23<U> &uMat23);
	template<class T> Mat23<T> operator+(const Mat23<T> &tLeft, const Mat23<T> &tRight);
	template<class T, class U> Mat23<T> operator-(const Mat23<T> &tMat23, U uScalar);
	template<class T, class U> Mat23<U> operator-(T tScalar, const Mat23<U> &uMat23);
	template<class T, class U> Mat23<T> operator-(const Mat23<T> &tMat23, const Vec3<U> &uVec3);
	template<class T, class U> Mat23<U> operator-(const Vec3<T> &tVec3, const Mat23<U> &uMat23);
	template<class T> Mat23<T> operator-(const Mat23<T> &tLeft, const Mat23<T> &tRight);
	template<class T, class U> Mat23<T> operator*(const Mat23<T> &tMat23, U uScalar);
	template<class T, class U> Mat23<U> operator*(T tScalar, const Mat23<U> &uMat23);
	template<class T, class U> Mat23<T> operator*(const Mat23<T> &tMat23, const Vec3<U> &uVec3);
	template<class T, class U> Mat23<U> operator*(const Vec3<T> &tVec3, const Mat23<U> &uMat23);
	template<class T> Mat23<T> operator*(const Mat23<T> &tLeft, const Mat23<T> &tRight);
	template<class T, class U> Mat23<T> operator/(const Mat23<T> &tMat23, U uScalar);
	template<class T, class U> Mat23<U> operator/(T tScalar, const Mat23<U> &uMat23);
	template<class T, class U> Mat23<T> operator/(const Mat23<T> &tMat23, const Vec3<U> &uVec3);
	template<class T, class U> Mat23<U> operator/(const Vec3<T> &tVec3, const Mat23<U> &uMat23);
	template<class T> Mat23<T> operator/(const Mat23<T> &tLeft, const Mat23<T> &tRight);
	template<class T, class U> Vec2<T> operator%(const Mat23<T> &tMat23, const Vec3<U> &uVec3);
	template<class T, class U> Vec3<U> operator%(const Vec2<T> &tVec2, const Mat23<U> &uMat23);

	using Mat23i = Mat23<std::int32_t>;
	using Mat23u = Mat23<std::uint32_t>;
	using Mat23f = Mat23<float>;
	using Mat23d = Mat23<double>;
}

#endif