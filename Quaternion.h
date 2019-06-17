#pragma once

#include "Vector3D.h"
#include "Vector4D.h"
#include "math.h"
#include <iostream>

namespace Oblivion {
namespace Math {
    template <typename T>
    class Quaternion {
    public:
        T w;
        Vector3D<T> v;

        /**********************************************************************
			****************Quaternion constructor definitions*****************
			**********************************************************************/

        Quaternion()
            : w(0.0f)
        {
        }

        Quaternion(const float& w, const Vector3D<T>& v)
            : w(w)
            , v(v)
        {
        }

        Quaternion(const Vector4D<T>& v)
            : w(v.w)
            , v(v.x, v.y, v.z)
        {
        }

        Quaternion(const Quaternion& q)
            : w(q.w)
            , v(q.v)
        {
        }

        /**********************************************************************
			****************Quaternion inline function definitions*****************
			**********************************************************************/

        inline Quaternion& SetIdentity()
        {
            w = 1.0f;
            v.x = v.y = v.z = 0.0f;
            return *this;
        }

        inline Quaternion& operator+=(const Quaternion& q)
        {
            this->w += q.w;
            this->v += q.v;
            return *this;
        }

        inline Quaternion& operator-=(const Quaternion& q)
        {
            this->w -= q.w;
            this->v -= q.v;
            return *this;
        }

        inline Quaternion& operator*=(const Quaternion& q)
        {
            *this = *this * q;
            return *this;
        }

        inline Quaternion operator+(const Quaternion& q) const
        {
            return Quaternion(w + q.w, v + q.v);
        }

        inline Quaternion operator-(const Quaternion& q) const
        {
            return Quaternion(w - q.w, v - q.v);
        }

        inline Quaternion operator*(const Quaternion& q2) const
        {
            return Quaternion(
                w * q2.w - v.x * q2.v.x - v.y * q2.v.y - v.z * q2.v.z,
                Vector3D<T>(w * q2.v.x + v.x * q2.w + v.y * q2.v.z - v.z * q2.v.y,
                    w * q2.v.y + v.y * q2.w + v.z * q2.v.x - v.x * q2.v.z,
                    w * q2.v.z + v.z * q2.w + v.x * q2.v.y - v.y * q2.v.x));
        }

        inline Quaternion operator*(const float& scalar) const
        {
            return Quaternion(w * scalar, v * scalar);
        }

        inline bool operator==(const Quaternion& q) const
        {
            return w == q.w && v == q.v;
        }

        inline bool operator!=(const Quaternion& q) const
        {
            return w != q.w || v != q.v;
        }

        inline T Magnitude() const
        {
            return sqrt(w * w) + v.Magnitude();
        }

        // Can be further optimized
        inline Quaternion Inverse() const
        {
            Quaternion conjugate(w, Vector3D<T>(-(v.x), -(v.y), -(v.z)));

            T inverseMag = 1.0f / Magnitude();

            return Quaternion(conjugate * inverseMag);
        }

        inline Quaternion& Conjugated()
        {
            v.x = -v.x;
            v.y = -v.y;
            v.z = -v.z;
            return *this;
        }

        /*inline Mat3x3<T> ToRotationMatrix() const
        {
            Mat3x3<T> rotMatrix;

            rotMatrix.m[0][0] = 1.0f - 2.0f * v.y * v.y - 2 * v.z * v.z;
            rotMatrix.m[0][1] = 2.0f * v.x * v.y + 2.0f * w * v.z;
            rotMatrix.m[0][2] = 2.0f * v.x * v.z - 2.0f * v.w * v.y;

            rotMatrix.m[1][0] = 2 * v.x * v.y - 2.0f * w * v.z;
            rotMatrix.m[1][1] = 1.0f - 2 * v.x * v.x - 2.0f * v.z * v.z;
            rotMatrix.m[1][2] = 2.0f * v.y * v.z + 2.0f * w * v.x;

            rotMatrix.m[2][0] = 2.0f * v.x * v.z + 2.0f * w * v.y;
            rotMatrix.m[2][1] = 2.0f * v.y * v.z - 2.0f * w * v.x;
            rotMatrix.m[2][2] = 1.0f - 2 * v.x * v.x - 2.0f * v.y * v.y;

            return rotMatrix;
        }*/

        /**********************************************************************
			*********************Output quaternions on console*********************
			**********************************************************************/
        inline std::ostream& operator<<(std::ostream& out)
        {
            out << "Quat[" << w << ", " << v << "]";
            return out;
        }
    };

    typedef Quaternion<float> Quatf;
    typedef Quaternion<double> Quatd;

} // end namespace Math
} // end namespace Oblivion