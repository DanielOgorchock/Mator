#ifndef MTR_VEC2_H
#define MTR_VEC2_H

namespace mtr
{
	class Mat2;

	class Vec2
	{
		
	public:
		//components
		float x;
		float y;

		//ctrs
		Vec2();
		Vec2(float nx, float ny);
		Vec2(float mag, const Vec2 &dir);
		Vec2(const Vec2 &vec);

		//dtr
		~Vec2();

		//alter
		void normalize();
		void rotate(float radians);

		//gets
		float getMag() const;
		float getMagSquared() const;
		Vec2 getUnit() const;
		Vec2 getProjectionOn(const Vec2 &vec) const;
		Vec2 getRotated(float radians) const;

		//statics
		static float angleBetween(const Vec2 &v1, const Vec2 &v2);

		//selfOperators
		const Vec2& operator=(const Vec2 &vec);
		const Vec2& operator+=(const Vec2 &vec);
		const Vec2& operator-=(const Vec2 &vec);
		const Vec2& operator*=(float scalar);
		const Vec2& operator/=(float scalar);
		const Vec2 operator-() const;

		friend const Vec2 operator+(const Vec2 &v1, const Vec2 &v2);
		friend const Vec2 operator-(const Vec2 &v1, const Vec2 &v2);
		friend const float operator*(const Vec2 &v1, const Vec2 &v2);
		friend const Vec2 operator*(const Vec2 &vec, float scalar);
		friend const Vec2 operator*(float scalar, const Vec2 &vec);
		friend const Vec2 operator/(const Vec2 &vec, float scalar);

		//crossOperators
		friend const Vec2 operator*(const Mat2 &mat, const Vec2 &vec);
	};
}

#endif