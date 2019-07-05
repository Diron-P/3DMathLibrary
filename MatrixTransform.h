#pragma once

#include <assert.h>

#include "MathFunctions.h"
#include "MatrixClipSpace.h"

namespace Oblivion {
namespace Math {
    // Scale along cardinal axes
    inline Matrix44 Scale(const Matrix44& m, const Vector3& v)
    {
        Matrix44 scale(1.0f);

        scale[0][0] = v.x;
        scale[1][1] = v.y;
        scale[2][2] = v.z;

        Matrix44 result = scale * m;

        result.SetTranslation(m.GetTranslation());
        return result;
    }

    // Scale in an arbitrary direction
    inline Matrix44 Scale(const Matrix44& m, Vector3& v, float& s)
    {
        Normalize(v);

        s -= 1.0f;

        float axisX = s * v.x;
        float axisY = s * v.y;
        float axisZ = s * v.z;

        Matrix44 scale(1.0f);

        scale[0][0] = 1.0f + axisX * v.x;
        scale[0][1] = axisX * v.y;
        scale[0][2] = axisX * v.z;

        scale[1][0] = axisX * v.y;
        scale[1][1] = 1.0f + axisY * v.y;
        scale[1][2] = axisY * v.z;

        scale[2][0] = axisX * v.z;
        scale[2][1] = axisY * v.z;
        scale[2][2] = 1.0f + axisZ * v.z;

        Matrix44 result = scale * m;

        result.SetTranslation(m.GetTranslation());
        return result;
    }

    // template <typename T>
    inline Matrix44 Rotate(const Matrix44& m, const float& angle, Vector3& v)
    {
        Normalize(v);

        float sin = Sin(angle);
        float cos = Cos(angle);
        float tmp = 1.0f - cos;

        float axisX = v.x * tmp;
        float axisY = v.y * tmp;
        float axisZ = v.z * tmp;

        Matrix44 rotate(1.0f);

        rotate[0][0] = v.x * axisX + cos;
        rotate[0][1] = v.x * axisY + v.z * sin;
        rotate[0][2] = v.x * axisZ - v.y * sin;

        rotate[1][0] = v.x * axisY - v.z * sin;
        rotate[1][1] = v.y * axisY + cos;
        rotate[1][2] = v.y * axisZ + v.x * sin;

        rotate[2][0] = v.x * axisZ + v.y * sin;
        rotate[2][1] = v.y * axisZ - v.x * sin;
        rotate[2][2] = v.z * axisZ + cos;

        Matrix44 result = rotate * m;
        result.SetTranslation(m.GetTranslation());
        return result;
    }

    inline Matrix44 Rotate(const Matrix44& m, const float& angle, const int& axis)
    {
        float cos = Cos(angle);
        float sin = Sin(angle);

        Matrix44 rotate(1.0f);

        switch (axis) {
            // Rotation about x axis
        case 1:
            rotate[1][1] = cos;
            rotate[1][2] = sin;
            rotate[2][1] = -sin;
            rotate[2][2] = cos;
            break;

            // Rotation about y axis
        case 2:
            rotate[0][0] = cos;
            rotate[0][2] = -sin;
            rotate[2][0] = sin;
            rotate[2][2] = cos;
            break;

            // Rotation about z axis
        case 3:
            rotate[0][0] = cos;
            rotate[0][1] = sin;
            rotate[1][0] = -sin;
            rotate[1][1] = cos;
            break;

        default:
            assert("Invalid input");
        }

        Matrix44 result = rotate * m;
        result.SetTranslation(m.GetTranslation());
        return result;
    }

    inline Matrix44 Translate(const Matrix44& m, const Vector3& v)
    {
        Matrix44 result(m);

        result[3][0] = v.x + m[3][0] * v.x;
        result[3][1] = v.y + m[3][1] * v.y;
        result[3][2] = v.z + m[3][2] * v.z;

        return result;
    }

    // Reflect about an arbitrary plane
    inline Matrix44 Reflect(const Matrix44& m, Vector3& v)
    {
        Normalize(v);

        float axisX = -2.0f * v.x;
        float axisY = -2.0f * v.y;
        float axisZ = -2.0f * v.z;

        Matrix44 reflect(1.0f);

        reflect[0][0] = 1.0f + axisX * v.x;
        reflect[0][1] = axisX * v.y;
        reflect[0][2] = axisX * v.z;

        reflect[1][0] = axisX * v.y;
        reflect[1][1] = 1.0f + axisY * v.y;
        reflect[1][2] = axisY * v.z;

        reflect[2][0] = axisX * v.z;
        reflect[2][1] = axisY * v.z;
        reflect[2][2] = 1.0f + axisZ * v.z;

        return reflect * m;
    }

    inline Matrix44 LookAtLH(const Vector3& eye, const Vector3& target, Vector3& tmp)
    {
        Vector3 forward = target - eye;
        Normalize(forward);
        Normalize(tmp);
        Vector3 right = CrossProduct(tmp, forward);
        Vector3 up = CrossProduct(forward, right);

        Matrix44 viewMat(1.0f);

        viewMat[0][0] = right.x;
        viewMat[0][1] = right.y;
        viewMat[0][2] = right.z;
        viewMat[1][0] = up.x;
        viewMat[1][1] = up.y;
        viewMat[1][2] = up.z;
        viewMat[2][0] = forward.x;
        viewMat[2][1] = forward.y;
        viewMat[2][2] = forward.z;
        viewMat[3][0] = -DotProduct(right, eye);
        viewMat[3][1] = -DotProduct(up, eye);
        viewMat[3][2] = DotProduct(forward, eye);

        return viewMat;
    }
} // namespace Math
} // namespace Oblivion