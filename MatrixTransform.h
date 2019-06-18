#pragma once

#include "MathFunctions.h"
#include "Math/Mappings.h"

namespace Oblivion
{
	namespace Math
	{
		// Scale along cardinal axes
		template <typename T>
		inline Mat4x4<T> Scale(const Mat4x4<T>& m, const Vector3D<T>& v)
		{
			Mat4x4<T> result;

			result[0][0] = v.x;
			result[1][1] = v.y;
			result[2][2] = v.z;

			return result * m;
		}

		// Scale in an arbitrary direction
		template <typename T>
		inline Mat4x4<T> Scale(const Mat4x4<T>& m, Vector3D<T>& v, T s)
		{
			v.Normalize();

			float temp = s - 1.0f;

			float axisX = temp * v.x;
			float axisY = temp * v.y;
			float axisZ = temp * v.z;

			Mat4x4<T> scale;

			scale[0][0] = 1.0f + axisX * v.x;
			scale[0][1] = axisX * v.y;
			scale[0][2] = axisX * v.z;

			scale[1][0] = axisX * v.y;
			scale[1][1] = 1.0f + axisY * v.y;
			scale[1][2] = axisY * v.z;

			scale[2][0] = axisX * v.z;
			scale[2][1] = axisY * v.z;
			scale[2][2] = 1.0f + axisZ * v.z;

			return scale * m;
		}

		//template <typename T>
		inline Mat4x4<float> Rotate(const Mat4x4<float>& m, float angle, Vector3D<float>& v)
		{
			v.Normalize();

			float sin = Sin(angle);
			float cos = Cos(angle);
			float temp = 1.0f - cos;

			float axisX = v.x * temp;
			float axisY = v.y * temp;
			float axisZ = v.z * temp;

			Mat4x4<float> rotate;

			rotate[0][0] = v.x * axisX + cos;
			rotate[0][1] = v.x * axisY + v.z * sin;
			rotate[0][2] = v.x * axisZ - v.y * sin;

			rotate[1][0] = v.x * axisY - v.z * sin;
			rotate[1][1] = v.y * axisY + cos;
			rotate[1][2] = v.y * axisZ + v.x * sin;

			rotate[2][0] = v.x * axisZ + v.y * sin;
			rotate[2][1] = v.y * axisZ - v.x * sin;
			rotate[2][2] = v.z * axisZ + cos;

			Mat4x4<float> result;

			result[0][0] = m[0][0] * rotate[0][0] + m[0][1] * rotate[1][0] + m[0][2] * rotate[2][0];
			result[0][1] = m[0][0] * rotate[0][1] + m[0][1] * rotate[1][1] + m[0][2] * rotate[2][1];
			result[0][2] = m[0][0] * rotate[0][2] + m[0][1] * rotate[1][2] + m[0][2] * rotate[2][2];

			result[1][0] = m[1][0] * rotate[0][0] + m[1][1] * rotate[1][0] + m[1][2] * rotate[2][0];
			result[1][1] = m[1][0] * rotate[0][1] + m[1][1] * rotate[1][1] + m[1][2] * rotate[2][1];
			result[1][2] = m[1][0] * rotate[0][2] + m[1][1] * rotate[1][2] + m[1][2] * rotate[2][2];

			result[2][0] = m[2][0] * rotate[0][0] + m[2][1] * rotate[1][0] + m[2][2] * rotate[2][0];
			result[2][1] = m[2][0] * rotate[0][1] + m[2][1] * rotate[1][1] + m[2][2] * rotate[2][1];
			result[2][2] = m[2][0] * rotate[0][2] + m[2][1] * rotate[1][2] + m[2][2] * rotate[2][2];

			result[3][0] = m[3][0];
			result[3][1] = m[3][1];
			result[3][2] = m[3][2];

			return result;
		}

		template <typename T>
		inline Mat4x4<T> Rotate(const Mat4x4<T>& m, float angle, int axis)
		{
			float cos = Cos(angle);
			float sin = Sin(angle);

			Mat4x4<T> rotate;

			switch (axis)
			{
				// Rotation about x axis
			case 1:
				rotate[1][1] = cos;
				rotate[1][2] = sin;
				rotate[2][1] = -sin;
				rotate[2][2] = cos;
				break;

				// Rotation about y axis
			case 2:
				rotate[0][0] = cos;
				rotate[0][2] = -sin;
				rotate[2][0] = sin;
				rotate[2][2] = cos;
				break;

				// Rotation about z axis
			case 3:
				rotate[0][0] = cos;
				rotate[0][1] = sin;
				rotate[1][0] = -sin;
				rotate[1][1] = cos;
				break;

			default:
				assert("Invalid input");
			}

			Mat4x4<T> result;

			result[0][0] = m[0][0] * rotate[0][0] + m[0][1] * rotate[1][0] + m[0][2] * rotate[2][0];
			result[0][1] = m[0][0] * rotate[0][1] + m[0][1] * rotate[1][1] + m[0][2] * rotate[2][1];
			result[0][2] = m[0][0] * rotate[0][2] + m[0][1] * rotate[1][2] + m[0][2] * rotate[2][2];

			result[1][0] = m[1][0] * rotate[0][0] + m[1][1] * rotate[1][0] + m[1][2] * rotate[2][0];
			result[1][1] = m[1][0] * rotate[0][1] + m[1][1] * rotate[1][1] + m[1][2] * rotate[2][1];
			result[1][2] = m[1][0] * rotate[0][2] + m[1][1] * rotate[1][2] + m[1][2] * rotate[2][2];

			result[2][0] = m[2][0] * rotate[0][0] + m[2][1] * rotate[1][0] + m[2][2] * rotate[2][0];
			result[2][1] = m[2][0] * rotate[0][1] + m[2][1] * rotate[1][1] + m[2][2] * rotate[2][1];
			result[2][2] = m[2][0] * rotate[0][2] + m[2][1] * rotate[1][2] + m[2][2] * rotate[2][2];

			result[3][0] = m[3][0];
			result[3][1] = m[3][1];
			result[3][2] = m[3][2];

			return result;
		}

		template <typename T>
		inline Mat4x4<T> Translate(const Mat4x4<T>& m, const Vector3D<T>& v)
		{
			Mat4x4<T> result(m);

			result[3][0] = v.x + m[3][0] * v.x;
			result[3][1] = v.y + m[3][1] * v.y;
			result[3][2] = v.z + m[3][2] * v.z;

			return result;
		}

		// Reflect about an arbitrary plane
		template <typename T>
		inline Mat4x4<T> Reflect(const Mat4x4<T>& m, const Vector3D<T>& v)
		{
			v.Normalize();

			T axisX = -2.0f * v.x;
			T axisY = -2.0f * v.y;
			T axisZ = -2.0f * v.z;

			Mat4x4<T> reflect;

			reflect[0][0] = 1.0f + axisX * v.x;
			reflect[0][1] = axisX * v.y;
			reflect[0][2] = axisX * v.z;

			reflect[1][0] = axisX * v.y;
			reflect[1][1] = 1.0f + axisY * v.y;
			reflect[1][2] = axisY * v.z;

			reflect[2][0] = axisX * v.z;
			reflect[2][1] = axisY * v.z;
			reflect[2][2] = 1.0f + axisZ * v.z;

			return reflect * m;
		}
	}
}