
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
		Mat44f sMatrix;
		
	public:
		Transform();
		Transform(const Mat44f &sMatrix);
		Transform(const Transform &sSrc) = default;
		~Transform() = default;
		
	public:
		Transform &operator=(const Transform &sSrc) = default;
		
	public:
		static Mat44f scale(float nScale);
		static Mat44f scale(float nScaleX, float nScaleY, float nScaleZ);
		static Mat44f rotate(float nAngle, const Vec3f &sAxis);
		static Mat44f rotateX(float nAngle);
		static Mat44f rotateY(float nAngle);
		static Mat44f rotateZ(float nAngle);
		static Mat44f translate(const Vec3f &sDistance);
		static Mat44f translate(float nDistanceX, float nDistanceY, float nDistanceZ);
		static Mat44f perspective(float nAspect, float nFoV, float nNear, float nFar);
	};
}

#endif