#pragma once

#include "Vector3D.h"

class RotationMatrix
{
public:
	RotationMatrix();
	~RotationMatrix();

	float m[3][3];

};



RotationMatrix::RotationMatrix()
{
	memset(m, 0, sizeof(m[0][0]) * 3 * 3);
	m[0][0] = m[1][1] = m[2][2] = 1.0f;
}


RotationMatrix::~RotationMatrix()
{
}
