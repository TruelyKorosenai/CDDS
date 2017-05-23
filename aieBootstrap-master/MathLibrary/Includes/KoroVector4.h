#pragma once
#include "KoroMaths.h"


	class Vector4
	{



	public:
		Vector4 ();
		Vector4 (float x, float y, float z, float w);
		~Vector4 ();



		float GetX ();
		float GetY ();
		float GetZ ();
		float GetW ();

		Vector4 add (Vector4 other);
		Vector4 subtract (Vector4 other);
		Vector4 multiply (Vector4 other);
		Vector4 cross (Vector4 other);
		float dot (Vector4 other);
		float magnitude ();
		void normalise ();


		friend Vector4 operator*(float, Vector4);
		Vector4 operator*(float);

		Vector4 operator+(Vector4);
		Vector4 operator-(Vector4);

		operator float *() const;
		
			
		

		float & operator[](int index);

		float m_x;
		float m_y;
		float m_z;
		float m_w;
	private:

	};

