#pragma once

#include "Vector2D.h"

namespace Oblivion {
namespace Math {
    class Mat2x2 {
    public:
        float m[2][2];

        Mat2x2();
        Mat2x2(const float& num1, const float& num2, const float& num3, const float& num4);
        Mat2x2(const Vector2D& v1, const Vector2D& v2);

        Mat2x2& identityMatrix();
        Vector2D getColumn(int i) const;
        Mat2x2& setColumn(int i, Vector2D& column);

        Mat2x2& operator*=(const Mat2x2& n);
        friend Mat2x2 operator*(const float& scalar, const Mat2x2& m1);
        friend Mat2x2 operator*(const Mat2x2& m1, const Mat2x2& m2);
        friend bool operator==(const Mat2x2& m1, const Mat2x2& m2);
        friend bool operator!=(const Mat2x2& m1, const Mat2x2& m2);
    };

    inline Mat2x2& Mat2x2::identityMatrix()
    {
        m[0][0] = m[1][1] = 1.0f;
        return *this;
    }

    inline Vector2D Mat2x2::getColumn(int i) const
    {
        return Vector2D(m[0][i], m[1][i]);
    }

    inline Mat2x2& Mat2x2::setColumn(int i, Vector2D& column)
    {
        m[0][i] = column.x;
        m[1][i] = column.y;

        return *this;
    }

    inline Mat2x2::Mat2x2()
    {
        memset(m, 0, sizeof(m[0][0]) * 2 * 2);
    }

    inline Mat2x2::Mat2x2(const float& num1, const float& num2, const float& num3, const float& num4)
    {
        m[0][0] = num1;
        m[0][1] = num3;
        m[1][0] = num2;
        m[1][1] = num4;
    }

    inline Mat2x2::Mat2x2(const Vector2D& v1, const Vector2D& v2)
    {
        m[0][0] = v1.x;
        m[0][1] = v1.y;
        m[1][0] = v2.x;
        m[1][1] = v2.y;
    }

    inline Mat2x2& Mat2x2::operator*=(const Mat2x2& n)
    {
        //Column 1
        Vector2D col1(m[0][0], m[1][0]);
        m[0][0] = col1.x * n.m[0][0] + col1.y * n.m[0][1];
        m[1][0] = col1.x * n.m[1][0] + col1.y * n.m[1][1];

        //Column 2
        Vector2D col2(m[0][1], m[1][1]);
        m[0][1] = col2.x * n.m[0][0] + col2.y * n.m[0][1];
        m[1][1] = col2.x * n.m[1][0] + col2.y * n.m[1][1];

        return *this;
    }

    inline Mat2x2 operator*(const float& scalar, const Mat2x2& m1)
    {
        return Mat2x2(
            scalar * m1.m[0][0], scalar * m1.m[0][1],
            scalar * m1.m[1][0], scalar * m1.m[1][1]);
    }

    inline Mat2x2 operator*(const Mat2x2& m1, const Mat2x2& m2)
    {
        return Mat2x2(
            m1.m[0][0] * m2.m[0][0] + m1.m[1][0] * m2.m[0][1],
            m1.m[0][0] * m2.m[1][0] + m1.m[1][0] * m2.m[1][1],
            m1.m[0][1] * m2.m[0][0] + m1.m[1][1] * m2.m[0][1],
            m1.m[0][1] * m2.m[1][0] + m1.m[1][1] * m2.m[1][1]);
    }

    inline bool operator==(const Mat2x2& m1, const Mat2x2& m2)
    {
        return (m1.m[0][0] == m2.m[0][0]) && (m1.m[0][1] == m2.m[0][1]) && (m1.m[1][0] == m2.m[1][0]) && (m1.m[1][1] == m2.m[1][1]);
    }

    inline bool operator!=(const Mat2x2& m1, const Mat2x2& m2)
    {
        return (m1.m[0][0] != m2.m[0][0]) || (m1.m[0][1] != m2.m[0][1]) || (m1.m[1][0] != m2.m[1][0]) || (m1.m[1][1] != m2.m[1][1]);
    }

    inline Mat2x2 transpose(const Mat2x2& m1)
    {
        return Mat2x2(
            m1.m[0][0], m1.m[1][0],
            m1.m[0][1], m1.m[1][1]);
    }

    inline float determinant(const Mat2x2& m1)
    {
        return m1.m[0][0] * m1.m[1][1] - m1.m[0][1] * m1.m[1][0];
    }

    Mat2x2 inverse(const Mat2x2& m1)
    {
        float determinant = m1.m[0][0] * m1.m[1][1] - m1.m[1][0] * m1.m[0][1];

        float inversedDet = 1.0f / determinant;

        return Mat2x2(
            +m1.m[1][1] * inversedDet,
            -m1.m[1][0] * inversedDet,
            -m1.m[0][1] * inversedDet,
            +m1.m[0][0] * inversedDet);
    }
}	// end namespace Math
}	// end namespace Oblivion