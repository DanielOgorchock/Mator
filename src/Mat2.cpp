#include "mator/2Dim/Mat2.h"

#include "mator/2Dim/Vec2.h"
#include <math.h>

namespace mtr
{
//private

	//utility
	void Mat2::zeroArray()
	{
		for(int count=0; count<Rows*Columns; count++)
		{
			m_fArray[count]=0;
		}
	}


//public

	//ctrs
	Mat2::Mat2()
	{
		zeroArray();
	}

	Mat2::Mat2(const Vec2 &v1, const Vec2 &v2, Mat2::VecArrangement e)
	{
		if(e==Mat2::VecArrangement::H_LEFT)
		{
			accessElement(1,1)=v1.x;
			accessElement(1,2)=v1.y;
			
			accessElement(2,1)=v2.x;
			accessElement(2,2)=v2.y;
		}

		else if(e==Mat2::VecArrangement::H_RIGHT)
		{
			accessElement(1,1)=v1.y;
			accessElement(1,2)=v1.x;
			
			accessElement(2,1)=v2.y;
			accessElement(2,2)=v2.x;
		}

		else if(e==Mat2::VecArrangement::V_TOP)
		{
			accessElement(1,1)=v1.x;
			accessElement(2,1)=v1.y;
			
			accessElement(1,2)=v2.x;
			accessElement(2,2)=v2.y;
		}

		else if(e==Mat2::VecArrangement::V_BOT)
		{
			accessElement(1,1)=v1.y;
			accessElement(2,1)=v1.x;
			
			accessElement(1,2)=v2.y;
			accessElement(2,2)=v2.x;
		}
	}

	Mat2::Mat2(const Mat2 &mat)
	{
		for(int count=0; count<Rows*Columns; count++)
		{
			m_fArray[count]=mat.m_fArray[count];
		}
	}

	//dtr
	Mat2::~Mat2()
	{

	}

	//access
	double& Mat2::accessElement(int r, int c)
	{
		return m_fArray[(r-1)*Columns+c-1];
	}

	double Mat2::accessElement(int r, int c) const
	{
		return m_fArray[(r-1)*Columns+c-1];
	}

	//gets
	double* Mat2::getArrayPointer()
	{
		return &m_fArray[0];
	}

	const double* Mat2::getArrayPointer() const
	{
		return &m_fArray[0];
	}

	float* Mat2::createFloatArray() const
	{
		float *a=new float[Rows*Columns];
		for(unsigned int i=0; i<Rows*Columns; ++i)
		{
			a[i]=m_fArray[i];
		}
		return a;
	}

	Vec2 Mat2::getRow(int r) const
	{
		return Vec2(accessElement(r,1), accessElement(r,2));
	}

	Vec2 Mat2::getColumn(int c) const
	{
		return Vec2(accessElement(1,c), accessElement(2,c));
	}

	Mat2 Mat2::getTranspose() const
	{
		Mat2 m;
		m.setRow(1,getColumn(1));
		m.setRow(2,getColumn(2));
		return m;
	}

	//sets
	void Mat2::setRow(int r, const Vec2 &vec)
	{
		accessElement(r,1)=vec.x;
		accessElement(r,2)=vec.y;
	}

	void Mat2::setColumn(int c, const Vec2 &vec)
	{
		accessElement(1,c)=vec.x;
		accessElement(2,c)=vec.y;
	}

	//statics
	Mat2 Mat2::buildIdentity()
	{
		Mat2 m;
		m.accessElement(1,1)=1;
		m.accessElement(2,2)=1;
		return m;
	}

	Mat2 Mat2::buildRotationMatrix2D(double radians)
	{
		Mat2 m;
		m.accessElement(1,1)=cos(radians);
		m.accessElement(1,2)=-sin(radians);
		m.accessElement(2,1)=sin(radians);
		m.accessElement(2,2)=cos(radians);
		return m;
	}

	Mat2 Mat2::buildScaleMatrix2D(const Vec2 &vec)
	{
		Mat2 m;
		m.accessElement(1,1)=vec.x;
		m.accessElement(2,2)=vec.y;
		return m;
	}

	//selfOperators
	const Mat2& Mat2::operator=(const Mat2 &mat)
	{
		for(int count=0; count<Rows*Columns; count++)
		{
			m_fArray[count]=mat.m_fArray[count];
		}
		return *this;
	}

	const Mat2& Mat2::operator+=(const Mat2 &mat)
	{
		for(int count=0; count<Rows*Columns; count++)
		{
			m_fArray[count]+=mat.m_fArray[count];
		}
		return *this;
	}

	const Mat2& Mat2::operator-=(const Mat2 &mat)
	{
		for(int count=0; count<Rows*Columns; count++)
		{
			m_fArray[count]-=mat.m_fArray[count];
		}
		return *this;
	}

	const Mat2& Mat2::operator*=(const Mat2 &mat)
	{
		*this=(*this)*mat;
		 return *this;
	}

	const Mat2& Mat2::operator*=(double scalar)
	{
		for(int count=0; count<Rows*Columns; count++)
		{
			m_fArray[count]*=scalar;
		}
		return *this;
	}

	const Mat2& Mat2::operator/=(double scalar)
	{
		for(int count=0; count<Rows*Columns; count++)
		{
			m_fArray[count]/=scalar;
		}
		return *this;
	}

	const Mat2 Mat2::operator-() const
	{
		return (*this)*-1;
	}


	double& Mat2::operator[](int i)
	{
		return m_fArray[i];
	}

	const double& Mat2::operator[](int i) const
	{
		return m_fArray[i];
	}

	const Mat2 operator+(const Mat2 &m1, const Mat2 &m2)
	{
		Mat2 m(m1);
		for(int count=0; count<m.Rows*m.Columns; count++)
		{
			m.m_fArray[count]+=m2.m_fArray[count];
		}
		return m;
	}

	const Mat2 operator-(const Mat2 &m1, const Mat2 &m2)
	{
		Mat2 m(m1);
		for(int count=0; count<m.Rows*m.Columns; count++)
		{
			m.m_fArray[count]-=m2.m_fArray[count];
		}
		return m;
	}

	const Mat2 operator*(const Mat2 &m1, const Mat2 &m2)
	{
		Mat2 m;
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

	const Mat2 operator*(const Mat2 &mat, double scalar)
	{
		Mat2 m(mat);
		for(int count=0; count<m.Rows*m.Columns; count++)
		{
			m.m_fArray[count]*=scalar;
		}
		return m;
	}

	const Mat2 operator*(double scalar, const Mat2 &mat)
	{
		Mat2 m(mat);
		for(int count=0; count<m.Rows*m.Columns; count++)
		{
			m.m_fArray[count]*=scalar;
		}
		return m;
	}

	const Mat2 operator/(const Mat2 &mat, double scalar)
	{
		Mat2 m(mat);
		for(int count=0; count<m.Rows*m.Columns; count++)
		{
			m.m_fArray[count]/=scalar;
		}
		return m;
	}

	//crossOperators
	const Vec2 operator*(const Mat2 &mat, const Vec2 &vec)
	{
		return Vec2(vec.x*mat.accessElement(1,1)+vec.y*mat.accessElement(1,2),
					vec.x*mat.accessElement(2,1)+vec.y*mat.accessElement(2,2));
	}
}
