#pragma once

#include "Quaternion.h"
#include "Mat3x3.h"

namespace Oblivion {
namespace Math {
    template <typename T>
    class RotationMatrix {
    public:
		RotationMatrix()
        {
            memset(m, 0, sizeof(m[0][0]) * 3 * 3);
            m[0][0] = m[1][1] = m[2][2] = 1.0f;
        }

        
    };
} // end namespace Math
} // enad namespace Oblivion
