
/*
	2019.06.11
	Created by AcrylicShrimp.
*/

#include "Transform.h"

namespace Onyx::Transform
{
	Transform::Transform() :
		sMatrix{Mat44f::identity()},
		sInverseMatrix{Mat44f::identity()}
	{
		//Empty.
	}

	Vec4f Transform::forward() const
	{
		return Vec4f::front() % this->sInverseMatrix;
	}

	Vec4f Transform::backward() const
	{
		return Vec4f::back() % this->sInverseMatrix;
	}

	Vec4f Transform::upward() const
	{
		return Vec4f::up() % this->sInverseMatrix;
	}

	Vec4f Transform::downward() const
	{
		return Vec4f::down() % this->sInverseMatrix;
	}

	Vec4f Transform::leftward() const
	{
		return Vec4f::left() % this->sInverseMatrix;
	}

	Vec4f Transform::rightward() const
	{
		return Vec4f::right() % this->sInverseMatrix;
	}

	void Transform::translateX(float nDistance, Space eSpace)
	{
		if (eSpace == Space::Local)
		{
			this->sMatrix = this->sMatrix % Transform::translation(nDistance, .0f, .0f);
			this->sInverseMatrix = this->sInverseMatrix % Transform::translation(-nDistance, .0f, .0f);
		}
		else
		{
			const auto sAxis{this->rightward() * nDistance};

			this->sMatrix = this->sMatrix % Transform::translation(sAxis.tX, sAxis.tY, sAxis.tZ);
			this->sInverseMatrix = this->sInverseMatrix % Transform::translation(-sAxis.tX, -sAxis.tY, -sAxis.tZ);
		}
	}

	void Transform::translateY(float nDistance, Space eSpace)
	{
		if (eSpace == Space::Local)
		{
			this->sMatrix = this->sMatrix % Transform::translation(.0f, nDistance, .0f);
			this->sInverseMatrix = this->sInverseMatrix % Transform::translation(.0f, -nDistance, .0f);
		}
		else
		{
			const auto sAxis{this->upward() * nDistance};

			this->sMatrix = this->sMatrix % Transform::translation(sAxis.tX, sAxis.tY, sAxis.tZ);
			this->sInverseMatrix = this->sInverseMatrix % Transform::translation(-sAxis.tX, -sAxis.tY, -sAxis.tZ);
		}
	}

	void Transform::translateZ(float nDistance, Space eSpace)
	{
		if (eSpace == Space::Local)
		{
			this->sMatrix = this->sMatrix % Transform::translation(.0f, .0f, nDistance);
			this->sInverseMatrix = this->sInverseMatrix % Transform::translation(.0f, .0f, -nDistance);
		}
		else
		{
			const auto sAxis{this->forward() * nDistance};

			this->sMatrix = this->sMatrix % Transform::translation(sAxis.tX, sAxis.tY, sAxis.tZ);
			this->sInverseMatrix = this->sInverseMatrix % Transform::translation(-sAxis.tX, -sAxis.tY, -sAxis.tZ);
		}
	}

	void Transform::translate(float nDistanceX, float nDistanceY, float nDistanceZ, Space eSpace)
	{
		if (eSpace == Space::Local)
		{
			this->sMatrix = this->sMatrix % Transform::translation(nDistanceX, nDistanceY, nDistanceZ);
			this->sInverseMatrix = this->sInverseMatrix % Transform::translation(-nDistanceX, -nDistanceY, -nDistanceZ);
		}
		else
		{
			const auto sAxisX{this->rightward()};
			const auto sAxisY{this->upward()};
			const auto sAxisZ{this->forward()};
			const auto sDistance{sAxisX * nDistanceX + sAxisY * nDistanceY + sAxisZ * nDistanceZ};

			this->sMatrix = this->sMatrix % Transform::translation(sDistance.tX, sDistance.tY, sDistance.tZ);
			this->sInverseMatrix = this->sInverseMatrix % Transform::translation(-sDistance.tX, -sDistance.tY, -sDistance.tZ);
		}
	}

	void Transform::rotateX(float nAngle, Space eSpace)
	{
		if (eSpace == Space::Local)
		{
			const auto sRotation{Transform::rotationX(nAngle)};

			this->sMatrix = this->sMatrix % sRotation;
			this->sInverseMatrix = this->sInverseMatrix % sRotation.transposed();
		}
		else
		{
			const auto sAxis{this->rightward()};
			const auto sRotation{Transform::rotation(nAngle, {sAxis.tX, sAxis.tY, sAxis.tZ})};

			this->sMatrix = this->sMatrix % sRotation;
			this->sInverseMatrix = this->sInverseMatrix % sRotation.transposed();
		}
	}

	void Transform::rotateY(float nAngle, Space eSpace)
	{
		if (eSpace == Space::Local)
		{
			const auto sRotation{Transform::rotationY(nAngle)};

			this->sMatrix = this->sMatrix % sRotation;
			this->sInverseMatrix = this->sInverseMatrix % sRotation.transposed();
		}
		else
		{
			const auto sAxis{this->upward()};
			const auto sRotation{Transform::rotation(nAngle, {sAxis.tX, sAxis.tY, sAxis.tZ})};

			this->sMatrix = this->sMatrix % sRotation;
			this->sInverseMatrix = this->sInverseMatrix % sRotation.transposed();
		}
	}

	void Transform::rotateZ(float nAngle, Space eSpace)
	{
		if (eSpace == Space::Local)
		{
			const auto sRotation{Transform::rotationZ(nAngle)};

			this->sMatrix = this->sMatrix % sRotation;
			this->sInverseMatrix = this->sInverseMatrix % sRotation.transposed();
		}
		else
		{
			const auto sAxis{this->forward()};
			const auto sRotation{Transform::rotation(nAngle, {sAxis.tX, sAxis.tY, sAxis.tZ})};

			this->sMatrix = this->sMatrix % sRotation;
			this->sInverseMatrix = this->sInverseMatrix % sRotation.transposed();
		}
	}

	void Transform::rotate(float nAngleX, float nAngleY, float nAngleZ, Space eSpace)
	{
		this->rotateY(nAngleY, eSpace);
		this->rotateZ(nAngleY, eSpace);
		this->rotateX(nAngleY, eSpace);
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
		/*
			TODO: Invert Z axis so +Z means toward.
		*/
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