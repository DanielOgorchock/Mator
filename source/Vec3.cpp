#include "Mator/3Dim/Vec3.h"

#include <math.h>
#include "Mator/3Dim/Mat3.h"
#include "Mator/2Dim/Vec2.h"

namespace mtr
{

//public
	//ctrs
	Vec3::Vec3():
		x(0),
		y(0),
		z(0)
	{

	}

	Vec3::Vec3(float nx, float ny, float nz):
		x(nx),
		y(ny),
		z(nz)
	{

	}

	Vec3::Vec3(float mag, const Vec3 &dir)
	{
		*this=dir.getUnit()*mag;
	}

	Vec3::Vec3(const Vec2 &vec, float nz):
		x(vec.x),
		y(vec.y),
		z(nz)
	{

	}

	Vec3::Vec3(const Vec3 &vec):
		x(vec.x),
		y(vec.y),
		z(vec.z)
	{

	}

	//dtr
	Vec3::~Vec3()
	{

	}

	//alter
	void Vec3::normalize()
	{
		float mag=getMag();
		if(mag!=0)
		{
			*this/=mag;
		}
	}

	void Vec3::rotateAbout(float radians, const Vec3 &vec)
	{
		*this=Mat3::buildRotationMatrix3D(radians, vec)*(*this);
	}

	void Vec3::rotate(const Vec3 &vec)
	{
		*this=Mat3::buildRotationMatrix3D(vec)*(*this);
	}

	//gets
	float Vec3::getMag() const
	{
		return sqrtf(x*x+y*y+z*z);
	}

	float Vec3::getMagSquared() const
	{
		return x*x+y*y+z*z;
	}

	Vec3 Vec3::getUnit() const
	{
		float mag=getMag();
		if(mag!=0)
		{
			return *this/mag;
		}
		else
		{
			return *this;
		}
	}

	Vec3 Vec3::getProjectionOn(const Vec3 &vec) const
	{
		return Vec3((((*this)*vec)/(vec*vec))*vec);
	}

	Vec3 Vec3::getRotated(float radians, const Vec3 &vec) const
	{
		return Mat3::buildRotationMatrix3D(radians, vec)*(*this);
	}

	Vec3 Vec3::getRotated(const Vec3 &vec) const
	{
		return Mat3::buildRotationMatrix3D(vec)*(*this);
	}

	//statics
	float Vec3::angleBetween(const Vec3 &v1, const Vec3 &v2) 
	{
		return acos((v1*v2)/(v1.getMag()*v2.getMag()));
	}

	Vec3 Vec3::crossProduct(const Vec3 &v1, const Vec3 &v2)
	{
		return Vec3(v1.y*v2.z-v2.y*v1.z,
						v1.z*v2.x-v2.z*v1.x,
						 v1.x*v2.y-v2.x*v1.y);
	}

	//selfOperators
	const Vec3& Vec3::operator=(const Vec3 &vec)
	{
		x=vec.x;
		y=vec.y;
		z=vec.z;
		return *this;
	}

	const Vec3& Vec3::operator+=(const Vec3 &vec)
	{
		x+=vec.x;
		y+=vec.y;
		z+=vec.z;
		return *this;
	}

	const Vec3& Vec3::operator-=(const Vec3 &vec)
	{
		x-=vec.x;
		y-=vec.y;
		z-=vec.z;
		return *this;
	}

	const Vec3& Vec3::operator*=(float scalar)
	{
		x*=scalar;
		y*=scalar;
		z*=scalar;
		return *this;
	}

	const Vec3& Vec3::operator/=(float scalar)
	{
		x/=scalar;
		y/=scalar;
		z/=scalar;
		return *this;
	}

	const Vec3 Vec3::operator-() const
	{
		return Vec3(-x,-y,-z);
	}


	const Vec3 operator+(const Vec3 &v1, const Vec3 &v2)
	{
		return Vec3(v1.x+v2.x, v1.y+v2.y, v1.z+v2.z);
	}

	const Vec3 operator-(const Vec3 &v1, const Vec3 &v2)
	{
		return Vec3(v1.x-v2.x, v1.y-v2.y, v1.z-v2.z);
	}

	const float operator*(const Vec3 &v1, const Vec3 &v2)
	{
		return v1.x*v2.x+v1.y*v2.y+v1.z*v2.z;
	}

	const Vec3 operator*(const Vec3 &vec, float scalar)
	{
		return Vec3(vec.x*scalar, vec.y*scalar, vec.z*scalar);
	}

	const Vec3 operator*(float scalar, const Vec3 &vec)
	{
		return Vec3(vec.x*scalar, vec.y*scalar, vec.z*scalar);
	}

	const Vec3 operator/(const Vec3 &vec, float scalar)
	{
		return Vec3(vec.x/scalar, vec.y/scalar, vec.z/scalar);
	}
}
