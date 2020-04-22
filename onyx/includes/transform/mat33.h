
#ifndef _ONYX_TRANSFORM_MAT33_H

#define _ONYX_TRANSFORM_MAT33_H

#include <cstddef>
#include <cstdint>

namespace onyx::transform {
	template<class T>
	class alignas(sizeof(T) * 4) Mat33 final {
	public:
		Vec3<T> tX;
		Vec3<T> tY;
		Vec3<T> tZ;

	public:
		Mat33() noexcept;
		Mat33(Vec3<T> tX, Vec3<T> tY, Vec3<T> tZ) noexcept;
		Mat33(T tXX, T tXY, T tXZ, T tYX, T tYY, T tYZ, T tZX, T tZY, T tZZ) noexcept;
		Mat33(const Mat33 &sRhs) noexcept = default;
		~Mat33() noexcept				  = default;

	public:
		Mat33 &operator=(const Mat33 &sRhs) noexcept = default;

	public:
		Vec3<T> &	   operator[](std::size_t nIndex) noexcept;
		const Vec3<T> &operator[](std::size_t nIndex) const noexcept;
		Mat33		   operator+() const noexcept;
		Mat33		   operator-() const noexcept;
		Mat33 &		   operator++() noexcept;
		Mat33		   operator++(int) noexcept;
		Mat33 &		   operator--() noexcept;
		Mat33		   operator--(int) noexcept;
		template<class U>
		Mat33 &operator+=(U uRhs) noexcept;
		template<class U>
		Mat33 &operator+=(const Vec3<U> &uRhs) noexcept;
		template<class U>
		Mat33 &operator+=(const Mat33<U> &uRhs) noexcept;
		template<class U>
		Mat33 &operator-=(U uRhs) noexcept;
		template<class U>
		Mat33 &operator-=(const Vec3<U> &uRhs) noexcept;
		template<class U>
		Mat33 &operator-=(const Mat33<U> &uRhs) noexcept;
		template<class U>
		Mat33 &operator*=(U uRhs) noexcept;
		template<class U>
		Mat33 &operator*=(const Vec3<U> &uRhs) noexcept;
		template<class U>
		Mat33 &operator*=(const Mat33<U> &uRhs) noexcept;
		template<class U>
		Mat33 &operator/=(U uRhs) noexcept;
		template<class U>
		Mat33 &operator/=(const Vec3<U> &uRhs) noexcept;
		template<class U>
		Mat33 &operator/=(const Mat33<U> &uRhs) noexcept;
		template<class U>
		bool operator==(U uRhs) const noexcept;
		template<class U>
		bool operator==(const Vec3<U> &uRhs) const noexcept;
		template<class U>
		bool operator==(const Mat33<U> &uRhs) const noexcept;
		template<class U>
		bool operator!=(U uRhs) const noexcept;
		template<class U>
		bool operator!=(const Vec3<U> &uRhs) const noexcept;
		template<class U>
		bool operator!=(const Mat33<U> &uRhs) const noexcept;
		template<class U>
		operator Mat33<U>() const noexcept;

	public:
		Mat33<T>	 transposed() const noexcept;
		static Mat33 zero() noexcept;
		static Mat33 one() noexcept;
		static Mat33 identity() noexcept;
	};

	template<class T, class U>
	Mat33<T> operator+(const Mat33<T> &tLhs, U uRhs) noexcept;
	template<class T, class U>
	Mat33<U> operator+(T tLhs, const Mat33<U> &uRhs) noexcept;
	template<class T, class U>
	Mat33<T> operator+(const Mat33<T> &tLhs, const Vec3<U> &uRhs) noexcept;
	template<class T, class U>
	Mat33<U> operator+(const Vec3<T> &tLhs, const Mat33<U> &uRhs) noexcept;
	template<class T>
	Mat33<T> operator+(const Mat33<T> &tLhs, const Mat33<T> &tRhs) noexcept;
	template<class T, class U>
	Mat33<T> operator-(const Mat33<T> &tLhs, U uRhs) noexcept;
	template<class T, class U>
	Mat33<U> operator-(T tLhs, const Mat33<U> &uRhs) noexcept;
	template<class T, class U>
	Mat33<T> operator-(const Mat33<T> &tLhs, const Vec3<U> &uRhs) noexcept;
	template<class T, class U>
	Mat33<U> operator-(const Vec3<T> &tLhs, const Mat33<U> &uRhs) noexcept;
	template<class T>
	Mat33<T> operator-(const Mat33<T> &tLhs, const Mat33<T> &tRhs) noexcept;
	template<class T, class U>
	Mat33<T> operator*(const Mat33<T> &tLhs, U uRhs) noexcept;
	template<class T, class U>
	Mat33<U> operator*(T tLhs, const Mat33<U> &uRhs) noexcept;
	template<class T, class U>
	Mat33<T> operator*(const Mat33<T> &tLhs, const Vec3<U> &uRhs) noexcept;
	template<class T, class U>
	Mat33<U> operator*(const Vec3<T> &tLhs, const Mat33<U> &uRhs) noexcept;
	template<class T>
	Mat33<T> operator*(const Mat33<T> &tLhs, const Mat33<T> &tRhs) noexcept;
	template<class T, class U>
	Mat33<T> operator/(const Mat33<T> &tLhs, U uRhs) noexcept;
	template<class T, class U>
	Mat33<U> operator/(T tLhs, const Mat33<U> &uRhs) noexcept;
	template<class T, class U>
	Mat33<T> operator/(const Mat33<T> &tLhs, const Vec3<U> &uRhs) noexcept;
	template<class T, class U>
	Mat33<U> operator/(const Vec3<T> &tLhs, const Mat33<U> &uRhs) noexcept;
	template<class T>
	Mat33<T> operator/(const Mat33<T> &tLhs, const Mat33<T> &tRhs) noexcept;
	template<class T, class U>
	Vec3<T> operator%(const Mat33<T> &tLhs, const Vec3<U> &uRhs) noexcept;
	template<class T, class U>
	Vec3<U> operator%(const Vec3<T> &tLhs, const Mat33<U> &uRhs) noexcept;

	using Mat33i = Mat33<std::int32_t>;
	using Mat33u = Mat33<std::uint32_t>;
	using Mat33f = Mat33<float>;
	using Mat33d = Mat33<double>;
}	 // namespace onyx::transform

#endif