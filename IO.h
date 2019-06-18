#pragma once

#include <iostream>
#include "Mappings.h"

namespace Oblivion {
namespace Math {
    template <typename T>
    inline std::ostream& operator<<(std::ostream& out, const Vector2D& v)
    {
        out << "Vector2D(" << v.x << ", " << v.y << ")";
        return out;
    }

	template <typename T>
    inline std::ostream& operator<<(std::ostream& out, const Vector3D<T>& v)
    {
        out << "Vector3D(" << v.x << ", " << v.y << ", " << v.z << ")";
        return out;
    }

    template <typename T>
    inline std::ostream& operator<<(std::ostream& out, const Vector4D<T>& v)
    {
        out << "Vector4D(" << v.x << ", " << v.y << ", " << v.z << ", " << v.w << ")";
        return out;
    }

	template <typename T>
    inline std::ostream& operator<<(std::ostream& out, const Quaternion<T>& q)
    {
        out << "Quat[" << q.w << ", " << q.v << "]";
        return out;
    }
}	// end namespace Math
}	// end namespace Oblivion