#pragma once
#include "KoroMaths.h"

//---- Vector2 ---- 

	class Vector2
	{
	public:
		Vector2 ();
		Vector2 (float x , float y);
		~Vector2 ();

	
		float GetX ();
		float GetY ();
		Vector2 add (Vector2 other);
		Vector2 subtract (Vector2 other);
		Vector2 multiply (Vector2 other);
		float dot (Vector2 other);
		float magnitude ();
		void normalise ();
		void setX (float x);
		void setY (float y);

		operator float *() const;
		
	
		friend Vector2 operator*(float, Vector2);
		Vector2 operator*(float);
		Vector2 operator+(Vector2);
		Vector2 operator-(Vector2);
	
		float & operator[](int index);
		//Vector2 MultiplyMatrixVector (Matrix2 & other);
		float m_x;
		float m_y;
	private:

	};




