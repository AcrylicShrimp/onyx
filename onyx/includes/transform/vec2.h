
#ifndef _ONYX_TRANSFORM_VEC2_H

#define _ONYX_TRANSFORM_VEC2_H

#include <cstddef>
#include <cstdint>

namespace onyx::transform {
	template<class T>
	class alignas(sizeof(T) * 2) Vec2 final {
	public:
		T tX;
		T tY;

	public:
		Vec2() noexcept;
		Vec2(T tX, T tY) noexcept;
		Vec2(const Vec2 &sRhs) noexcept = default;
		~Vec2() noexcept				= default;

	public:
		Vec2 &	 operator=(const Vec2 &sRhs) noexcept = default;
		T &		 operator[](std::size_t nIndex) noexcept;
		const T &operator[](std::size_t nIndex) const noexcept;
		Vec2	 operator+() const noexcept;
		Vec2	 operator-() const noexcept;
		Vec2 &	 operator++() noexcept;
		Vec2	 operator++(int) noexcept;
		Vec2 &	 operator--() noexcept;
		Vec2	 operator--(int) noexcept;
		template<class U>
		Vec2 &operator+=(U uRhs) noexcept;
		template<class U>
		Vec2 &operator+=(const Vec2<U> &uRhs) noexcept;
		template<class U>
		Vec2 &operator-=(U uRhs) noexcept;
		template<class U>
		Vec2 &operator-=(const Vec2<U> &uRhs) noexcept;
		template<class U>
		Vec2 &operator*=(U uRhs) noexcept;
		template<class U>
		Vec2 &operator*=(const Vec2<U> &uRhs) noexcept;
		template<class U>
		Vec2 &operator/=(U uRhs) noexcept;
		template<class U>
		Vec2 &operator/=(const Vec2<U> &uRhs) noexcept;
		template<class U>
		bool operator==(U uRhs) const noexcept;
		template<class U>
		bool operator==(const Vec2<U> &uRhs) const noexcept;
		template<class U>
		bool operator!=(U uRhs) const noexcept;
		template<class U>
		bool operator!=(const Vec2<U> &uRhs) const noexcept;
		template<class U>
		operator Vec2<U>() const noexcept;

	public:
		T			length() const;
		T			lengthSquare() const noexcept;
		Vec2		normalized() const;
		static Vec2 zero() noexcept;
		static Vec2 one() noexcept;
		static Vec2 up() noexcept;
		static Vec2 down() noexcept;
		static Vec2 left() noexcept;
		static Vec2 right() noexcept;
		static T	dot(const Vec2<T> &tLhs, const Vec2<T> &tRhs) noexcept;
	};

	template<class T, class U>
	Vec2<T> operator+(const Vec2<T> &tLhs, U uRhs) noexcept;
	template<class T, class U>
	Vec2<U> operator+(T tLhs, const Vec2<U> &uVec2) noexcept;
	template<class T>
	Vec2<T> operator+(const Vec2<T> &tLhs, const Vec2<T> &tRhs) noexcept;
	template<class T, class U>
	Vec2<T> operator-(const Vec2<T> &tLhs, U uRhs) noexcept;
	template<class T, class U>
	Vec2<U> operator-(T tLhs, const Vec2<U> &uVec2) noexcept;
	template<class T>
	Vec2<T> operator-(const Vec2<T> &tLhs, const Vec2<T> &tRhs) noexcept;
	template<class T, class U>
	Vec2<T> operator*(const Vec2<T> &tLhs, U uRhs) noexcept;
	template<class T, class U>
	Vec2<U> operator*(T tLhs, const Vec2<U> &uVec2) noexcept;
	template<class T>
	Vec2<T> operator*(const Vec2<T> &tLhs, const Vec2<T> &tRhs) noexcept;
	template<class T, class U>
	Vec2<T> operator/(const Vec2<T> &tLhs, U uRhs) noexcept;
	template<class T, class U>
	Vec2<U> operator/(T tLhs, const Vec2<U> &uVec2) noexcept;
	template<class T>
	Vec2<T> operator/(const Vec2<T> &tLhs, const Vec2<T> &tRhs) noexcept;

	using Vec2i = Vec2<std::int32_t>;
	using Vec2u = Vec2<std::uint32_t>;
	using Vec2f = Vec2<float>;
	using Vec2d = Vec2<double>;
}	 // namespace onyx::transform

#endif