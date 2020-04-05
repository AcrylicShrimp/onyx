
#ifndef _ONYX_TRANSFORM_MAT22_H

#define _ONYX_TRANSFORM_MAT22_H

#include <cstddef>
#include <cstdint>

namespace onyx::transform {
	template<class T>
	class alignas(sizeof(T) * 2) Mat22 final {
	public:
		Vec2<T> tX;
		Vec2<T> tY;

	public:
		Mat22() noexcept;
		Mat22(Vec2<T> tX, Vec2<T> tY) noexcept;
		Mat22(T tXX, T tXY, T tYX, T tYY) noexcept;
		Mat22(const Mat22 &sSrc) noexcept = default;
		~Mat22() noexcept				  = default;

	public:
		Mat22 &operator=(const Mat22 &sSrc) noexcept = default;

	public:
		Vec2<T> &	   operator[](std::size_t nIndex) noexcept;
		const Vec2<T> &operator[](std::size_t nIndex) const noexcept;
		Mat22		   operator+() const noexcept;
		Mat22		   operator-() const noexcept;
		Mat22 &		   operator++() noexcept;
		Mat22		   operator++(int) noexcept;
		Mat22 &		   operator--() noexcept;
		Mat22		   operator--(int) noexcept;
		template<class U>
		Mat22 &operator+=(U uRhs) noexcept;
		template<class U>
		Mat22 &operator+=(const Vec2<U> &uRhs) noexcept;
		template<class U>
		Mat22 &operator+=(const Mat22<U> &uRhs) noexcept;
		template<class U>
		Mat22 &operator-=(U uRhs) noexcept;
		template<class U>
		Mat22 &operator-=(const Vec2<U> &uRhs) noexcept;
		template<class U>
		Mat22 &operator-=(const Mat22<U> &uRhs) noexcept;
		template<class U>
		Mat22 &operator*=(U uRhs) noexcept;
		template<class U>
		Mat22 &operator*=(const Vec2<U> &uRhs) noexcept;
		template<class U>
		Mat22 &operator*=(const Mat22<U> &uRhs) noexcept;
		template<class U>
		Mat22 &operator/=(U uRhs) noexcept;
		template<class U>
		Mat22 &operator/=(const Vec2<U> &uRhs) noexcept;
		template<class U>
		Mat22 &operator/=(const Mat22<U> &uRhs) noexcept;
		template<class U>
		bool operator==(U uRhs) const noexcept;
		template<class U>
		bool operator==(const Vec2<U> &uRhs) const noexcept;
		template<class U>
		bool operator==(const Mat22<U> &uRhs) const noexcept;
		template<class U>
		bool operator!=(U uRhs) const noexcept;
		template<class U>
		bool operator!=(const Vec2<U> &uRhs) const noexcept;
		template<class U>
		bool operator!=(const Mat22<U> &uRhs) const noexcept;
		template<class U>
		operator Mat22<U>() const noexcept;

	public:
		Mat22		 transposed() const noexcept;
		static Mat22 zero() noexcept;
		static Mat22 one() noexcept;
		static Mat22 identity() noexcept;
	};

	template<class T, class U>
	Mat22<T> operator+(const Mat22<T> &tLhs, U uRhs) noexcept;
	template<class T, class U>
	Mat22<U> operator+(T tLhs, const Mat22<U> &uRhs) noexcept;
	template<class T, class U>
	Mat22<T> operator+(const Mat22<T> &tLhs, const Vec2<U> &uRhs) noexcept;
	template<class T, class U>
	Mat22<U> operator+(const Vec2<T> &tLhs, const Mat22<U> &uRhs) noexcept;
	template<class T>
	Mat22<T> operator+(const Mat22<T> &tLhs, const Mat22<T> &tRhs) noexcept;
	template<class T, class U>
	Mat22<T> operator-(const Mat22<T> &tLhs, U uRhs) noexcept;
	template<class T, class U>
	Mat22<U> operator-(T tLhs, const Mat22<U> &uRhs) noexcept;
	template<class T, class U>
	Mat22<T> operator-(const Mat22<T> &tLhs, const Vec2<U> &uRhs) noexcept;
	template<class T, class U>
	Mat22<U> operator-(const Vec2<T> &tLhs, const Mat22<U> &uRhs) noexcept;
	template<class T>
	Mat22<T> operator-(const Mat22<T> &tLhs, const Mat22<T> &tRhs) noexcept;
	template<class T, class U>
	Mat22<T> operator*(const Mat22<T> &tLhs, U uRhs) noexcept;
	template<class T, class U>
	Mat22<U> operator*(T tLhs, const Mat22<U> &uRhs) noexcept;
	template<class T, class U>
	Mat22<T> operator*(const Mat22<T> &tLhs, const Vec2<U> &uRhs) noexcept;
	template<class T, class U>
	Mat22<U> operator*(const Vec2<T> &tLhs, const Mat22<U> &uRhs) noexcept;
	template<class T>
	Mat22<T> operator*(const Mat22<T> &tLhs, const Mat22<T> &tRhs) noexcept;
	template<class T, class U>
	Mat22<T> operator/(const Mat22<T> &tLhs, U uRhs) noexcept;
	template<class T, class U>
	Mat22<U> operator/(T tLhs, const Mat22<U> &uRhs) noexcept;
	template<class T, class U>
	Mat22<T> operator/(const Mat22<T> &tLhs, const Vec2<U> &uRhs) noexcept;
	template<class T, class U>
	Mat22<U> operator/(const Vec2<T> &tLhs, const Mat22<U> &uRhs) noexcept;
	template<class T>
	Mat22<T> operator/(const Mat22<T> &tLhs, const Mat22<T> &tRhs) noexcept;
	template<class T, class U>
	Vec2<T> operator%(const Mat22<T> &tLhs, const Vec2<U> &uRhs) noexcept;
	template<class T, class U>
	Vec2<U> operator%(const Vec2<T> &tLhs, const Mat22<U> &uRhs) noexcept;

	using Mat22i = Mat22<std::int32_t>;
	using Mat22u = Mat22<std::uint32_t>;
	using Mat22f = Mat22<float>;
	using Mat22d = Mat22<double>;
}	 // namespace onyx::transform

#endif