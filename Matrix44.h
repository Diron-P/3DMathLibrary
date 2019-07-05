#pragma once

#include "Vector4.h"
#include <stdint.h>
#include <string.h>

namespace Oblivion {
namespace Math {
    class Matrix44 {
    public:
        float m[4][4];
        Matrix44();
        Matrix44(const float& diagonal);
        Matrix44(const float& num1, const float& num2, const float& num3, const float& num4, const float& num5, const float& num6, const float& num7, const float& num8, const float& num9, const float& num10, const float& num11, const float& num12, const float& num13, const float& num14, const float& num15, const float& num16);
        Matrix44(const Vector4& vx, const Vector4& vy, const Vector4& vz, const Vector4& vw);
		
        /*************************************************************
		//	MATRIX OPERATOR DECLARATIONS
		*************************************************************/
        friend Matrix44& operator*=(const Matrix44& m, const Matrix44& m1);
        friend Matrix44 operator*(const Matrix44& m, const float& scalar);
        friend Matrix44 operator*(const Matrix44& m, const Matrix44& m1);
        friend Vector3 operator*(const Matrix44& m, const Vector3& v);
        friend Vector4 operator*(const Matrix44& m, const Vector4& v);
        friend bool operator==(const Matrix44& m, const Matrix44& m1);
        friend bool operator!=(const Matrix44& m, const Matrix44& m1);
        
		/*************************************************************
		//	MATRIX ACCESSORS
		*************************************************************/
        /*const float& operator()(uint8_t i, uint8_t j) const
        {
            return m[i][j];
        }

        inline float& operator()(uint8_t i, uint8_t j)
        {
            return m[i][j];
        }*/

        const float* operator[](uint8_t i) const
        {
            return m[i];
        }

        float* operator[](uint8_t i)
        {
            return m[i];
        }
		
		/*************************************************************
		//	MEMBER FUNCTIONS
		*************************************************************/
        Matrix44& MakeZero();
        Matrix44& SetIdentity();
        Matrix44& SetTranslation(const Vector3& v);
        const Vector3& GetTranslation(void) const;
		float Determinant() const;
    };

    Matrix44::Matrix44()
    {
        memset(m, 0, sizeof(m[0][0]) * 4 * 4);
    }

    Matrix44::Matrix44(const float& diagonal)
    {
        memset(m, 0, sizeof(m[0][0]) * 4 * 4);
        m[0][0] = m[1][1] = m[2][2] = m[3][3] = diagonal;
    }

    Matrix44::Matrix44(const float& num1, const float& num2, const float& num3, const float& num4, const float& num5, const float& num6, const float& num7, const float& num8, const float& num9, const float& num10, const float& num11, const float& num12, const float& num13, const float& num14, const float& num15, const float& num16)
    {
        m[0][0] = num1;
        m[0][1] = num2;
        m[0][2] = num3;
        m[0][3] = num4;
        m[1][0] = num5;
        m[1][1] = num6;
        m[1][2] = num7;
        m[1][3] = num8;
        m[2][0] = num9;
        m[2][1] = num10;
        m[2][2] = num11;
        m[2][3] = num12;
        m[3][0] = num13;
        m[3][1] = num14;
        m[3][2] = num15;
        m[3][3] = num16;
    }

    // Parameters - basis vectors (x, y, z axes)
    Matrix44::Matrix44(const Vector4& vx, const Vector4& vy, const Vector4& vz, const Vector4& vw)
    {
        m[0][0] = vx.x;
        m[0][1] = vx.y;
        m[0][2] = vx.z;
        m[0][3] = 0.0f;
        m[1][0] = vy.x;
        m[1][1] = vy.y;
        m[1][2] = vy.z;
        m[1][3] = 0.0f;
        m[2][0] = vz.x;
        m[2][1] = vz.y;
        m[2][2] = vz.z;
        m[2][3] = 0.0f;
        m[3][0] = vw.x;
        m[3][1] = vw.y;
        m[3][2] = vw.z;
        m[3][3] = 1.0f;
    }

    Matrix44& operator*=(Matrix44& m, const Matrix44& m1)
    {
        // Row 1
        Vector4 tmp(m[0][0], m[0][1], m[0][2], m[0][3]);
        m[0][0] = tmp.x * m1[0][0] + tmp.y * m1[1][0] + tmp.z * m1[2][0] + tmp.w * m1[3][0];
        m[0][1] = tmp.x * m1[0][1] + tmp.y * m1[1][1] + tmp.z * m1[2][1] + tmp.w * m1[3][1];
        m[0][2] = tmp.x * m1[0][2] + tmp.y * m1[1][2] + tmp.z * m1[2][2] + tmp.w * m1[3][2];
        m[0][3] = tmp.x * m1[0][3] + tmp.y * m1[1][3] + tmp.z * m1[2][3] + tmp.w * m1[3][3];

        // Row 2
        tmp.x = m[1][0];
        tmp.y = m[1][1];
        tmp.z = m[1][2];
        tmp.w = m[1][3];
        m[1][0] = tmp.x * m1[0][0] + tmp.y * m1[1][0] + tmp.z * m1[2][0] + tmp.w * m1[3][0];
        m[1][1] = tmp.x * m1[0][1] + tmp.y * m1[1][1] + tmp.z * m1[2][1] + tmp.w * m1[3][1];
        m[1][2] = tmp.x * m1[0][2] + tmp.y * m1[1][2] + tmp.z * m1[2][2] + tmp.w * m1[3][2];
        m[1][3] = tmp.x * m1[0][3] + tmp.y * m1[1][3] + tmp.z * m1[2][3] + tmp.w * m1[3][3];

        // Row 3
        tmp.x = m[2][0];
        tmp.y = m[2][1];
        tmp.z = m[2][2];
        tmp.w = m[2][3];
        m[2][0] = tmp.x * m1[0][0] + tmp.y * m1[1][0] + tmp.z * m1[2][0] + tmp.w * m1[3][0];
        m[2][1] = tmp.x * m1[0][1] + tmp.y * m1[1][1] + tmp.z * m1[2][1] + tmp.w * m1[3][1];
        m[2][2] = tmp.x * m1[0][2] + tmp.y * m1[1][2] + tmp.z * m1[2][2] + tmp.w * m1[3][2];
        m[2][3] = tmp.x * m1[0][3] + tmp.y * m1[1][3] + tmp.z * m1[2][3] + tmp.w * m1[3][3];

        // Row 4
        tmp.x = m[3][0];
        tmp.y = m[3][1];
        tmp.z = m[3][2];
        tmp.w = m[3][3];
        m[3][0] = tmp.x * m1[0][0] + tmp.y * m1[1][0] + tmp.z * m1[2][0] + tmp.w * m1[3][0];
        m[3][1] = tmp.x * m1[0][1] + tmp.y * m1[1][1] + tmp.z * m1[2][1] + tmp.w * m1[3][1];
        m[3][2] = tmp.x * m1[0][2] + tmp.y * m1[1][2] + tmp.z * m1[2][2] + tmp.w * m1[3][2];
        m[3][3] = tmp.x * m1[0][3] + tmp.y * m1[1][3] + tmp.z * m1[2][3] + tmp.w * m1[3][3];

        return m;
    }

    Matrix44 operator*(const Matrix44& m, const float& scalar)
    {
        return Matrix44(
            scalar * m[0][0], scalar * m[0][1], scalar * m[0][2], scalar * m[0][3],
            scalar * m[1][0], scalar * m[1][1], scalar * m[1][2], scalar * m[1][3],
            scalar * m[2][0], scalar * m[2][1], scalar * m[2][2], scalar * m[2][3],
            scalar * m[3][0], scalar * m[3][1], scalar * m[3][2], scalar * m[3][3]);
    }

    Matrix44 operator*(const Matrix44& m, const Matrix44& m1)
    {
        return Matrix44(
            m[0][0] * m1[0][0] + m[0][1] * m1[1][0] + m[0][2] * m1[2][0] + m[0][3] * m1[3][0],
            m[0][0] * m1[0][1] + m[0][1] * m1[1][1] + m[0][2] * m1[2][1] + m[0][3] * m1[3][1],
            m[0][0] * m1[0][2] + m[0][1] * m1[1][2] + m[0][2] * m1[2][2] + m[0][3] * m1[3][2],
            m[0][0] * m1[0][3] + m[0][1] * m1[1][3] + m[0][2] * m1[2][3] + m[0][3] * m1[3][3],
            m[1][0] * m1[0][0] + m[1][1] * m1[1][0] + m[1][2] * m1[2][0] + m[1][3] * m1[3][0],
            m[1][0] * m1[0][1] + m[1][1] * m1[1][1] + m[1][2] * m1[2][1] + m[1][3] * m1[3][1],
            m[1][0] * m1[0][2] + m[1][1] * m1[1][2] + m[1][2] * m1[2][2] + m[1][3] * m1[3][2],
            m[1][0] * m1[0][3] + m[1][1] * m1[1][3] + m[1][2] * m1[2][3] + m[1][3] * m1[3][3],
            m[2][0] * m1[0][0] + m[2][1] * m1[1][0] + m[2][2] * m1[2][0] + m[2][3] * m1[3][0],
            m[2][0] * m1[0][1] + m[2][1] * m1[1][1] + m[2][2] * m1[2][1] + m[2][3] * m1[3][1],
            m[2][0] * m1[0][2] + m[2][1] * m1[1][2] + m[2][2] * m1[2][2] + m[2][3] * m1[3][2],
            m[2][0] * m1[0][3] + m[2][1] * m1[1][3] + m[2][2] * m1[2][3] + m[2][3] * m1[3][3],
            m[3][0] * m1[0][0] + m[3][1] * m1[1][0] + m[3][2] * m1[2][0] + m[3][3] * m1[3][0],
            m[3][0] * m1[0][1] + m[3][1] * m1[1][1] + m[3][2] * m1[2][1] + m[3][3] * m1[3][1],
            m[3][0] * m1[0][2] + m[3][1] * m1[1][2] + m[3][2] * m1[2][2] + m[3][3] * m1[3][2],
            m[3][0] * m1[0][3] + m[3][1] * m1[1][3] + m[3][2] * m1[2][3] + m[3][3] * m1[3][3]);
    }

    // Multiplies a matrix by a vector and returns a new vector.
    Vector3 operator*(const Matrix44& m, const Vector3& v)
    {
        return Vector3(
            v.x * m[0][0] + v.y * m[1][0] + v.z * m[2][0],
            v.x * m[0][1] + v.y * m[1][1] + v.z * m[2][1],
            v.x * m[0][2] + v.y * m[1][2] + v.z * m[2][2]);
    }

    // Multiplies a matrix by a position vector and returns a new position vector.
    Vector4 operator*(const Matrix44& m, const Vector4& v)
    {
        return Vector4(
            v.x * m[0][0] + v.y * m[1][0] + v.z * m[2][0] + m[3][0],
            v.x * m[0][1] + v.y * m[1][1] + v.z * m[2][1] + m[3][1],
            v.x * m[0][2] + v.y * m[1][2] + v.z * m[2][2] + m[3][2],
            1.0f);
    }

    bool operator==(const Matrix44& m, const Matrix44& m1)
    {
        return (m[0][0] == m1[0][0]) && (m[0][1] == m1[0][1]) && (m[0][2] == m1[0][2]) && (m[0][3] == m1[0][3])
            && (m[1][0] == m1[1][0]) && (m[1][1] == m1[1][1]) && (m[1][2] == m1[1][2]) && (m[1][3] == m1[1][3])
            && (m[2][0] == m1[2][0]) && (m[2][1] == m1[2][1]) && (m[2][2] == m1[2][2]) && (m[2][3] == m1[2][3])
            && (m[3][0] == m1[3][0]) && (m[3][1] == m1[3][1]) && (m[3][2] == m1[3][2]) && (m[3][3] == m1[3][3]);
    }

    bool operator!=(const Matrix44& m, const Matrix44& m1)
    {
        return (m[0][0] != m1[0][0]) || (m[0][1] != m1[0][1]) || (m[0][2] != m1[0][2]) || (m[0][3] != m1[0][3])
            || (m[1][0] != m1[1][0]) || (m[1][1] != m1[1][1]) || (m[1][2] != m1[1][2]) || (m[1][3] != m1[1][3])
            || (m[2][0] != m1[2][0]) || (m[2][1] != m1[2][1]) || (m[2][2] != m1[2][2]) || (m[2][3] != m1[2][3])
            || (m[3][0] != m1[3][0]) || (m[3][1] != m1[3][1]) || (m[3][2] != m1[3][2]) || (m[3][3] != m1[3][3]);
    }

	inline Matrix44& Matrix44::MakeZero()
    {
        memset(m, 0, sizeof(m[0][0]) * 4 * 4);
        return *this;
    }

    inline Matrix44& Matrix44::SetIdentity()
    {
        memset(m, 0, sizeof(m[0][0]) * 4 * 4);
        m[0][0] = m[1][1] = m[2][2] = m[3][3] = 1.0f;
        return *this;
    }

    inline Matrix44& Matrix44::SetTranslation(const Vector3& v)
    {
        m[3][0] = v.x;
        m[3][1] = v.y;
        m[3][2] = v.z;

        return *this;
    }

    inline const Vector3& Matrix44::GetTranslation(void) const
    {
        return (*reinterpret_cast<const Vector3*>(m[3]));
    }

    inline float Matrix44::Determinant() const
    {
        return m[0][0] * (m[1][1] * (m[2][2] * m[3][3] - m[2][3] * m[3][2]) - m[1][2] * (m[2][1] * m[3][3] - m[2][3] * m[3][1]) + m[1][3] * (m[2][1] * m[3][2] - m[2][2] * m[3][1]))
            - m[0][1] * (m[1][0] * (m[2][2] * m[3][3] - m[2][3] * m[3][2]) - m[1][2] * (m[2][0] * m[3][3] - m[2][3] * m[3][0]) + m[1][3] * (m[2][0] * m[3][2] - m[2][2] * m[3][0]))
            + m[0][2] * (m[1][0] * (m[2][1] * m[3][3] - m[2][3] * m[3][1]) - m[1][1] * (m[2][0] * m[3][3] - m[2][3] * m[3][0]) + m[1][3] * (m[2][0] * m[3][1] - m[2][1] * m[3][0]))
            - m[0][3] * (m[1][0] * (m[2][1] * m[3][2] - m[2][2] * m[3][1]) - m[1][1] * (m[2][0] * m[3][2] - m[2][2] * m[3][0]) + m[1][2] * (m[2][0] * m[3][1] - m[2][1] * m[3][0]));
    }

	/********************************************************************
	// NON-MEMBER FUNCTIONS
	********************************************************************/
    inline Matrix44 Transpose(const Matrix44& m)
    {
        return Matrix44(
            Vector4(m[0][0], m[1][0], m[2][0], m[3][0]),
            Vector4(m[0][1], m[1][1], m[2][1], m[3][1]),
            Vector4(m[0][2], m[1][2], m[2][2], m[3][2]),
            Vector4(m[0][3], m[1][3], m[2][3], m[3][3]));
    }
}
}
