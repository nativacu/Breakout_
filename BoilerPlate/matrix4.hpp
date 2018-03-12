#include <iostream>
#include "vector3.hpp"

#pragma once
#ifndef MATRIX4
#define MATRIX4

class matrix4
{
public:
	/*CONSTRUCTORS*/
		matrix4();
	matrix4(float, float, float, float, float, float, float, float, float, float, float, float, float,
		float, float, float);
	matrix4(float[16]);

	/*PUBLIC FUNCTIONS*/
	float* get();
	float get_entry(int, int);
	void identity();
	friend std::ostream& operator<<(std::ostream&, const matrix4&);
	float operator[](float);
	matrix4 operator+(matrix4);
	matrix4 operator-(matrix4);
	matrix4 operator*(matrix4);
	matrix4 get_transpose();
	vector3 get_rotation(float&, float&, float&);


private:
	/*PRIVATE MEMBERS*/
		float matrixEntries[4][4];
};

#endif // !MATRIX4