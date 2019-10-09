
/*
	2019.06.11
	Created by AcrylicShrimp.
*/

#include "Transform.h"

namespace Onyx::Transform
{
	Transform::Transform() :
		sMatrix{Mat44f::identity()}
	{
		//Empty.
	}

	Transform::Transform(const Mat44f &sMatrix) :
		sMatrix{sMatrix}
	{
		//Empty.
	}

	Mat44f Transform::scale(float nScale)
	{
		return
		{
			nScale, .0f, .0f, .0f,
			.0f, nScale, .0f, .0f,
			.0f, .0f, nScale, .0f,
			.0f, .0f, .0f, 1.f
		};
	}

	Mat44f Transform::scale(float nScaleX, float nScaleY, float nScaleZ)
	{
		return
		{
			nScaleX, .0f, .0f, .0f,
			.0f, nScaleY, .0f, .0f,
			.0f, .0f, nScaleZ, .0f,
			.0f, .0f, .0f, 1.f
		};
	}

	Mat44f Transform::rotate(float nAngle, const Vec3f &sAxis)
	{
		const auto nSin{std::sin(nAngle)};
		const auto nCos{std::cos(nAngle)};
		const auto nOneMinusCos{1.f - nCos};

		return
		{
			nOneMinusCos * sAxis.tX * sAxis.tX + nCos,
			nOneMinusCos * sAxis.tX * sAxis.tY + sAxis.tZ * nSin,
			nOneMinusCos * sAxis.tX * sAxis.tZ - sAxis.tY * nSin,
			.0f,

			nOneMinusCos * sAxis.tX * sAxis.tY - sAxis.tZ * nSin,
			nOneMinusCos * sAxis.tY * sAxis.tY + nCos,
			nOneMinusCos * sAxis.tY * sAxis.tZ + sAxis.tX * nSin,
			.0f,

			nOneMinusCos * sAxis.tX * sAxis.tZ + sAxis.tY * nSin,
			nOneMinusCos * sAxis.tY * sAxis.tZ - sAxis.tX * nSin,
			nOneMinusCos * sAxis.tZ * sAxis.tZ + nCos,
			.0f,

			.0f,
			.0f,
			.0f,
			1.f
		};
	}

	Mat44f Transform::rotateX(float nAngle)
	{
		const auto nSin{std::sin(nAngle)};
		const auto nCos{std::cos(nAngle)};

		return
		{
			1.f, .0f, .0f, .0f,
			.0f, nCos, nSin, .0f,
			.0f, -nSin, nCos, .0f,
			.0f, .0f, .0f, 1.f
		};
	}

	Mat44f Transform::rotateY(float nAngle)
	{
		const auto nSin{std::sin(nAngle)};
		const auto nCos{std::cos(nAngle)};

		return
		{
			nCos, .0f, -nSin, .0f,
			.0f, 1.f, .0f, .0f,
			nSin, .0f, nCos, .0f,
			.0f, .0f, .0f, 1.f
		};
	}

	Mat44f Transform::rotateZ(float nAngle)
	{
		const auto nSin{std::sin(nAngle)};
		const auto nCos{std::cos(nAngle)};

		return
		{
			nCos, nSin, .0f, .0f,
			-nSin, nCos, .0f, .0f,
			.0f, .0f, 1.f, .0f,
			.0f, .0f, .0f, 1.f
		};
	}

	Mat44f Transform::translate(const Vec3f &sDistance)
	{
		return
		{
			1.f, .0f, .0f, .0f,
			.0f, 1.f, .0f, .0f,
			.0f, .0f, 1.f, .0f,
			sDistance.tX, sDistance.tY, sDistance.tZ, 1.f
		};
	}

	Mat44f Transform::translate(float nDistanceX, float nDistanceY, float nDistanceZ)
	{
		return
		{
			1.f, .0f, .0f, .0f,
			.0f, 1.f, .0f, .0f,
			.0f, .0f, 1.f, .0f,
			nDistanceX, nDistanceY, nDistanceZ, 1.f
		};
	}

	Mat44f Transform::perspective(float nAspect, float nFoV, float nNear, float nFar)
	{
		const auto n2FarPerHeight{1.f / std::tan(.5f * nFoV)};
		const auto nNearMinusFarInv{1.f / (nNear - nFar)};

		return
		{
			n2FarPerHeight / nAspect, .0f, .0f, .0f,
			.0f, -n2FarPerHeight, .0f, .0f,
			.0f, .0f, nFar * nNearMinusFarInv, -1.f,
			.0f, .0f, nNear * nFar * nNearMinusFarInv, .0f
		};
	}
}