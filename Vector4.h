#pragma once

#include "Vector3.h"

namespace Oblivion {
namespace Math {
    class Vector4 {
    public:
        float x, y, z, w;

        Vector4();
        Vector4(const float& x, const float& y, const float& z, const float& w);

        friend Vector4& operator+=(Vector4& v, const Vector4& v1);
        friend Vector4& operator-=(Vector4& v, const Vector4& v1);
        friend Vector4& operator*=(Vector4& v, const Vector4& v1);
        friend Vector4& operator/=(Vector4& v, const Vector4& v1);
        friend Vector4 operator+(const Vector4& v, const Vector4& v1);
        friend Vector4 operator-(const Vector4& v, const Vector4& v1);
        friend float operator*(const Vector4& v, const Vector4& v1);
        friend Vector4 operator*(const Vector4& v, const float scalar);
        friend Vector4 operator^(const Vector4& v, const Vector4& v1);
        friend bool operator==(const Vector4& v, const Vector4& v1);
        friend bool operator!=(const Vector4& v, const Vector4& v1);

		float Magnitude();
    };

    Vector4::Vector4()
        : x(0.0f)
        , y(0.0f)
        , z(0.0f)
        , w(1.0f)
    {
    }

    Vector4::Vector4(const float& x, const float& y, const float& z, const float& w)
        : x(x)
        , y(y)
        , z(z)
        , w(w)
    {
    }

    Vector4& operator+=(Vector4& v, const Vector4& v1)
    {
        v.x += v1.x;
        v.y += v1.y;
        v.z += v1.z;
        v.w += v1.w;

        return v;
    }

    Vector4& operator-=(Vector4& v, const Vector4& v1)
    {
        v.x -= v1.x;
        v.y -= v1.y;
        v.z -= v1.z;
        v.w -= v1.w;

        return v;
    }

    Vector4& operator*=(Vector4& v, const Vector4& v1)
    {
        v.x *= v1.x;
        v.y *= v1.y;
        v.z *= v1.z;
        v.w *= v1.w;

        return v;
    }

    Vector4& operator/=(Vector4& v, const Vector4& v1)
    {
        v.x /= v1.x;
        v.y /= v1.y;
        v.z /= v1.z;
        v.w /= v1.w;

        return v;
    }

    Vector4 operator+(const Vector4& v, const Vector4& v1)
    {
        return Vector4(v.x + v1.x, v.y + v1.y, v.z + v1.z, v.w + v1.w);
    }

    Vector4 operator-(const Vector4& v, const Vector4& v1)
    {
        return Vector4(v.x - v1.x, v.y - v1.y, v.z - v1.z, v.w - v1.w);
    }

    float operator*(const Vector4& v, const Vector4& v1)
    {
        return (v.x * v1.x) + (v.y * v1.y) + (v.z * v1.z) + (v.w * v1.w);
    }

    Vector4 operator*(const Vector4& v, const float scalar)
    {
        return Vector4(scalar * v.x, scalar * v.y, scalar * v.z, scalar * v.w);
    }

    Vector4 operator^(const Vector4& v, const Vector4& v1)
    {
        return Vector4(v.y * v1.z - v.z * v1.y, v.z * v1.x - v.x * v1.z, v.x * v1.y - v.y * v1.x, 0.0f);
    }

    bool operator==(const Vector4& v, const Vector4& v1)
    {
        return (v.x == v1.x && v.y == v1.y && v.z == v1.z && v.w == v1.w);
    }

    bool operator!=(const Vector4& v, const Vector4& v1)
    {
        return (v.x != v1.x || v.y != v1.y || v.z != v1.z || v.w != v1.w);
    }

    inline float Vector4::Magnitude()
    {
        return sqrtf((x * x) + (y * y) + (z * z) + (w * w));
    }

	/********************************************************************
	// NON-MEMBER FUNCTIONS
	********************************************************************/
    inline float DotProduct(const Vector4& v1, const Vector4& v2)
    {
        return v1 * v2;
    }
}
}

