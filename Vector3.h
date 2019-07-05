#pragma once

#include <math.h>

namespace Oblivion {
namespace Math {
    class Vector3 {
    public:
        float x, y, z;

        Vector3();
        Vector3(const float& x, const float& y, const float& z);

        friend Vector3& operator+=(Vector3& v, const Vector3& v1);
        friend Vector3& operator-=(Vector3& v, const Vector3& v1);
        friend Vector3& operator*=(Vector3& v, const Vector3& v1);
        friend Vector3& operator/=(Vector3& v, const Vector3& v1);
        friend Vector3 operator+(const Vector3& v, const Vector3& v1);
        friend Vector3 operator-(const Vector3& v, const Vector3& v1);
        friend float operator*(const Vector3& v, const Vector3& v1);
        friend Vector3 operator*(const Vector3& v, const float scalar);
        friend Vector3 operator^(const Vector3& v, const Vector3& v1);
        friend bool operator==(const Vector3& v, const Vector3& v1);
        friend bool operator!=(const Vector3& v, const Vector3& v1);
        friend Vector3 operator/(const Vector3& v, const float s);

		Vector3& MakeZero();
		float Magnitude();
    };

	class Vector4;

    Vector3::Vector3()
        : x(0.0f)
        , y(0.0f)
        , z(0.0f)
    {
    }

    Vector3::Vector3(const float& x, const float& y, const float& z)
        : x(x)
        , y(y)
        , z(z)
    {
    }

    Vector3& operator+=(Vector3& v, const Vector3& v1)
    {
        v.x += v1.x;
        v.y += v1.y;
        v.z += v1.z;

        return v;
    }

    Vector3& operator-=(Vector3& v, const Vector3& v1)
    {
        v.x -= v1.x;
        v.y -= v1.y;
        v.z -= v1.z;

        return v;
    }

    Vector3& operator*=(Vector3& v, const Vector3& v1)
    {
        v.x *= v1.x;
        v.y *= v1.y;
        v.z *= v1.z;

        return v;
    }

    Vector3& operator/=(Vector3& v, const Vector3& v1)
    {
        v.x /= v1.x;
        v.y /= v1.y;
        v.z /= v1.z;

        return v;
    }

    inline Vector3 operator+(const Vector3& v, const Vector3& v1)
    {
        return Vector3(v.x + v1.x, v.y + v1.y, v.z + v1.z);
    }

    inline Vector3 operator-(const Vector3& v, const Vector3& v1)
    {
        return Vector3(v.x - v1.x, v.y - v1.y, v.z - v1.z);
    }

    inline float operator*(const Vector3& v, const Vector3& v1)
    {
        return (v.x * v1.x) + (v.y * v1.y) + (v.z * v1.z);
    }

    inline Vector3 operator*(const Vector3& v, const float scalar)
    {
        return Vector3(scalar * v.x, scalar * v.y, scalar * v.z);
    }

    inline Vector3 operator^(const Vector3& v, const Vector3& v1)
    {
        return Vector3(v.y * v1.z - v.z * v1.y, v.z * v1.x - v.x * v1.z, v.x * v1.y - v.y * v1.x);
    }

    inline bool operator==(const Vector3& v, const Vector3& v1)
    {
        return (v.x == v1.x && v.y == v1.y && v.z == v1.z);
    }

    inline bool operator!=(const Vector3& v, const Vector3& v1)
    {
        return (v.x != v1.x || v.y != v1.y || v.z != v1.z);
    }

    inline Vector3 operator/(const Vector3& v, const float s)
    {
        return Vector3(v.x / s, v.y / s, v.z / s);
    }

    inline Vector3& Vector3::MakeZero()
    {
        x = y = z = 0.0f;
        return *this;
    }

    inline float Vector3::Magnitude()
    {
        return sqrtf((x * x) + (y * y) + (z * z));
    }

	/********************************************************************
	// NON-MEMBER FUNCTIONS
	********************************************************************/
	inline Vector3 Normalize(Vector3& v)
    {
        Vector3 result;
        float length = v.Magnitude();
        if (length > 0.0f) {
            float invLen = 1.0f / length;
            result.x = v.x * invLen;
            result.y = v.y * invLen;
            result.z = v.z * invLen;
        }

        return result;
    }

	inline float DotProduct(const Vector3& v, const Vector3& v1)
    {
        return v * v1;
    }

	inline Vector3 CrossProduct(const Vector3& v1, const Vector3& v2)
    {
        return v1 ^ v2;
    }
}
}
