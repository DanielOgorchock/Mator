#include "mator/4Dim/Vec4.h"

#include <math.h>
#include "mator/3Dim/Vec3.h"

namespace mtr
{

//public
	//ctrs
	Vec4::Vec4():
		x(0),
		y(0),
		z(0),
		w(1)
	{

	}

	Vec4::Vec4(double nx, double ny, double nz, double nw):
		x(nx),
		y(ny),
		z(nz),
		w(nw)
	{

	}

	Vec4::Vec4(double mag, const Vec4 &dir)
	{
		*this=dir.getUnit()*mag;
	}

	Vec4::Vec4(const Vec3 &vec, double nw):
		x(vec.x),
		y(vec.y),
		z(vec.z),
		w(nw)
	{

	}

	Vec4::Vec4(const Vec4 &vec):
		x(vec.x),
		y(vec.y),
		z(vec.z),
		w(vec.w)
	{

	}

	//dtr
	Vec4::~Vec4()
	{

	}

	//alter
	void Vec4::normalize()
	{
		double mag=getMag();
		if(mag!=0)
		{
			*this/=mag;
		}
	}

	//gets
	double Vec4::getMag() const
	{
		return sqrtf(x*x+y*y+z*z+w*w);
	}

	double Vec4::getMagSquared() const
	{
		return x*x+y*y+z*z+w*w;
	}

	Vec4 Vec4::getUnit() const
	{
		double mag=getMag();
		if(mag!=0)
		{
			return *this/mag;
		}
		else
		{
			return *this;
		}
	}

	Vec4 Vec4::getProjectionOn(const Vec4 &vec) const
	{
		return Vec4((((*this)*vec)/(vec*vec))*vec);
	}

	
	//statics
	double Vec4::angleBetween(const Vec4 &v1, const Vec4 &v2) 
	{
		return acos((v1*v2)/(v1.getMag()*v2.getMag()));
	}

	//selfOperators
	const Vec4& Vec4::operator=(const Vec4 &vec)
	{
		x=vec.x;
		y=vec.y;
		z=vec.z;
		w=vec.w;
		return *this;
	}

	const Vec4& Vec4::operator+=(const Vec4 &vec)
	{
		x+=vec.x;
		y+=vec.y;
		z+=vec.z;
		w+=vec.w;
		return *this;
	}

	const Vec4& Vec4::operator-=(const Vec4 &vec)
	{
		x-=vec.x;
		y-=vec.y;
		z-=vec.z;
		w-=vec.w;
		return *this;
	}

	const Vec4& Vec4::operator*=(double scalar)
	{
		x*=scalar;
		y*=scalar;
		z*=scalar;
		w*=scalar;
		return *this;
	}

	const Vec4& Vec4::operator/=(double scalar)
	{
		x/=scalar;
		y/=scalar;
		z/=scalar;
		w/=scalar;
		return *this;
	}

	const Vec4 Vec4::operator-() const
	{
		return Vec4(-x,-y,-z,-w);
	}


	const Vec4 operator+(const Vec4 &v1, const Vec4 &v2)
	{
		return Vec4(v1.x+v2.x, v1.y+v2.y, v1.z+v2.z, v1.w+v2.w);
	}

	const Vec4 operator-(const Vec4 &v1, const Vec4 &v2)
	{
		return Vec4(v1.x-v2.x, v1.y-v2.y, v1.z-v2.z, v1.w-v2.w);
	}

	const double operator*(const Vec4 &v1, const Vec4 &v2)
	{
		return v1.x*v2.x+v1.y*v2.y+v1.z*v2.z+v1.w*v2.w;
	}

	const Vec4 operator*(const Vec4 &vec, double scalar)
	{
		return Vec4(vec.x*scalar, vec.y*scalar, vec.z*scalar, vec.w*scalar);
	}

	const Vec4 operator*(double scalar, const Vec4 &vec)
	{
		return Vec4(vec.x*scalar, vec.y*scalar, vec.z*scalar, vec.w*scalar);
	}

	const Vec4 operator/(const Vec4 &vec, double scalar)
	{
		return Vec4(vec.x/scalar, vec.y/scalar, vec.z/scalar, vec.w/scalar);
	}
}
