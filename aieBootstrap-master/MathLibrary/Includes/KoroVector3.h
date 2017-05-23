#pragma once
#include "KoroMaths.h"

//---- Vector3 ---- 




	class Vector3
	{
	public:
		Vector3 ();
		Vector3 (float x, float y, float z);
		~Vector3 ();



		float GetX ();
		float GetY ();
		float GetZ ();

		Vector3 add (Vector3 other);
		Vector3 subtract (Vector3 other);
		Vector3 multiply (Vector3 other);
		Vector3 cross (Vector3 other);
		float dot (Vector3 other);
		float magnitude ();
		void normalise ();
	
		float & operator[](int index);
		
		

		friend Vector3 operator*(float, Vector3);
		Vector3 operator*(float);


		operator float *() const;
		

		Vector3 operator+(Vector3);
		Vector3 operator-(Vector3);

		float m_x;
		float m_y;
		float m_z;
	private:
	};

