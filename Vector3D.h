#pragma once


#include <math.h>

namespace Oblivion {
namespace Math {
    template <typename T>
    class Vector3D {
    public:
        T x, y, z;

        Vector3D()
            : x(0.0f)
            , y(0.0f)
            , z(0.0f)
        {
        }

        Vector3D(const T& x, const T& y, const T& z)
            : x(x)
            , y(y)
            , z(z)
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

        inline Vector3D& Zero()
        {
            x = y = z = 0.0f;
            return *this;
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
            if (length > 0.0f) {
                float invLen = 1.0f / length;
                x *= invLen, y *= invLen, z *= invLen;
            }

            return *this;
        }
    };
}	// end namespace Math
}	// end namespace Oblivion
