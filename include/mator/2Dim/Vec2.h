#ifndef MTR_VEC2_H
#define MTR_VEC2_H

namespace mtr
{
	class Mat2;

	class Vec2
	{
		
	public:
		//components
		double x;
		double y;

		//ctrs
		Vec2();
		Vec2(double nx, double ny);
		Vec2(double mag, const Vec2 &dir);
		Vec2(const Vec2 &vec);

		//dtr
		~Vec2();

		//alter
		void normalize();
		void rotate(double radians);

		//gets
		double getMag() const;
		double getMagSquared() const;
		Vec2 getUnit() const;
		Vec2 getProjectionOn(const Vec2 &vec) const;
		Vec2 getRotated(double radians) const;

		//statics
		static double angleBetween(const Vec2 &v1, const Vec2 &v2);

		//selfOperators
		const Vec2& operator=(const Vec2 &vec);
		const Vec2& operator+=(const Vec2 &vec);
		const Vec2& operator-=(const Vec2 &vec);
		const Vec2& operator*=(double scalar);
		const Vec2& operator/=(double scalar);
		const Vec2 operator-() const;

		friend const Vec2 operator+(const Vec2 &v1, const Vec2 &v2);
		friend const Vec2 operator-(const Vec2 &v1, const Vec2 &v2);
		friend const double operator*(const Vec2 &v1, const Vec2 &v2);
		friend const Vec2 operator*(const Vec2 &vec, double scalar);
		friend const Vec2 operator*(double scalar, const Vec2 &vec);
		friend const Vec2 operator/(const Vec2 &vec, double scalar);

		//crossOperators
		friend const Vec2 operator*(const Mat2 &mat, const Vec2 &vec);
	};
}

#endif