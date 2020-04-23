
#ifndef _ONYX_TRANSFORM_MATMUL_HPP

#define _ONYX_TRANSFORM_MATMUL_HPP

namespace onyx::transform {
	template<class T>
	Mat22<T> operator%(const Mat22<T> &tLhs, const Mat22<T> &tRhs)
	{
		return {tLhs.tX.tX * tRhs.tX.tX + tLhs.tX.tY * tRhs.tY.tX,
				tLhs.tX.tX * tRhs.tX.tY + tLhs.tX.tY * tRhs.tY.tY,

				tLhs.tY.tX * tRhs.tX.tX + tLhs.tY.tY * tRhs.tY.tX,
				tLhs.tY.tX * tRhs.tX.tY + tLhs.tY.tY * tRhs.tY.tY};
	}

	template<class T>
	Mat23<T> operator%(const Mat22<T> &tLhs, const Mat23<T> &tRhs)
	{
		return {tLhs.tX.tX * tRhs.tX.tX + tLhs.tX.tY * tRhs.tY.tX,
				tLhs.tX.tX * tRhs.tX.tY + tLhs.tX.tY * tRhs.tY.tY,
				tLhs.tX.tX * tRhs.tX.tZ + tLhs.tX.tY * tRhs.tY.tZ,

				tLhs.tY.tX * tRhs.tX.tX + tLhs.tY.tY * tRhs.tY.tX,
				tLhs.tY.tX * tRhs.tX.tY + tLhs.tY.tY * tRhs.tY.tY,
				tLhs.tY.tX * tRhs.tX.tZ + tLhs.tY.tY * tRhs.tY.tZ};
	}

	template<class T>
	Mat24<T> operator%(const Mat22<T> &tLhs, const Mat24<T> &tRhs)
	{
		return {tLhs.tX.tX * tRhs.tX.tX + tLhs.tX.tY * tRhs.tY.tX,
				tLhs.tX.tX * tRhs.tX.tY + tLhs.tX.tY * tRhs.tY.tY,
				tLhs.tX.tX * tRhs.tX.tZ + tLhs.tX.tY * tRhs.tY.tZ,
				tLhs.tX.tX * tRhs.tX.tW + tLhs.tX.tY * tRhs.tY.tW,

				tLhs.tY.tX * tRhs.tX.tX + tLhs.tY.tY * tRhs.tY.tX,
				tLhs.tY.tX * tRhs.tX.tY + tLhs.tY.tY * tRhs.tY.tY,
				tLhs.tY.tX * tRhs.tX.tZ + tLhs.tY.tY * tRhs.tY.tZ,
				tLhs.tY.tX * tRhs.tX.tW + tLhs.tY.tY * tRhs.tY.tW};
	}

	template<class T>
	Mat22<T> operator%(const Mat23<T> &tLhs, const Mat32<T> &tRhs)
	{
		return {tLhs.tX.tX * tRhs.tX.tX + tLhs.tX.tY * tRhs.tY.tX + tLhs.tX.tZ * tRhs.tZ.tX,
				tLhs.tX.tX * tRhs.tX.tY + tLhs.tX.tY * tRhs.tY.tY + tLhs.tX.tZ * tRhs.tZ.tY,

				tLhs.tY.tX * tRhs.tX.tX + tLhs.tY.tY * tRhs.tY.tX + tLhs.tY.tZ * tRhs.tZ.tX,
				tLhs.tY.tX * tRhs.tX.tY + tLhs.tY.tY * tRhs.tY.tY + tLhs.tY.tZ * tRhs.tZ.tY};
	}

	template<class T>
	Mat23<T> operator%(const Mat23<T> &tLhs, const Mat33<T> &tRhs)
	{
		return {tLhs.tX.tX * tRhs.tX.tX + tLhs.tX.tY * tRhs.tY.tX + tLhs.tX.tZ * tRhs.tZ.tX,
				tLhs.tX.tX * tRhs.tX.tY + tLhs.tX.tY * tRhs.tY.tY + tLhs.tX.tZ * tRhs.tZ.tY,
				tLhs.tX.tX * tRhs.tX.tZ + tLhs.tX.tY * tRhs.tY.tZ + tLhs.tX.tZ * tRhs.tZ.tZ,

				tLhs.tY.tX * tRhs.tX.tX + tLhs.tY.tY * tRhs.tY.tX + tLhs.tY.tZ * tRhs.tZ.tX,
				tLhs.tY.tX * tRhs.tX.tY + tLhs.tY.tY * tRhs.tY.tY + tLhs.tY.tZ * tRhs.tZ.tY,
				tLhs.tY.tX * tRhs.tX.tZ + tLhs.tY.tY * tRhs.tY.tZ + tLhs.tY.tZ * tRhs.tZ.tZ};
	}

	template<class T>
	Mat24<T> operator%(const Mat23<T> &tLhs, const Mat34<T> &tRhs)
	{
		return {tLhs.tX.tX * tRhs.tX.tX + tLhs.tX.tY * tRhs.tY.tX + tLhs.tX.tZ * tRhs.tZ.tX,
				tLhs.tX.tX * tRhs.tX.tY + tLhs.tX.tY * tRhs.tY.tY + tLhs.tX.tZ * tRhs.tZ.tY,
				tLhs.tX.tX * tRhs.tX.tZ + tLhs.tX.tY * tRhs.tY.tZ + tLhs.tX.tZ * tRhs.tZ.tZ,
				tLhs.tX.tX * tRhs.tX.tW + tLhs.tX.tY * tRhs.tY.tW + tLhs.tX.tZ * tRhs.tZ.tW,

				tLhs.tY.tX * tRhs.tX.tX + tLhs.tY.tY * tRhs.tY.tX + tLhs.tY.tZ * tRhs.tZ.tX,
				tLhs.tY.tX * tRhs.tX.tY + tLhs.tY.tY * tRhs.tY.tY + tLhs.tY.tZ * tRhs.tZ.tY,
				tLhs.tY.tX * tRhs.tX.tZ + tLhs.tY.tY * tRhs.tY.tZ + tLhs.tY.tZ * tRhs.tZ.tZ,
				tLhs.tY.tX * tRhs.tX.tW + tLhs.tY.tY * tRhs.tY.tW + tLhs.tY.tZ * tRhs.tZ.tW};
	}

	template<class T>
	Mat22<T> operator%(const Mat24<T> &tLhs, const Mat42<T> &tRhs)
	{
		return {tLhs.tX.tX * tRhs.tX.tX + tLhs.tX.tY * tRhs.tY.tX + tLhs.tX.tZ * tRhs.tZ.tX + tLhs.tX.tW * tRhs.tW.tX,
				tLhs.tX.tX * tRhs.tX.tY + tLhs.tX.tY * tRhs.tY.tY + tLhs.tX.tZ * tRhs.tZ.tY + tLhs.tX.tW * tRhs.tW.tY,

				tLhs.tY.tX * tRhs.tX.tX + tLhs.tY.tY * tRhs.tY.tX + tLhs.tY.tZ * tRhs.tZ.tX + tLhs.tY.tW * tRhs.tW.tX,
				tLhs.tY.tX * tRhs.tX.tY + tLhs.tY.tY * tRhs.tY.tY + tLhs.tY.tZ * tRhs.tZ.tY + tLhs.tY.tW * tRhs.tW.tY};
	}

	template<class T>
	Mat23<T> operator%(const Mat24<T> &tLhs, const Mat43<T> &tRhs)
	{
		return {tLhs.tX.tX * tRhs.tX.tX + tLhs.tX.tY * tRhs.tY.tX + tLhs.tX.tZ * tRhs.tZ.tX + tLhs.tX.tW * tRhs.tW.tX,
				tLhs.tX.tX * tRhs.tX.tY + tLhs.tX.tY * tRhs.tY.tY + tLhs.tX.tZ * tRhs.tZ.tY + tLhs.tX.tW * tRhs.tW.tY,
				tLhs.tX.tX * tRhs.tX.tZ + tLhs.tX.tY * tRhs.tY.tZ + tLhs.tX.tZ * tRhs.tZ.tZ + tLhs.tX.tW * tRhs.tW.tZ,

				tLhs.tY.tX * tRhs.tX.tX + tLhs.tY.tY * tRhs.tY.tX + tLhs.tY.tZ * tRhs.tZ.tX + tLhs.tY.tW * tRhs.tW.tX,
				tLhs.tY.tX * tRhs.tX.tY + tLhs.tY.tY * tRhs.tY.tY + tLhs.tY.tZ * tRhs.tZ.tY + tLhs.tY.tW * tRhs.tW.tY,
				tLhs.tY.tX * tRhs.tX.tZ + tLhs.tY.tY * tRhs.tY.tZ + tLhs.tY.tZ * tRhs.tZ.tZ + tLhs.tY.tW * tRhs.tW.tZ};
	}

	template<class T>
	Mat24<T> operator%(const Mat24<T> &tLhs, const Mat44<T> &tRhs)
	{
		return {tLhs.tX.tX * tRhs.tX.tX + tLhs.tX.tY * tRhs.tY.tX + tLhs.tX.tZ * tRhs.tZ.tX + tLhs.tX.tW * tRhs.tW.tX,
				tLhs.tX.tX * tRhs.tX.tY + tLhs.tX.tY * tRhs.tY.tY + tLhs.tX.tZ * tRhs.tZ.tY + tLhs.tX.tW * tRhs.tW.tY,
				tLhs.tX.tX * tRhs.tX.tZ + tLhs.tX.tY * tRhs.tY.tZ + tLhs.tX.tZ * tRhs.tZ.tZ + tLhs.tX.tW * tRhs.tW.tZ,
				tLhs.tX.tX * tRhs.tX.tW + tLhs.tX.tY * tRhs.tY.tW + tLhs.tX.tZ * tRhs.tZ.tW + tLhs.tX.tW * tRhs.tW.tW,

				tLhs.tY.tX * tRhs.tX.tX + tLhs.tY.tY * tRhs.tY.tX + tLhs.tY.tZ * tRhs.tZ.tX + tLhs.tY.tW * tRhs.tW.tX,
				tLhs.tY.tX * tRhs.tX.tY + tLhs.tY.tY * tRhs.tY.tY + tLhs.tY.tZ * tRhs.tZ.tY + tLhs.tY.tW * tRhs.tW.tY,
				tLhs.tY.tX * tRhs.tX.tZ + tLhs.tY.tY * tRhs.tY.tZ + tLhs.tY.tZ * tRhs.tZ.tZ + tLhs.tY.tW * tRhs.tW.tZ,
				tLhs.tY.tX * tRhs.tX.tW + tLhs.tY.tY * tRhs.tY.tW + tLhs.tY.tZ * tRhs.tZ.tW + tLhs.tY.tW * tRhs.tW.tW};
	}

	template<class T>
	Mat32<T> operator%(const Mat32<T> &tLhs, const Mat22<T> &tRhs)
	{
		return {tLhs.tX.tX * tRhs.tX.tX + tLhs.tX.tY * tRhs.tY.tX,
				tLhs.tX.tX * tRhs.tX.tY + tLhs.tX.tY * tRhs.tY.tY,

				tLhs.tY.tX * tRhs.tX.tX + tLhs.tY.tY * tRhs.tY.tX,
				tLhs.tY.tX * tRhs.tX.tY + tLhs.tY.tY * tRhs.tY.tY,

				tLhs.tZ.tX * tRhs.tX.tX + tLhs.tZ.tY * tRhs.tY.tX,
				tLhs.tZ.tX * tRhs.tX.tY + tLhs.tZ.tY * tRhs.tY.tY};
	}

	template<class T>
	Mat33<T> operator%(const Mat32<T> &tLhs, const Mat23<T> &tRhs)
	{
		return {tLhs.tX.tX * tRhs.tX.tX + tLhs.tX.tY * tRhs.tY.tX,
				tLhs.tX.tX * tRhs.tX.tY + tLhs.tX.tY * tRhs.tY.tY,
				tLhs.tX.tX * tRhs.tX.tZ + tLhs.tX.tY * tRhs.tY.tZ,

				tLhs.tY.tX * tRhs.tX.tX + tLhs.tY.tY * tRhs.tY.tX,
				tLhs.tY.tX * tRhs.tX.tY + tLhs.tY.tY * tRhs.tY.tY,
				tLhs.tY.tX * tRhs.tX.tZ + tLhs.tY.tY * tRhs.tY.tZ,

				tLhs.tZ.tX * tRhs.tX.tX + tLhs.tZ.tY * tRhs.tY.tX,
				tLhs.tZ.tX * tRhs.tX.tY + tLhs.tZ.tY * tRhs.tY.tY,
				tLhs.tZ.tX * tRhs.tX.tZ + tLhs.tZ.tY * tRhs.tY.tZ};
	}

	template<class T>
	Mat34<T> operator%(const Mat32<T> &tLhs, const Mat24<T> &tRhs)
	{
		return {tLhs.tX.tX * tRhs.tX.tX + tLhs.tX.tY * tRhs.tY.tX,
				tLhs.tX.tX * tRhs.tX.tY + tLhs.tX.tY * tRhs.tY.tY,
				tLhs.tX.tX * tRhs.tX.tZ + tLhs.tX.tY * tRhs.tY.tZ,
				tLhs.tX.tX * tRhs.tX.tW + tLhs.tX.tY * tRhs.tY.tW,

				tLhs.tY.tX * tRhs.tX.tX + tLhs.tY.tY * tRhs.tY.tX,
				tLhs.tY.tX * tRhs.tX.tY + tLhs.tY.tY * tRhs.tY.tY,
				tLhs.tY.tX * tRhs.tX.tZ + tLhs.tY.tY * tRhs.tY.tZ,
				tLhs.tY.tX * tRhs.tX.tW + tLhs.tY.tY * tRhs.tY.tW,

				tLhs.tZ.tX * tRhs.tX.tX + tLhs.tZ.tY * tRhs.tY.tX,
				tLhs.tZ.tX * tRhs.tX.tY + tLhs.tZ.tY * tRhs.tY.tY,
				tLhs.tZ.tX * tRhs.tX.tZ + tLhs.tZ.tY * tRhs.tY.tZ,
				tLhs.tZ.tX * tRhs.tX.tW + tLhs.tZ.tY * tRhs.tY.tW};
	}

	template<class T>
	Mat32<T> operator%(const Mat33<T> &tLhs, const Mat32<T> &tRhs)
	{
		return {tLhs.tX.tX * tRhs.tX.tX + tLhs.tX.tY * tRhs.tY.tX + tLhs.tX.tZ * tRhs.tZ.tX,
				tLhs.tX.tX * tRhs.tX.tY + tLhs.tX.tY * tRhs.tY.tY + tLhs.tX.tZ * tRhs.tZ.tY,

				tLhs.tY.tX * tRhs.tX.tX + tLhs.tY.tY * tRhs.tY.tX + tLhs.tY.tZ * tRhs.tZ.tX,
				tLhs.tY.tX * tRhs.tX.tY + tLhs.tY.tY * tRhs.tY.tY + tLhs.tY.tZ * tRhs.tZ.tY,

				tLhs.tZ.tX * tRhs.tX.tX + tLhs.tZ.tY * tRhs.tY.tX + tLhs.tZ.tZ * tRhs.tZ.tX,
				tLhs.tZ.tX * tRhs.tX.tY + tLhs.tZ.tY * tRhs.tY.tY + tLhs.tZ.tZ * tRhs.tZ.tY};
	}

	template<class T>
	Mat33<T> operator%(const Mat33<T> &tLhs, const Mat33<T> &tRhs)
	{
		return {tLhs.tX.tX * tRhs.tX.tX + tLhs.tX.tY * tRhs.tY.tX + tLhs.tX.tZ * tRhs.tZ.tX,
				tLhs.tX.tX * tRhs.tX.tY + tLhs.tX.tY * tRhs.tY.tY + tLhs.tX.tZ * tRhs.tZ.tY,
				tLhs.tX.tX * tRhs.tX.tZ + tLhs.tX.tY * tRhs.tY.tZ + tLhs.tX.tZ * tRhs.tZ.tZ,

				tLhs.tY.tX * tRhs.tX.tX + tLhs.tY.tY * tRhs.tY.tX + tLhs.tY.tZ * tRhs.tZ.tX,
				tLhs.tY.tX * tRhs.tX.tY + tLhs.tY.tY * tRhs.tY.tY + tLhs.tY.tZ * tRhs.tZ.tY,
				tLhs.tY.tX * tRhs.tX.tZ + tLhs.tY.tY * tRhs.tY.tZ + tLhs.tY.tZ * tRhs.tZ.tZ,

				tLhs.tZ.tX * tRhs.tX.tX + tLhs.tZ.tY * tRhs.tY.tX + tLhs.tZ.tZ * tRhs.tZ.tX,
				tLhs.tZ.tX * tRhs.tX.tY + tLhs.tZ.tY * tRhs.tY.tY + tLhs.tZ.tZ * tRhs.tZ.tY,
				tLhs.tZ.tX * tRhs.tX.tZ + tLhs.tZ.tY * tRhs.tY.tZ + tLhs.tZ.tZ * tRhs.tZ.tZ};
	}

	template<class T>
	Mat34<T> operator%(const Mat33<T> &tLhs, const Mat34<T> &tRhs)
	{
		return {tLhs.tX.tX * tRhs.tX.tX + tLhs.tX.tY * tRhs.tY.tX + tLhs.tX.tZ * tRhs.tZ.tX,
				tLhs.tX.tX * tRhs.tX.tY + tLhs.tX.tY * tRhs.tY.tY + tLhs.tX.tZ * tRhs.tZ.tY,
				tLhs.tX.tX * tRhs.tX.tZ + tLhs.tX.tY * tRhs.tY.tZ + tLhs.tX.tZ * tRhs.tZ.tZ,
				tLhs.tX.tX * tRhs.tX.tW + tLhs.tX.tY * tRhs.tY.tW + tLhs.tX.tZ * tRhs.tZ.tW,

				tLhs.tY.tX * tRhs.tX.tX + tLhs.tY.tY * tRhs.tY.tX + tLhs.tY.tZ * tRhs.tZ.tX,
				tLhs.tY.tX * tRhs.tX.tY + tLhs.tY.tY * tRhs.tY.tY + tLhs.tY.tZ * tRhs.tZ.tY,
				tLhs.tY.tX * tRhs.tX.tZ + tLhs.tY.tY * tRhs.tY.tZ + tLhs.tY.tZ * tRhs.tZ.tZ,
				tLhs.tY.tX * tRhs.tX.tW + tLhs.tY.tY * tRhs.tY.tW + tLhs.tY.tZ * tRhs.tZ.tW,

				tLhs.tZ.tX * tRhs.tX.tX + tLhs.tZ.tY * tRhs.tY.tX + tLhs.tZ.tZ * tRhs.tZ.tX,
				tLhs.tZ.tX * tRhs.tX.tY + tLhs.tZ.tY * tRhs.tY.tY + tLhs.tZ.tZ * tRhs.tZ.tY,
				tLhs.tZ.tX * tRhs.tX.tZ + tLhs.tZ.tY * tRhs.tY.tZ + tLhs.tZ.tZ * tRhs.tZ.tZ,
				tLhs.tZ.tX * tRhs.tX.tW + tLhs.tZ.tY * tRhs.tY.tW + tLhs.tZ.tZ * tRhs.tZ.tW};
	}

	template<class T>
	Mat32<T> operator%(const Mat34<T> &tLhs, const Mat42<T> &tRhs)
	{
		return {tLhs.tX.tX * tRhs.tX.tX + tLhs.tX.tY * tRhs.tY.tX + tLhs.tX.tZ * tRhs.tZ.tX + tLhs.tX.tW * tRhs.tW.tX,
				tLhs.tX.tX * tRhs.tX.tY + tLhs.tX.tY * tRhs.tY.tY + tLhs.tX.tZ * tRhs.tZ.tY + tLhs.tX.tW * tRhs.tW.tY,

				tLhs.tY.tX * tRhs.tX.tX + tLhs.tY.tY * tRhs.tY.tX + tLhs.tY.tZ * tRhs.tZ.tX + tLhs.tY.tW * tRhs.tW.tX,
				tLhs.tY.tX * tRhs.tX.tY + tLhs.tY.tY * tRhs.tY.tY + tLhs.tY.tZ * tRhs.tZ.tY + tLhs.tY.tW * tRhs.tW.tY,

				tLhs.tZ.tX * tRhs.tX.tX + tLhs.tZ.tY * tRhs.tY.tX + tLhs.tZ.tZ * tRhs.tZ.tX + tLhs.tZ.tW * tRhs.tW.tX,
				tLhs.tZ.tX * tRhs.tX.tY + tLhs.tZ.tY * tRhs.tY.tY + tLhs.tZ.tZ * tRhs.tZ.tY + tLhs.tZ.tW * tRhs.tW.tY};
	}

	template<class T>
	Mat33<T> operator%(const Mat34<T> &tLhs, const Mat43<T> &tRhs)
	{
		return {tLhs.tX.tX * tRhs.tX.tX + tLhs.tX.tY * tRhs.tY.tX + tLhs.tX.tZ * tRhs.tZ.tX + tLhs.tX.tW * tRhs.tW.tX,
				tLhs.tX.tX * tRhs.tX.tY + tLhs.tX.tY * tRhs.tY.tY + tLhs.tX.tZ * tRhs.tZ.tY + tLhs.tX.tW * tRhs.tW.tY,
				tLhs.tX.tX * tRhs.tX.tZ + tLhs.tX.tY * tRhs.tY.tZ + tLhs.tX.tZ * tRhs.tZ.tZ + tLhs.tX.tW * tRhs.tW.tZ,

				tLhs.tY.tX * tRhs.tX.tX + tLhs.tY.tY * tRhs.tY.tX + tLhs.tY.tZ * tRhs.tZ.tX + tLhs.tY.tW * tRhs.tW.tX,
				tLhs.tY.tX * tRhs.tX.tY + tLhs.tY.tY * tRhs.tY.tY + tLhs.tY.tZ * tRhs.tZ.tY + tLhs.tY.tW * tRhs.tW.tY,
				tLhs.tY.tX * tRhs.tX.tZ + tLhs.tY.tY * tRhs.tY.tZ + tLhs.tY.tZ * tRhs.tZ.tZ + tLhs.tY.tW * tRhs.tW.tZ,

				tLhs.tZ.tX * tRhs.tX.tX + tLhs.tZ.tY * tRhs.tY.tX + tLhs.tZ.tZ * tRhs.tZ.tX + tLhs.tZ.tW * tRhs.tW.tX,
				tLhs.tZ.tX * tRhs.tX.tY + tLhs.tZ.tY * tRhs.tY.tY + tLhs.tZ.tZ * tRhs.tZ.tY + tLhs.tZ.tW * tRhs.tW.tY,
				tLhs.tZ.tX * tRhs.tX.tZ + tLhs.tZ.tY * tRhs.tY.tZ + tLhs.tZ.tZ * tRhs.tZ.tZ + tLhs.tZ.tW * tRhs.tW.tZ};
	}

	template<class T>
	Mat33<T> operator%(const Mat34<T> &tLhs, const Mat44<T> &tRhs)
	{
		return {tLhs.tX.tX * tRhs.tX.tX + tLhs.tX.tY * tRhs.tY.tX + tLhs.tX.tZ * tRhs.tZ.tX + tLhs.tX.tW * tRhs.tW.tX,
				tLhs.tX.tX * tRhs.tX.tY + tLhs.tX.tY * tRhs.tY.tY + tLhs.tX.tZ * tRhs.tZ.tY + tLhs.tX.tW * tRhs.tW.tY,
				tLhs.tX.tX * tRhs.tX.tZ + tLhs.tX.tY * tRhs.tY.tZ + tLhs.tX.tZ * tRhs.tZ.tZ + tLhs.tX.tW * tRhs.tW.tZ,
				tLhs.tX.tX * tRhs.tX.tW + tLhs.tX.tY * tRhs.tY.tW + tLhs.tX.tZ * tRhs.tZ.tW + tLhs.tX.tW * tRhs.tW.tW,

				tLhs.tY.tX * tRhs.tX.tX + tLhs.tY.tY * tRhs.tY.tX + tLhs.tY.tZ * tRhs.tZ.tX + tLhs.tY.tW * tRhs.tW.tX,
				tLhs.tY.tX * tRhs.tX.tY + tLhs.tY.tY * tRhs.tY.tY + tLhs.tY.tZ * tRhs.tZ.tY + tLhs.tY.tW * tRhs.tW.tY,
				tLhs.tY.tX * tRhs.tX.tZ + tLhs.tY.tY * tRhs.tY.tZ + tLhs.tY.tZ * tRhs.tZ.tZ + tLhs.tY.tW * tRhs.tW.tZ,
				tLhs.tY.tX * tRhs.tX.tW + tLhs.tY.tY * tRhs.tY.tW + tLhs.tY.tZ * tRhs.tZ.tW + tLhs.tY.tW * tRhs.tW.tW,

				tLhs.tZ.tX * tRhs.tX.tX + tLhs.tZ.tY * tRhs.tY.tX + tLhs.tZ.tZ * tRhs.tZ.tX + tLhs.tZ.tW * tRhs.tW.tX,
				tLhs.tZ.tX * tRhs.tX.tY + tLhs.tZ.tY * tRhs.tY.tY + tLhs.tZ.tZ * tRhs.tZ.tY + tLhs.tZ.tW * tRhs.tW.tY,
				tLhs.tZ.tX * tRhs.tX.tZ + tLhs.tZ.tY * tRhs.tY.tZ + tLhs.tZ.tZ * tRhs.tZ.tZ + tLhs.tZ.tW * tRhs.tW.tZ,
				tLhs.tZ.tX * tRhs.tX.tW + tLhs.tZ.tY * tRhs.tY.tW + tLhs.tZ.tZ * tRhs.tZ.tW + tLhs.tZ.tW * tRhs.tW.tW};
	}

	template<class T>
	Mat42<T> operator%(const Mat42<T> &tLhs, const Mat22<T> &tRhs)
	{
		return {tLhs.tX.tX * tRhs.tX.tX + tLhs.tX.tY * tRhs.tY.tX,
				tLhs.tX.tX * tRhs.tX.tY + tLhs.tX.tY * tRhs.tY.tY,

				tLhs.tY.tX * tRhs.tX.tX + tLhs.tY.tY * tRhs.tY.tX,
				tLhs.tY.tX * tRhs.tX.tY + tLhs.tY.tY * tRhs.tY.tY,

				tLhs.tZ.tX * tRhs.tX.tX + tLhs.tZ.tY * tRhs.tY.tX,
				tLhs.tZ.tX * tRhs.tX.tY + tLhs.tZ.tY * tRhs.tY.tY,

				tLhs.tW.tX * tRhs.tX.tX + tLhs.tW.tY * tRhs.tY.tX,
				tLhs.tW.tX * tRhs.tX.tY + tLhs.tW.tY * tRhs.tY.tY};
	}

	template<class T>
	Mat43<T> operator%(const Mat42<T> &tLhs, const Mat23<T> &tRhs)
	{
		return {tLhs.tX.tX * tRhs.tX.tX + tLhs.tX.tY * tRhs.tY.tX,
				tLhs.tX.tX * tRhs.tX.tY + tLhs.tX.tY * tRhs.tY.tY,
				tLhs.tX.tX * tRhs.tX.tZ + tLhs.tX.tY * tRhs.tY.tZ,

				tLhs.tY.tX * tRhs.tX.tX + tLhs.tY.tY * tRhs.tY.tX,
				tLhs.tY.tX * tRhs.tX.tY + tLhs.tY.tY * tRhs.tY.tY,
				tLhs.tY.tX * tRhs.tX.tZ + tLhs.tY.tY * tRhs.tY.tZ,

				tLhs.tZ.tX * tRhs.tX.tX + tLhs.tZ.tY * tRhs.tY.tX,
				tLhs.tZ.tX * tRhs.tX.tY + tLhs.tZ.tY * tRhs.tY.tY,
				tLhs.tZ.tX * tRhs.tX.tZ + tLhs.tZ.tY * tRhs.tY.tZ,

				tLhs.tW.tX * tRhs.tX.tX + tLhs.tW.tY * tRhs.tY.tX,
				tLhs.tW.tX * tRhs.tX.tY + tLhs.tW.tY * tRhs.tY.tY,
				tLhs.tW.tX * tRhs.tX.tZ + tLhs.tW.tY * tRhs.tY.tZ};
	}

	template<class T>
	Mat44<T> operator%(const Mat42<T> &tLhs, const Mat24<T> &tRhs)
	{
		return {tLhs.tX.tX * tRhs.tX.tX + tLhs.tX.tY * tRhs.tY.tX,
				tLhs.tX.tX * tRhs.tX.tY + tLhs.tX.tY * tRhs.tY.tY,
				tLhs.tX.tX * tRhs.tX.tZ + tLhs.tX.tY * tRhs.tY.tZ,
				tLhs.tX.tX * tRhs.tX.tW + tLhs.tX.tY * tRhs.tY.tW,

				tLhs.tY.tX * tRhs.tX.tX + tLhs.tY.tY * tRhs.tY.tX,
				tLhs.tY.tX * tRhs.tX.tY + tLhs.tY.tY * tRhs.tY.tY,
				tLhs.tY.tX * tRhs.tX.tZ + tLhs.tY.tY * tRhs.tY.tZ,
				tLhs.tY.tX * tRhs.tX.tW + tLhs.tY.tY * tRhs.tY.tW,

				tLhs.tZ.tX * tRhs.tX.tX + tLhs.tZ.tY * tRhs.tY.tX,
				tLhs.tZ.tX * tRhs.tX.tY + tLhs.tZ.tY * tRhs.tY.tY,
				tLhs.tZ.tX * tRhs.tX.tZ + tLhs.tZ.tY * tRhs.tY.tZ,
				tLhs.tZ.tX * tRhs.tX.tW + tLhs.tZ.tY * tRhs.tY.tW,

				tLhs.tW.tX * tRhs.tX.tX + tLhs.tW.tY * tRhs.tY.tX,
				tLhs.tW.tX * tRhs.tX.tY + tLhs.tW.tY * tRhs.tY.tY,
				tLhs.tW.tX * tRhs.tX.tZ + tLhs.tW.tY * tRhs.tY.tZ,
				tLhs.tW.tX * tRhs.tX.tW + tLhs.tW.tY * tRhs.tY.tW};
	}

	template<class T>
	Mat42<T> operator%(const Mat43<T> &tLhs, const Mat32<T> &tRhs)
	{
		return {tLhs.tX.tX * tRhs.tX.tX + tLhs.tX.tY * tRhs.tY.tX + tLhs.tX.tZ * tRhs.tZ.tX,
				tLhs.tX.tX * tRhs.tX.tY + tLhs.tX.tY * tRhs.tY.tY + tLhs.tX.tZ * tRhs.tZ.tY,

				tLhs.tY.tX * tRhs.tX.tX + tLhs.tY.tY * tRhs.tY.tX + tLhs.tY.tZ * tRhs.tZ.tX,
				tLhs.tY.tX * tRhs.tX.tY + tLhs.tY.tY * tRhs.tY.tY + tLhs.tY.tZ * tRhs.tZ.tY,

				tLhs.tZ.tX * tRhs.tX.tX + tLhs.tZ.tY * tRhs.tY.tX + tLhs.tZ.tZ * tRhs.tZ.tX,
				tLhs.tZ.tX * tRhs.tX.tY + tLhs.tZ.tY * tRhs.tY.tY + tLhs.tZ.tZ * tRhs.tZ.tY,

				tLhs.tW.tX * tRhs.tX.tX + tLhs.tW.tY * tRhs.tY.tX + tLhs.tW.tZ * tRhs.tZ.tX,
				tLhs.tW.tX * tRhs.tX.tY + tLhs.tW.tY * tRhs.tY.tY + tLhs.tW.tZ * tRhs.tZ.tY};
	}

	template<class T>
	Mat43<T> operator%(const Mat43<T> &tLhs, const Mat33<T> &tRhs)
	{
		return {tLhs.tX.tX * tRhs.tX.tX + tLhs.tX.tY * tRhs.tY.tX + tLhs.tX.tZ * tRhs.tZ.tX,
				tLhs.tX.tX * tRhs.tX.tY + tLhs.tX.tY * tRhs.tY.tY + tLhs.tX.tZ * tRhs.tZ.tY,
				tLhs.tX.tX * tRhs.tX.tZ + tLhs.tX.tY * tRhs.tY.tZ + tLhs.tX.tZ * tRhs.tZ.tZ,

				tLhs.tY.tX * tRhs.tX.tX + tLhs.tY.tY * tRhs.tY.tX + tLhs.tY.tZ * tRhs.tZ.tX,
				tLhs.tY.tX * tRhs.tX.tY + tLhs.tY.tY * tRhs.tY.tY + tLhs.tY.tZ * tRhs.tZ.tY,
				tLhs.tY.tX * tRhs.tX.tZ + tLhs.tY.tY * tRhs.tY.tZ + tLhs.tY.tZ * tRhs.tZ.tZ,

				tLhs.tZ.tX * tRhs.tX.tX + tLhs.tZ.tY * tRhs.tY.tX + tLhs.tZ.tZ * tRhs.tZ.tX,
				tLhs.tZ.tX * tRhs.tX.tY + tLhs.tZ.tY * tRhs.tY.tY + tLhs.tZ.tZ * tRhs.tZ.tY,
				tLhs.tZ.tX * tRhs.tX.tZ + tLhs.tZ.tY * tRhs.tY.tZ + tLhs.tZ.tZ * tRhs.tZ.tZ,

				tLhs.tW.tX * tRhs.tX.tX + tLhs.tW.tY * tRhs.tY.tX + tLhs.tW.tZ * tRhs.tZ.tX,
				tLhs.tW.tX * tRhs.tX.tY + tLhs.tW.tY * tRhs.tY.tY + tLhs.tW.tZ * tRhs.tZ.tY,
				tLhs.tW.tX * tRhs.tX.tZ + tLhs.tW.tY * tRhs.tY.tZ + tLhs.tW.tZ * tRhs.tZ.tZ};
	}

	template<class T>
	Mat44<T> operator%(const Mat43<T> &tLhs, const Mat34<T> &tRhs)
	{
		return {tLhs.tX.tX * tRhs.tX.tX + tLhs.tX.tY * tRhs.tY.tX + tLhs.tX.tZ * tRhs.tZ.tX,
				tLhs.tX.tX * tRhs.tX.tY + tLhs.tX.tY * tRhs.tY.tY + tLhs.tX.tZ * tRhs.tZ.tY,
				tLhs.tX.tX * tRhs.tX.tZ + tLhs.tX.tY * tRhs.tY.tZ + tLhs.tX.tZ * tRhs.tZ.tZ,
				tLhs.tX.tX * tRhs.tX.tW + tLhs.tX.tY * tRhs.tY.tW + tLhs.tX.tZ * tRhs.tZ.tW,

				tLhs.tY.tX * tRhs.tX.tX + tLhs.tY.tY * tRhs.tY.tX + tLhs.tY.tZ * tRhs.tZ.tX,
				tLhs.tY.tX * tRhs.tX.tY + tLhs.tY.tY * tRhs.tY.tY + tLhs.tY.tZ * tRhs.tZ.tY,
				tLhs.tY.tX * tRhs.tX.tZ + tLhs.tY.tY * tRhs.tY.tZ + tLhs.tY.tZ * tRhs.tZ.tZ,
				tLhs.tY.tX * tRhs.tX.tW + tLhs.tY.tY * tRhs.tY.tW + tLhs.tY.tZ * tRhs.tZ.tW,

				tLhs.tZ.tX * tRhs.tX.tX + tLhs.tZ.tY * tRhs.tY.tX + tLhs.tZ.tZ * tRhs.tZ.tX,
				tLhs.tZ.tX * tRhs.tX.tY + tLhs.tZ.tY * tRhs.tY.tY + tLhs.tZ.tZ * tRhs.tZ.tY,
				tLhs.tZ.tX * tRhs.tX.tZ + tLhs.tZ.tY * tRhs.tY.tZ + tLhs.tZ.tZ * tRhs.tZ.tZ,
				tLhs.tZ.tX * tRhs.tX.tW + tLhs.tZ.tY * tRhs.tY.tW + tLhs.tZ.tZ * tRhs.tZ.tW,

				tLhs.tW.tX * tRhs.tX.tX + tLhs.tW.tY * tRhs.tY.tX + tLhs.tW.tZ * tRhs.tZ.tX,
				tLhs.tW.tX * tRhs.tX.tY + tLhs.tW.tY * tRhs.tY.tY + tLhs.tW.tZ * tRhs.tZ.tY,
				tLhs.tW.tX * tRhs.tX.tZ + tLhs.tW.tY * tRhs.tY.tZ + tLhs.tW.tZ * tRhs.tZ.tZ,
				tLhs.tW.tX * tRhs.tX.tW + tLhs.tW.tY * tRhs.tY.tW + tLhs.tW.tZ * tRhs.tZ.tW};
	}

	template<class T>
	Mat42<T> operator%(const Mat44<T> &tLhs, const Mat42<T> &tRhs)
	{
		return {tLhs.tX.tX * tRhs.tX.tX + tLhs.tX.tY * tRhs.tY.tX + tLhs.tX.tZ * tRhs.tZ.tX + tLhs.tX.tW * tRhs.tW.tX,
				tLhs.tX.tX * tRhs.tX.tY + tLhs.tX.tY * tRhs.tY.tY + tLhs.tX.tZ * tRhs.tZ.tY + tLhs.tX.tW * tRhs.tW.tY,

				tLhs.tY.tX * tRhs.tX.tX + tLhs.tY.tY * tRhs.tY.tX + tLhs.tY.tZ * tRhs.tZ.tX + tLhs.tY.tW * tRhs.tW.tX,
				tLhs.tY.tX * tRhs.tX.tY + tLhs.tY.tY * tRhs.tY.tY + tLhs.tY.tZ * tRhs.tZ.tY + tLhs.tY.tW * tRhs.tW.tY,

				tLhs.tZ.tX * tRhs.tX.tX + tLhs.tZ.tY * tRhs.tY.tX + tLhs.tZ.tZ * tRhs.tZ.tX + tLhs.tZ.tW * tRhs.tW.tX,
				tLhs.tZ.tX * tRhs.tX.tY + tLhs.tZ.tY * tRhs.tY.tY + tLhs.tZ.tZ * tRhs.tZ.tY + tLhs.tZ.tW * tRhs.tW.tY,

				tLhs.tW.tX * tRhs.tX.tX + tLhs.tW.tY * tRhs.tY.tX + tLhs.tW.tZ * tRhs.tZ.tX + tLhs.tW.tW * tRhs.tW.tX,
				tLhs.tW.tX * tRhs.tX.tY + tLhs.tW.tY * tRhs.tY.tY + tLhs.tW.tZ * tRhs.tZ.tY + tLhs.tW.tW * tRhs.tW.tY};
	}

	template<class T>
	Mat43<T> operator%(const Mat44<T> &tLhs, const Mat43<T> &tRhs)
	{
		return {tLhs.tX.tX * tRhs.tX.tX + tLhs.tX.tY * tRhs.tY.tX + tLhs.tX.tZ * tRhs.tZ.tX + tLhs.tX.tW * tRhs.tW.tX,
				tLhs.tX.tX * tRhs.tX.tY + tLhs.tX.tY * tRhs.tY.tY + tLhs.tX.tZ * tRhs.tZ.tY + tLhs.tX.tW * tRhs.tW.tY,
				tLhs.tX.tX * tRhs.tX.tZ + tLhs.tX.tY * tRhs.tY.tZ + tLhs.tX.tZ * tRhs.tZ.tZ + tLhs.tX.tW * tRhs.tW.tZ,

				tLhs.tY.tX * tRhs.tX.tX + tLhs.tY.tY * tRhs.tY.tX + tLhs.tY.tZ * tRhs.tZ.tX + tLhs.tY.tW * tRhs.tW.tX,
				tLhs.tY.tX * tRhs.tX.tY + tLhs.tY.tY * tRhs.tY.tY + tLhs.tY.tZ * tRhs.tZ.tY + tLhs.tY.tW * tRhs.tW.tY,
				tLhs.tY.tX * tRhs.tX.tZ + tLhs.tY.tY * tRhs.tY.tZ + tLhs.tY.tZ * tRhs.tZ.tZ + tLhs.tY.tW * tRhs.tW.tZ,

				tLhs.tZ.tX * tRhs.tX.tX + tLhs.tZ.tY * tRhs.tY.tX + tLhs.tZ.tZ * tRhs.tZ.tX + tLhs.tZ.tW * tRhs.tW.tX,
				tLhs.tZ.tX * tRhs.tX.tY + tLhs.tZ.tY * tRhs.tY.tY + tLhs.tZ.tZ * tRhs.tZ.tY + tLhs.tZ.tW * tRhs.tW.tY,
				tLhs.tZ.tX * tRhs.tX.tZ + tLhs.tZ.tY * tRhs.tY.tZ + tLhs.tZ.tZ * tRhs.tZ.tZ + tLhs.tZ.tW * tRhs.tW.tZ,

				tLhs.tW.tX * tRhs.tX.tX + tLhs.tW.tY * tRhs.tY.tX + tLhs.tW.tZ * tRhs.tZ.tX + tLhs.tW.tW * tRhs.tW.tX,
				tLhs.tW.tX * tRhs.tX.tY + tLhs.tW.tY * tRhs.tY.tY + tLhs.tW.tZ * tRhs.tZ.tY + tLhs.tW.tW * tRhs.tW.tY,
				tLhs.tW.tX * tRhs.tX.tZ + tLhs.tW.tY * tRhs.tY.tZ + tLhs.tW.tZ * tRhs.tZ.tZ + tLhs.tW.tW * tRhs.tW.tZ};
	}

	template<class T>
	Mat44<T> operator%(const Mat44<T> &tLhs, const Mat44<T> &tRhs)
	{
		return {tLhs.tX.tX * tRhs.tX.tX + tLhs.tX.tY * tRhs.tY.tX + tLhs.tX.tZ * tRhs.tZ.tX + tLhs.tX.tW * tRhs.tW.tX,
				tLhs.tX.tX * tRhs.tX.tY + tLhs.tX.tY * tRhs.tY.tY + tLhs.tX.tZ * tRhs.tZ.tY + tLhs.tX.tW * tRhs.tW.tY,
				tLhs.tX.tX * tRhs.tX.tZ + tLhs.tX.tY * tRhs.tY.tZ + tLhs.tX.tZ * tRhs.tZ.tZ + tLhs.tX.tW * tRhs.tW.tZ,
				tLhs.tX.tX * tRhs.tX.tW + tLhs.tX.tY * tRhs.tY.tW + tLhs.tX.tZ * tRhs.tZ.tW + tLhs.tX.tW * tRhs.tW.tW,

				tLhs.tY.tX * tRhs.tX.tX + tLhs.tY.tY * tRhs.tY.tX + tLhs.tY.tZ * tRhs.tZ.tX + tLhs.tY.tW * tRhs.tW.tX,
				tLhs.tY.tX * tRhs.tX.tY + tLhs.tY.tY * tRhs.tY.tY + tLhs.tY.tZ * tRhs.tZ.tY + tLhs.tY.tW * tRhs.tW.tY,
				tLhs.tY.tX * tRhs.tX.tZ + tLhs.tY.tY * tRhs.tY.tZ + tLhs.tY.tZ * tRhs.tZ.tZ + tLhs.tY.tW * tRhs.tW.tZ,
				tLhs.tY.tX * tRhs.tX.tW + tLhs.tY.tY * tRhs.tY.tW + tLhs.tY.tZ * tRhs.tZ.tW + tLhs.tY.tW * tRhs.tW.tW,

				tLhs.tZ.tX * tRhs.tX.tX + tLhs.tZ.tY * tRhs.tY.tX + tLhs.tZ.tZ * tRhs.tZ.tX + tLhs.tZ.tW * tRhs.tW.tX,
				tLhs.tZ.tX * tRhs.tX.tY + tLhs.tZ.tY * tRhs.tY.tY + tLhs.tZ.tZ * tRhs.tZ.tY + tLhs.tZ.tW * tRhs.tW.tY,
				tLhs.tZ.tX * tRhs.tX.tZ + tLhs.tZ.tY * tRhs.tY.tZ + tLhs.tZ.tZ * tRhs.tZ.tZ + tLhs.tZ.tW * tRhs.tW.tZ,
				tLhs.tZ.tX * tRhs.tX.tW + tLhs.tZ.tY * tRhs.tY.tW + tLhs.tZ.tZ * tRhs.tZ.tW + tLhs.tZ.tW * tRhs.tW.tW,

				tLhs.tW.tX * tRhs.tX.tX + tLhs.tW.tY * tRhs.tY.tX + tLhs.tW.tZ * tRhs.tZ.tX + tLhs.tW.tW * tRhs.tW.tX,
				tLhs.tW.tX * tRhs.tX.tY + tLhs.tW.tY * tRhs.tY.tY + tLhs.tW.tZ * tRhs.tZ.tY + tLhs.tW.tW * tRhs.tW.tY,
				tLhs.tW.tX * tRhs.tX.tZ + tLhs.tW.tY * tRhs.tY.tZ + tLhs.tW.tZ * tRhs.tZ.tZ + tLhs.tW.tW * tRhs.tW.tZ,
				tLhs.tW.tX * tRhs.tX.tW + tLhs.tW.tY * tRhs.tY.tW + tLhs.tW.tZ * tRhs.tZ.tW + tLhs.tW.tW * tRhs.tW.tW};
	}
}	 // namespace onyx::transform

#endif