
#ifndef _ONYX_TRANSFORM_MAT43_H

#define _ONYX_TRANSFORM_MAT43_H

#include <cstddef>
#include <cstdint>

namespace onyx::transform {
	template<class T>
	class Mat34;
}

namespace onyx::transform {
	template<class T>
	class alignas(sizeof(T) * 4) Mat43 final {
	public:
		Vec3<T> tX;
		Vec3<T> tY;
		Vec3<T> tZ;
		Vec3<T> tW;

	public:
		Mat43() noexcept;
		Mat43(Vec3<T> tX, Vec3<T> tY, Vec3<T> tZ, Vec3<T> tW) noexcept;
		Mat43(T tXX, T tXY, T tXZ, T tYX, T tYY, T tYZ, T tZX, T tZY, T tZZ, T tWX, T tWY, T tWZ) noexcept;
		Mat43(const Mat43 &sRhs) noexcept = default;
		~Mat43() noexcept				  = default;

	public:
		Mat43 &operator=(const Mat43 &sRhs) noexcept = default;

	public:
		Vec3<T> &	   operator[](std::size_t nIndex) noexcept;
		const Vec3<T> &operator[](std::size_t nIndex) const noexcept;
		Mat43		   operator+() const noexcept;
		Mat43		   operator-() const noexcept;
		Mat43 &		   operator++() noexcept;
		Mat43		   operator++(int) noexcept;
		Mat43 &		   operator--() noexcept;
		Mat43		   operator--(int) noexcept;
		template<class U>
		Mat43 &operator+=(U uRhs) noexcept;
		template<class U>
		Mat43 &operator+=(const Vec3<U> &uRhs) noexcept;
		template<class U>
		Mat43 &operator+=(const Mat43<U> &uRhs) noexcept;
		template<class U>
		Mat43 &operator-=(U uRhs) noexcept;
		template<class U>
		Mat43 &operator-=(const Vec3<U> &uRhs) noexcept;
		template<class U>
		Mat43 &operator-=(const Mat43<U> &uRhs) noexcept;
		template<class U>
		Mat43 &operator*=(U uRhs) noexcept;
		template<class U>
		Mat43 &operator*=(const Vec3<U> &uRhs) noexcept;
		template<class U>
		Mat43 &operator*=(const Mat43<U> &uRhs) noexcept;
		template<class U>
		Mat43 &operator/=(U uRhs) noexcept;
		template<class U>
		Mat43 &operator/=(const Vec3<U> &uRhs) noexcept;
		template<class U>
		Mat43 &operator/=(const Mat43<U> &uRhs) noexcept;
		template<class U>
		bool operator==(U uRhs) const noexcept;
		template<class U>
		bool operator==(const Vec3<U> &uRhs) const noexcept;
		template<class U>
		bool operator==(const Mat43<U> &uRhs) const noexcept;
		template<class U>
		bool operator!=(U uRhs) const noexcept;
		template<class U>
		bool operator!=(const Vec3<U> &uRhs) const noexcept;
		template<class U>
		bool operator!=(const Mat43<U> &uRhs) const noexcept;
		template<class U>
		operator Mat43<U>() const noexcept;

	public:
		Mat34<T>	 transposed() const noexcept;
		static Mat43 zero() noexcept;
		static Mat43 one() noexcept;
	};

	template<class T, class U>
	Mat43<T> operator+(const Mat43<T> &tLhs, U uRhs) noexcept;
	template<class T, class U>
	Mat43<U> operator+(T tLhs, const Mat43<U> &uRhs) noexcept;
	template<class T, class U>
	Mat43<T> operator+(const Mat43<T> &tLhs, const Vec3<U> &uRhs) noexcept;
	template<class T, class U>
	Mat43<U> operator+(const Vec3<T> &tLhs, const Mat43<U> &uRhs) noexcept;
	template<class T>
	Mat43<T> operator+(const Mat43<T> &tLhs, const Mat43<T> &tRhs) noexcept;
	template<class T, class U>
	Mat43<T> operator-(const Mat43<T> &tLhs, U uRhs) noexcept;
	template<class T, class U>
	Mat43<U> operator-(T tLhs, const Mat43<U> &uRhs) noexcept;
	template<class T, class U>
	Mat43<T> operator-(const Mat43<T> &tLhs, const Vec3<U> &uRhs) noexcept;
	template<class T, class U>
	Mat43<U> operator-(const Vec3<T> &tLhs, const Mat43<U> &uRhs) noexcept;
	template<class T>
	Mat43<T> operator-(const Mat43<T> &tLhs, const Mat43<T> &tRhs) noexcept;
	template<class T, class U>
	Mat43<T> operator*(const Mat43<T> &tLhs, U uRhs) noexcept;
	template<class T, class U>
	Mat43<U> operator*(T tLhs, const Mat43<U> &uRhs) noexcept;
	template<class T, class U>
	Mat43<T> operator*(const Mat43<T> &tLhs, const Vec3<U> &uRhs) noexcept;
	template<class T, class U>
	Mat43<U> operator*(const Vec3<T> &tLhs, const Mat43<U> &uRhs) noexcept;
	template<class T>
	Mat43<T> operator*(const Mat43<T> &tLhs, const Mat43<T> &tRhs) noexcept;
	template<class T, class U>
	Mat43<T> operator/(const Mat43<T> &tLhs, U uRhs) noexcept;
	template<class T, class U>
	Mat43<U> operator/(T tLhs, const Mat43<U> &uRhs) noexcept;
	template<class T, class U>
	Mat43<T> operator/(const Mat43<T> &tLhs, const Vec3<U> &uRhs) noexcept;
	template<class T, class U>
	Mat43<U> operator/(const Vec3<T> &tLhs, const Mat43<U> &uRhs) noexcept;
	template<class T>
	Mat43<T> operator/(const Mat43<T> &tLhs, const Mat43<T> &tRhs) noexcept;
	template<class T, class U>
	Vec4<T> operator%(const Mat43<T> &tLhs, const Vec3<U> &uRhs) noexcept;
	template<class T, class U>
	Vec3<U> operator%(const Vec4<T> &tLhs, const Mat43<U> &uRhs) noexcept;

	using Mat43i = Mat43<std::int32_t>;
	using Mat43u = Mat43<std::uint32_t>;
	using Mat43f = Mat43<float>;
	using Mat43d = Mat43<double>;
}	 // namespace onyx::transform

#endif