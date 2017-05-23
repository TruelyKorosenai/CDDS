#pragma once
#include "KoroMaths.h"

class Matrix4
{
public:
	Matrix4 (float m_00, float m_10, float m_20, float  m_30,
		     float m_01, float m_11, float m_21, float  m_31,
			 float m_02, float m_12, float m_22, float  m_32,
			 float m_03, float m_13, float m_23, float  m_33);

	float m_matrix4[4][4];

	void setidentity ();
	void setRotateX (float rotation);
	void setRotateY (float rotation);
	void setRotateZ (float rotation);

	Matrix4 & operator=(Matrix4 &other);
	Vector4 &Matrix4::operator[](int index);
	Matrix4 operator*(Matrix4 &other);
	Vector4 operator*(Vector4 &other);
	operator float*();

	Matrix4 ();
	~Matrix4 ();
};

