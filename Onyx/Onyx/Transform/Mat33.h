
/*
	2019.06.08
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_ONYX_TRANSFORM_MAT33_H

#define _CLASS_ONYX_TRANSFORM_MAT33_H

namespace Onyx::Transform
{
	template<class T> class alignas(sizeof(float) * 2) Mat33 final
	{
	private:
		Vec3<T> tX;
		Vec3<T> tY;
		Vec3<T> tZ;
		
	public:
		Mat33();
		Mat33(Vec3<T> tX, Vec3<T> tY, Vec3<T> tZ);
		Mat33(T tXX, T tXY, T tXZ, T tYX, T tYY, T tYZ, T tZX, T tZY, T tZZ);
		Mat33(const Mat33 &sSrc) = default;
		~Mat33() = default;
		
	public:
		Mat33 &operator=(const Mat33 &sSrc) = default;
		
	public:
		Vec3<T> &operator[](std::size_t nIndex);
		const Vec3<T> &operator[](std::size_t nIndex) const;
		Mat33 operator+() const;
		Mat33 operator-() const;
		Mat33 &operator++();
		Mat33 operator++(int);
		Mat33 &operator--();
		Mat33 operator--(int);
		template<class U> Mat33 &operator+=(U uScalar);
		template<class U> Mat33 &operator+=(const Vec3<U> & uVec3);
		template<class U> Mat33 &operator+=(const Mat33<U> & uMat33);
		template<class U> Mat33 &operator-=(U uScalar);
		template<class U> Mat33 &operator-=(const Vec3<U> & uVec3);
		template<class U> Mat33 &operator-=(const Mat33<U> & uMat33);
		template<class U> Mat33 &operator*=(U uScalar);
		template<class U> Mat33 &operator*=(const Vec3<U> & uVec3);
		template<class U> Mat33 &operator*=(const Mat33<U> & uMat33);
		template<class U> Mat33 &operator/=(U uScalar);
		template<class U> Mat33 &operator/=(const Vec3<U> & uVec3);
		template<class U> Mat33 &operator/=(const Mat33<U> & uMat33);
		template<class U> bool operator==(U uScalar) const;
		template<class U> bool operator==(const Vec3<U> & uVec3) const;
		template<class U> bool operator==(const Mat33<U> & uMat33) const;
		template<class U> bool operator!=(U uScalar) const;
		template<class U> bool operator!=(const Vec3<U> & uVec3) const;
		template<class U> bool operator!=(const Mat33<U> & uMat33) const;
		template<class U> operator Mat33<U>() const;

	public:
		Mat33<T> transposed() const;
		static Mat33 zero();
		static Mat33 one();
		static Mat33 identity();
	};

	template<class T, class U> Mat33<T> operator+(const Mat33<T> &tMat33, U uScalar);
	template<class T, class U> Mat33<U> operator+(T tScalar, const Mat33<U> &uMat33);
	template<class T, class U> Mat33<T> operator+(const Mat33<T> &tMat33, const Vec3<U> &uVec3);
	template<class T, class U> Mat33<U> operator+(const Vec3<T> &tVec3, const Mat33<U> &uMat33);
	template<class T> Mat33<T> operator+(const Mat33<T> &tLeft, const Mat33<T> &tRight);
	template<class T, class U> Mat33<T> operator-(const Mat33<T> &tMat33, U uScalar);
	template<class T, class U> Mat33<U> operator-(T tScalar, const Mat33<U> &uMat33);
	template<class T, class U> Mat33<T> operator-(const Mat33<T> &tMat33, const Vec3<U> &uVec3);
	template<class T, class U> Mat33<U> operator-(const Vec3<T> &tVec3, const Mat33<U> &uMat33);
	template<class T> Mat33<T> operator-(const Mat33<T> &tLeft, const Mat33<T> &tRight);
	template<class T, class U> Mat33<T> operator*(const Mat33<T> &tMat33, U uScalar);
	template<class T, class U> Mat33<U> operator*(T tScalar, const Mat33<U> &uMat33);
	template<class T, class U> Mat33<T> operator*(const Mat33<T> &tMat33, const Vec3<U> &uVec3);
	template<class T, class U> Mat33<U> operator*(const Vec3<T> &tVec3, const Mat33<U> &uMat33);
	template<class T> Mat33<T> operator*(const Mat33<T> &tLeft, const Mat33<T> &tRight);
	template<class T, class U> Mat33<T> operator/(const Mat33<T> &tMat33, U uScalar);
	template<class T, class U> Mat33<U> operator/(T tScalar, const Mat33<U> &uMat33);
	template<class T, class U> Mat33<T> operator/(const Mat33<T> &tMat33, const Vec3<U> &uVec3);
	template<class T, class U> Mat33<U> operator/(const Vec3<T> &tVec3, const Mat33<U> &uMat33);
	template<class T> Mat33<T> operator/(const Mat33<T> &tLeft, const Mat33<T> &tRight);
	template<class T, class U> Vec3<T> operator%(const Mat33<T> &tMat33, const Vec3<U> &uVec3);
	template<class T, class U> Vec3<U> operator%(const Vec3<T> &tVec3, const Mat33<U> &uMat33);

	using Mat33i = Mat33<std::int32_t>;
	using Mat33u = Mat33<std::uint32_t>;
	using Mat33f = Mat33<float>;
	using Mat33d = Mat33<double>;
}

#endif