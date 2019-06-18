#pragma once

#include "Mappings.h"

namespace Oblivion {
namespace Math {
    template <typename T>
    class Mat4x4 {
    public:
        T m[4][4];

        inline Mat4x4()
        {
            memset(m, 0, sizeof(m[0][0]) * 4 * 4);
            m[0][0] = m[1][1] = m[2][2] = m[3][3] = 1.0f;
        }

        inline Mat4x4(const T diagonal)
        {
            memset(m, 0, sizeof(m[0][0]) * 4 * 4);
            m[0][0] = m[1][1] = m[2][2] = m[3][3] = diagonal;
        }

        inline Mat4x4(const T& num1, const T& num2, const T& num3, const T& num4, const T& num5, const T& num6, const T& num7, const T& num8, const T& num9, const T& num10, const T& num11, const T& num12, const T& num13, const T& num14, const T& num15, const T& num16)
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
        inline Mat4x4(const Vector4D<T>& vx, const Vector4D<T>& vy, const Vector4D<T>& vz, const Vector4D<T>& vw)
        {
            m[0][0] = vx.x;
            m[0][1] = vx.y;
            m[0][2] = vx.z;
            m[0][3] = vx.w;
            m[1][0] = vy.x;
            m[1][1] = vy.y;
            m[1][2] = vy.z;
            m[1][3] = vy.w;
            m[2][0] = vz.x;
            m[2][1] = vz.y;
            m[2][2] = vz.z;
            m[2][3] = vz.w;
            m[3][0] = vw.x;
            m[3][1] = vw.y;
            m[3][2] = vw.z;
            m[3][3] = vw.w;
        }

        inline Mat4x4& Zero()
        {
            memset(m, 0, sizeof(m[0][0]) * 4 * 4);
            return *this;
        }

        inline Mat4x4& Identity()
        {
            m[0][0] = m[1][1] = m[2][2] = m[3][3] = 1.0f;
            return *this;
        }

        inline Vector3D<T> GetTranslation() const
        {
            return Vector3D<T>(m[3][0], m[3][1], m[3][2]);
        }

        inline Vector4D<T> GetRow(int i) const
        {
            return Vector4D<T>(m[i][0], m[i][1], m[i][2], m[i][3]);
        }

        inline Mat4x4& SetRow(int i, const Vector3D<T>& column)
        {
            m[i][0] = column.x;
            m[i][1] = column.y;
            m[i][2] = column.z;
            m[i][3] = column.w;

            return *this;
        }

        inline Mat4x4& operator*=(const Mat4x4& n)
        {
            //Column 1
            Vector4D<T> col1(m[0][0], m[1][0], m[2][0], m[3][0]);
            m[0][0] = col1.x * n.m[0][0] + col1.y * n.m[0][1] + col1.z * n.m[0][2] + col1.w * n.m[0][3];
            m[1][0] = col1.x * n.m[1][0] + col1.y * n.m[1][1] + col1.z * n.m[1][2] + col1.w * n.m[1][3];
            m[2][0] = col1.x * n.m[2][0] + col1.y * n.m[2][1] + col1.z * n.m[2][2] + col1.w * n.m[2][3];
            m[3][0] = col1.x * n.m[3][0] + col1.y * n.m[3][1] + col1.z * n.m[3][2] + col1.w * n.m[3][3];

            //Column 2
            Vector4D<T> col2(m[0][1], m[1][1], m[2][1], m[3][1]);
            m[0][1] = col2.x * n.m[0][0] + col2.y * n.m[0][1] + col2.z * n.m[0][2] + col2.w * n.m[0][3];
            m[1][1] = col2.x * n.m[1][0] + col2.y * n.m[1][1] + col2.z * n.m[1][2] + col2.w * n.m[1][3];
            m[2][1] = col2.x * n.m[2][0] + col2.y * n.m[2][1] + col2.z * n.m[2][2] + col2.w * n.m[2][3];
            m[3][1] = col2.x * n.m[3][0] + col2.y * n.m[3][1] + col2.z * n.m[3][2] + col2.w * n.m[3][3];

            //Column 3
            Vector4D<T> col3(m[0][2], m[1][2], m[2][2], m[3][2]);
            m[0][2] = col3.x * n.m[0][0] + col3.y * n.m[0][1] + col3.z * n.m[0][2] + col3.w * n.m[0][3];
            m[1][2] = col3.x * n.m[1][0] + col3.y * n.m[1][1] + col3.z * n.m[1][2] + col3.w * n.m[1][3];
            m[2][2] = col3.x * n.m[2][0] + col3.y * n.m[2][1] + col3.z * n.m[2][2] + col3.w * n.m[2][3];
            m[3][2] = col3.x * n.m[3][0] + col3.y * n.m[3][1] + col3.z * n.m[3][2] + col3.w * n.m[3][3];

            //Column 4
            Vector4D<T> col4(m[0][3], m[1][3], m[2][3], m[3][3]);
            m[0][3] = col4.x * n.m[0][0] + col4.y * n.m[0][1] + col4.z * n.m[0][2] + col4.w * n.m[0][3];
            m[1][3] = col4.x * n.m[1][0] + col4.y * n.m[1][1] + col4.z * n.m[1][2] + col4.w * n.m[1][3];
            m[2][3] = col4.x * n.m[2][0] + col4.y * n.m[2][1] + col4.z * n.m[2][2] + col4.w * n.m[2][3];
            m[3][3] = col4.x * n.m[3][0] + col4.y * n.m[3][1] + col4.z * n.m[3][2] + col4.w * n.m[3][3];

            return *this;
        }

        inline Mat4x4& operator*(const float& scalar) const
        {
            return Mat4x4(
                scalar * m[0][0], scalar * m[0][1], scalar * m[0][2], scalar * m[0][3],
                scalar * m[1][0], scalar * m[1][1], scalar * m[1][2], scalar * m[1][3],
                scalar * m[2][0], scalar * m[2][1], scalar * m[2][2], scalar * m[2][3],
                scalar * m[3][0], scalar * m[3][1], scalar * m[3][2], scalar * m[3][3]);
        }

        inline Mat4x4 operator*(const Mat4x4& m2) const
        {
            return Mat4x4(
                m[0][0] * m2[0][0] + m[0][1] * m2[1][0] + m[0][2] * m2[2][0] + m[0][3] * m2[3][0],
                m[0][0] * m2[0][1] + m[0][1] * m2[1][1] + m[0][2] * m2[2][1] + m[0][3] * m2[3][1],
                m[0][0] * m2[0][2] + m[0][1] * m2[1][2] + m[0][2] * m2[2][2] + m[0][3] * m2[3][2],
                m[0][0] * m2[0][3] + m[0][1] * m2[1][3] + m[0][2] * m2[2][3] + m[0][3] * m2[3][3],
                m[1][0] * m2[0][0] + m[1][1] * m2[1][0] + m[1][2] * m2[2][0] + m[1][3] * m2[3][0],
                m[1][0] * m2[0][1] + m[1][1] * m2[1][1] + m[1][2] * m2[2][1] + m[1][3] * m2[3][1],
                m[1][0] * m2[0][2] + m[1][1] * m2[1][2] + m[1][2] * m2[2][2] + m[1][3] * m2[3][2],
                m[1][0] * m2[0][3] + m[1][1] * m2[1][3] + m[1][2] * m2[2][3] + m[1][3] * m2[3][3],
                m[2][0] * m2[0][0] + m[2][1] * m2[1][0] + m[2][2] * m2[2][0] + m[2][3] * m2[3][0],
                m[2][0] * m2[0][1] + m[2][1] * m2[1][1] + m[2][2] * m2[2][1] + m[2][3] * m2[3][1],
                m[2][0] * m2[0][2] + m[2][1] * m2[1][2] + m[2][2] * m2[2][2] + m[2][3] * m2[3][2],
                m[2][0] * m2[0][3] + m[2][1] * m2[1][3] + m[2][2] * m2[2][3] + m[2][3] * m2[3][3],
                m[3][0] * m2[0][0] + m[3][1] * m2[1][0] + m[3][2] * m2[2][0] + m[3][3] * m2[3][0],
                m[3][0] * m2[0][1] + m[3][1] * m2[1][1] + m[3][2] * m2[2][1] + m[3][3] * m2[3][1],
                m[3][0] * m2[0][2] + m[3][1] * m2[1][2] + m[3][2] * m2[2][2] + m[3][3] * m2[3][2],
                m[3][0] * m2[0][3] + m[3][1] * m2[1][3] + m[3][2] * m2[2][3] + m[3][3] * m2[3][3]);
        }

        inline Vector4D<T> operator*(const Vector4D<T>& v) const
        {
            return Vector4D<T>(
                v.x * m[0][0] + v.y * m[1][0] + v.z * m[2][0] + v.w * m[3][0],
                v.x * m[0][1] + v.y * m[1][1] + v.z * m[2][1] + v.w * m[3][1],
                v.x * m[0][2] + v.y * m[1][2] + v.z * m[2][2] + v.w * m[3][2],
                v.x * m[0][3] + v.y * m[1][3] + v.z * m[2][3] + v.w * m[3][3]);
        }

        inline bool operator==(const Mat4x4& m2) const
        {
            return (m[0][0] == m2[0][0]) && (m[0][1] == m2[0][1]) && //1st row
                (m[0][2] == m2[0][2]) && (m[0][3] == m2[0][3]) && (m[1][0] == m2[1][0]) && (m[1][1] == m2[1][1]) && //2nd row
                (m[1][2] == m2[1][2]) && (m[1][3] == m2[1][3]) && (m[2][0] == m2[2][0]) && (m[2][1] == m2[2][1]) && //3rd row
                (m[2][2] == m2[2][2]) && (m[2][3] == m2[2][3]) && (m[3][0] == m2[3][0]) && (m[3][1] == m2[3][1]) && //4th row
                (m[3][2] == m2[3][2]) && (m[3][3] == m2[3][3]);
        }

        inline bool operator!=(const Mat4x4& m2) const
        {
            return (m[0][0] != m2[0][0]) || (m[0][1] != m2[0][1]) || //1st row
                (m[0][2] != m2[0][2]) || (m[0][3] != m2[0][3]) || (m[1][0] != m2[1][0]) || (m[1][1] != m2[1][1]) || //2nd row
                (m[1][2] != m2[1][2]) || (m[1][3] != m2[1][3]) || (m[2][0] != m2[2][0]) || (m[2][1] != m2[2][1]) || //3rd row
                (m[2][2] != m2[2][2]) || (m[2][3] != m2[2][3]) || (m[3][0] != m2[3][0]) || (m[3][1] != m2[3][1]) || //4th row
                (m[3][2] != m2[3][2]) || (m[3][3] != m2[3][3]);
        }

        const T* operator[](uint8_t i) const
        {
            return m[i];
        }

        T* operator[](uint8_t i)
        {
            return m[i];
        }

        inline Mat4x4 Transpose() const
        {
            return Mat4x4(
                Vector4D<T>(m[0][0], m[1][0], m[2][0], m[3][0]),
                Vector4D<T>(m[0][1], m[1][1], m[2][1], m[3][1]),
                Vector4D<T>(m[0][2], m[1][2], m[2][2], m[3][2]),
                Vector4D<T>(m[0][3], m[1][3], m[2][3], m[3][3]));
        }

        inline T Determinant() const
        {
            return m[0][0] * (m[1][1] * (m[2][2] * m[3][3] - m[2][3] * m[3][2]) - m[1][2] * (m[2][1] * m[3][3] - m[2][3] * m[3][1]) + m[1][3] * (m[2][1] * m[3][2] - m[2][2] * m[3][1])) -

                m[0][1] * (m[1][0] * (m[2][2] * m[3][3] - m[2][3] * m[3][2]) - m[1][2] * (m[2][0] * m[3][3] - m[2][3] * m[3][0]) + m[1][3] * (m[2][0] * m[3][2] - m[2][2] * m[3][0])) +

                m[0][2] * (m[1][0] * (m[2][1] * m[3][3] - m[2][3] * m[3][1]) - m[1][1] * (m[2][0] * m[3][3] - m[2][3] * m[3][0]) + m[1][3] * (m[2][0] * m[3][1] - m[2][1] * m[3][0])) -

                m[0][3] * (m[1][0] * (m[2][1] * m[3][2] - m[2][2] * m[3][1]) - m[1][1] * (m[2][0] * m[3][2] - m[2][2] * m[3][0]) + m[1][2] * (m[2][0] * m[3][1] - m[2][1] * m[3][0]));
        }

        inline bool Inverse(Mat4x4& dst) const
        {
            T determinant = Determinant();

            if (determinant == 0.0f) {
                return false;
            }

            T inversedDet = 1.0f / determinant;

            // Row 1 transposed
            dst[0][0] = (m[1][1] * m[2][2] * m[3][3] + m[1][2] * m[2][3] * m[3][1] + m[1][3] * m[2][1] * m[3][2]
                            - m[1][1] * m[2][3] * m[3][2] - m[1][2] * m[2][1] * m[3][3] - m[1][3] * m[2][2] * m[3][1])
                * inversedDet;

            dst[1][0] = -(m[1][0] * m[2][2] * m[3][3] + m[1][2] * m[2][3] * m[3][0] + m[1][3] * m[2][0] * m[3][2]
                            - m[1][0] * m[2][3] * m[3][2] - m[1][2] * m[2][0] * m[3][3] - m[1][3] * m[2][2] * m[3][0])
                * inversedDet;

            dst[2][0] = (m[1][0] * m[2][1] * m[3][3] + m[1][1] * m[2][3] * m[3][0] + m[1][3] * m[2][0] * m[3][1]
                            - m[1][0] * m[2][3] * m[3][1] - m[1][1] * m[2][0] * m[3][3] - m[1][3] * m[2][1] * m[3][0])
                * inversedDet;

            dst[3][0] = -(m[1][0] * m[2][1] * m[3][2] + m[1][1] * m[2][2] * m[3][0] + m[1][2] * m[2][0] * m[3][1]
                            - m[1][0] * m[2][2] * m[3][1] - m[1][1] * m[2][0] * m[3][2] - m[1][2] * m[2][1] * m[3][0])
                * inversedDet;

            // Row 2 transposed
            dst[0][1] = -(m[0][1] * m[2][2] * m[3][3] + m[0][2] * m[2][3] * m[3][1] + m[0][3] * m[2][1] * m[3][2]
                            - m[0][1] * m[2][3] * m[3][2] - m[0][2] * m[2][1] * m[3][3] - m[0][3] * m[2][2] * m[3][1])
                * inversedDet;

            dst[1][1] = (m[0][0] * m[2][2] * m[3][3] + m[0][2] * m[2][3] * m[3][0] + m[0][3] * m[2][0] * m[3][2]
                            - m[0][0] * m[2][3] * m[3][2] - m[0][2] * m[2][0] * m[3][3] - m[0][3] * m[2][2] * m[3][0])
                * inversedDet;

            dst[2][1] = -(m[0][0] * m[2][1] * m[3][3] + m[0][1] * m[2][3] * m[3][0] + m[0][3] * m[2][0] * m[3][1]
                            - m[0][0] * m[2][3] * m[3][1] - m[0][1] * m[2][0] * m[3][3] - m[0][3] * m[2][1] * m[3][0])
                * inversedDet;

            dst[3][1] = (m[0][0] * m[2][1] * m[3][2] + m[0][1] * m[2][2] * m[3][0] + m[0][2] * m[2][0] * m[3][1]
                            - m[0][0] * m[2][2] * m[3][1] - m[0][1] * m[2][0] * m[3][2] - m[0][2] * m[2][1] * m[3][0])
                * inversedDet;

            // Row 3 transposed
            dst[0][2] = (m[0][1] * m[1][2] * m[3][3] + m[0][2] * m[1][3] * m[3][1] + m[0][3] * m[1][1] * m[3][2]
                            - m[0][1] * m[1][3] * m[3][2] - m[0][2] * m[1][1] * m[3][3] - m[0][3] * m[1][2] * m[3][1])
                * inversedDet;

            dst[1][2] = -(m[0][0] * m[1][2] * m[3][3] + m[0][2] * m[1][3] * m[3][0] + m[0][3] * m[1][0] * m[3][2]
                            - m[0][0] * m[1][3] * m[3][2] - m[0][2] * m[1][0] * m[3][3] - m[0][3] * m[1][2] * m[3][0])
                * inversedDet;

            dst[2][2] = (m[0][0] * m[1][1] * m[3][3] + m[0][1] * m[1][3] * m[3][0] + m[0][3] * m[1][0] * m[3][1]
                            - m[0][0] * m[1][3] * m[3][1] - m[0][1] * m[1][0] * m[3][3] - m[0][3] * m[1][1] * m[3][0])
                * inversedDet;

            dst[3][2] = -(m[0][0] * m[1][1] * m[3][2] + m[0][1] * m[1][2] * m[3][0] + m[0][2] * m[1][0] * m[3][1]
                            - m[0][0] * m[1][2] * m[3][1] - m[0][1] * m[1][0] * m[3][2] - m[0][2] * m[1][1] * m[3][0])
                * inversedDet;

            // Row 4 transposed
            dst[0][3] = -(m[0][1] * m[1][2] * m[2][3] + m[0][2] * m[1][3] * m[2][1] + m[0][3] * m[1][1] * m[2][2]
                            - m[0][1] * m[1][3] * m[2][2] - m[0][2] * m[1][1] * m[2][3] - m[0][3] * m[1][2] * m[2][1])
                * inversedDet;

            dst[1][3] = (m[0][0] * m[1][2] * m[2][3] + m[0][2] * m[1][3] * m[2][0] + m[0][3] * m[1][0] * m[2][2]
                            - m[0][0] * m[1][3] * m[2][2] - m[0][2] * m[1][0] * m[2][3] - m[0][3] * m[1][2] * m[2][0])
                * inversedDet;

            dst[2][3] = -(m[0][0] * m[1][1] * m[2][3] + m[0][1] * m[2][3] * m[2][0] + m[0][3] * m[1][0] * m[2][1]
                            - m[0][0] * m[1][3] * m[2][1] - m[0][1] * m[1][0] * m[2][3] - m[0][3] * m[1][1] * m[2][0])
                * inversedDet;

            dst[3][3] = (m[0][0] * m[1][1] * m[2][2] + m[0][1] * m[1][2] * m[2][0] + m[0][2] * m[1][0] * m[2][1]
                            - m[0][0] * m[1][2] * m[2][1] - m[0][1] * m[1][0] * m[2][2] - m[0][2] * m[1][1] * m[2][0])
                * inversedDet;

            return true;
        }

        inline Mat4x4& FromQuatToMat(const Quaternion<T>& q)
        {
            float qw = 2.0f * q.w;
            float qx = 2.0f * q.v.x;
            float qy = 2.0f * q.v.y;
            float qz = 2.0f * q.v.z;

            m[0][0] = 1.0f - qy * q.v.y - qz * q.v.z;
            m[0][1] = qx * q.v.y + qw * q.v.z;
            m[0][2] = qx * q.v.z - qw * q.v.y;

            m[1][0] = qx * q.v.y - qw * q.v.z;
            m[1][1] = 1.0f - qx * q.v.x - qz * q.v.z;
            m[1][2] = qy * q.v.z + qw * q.v.x;

            m[2][0] = qx * q.v.z + qw * q.v.y;
            m[2][1] = qy * q.v.z - qw * q.v.x;
            m[2][2] = 1.0f - qx * q.v.x - qy * q.v.y;

            return *this;
        }

        //inline Mat4x4 Scale(const Vector3D<T>& v)
        //{
        //	Mat4x4 result(1.0f);

        //	result[0][0] = v.x;
        //	result[1][1] = v.y;
        //	result[2][2] = v.z;

        //	return result * m;
        //}

        //inline Mat4x4& Translate(const Vector3D<T>& v)
        //{
        //	//Mat4x4 result(m);

        //	//result.Idntity();

        //	m[3][0] = v.x + m[3][0] * v.x;
        //	m[3][1] = v.y + m[3][1] * v.y;
        //	m[3][2] = v.z + m[3][2] * v.z;

        //	return *this;
        //}
    };
}	// end namespace Math
}	// end namespace Oblivion