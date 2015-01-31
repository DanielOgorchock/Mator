#ifndef MTR_MAT3_H
#define MTR_MAT3_H

namespace mtr
{
	class Vec3;
	class Mat2;
	class Vec2;

	class Mat3
	{
		static const int Rows=3;
		static const int Columns=3;
		
		double m_fArray[Rows*Columns];

		//utility
		void zeroArray();

	public:
		enum VecArrangement {V_TOP, V_BOT, H_LEFT, H_RIGHT};

		//ctrs
		Mat3();
		Mat3(const Vec3 &v1, const Vec3 &v2, const Vec3 &v3, VecArrangement e=VecArrangement::H_LEFT);
		Mat3(const Mat2 &mat);
		Mat3(const Mat3 &mat);

		//dtr
		~Mat3();

		//access
		double& accessElement(int r, int c);
		double accessElement(int r, int c) const;

		//gets
		double* getArrayPointer();
		const double* getArrayPointer() const;
		float* createFloatArray() const;
		Vec3 getRow(int r) const;
		Vec3 getColumn(int c) const;
		Mat3 getTranspose() const;

		//sets
		void setRow(int r, const Vec3 &vec);
		void setColumn(int c, const Vec3 &vec);

		//statics
		static Mat3 buildIdentity();
		static Mat3 buildRotationMatrix3D(const Vec3 &vec);
		static Mat3 buildRotationMatrix3D(double radians, const Vec3 &vec);
		static Mat3 buildScaleMatrix3D(const Vec3 &vec);
		static Mat3 buildRotationMatrix2D(double radians);
		static Mat3 buildScaleMatrix2D(const Vec2 &vec);
		static Mat3 buildTranslationMatrix2D(const Vec2 &vec);

		//selfOperators
		const Mat3& operator=(const Mat3 &mat);
		const Mat3& operator+=(const Mat3 &mat);
		const Mat3& operator-=(const Mat3 &mat);
		const Mat3& operator*=(const Mat3 &mat);
		const Mat3& operator*=(double scalar);
		const Mat3& operator/=(double scalar);
		const Mat3 operator-() const;

		double& operator[](int i);
		const double& operator[](int i) const;

		friend const Mat3 operator+(const Mat3 &m1, const Mat3 &m2);
		friend const Mat3 operator-(const Mat3 &m1, const Mat3 &m2);
		friend const Mat3 operator*(const Mat3 &m1, const Mat3 &m2);
		friend const Mat3 operator*(const Mat3 &mat, double scalar);
		friend const Mat3 operator*(double scalar, const Mat3 &mat);
		friend const Mat3 operator/(const Mat3 &mat, double scalar);

		//crossOperators
		friend const Vec3 operator*(const Mat3 &mat, const Vec3 &vec);
	};
}

#endif