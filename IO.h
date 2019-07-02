#pragma once

#include <iostream>
#include "Vector3.h"
#include "Vector4.h"
//#include "Mat3x3.h"
//#include "Matrix4.h"

namespace Oblivion {
namespace Math {
    /*inline std::ostream& operator<<(std::ostream& out, const Vector2D& v)
    {
        out << "Vector2D(" << v.x << ", " << v.y << ")";
        return out;
    }*/

    inline std::ostream& operator<<(std::ostream& out, const Vector3& v)
    {
        out << "Vector3(" << v.x << ", " << v.y << ", " << v.z << ")";
        return out;
    }

    inline std::ostream& operator<<(std::ostream& out, const Vector4& v)
    {
        out << "Vector4(" << v.x << ", " << v.y << ", " << v.z << ", " << v.w << ")";
        return out;
    }

    /*inline std::ostream& operator<<(std::ostream& out, const Quaternion& q)
    {
        out << "Quat[" << q.w << ", " << q.v << "]";
        return out;
    }*/
}	// end namespace Math
}	// end namespace Oblivion