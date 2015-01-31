#ifndef MTR_VEC4_H
#define MTR_VEC4_H

namespace mtr
{
	class Mat4;
	class Vec3;

	class Vec4
	{
		
	public:
		//components
		double x;
		double y;
		double z;
		double w;

		//ctrs
		Vec4();
		Vec4(double nx, double ny, double nz, double nw);
		Vec4(double mag, const Vec4 &dir);
		Vec4(const Vec3 &vec, double nw=1);
		Vec4(const Vec4 &vec);

		//dtr
		~Vec4();

		//alter
		void normalize();
		
		//gets
		double getMag() const;
		double getMagSquared() const;
		Vec4 getUnit() const;
		Vec4 getProjectionOn(const Vec4 &vec) const;
		
		//statics
		static double angleBetween(const Vec4 &v1, const Vec4 &v2);
		
		//selfOperators
		const Vec4& operator=(const Vec4 &vec);
		const Vec4& operator+=(const Vec4 &vec);
		const Vec4& operator-=(const Vec4 &vec);
		const Vec4& operator*=(double scalar);
		const Vec4& operator/=(double scalar);
		const Vec4 operator-() const;

		friend const Vec4 operator+(const Vec4 &v1, const Vec4 &v2);
		friend const Vec4 operator-(const Vec4 &v1, const Vec4 &v2);
		friend const double operator*(const Vec4 &v1, const Vec4 &v2);
		friend const Vec4 operator*(const Vec4 &vec, double scalar);
		friend const Vec4 operator*(double scalar, const Vec4 &vec);
		friend const Vec4 operator/(const Vec4 &vec, double scalar);

		//crossOperators
		friend const Vec4 operator*(const Mat4 &mat, const Vec4 &vec);
	};
}

#endif