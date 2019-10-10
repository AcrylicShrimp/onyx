
/*
	2019.06.11
	Created by AcrylicShrimp.
*/

#include "Transform.h"

namespace Onyx::Transform
{
	Transform::Transform() :
		sPosition{Vec3f::zero()},
		sRotation{Mat33f::identity()}
	{
		//Empty.
	}

	Transform::Transform(const Mat44f &sMatrix) :
		sPosition{sMatrix[3][0], sMatrix[3][1], sMatrix[3][2]},
		sRotation{sMatrix[0][0], sMatrix[0][1], sMatrix[0][2], sMatrix[1][0], sMatrix[1][1], sMatrix[1][2], sMatrix[2][0], sMatrix[2][1], sMatrix[2][2]}
	{
		//Empty.
	}

	Mat44f Transform::matrix() const
	{
		return
		{
			this->sRotation[0][0], this->sRotation[0][1], this->sRotation[0][2], .0f,
			this->sRotation[1][0], this->sRotation[1][1], this->sRotation[1][2], .0f,
			this->sRotation[2][0], this->sRotation[2][1], this->sRotation[2][2], .0f,
			this->sPosition[0], this->sPosition[1], this->sPosition[2], 1.f
		};
	}

	Mat44f Transform::inverseMatrix() const
	{
		auto sTransposedMat{this->sRotation.transposed()};
		auto sMultipliedVec{-this->sPosition % sTransposedMat};

		return
		{
			sTransposedMat[0][0], sTransposedMat[0][1], sTransposedMat[0][2], .0f,
			sTransposedMat[1][0], sTransposedMat[1][1], sTransposedMat[1][2], .0f,
			sTransposedMat[2][0], sTransposedMat[2][1], sTransposedMat[2][2], .0f,
			sMultipliedVec[0], sMultipliedVec[1], sMultipliedVec[2], 1.f
		};
	}

	Vec3f Transform::forward() const
	{
		return this->sRotation % Vec3f::front();
	}

	Vec3f Transform::backward() const
	{
		return this->sRotation % Vec3f::back();
	}

	Vec3f Transform::upward() const
	{
		return this->sRotation % Vec3f::up();
	}

	Vec3f Transform::downward() const
	{
		return this->sRotation % Vec3f::down();
	}

	Vec3f Transform::leftward() const
	{
		return this->sRotation % Vec3f::left();
	}

	Vec3f Transform::rightward() const
	{
		return this->sRotation % Vec3f::right();
	}

	void Transform::translateX(float nDistance, Space eSpace)
	{
		if (eSpace == Space::World)
			this->sPosition.tX += nDistance;
		else
			this->sPosition += nDistance * this->rightward();
	}

	void Transform::translateY(float nDistance, Space eSpace)
	{
		if (eSpace == Space::World)
			this->sPosition.tY += nDistance;
		else
			this->sPosition += nDistance * this->upward();
	}

	void Transform::translateZ(float nDistance, Space eSpace)
	{
		if (eSpace == Space::World)
			this->sPosition.tZ += nDistance;
		else
			this->sPosition += nDistance * this->forward();
	}

	void Transform::translate(float nDistanceX, float nDistanceY, float nDistanceZ, Space eSpace)
	{
		if (eSpace == Space::World)
		{
			this->sPosition.tX += nDistanceX;
			this->sPosition.tY += nDistanceY;
			this->sPosition.tZ += nDistanceZ;
		}
		else
			this->sPosition += Vec3f{nDistanceX, nDistanceY, nDistanceZ} * this->rightward();
	}

	void Transform::rotateX(float nAngle, Space eSpace)
	{
		if (eSpace == Space::World)
		{
			const auto nSin{std::sin(nAngle)};
			const auto nCos{std::cos(nAngle)};

			this->sRotation % Mat33f{1.f, .0f, .0f, .0f, nCos, nSin, .0f, -nSin, nCos};
		}
		/*else
*/
	}

	void Transform::rotateY(float nAngle, Space eSpace)
	{

	}

	void Transform::rotateZ(float nAngle, Space eSpace)
	{

	}

	void Transform::rotate(float nAngleX, float nAngleY, float nAngleZ, Space eSpace)
	{

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

	Mat44f Transform::rotation(float nAngle, const Vec3f &sAxis)
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

	Mat44f Transform::rotationX(float nAngle)
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

	Mat44f Transform::rotationY(float nAngle)
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

	Mat44f Transform::rotationZ(float nAngle)
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

	Mat44f Transform::translation(const Vec3f &sDistance)
	{
		return
		{
			1.f, .0f, .0f, .0f,
			.0f, 1.f, .0f, .0f,
			.0f, .0f, 1.f, .0f,
			sDistance.tX, sDistance.tY, sDistance.tZ, 1.f
		};
	}

	Mat44f Transform::translation(float nDistanceX, float nDistanceY, float nDistanceZ)
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