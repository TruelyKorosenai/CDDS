#pragma once
#include "KoroMaths.h"

    class Matrix3
    {
    public:
        Matrix3(float m_00, float m_10, float m_20,
                float m_01, float m_11, float m_21,
                float m_02, float m_12, float m_22);

        float m_matrix3[3][3];
        void setidentity();
        void setRotateX(float rotation);
        void setRotateY(float rotation);
        void setRotateZ(float rotation);

		Matrix3 &SetTranslateFloats (float x , float y);
		Matrix3 &SetTranslateVectors (Vector2 & other);
		Matrix3 SetScaleWithFloats (float x, float y);
		Matrix3 SetScaleWithVectors (Vector2 & other);


        Matrix3 &operator=(Matrix3 &other);
        Matrix3 operator*(Matrix3 &other);
        Vector3 operator*(Vector3 &other);
        Vector3 &Matrix3::operator[](int index);

        operator float*();

        Matrix3();
        ~Matrix3();
    };

