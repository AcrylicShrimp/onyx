
/*
	2019.06.06
	Created by AcrylicShrimp.
*/

namespace Onyx::Transform
{
	template<class T> Mat22<T> operator%(const Mat22<T> &tLeft, const Mat22<T> &tRight)
	{
		return
		{
			tLeft.tX.tX * tRight.tX.tX + tLeft.tX.tY * tRight.tY.tX,
			tLeft.tX.tX * tRight.tX.tY + tLeft.tX.tY * tRight.tY.tY,

			tLeft.tY.tX * tRight.tX.tX + tLeft.tY.tY * tRight.tY.tX,
			tLeft.tY.tX * tRight.tX.tY + tLeft.tY.tY * tRight.tY.tY
		};
	}

	template<class T> Mat23<T> operator%(const Mat22<T> &tLeft, const Mat23<T> &tRight)
	{
		return
		{
			tLeft.tX.tX * tRight.tX.tX + tLeft.tX.tY * tRight.tY.tX,
			tLeft.tX.tX * tRight.tX.tY + tLeft.tX.tY * tRight.tY.tY,
			tLeft.tX.tX * tRight.tX.tZ + tLeft.tX.tY * tRight.tY.tZ,

			tLeft.tY.tX * tRight.tX.tX + tLeft.tY.tY * tRight.tY.tX,
			tLeft.tY.tX * tRight.tX.tY + tLeft.tY.tY * tRight.tY.tY,
			tLeft.tY.tX * tRight.tX.tZ + tLeft.tY.tY * tRight.tY.tZ
		};
	}

	template<class T> Mat24<T> operator%(const Mat22<T> &tLeft, const Mat24<T> &tRight)
	{
		return
		{
			tLeft.tX.tX * tRight.tX.tX + tLeft.tX.tY * tRight.tY.tX,
			tLeft.tX.tX * tRight.tX.tY + tLeft.tX.tY * tRight.tY.tY,
			tLeft.tX.tX * tRight.tX.tZ + tLeft.tX.tY * tRight.tY.tZ,
			tLeft.tX.tX * tRight.tX.tW + tLeft.tX.tY * tRight.tY.tW,

			tLeft.tY.tX * tRight.tX.tX + tLeft.tY.tY * tRight.tY.tX,
			tLeft.tY.tX * tRight.tX.tY + tLeft.tY.tY * tRight.tY.tY,
			tLeft.tY.tX * tRight.tX.tZ + tLeft.tY.tY * tRight.tY.tZ,
			tLeft.tY.tX * tRight.tX.tW + tLeft.tY.tY * tRight.tY.tW
		};
	}

	template<class T> Mat22<T> operator%(const Mat23<T> &tLeft, const Mat32<T> &tRight)
	{
		return
		{
			tLeft.tX.tX * tRight.tX.tX + tLeft.tX.tY * tRight.tY.tX + tLeft.tX.tZ * tRight.tZ.tX,
			tLeft.tX.tX * tRight.tX.tY + tLeft.tX.tY * tRight.tY.tY + tLeft.tX.tZ * tRight.tZ.tY,

			tLeft.tY.tX * tRight.tX.tX + tLeft.tY.tY * tRight.tY.tX + tLeft.tY.tZ * tRight.tZ.tX,
			tLeft.tY.tX * tRight.tX.tY + tLeft.tY.tY * tRight.tY.tY + tLeft.tY.tZ * tRight.tZ.tY
		};
	}

	template<class T> Mat23<T> operator%(const Mat23<T> &tLeft, const Mat33<T> &tRight)
	{
		return
		{
			tLeft.tX.tX * tRight.tX.tX + tLeft.tX.tY * tRight.tY.tX + tLeft.tX.tZ * tRight.tZ.tX,
			tLeft.tX.tX * tRight.tX.tY + tLeft.tX.tY * tRight.tY.tY + tLeft.tX.tZ * tRight.tZ.tY,
			tLeft.tX.tX * tRight.tX.tZ + tLeft.tX.tY * tRight.tY.tZ + tLeft.tX.tZ * tRight.tZ.tZ,

			tLeft.tY.tX * tRight.tX.tX + tLeft.tY.tY * tRight.tY.tX + tLeft.tY.tZ * tRight.tZ.tX,
			tLeft.tY.tX * tRight.tX.tY + tLeft.tY.tY * tRight.tY.tY + tLeft.tY.tZ * tRight.tZ.tY,
			tLeft.tY.tX * tRight.tX.tZ + tLeft.tY.tY * tRight.tY.tZ + tLeft.tY.tZ * tRight.tZ.tZ
		};
	}

	template<class T> Mat24<T> operator%(const Mat23<T> &tLeft, const Mat34<T> &tRight)
	{
		return
		{
			tLeft.tX.tX * tRight.tX.tX + tLeft.tX.tY * tRight.tY.tX + tLeft.tX.tZ * tRight.tZ.tX,
			tLeft.tX.tX * tRight.tX.tY + tLeft.tX.tY * tRight.tY.tY + tLeft.tX.tZ * tRight.tZ.tY,
			tLeft.tX.tX * tRight.tX.tZ + tLeft.tX.tY * tRight.tY.tZ + tLeft.tX.tZ * tRight.tZ.tZ,
			tLeft.tX.tX * tRight.tX.tW + tLeft.tX.tY * tRight.tY.tW + tLeft.tX.tZ * tRight.tZ.tW,

			tLeft.tY.tX * tRight.tX.tX + tLeft.tY.tY * tRight.tY.tX + tLeft.tY.tZ * tRight.tZ.tX,
			tLeft.tY.tX * tRight.tX.tY + tLeft.tY.tY * tRight.tY.tY + tLeft.tY.tZ * tRight.tZ.tY,
			tLeft.tY.tX * tRight.tX.tZ + tLeft.tY.tY * tRight.tY.tZ + tLeft.tY.tZ * tRight.tZ.tZ,
			tLeft.tY.tX * tRight.tX.tW + tLeft.tY.tY * tRight.tY.tW + tLeft.tY.tZ * tRight.tZ.tW
		};
	}

	template<class T> Mat22<T> operator%(const Mat24<T> &tLeft, const Mat42<T> &tRight)
	{
		return
		{
			tLeft.tX.tX * tRight.tX.tX + tLeft.tX.tY * tRight.tY.tX + tLeft.tX.tZ * tRight.tZ.tX + tLeft.tX.tW * tRight.tW.tX,
			tLeft.tX.tX * tRight.tX.tY + tLeft.tX.tY * tRight.tY.tY + tLeft.tX.tZ * tRight.tZ.tY + tLeft.tX.tW * tRight.tW.tY,

			tLeft.tY.tX * tRight.tX.tX + tLeft.tY.tY * tRight.tY.tX + tLeft.tY.tZ * tRight.tZ.tX + tLeft.tY.tW * tRight.tW.tX,
			tLeft.tY.tX * tRight.tX.tY + tLeft.tY.tY * tRight.tY.tY + tLeft.tY.tZ * tRight.tZ.tY + tLeft.tY.tW * tRight.tW.tY
		};
	}

	template<class T> Mat23<T> operator%(const Mat24<T> &tLeft, const Mat43<T> &tRight)
	{
		return
		{
			tLeft.tX.tX * tRight.tX.tX + tLeft.tX.tY * tRight.tY.tX + tLeft.tX.tZ * tRight.tZ.tX + tLeft.tX.tW * tRight.tW.tX,
			tLeft.tX.tX * tRight.tX.tY + tLeft.tX.tY * tRight.tY.tY + tLeft.tX.tZ * tRight.tZ.tY + tLeft.tX.tW * tRight.tW.tY,
			tLeft.tX.tX * tRight.tX.tZ + tLeft.tX.tY * tRight.tY.tZ + tLeft.tX.tZ * tRight.tZ.tZ + tLeft.tX.tW * tRight.tW.tZ,

			tLeft.tY.tX * tRight.tX.tX + tLeft.tY.tY * tRight.tY.tX + tLeft.tY.tZ * tRight.tZ.tX + tLeft.tY.tW * tRight.tW.tX,
			tLeft.tY.tX * tRight.tX.tY + tLeft.tY.tY * tRight.tY.tY + tLeft.tY.tZ * tRight.tZ.tY + tLeft.tY.tW * tRight.tW.tY,
			tLeft.tY.tX * tRight.tX.tZ + tLeft.tY.tY * tRight.tY.tZ + tLeft.tY.tZ * tRight.tZ.tZ + tLeft.tY.tW * tRight.tW.tZ
		};
	}

	template<class T> Mat24<T> operator%(const Mat24<T> &tLeft, const Mat44<T> &tRight)
	{
		return
		{
			tLeft.tX.tX * tRight.tX.tX + tLeft.tX.tY * tRight.tY.tX + tLeft.tX.tZ * tRight.tZ.tX + tLeft.tX.tW * tRight.tW.tX,
			tLeft.tX.tX * tRight.tX.tY + tLeft.tX.tY * tRight.tY.tY + tLeft.tX.tZ * tRight.tZ.tY + tLeft.tX.tW * tRight.tW.tY,
			tLeft.tX.tX * tRight.tX.tZ + tLeft.tX.tY * tRight.tY.tZ + tLeft.tX.tZ * tRight.tZ.tZ + tLeft.tX.tW * tRight.tW.tZ,
			tLeft.tX.tX * tRight.tX.tW + tLeft.tX.tY * tRight.tY.tW + tLeft.tX.tZ * tRight.tZ.tW + tLeft.tX.tW * tRight.tW.tW,

			tLeft.tY.tX * tRight.tX.tX + tLeft.tY.tY * tRight.tY.tX + tLeft.tY.tZ * tRight.tZ.tX + tLeft.tY.tW * tRight.tW.tX,
			tLeft.tY.tX * tRight.tX.tY + tLeft.tY.tY * tRight.tY.tY + tLeft.tY.tZ * tRight.tZ.tY + tLeft.tY.tW * tRight.tW.tY,
			tLeft.tY.tX * tRight.tX.tZ + tLeft.tY.tY * tRight.tY.tZ + tLeft.tY.tZ * tRight.tZ.tZ + tLeft.tY.tW * tRight.tW.tZ,
			tLeft.tY.tX * tRight.tX.tW + tLeft.tY.tY * tRight.tY.tW + tLeft.tY.tZ * tRight.tZ.tW + tLeft.tY.tW * tRight.tW.tW
		};
	}

	template<class T> Mat32<T> operator%(const Mat32<T> &tLeft, const Mat22<T> &tRight)
	{
		return
		{
			tLeft.tX.tX * tRight.tX.tX + tLeft.tX.tY * tRight.tY.tX,
			tLeft.tX.tX * tRight.tX.tY + tLeft.tX.tY * tRight.tY.tY,

			tLeft.tY.tX * tRight.tX.tX + tLeft.tY.tY * tRight.tY.tX,
			tLeft.tY.tX * tRight.tX.tY + tLeft.tY.tY * tRight.tY.tY,

			tLeft.tZ.tX * tRight.tX.tX + tLeft.tZ.tY * tRight.tY.tX,
			tLeft.tZ.tX * tRight.tX.tY + tLeft.tZ.tY * tRight.tY.tY
		};
	}

	template<class T> Mat33<T> operator%(const Mat32<T> &tLeft, const Mat23<T> &tRight)
	{
		return
		{
			tLeft.tX.tX * tRight.tX.tX + tLeft.tX.tY * tRight.tY.tX,
			tLeft.tX.tX * tRight.tX.tY + tLeft.tX.tY * tRight.tY.tY,
			tLeft.tX.tX * tRight.tX.tZ + tLeft.tX.tY * tRight.tY.tZ,

			tLeft.tY.tX * tRight.tX.tX + tLeft.tY.tY * tRight.tY.tX,
			tLeft.tY.tX * tRight.tX.tY + tLeft.tY.tY * tRight.tY.tY,
			tLeft.tY.tX * tRight.tX.tZ + tLeft.tY.tY * tRight.tY.tZ,

			tLeft.tZ.tX * tRight.tX.tX + tLeft.tZ.tY * tRight.tY.tX,
			tLeft.tZ.tX * tRight.tX.tY + tLeft.tZ.tY * tRight.tY.tY,
			tLeft.tZ.tX * tRight.tX.tZ + tLeft.tZ.tY * tRight.tY.tZ
		};
	}

	template<class T> Mat34<T> operator%(const Mat32<T> &tLeft, const Mat24<T> &tRight)
	{
		return
		{
			tLeft.tX.tX * tRight.tX.tX + tLeft.tX.tY * tRight.tY.tX,
			tLeft.tX.tX * tRight.tX.tY + tLeft.tX.tY * tRight.tY.tY,
			tLeft.tX.tX * tRight.tX.tZ + tLeft.tX.tY * tRight.tY.tZ,
			tLeft.tX.tX * tRight.tX.tW + tLeft.tX.tY * tRight.tY.tW,

			tLeft.tY.tX * tRight.tX.tX + tLeft.tY.tY * tRight.tY.tX,
			tLeft.tY.tX * tRight.tX.tY + tLeft.tY.tY * tRight.tY.tY,
			tLeft.tY.tX * tRight.tX.tZ + tLeft.tY.tY * tRight.tY.tZ,
			tLeft.tY.tX * tRight.tX.tW + tLeft.tY.tY * tRight.tY.tW,

			tLeft.tZ.tX * tRight.tX.tX + tLeft.tZ.tY * tRight.tY.tX,
			tLeft.tZ.tX * tRight.tX.tY + tLeft.tZ.tY * tRight.tY.tY,
			tLeft.tZ.tX * tRight.tX.tZ + tLeft.tZ.tY * tRight.tY.tZ,
			tLeft.tZ.tX * tRight.tX.tW + tLeft.tZ.tY * tRight.tY.tW
		};
	}

	template<class T> Mat32<T> operator%(const Mat33<T> &tLeft, const Mat32<T> &tRight)
	{
		return
		{
			tLeft.tX.tX * tRight.tX.tX + tLeft.tX.tY * tRight.tY.tX + tLeft.tX.tZ * tRight.tY.tX,
			tLeft.tX.tX * tRight.tX.tY + tLeft.tX.tY * tRight.tY.tY + tLeft.tX.tZ * tRight.tY.tY,

			tLeft.tY.tX * tRight.tX.tX + tLeft.tY.tY * tRight.tY.tX + tLeft.tY.tZ * tRight.tY.tX,
			tLeft.tY.tX * tRight.tX.tY + tLeft.tY.tY * tRight.tY.tY + tLeft.tY.tZ * tRight.tY.tY,

			tLeft.tZ.tX * tRight.tX.tX + tLeft.tZ.tY * tRight.tY.tX + tLeft.tZ.tZ * tRight.tY.tX,
			tLeft.tZ.tX * tRight.tX.tY + tLeft.tZ.tY * tRight.tY.tY + tLeft.tZ.tZ * tRight.tY.tY
		};
	}
	
	template<class T> Mat33<T> operator%(const Mat33<T> &tLeft, const Mat33<T> &tRight)
	{
		return
		{
			tLeft.tX.tX * tRight.tX.tX + tLeft.tX.tY * tRight.tY.tX + tLeft.tX.tZ * tRight.tY.tX,
			tLeft.tX.tX * tRight.tX.tY + tLeft.tX.tY * tRight.tY.tY + tLeft.tX.tZ * tRight.tY.tY,
			tLeft.tX.tX * tRight.tX.tZ + tLeft.tX.tY * tRight.tY.tZ + tLeft.tX.tZ * tRight.tY.tZ,

			tLeft.tY.tX * tRight.tX.tX + tLeft.tY.tY * tRight.tY.tX + tLeft.tY.tZ * tRight.tY.tX,
			tLeft.tY.tX * tRight.tX.tY + tLeft.tY.tY * tRight.tY.tY + tLeft.tY.tZ * tRight.tY.tY,
			tLeft.tY.tX * tRight.tX.tZ + tLeft.tY.tY * tRight.tY.tZ + tLeft.tY.tZ * tRight.tY.tZ,

			tLeft.tZ.tX * tRight.tX.tX + tLeft.tZ.tY * tRight.tY.tX + tLeft.tZ.tZ * tRight.tY.tX,
			tLeft.tZ.tX * tRight.tX.tY + tLeft.tZ.tY * tRight.tY.tY + tLeft.tZ.tZ * tRight.tY.tY,
			tLeft.tZ.tX * tRight.tX.tZ + tLeft.tZ.tY * tRight.tY.tZ + tLeft.tZ.tZ * tRight.tY.tZ
		};
	}

	template<class T> Mat34<T> operator%(const Mat33<T> &tLeft, const Mat34<T> &tRight)
	{
		return
		{
			tLeft.tX.tX * tRight.tX.tX + tLeft.tX.tY * tRight.tY.tX + tLeft.tX.tZ * tRight.tY.tX,
			tLeft.tX.tX * tRight.tX.tY + tLeft.tX.tY * tRight.tY.tY + tLeft.tX.tZ * tRight.tY.tY,
			tLeft.tX.tX * tRight.tX.tZ + tLeft.tX.tY * tRight.tY.tZ + tLeft.tX.tZ * tRight.tY.tZ,
			tLeft.tX.tX * tRight.tX.tW + tLeft.tX.tY * tRight.tY.tW + tLeft.tX.tZ * tRight.tY.tW,

			tLeft.tY.tX * tRight.tX.tX + tLeft.tY.tY * tRight.tY.tX + tLeft.tY.tZ * tRight.tY.tX,
			tLeft.tY.tX * tRight.tX.tY + tLeft.tY.tY * tRight.tY.tY + tLeft.tY.tZ * tRight.tY.tY,
			tLeft.tY.tX * tRight.tX.tZ + tLeft.tY.tY * tRight.tY.tZ + tLeft.tY.tZ * tRight.tY.tZ,
			tLeft.tY.tX * tRight.tX.tW + tLeft.tY.tY * tRight.tY.tW + tLeft.tY.tZ * tRight.tY.tW,

			tLeft.tZ.tX * tRight.tX.tX + tLeft.tZ.tY * tRight.tY.tX + tLeft.tZ.tZ * tRight.tY.tX,
			tLeft.tZ.tX * tRight.tX.tY + tLeft.tZ.tY * tRight.tY.tY + tLeft.tZ.tZ * tRight.tY.tY,
			tLeft.tZ.tX * tRight.tX.tZ + tLeft.tZ.tY * tRight.tY.tZ + tLeft.tZ.tZ * tRight.tY.tZ,
			tLeft.tZ.tX * tRight.tX.tW + tLeft.tZ.tY * tRight.tY.tW + tLeft.tZ.tZ * tRight.tY.tW
		};
	}

	template<class T> Mat32<T> operator%(const Mat34<T> &tLeft, const Mat42<T> &tRight)
	{
		return
		{
			tLeft.tX.tX * tRight.tX.tX + tLeft.tX.tY * tRight.tY.tX + tLeft.tX.tZ * tRight.tY.tX + tLeft.tX.tW * tRight.tY.tX,
			tLeft.tX.tX * tRight.tX.tY + tLeft.tX.tY * tRight.tY.tY + tLeft.tX.tZ * tRight.tY.tY + tLeft.tX.tW * tRight.tY.tY,

			tLeft.tY.tX * tRight.tX.tX + tLeft.tY.tY * tRight.tY.tX + tLeft.tY.tZ * tRight.tY.tX + tLeft.tY.tW * tRight.tY.tX,
			tLeft.tY.tX * tRight.tX.tY + tLeft.tY.tY * tRight.tY.tY + tLeft.tY.tZ * tRight.tY.tY + tLeft.tY.tW * tRight.tY.tY,

			tLeft.tZ.tX * tRight.tX.tX + tLeft.tZ.tY * tRight.tY.tX + tLeft.tZ.tZ * tRight.tY.tX + tLeft.tZ.tW * tRight.tY.tX,
			tLeft.tZ.tX * tRight.tX.tY + tLeft.tZ.tY * tRight.tY.tY + tLeft.tZ.tZ * tRight.tY.tY + tLeft.tZ.tW * tRight.tY.tY
		};
	}

	template<class T> Mat33<T> operator%(const Mat34<T> &tLeft, const Mat43<T> &tRight)
	{
		return
		{
			tLeft.tX.tX * tRight.tX.tX + tLeft.tX.tY * tRight.tY.tX + tLeft.tX.tZ * tRight.tY.tX + tLeft.tX.tW * tRight.tY.tX,
			tLeft.tX.tX * tRight.tX.tY + tLeft.tX.tY * tRight.tY.tY + tLeft.tX.tZ * tRight.tY.tY + tLeft.tX.tW * tRight.tY.tY,
			tLeft.tX.tX * tRight.tX.tZ + tLeft.tX.tY * tRight.tY.tZ + tLeft.tX.tZ * tRight.tY.tZ + tLeft.tX.tW * tRight.tY.tZ,

			tLeft.tY.tX * tRight.tX.tX + tLeft.tY.tY * tRight.tY.tX + tLeft.tY.tZ * tRight.tY.tX + tLeft.tY.tW * tRight.tY.tX,
			tLeft.tY.tX * tRight.tX.tY + tLeft.tY.tY * tRight.tY.tY + tLeft.tY.tZ * tRight.tY.tY + tLeft.tY.tW * tRight.tY.tY,
			tLeft.tY.tX * tRight.tX.tZ + tLeft.tY.tY * tRight.tY.tZ + tLeft.tY.tZ * tRight.tY.tZ + tLeft.tY.tW * tRight.tY.tZ,

			tLeft.tZ.tX * tRight.tX.tX + tLeft.tZ.tY * tRight.tY.tX + tLeft.tZ.tZ * tRight.tY.tX + tLeft.tZ.tW * tRight.tY.tX,
			tLeft.tZ.tX * tRight.tX.tY + tLeft.tZ.tY * tRight.tY.tY + tLeft.tZ.tZ * tRight.tY.tY + tLeft.tZ.tW * tRight.tY.tY,
			tLeft.tZ.tX * tRight.tX.tZ + tLeft.tZ.tY * tRight.tY.tZ + tLeft.tZ.tZ * tRight.tY.tZ + tLeft.tZ.tW * tRight.tY.tZ
		};
	}

	template<class T> Mat33<T> operator%(const Mat34<T> &tLeft, const Mat44<T> &tRight)
	{
		return
		{
			tLeft.tX.tX * tRight.tX.tX + tLeft.tX.tY * tRight.tY.tX + tLeft.tX.tZ * tRight.tY.tX + tLeft.tX.tW * tRight.tY.tX,
			tLeft.tX.tX * tRight.tX.tY + tLeft.tX.tY * tRight.tY.tY + tLeft.tX.tZ * tRight.tY.tY + tLeft.tX.tW * tRight.tY.tY,
			tLeft.tX.tX * tRight.tX.tZ + tLeft.tX.tY * tRight.tY.tZ + tLeft.tX.tZ * tRight.tY.tZ + tLeft.tX.tW * tRight.tY.tZ,
			tLeft.tX.tX * tRight.tX.tW + tLeft.tX.tY * tRight.tY.tW + tLeft.tX.tZ * tRight.tY.tW + tLeft.tX.tW * tRight.tY.tW,

			tLeft.tY.tX * tRight.tX.tX + tLeft.tY.tY * tRight.tY.tX + tLeft.tY.tZ * tRight.tY.tX + tLeft.tY.tW * tRight.tY.tX,
			tLeft.tY.tX * tRight.tX.tY + tLeft.tY.tY * tRight.tY.tY + tLeft.tY.tZ * tRight.tY.tY + tLeft.tY.tW * tRight.tY.tY,
			tLeft.tY.tX * tRight.tX.tZ + tLeft.tY.tY * tRight.tY.tZ + tLeft.tY.tZ * tRight.tY.tZ + tLeft.tY.tW * tRight.tY.tZ,
			tLeft.tY.tX * tRight.tX.tW + tLeft.tY.tY * tRight.tY.tW + tLeft.tY.tZ * tRight.tY.tW + tLeft.tY.tW * tRight.tY.tW,

			tLeft.tZ.tX * tRight.tX.tX + tLeft.tZ.tY * tRight.tY.tX + tLeft.tZ.tZ * tRight.tY.tX + tLeft.tZ.tW * tRight.tY.tX,
			tLeft.tZ.tX * tRight.tX.tY + tLeft.tZ.tY * tRight.tY.tY + tLeft.tZ.tZ * tRight.tY.tY + tLeft.tZ.tW * tRight.tY.tY,
			tLeft.tZ.tX * tRight.tX.tZ + tLeft.tZ.tY * tRight.tY.tZ + tLeft.tZ.tZ * tRight.tY.tZ + tLeft.tZ.tW * tRight.tY.tZ,
			tLeft.tZ.tX * tRight.tX.tW + tLeft.tZ.tY * tRight.tY.tW + tLeft.tZ.tZ * tRight.tY.tW + tLeft.tZ.tW * tRight.tY.tW
		};
	}

	template<class T> Mat42<T> operator%(const Mat42<T> &tLeft, const Mat22<T> &tRight)
	{
		return
		{
			tLeft.tX.tX * tRight.tX.tX + tLeft.tX.tY * tRight.tY.tX,
			tLeft.tX.tX * tRight.tX.tY + tLeft.tX.tY * tRight.tY.tY,

			tLeft.tY.tX * tRight.tX.tX + tLeft.tY.tY * tRight.tY.tX,
			tLeft.tY.tX * tRight.tX.tY + tLeft.tY.tY * tRight.tY.tY,

			tLeft.tZ.tX * tRight.tX.tX + tLeft.tZ.tY * tRight.tY.tX,
			tLeft.tZ.tX * tRight.tX.tY + tLeft.tZ.tY * tRight.tY.tY,

			tLeft.tW.tX * tRight.tX.tX + tLeft.tW.tY * tRight.tY.tX,
			tLeft.tW.tX * tRight.tX.tY + tLeft.tW.tY * tRight.tY.tY
		};
	}

	template<class T> Mat43<T> operator%(const Mat42<T> &tLeft, const Mat23<T> &tRight)
	{
		return
		{
			tLeft.tX.tX * tRight.tX.tX + tLeft.tX.tY * tRight.tY.tX,
			tLeft.tX.tX * tRight.tX.tY + tLeft.tX.tY * tRight.tY.tY,
			tLeft.tX.tX * tRight.tX.tZ + tLeft.tX.tY * tRight.tY.tZ,

			tLeft.tY.tX * tRight.tX.tX + tLeft.tY.tY * tRight.tY.tX,
			tLeft.tY.tX * tRight.tX.tY + tLeft.tY.tY * tRight.tY.tY,
			tLeft.tY.tX * tRight.tX.tZ + tLeft.tY.tY * tRight.tY.tZ,

			tLeft.tZ.tX * tRight.tX.tX + tLeft.tZ.tY * tRight.tY.tX,
			tLeft.tZ.tX * tRight.tX.tY + tLeft.tZ.tY * tRight.tY.tY,
			tLeft.tZ.tX * tRight.tX.tZ + tLeft.tZ.tY * tRight.tY.tZ,

			tLeft.tW.tX * tRight.tX.tX + tLeft.tW.tY * tRight.tY.tX,
			tLeft.tW.tX * tRight.tX.tY + tLeft.tW.tY * tRight.tY.tY,
			tLeft.tW.tX * tRight.tX.tZ + tLeft.tW.tY * tRight.tY.tZ
		};
	}

	template<class T> Mat44<T> operator%(const Mat42<T> &tLeft, const Mat24<T> &tRight)
	{
		return
		{
			tLeft.tX.tX * tRight.tX.tX + tLeft.tX.tY * tRight.tY.tX,
			tLeft.tX.tX * tRight.tX.tY + tLeft.tX.tY * tRight.tY.tY,
			tLeft.tX.tX * tRight.tX.tZ + tLeft.tX.tY * tRight.tY.tZ,
			tLeft.tX.tX * tRight.tX.tW + tLeft.tX.tY * tRight.tY.tW,

			tLeft.tY.tX * tRight.tX.tX + tLeft.tY.tY * tRight.tY.tX,
			tLeft.tY.tX * tRight.tX.tY + tLeft.tY.tY * tRight.tY.tY,
			tLeft.tY.tX * tRight.tX.tZ + tLeft.tY.tY * tRight.tY.tZ,
			tLeft.tY.tX * tRight.tX.tW + tLeft.tY.tY * tRight.tY.tW,

			tLeft.tZ.tX * tRight.tX.tX + tLeft.tZ.tY * tRight.tY.tX,
			tLeft.tZ.tX * tRight.tX.tY + tLeft.tZ.tY * tRight.tY.tY,
			tLeft.tZ.tX * tRight.tX.tZ + tLeft.tZ.tY * tRight.tY.tZ,
			tLeft.tZ.tX * tRight.tX.tW + tLeft.tZ.tY * tRight.tY.tW,

			tLeft.tW.tX * tRight.tX.tX + tLeft.tW.tY * tRight.tY.tX,
			tLeft.tW.tX * tRight.tX.tY + tLeft.tW.tY * tRight.tY.tY,
			tLeft.tW.tX * tRight.tX.tZ + tLeft.tW.tY * tRight.tY.tZ,
			tLeft.tW.tX * tRight.tX.tW + tLeft.tW.tY * tRight.tY.tW
		};
	}

	template<class T> Mat42<T> operator%(const Mat43<T> &tLeft, const Mat32<T> &tRight)
	{
		return
		{
			tLeft.tX.tX * tRight.tX.tX + tLeft.tX.tY * tRight.tY.tX + tLeft.tX.tZ * tRight.tY.tX,
			tLeft.tX.tX * tRight.tX.tY + tLeft.tX.tY * tRight.tY.tY + tLeft.tX.tZ * tRight.tY.tY,

			tLeft.tY.tX * tRight.tX.tX + tLeft.tY.tY * tRight.tY.tX + tLeft.tY.tZ * tRight.tY.tX,
			tLeft.tY.tX * tRight.tX.tY + tLeft.tY.tY * tRight.tY.tY + tLeft.tY.tZ * tRight.tY.tY,

			tLeft.tZ.tX * tRight.tX.tX + tLeft.tZ.tY * tRight.tY.tX + tLeft.tZ.tZ * tRight.tY.tX,
			tLeft.tZ.tX * tRight.tX.tY + tLeft.tZ.tY * tRight.tY.tY + tLeft.tZ.tZ * tRight.tY.tY,

			tLeft.tW.tX * tRight.tX.tX + tLeft.tW.tY * tRight.tY.tX + tLeft.tW.tZ * tRight.tY.tX,
			tLeft.tW.tX * tRight.tX.tY + tLeft.tW.tY * tRight.tY.tY + tLeft.tW.tZ * tRight.tY.tY
		};
	}

	template<class T> Mat43<T> operator%(const Mat43<T> &tLeft, const Mat33<T> &tRight)
	{
		return
		{
			tLeft.tX.tX * tRight.tX.tX + tLeft.tX.tY * tRight.tY.tX + tLeft.tX.tZ * tRight.tY.tX,
			tLeft.tX.tX * tRight.tX.tY + tLeft.tX.tY * tRight.tY.tY + tLeft.tX.tZ * tRight.tY.tY,
			tLeft.tX.tX * tRight.tX.tZ + tLeft.tX.tY * tRight.tY.tZ + tLeft.tX.tZ * tRight.tY.tZ,

			tLeft.tY.tX * tRight.tX.tX + tLeft.tY.tY * tRight.tY.tX + tLeft.tY.tZ * tRight.tY.tX,
			tLeft.tY.tX * tRight.tX.tY + tLeft.tY.tY * tRight.tY.tY + tLeft.tY.tZ * tRight.tY.tY,
			tLeft.tY.tX * tRight.tX.tZ + tLeft.tY.tY * tRight.tY.tZ + tLeft.tY.tZ * tRight.tY.tZ,

			tLeft.tZ.tX * tRight.tX.tX + tLeft.tZ.tY * tRight.tY.tX + tLeft.tZ.tZ * tRight.tY.tX,
			tLeft.tZ.tX * tRight.tX.tY + tLeft.tZ.tY * tRight.tY.tY + tLeft.tZ.tZ * tRight.tY.tY,
			tLeft.tZ.tX * tRight.tX.tZ + tLeft.tZ.tY * tRight.tY.tZ + tLeft.tZ.tZ * tRight.tY.tZ,

			tLeft.tW.tX * tRight.tX.tX + tLeft.tW.tY * tRight.tY.tX + tLeft.tW.tZ * tRight.tY.tX,
			tLeft.tW.tX * tRight.tX.tY + tLeft.tW.tY * tRight.tY.tY + tLeft.tW.tZ * tRight.tY.tY,
			tLeft.tW.tX * tRight.tX.tZ + tLeft.tW.tY * tRight.tY.tZ + tLeft.tW.tZ * tRight.tY.tZ
		};
	}

	template<class T> Mat44<T> operator%(const Mat43<T> &tLeft, const Mat34<T> &tRight)
	{
		return
		{
			tLeft.tX.tX * tRight.tX.tX + tLeft.tX.tY * tRight.tY.tX + tLeft.tX.tZ * tRight.tY.tX,
			tLeft.tX.tX * tRight.tX.tY + tLeft.tX.tY * tRight.tY.tY + tLeft.tX.tZ * tRight.tY.tY,
			tLeft.tX.tX * tRight.tX.tZ + tLeft.tX.tY * tRight.tY.tZ + tLeft.tX.tZ * tRight.tY.tZ,
			tLeft.tX.tX * tRight.tX.tW + tLeft.tX.tY * tRight.tY.tW + tLeft.tX.tZ * tRight.tY.tW,

			tLeft.tY.tX * tRight.tX.tX + tLeft.tY.tY * tRight.tY.tX + tLeft.tY.tZ * tRight.tY.tX,
			tLeft.tY.tX * tRight.tX.tY + tLeft.tY.tY * tRight.tY.tY + tLeft.tY.tZ * tRight.tY.tY,
			tLeft.tY.tX * tRight.tX.tZ + tLeft.tY.tY * tRight.tY.tZ + tLeft.tY.tZ * tRight.tY.tZ,
			tLeft.tY.tX * tRight.tX.tW + tLeft.tY.tY * tRight.tY.tW + tLeft.tY.tZ * tRight.tY.tW,

			tLeft.tZ.tX * tRight.tX.tX + tLeft.tZ.tY * tRight.tY.tX + tLeft.tZ.tZ * tRight.tY.tX,
			tLeft.tZ.tX * tRight.tX.tY + tLeft.tZ.tY * tRight.tY.tY + tLeft.tZ.tZ * tRight.tY.tY,
			tLeft.tZ.tX * tRight.tX.tZ + tLeft.tZ.tY * tRight.tY.tZ + tLeft.tZ.tZ * tRight.tY.tZ,
			tLeft.tZ.tX * tRight.tX.tW + tLeft.tZ.tY * tRight.tY.tW + tLeft.tZ.tZ * tRight.tY.tW,

			tLeft.tW.tX * tRight.tX.tX + tLeft.tW.tY * tRight.tY.tX + tLeft.tW.tZ * tRight.tY.tX,
			tLeft.tW.tX * tRight.tX.tY + tLeft.tW.tY * tRight.tY.tY + tLeft.tW.tZ * tRight.tY.tY,
			tLeft.tW.tX * tRight.tX.tZ + tLeft.tW.tY * tRight.tY.tZ + tLeft.tW.tZ * tRight.tY.tZ,
			tLeft.tW.tX * tRight.tX.tW + tLeft.tW.tY * tRight.tY.tW + tLeft.tW.tZ * tRight.tY.tW
		};
	}

	template<class T> Mat42<T> operator%(const Mat44<T> &tLeft, const Mat42<T> &tRight)
	{
		return
		{
			tLeft.tX.tX * tRight.tX.tX + tLeft.tX.tY * tRight.tY.tX + tLeft.tX.tZ * tRight.tY.tX + tLeft.tX.tW * tRight.tY.tX,
			tLeft.tX.tX * tRight.tX.tY + tLeft.tX.tY * tRight.tY.tY + tLeft.tX.tZ * tRight.tY.tY + tLeft.tX.tW * tRight.tY.tY,

			tLeft.tY.tX * tRight.tX.tX + tLeft.tY.tY * tRight.tY.tX + tLeft.tY.tZ * tRight.tY.tX + tLeft.tY.tW * tRight.tY.tX,
			tLeft.tY.tX * tRight.tX.tY + tLeft.tY.tY * tRight.tY.tY + tLeft.tY.tZ * tRight.tY.tY + tLeft.tY.tW * tRight.tY.tY,

			tLeft.tZ.tX * tRight.tX.tX + tLeft.tZ.tY * tRight.tY.tX + tLeft.tZ.tZ * tRight.tY.tX + tLeft.tZ.tW * tRight.tY.tX,
			tLeft.tZ.tX * tRight.tX.tY + tLeft.tZ.tY * tRight.tY.tY + tLeft.tZ.tZ * tRight.tY.tY + tLeft.tZ.tW * tRight.tY.tY,

			tLeft.tW.tX * tRight.tX.tX + tLeft.tW.tY * tRight.tY.tX + tLeft.tW.tZ * tRight.tY.tX + tLeft.tW.tW * tRight.tY.tX,
			tLeft.tW.tX * tRight.tX.tY + tLeft.tW.tY * tRight.tY.tY + tLeft.tW.tZ * tRight.tY.tY + tLeft.tW.tW * tRight.tY.tY
		};
	}

	template<class T> Mat43<T> operator%(const Mat44<T> &tLeft, const Mat43<T> &tRight)
	{
		return
		{
			tLeft.tX.tX * tRight.tX.tX + tLeft.tX.tY * tRight.tY.tX + tLeft.tX.tZ * tRight.tY.tX + tLeft.tX.tW * tRight.tY.tX,
			tLeft.tX.tX * tRight.tX.tY + tLeft.tX.tY * tRight.tY.tY + tLeft.tX.tZ * tRight.tY.tY + tLeft.tX.tW * tRight.tY.tY,
			tLeft.tX.tX * tRight.tX.tZ + tLeft.tX.tY * tRight.tY.tZ + tLeft.tX.tZ * tRight.tY.tZ + tLeft.tX.tW * tRight.tY.tZ,

			tLeft.tY.tX * tRight.tX.tX + tLeft.tY.tY * tRight.tY.tX + tLeft.tY.tZ * tRight.tY.tX + tLeft.tY.tW * tRight.tY.tX,
			tLeft.tY.tX * tRight.tX.tY + tLeft.tY.tY * tRight.tY.tY + tLeft.tY.tZ * tRight.tY.tY + tLeft.tY.tW * tRight.tY.tY,
			tLeft.tY.tX * tRight.tX.tZ + tLeft.tY.tY * tRight.tY.tZ + tLeft.tY.tZ * tRight.tY.tZ + tLeft.tY.tW * tRight.tY.tZ,

			tLeft.tZ.tX * tRight.tX.tX + tLeft.tZ.tY * tRight.tY.tX + tLeft.tZ.tZ * tRight.tY.tX + tLeft.tZ.tW * tRight.tY.tX,
			tLeft.tZ.tX * tRight.tX.tY + tLeft.tZ.tY * tRight.tY.tY + tLeft.tZ.tZ * tRight.tY.tY + tLeft.tZ.tW * tRight.tY.tY,
			tLeft.tZ.tX * tRight.tX.tZ + tLeft.tZ.tY * tRight.tY.tZ + tLeft.tZ.tZ * tRight.tY.tZ + tLeft.tZ.tW * tRight.tY.tZ,

			tLeft.tW.tX * tRight.tX.tX + tLeft.tW.tY * tRight.tY.tX + tLeft.tW.tZ * tRight.tY.tX + tLeft.tW.tW * tRight.tY.tX,
			tLeft.tW.tX * tRight.tX.tY + tLeft.tW.tY * tRight.tY.tY + tLeft.tW.tZ * tRight.tY.tY + tLeft.tW.tW * tRight.tY.tY,
			tLeft.tW.tX * tRight.tX.tZ + tLeft.tW.tY * tRight.tY.tZ + tLeft.tW.tZ * tRight.tY.tZ + tLeft.tW.tW * tRight.tY.tZ
		};
	}

	template<class T> Mat44<T> operator%(const Mat44<T> &tLeft, const Mat44<T> &tRight)
	{
		return
		{
			tLeft.tX.tX * tRight.tX.tX + tLeft.tX.tY * tRight.tY.tX + tLeft.tX.tZ * tRight.tY.tX + tLeft.tX.tW * tRight.tY.tX,
			tLeft.tX.tX * tRight.tX.tY + tLeft.tX.tY * tRight.tY.tY + tLeft.tX.tZ * tRight.tY.tY + tLeft.tX.tW * tRight.tY.tY,
			tLeft.tX.tX * tRight.tX.tZ + tLeft.tX.tY * tRight.tY.tZ + tLeft.tX.tZ * tRight.tY.tZ + tLeft.tX.tW * tRight.tY.tZ,
			tLeft.tX.tX * tRight.tX.tW + tLeft.tX.tY * tRight.tY.tW + tLeft.tX.tZ * tRight.tY.tW + tLeft.tX.tW * tRight.tY.tW,

			tLeft.tY.tX * tRight.tX.tX + tLeft.tY.tY * tRight.tY.tX + tLeft.tY.tZ * tRight.tY.tX + tLeft.tY.tW * tRight.tY.tX,
			tLeft.tY.tX * tRight.tX.tY + tLeft.tY.tY * tRight.tY.tY + tLeft.tY.tZ * tRight.tY.tY + tLeft.tY.tW * tRight.tY.tY,
			tLeft.tY.tX * tRight.tX.tZ + tLeft.tY.tY * tRight.tY.tZ + tLeft.tY.tZ * tRight.tY.tZ + tLeft.tY.tW * tRight.tY.tZ,
			tLeft.tY.tX * tRight.tX.tW + tLeft.tY.tY * tRight.tY.tW + tLeft.tY.tZ * tRight.tY.tW + tLeft.tY.tW * tRight.tY.tW,

			tLeft.tZ.tX * tRight.tX.tX + tLeft.tZ.tY * tRight.tY.tX + tLeft.tZ.tZ * tRight.tY.tX + tLeft.tZ.tW * tRight.tY.tX,
			tLeft.tZ.tX * tRight.tX.tY + tLeft.tZ.tY * tRight.tY.tY + tLeft.tZ.tZ * tRight.tY.tY + tLeft.tZ.tW * tRight.tY.tY,
			tLeft.tZ.tX * tRight.tX.tZ + tLeft.tZ.tY * tRight.tY.tZ + tLeft.tZ.tZ * tRight.tY.tZ + tLeft.tZ.tW * tRight.tY.tZ,
			tLeft.tZ.tX * tRight.tX.tW + tLeft.tZ.tY * tRight.tY.tW + tLeft.tZ.tZ * tRight.tY.tW + tLeft.tZ.tW * tRight.tY.tW,

			tLeft.tW.tX * tRight.tX.tX + tLeft.tW.tY * tRight.tY.tX + tLeft.tW.tZ * tRight.tY.tX + tLeft.tW.tW * tRight.tY.tX,
			tLeft.tW.tX * tRight.tX.tY + tLeft.tW.tY * tRight.tY.tY + tLeft.tW.tZ * tRight.tY.tY + tLeft.tW.tW * tRight.tY.tY,
			tLeft.tW.tX * tRight.tX.tZ + tLeft.tW.tY * tRight.tY.tZ + tLeft.tW.tZ * tRight.tY.tZ + tLeft.tW.tW * tRight.tY.tZ,
			tLeft.tW.tX * tRight.tX.tW + tLeft.tW.tY * tRight.tY.tW + tLeft.tW.tZ * tRight.tY.tW + tLeft.tW.tW * tRight.tY.tW
		};
	}
}