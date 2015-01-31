#ifndef MTR_MAT4_H
#define MTR_MAT4_H

namespace mtr
{
	class Vec4;
	class Vec3;
	class Mat3;
	class Mat4
	{
		static const int Rows=4;
		static const int Columns=4;
		
		double m_fArray[Rows*Columns];

		//utility
		void zeroArray();

	public:
		enum VecArrangement {V_TOP, V_BOT, H_LEFT, H_RIGHT};

		//ctrs
		Mat4();
		Mat4(const Vec4 &v1, const Vec4 &v2, const Vec4 &v3, const Vec4 &v4, VecArrangement e=VecArrangement::H_LEFT);
		Mat4(const Mat3 &mat);
		Mat4(const Mat4 &mat);

		//dtr
		~Mat4();

		//access
		double& accessElement(int r, int c);
		double accessElement(int r, int c) const;

		//gets
		double* getArrayPointer();
		const double* getArrayPointer() const;
		float* createFloatArray() const;
		Vec4 getRow(int r) const;
		Vec4 getColumn(int c) const;
		Mat4 getTranspose() const;

		//sets
		void setRow(int r, const Vec4 &vec);
		void setColumn(int c, const Vec4 &vec);

		//statics
		static Mat4 buildIdentity();
		static Mat4 buildRotationMatrix3D(const Vec3 &vec);
		static Mat4 buildRotationMatrix3D(double radians, const Vec3 &vec);
		static Mat4 buildScaleMatrix3D(const Vec3 &vec);
		static Mat4 buildTranslationMatrix3D(const Vec3 &vec);

		//selfOperators
		const Mat4& operator=(const Mat4 &mat);
		const Mat4& operator+=(const Mat4 &mat);
		const Mat4& operator-=(const Mat4 &mat);
		const Mat4& operator*=(const Mat4 &mat);
		const Mat4& operator*=(double scalar);
		const Mat4& operator/=(double scalar);
		const Mat4 operator-() const;

		double& operator[](int i);
		const double& operator[](int i) const;

		friend const Mat4 operator+(const Mat4 &m1, const Mat4 &m2);
		friend const Mat4 operator-(const Mat4 &m1, const Mat4 &m2);
		friend const Mat4 operator*(const Mat4 &m1, const Mat4 &m2);
		friend const Mat4 operator*(const Mat4 &mat, double scalar);
		friend const Mat4 operator*(double scalar, const Mat4 &mat);
		friend const Mat4 operator/(const Mat4 &mat, double scalar);

		//crossOperators
		friend const Vec4 operator*(const Mat4 &mat, const Vec4 &vec);
	};
}

#endif