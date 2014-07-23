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
		float x;
		float y;
		float z;

		//ctrs
		Vec3();
		Vec3(float nx, float ny, float nz);
		Vec3(float mag, const Vec3 &dir);
		Vec3(const Vec2 &vec, float nz=1);
		Vec3(const Vec3 &vec);

		//dtr
		~Vec3();

		//alter
		void normalize();
		void rotateAbout(float radians, const Vec3 &vec);
		void rotate(const Vec3 &vec);

		//gets
		float getMag() const;
		float getMagSquared() const;
		Vec3 getUnit() const;
		Vec3 getProjectionOn(const Vec3 &vec) const;
		Vec3 getRotated(float radians, const Vec3 &vec) const;
		Vec3 getRotated(const Vec3 &vec) const;

		//statics
		static float angleBetween(const Vec3 &v1, const Vec3 &v2);
		static Vec3 crossProduct(const Vec3 &v1, const Vec3 &v2);

		//selfOperators
		const Vec3& operator=(const Vec3 &vec);
		const Vec3& operator+=(const Vec3 &vec);
		const Vec3& operator-=(const Vec3 &vec);
		const Vec3& operator*=(float scalar);
		const Vec3& operator/=(float scalar);
		const Vec3 operator-() const;

		friend const Vec3 operator+(const Vec3 &v1, const Vec3 &v2);
		friend const Vec3 operator-(const Vec3 &v1, const Vec3 &v2);
		friend const float operator*(const Vec3 &v1, const Vec3 &v2);
		friend const Vec3 operator*(const Vec3 &vec, float scalar);
		friend const Vec3 operator*(float scalar, const Vec3 &vec);
		friend const Vec3 operator/(const Vec3 &vec, float scalar);

		//crossOperators
		friend const Vec3 operator*(const Mat3 &mat, const Vec3 &vec);
	};
}

#endif