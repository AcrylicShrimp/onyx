
#ifndef _ONYX_TRANSFORM_VEC4_H

#define _ONYX_TRANSFORM_VEC4_H

#include <cstddef>
#include <cstdint>

namespace onyx::transform {
	template<class T>
	class alignas(sizeof(T) * 4) Vec4 final {
	public:
		T tX;
		T tY;
		T tZ;
		T tW;

	public:
		Vec4() noexcept;
		Vec4(T tX, T tY, T tZ, T tW) noexcept;
		Vec4(const Vec4 &sRhs) noexcept = default;
		~Vec4() noexcept				= default;

	public:
		Vec4 &	 operator=(const Vec4 &sRhs) noexcept = default;
		T &		 operator[](std::size_t nIndex) noexcept;
		const T &operator[](std::size_t nIndex) const noexcept;
		Vec4	 operator+() const noexcept;
		Vec4	 operator-() const noexcept;
		Vec4 &	 operator++() noexcept;
		Vec4	 operator++(int) noexcept;
		Vec4 &	 operator--() noexcept;
		Vec4	 operator--(int) noexcept;
		template<class U>
		Vec4 &operator+=(U uRhs) noexcept;
		template<class U>
		Vec4 &operator+=(const Vec4<U> &uRhs) noexcept;
		template<class U>
		Vec4 &operator-=(U uRhs) noexcept;
		template<class U>
		Vec4 &operator-=(const Vec4<U> &uRhs) noexcept;
		template<class U>
		Vec4 &operator*=(U uRhs) noexcept;
		template<class U>
		Vec4 &operator*=(const Vec4<U> &uRhs) noexcept;
		template<class U>
		Vec4 &operator/=(U uRhs) noexcept;
		template<class U>
		Vec4 &operator/=(const Vec4<U> &uRhs) noexcept;
		template<class U>
		bool operator==(U uRhs) const noexcept;
		template<class U>
		bool operator==(const Vec4<U> &uRhs) const noexcept;
		template<class U>
		bool operator!=(U uRhs) const noexcept;
		template<class U>
		bool operator!=(const Vec4<U> &uRhs) const noexcept;
		template<class U>
		operator Vec4<U>() const noexcept;

	public:
		T			length() const;
		T			lengthSquare() const noexcept;
		Vec4		normalized() const;
		static Vec4 zero() noexcept;
		static Vec4 one() noexcept;
		static Vec4 up() noexcept;
		static Vec4 down() noexcept;
		static Vec4 left() noexcept;
		static Vec4 right() noexcept;
		static Vec4 front() noexcept;
		static Vec4 back() noexcept;
		static T	dot(const Vec4<T> &tLhs, const Vec4<T> &tRhs) noexcept;
	};

	template<class T, class U>
	Vec4<T> operator+(const Vec4<T> &tLhs, U uRhs) noexcept;
	template<class T, class U>
	Vec4<U> operator+(T tLhs, const Vec4<U> &uRhs) noexcept;
	template<class T>
	Vec4<T> operator+(const Vec4<T> &tLhs, const Vec4<T> &tRhs) noexcept;
	template<class T, class U>
	Vec4<T> operator-(const Vec4<T> &tLhs, U uRhs) noexcept;
	template<class T, class U>
	Vec4<U> operator-(T tLhs, const Vec4<U> &uRhs) noexcept;
	template<class T>
	Vec4<T> operator-(const Vec4<T> &tLhs, const Vec4<T> &tRhs) noexcept;
	template<class T, class U>
	Vec4<T> operator*(const Vec4<T> &tLhs, U uRhs) noexcept;
	template<class T, class U>
	Vec4<U> operator*(T tLhs, const Vec4<U> &uRhs) noexcept;
	template<class T>
	Vec4<T> operator*(const Vec4<T> &tLhs, const Vec4<T> &tRhs) noexcept;
	template<class T, class U>
	Vec4<T> operator/(const Vec4<T> &tLhs, U uRhs) noexcept;
	template<class T, class U>
	Vec4<U> operator/(T tLhs, const Vec4<U> &uRhs) noexcept;
	template<class T>
	Vec4<T> operator/(const Vec4<T> &tLhs, const Vec4<T> &tRhs) noexcept;

	using Vec4i = Vec4<std::int32_t>;
	using Vec4u = Vec4<std::uint32_t>;
	using Vec4f = Vec4<float>;
	using Vec4d = Vec4<double>;
}	 // namespace onyx::transform

#endif