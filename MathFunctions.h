#pragma once

#include <math.h>

//PI defines
#define PI 3.14159265359f 

namespace Oblivion
{
	namespace Math
	{
		//Trigonometric Functions
		inline float Sin(float fValue)
		{
			return (float)sin(fValue);
		}

		inline float Cos(float fValue)
		{
			return (float)cos(fValue);
		}

		inline float Tan(float fValue)
		{
			return (float)tan(fValue);
		}

		inline float ASin(float fValue)
		{
			return (float)asin(fValue);
		}

		inline float ACos(float fValue)
		{
			return (float)acos(fValue);
		}

		inline float ATan(float fValue)
		{
			return (float)atan(fValue);
		}

		inline float Max(float fValueA, float fValueB)
		{
			return (fValueA > fValueB) ? fValueA : fValueB;
		}

		inline float Min(float fValueA, float fValueB)
		{
			return (fValueA < fValueB) ? fValueA : fValueB;
		}

		inline float DegToRad(float fValue)
		{
			return (float)fValue * PI / 180.0f;
		}

		inline float RadToDeg(float fValue)
		{
			return (float)fValue * 180.0f / PI;
		}
	}
}


