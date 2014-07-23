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
		float x;
		float y;
		float z;
		float w;

		//ctrs
		Vec4();
		Vec4(float nx, float ny, float nz, float nw);
		Vec4(float mag, const Vec4 &dir);
		Vec4(const Vec3 &vec, float nw=1);
		Vec4(const Vec4 &vec);

		//dtr
		~Vec4();

		//alter
		void normalize();
		
		//gets
		float getMag() const;
		float getMagSquared() const;
		Vec4 getUnit() const;
		Vec4 getProjectionOn(const Vec4 &vec) const;
		
		//statics
		static float angleBetween(const Vec4 &v1, const Vec4 &v2);
		
		//selfOperators
		const Vec4& operator=(const Vec4 &vec);
		const Vec4& operator+=(const Vec4 &vec);
		const Vec4& operator-=(const Vec4 &vec);
		const Vec4& operator*=(float scalar);
		const Vec4& operator/=(float scalar);
		const Vec4 operator-() const;

		friend const Vec4 operator+(const Vec4 &v1, const Vec4 &v2);
		friend const Vec4 operator-(const Vec4 &v1, const Vec4 &v2);
		friend const float operator*(const Vec4 &v1, const Vec4 &v2);
		friend const Vec4 operator*(const Vec4 &vec, float scalar);
		friend const Vec4 operator*(float scalar, const Vec4 &vec);
		friend const Vec4 operator/(const Vec4 &vec, float scalar);

		//crossOperators
		friend const Vec4 operator*(const Mat4 &mat, const Vec4 &vec);
	};
}

#endif