#pragma once

#include <math.h>

namespace Oblivion {
namespace Math {
    class Vector2D {
    public:
        float x;
        float y;

        Vector2D()
            : x(0.0f)
            , y(0.0f)
        {
        }

        Vector2D(const float& x, const float& y)
            : x(x)
            , y(y)
        {
        }

        Vector2D& operator+=(const Vector2D& v)
        {
            x += v.x;
            y += v.y;
            return *this;
        }

        Vector2D& operator-=(const Vector2D& v)
        {
            x -= v.x;
            y -= v.y;
            return *this;
        }

        Vector2D& operator*=(const Vector2D& v)
        {
            x *= v.x;
            y *= v.y;
            return *this;
        }

        Vector2D& operator/=(const Vector2D& v)
        {
            x /= v.x;
            y /= v.y;
            return *this;
        }

        inline Vector2D operator+(const Vector2D& v) const
        {
            return Vector2D(x + v.x, y + v.y);
        }

        inline Vector2D operator-(const Vector2D& v) const
        {
            return Vector2D(x - v.x, y - v.y);
        }

        inline float operator*(const Vector2D& v) const
        {
            return (x * v.x) + (y * v.y);
        }

        inline Vector2D operator*(const float scalar) const
        {
            return Vector2D(scalar * x, scalar * y);
        }

        inline Vector2D operator/(float s) const
        {
            return Vector2D(x / s, y / s);
        }

        inline bool operator==(const Vector2D& v) const
        {
            return (x == v.x && y == v.y);
        }

        inline bool operator!=(const Vector2D& v) const
        {
            return (x != v.x || y != v.y);
        }

        inline float Magnitude() const
        {
            return sqrt((x * x) + (y * y));
        }

        inline float DotProduct(const Vector2D& v1, const Vector2D& v2)
        {
            return v1 * v2;
        }

        inline Vector2D Normalize(Vector2D& v)
        {
            return (v / v.Magnitude());
        }
    };
}
}