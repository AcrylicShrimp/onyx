
#ifndef _ONYX_TRANSFORM_VEC3_H

#define _ONYX_TRANSFORM_VEC3_H

#include <cstddef>
#include <cstdint>

namespace onyx::transform {
	template<class T>
	class alignas(sizeof(T) * 4) Vec3 final {
	public:
		T tX;
		T tY;
		T tZ;

	public:
		Vec3() noexcept;
		Vec3(T tX, T tY, T tZ) noexcept;
		Vec3(const Vec3 &sRhs) noexcept = default;
		~Vec3() noexcept				= default;

	public:
		Vec3 &	 operator=(const Vec3 &sRhs) noexcept = default;
		T &		 operator[](std::size_t nIndex) noexcept;
		const T &operator[](std::size_t nIndex) const noexcept;
		Vec3	 operator+() const noexcept;
		Vec3	 operator-() const noexcept;
		Vec3 &	 operator++() noexcept;
		Vec3	 operator++(int) noexcept;
		Vec3 &	 operator--() noexcept;
		Vec3	 operator--(int) noexcept;
		template<class U>
		Vec3 &operator+=(U uRhs) noexcept;
		template<class U>
		Vec3 &operator+=(const Vec3<U> &uRhs) noexcept;
		template<class U>
		Vec3 &operator-=(U uRhs) noexcept;
		template<class U>
		Vec3 &operator-=(const Vec3<U> &uRhs) noexcept;
		template<class U>
		Vec3 &operator*=(U uRhs) noexcept;
		template<class U>
		Vec3 &operator*=(const Vec3<U> &uRhs) noexcept;
		template<class U>
		Vec3 &operator/=(U uRhs) noexcept;
		template<class U>
		Vec3 &operator/=(const Vec3<U> &uRhs) noexcept;
		template<class U>
		bool operator==(U uRhs) const noexcept;
		template<class U>
		bool operator==(const Vec3<U> &uRhs) const noexcept;
		template<class U>
		bool operator!=(U uRhs) const noexcept;
		template<class U>
		bool operator!=(const Vec3<U> &uRhs) const noexcept;
		template<class U>
		operator Vec3<U>() const noexcept;

	public:
		T			   length() const;
		T			   lengthSquare() const noexcept;
		Vec3		   normalized() const;
		static Vec3	   zero() noexcept;
		static Vec3	   one() noexcept;
		static Vec3	   up() noexcept;
		static Vec3	   down() noexcept;
		static Vec3	   left() noexcept;
		static Vec3	   right() noexcept;
		static Vec3	   front() noexcept;
		static Vec3	   back() noexcept;
		static T	   dot(const Vec3<T> &tLhs, const Vec3<T> &tRhs) noexcept;
		static Vec3<T> cross(const Vec3<T> &tLhs, const Vec3<T> &tRhs) noexcept;
	};

	template<class T, class U>
	Vec3<T> operator+(const Vec3<T> &tLhs, U uRhs) noexcept;
	template<class T, class U>
	Vec3<U> operator+(T tLhs, const Vec3<U> &uRhs) noexcept;
	template<class T>
	Vec3<T> operator+(const Vec3<T> &tLhs, const Vec3<T> &tRhs) noexcept;
	template<class T, class U>
	Vec3<T> operator-(const Vec3<T> &tLhs, U uRhs) noexcept;
	template<class T, class U>
	Vec3<U> operator-(T tLhs, const Vec3<U> &uRhs) noexcept;
	template<class T>
	Vec3<T> operator-(const Vec3<T> &tLhs, const Vec3<T> &tRhs) noexcept;
	template<class T, class U>
	Vec3<T> operator*(const Vec3<T> &tLhs, U uRhs) noexcept;
	template<class T, class U>
	Vec3<U> operator*(T tLhs, const Vec3<U> &uRhs) noexcept;
	template<class T>
	Vec3<T> operator*(const Vec3<T> &tLhs, const Vec3<T> &tRhs) noexcept;
	template<class T, class U>
	Vec3<T> operator/(const Vec3<T> &tLhs, U uRhs) noexcept;
	template<class T, class U>
	Vec3<U> operator/(T tLhs, const Vec3<U> &uRhs) noexcept;
	template<class T>
	Vec3<T> operator/(const Vec3<T> &tLhs, const Vec3<T> &tRhs) noexcept;

	using Vec3i = Vec3<std::int32_t>;
	using Vec3u = Vec3<std::uint32_t>;
	using Vec3f = Vec3<float>;
	using Vec3d = Vec3<double>;
}	 // namespace onyx::transform

#endif