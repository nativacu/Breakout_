#include <iostream>
#include "vector3.hpp"
#include "vector4.hpp"
#include "mathUtilities.hpp"

#pragma once
#ifndef MATRIX4
#define MATRIX4

namespace engine 
{
	namespace math 
	{
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
			void operator=(matrix4 rhs);
			float operator[](int);
			matrix4 operator+(matrix4);
			matrix4 operator-(matrix4);
			matrix4 operator*(matrix4);
			matrix4 get_transpose();
			vector3 get_angle();
			float* get_row(int);
			float* get_column(int);
			void rotate_using_degrees(float);
			void rotate_using_radians(float);
			void rotate_x(float);
			void rotate_y(float);
			void rotate_z(float);
			void translate_matrix(vector4);
			matrix4 operator/(matrix4);

			bool get_inverse(matrix4&);
			matrix4 look_at(vector3 currentPosition, vector3 newPosition);
			void make_perspective_matrix(const float&, const float&, const float&, const float&);
			void make_orthographic_matrix(float, float, float, float, float, float);
			void scale_matrix(float, float, float);
			void set_matrix(float[16]);

		private:
			/*PRIVATE MEMBERS*/
			float matrixEntries[16];
		};
	}
}
// http://www.opengl-tutorial.org/beginners-tutorials/tutorial-3-matrices/

#endif // !MATRIX4