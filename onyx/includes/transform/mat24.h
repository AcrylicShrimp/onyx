
#ifndef _ONYX_TRANSFORM_MAT24_H

#define _ONYX_TRANSFORM_MAT24_H

#include <cstddef>
#include <cstdint>

namespace onyx::transform {
	template<class T>
	class Mat42;
}

namespace onyx::transform {
	template<class T>
	class alignas(sizeof(T) * 4) Mat24 final {
	public:
		Vec4<T> tX;
		Vec4<T> tY;

	public:
		Mat24() noexcept;
		Mat24(Vec4<T> tX, Vec4<T> tY) noexcept;
		Mat24(T tXX, T tXY, T tXZ, T tXW, T tYX, T tYY, T tYZ, T tYW) noexcept;
		Mat24(const Mat24 &sRhs) noexcept = default;
		~Mat24() noexcept				  = default;

	public:
		Mat24 &operator=(const Mat24 &sRhs) noexcept = default;

	public:
		Vec4<T> &	   operator[](std::size_t nIndex) noexcept;
		const Vec4<T> &operator[](std::size_t nIndex) const noexcept;
		Mat24		   operator+() const noexcept;
		Mat24		   operator-() const noexcept;
		Mat24 &		   operator++() noexcept;
		Mat24		   operator++(int) noexcept;
		Mat24 &		   operator--() noexcept;
		Mat24		   operator--(int) noexcept;
		template<class U>
		Mat24 &operator+=(U uRhs) noexcept;
		template<class U>
		Mat24 &operator+=(const Vec4<U> &uRhs) noexcept;
		template<class U>
		Mat24 &operator+=(const Mat24<U> &uRhs) noexcept;
		template<class U>
		Mat24 &operator-=(U uRhs) noexcept;
		template<class U>
		Mat24 &operator-=(const Vec4<U> &uRhs) noexcept;
		template<class U>
		Mat24 &operator-=(const Mat24<U> &uRhs) noexcept;
		template<class U>
		Mat24 &operator*=(U uRhs) noexcept;
		template<class U>
		Mat24 &operator*=(const Vec4<U> &uRhs) noexcept;
		template<class U>
		Mat24 &operator*=(const Mat24<U> &uRhs) noexcept;
		template<class U>
		Mat24 &operator/=(U uRhs) noexcept;
		template<class U>
		Mat24 &operator/=(const Vec4<U> &uRhs) noexcept;
		template<class U>
		Mat24 &operator/=(const Mat24<U> &uRhs) noexcept;
		template<class U>
		bool operator==(U uRhs) const noexcept;
		template<class U>
		bool operator==(const Vec4<U> &uRhs) const noexcept;
		template<class U>
		bool operator==(const Mat24<U> &uRhs) const noexcept;
		template<class U>
		bool operator!=(U uRhs) const noexcept;
		template<class U>
		bool operator!=(const Vec4<U> &uRhs) const noexcept;
		template<class U>
		bool operator!=(const Mat24<U> &uRhs) const noexcept;
		template<class U>
		operator Mat24<U>() const noexcept;

	public:
		Mat42<T>	 transposed() const noexcept;
		static Mat24 zero() noexcept;
		static Mat24 one() noexcept;
	};

	template<class T, class U>
	Mat24<T> operator+(const Mat24<T> &tLhs, U uRhs) noexcept;
	template<class T, class U>
	Mat24<U> operator+(T tLhs, const Mat24<U> &uRhs) noexcept;
	template<class T, class U>
	Mat24<T> operator+(const Mat24<T> &tLhs, const Vec4<U> &uRhs) noexcept;
	template<class T, class U>
	Mat24<U> operator+(const Vec4<T> &tLhs, const Mat24<U> &uRhs) noexcept;
	template<class T>
	Mat24<T> operator+(const Mat24<T> &tLhs, const Mat24<T> &tRhs) noexcept;
	template<class T, class U>
	Mat24<T> operator-(const Mat24<T> &tLhs, U uRhs) noexcept;
	template<class T, class U>
	Mat24<U> operator-(T tLhs, const Mat24<U> &uRhs) noexcept;
	template<class T, class U>
	Mat24<T> operator-(const Mat24<T> &tLhs, const Vec4<U> &uRhs) noexcept;
	template<class T, class U>
	Mat24<U> operator-(const Vec4<T> &tLhs, const Mat24<U> &uRhs) noexcept;
	template<class T>
	Mat24<T> operator-(const Mat24<T> &tLhs, const Mat24<T> &tRhs) noexcept;
	template<class T, class U>
	Mat24<T> operator*(const Mat24<T> &tLhs, U uRhs) noexcept;
	template<class T, class U>
	Mat24<U> operator*(T tLhs, const Mat24<U> &uRhs) noexcept;
	template<class T, class U>
	Mat24<T> operator*(const Mat24<T> &tLhs, const Vec4<U> &uRhs) noexcept;
	template<class T, class U>
	Mat24<U> operator*(const Vec4<T> &tLhs, const Mat24<U> &uRhs) noexcept;
	template<class T>
	Mat24<T> operator*(const Mat24<T> &tLhs, const Mat24<T> &tRhs) noexcept;
	template<class T, class U>
	Mat24<T> operator/(const Mat24<T> &tLhs, U uRhs) noexcept;
	template<class T, class U>
	Mat24<U> operator/(T tLhs, const Mat24<U> &uRhs) noexcept;
	template<class T, class U>
	Mat24<T> operator/(const Mat24<T> &tLhs, const Vec4<U> &uRhs) noexcept;
	template<class T, class U>
	Mat24<U> operator/(const Vec4<T> &tLhs, const Mat24<U> &uRhs) noexcept;
	template<class T>
	Mat24<T> operator/(const Mat24<T> &tLhs, const Mat24<T> &tRhs) noexcept;
	template<class T, class U>
	Vec2<T> operator%(const Mat24<T> &tLhs, const Vec4<U> &uRhs) noexcept;
	template<class T, class U>
	Vec4<U> operator%(const Vec2<T> &tLhs, const Mat24<U> &uRhs) noexcept;

	using Mat24i = Mat24<std::int32_t>;
	using Mat24u = Mat24<std::uint32_t>;
	using Mat24f = Mat24<float>;
	using Mat24d = Mat24<double>;
}	 // namespace onyx::transform

#endif