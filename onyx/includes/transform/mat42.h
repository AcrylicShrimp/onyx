
#ifndef _ONYX_TRANSFORM_MAT42_H

#define _ONYX_TRANSFORM_MAT42_H

#include <cstddef>
#include <cstdint>

namespace onyx::transform {
	template<class T>
	class Mat24;
}

namespace onyx::transform {
	template<class T>
	class alignas(sizeof(T) * 2) Mat42 final {
	public:
		Vec2<T> tX;
		Vec2<T> tY;
		Vec2<T> tZ;
		Vec2<T> tW;

	public:
		Mat42() noexcept;
		Mat42(Vec2<T> tX, Vec2<T> tY, Vec2<T> tZ, Vec2<T> tW) noexcept;
		Mat42(T tXX, T tXY, T tYX, T tYY, T tZX, T tZY, T tWX, T tWY) noexcept;
		Mat42(const Mat42 &sRhs) noexcept = default;
		~Mat42() noexcept				  = default;

	public:
		Mat42 &operator=(const Mat42 &sRhs) noexcept = default;

	public:
		Vec2<T> &	   operator[](std::size_t nIndex) noexcept;
		const Vec2<T> &operator[](std::size_t nIndex) const noexcept;
		Mat42		   operator+() const noexcept;
		Mat42		   operator-() const noexcept;
		Mat42 &		   operator++() noexcept;
		Mat42		   operator++(int) noexcept;
		Mat42 &		   operator--() noexcept;
		Mat42		   operator--(int) noexcept;
		template<class U>
		Mat42 &operator+=(U uRhs) noexcept;
		template<class U>
		Mat42 &operator+=(const Vec2<U> &uRhs) noexcept;
		template<class U>
		Mat42 &operator+=(const Mat42<U> &uRhs) noexcept;
		template<class U>
		Mat42 &operator-=(U uRhs) noexcept;
		template<class U>
		Mat42 &operator-=(const Vec2<U> &uRhs) noexcept;
		template<class U>
		Mat42 &operator-=(const Mat42<U> &uRhs) noexcept;
		template<class U>
		Mat42 &operator*=(U uRhs) noexcept;
		template<class U>
		Mat42 &operator*=(const Vec2<U> &uRhs) noexcept;
		template<class U>
		Mat42 &operator*=(const Mat42<U> &uRhs) noexcept;
		template<class U>
		Mat42 &operator/=(U uRhs) noexcept;
		template<class U>
		Mat42 &operator/=(const Vec2<U> &uRhs) noexcept;
		template<class U>
		Mat42 &operator/=(const Mat42<U> &uRhs) noexcept;
		template<class U>
		bool operator==(U uRhs) const noexcept;
		template<class U>
		bool operator==(const Vec2<U> &uRhs) const noexcept;
		template<class U>
		bool operator==(const Mat42<U> &uRhs) const noexcept;
		template<class U>
		bool operator!=(U uRhs) const noexcept;
		template<class U>
		bool operator!=(const Vec2<U> &uRhs) const noexcept;
		template<class U>
		bool operator!=(const Mat42<U> &uRhs) const noexcept;
		template<class U>
		operator Mat42<U>() const noexcept;

	public:
		Mat24<T>	 transposed() const noexcept;
		static Mat42 zero() noexcept;
		static Mat42 one() noexcept;
	};

	template<class T, class U>
	Mat42<T> operator+(const Mat42<T> &tLhs, U uRhs) noexcept;
	template<class T, class U>
	Mat42<U> operator+(T tLhs, const Mat42<U> &uRhs) noexcept;
	template<class T, class U>
	Mat42<T> operator+(const Mat42<T> &tLhs, const Vec2<U> &uRhs) noexcept;
	template<class T, class U>
	Mat42<U> operator+(const Vec2<T> &tLhs, const Mat42<U> &uRhs) noexcept;
	template<class T>
	Mat42<T> operator+(const Mat42<T> &tLhs, const Mat42<T> &tRhs) noexcept;
	template<class T, class U>
	Mat42<T> operator-(const Mat42<T> &tLhs, U uRhs) noexcept;
	template<class T, class U>
	Mat42<U> operator-(T tLhs, const Mat42<U> &uRhs) noexcept;
	template<class T, class U>
	Mat42<T> operator-(const Mat42<T> &tLhs, const Vec2<U> &uRhs) noexcept;
	template<class T, class U>
	Mat42<U> operator-(const Vec2<T> &tLhs, const Mat42<U> &uRhs) noexcept;
	template<class T>
	Mat42<T> operator-(const Mat42<T> &tLhs, const Mat42<T> &tRhs) noexcept;
	template<class T, class U>
	Mat42<T> operator*(const Mat42<T> &tLhs, U uRhs) noexcept;
	template<class T, class U>
	Mat42<U> operator*(T tLhs, const Mat42<U> &uRhs) noexcept;
	template<class T, class U>
	Mat42<T> operator*(const Mat42<T> &tLhs, const Vec2<U> &uRhs) noexcept;
	template<class T, class U>
	Mat42<U> operator*(const Vec2<T> &tLhs, const Mat42<U> &uRhs) noexcept;
	template<class T>
	Mat42<T> operator*(const Mat42<T> &tLhs, const Mat42<T> &tRhs) noexcept;
	template<class T, class U>
	Mat42<T> operator/(const Mat42<T> &tLhs, U uRhs) noexcept;
	template<class T, class U>
	Mat42<U> operator/(T tLhs, const Mat42<U> &uRhs) noexcept;
	template<class T, class U>
	Mat42<T> operator/(const Mat42<T> &tLhs, const Vec2<U> &uRhs) noexcept;
	template<class T, class U>
	Mat42<U> operator/(const Vec2<T> &tLhs, const Mat42<U> &uRhs) noexcept;
	template<class T>
	Mat42<T> operator/(const Mat42<T> &tLhs, const Mat42<T> &tRhs) noexcept;
	template<class T, class U>
	Vec4<T> operator%(const Mat42<T> &tLhs, const Vec2<U> &uRhs) noexcept;
	template<class T, class U>
	Vec2<U> operator%(const Vec4<T> &tLhs, const Mat42<U> &uRhs) noexcept;

	using Mat42i = Mat42<std::int32_t>;
	using Mat42u = Mat42<std::uint32_t>;
	using Mat42f = Mat42<float>;
	using Mat42d = Mat42<double>;
}	 // namespace onyx::transform

#endif