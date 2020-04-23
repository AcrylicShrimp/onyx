
#ifndef _ONYX_TRANSFORM_MAT34_H

#define _ONYX_TRANSFORM_MAT34_H

#include <cstddef>
#include <cstdint>

namespace onyx::transform {
	template<class T>
	class Mat43;
}

namespace onyx::transform {
	template<class T>
	class alignas(sizeof(T) * 4) Mat34 final {
	public:
		Vec4<T> tX;
		Vec4<T> tY;
		Vec4<T> tZ;

	public:
		Mat34() noexcept;
		Mat34(Vec4<T> tX, Vec4<T> tY, Vec4<T> tZ) noexcept;
		Mat34(T tXX, T tXY, T tXZ, T tXW, T tYX, T tYY, T tYZ, T tYW, T tZX, T tZY, T tZZ, T tZW) noexcept;
		Mat34(const Mat34 &sRhs) noexcept = default;
		~Mat34() noexcept				  = default;

	public:
		Mat34 &operator=(const Mat34 &sRhs) noexcept = default;

	public:
		Vec4<T> &	   operator[](std::size_t nIndex) noexcept;
		const Vec4<T> &operator[](std::size_t nIndex) const noexcept;
		Mat34		   operator+() const noexcept;
		Mat34		   operator-() const noexcept;
		Mat34 &		   operator++() noexcept;
		Mat34		   operator++(int) noexcept;
		Mat34 &		   operator--() noexcept;
		Mat34		   operator--(int) noexcept;
		template<class U>
		Mat34 &operator+=(U uRhs) noexcept;
		template<class U>
		Mat34 &operator+=(const Vec4<U> &uRhs) noexcept;
		template<class U>
		Mat34 &operator+=(const Mat34<U> &uRhs) noexcept;
		template<class U>
		Mat34 &operator-=(U uRhs) noexcept;
		template<class U>
		Mat34 &operator-=(const Vec4<U> &uRhs) noexcept;
		template<class U>
		Mat34 &operator-=(const Mat34<U> &uRhs) noexcept;
		template<class U>
		Mat34 &operator*=(U uRhs) noexcept;
		template<class U>
		Mat34 &operator*=(const Vec4<U> &uRhs) noexcept;
		template<class U>
		Mat34 &operator*=(const Mat34<U> &uRhs) noexcept;
		template<class U>
		Mat34 &operator/=(U uRhs) noexcept;
		template<class U>
		Mat34 &operator/=(const Vec4<U> &uRhs) noexcept;
		template<class U>
		Mat34 &operator/=(const Mat34<U> &uRhs) noexcept;
		template<class U>
		bool operator==(U uRhs) const noexcept;
		template<class U>
		bool operator==(const Vec4<U> &uRhs) const noexcept;
		template<class U>
		bool operator==(const Mat34<U> &uRhs) const noexcept;
		template<class U>
		bool operator!=(U uRhs) const noexcept;
		template<class U>
		bool operator!=(const Vec4<U> &uRhs) const noexcept;
		template<class U>
		bool operator!=(const Mat34<U> &uRhs) const noexcept;
		template<class U>
		operator Mat34<U>() const noexcept;

	public:
		Mat43<T>	 transposed() const noexcept;
		static Mat34 zero() noexcept;
		static Mat34 one() noexcept;
		static Mat34 identity() noexcept;
	};

	template<class T, class U>
	Mat34<T> operator+(const Mat34<T> &tLhs, U uRhs) noexcept;
	template<class T, class U>
	Mat34<U> operator+(T tLhs, const Mat34<U> &uRhs) noexcept;
	template<class T, class U>
	Mat34<T> operator+(const Mat34<T> &tLhs, const Vec4<U> &uRhs) noexcept;
	template<class T, class U>
	Mat34<U> operator+(const Vec4<T> &tLhs, const Mat34<U> &uRhs) noexcept;
	template<class T>
	Mat34<T> operator+(const Mat34<T> &tLhs, const Mat34<T> &tRhs) noexcept;
	template<class T, class U>
	Mat34<T> operator-(const Mat34<T> &tLhs, U uRhs) noexcept;
	template<class T, class U>
	Mat34<U> operator-(T tLhs, const Mat34<U> &uRhs) noexcept;
	template<class T, class U>
	Mat34<T> operator-(const Mat34<T> &tLhs, const Vec4<U> &uRhs) noexcept;
	template<class T, class U>
	Mat34<U> operator-(const Vec4<T> &tLhs, const Mat34<U> &uRhs) noexcept;
	template<class T>
	Mat34<T> operator-(const Mat34<T> &tLhs, const Mat34<T> &tRhs) noexcept;
	template<class T, class U>
	Mat34<T> operator*(const Mat34<T> &tLhs, U uRhs) noexcept;
	template<class T, class U>
	Mat34<U> operator*(T tLhs, const Mat34<U> &uRhs) noexcept;
	template<class T, class U>
	Mat34<T> operator*(const Mat34<T> &tLhs, const Vec4<U> &uRhs) noexcept;
	template<class T, class U>
	Mat34<U> operator*(const Vec4<T> &tLhs, const Mat34<U> &uRhs) noexcept;
	template<class T>
	Mat34<T> operator*(const Mat34<T> &tLhs, const Mat34<T> &tRhs) noexcept;
	template<class T, class U>
	Mat34<T> operator/(const Mat34<T> &tLhs, U uRhs) noexcept;
	template<class T, class U>
	Mat34<U> operator/(T tLhs, const Mat34<U> &uRhs) noexcept;
	template<class T, class U>
	Mat34<T> operator/(const Mat34<T> &tLhs, const Vec4<U> &uRhs) noexcept;
	template<class T, class U>
	Mat34<U> operator/(const Vec4<T> &tLhs, const Mat34<U> &uRhs) noexcept;
	template<class T>
	Mat34<T> operator/(const Mat34<T> &tLhs, const Mat34<T> &tRhs) noexcept;
	template<class T, class U>
	Vec3<T> operator%(const Mat34<T> &tLhs, const Vec4<U> &uRhs) noexcept;
	template<class T, class U>
	Vec4<U> operator%(const Vec3<T> &tLhs, const Mat34<U> &uRhs) noexcept;

	using Mat34i = Mat34<std::int32_t>;
	using Mat34u = Mat34<std::uint32_t>;
	using Mat34f = Mat34<float>;
	using Mat34d = Mat34<double>;
}	 // namespace onyx::transform

#endif