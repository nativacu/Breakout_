#include <iostream>
#include "vector3.hpp"
#include "vector4.hpp"
#include "mathUtilities.hpp"

#pragma once
#ifndef MATRIX4
#define MATRIX4

namespace engine {
	namespace math {
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
			matrix4 rotate_x(float);
			matrix4 rotate_y(float);
			matrix4 rotate_z(float);
			matrix4 get_translate_matrix(vector4);
			void translate_matrix(vector4);
			matrix4 operator/(matrix4);

			bool get_inverse(matrix4&);


		private:
			/*PRIVATE MEMBERS*/
			float matrixEntries[16];
		};
	}
}
// http://www.opengl-tutorial.org/beginners-tutorials/tutorial-3-matrices/

#endif // !MATRIX4