#ifndef MTR_MAT2_H
#define MTR_MAT2_H

namespace mtr
{
	class Vec2;

	class Mat2
	{
		static const int Rows=2;
		static const int Columns=2;
		
		double m_fArray[Rows*Columns];

		//utility
		void zeroArray();

	public:
		enum VecArrangement {V_TOP, V_BOT, H_LEFT, H_RIGHT};

		//ctrs
		Mat2();
		Mat2(const Vec2 &v1, const Vec2 &v2, VecArrangement e=H_LEFT);
		Mat2(const Mat2 &mat);

		//dtr
		~Mat2();

		//access
		double& accessElement(int r, int c);
		double accessElement(int r, int c) const;

		//gets
		double* getArrayPointer();
		const double* getArrayPointer() const;
		float* createFloatArray() const;
		Vec2 getRow(int r) const;
		Vec2 getColumn(int c) const;
		Mat2 getTranspose() const;

		//sets
		void setRow(int r, const Vec2 &vec);
		void setColumn(int c, const Vec2 &vec);

		//statics
		static Mat2 buildIdentity();
		static Mat2 buildRotationMatrix2D(double radians);
		static Mat2 buildScaleMatrix2D(const Vec2 &vec);

		//selfOperators
		const Mat2& operator=(const Mat2 &mat);
		const Mat2& operator+=(const Mat2 &mat);
		const Mat2& operator-=(const Mat2 &mat);
		const Mat2& operator*=(const Mat2 &mat);
		const Mat2& operator*=(double scalar);
		const Mat2& operator/=(double scalar);
		const Mat2 operator-() const;

		double& operator[](int i);
		const double& operator[](int i) const;

		friend const Mat2 operator+(const Mat2 &m1, const Mat2 &m2);
		friend const Mat2 operator-(const Mat2 &m1, const Mat2 &m2);
		friend const Mat2 operator*(const Mat2 &m1, const Mat2 &m2);
		friend const Mat2 operator*(const Mat2 &mat, double scalar);
		friend const Mat2 operator*(double scalar, const Mat2 &mat);
		friend const Mat2 operator/(const Mat2 &mat, double scalar);

		//crossOperators
		friend const Vec2 operator*(const Mat2 &mat, const Vec2 &vec);
	};
}

#endif