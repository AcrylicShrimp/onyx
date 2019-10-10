
/*
	2019.06.11
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_ONYX_TRANSFORM_TRANSFORM_H

#define _CLASS_ONYX_TRANSFORM_TRANSFORM_H

#include "./Vecs.h"
#include "./Mats.h"

#include <cmath>

namespace Onyx::Transform
{
	class Transform final
	{
	public:
		enum Space
		{
			Local,
			World
		};

	public:
		Vec3f sPosition;
		Mat33f sRotation;
		
	public:
		Transform();
		Transform(const Mat44f &sMatrix);
		Transform(const Transform &sSrc) = default;
		~Transform() = default;
		
	public:
		Transform &operator=(const Transform &sSrc) = default;
		
	public:
		Mat44f matrix() const;
		Mat44f inverseMatrix() const;
		Vec3f forward() const;
		Vec3f backward() const;
		Vec3f upward() const;
		Vec3f downward() const;
		Vec3f leftward() const;
		Vec3f rightward() const;
		void translateX(float nDistance, Space eSpace);
		void translateY(float nDistance, Space eSpace);
		void translateZ(float nDistance, Space eSpace);
		void translate(float nDistanceX, float nDistanceY, float nDistanceZ, Space eSpace);
		void rotateX(float nAngle, Space eSpace);
		void rotateY(float nAngle, Space eSpace);
		void rotateZ(float nAngle, Space eSpace);
		void rotate(float nAngleX, float nAngleY, float nAngleZ, Space eSpace);

	public:
		static Mat44f scale(float nScale);
		static Mat44f scale(float nScaleX, float nScaleY, float nScaleZ);
		static Mat44f rotation(float nAngle, const Vec3f &sAxis);
		static Mat44f rotationX(float nAngle);
		static Mat44f rotationY(float nAngle);
		static Mat44f rotationZ(float nAngle);
		static Mat44f translation(const Vec3f &sDistance);
		static Mat44f translation(float nDistanceX, float nDistanceY, float nDistanceZ);
		static Mat44f perspective(float nAspect, float nFoV, float nNear, float nFar);
	};
}

#endif