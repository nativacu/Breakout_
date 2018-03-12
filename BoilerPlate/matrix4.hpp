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
	float* get_row(int);
	float* get_column(int);
	matrix4 rotate_x(float);
	matrix4 rotate_y(float);
	matrix4 rotate_z(float);



private:
	/*PRIVATE MEMBERS*/
		float matrixEntries[4][4];
};

// http://www.opengl-tutorial.org/beginners-tutorials/tutorial-3-matrices/

#endif // !MATRIX4