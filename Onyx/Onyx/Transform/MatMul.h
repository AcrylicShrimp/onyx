
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
			tLeft.tX.tX * tRight.tX.tX + tLeft.tX.tY * tRight.tY.tX,
			tLeft.tX.tX * tRight.tX.tY + tLeft.tX.tY * tRight.tY.tY,

			tLeft.tY.tX * tRight.tX.tX + tLeft.tY.tY * tRight.tY.tX,
			tLeft.tY.tX * tRight.tX.tY + tLeft.tY.tY * tRight.tY.tY,

			tLeft.tZ.tX * tRight.tX.tX + tLeft.tZ.tY * tRight.tY.tX,
			tLeft.tZ.tX * tRight.tX.tY + tLeft.tZ.tY * tRight.tY.tY
		};
	}
}