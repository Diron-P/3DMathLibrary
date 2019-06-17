#pragma once

#include <math.h>
#include <iostream>

namespace Oblivion
{
	namespace Math
	{
		template <typename T>
		class Vector3D
		{
		public:
			T x, y, z;

			Vector3D()
				: x(0.0f), y(0.0f), z(0.0f)
			{
			}

			Vector3D(const T& x, const T& y, const T& z)
				: x(x), y(y), z(z)
			{
			}

			Vector3D& operator+=(const Vector3D& v)
			{
				x += v.x;
				y += v.y;
				z += v.z;
				return *this;
			}

			Vector3D& operator-=(const Vector3D& v)
			{
				x -= v.x;
				y -= v.y;
				z -= v.z;
				return *this;
			}

			Vector3D& operator*=(const Vector3D& v)
			{
				x *= v.x;
				y *= v.y;
				z *= v.z;
				return *this;
			}

			Vector3D& operator/=(const Vector3D& v)
			{
				x /= v.x;
				y /= v.y;
				z /= v.z;
				return *this;
			}

			inline Vector3D operator+(const Vector3D& v) const
			{
				return Vector3D(x + v.x, y + v.y, z + v.z);
			}

			inline Vector3D operator-(const Vector3D& v) const
			{
				return Vector3D(x - v.x, y - v.y, z - v.z);
			}

			inline float operator*(const Vector3D& v) const
			{
				return (x * v.x) + (y * v.y) + (z * v.z);
			}

			inline Vector3D operator*(const float scalar) const
			{
				return Vector3D(scalar * x, scalar * y, scalar * z);
			}

			inline Vector3D operator^(const Vector3D& v) const
			{
				return Vector3D(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x);
			}

			inline bool operator==(const Vector3D& v) const
			{
				return (x == v.x && y == v.y && z == v.z);
			}

			inline bool operator!=(const Vector3D& v) const
			{
				return (x != v.x || y != v.y || z != v.z);
			}

			inline Vector3D operator/(const float s) const
			{
				return Vector3D(x / s, y / s, z / s);
			}

			inline float Magnitude() const
			{
				return sqrt((x * x) + (y * y) + (z * z));
			}

			inline float DotProduct(const Vector3D& v1, const Vector3D& v2)
			{
				return v1 * v2;
			}

			inline Vector3D CrossProduct(const Vector3D& v1, const Vector3D& v2)
			{
				return v1 ^ v2;
			}

			inline Vector3D& Normalize()
			{
				float length = Magnitude();
				if (length > 0.0f)
				{
					float invLen = 1.0f / length;
					x *= invLen, y *= invLen, z *= invLen;
				}

				return *this;
			}

			inline friend std::ostream& operator<<(std::ostream& out, const Vector3D<T>& v)
			{
				out << "Vector3D(" << v.x << ", " << v.y << ", " << v.z << ")";
				return out;
			}
		};

		typedef Vector3D<float> Vector3f;	// A 3D vector with the type of float.
		typedef Vector3D<double> Vector3d;	// A 3D vector with the type of double.
	}
}