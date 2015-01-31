#include "Mator/3Dim/Mat3.h"

#include "Mator/3Dim/Vec3.h"
#include <math.h>
#include "Mator/2Dim/Mat2.h"
#include "Mator/2Dim/Vec2.h"

namespace mtr
{
//private

	//utility
	void Mat3::zeroArray()
	{
		for(int count=0; count<Rows*Columns; count++)
		{
			m_fArray[count]=0;
		}
	}


//public

	//ctrs
	Mat3::Mat3()
	{
		zeroArray();
	}

	Mat3::Mat3(const Vec3 &v1, const Vec3 &v2, const Vec3 &v3, Mat3::VecArrangement e)
	{
		if(e==Mat3::VecArrangement::H_LEFT)
		{
			accessElement(1,1)=v1.x;
			accessElement(1,2)=v1.y;
			accessElement(1,3)=v1.z;
			
			accessElement(2,1)=v2.x;
			accessElement(2,2)=v2.y;
			accessElement(2,3)=v2.z;

			accessElement(3,1)=v3.x;
			accessElement(3,2)=v3.y;
			accessElement(3,3)=v3.z;
		}

		else if(e==Mat3::VecArrangement::H_RIGHT)
		{
			accessElement(1,1)=v1.z;
			accessElement(1,2)=v1.y;
			accessElement(1,3)=v1.x;
			
			accessElement(2,1)=v2.z;
			accessElement(2,2)=v2.y;
			accessElement(2,3)=v2.x;

			accessElement(3,1)=v3.z;
			accessElement(3,2)=v3.y;
			accessElement(3,3)=v3.x;
		}

		else if(e==Mat3::VecArrangement::V_TOP)
		{
			accessElement(1,1)=v1.x;
			accessElement(2,1)=v1.y;
			accessElement(3,1)=v1.z;
			
			accessElement(1,2)=v2.x;
			accessElement(2,2)=v2.y;
			accessElement(3,2)=v2.z;

			accessElement(1,3)=v3.x;
			accessElement(2,3)=v3.y;
			accessElement(3,3)=v3.z;
		}

		else
		{
			accessElement(1,1)=v1.z;
			accessElement(2,1)=v1.y;
			accessElement(3,1)=v1.x;
			
			accessElement(1,2)=v2.z;
			accessElement(2,2)=v2.y;
			accessElement(3,2)=v2.x;

			accessElement(1,3)=v3.z;
			accessElement(2,3)=v3.y;
			accessElement(3,3)=v3.x;
		}
	}

	Mat3::Mat3(const Mat2 &mat)
	{
		zeroArray();
		accessElement(1,1)=mat.accessElement(1,1);
		accessElement(1,2)=mat.accessElement(1,2);
		accessElement(2,1)=mat.accessElement(2,1);
		accessElement(2,2)=mat.accessElement(2,2);
		accessElement(3,3)=1;
	}

	Mat3::Mat3(const Mat3 &mat)
	{
		for(int count=0; count<Rows*Columns; count++)
		{
			m_fArray[count]=mat.m_fArray[count];
		}
	}

	//dtr
	Mat3::~Mat3()
	{

	}

	//access
	double& Mat3::accessElement(int r, int c)
	{
		return m_fArray[(r-1)*Columns+c-1];
	}

	double Mat3::accessElement(int r, int c) const
	{
		return m_fArray[(r-1)*Columns+c-1];
	}

	//gets
	double* Mat3::getArrayPointer()
	{
		return &m_fArray[0];
	}

	const double* Mat3::getArrayPointer() const
	{
		return &m_fArray[0];
	}

	float* Mat3::createFloatArray() const
	{
		float *a=new float[Rows*Columns];
		for(unsigned int i=0; i<Rows*Columns; ++i)
		{
			a[i]=m_fArray[i];
		}
		return a;
	}

	Vec3 Mat3::getRow(int r) const
	{
		return Vec3(accessElement(r,1), accessElement(r,2), accessElement(r,3));
	}

	Vec3 Mat3::getColumn(int c) const
	{
		return Vec3(accessElement(1,c), accessElement(2,c), accessElement(3,c));
	}

	Mat3 Mat3::getTranspose() const
	{
		Mat3 m;
		m.setRow(1,getColumn(1));
		m.setRow(2,getColumn(2));
		m.setRow(3,getColumn(3));
		return m;
	}

	//sets
	void Mat3::setRow(int r, const Vec3 &vec)
	{
		accessElement(r,1)=vec.x;
		accessElement(r,2)=vec.y;
		accessElement(r,3)=vec.z;
	}

	void Mat3::setColumn(int c, const Vec3 &vec)
	{
		accessElement(1,c)=vec.x;
		accessElement(2,c)=vec.y;
		accessElement(3,c)=vec.z;
	}

	//statics
	Mat3 Mat3::buildIdentity()
	{
		Mat3 m;
		m.accessElement(1,1)=1;
		m.accessElement(2,2)=1;
		m.accessElement(3,3)=1;
		return m;
	}

	Mat3 Mat3::buildRotationMatrix3D(const Vec3 &vec)
	{
		Mat3 mx;
		mx.accessElement(1,1)=1;
		mx.accessElement(2,2)=cos(vec.x);
		mx.accessElement(2,3)=-sin(vec.x);
		mx.accessElement(3,2)=sin(vec.x);
		mx.accessElement(3,3)=cos(vec.x);

		Mat3 my;
		my.accessElement(1,1)=cos(vec.y);
		my.accessElement(1,3)=sin(vec.y);
		my.accessElement(2,2)=1;
		my.accessElement(3,1)=-sin(vec.y);
		my.accessElement(3,3)=cos(vec.y);

		Mat3 mz;
		mz.accessElement(1,1)=cos(vec.z);
		mz.accessElement(1,2)=-sin(vec.z);
		mz.accessElement(2,1)=sin(vec.z);
		mz.accessElement(2,2)=cos(vec.z);
		mz.accessElement(3,3)=1;
		
		return mx*my*mz;
	}

	Mat3 Mat3::buildRotationMatrix3D(double radians, const Vec3 &vec)
	{
		Vec3 a=vec.getUnit();
		Mat3 m;
		double c=cos(radians);
		double s=sin(radians);
		m.accessElement(1,1)=c+(a.x*a.x)*(1-c);
		m.accessElement(1,2)=(a.x*a.y)*(1-c)-a.z*s;
		m.accessElement(1,3)=(a.x*a.z)*(1-c)+a.y*s;
		m.accessElement(2,1)=(a.y*a.x)*(1-c)+a.z*s;
		m.accessElement(2,2)=c+(a.y*a.y)*(1-c);
		m.accessElement(2,3)=(a.y*a.z)*(1-c)-a.x*s;
		m.accessElement(3,1)=(a.z*a.x)*(1-c)-a.y*s;
		m.accessElement(3,2)=(a.z*a.y)*(1-c)+a.x*s;
		m.accessElement(3,3)=c+(a.z*a.z)*(1-c);
		return m;
	}

	Mat3 Mat3::buildScaleMatrix3D(const Vec3 &vec)
	{
		Mat3 m;
		m.accessElement(1,1)=vec.x;
		m.accessElement(2,2)=vec.y;
		m.accessElement(3,3)=vec.z;
		return m;
	}

	Mat3 Mat3::buildRotationMatrix2D(double radians)
	{
		Mat3 m;
		m.accessElement(1,1)=cos(radians);
		m.accessElement(1,2)=-sin(radians);
		m.accessElement(2,1)=sin(radians);
		m.accessElement(2,2)=cos(radians);
		m.accessElement(3,3)=1;
		return m;
	}

	Mat3 Mat3::buildScaleMatrix2D(const Vec2 &vec)
	{
		Mat3 m;
		m.accessElement(1,1)=vec.x;
		m.accessElement(2,2)=vec.y;
		m.accessElement(3,3)=1;
		return m;
	}

	Mat3 Mat3::buildTranslationMatrix2D(const Vec2 &vec)
	{
		Mat3 m(buildIdentity());
		m.accessElement(1,3)=vec.x;
		m.accessElement(2,3)=vec.y;
		return m;
	}

	//selfOperators
	const Mat3& Mat3::operator=(const Mat3 &mat)
	{
		for(int count=0; count<Rows*Columns; count++)
		{
			m_fArray[count]=mat.m_fArray[count];
		}
		return *this;
	}

	const Mat3& Mat3::operator+=(const Mat3 &mat)
	{
		for(int count=0; count<Rows*Columns; count++)
		{
			m_fArray[count]+=mat.m_fArray[count];
		}
		return *this;
	}

	const Mat3& Mat3::operator-=(const Mat3 &mat)
	{
		for(int count=0; count<Rows*Columns; count++)
		{
			m_fArray[count]-=mat.m_fArray[count];
		}
		return *this;
	}

	const Mat3& Mat3::operator*=(const Mat3 &mat)
	{
		*this=(*this)*mat;
		 return *this;
	}

	const Mat3& Mat3::operator*=(double scalar)
	{
		for(int count=0; count<Rows*Columns; count++)
		{
			m_fArray[count]*=scalar;
		}
		return *this;
	}

	const Mat3& Mat3::operator/=(double scalar)
	{
		for(int count=0; count<Rows*Columns; count++)
		{
			m_fArray[count]/=scalar;
		}
		return *this;
	}

	const Mat3 Mat3::operator-() const
	{
		return (*this)*-1;
	}


	double& Mat3::operator[](int i)
	{
		return m_fArray[i];
	}

	const double& Mat3::operator[](int i) const
	{
		return m_fArray[i];
	}

	const Mat3 operator+(const Mat3 &m1, const Mat3 &m2)
	{
		Mat3 m(m1);
		for(int count=0; count<m.Rows*m.Columns; count++)
		{
			m.m_fArray[count]+=m2.m_fArray[count];
		}
		return m;
	}

	const Mat3 operator-(const Mat3 &m1, const Mat3 &m2)
	{
		Mat3 m(m1);
		for(int count=0; count<m.Rows*m.Columns; count++)
		{
			m.m_fArray[count]-=m2.m_fArray[count];
		}
		return m;
	}

	const Mat3 operator*(const Mat3 &m1, const Mat3 &m2)
	{
		Mat3 m;
		for(int counter1=m.Rows; counter1>0; counter1--)
		{
			for(int counter2=m.Columns; counter2>0; counter2--)
			{
				double &element=m.accessElement(counter1, counter2);
				for(int counter3=m.Columns; counter3>0; counter3--)
				{
					element+=m1.accessElement(counter1, counter3)*m2.accessElement(counter3, counter2); 
				}
			}
		}
		return m;
	}

	const Mat3 operator*(const Mat3 &mat, double scalar)
	{
		Mat3 m(mat);
		for(int count=0; count<m.Rows*m.Columns; count++)
		{
			m.m_fArray[count]*=scalar;
		}
		return m;
	}

	const Mat3 operator*(double scalar, const Mat3 &mat)
	{
		Mat3 m(mat);
		for(int count=0; count<m.Rows*m.Columns; count++)
		{
			m.m_fArray[count]*=scalar;
		}
		return m;
	}

	const Mat3 operator/(const Mat3 &mat, double scalar)
	{
		Mat3 m(mat);
		for(int count=0; count<m.Rows*m.Columns; count++)
		{
			m.m_fArray[count]/=scalar;
		}
		return m;
	}

	//crossOperators
	const Vec3 operator*(const Mat3 &mat, const Vec3 &vec)
	{
		return Vec3(vec.x*mat.accessElement(1,1)+vec.y*mat.accessElement(1,2)+vec.z*mat.accessElement(1,3),
					vec.x*mat.accessElement(2,1)+vec.y*mat.accessElement(2,2)+vec.z*mat.accessElement(2,3),
					vec.x*mat.accessElement(3,1)+vec.y*mat.accessElement(3,2)+vec.z*mat.accessElement(3,3));
	}
}
