
#ifndef _ONYX_TRANSFORM_MAT23_H

#define _ONYX_TRANSFORM_MAT23_H

#include <cstddef>
#include <cstdint>

namespace onyx::transform {
	template<class T>
	class Mat32;
}

namespace onyx::transform {
	template<class T>
	class alignas(sizeof(T) * 4) Mat23 final {
	public:
		Vec3<T> tX;
		Vec3<T> tY;

	public:
		Mat23() noexcept;
		Mat23(Vec3<T> tX, Vec3<T> tY) noexcept;
		Mat23(T tXX, T tXY, T tXZ, T tYX, T tYY, T tYZ) noexcept;
		Mat23(const Mat23 &sRhs) noexcept = default;
		~Mat23() noexcept				  = default;

	public:
		Mat23 &operator=(const Mat23 &sRhs) noexcept = default;

	public:
		Vec3<T> &	   operator[](std::size_t nIndex) noexcept;
		const Vec3<T> &operator[](std::size_t nIndex) const noexcept;
		Mat23		   operator+() const noexcept;
		Mat23		   operator-() const noexcept;
		Mat23 &		   operator++() noexcept;
		Mat23		   operator++(int) noexcept;
		Mat23 &		   operator--() noexcept;
		Mat23		   operator--(int) noexcept;
		template<class U>
		Mat23 &operator+=(U uRhs) noexcept;
		template<class U>
		Mat23 &operator+=(const Vec3<U> &uRhs) noexcept;
		template<class U>
		Mat23 &operator+=(const Mat23<U> &sRhs) noexcept;
		template<class U>
		Mat23 &operator-=(U uRhs) noexcept;
		template<class U>
		Mat23 &operator-=(const Vec3<U> &uRhs) noexcept;
		template<class U>
		Mat23 &operator-=(const Mat23<U> &sRhs) noexcept;
		template<class U>
		Mat23 &operator*=(U uRhs) noexcept;
		template<class U>
		Mat23 &operator*=(const Vec3<U> &uRhs) noexcept;
		template<class U>
		Mat23 &operator*=(const Mat23<U> &sRhs) noexcept;
		template<class U>
		Mat23 &operator/=(U uRhs) noexcept;
		template<class U>
		Mat23 &operator/=(const Vec3<U> &uRhs) noexcept;
		template<class U>
		Mat23 &operator/=(const Mat23<U> &sRhs) noexcept;
		template<class U>
		bool operator==(U uRhs) const noexcept;
		template<class U>
		bool operator==(const Vec3<U> &uRhs) const noexcept;
		template<class U>
		bool operator==(const Mat23<U> &sRhs) const noexcept;
		template<class U>
		bool operator!=(U uRhs) const noexcept;
		template<class U>
		bool operator!=(const Vec3<U> &uRhs) const noexcept;
		template<class U>
		bool operator!=(const Mat23<U> &sRhs) const noexcept;
		template<class U>
		operator Mat23<U>() const noexcept;

	public:
		Mat32<T>	 transposed() const noexcept;
		static Mat23 zero() noexcept;
		static Mat23 one() noexcept;
	};

	template<class T, class U>
	Mat23<T> operator+(const Mat23<T> &tLhs, U uRhs) noexcept;
	template<class T, class U>
	Mat23<U> operator+(T tLhs, const Mat23<U> &uRhs) noexcept;
	template<class T, class U>
	Mat23<T> operator+(const Mat23<T> &tLhs, const Vec3<U> &uRhs) noexcept;
	template<class T, class U>
	Mat23<U> operator+(const Vec3<T> &tLhs, const Mat23<U> &uRhs) noexcept;
	template<class T>
	Mat23<T> operator+(const Mat23<T> &tLhs, const Mat23<T> &tRhs) noexcept;
	template<class T, class U>
	Mat23<T> operator-(const Mat23<T> &tLhs, U uRhs) noexcept;
	template<class T, class U>
	Mat23<U> operator-(T tLhs, const Mat23<U> &uRhs) noexcept;
	template<class T, class U>
	Mat23<T> operator-(const Mat23<T> &tLhs, const Vec3<U> &uRhs) noexcept;
	template<class T, class U>
	Mat23<U> operator-(const Vec3<T> &tLhs, const Mat23<U> &uRhs) noexcept;
	template<class T>
	Mat23<T> operator-(const Mat23<T> &tLhs, const Mat23<T> &tRhs) noexcept;
	template<class T, class U>
	Mat23<T> operator*(const Mat23<T> &tLhs, U uRhs) noexcept;
	template<class T, class U>
	Mat23<U> operator*(T tLhs, const Mat23<U> &uRhs) noexcept;
	template<class T, class U>
	Mat23<T> operator*(const Mat23<T> &tLhs, const Vec3<U> &uRhs) noexcept;
	template<class T, class U>
	Mat23<U> operator*(const Vec3<T> &tLhs, const Mat23<U> &uRhs) noexcept;
	template<class T>
	Mat23<T> operator*(const Mat23<T> &tLhs, const Mat23<T> &tRhs) noexcept;
	template<class T, class U>
	Mat23<T> operator/(const Mat23<T> &tLhs, U uRhs) noexcept;
	template<class T, class U>
	Mat23<U> operator/(T tLhs, const Mat23<U> &uRhs) noexcept;
	template<class T, class U>
	Mat23<T> operator/(const Mat23<T> &tLhs, const Vec3<U> &uRhs) noexcept;
	template<class T, class U>
	Mat23<U> operator/(const Vec3<T> &tLhs, const Mat23<U> &uRhs) noexcept;
	template<class T>
	Mat23<T> operator/(const Mat23<T> &tLhs, const Mat23<T> &tRhs) noexcept;
	template<class T, class U>
	Vec2<T> operator%(const Mat23<T> &tLhs, const Vec3<U> &uRhs) noexcept;
	template<class T, class U>
	Vec3<U> operator%(const Vec2<T> &tLhs, const Mat23<U> &uRhs) noexcept;

	using Mat23i = Mat23<std::int32_t>;
	using Mat23u = Mat23<std::uint32_t>;
	using Mat23f = Mat23<float>;
	using Mat23d = Mat23<double>;
}	 // namespace onyx::transform

#endif