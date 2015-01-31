#ifndef MTR_VEC3_H
#define MTR_VEC3_H

namespace mtr
{
	class Mat3;
	class Vec2;

	class Vec3
	{
		
	public:
		//components
		double x;
		double y;
		double z;

		//ctrs
		Vec3();
		Vec3(double nx, double ny, double nz);
		Vec3(double mag, const Vec3 &dir);
		Vec3(const Vec2 &vec, double nz=1);
		Vec3(const Vec3 &vec);

		//dtr
		~Vec3();

		//alter
		void normalize();
		void rotateAbout(double radians, const Vec3 &vec);
		void rotate(const Vec3 &vec);

		//gets
		double getMag() const;
		double getMagSquared() const;
		Vec3 getUnit() const;
		Vec3 getProjectionOn(const Vec3 &vec) const;
		Vec3 getRotated(double radians, const Vec3 &vec) const;
		Vec3 getRotated(const Vec3 &vec) const;

		//statics
		static double angleBetween(const Vec3 &v1, const Vec3 &v2);
		static Vec3 crossProduct(const Vec3 &v1, const Vec3 &v2);

		//selfOperators
		const Vec3& operator=(const Vec3 &vec);
		const Vec3& operator+=(const Vec3 &vec);
		const Vec3& operator-=(const Vec3 &vec);
		const Vec3& operator*=(double scalar);
		const Vec3& operator/=(double scalar);
		const Vec3 operator-() const;

		friend const Vec3 operator+(const Vec3 &v1, const Vec3 &v2);
		friend const Vec3 operator-(const Vec3 &v1, const Vec3 &v2);
		friend const double operator*(const Vec3 &v1, const Vec3 &v2);
		friend const Vec3 operator*(const Vec3 &vec, double scalar);
		friend const Vec3 operator*(double scalar, const Vec3 &vec);
		friend const Vec3 operator/(const Vec3 &vec, double scalar);

		//crossOperators
		friend const Vec3 operator*(const Mat3 &mat, const Vec3 &vec);
	};
}

#endif