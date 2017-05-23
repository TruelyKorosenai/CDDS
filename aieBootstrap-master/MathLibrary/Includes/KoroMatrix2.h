#pragma once
#include "KoroMaths.h"


	class Matrix2

	{

	public:
		
		Matrix2 ();
		Matrix2 (float m_00, float m_01, float m_10, float m_11);
		~Matrix2 ();
	
		void setRotate (float angle);
		void setIdentity ();

		void operator=(Matrix2 & other);
		
		Matrix2 operator* (Matrix2 & other);
		operator float *() const;
		Vector2 & operator[] (const int index);
		Vector2 operator*(Vector2 &other);
		
	private:
		float m_matrix2[2][2];
	
	};



