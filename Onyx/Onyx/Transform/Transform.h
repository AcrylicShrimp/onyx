
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
	/*
		This class represents transformation for cameras;
		It means below sMatrix and sInverseMatrix matrices are:

		sInverseMatrix: World -> View
		sMatrix: View -> World
	*/
	class Transform final
	{
	public:
		enum class Space
		{
			Local,
			World
		};

	public:
		Mat44f sMatrix;
		Mat44f sInverseMatrix;
		
	public:
		Transform();
		Transform(const Transform &sSrc) = default;
		~Transform() = default;
		
	public:
		Transform &operator=(const Transform &sSrc) = default;
		
	public:
		inline const Mat44f &matrix() const;
		inline const Mat44f &inverseMatrix() const;
		Vec4f forward() const;
		Vec4f backward() const;
		Vec4f upward() const;
		Vec4f downward() const;
		Vec4f leftward() const;
		Vec4f rightward() const;
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

	inline const Mat44f &Transform::matrix() const
	{
		return this->sMatrix;
	}

	inline const Mat44f &Transform::inverseMatrix() const
	{
		return this->sInverseMatrix;
	}
}

#endif