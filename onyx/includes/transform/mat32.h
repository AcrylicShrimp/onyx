
#ifndef _ONYX_TRANSFORM_MAT32_H

#define _ONYX_TRANSFORM_MAT32_H

#include <cstddef>
#include <cstdint>

namespace onyx::transform {
	template<class T>
	class Mat23;
}

namespace onyx::transform {
	template<class T>
	class alignas(sizeof(T) * 2) Mat32 final {
	public:
		Vec2<T> tX;
		Vec2<T> tY;
		Vec2<T> tZ;

	public:
		Mat32() noexcept;
		Mat32(Vec2<T> tX, Vec2<T> tY, Vec2<T> tZ) noexcept;
		Mat32(T tXX, T tXY, T tYX, T tYY, T tZX, T tZY) noexcept;
		Mat32(const Mat32 &sRhs) noexcept = default;
		~Mat32() noexcept				  = default;

	public:
		Mat32 &operator=(const Mat32 &sRhs) noexcept = default;

	public:
		Vec2<T> &	   operator[](std::size_t nIndex) noexcept;
		const Vec2<T> &operator[](std::size_t nIndex) const noexcept;
		Mat32		   operator+() const noexcept;
		Mat32		   operator-() const noexcept;
		Mat32 &		   operator++() noexcept;
		Mat32		   operator++(int) noexcept;
		Mat32 &		   operator--() noexcept;
		Mat32		   operator--(int) noexcept;
		template<class U>
		Mat32 &operator+=(U uRhs) noexcept;
		template<class U>
		Mat32 &operator+=(const Vec2<U> &uRhs) noexcept;
		template<class U>
		Mat32 &operator+=(const Mat32<U> &uRhs) noexcept;
		template<class U>
		Mat32 &operator-=(U uRhs) noexcept;
		template<class U>
		Mat32 &operator-=(const Vec2<U> &uRhs) noexcept;
		template<class U>
		Mat32 &operator-=(const Mat32<U> &uRhs) noexcept;
		template<class U>
		Mat32 &operator*=(U uRhs) noexcept;
		template<class U>
		Mat32 &operator*=(const Vec2<U> &uRhs) noexcept;
		template<class U>
		Mat32 &operator*=(const Mat32<U> &uRhs) noexcept;
		template<class U>
		Mat32 &operator/=(U uRhs) noexcept;
		template<class U>
		Mat32 &operator/=(const Vec2<U> &uRhs) noexcept;
		template<class U>
		Mat32 &operator/=(const Mat32<U> &uRhs) noexcept;
		template<class U>
		bool operator==(U uRhs) const noexcept;
		template<class U>
		bool operator==(const Vec2<U> &uRhs) const noexcept;
		template<class U>
		bool operator==(const Mat32<U> &uRhs) const noexcept;
		template<class U>
		bool operator!=(U uRhs) const noexcept;
		template<class U>
		bool operator!=(const Vec2<U> &uRhs) const noexcept;
		template<class U>
		bool operator!=(const Mat32<U> &uRhs) const noexcept;
		template<class U>
		operator Mat32<U>() const noexcept;

	public:
		Mat23<T>	 transposed() const noexcept;
		static Mat32 zero() noexcept;
		static Mat32 one() noexcept;
	};

	template<class T, class U>
	Mat32<T> operator+(const Mat32<T> &tLhs, U uRhs) noexcept;
	template<class T, class U>
	Mat32<U> operator+(T tLhs, const Mat32<U> &uRhs) noexcept;
	template<class T, class U>
	Mat32<T> operator+(const Mat32<T> &tLhs, const Vec2<U> &uRhs) noexcept;
	template<class T, class U>
	Mat32<U> operator+(const Vec2<T> &tLhs, const Mat32<U> &uRhs) noexcept;
	template<class T>
	Mat32<T> operator+(const Mat32<T> &tLhs, const Mat32<T> &tRhs) noexcept;
	template<class T, class U>
	Mat32<T> operator-(const Mat32<T> &tLhs, U uRhs) noexcept;
	template<class T, class U>
	Mat32<U> operator-(T tLhs, const Mat32<U> &uRhs) noexcept;
	template<class T, class U>
	Mat32<T> operator-(const Mat32<T> &tLhs, const Vec2<U> &uRhs) noexcept;
	template<class T, class U>
	Mat32<U> operator-(const Vec2<T> &tLhs, const Mat32<U> &uRhs) noexcept;
	template<class T>
	Mat32<T> operator-(const Mat32<T> &tLhs, const Mat32<T> &tRhs) noexcept;
	template<class T, class U>
	Mat32<T> operator*(const Mat32<T> &tLhs, U uRhs) noexcept;
	template<class T, class U>
	Mat32<U> operator*(T tLhs, const Mat32<U> &uRhs) noexcept;
	template<class T, class U>
	Mat32<T> operator*(const Mat32<T> &tLhs, const Vec2<U> &uRhs) noexcept;
	template<class T, class U>
	Mat32<U> operator*(const Vec2<T> &tLhs, const Mat32<U> &uRhs) noexcept;
	template<class T>
	Mat32<T> operator*(const Mat32<T> &tLhs, const Mat32<T> &tRhs) noexcept;
	template<class T, class U>
	Mat32<T> operator/(const Mat32<T> &tLhs, U uRhs) noexcept;
	template<class T, class U>
	Mat32<U> operator/(T tLhs, const Mat32<U> &uRhs) noexcept;
	template<class T, class U>
	Mat32<T> operator/(const Mat32<T> &tLhs, const Vec2<U> &uRhs) noexcept;
	template<class T, class U>
	Mat32<U> operator/(const Vec2<T> &tLhs, const Mat32<U> &uRhs) noexcept;
	template<class T>
	Mat32<T> operator/(const Mat32<T> &tLhs, const Mat32<T> &tRhs) noexcept;
	template<class T, class U>
	Vec3<T> operator%(const Mat32<T> &tLhs, const Vec2<U> &uRhs) noexcept;
	template<class T, class U>
	Vec2<U> operator%(const Vec3<T> &tLhs, const Mat32<U> &uRhs) noexcept;

	using Mat32i = Mat32<std::int32_t>;
	using Mat32u = Mat32<std::uint32_t>;
	using Mat32f = Mat32<float>;
	using Mat32d = Mat32<double>;
}	 // namespace onyx::transform

#endif