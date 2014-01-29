#include "include/mator/4Dim/Mat4.h"

#include "include/mator/3Dim/Vec3.h"
#include "include/mator/4Dim/Vec4.h"
#include <math.h>
#include "include/mator/3Dim/Mat3.h"

namespace mtr
{
//private

	//utility
	void Mat4::zeroArray()
	{
		for(int count=0; count<Rows*Columns; count++)
		{
			m_fArray[count]=0;
		}
	}


//public

	//ctrs
	Mat4::Mat4()
	{
		zeroArray();
	}

	Mat4::Mat4(const Vec4 &v1, const Vec4 &v2, const Vec4 &v3, const Vec4 &v4, Mat4::VecArrangement e)
	{
		if(e==Mat4::VecArrangement::H_LEFT)
		{
			accessElement(1,1)=v1.x;
			accessElement(1,2)=v1.y;
			accessElement(1,3)=v1.z;
			accessElement(1,4)=v1.w;
			
			accessElement(2,1)=v2.x;
			accessElement(2,2)=v2.y;
			accessElement(2,3)=v2.z;
			accessElement(2,4)=v2.w;

			accessElement(3,1)=v3.x;
			accessElement(3,2)=v3.y;
			accessElement(3,3)=v3.z;
			accessElement(3,4)=v3.w;

			accessElement(4,1)=v4.x;
			accessElement(4,2)=v4.y;
			accessElement(4,3)=v4.z;
			accessElement(4,4)=v4.w;
		}

		else if(e==Mat4::VecArrangement::H_RIGHT)
		{
			accessElement(1,1)=v1.w;
			accessElement(1,2)=v1.z;
			accessElement(1,3)=v1.y;
			accessElement(1,4)=v1.x;
			
			accessElement(2,1)=v2.w;
			accessElement(2,2)=v2.z;
			accessElement(2,3)=v2.y;
			accessElement(2,4)=v2.x;

			accessElement(3,1)=v3.w;
			accessElement(3,2)=v3.z;
			accessElement(3,3)=v3.y;
			accessElement(3,4)=v3.x;

			accessElement(4,1)=v4.w;
			accessElement(4,2)=v4.z;
			accessElement(4,3)=v4.y;
			accessElement(4,4)=v4.x;
		}

		else if(e==Mat4::VecArrangement::V_TOP)
		{
			accessElement(1,1)=v1.x;
			accessElement(2,1)=v1.y;
			accessElement(3,1)=v1.z;
			accessElement(4,1)=v1.w;
			
			accessElement(1,2)=v2.x;
			accessElement(2,2)=v2.y;
			accessElement(3,2)=v2.z;
			accessElement(4,2)=v2.w;

			accessElement(1,3)=v3.x;
			accessElement(2,3)=v3.y;
			accessElement(3,3)=v3.z;
			accessElement(4,3)=v3.w;

			accessElement(1,4)=v4.x;
			accessElement(2,4)=v4.y;
			accessElement(3,4)=v4.z;
			accessElement(4,4)=v4.w;
		}

		else
		{
			accessElement(1,1)=v1.w;
			accessElement(2,1)=v1.z;
			accessElement(3,1)=v1.y;
			accessElement(4,1)=v1.x;
			
			accessElement(1,2)=v2.w;
			accessElement(2,2)=v2.z;
			accessElement(3,2)=v2.y;
			accessElement(4,2)=v2.x;

			accessElement(1,3)=v3.w;
			accessElement(2,3)=v3.z;
			accessElement(3,3)=v3.y;
			accessElement(4,3)=v3.x;

			accessElement(1,4)=v4.w;
			accessElement(2,4)=v4.z;
			accessElement(3,4)=v4.y;
			accessElement(4,4)=v4.x;
		}
	}

	Mat4::Mat4(const Mat3 &mat)
	{
		zeroArray();
		accessElement(1,1)=mat.accessElement(1,1);
		accessElement(1,2)=mat.accessElement(1,2);
		accessElement(1,3)=mat.accessElement(1,3);
		accessElement(2,1)=mat.accessElement(2,1);
		accessElement(2,2)=mat.accessElement(2,2);
		accessElement(2,3)=mat.accessElement(2,3);
		accessElement(3,1)=mat.accessElement(3,1);
		accessElement(3,2)=mat.accessElement(3,2);
		accessElement(3,3)=mat.accessElement(3,3);
		accessElement(4,4)=1;
	}

	Mat4::Mat4(const Mat4 &mat)
	{
		for(int count=0; count<Rows*Columns; count++)
		{
			m_fArray[count]=mat.m_fArray[count];
		}
	}

	//dtr
	Mat4::~Mat4()
	{

	}

	//access
	float& Mat4::accessElement(int r, int c)
	{
		return m_fArray[(r-1)*Columns+c-1];
	}

	float Mat4::accessElement(int r, int c) const
	{
		return m_fArray[(r-1)*Columns+c-1];
	}

	//gets
	float* Mat4::getArrayPointer()
	{
		return &m_fArray[0];
	}

	const float* Mat4::getArrayPointer() const
	{
		return &m_fArray[0];
	}

	Vec4 Mat4::getRow(int r) const
	{
		return Vec4(accessElement(r,1), accessElement(r,2), accessElement(r,3), accessElement(r,4));
	}

	Vec4 Mat4::getColumn(int c) const
	{
		return Vec4(accessElement(1,c), accessElement(2,c), accessElement(3,c), accessElement(4,c));
	}

	Mat4 Mat4::getTranspose() const
	{
		Mat4 m;
		m.setRow(1,getColumn(1));
		m.setRow(2,getColumn(2));
		m.setRow(3,getColumn(3));
		m.setRow(4,getColumn(4));
		return m;
	}

	//sets
	void Mat4::setRow(int r, const Vec4 &vec)
	{
		accessElement(r,1)=vec.x;
		accessElement(r,2)=vec.y;
		accessElement(r,3)=vec.z;
		accessElement(r,4)=vec.w;
	}

	void Mat4::setColumn(int c, const Vec4 &vec)
	{
		accessElement(1,c)=vec.x;
		accessElement(2,c)=vec.y;
		accessElement(3,c)=vec.z;
		accessElement(4,c)=vec.w;
	}

	//statics
	Mat4 Mat4::buildIdentity()
	{
		Mat4 m;
		m.accessElement(1,1)=1;
		m.accessElement(2,2)=1;
		m.accessElement(3,3)=1;
		m.accessElement(4,4)=1;
		return m;
	}

	Mat4 Mat4::buildRotationMatrix3D(const Vec3 &vec)
	{
		Mat4 mx;
		mx.accessElement(1,1)=1;
		mx.accessElement(2,2)=cos(vec.x);
		mx.accessElement(2,3)=-sin(vec.x);
		mx.accessElement(3,2)=sin(vec.x);
		mx.accessElement(3,3)=cos(vec.x);
		mx.accessElement(4,4)=1;

		Mat4 my;
		my.accessElement(1,1)=cos(vec.y);
		my.accessElement(1,3)=sin(vec.y);
		my.accessElement(2,2)=1;
		my.accessElement(3,1)=-sin(vec.y);
		my.accessElement(3,3)=cos(vec.y);
		my.accessElement(4,4)=1;

		Mat4 mz;
		mz.accessElement(1,1)=cos(vec.z);
		mz.accessElement(1,2)=-sin(vec.z);
		mz.accessElement(2,1)=sin(vec.z);
		mz.accessElement(2,2)=cos(vec.z);
		mz.accessElement(3,3)=1;
		mz.accessElement(4,4)=1;
		
		return mx*my*mz;
	}

	Mat4 Mat4::buildRotationMatrix3D(float radians, const Vec3 &vec)
	{
		Vec3 a=vec.getUnit();
		Mat4 m;
		float c=cos(radians);
		float s=sin(radians);
		m.accessElement(1,1)=c+(a.x*a.x)*(1-c);
		m.accessElement(1,2)=(a.x*a.y)*(1-c)-a.z*s;
		m.accessElement(1,3)=(a.x*a.z)*(1-c)+a.y*s;
		m.accessElement(2,1)=(a.y*a.x)*(1-c)+a.z*s;
		m.accessElement(2,2)=c+(a.y*a.y)*(1-c);
		m.accessElement(2,3)=(a.y*a.z)*(1-c)-a.x*s;
		m.accessElement(3,1)=(a.z*a.x)*(1-c)-a.y*s;
		m.accessElement(3,2)=(a.z*a.y)*(1-c)+a.x*s;
		m.accessElement(3,3)=c+(a.z*a.z)*(1-c);
		m.accessElement(4,4)=1;
		return m;
	}

	Mat4 Mat4::buildScaleMatrix3D(const Vec3 &vec)
	{
		Mat4 m;
		m.accessElement(1,1)=vec.x;
		m.accessElement(2,2)=vec.y;
		m.accessElement(3,3)=vec.z;
		m.accessElement(4,4)=1;
		return m;
	}

	Mat4 Mat4::buildTranslationMatrix3D(const Vec3 &vec)
	{
		Mat4 m(buildIdentity());
		m.accessElement(1,4)=vec.x;
		m.accessElement(2,4)=vec.y;
		m.accessElement(3,4)=vec.z;
		return m;
	}
	
	//selfOperators
	const Mat4& Mat4::operator=(const Mat4 &mat)
	{
		for(int count=0; count<Rows*Columns; count++)
		{
			m_fArray[count]=mat.m_fArray[count];
		}
		return *this;
	}

	const Mat4& Mat4::operator+=(const Mat4 &mat)
	{
		for(int count=0; count<Rows*Columns; count++)
		{
			m_fArray[count]+=mat.m_fArray[count];
		}
		return *this;
	}

	const Mat4& Mat4::operator-=(const Mat4 &mat)
	{
		for(int count=0; count<Rows*Columns; count++)
		{
			m_fArray[count]-=mat.m_fArray[count];
		}
		return *this;
	}

	const Mat4& Mat4::operator*=(const Mat4 &mat)
	{
		*this=(*this)*mat;
		 return *this;
	}

	const Mat4& Mat4::operator*=(float scalar)
	{
		for(int count=0; count<Rows*Columns; count++)
		{
			m_fArray[count]*=scalar;
		}
		return *this;
	}

	const Mat4& Mat4::operator/=(float scalar)
	{
		for(int count=0; count<Rows*Columns; count++)
		{
			m_fArray[count]/=scalar;
		}
		return *this;
	}

	const Mat4 Mat4::operator-() const
	{
		return (*this)*-1;
	}


	float& Mat4::operator[](int i)
	{
		return m_fArray[i];
	}

	const float& Mat4::operator[](int i) const
	{
		return m_fArray[i];
	}

	const Mat4 operator+(const Mat4 &m1, const Mat4 &m2)
	{
		Mat4 m(m1);
		for(int count=0; count<m.Rows*m.Columns; count++)
		{
			m.m_fArray[count]+=m2.m_fArray[count];
		}
		return m;
	}

	const Mat4 operator-(const Mat4 &m1, const Mat4 &m2)
	{
		Mat4 m(m1);
		for(int count=0; count<m.Rows*m.Columns; count++)
		{
			m.m_fArray[count]-=m2.m_fArray[count];
		}
		return m;
	}

	const Mat4 operator*(const Mat4 &m1, const Mat4 &m2)
	{
		Mat4 m;
		for(int counter1=m.Rows; counter1>0; counter1--)
		{
			for(int counter2=m.Columns; counter2>0; counter2--)
			{
				float &element=m.accessElement(counter1, counter2);
				for(int counter3=m.Columns; counter3>0; counter3--)
				{
					element+=m1.accessElement(counter1, counter3)*m2.accessElement(counter3, counter2); 
				}
			}
		}
		return m;
	}

	const Mat4 operator*(const Mat4 &mat, float scalar)
	{
		Mat4 m(mat);
		for(int count=0; count<m.Rows*m.Columns; count++)
		{
			m.m_fArray[count]*=scalar;
		}
		return m;
	}

	const Mat4 operator*(float scalar, const Mat4 &mat)
	{
		Mat4 m(mat);
		for(int count=0; count<m.Rows*m.Columns; count++)
		{
			m.m_fArray[count]*=scalar;
		}
		return m;
	}

	const Mat4 operator/(const Mat4 &mat, float scalar)
	{
		Mat4 m(mat);
		for(int count=0; count<m.Rows*m.Columns; count++)
		{
			m.m_fArray[count]/=scalar;
		}
		return m;
	}

	//crossOperators
	const Vec4 operator*(const Mat4 &mat, const Vec4 &vec)
	{
		return Vec4(vec.x*mat.accessElement(1,1)+vec.y*mat.accessElement(1,2)+vec.z*mat.accessElement(1,3)+vec.w*mat.accessElement(1,4),
					vec.x*mat.accessElement(2,1)+vec.y*mat.accessElement(2,2)+vec.z*mat.accessElement(2,3)+vec.w*mat.accessElement(2,4),
					vec.x*mat.accessElement(3,1)+vec.y*mat.accessElement(3,2)+vec.z*mat.accessElement(3,3)+vec.w*mat.accessElement(3,4),
					vec.x*mat.accessElement(4,1)+vec.y*mat.accessElement(4,2)+vec.z*mat.accessElement(4,3)+vec.w*mat.accessElement(4,4));
	}
}
