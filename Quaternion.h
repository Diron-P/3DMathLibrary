#pragma once

#include "vector3d.h"
#include "vector4d.h"
#include "math.h"
#include <iostream>

namespace Oblivion
{
	namespace Math
	{
		class Quaternion
		{
		public:
			float w;
			Vector3D v;

			Quaternion();
			Quaternion(const float& w, const Vector3D& v);
			Quaternion(const Vector4D& v);
			Quaternion(const Quaternion& q);

			Quaternion& setIdentity();
			float magnitude() const;

			Quaternion& operator+=(const Quaternion& q);
			Quaternion& operator-=(const Quaternion& q);
			Quaternion& operator*=(const Quaternion& q);

			Quaternion operator+(const Quaternion& q2) const;
			Quaternion operator-(const Quaternion& q2) const;
			Quaternion operator*(const Quaternion& q2) const;
			bool operator==(const Quaternion& q) const;
			bool operator!=(const Quaternion& q) const;

			Quaternion inverse() const; //TODO
		};

		/**********************************************************************
		****************Quaternion constructor definitions*****************
		**********************************************************************/
		Quaternion::Quaternion()
			: w(0.0f)
		{
		}

		Quaternion::Quaternion(const float& w, const Vector3D& v)
			: w(w), v(v)
		{
		}

		Quaternion::Quaternion(const Vector4D& v)
			: w(v.w), v(v.x, v.y, v.z)
		{
		}

		Quaternion::Quaternion(const Quaternion& q)
			: w(q.w), v(q.v)
		{
		}

		/**********************************************************************
		****************Quaternion inline function definitions*****************
		**********************************************************************/
		inline Quaternion& Quaternion::setIdentity()
		{
			w = 1.0f;
			v.x = v.y = v.z = 0.0f;
			return *this;
		}

		inline float Quaternion::magnitude() const
		{
			return sqrt(w * w + (v.x * v.x + v.y * v.y + v.z * v.z));
		}

		inline Quaternion& Quaternion::operator+=(const Quaternion& q)
		{
			this->w += q.w;
			this->v += q.v;
			return *this;
		}

		inline Quaternion& Quaternion::operator-=(const Quaternion& q)
		{
			this->w -= q.w;
			this->v -= q.v;
			return *this;
		}

		inline Quaternion& Quaternion::operator*=(const Quaternion& q)
		{
			*this = *this * q;
			return *this;
		}

		inline Quaternion Quaternion::operator+(const Quaternion& q) const
		{
			return Quaternion(w + q.w, v + q.v);
		}

		inline Quaternion Quaternion::operator-(const Quaternion& q) const
		{
			return Quaternion(w - q.w, v - q.v);
		}

		inline Quaternion Quaternion::operator*(const Quaternion& q2) const
		{
			return Quaternion(
				w * q2.w - v.x * q2.v.x - v.y * q2.v.y - v.z * q2.v.z,
				Vector3D(w * q2.v.x + v.x * q2.w + v.y * q2.v.z - v.z * q2.v.y,
					w * q2.v.y + v.y * q2.w + v.z * q2.v.x - v.x * q2.v.z,
					w * q2.v.z + v.z * q2.w + v.x * q2.v.y - v.y * q2.v.x)
			);
		}

		inline bool Quaternion::operator==(const Quaternion& q) const
		{
			return w == q.w && v == q.v;
		}

		inline bool Quaternion::operator!=(const Quaternion& q) const
		{
			return w != q.w || v != q.v;
		}

		inline Quaternion Quaternion::inverse() const
		{
			return Quaternion(w, Vector3D(-(v.x), -(v.y), -(v.z)) );
		}


		/**********************************************************************
		*********************Output quaternions on console*********************
		**********************************************************************/
		inline std::ostream& operator<<(std::ostream& out, const Quaternion& q)
		{
			out << "Quat[" << q.w << ", " << q.v << "]";
			return out;
		}
	}
}