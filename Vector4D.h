#pragma once

#include <math.h>
#include <iostream>

namespace Oblivion
{
	namespace Math
	{
		template <typename T>
		class Vector4D
		{
		public:
			T x, y, z, w;

			Vector4D()
				: x(0.0f), y(0.0f), z(0.0f), w(1.0f)
			{
			}

			Vector4D(const T& x, const T& y, const T& z, const T& w)
				: x(x), y(y), z(z), w(w)
			{
			}

			Vector4D& operator+=(const Vector4D& v)
			{
				x += v.x;
				y += v.y;
				z += v.z;
				w += v.w;
				return *this;
			}

			Vector4D& operator-=(const Vector4D& v)
			{
				x -= v.x;
				y -= v.y;
				z -= v.z;
				z -= v.z;
				return *this;
			}

			Vector4D& operator*=(const Vector4D& v)
			{
				x *= v.x;
				y *= v.y;
				z *= v.z;
				z *= v.z;
				return *this;
			}

			Vector4D& operator/=(const Vector4D& v)
			{
				x /= v.x;
				y /= v.y;
				z /= v.z;
				z /= v.z;
				return *this;
			}

			inline Vector4D operator+(const Vector4D& v) const
			{
				return Vector4D(v.x + x, v.y + y, v.z + z, v.w + w);
			}

			inline Vector4D operator-(const Vector4D& v) const
			{
				return Vector4D(x - v.x, y - v.y, z - v.z, w - v.w);
			}

			inline float operator*(const Vector4D& v) const
			{
				return (x * v.x) + (y * v.y) + (z * v.z) + (w * v.w);
			}

			inline Vector4D operator*(const float scalar) const
			{
				return Vector4D(scalar * x, scalar * y, scalar * z, scalar * w);
			}

			inline Vector4D operator^(const Vector4D& v) const
			{
				return Vector4D(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x, 0.0f);
			}

			inline bool operator==(const Vector4D& v) const
			{
				return (x == v.x && y == v.y && z == v.z && w == v.w);
			}

			inline bool operator!=(const Vector4D& v) const
			{
				return (x != v.x || y != v.y || z != v.z || w != v.w);
			}

			inline float Magnitude() const
			{
				return sqrt((x * x) + (y * y) + (z * z) + (w * w));
			}

			inline float DotProduct(const Vector4D& v1, const Vector4D& v2)
			{
				return v1 * v2;
			}

			inline std::ostream& operator<<(std::ostream& out)
			{
				out << "Vector4D(" << this.x << ", " << this.y << ", " << this.z << ", " << this.w << ")";
				return out;
			}
		};

		typedef Vector4D<float> Vector4f;	// A 4D vector with the type of float.
		typedef Vector4D<double> Vector4d;	// A 4D vector with the type of double.
	}
}