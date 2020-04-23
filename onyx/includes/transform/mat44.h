
#ifndef _ONYX_TRANSFORM_MAT44_H

#define _ONYX_TRANSFORM_MAT44_H

#include <cstddef>
#include <cstdint>

namespace onyx::transform {
	template<class T>
	class alignas(sizeof(T) * 4) Mat44 final {
	public:
		Vec4<T> tX;
		Vec4<T> tY;
		Vec4<T> tZ;
		Vec4<T> tW;

	public:
		Mat44() noexcept;
		Mat44(Vec4<T> tX, Vec4<T> tY, Vec4<T> tZ, Vec4<T> tW) noexcept;
		Mat44(
			T tXX,
			T tXY,
			T tXZ,
			T tXW,
			T tYX,
			T tYY,
			T tYZ,
			T tYW,
			T tZX,
			T tZY,
			T tZZ,
			T tZW,
			T tWX,
			T tWY,
			T tWZ,
			T tWW) noexcept;
		Mat44(const Mat44 &sRhs) noexcept = default;
		~Mat44() noexcept				  = default;

	public:
		Mat44 &operator=(const Mat44 &sRhs) noexcept = default;

	public:
		Vec4<T> &	   operator[](std::size_t nIndex) noexcept;
		const Vec4<T> &operator[](std::size_t nIndex) const noexcept;
		Mat44		   operator+() const noexcept;
		Mat44		   operator-() const noexcept;
		Mat44 &		   operator++() noexcept;
		Mat44		   operator++(int) noexcept;
		Mat44 &		   operator--() noexcept;
		Mat44		   operator--(int) noexcept;
		template<class U>
		Mat44 &operator+=(U uRhs) noexcept;
		template<class U>
		Mat44 &operator+=(const Vec4<U> &uRhs) noexcept;
		template<class U>
		Mat44 &operator+=(const Mat44<U> &uRhs) noexcept;
		template<class U>
		Mat44 &operator-=(U uRhs) noexcept;
		template<class U>
		Mat44 &operator-=(const Vec4<U> &uRhs) noexcept;
		template<class U>
		Mat44 &operator-=(const Mat44<U> &uRhs) noexcept;
		template<class U>
		Mat44 &operator*=(U uRhs) noexcept;
		template<class U>
		Mat44 &operator*=(const Vec4<U> &uRhs) noexcept;
		template<class U>
		Mat44 &operator*=(const Mat44<U> &uRhs) noexcept;
		template<class U>
		Mat44 &operator/=(U uRhs) noexcept;
		template<class U>
		Mat44 &operator/=(const Vec4<U> &uRhs) noexcept;
		template<class U>
		Mat44 &operator/=(const Mat44<U> &uRhs) noexcept;
		template<class U>
		bool operator==(U uRhs) const noexcept;
		template<class U>
		bool operator==(const Vec4<U> &uRhs) const noexcept;
		template<class U>
		bool operator==(const Mat44<U> &uRhs) const noexcept;
		template<class U>
		bool operator!=(U uRhs) const noexcept;
		template<class U>
		bool operator!=(const Vec4<U> &uRhs) const noexcept;
		template<class U>
		bool operator!=(const Mat44<U> &uRhs) const noexcept;
		template<class U>
		operator Mat44<U>() const noexcept;

	public:
		Mat44<T>	 transposed() const noexcept;
		static Mat44 zero() noexcept;
		static Mat44 one() noexcept;
		static Mat44 identity() noexcept;
	};

	template<class T, class U>
	Mat44<T> operator+(const Mat44<T> &tLhs, U uRhs) noexcept;
	template<class T, class U>
	Mat44<U> operator+(T tLhs, const Mat44<U> &uRhs) noexcept;
	template<class T, class U>
	Mat44<T> operator+(const Mat44<T> &tLhs, const Vec4<U> &uRhs) noexcept;
	template<class T, class U>
	Mat44<U> operator+(const Vec4<T> &tLhs, const Mat44<U> &uRhs) noexcept;
	template<class T>
	Mat44<T> operator+(const Mat44<T> &tLhs, const Mat44<T> &tRhs) noexcept;
	template<class T, class U>
	Mat44<T> operator-(const Mat44<T> &tLhs, U uRhs) noexcept;
	template<class T, class U>
	Mat44<U> operator-(T tLhs, const Mat44<U> &uRhs) noexcept;
	template<class T, class U>
	Mat44<T> operator-(const Mat44<T> &tLhs, const Vec4<U> &uRhs) noexcept;
	template<class T, class U>
	Mat44<U> operator-(const Vec4<T> &tLhs, const Mat44<U> &uRhs) noexcept;
	template<class T>
	Mat44<T> operator-(const Mat44<T> &tLhs, const Mat44<T> &tRhs) noexcept;
	template<class T, class U>
	Mat44<T> operator*(const Mat44<T> &tLhs, U uRhs) noexcept;
	template<class T, class U>
	Mat44<U> operator*(T tLhs, const Mat44<U> &uRhs) noexcept;
	template<class T, class U>
	Mat44<T> operator*(const Mat44<T> &tLhs, const Vec4<U> &uRhs) noexcept;
	template<class T, class U>
	Mat44<U> operator*(const Vec4<T> &tLhs, const Mat44<U> &uRhs) noexcept;
	template<class T>
	Mat44<T> operator*(const Mat44<T> &tLhs, const Mat44<T> &tRhs) noexcept;
	template<class T, class U>
	Mat44<T> operator/(const Mat44<T> &tLhs, U uRhs) noexcept;
	template<class T, class U>
	Mat44<U> operator/(T tLhs, const Mat44<U> &uRhs) noexcept;
	template<class T, class U>
	Mat44<T> operator/(const Mat44<T> &tLhs, const Vec4<U> &uRhs) noexcept;
	template<class T, class U>
	Mat44<U> operator/(const Vec4<T> &tLhs, const Mat44<U> &uRhs) noexcept;
	template<class T>
	Mat44<T> operator/(const Mat44<T> &tLhs, const Mat44<T> &tRhs) noexcept;
	template<class T, class U>
	Vec4<T> operator%(const Mat44<T> &tLhs, const Vec4<U> &uRhs) noexcept;
	template<class T, class U>
	Vec4<U> operator%(const Vec4<T> &tLhs, const Mat44<U> &uRhs) noexcept;

	using Mat44i = Mat44<std::int32_t>;
	using Mat44u = Mat44<std::uint32_t>;
	using Mat44f = Mat44<float>;
	using Mat44d = Mat44<double>;
}	 // namespace onyx::transform

#endif