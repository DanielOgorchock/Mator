#include "mator/2Dim/Vec2.h"

#include <math.h>
#include "mator/2Dim/Mat2.h"

namespace mtr
{

//public
	//ctrs
	Vec2::Vec2():
		x(0),
		y(0)
	{

	}

	Vec2::Vec2(double nx, double ny):
		x(nx),
		y(ny)
	{

	}

	Vec2::Vec2(double mag, const Vec2 &dir)
	{
		*this=dir.getUnit()*mag;
	}

	Vec2::Vec2(const Vec2 &vec):
		x(vec.x),
		y(vec.y)
	{

	}

	//dtr
	Vec2::~Vec2()
	{

	}

	//alter
	void Vec2::normalize()
	{
		double mag=getMag();
		if(mag!=0)
		{
			*this/=mag;
		}
	}

	void Vec2::rotate(double radians)
	{
		*this=Mat2::buildRotationMatrix2D(radians)*(*this);
	}

	//gets
	double Vec2::getMag() const
	{
		return sqrtf(x*x+y*y); 
	}

	double Vec2::getMagSquared() const
	{
		return x*x+y*y;
	}

	Vec2 Vec2::getUnit() const
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

	Vec2 Vec2::getProjectionOn(const Vec2 &vec) const
	{
		return Vec2((((*this)*vec)/(vec*vec))*vec);
	}

	Vec2 Vec2::getRotated(double radians) const
	{
		return Mat2::buildRotationMatrix2D(radians)*(*this);
	}

	//statics
	double Vec2::angleBetween(const Vec2 &v1, const Vec2 &v2) 
	{
		return acos((v1*v2)/(v1.getMag()*v2.getMag()));
	}

	//selfOperators
	const Vec2& Vec2::operator=(const Vec2 &vec)
	{
		x=vec.x;
		y=vec.y;
		return *this;
	}

	const Vec2& Vec2::operator+=(const Vec2 &vec)
	{
		x+=vec.x;
		y+=vec.y;
		return *this;
	}

	const Vec2& Vec2::operator-=(const Vec2 &vec)
	{
		x-=vec.x;
		y-=vec.y;
		return *this;
	}

	const Vec2& Vec2::operator*=(double scalar)
	{
		x*=scalar;
		y*=scalar;
		return *this;
	}

	const Vec2& Vec2::operator/=(double scalar)
	{
		x/=scalar;
		y/=scalar;
		return *this;
	}

	const Vec2 Vec2::operator-() const
	{
		return Vec2(-x,-y);
	}


	const Vec2 operator+(const Vec2 &v1, const Vec2 &v2)
	{
		return Vec2(v1.x+v2.x, v1.y+v2.y);
	}

	const Vec2 operator-(const Vec2 &v1, const Vec2 &v2)
	{
		return Vec2(v1.x-v2.x, v1.y-v2.y);
	}

	const double operator*(const Vec2 &v1, const Vec2 &v2)
	{
		return v1.x*v2.x+v1.y*v2.y;
	}

	const Vec2 operator*(const Vec2 &vec, double scalar)
	{
		return Vec2(vec.x*scalar, vec.y*scalar);
	}

	const Vec2 operator*(double scalar, const Vec2 &vec)
	{
		return Vec2(vec.x*scalar, vec.y*scalar);
	}

	const Vec2 operator/(const Vec2 &vec, double scalar)
	{
		return Vec2(vec.x/scalar, vec.y/scalar);
	}
}
