#include "matrix4.hpp"
#include <math.h>
#include "mathUtilities.hpp"

engine::math::matrix4::matrix4()
{
	identity();
}

engine::math::matrix4::matrix4(float entry0, float entry1, float entry2, float entry3, float entry4,
	float entry5, float entry6, float entry7, float entry8, float entry9, float entry10,
	float entry11, float entry12, float entry13, float entry14, float entry15)
{
	matrixEntries[0] = entry0;
	matrixEntries[1] = entry1;
	matrixEntries[2] = entry2;
	matrixEntries[3] = entry3;

	matrixEntries[4] = entry4;
	matrixEntries[5] = entry5;
	matrixEntries[6] = entry6;
	matrixEntries[7] = entry7;

	matrixEntries[8] = entry8;
	matrixEntries[9] = entry9;
	matrixEntries[10] = entry10;
	matrixEntries[11] = entry11;

	matrixEntries[12] = entry12;
	matrixEntries[13] = entry13;
	matrixEntries[14] = entry14;
	matrixEntries[15] = entry15;
}

engine::math::matrix4::matrix4(float inputEntries[16])
{
	//First column
	matrixEntries[0] = inputEntries[0];
	matrixEntries[1] = inputEntries[1];
	matrixEntries[2] = inputEntries[2];
	matrixEntries[3] = inputEntries[3];

	//Second column
	matrixEntries[4] = inputEntries[4];
	matrixEntries[5] = inputEntries[5];
	matrixEntries[6] = inputEntries[6];
	matrixEntries[7] = inputEntries[7];

	//Third column
	matrixEntries[8] = inputEntries[8];
	matrixEntries[9] = inputEntries[9];
	matrixEntries[10] = inputEntries[10];
	matrixEntries[11] = inputEntries[11];

	//Fourth column
	matrixEntries[12] = inputEntries[12];
	matrixEntries[13] = inputEntries[13];
	matrixEntries[14] = inputEntries[14];
	matrixEntries[15] = inputEntries[15];
}

float * engine::math::matrix4::get()
{
	return matrixEntries;
}

float engine::math::matrix4::get_entry(int column, int row)
{
	int linearIndex = row + (4 * column);
	return matrixEntries[linearIndex];
}

void engine::math::matrix4::identity()
{
	//First column
	matrixEntries[0] = 1;
	matrixEntries[1] = 0;
	matrixEntries[2] = 0;
	matrixEntries[3] = 0;

	//Second column
	matrixEntries[4] = 0;
	matrixEntries[5] = 1;
	matrixEntries[6] = 0;
	matrixEntries[7] = 0;

	//Third column
	matrixEntries[8] = 0;
	matrixEntries[9] = 0;
	matrixEntries[10] = 1;
	matrixEntries[11] = 0;

	//Fourth column
	matrixEntries[12] = 0;
	matrixEntries[13] = 0;
	matrixEntries[14] = 0;
	matrixEntries[15] = 1;
}

void engine::math::matrix4::operator=(matrix4 rhs)
{
	matrixEntries[0] = rhs.matrixEntries[0];
	matrixEntries[1] = rhs.matrixEntries[1];
	matrixEntries[2] = rhs.matrixEntries[2];
	matrixEntries[3] = rhs.matrixEntries[3];

	matrixEntries[4] = rhs.matrixEntries[4];
	matrixEntries[5] = rhs.matrixEntries[5];
	matrixEntries[6] = rhs.matrixEntries[6];
	matrixEntries[7] = rhs.matrixEntries[7];

	matrixEntries[8] = rhs.matrixEntries[8];
	matrixEntries[9] = rhs.matrixEntries[9];
	matrixEntries[10] = rhs.matrixEntries[10];
	matrixEntries[11] = rhs.matrixEntries[11];

	matrixEntries[12] = rhs.matrixEntries[12];
	matrixEntries[13] = rhs.matrixEntries[13];
	matrixEntries[14] = rhs.matrixEntries[14];
	matrixEntries[15] = rhs.matrixEntries[15];
}

float engine::math::matrix4::operator[](int index)
{
	return matrixEntries[index];
}

std::ostream & engine::math::operator<<(std::ostream& ostream, const engine::math::matrix4& matrix)
{
	//First row
	ostream << matrix.matrixEntries[0]<< " ";
	ostream << matrix.matrixEntries[4] << " ";
	ostream << matrix.matrixEntries[8] << " ";
	ostream << matrix.matrixEntries[12] << " ";
	ostream << std::endl;

	//Second row
	ostream << matrix.matrixEntries[1] << " ";
	ostream << matrix.matrixEntries[5] << " ";
	ostream << matrix.matrixEntries[9] << " ";
	ostream << matrix.matrixEntries[13] << " ";
	ostream << std::endl;

	//Third row
	ostream << matrix.matrixEntries[2] << " ";
	ostream << matrix.matrixEntries[6] << " ";
	ostream << matrix.matrixEntries[10] << " ";
	ostream << matrix.matrixEntries[14] << " ";
	ostream << std::endl;

	//Fourth row
	ostream << matrix.matrixEntries[3] << " ";
	ostream << matrix.matrixEntries[7] << " ";
	ostream << matrix.matrixEntries[11] << " ";
	ostream << matrix.matrixEntries[15] << " ";
	ostream << std::endl;

	return ostream;
}

engine::math::matrix4 engine::math::matrix4::get_transpose()
{
	matrix4 transpose;

	//Set first column using original's first row
	transpose.matrixEntries[0] = matrixEntries[0];
	transpose.matrixEntries[1] = matrixEntries[4];
	transpose.matrixEntries[2] = matrixEntries[8];
	transpose.matrixEntries[3] = matrixEntries[12];

	//Set second column using original's second row
	transpose.matrixEntries[4] = matrixEntries[1];
	transpose.matrixEntries[5] = matrixEntries[5];
	transpose.matrixEntries[6] = matrixEntries[9];
	transpose.matrixEntries[7] = matrixEntries[13];

	//Set third column using original's third row
	transpose.matrixEntries[8] = matrixEntries[2];
	transpose.matrixEntries[9] = matrixEntries[6];
	transpose.matrixEntries[10] = matrixEntries[10];
	transpose.matrixEntries[11] = matrixEntries[14];

	//Set fourth column using original's fourth row
	transpose.matrixEntries[12] = matrixEntries[3];
	transpose.matrixEntries[13] = matrixEntries[7];
	transpose.matrixEntries[14] = matrixEntries[11];
	transpose.matrixEntries[15] = matrixEntries[15];

	return transpose;
}

engine::math::vector3 engine::math::matrix4::get_angle()
{
	engine::math::mathUtilities utility;
	vector3 angles;
	float yaw, pitch, roll;
	
	//Get angles
	if (matrixEntries[0] == 1.0f || matrixEntries[0] == -1.0f) {
		yaw = atan2f(matrixEntries[8], matrixEntries[14]);
		pitch = 0.0f;
		roll = 0.0f;
	}

	else {
		yaw = atan2f(-matrixEntries[2], matrixEntries[0]);
		pitch = asinf(matrixEntries[1]);
		roll = atan2f(-matrixEntries[9], matrixEntries[5]);
	}

	//Convert angles returned in radians to degrees
	yaw = utility.to_degrees(yaw);
	pitch = utility.to_degrees(pitch);
	roll = utility.to_degrees(roll);

	angles.x = yaw;
	angles.y = pitch;
	angles.z = roll;

	return angles;
}

float * engine::math::matrix4::get_row(int row)
{
	float retrievedRow[4];

	retrievedRow[0] = matrixEntries[row];
	retrievedRow[1] = matrixEntries[row += 4];
	retrievedRow[2] = matrixEntries[row += 4];
	retrievedRow[3] = matrixEntries[row += 4];

	return retrievedRow;
}

float * engine::math::matrix4::get_column(int column)
{
	float retrievedColumn[4];

	retrievedColumn[0] = matrixEntries[column * 4];
	retrievedColumn[1] = matrixEntries[(column * 4) + 1];
	retrievedColumn[2] = matrixEntries[(column * 4) + 2];
	retrievedColumn[3] = matrixEntries[(column * 4) + 3];

	return retrievedColumn;
}

bool engine::math::matrix4::get_inverse(engine::math::matrix4& result)
{
	float determinant;

	result.get()[0] = matrixEntries[5] * matrixEntries[10] * matrixEntries[15] - matrixEntries[5] * matrixEntries[11] * matrixEntries[14] -
		matrixEntries[9] * matrixEntries[6] * matrixEntries[15] + matrixEntries[9] * matrixEntries[7] * matrixEntries[14] +
		matrixEntries[13] * matrixEntries[6] * matrixEntries[11] - matrixEntries[13] * matrixEntries[7] * matrixEntries[10];


	result.get()[4] = -matrixEntries[4] * matrixEntries[10] * matrixEntries[15] + matrixEntries[4] * matrixEntries[11] * matrixEntries[14] +
		matrixEntries[8] * matrixEntries[6] * matrixEntries[15] - matrixEntries[8] * matrixEntries[7] * matrixEntries[14] -
		matrixEntries[12] * matrixEntries[6] * matrixEntries[11] + matrixEntries[12] * matrixEntries[7] * matrixEntries[10];

	result.get()[8] = matrixEntries[4] * matrixEntries[9] * matrixEntries[15] - matrixEntries[4] * matrixEntries[11] * matrixEntries[13] -
		matrixEntries[8] * matrixEntries[5] * matrixEntries[15] + matrixEntries[8] * matrixEntries[7] * matrixEntries[13] +
		matrixEntries[12] * matrixEntries[5] * matrixEntries[11] - matrixEntries[12] * matrixEntries[7] * matrixEntries[9];

	result.get()[12] = -matrixEntries[4] * matrixEntries[9] * matrixEntries[14] + matrixEntries[4] * matrixEntries[10] * matrixEntries[13] +
		matrixEntries[8] * matrixEntries[5] * matrixEntries[14] - matrixEntries[8] * matrixEntries[6] * matrixEntries[13] -
		matrixEntries[12] * matrixEntries[5] * matrixEntries[10] + matrixEntries[12] * matrixEntries[6] * matrixEntries[9];

	result.get()[1] = -matrixEntries[1] * matrixEntries[10] * matrixEntries[15] + matrixEntries[1] * matrixEntries[11] * matrixEntries[14] +
		matrixEntries[9] * matrixEntries[2] * matrixEntries[15] - matrixEntries[9] * matrixEntries[3] * matrixEntries[14] -
		matrixEntries[13] * matrixEntries[2] * matrixEntries[11] + matrixEntries[13] * matrixEntries[3] * matrixEntries[10];

	result.get()[5] = matrixEntries[0] * matrixEntries[10] * matrixEntries[15] - matrixEntries[0] * matrixEntries[11] * matrixEntries[14] -
		matrixEntries[8] * matrixEntries[2] * matrixEntries[15] + matrixEntries[8] * matrixEntries[3] * matrixEntries[14] +
		matrixEntries[12] * matrixEntries[2] * matrixEntries[11] - matrixEntries[12] * matrixEntries[3] * matrixEntries[10];

	result.get()[9] = -matrixEntries[0] * matrixEntries[9] * matrixEntries[15] + matrixEntries[0] * matrixEntries[11] * matrixEntries[13] +
		matrixEntries[8] * matrixEntries[1] * matrixEntries[15] - matrixEntries[8] * matrixEntries[3] * matrixEntries[13] -
		matrixEntries[12] * matrixEntries[1] * matrixEntries[11] + matrixEntries[12] * matrixEntries[3] * matrixEntries[9];

	result.get()[13] = matrixEntries[0] * matrixEntries[9] * matrixEntries[14] - matrixEntries[0] * matrixEntries[10] * matrixEntries[13] -
		matrixEntries[8] * matrixEntries[1] * matrixEntries[14] + matrixEntries[8] * matrixEntries[2] * matrixEntries[13] +
		matrixEntries[12] * matrixEntries[1] * matrixEntries[10] - matrixEntries[12] * matrixEntries[2] * matrixEntries[9];

	result.get()[2] = matrixEntries[1] * matrixEntries[6] * matrixEntries[15] - matrixEntries[1] * matrixEntries[7] * matrixEntries[14] -
		matrixEntries[5] * matrixEntries[2] * matrixEntries[15] + matrixEntries[5] * matrixEntries[3] * matrixEntries[14] +
		matrixEntries[13] * matrixEntries[2] * matrixEntries[7] - matrixEntries[13] * matrixEntries[3] * matrixEntries[6];

	result.get()[6] = -matrixEntries[0] * matrixEntries[6] * matrixEntries[15] + matrixEntries[0] * matrixEntries[7] * matrixEntries[14] +
		matrixEntries[4] * matrixEntries[2] * matrixEntries[15] - matrixEntries[4] * matrixEntries[3] * matrixEntries[14] -
		matrixEntries[12] * matrixEntries[2] * matrixEntries[7] + matrixEntries[12] * matrixEntries[3] * matrixEntries[6];

	result.get()[10] = matrixEntries[0] * matrixEntries[5] * matrixEntries[15] - matrixEntries[0] * matrixEntries[7] * matrixEntries[13] -
		matrixEntries[4] * matrixEntries[1] * matrixEntries[15] + matrixEntries[4] * matrixEntries[3] * matrixEntries[13] +
		matrixEntries[12] * matrixEntries[1] * matrixEntries[7] - matrixEntries[12] * matrixEntries[3] * matrixEntries[5];

	result.get()[14] = -matrixEntries[0] * matrixEntries[5] * matrixEntries[14] + matrixEntries[0] * matrixEntries[6] * matrixEntries[13] +
		matrixEntries[4] * matrixEntries[1] * matrixEntries[14] - matrixEntries[4] * matrixEntries[2] * matrixEntries[13] -
		matrixEntries[12] * matrixEntries[1] * matrixEntries[6] + matrixEntries[12] * matrixEntries[2] * matrixEntries[5];

	result.get()[3] = -matrixEntries[1] * matrixEntries[6] * matrixEntries[11] + matrixEntries[1] * matrixEntries[7] * matrixEntries[10] +
		matrixEntries[5] * matrixEntries[2] * matrixEntries[11] - matrixEntries[5] * matrixEntries[3] * matrixEntries[10] -
		matrixEntries[9] * matrixEntries[2] * matrixEntries[7] + matrixEntries[9] * matrixEntries[3] * matrixEntries[6];

	result.get()[7] = matrixEntries[0] * matrixEntries[6] * matrixEntries[11] - matrixEntries[0] * matrixEntries[7] * matrixEntries[10] -
		matrixEntries[4] * matrixEntries[2] * matrixEntries[11] + matrixEntries[4] * matrixEntries[3] * matrixEntries[10] +
		matrixEntries[8] * matrixEntries[2] * matrixEntries[7] - matrixEntries[8] * matrixEntries[3] * matrixEntries[6];

	result.get()[11] = -matrixEntries[0] * matrixEntries[5] * matrixEntries[11] + matrixEntries[0] * matrixEntries[7] * matrixEntries[9] +
		matrixEntries[4] * matrixEntries[1] * matrixEntries[11] - matrixEntries[4] * matrixEntries[3] * matrixEntries[9] -
		matrixEntries[8] * matrixEntries[1] * matrixEntries[7] + matrixEntries[8] * matrixEntries[3] * matrixEntries[5];

	result.get()[15] = matrixEntries[0] * matrixEntries[5] * matrixEntries[10] - matrixEntries[0] * matrixEntries[6] * matrixEntries[9] -
		matrixEntries[4] * matrixEntries[1] * matrixEntries[10] + matrixEntries[4] * matrixEntries[2] * matrixEntries[9] +
		matrixEntries[8] * matrixEntries[1] * matrixEntries[6] - matrixEntries[8] * matrixEntries[2] * matrixEntries[5];

	determinant = matrixEntries[0] * result[0] + matrixEntries[1] * result[4] + matrixEntries[2] * result[8] + matrixEntries[3] * result[12];

	if (determinant == 0) {
		return false;
	}

	else {
		determinant = 1 / determinant;
		for (int i = 0; i < 16; i++) {
			result.get()[i] = result[i] * determinant;
		}

		return true;
	}
}

void engine::math::matrix4::rotate_x(float angle)
{
	matrix4 xRotationMatrix;

	xRotationMatrix.matrixEntries[5] = std::cosf(-angle);
	xRotationMatrix.matrixEntries[6] = -std::sinf(-angle);
	xRotationMatrix.matrixEntries[9] = std::sinf(-angle);
	xRotationMatrix.matrixEntries[10] = std::cosf(-angle);

	*this = *this * xRotationMatrix;
}

void engine::math::matrix4::rotate_y(float angle)
{
	matrix4 yRotationMatrix;

	yRotationMatrix.matrixEntries[0] = std::cosf(-angle);
	yRotationMatrix.matrixEntries[2] = std::sinf(-angle);
	yRotationMatrix.matrixEntries[8] = -std::sinf(-angle);
	yRotationMatrix.matrixEntries[10] = std::cosf(-angle);

	*this = *this * yRotationMatrix;
}

void engine::math::matrix4::rotate_z(float angle)
{
	matrix4 zRotationMatrix;

	zRotationMatrix.matrixEntries[0] = std::cosf(-angle);
	zRotationMatrix.matrixEntries[1] = -std::sinf(-angle);
	zRotationMatrix.matrixEntries[4] = std::sinf(-angle);
	zRotationMatrix.matrixEntries[5] = std::cosf(-angle);

	*this = *this * zRotationMatrix;
}

void engine::math::matrix4::translate_matrix(vector4 vector)
{
	matrix4 translated;

	translated.matrixEntries[12] = vector.x;
	translated.matrixEntries[13] = vector.y;
	translated.matrixEntries[14] = vector.z;


	*this = *this * translated;
}

engine::math::matrix4 engine::math::matrix4::operator+(matrix4 rightHandSide) {
	matrix4 result;

	result.get()[0] = matrixEntries[0] + rightHandSide[0];
	result.get()[1] = matrixEntries[1] + rightHandSide[1];
	result.get()[2] = matrixEntries[2] + rightHandSide[2];
	result.get()[3] = matrixEntries[3] + rightHandSide[3];

	result.get()[4] = matrixEntries[4] + rightHandSide[4];
	result.get()[5] = matrixEntries[5] + rightHandSide[5];
	result.get()[6] = matrixEntries[6] + rightHandSide[6];
	result.get()[7] = matrixEntries[7] + rightHandSide[7];

	result.get()[8] = matrixEntries[8] + rightHandSide[8];
	result.get()[9] = matrixEntries[9] + rightHandSide[9];
	result.get()[10] = matrixEntries[10] + rightHandSide[9];
	result.get()[11] = matrixEntries[11] + rightHandSide[9];

	result.get()[12] = matrixEntries[12] + rightHandSide[10];
	result.get()[13] = matrixEntries[13] + rightHandSide[11];
	result.get()[14] = matrixEntries[14] + rightHandSide[12];
	result.get()[15] = matrixEntries[15] + rightHandSide[13];

	return result;
}

engine::math::matrix4 engine::math::matrix4::operator-(matrix4 rightHandSide) {
	matrix4 result;

	result.get()[0] = matrixEntries[0] - rightHandSide[0];
	result.get()[1] = matrixEntries[1] - rightHandSide[1];
	result.get()[2] = matrixEntries[2] - rightHandSide[2];
	result.get()[3] = matrixEntries[3] - rightHandSide[3];

	result.get()[4] = matrixEntries[4] - rightHandSide[4];
	result.get()[5] = matrixEntries[5] - rightHandSide[5];
	result.get()[6] = matrixEntries[6] - rightHandSide[6];
	result.get()[7] = matrixEntries[7] - rightHandSide[7];

	result.get()[8] = matrixEntries[8] - rightHandSide[8];
	result.get()[9] = matrixEntries[9] - rightHandSide[9];
	result.get()[10] = matrixEntries[10] - rightHandSide[9];
	result.get()[11] = matrixEntries[11] - rightHandSide[9];

	result.get()[12] = matrixEntries[12] - rightHandSide[10];
	result.get()[13] = matrixEntries[13] - rightHandSide[11];
	result.get()[14] = matrixEntries[14] - rightHandSide[12];
	result.get()[15] = matrixEntries[15] - rightHandSide[13];

	return result;
}

engine::math::matrix4 engine::math::matrix4::operator*(engine::math::matrix4 rightHandSide) {
	float resultEntries[16];

	resultEntries[0] = matrixEntries[0] * rightHandSide[0] + matrixEntries[1] * rightHandSide[4] + matrixEntries[2] * rightHandSide[8] + matrixEntries[3] * rightHandSide[12];
	resultEntries[1] = matrixEntries[0] * rightHandSide[1] + matrixEntries[1] * rightHandSide[5] + matrixEntries[2] * rightHandSide[9] + matrixEntries[3] * rightHandSide[13];
	resultEntries[2] = matrixEntries[0] * rightHandSide[2] + matrixEntries[1] * rightHandSide[6] + matrixEntries[2] * rightHandSide[10] + matrixEntries[3] * rightHandSide[14];
	resultEntries[3] = matrixEntries[0] * rightHandSide[3] + matrixEntries[1] * rightHandSide[7] + matrixEntries[2] * rightHandSide[11] + matrixEntries[3] * rightHandSide[15];

	resultEntries[4] = matrixEntries[4] * rightHandSide[0] + matrixEntries[5] * rightHandSide[4] + matrixEntries[6] * rightHandSide[8] + matrixEntries[7] * rightHandSide[12];
	resultEntries[5] = matrixEntries[4] * rightHandSide[1] + matrixEntries[5] * rightHandSide[5] + matrixEntries[6] * rightHandSide[9] + matrixEntries[7] * rightHandSide[13];
	resultEntries[6] = matrixEntries[4] * rightHandSide[2] + matrixEntries[5] * rightHandSide[6] + matrixEntries[6] * rightHandSide[10] + matrixEntries[7] * rightHandSide[14];
	resultEntries[7] = matrixEntries[4] * rightHandSide[3] + matrixEntries[5] * rightHandSide[7] + matrixEntries[6] * rightHandSide[11] + matrixEntries[7] * rightHandSide[15];

	resultEntries[8] = matrixEntries[8] * rightHandSide[0] + matrixEntries[9] * rightHandSide[4] + matrixEntries[10] * rightHandSide[8] + matrixEntries[11] * rightHandSide[12];
	resultEntries[9] = matrixEntries[8] * rightHandSide[1] + matrixEntries[9] * rightHandSide[5] + matrixEntries[10] * rightHandSide[9] + matrixEntries[11] * rightHandSide[13];
	resultEntries[10] = matrixEntries[8] * rightHandSide[2] + matrixEntries[9] * rightHandSide[6] + matrixEntries[10] * rightHandSide[10] + matrixEntries[11] * rightHandSide[14];
	resultEntries[11] = matrixEntries[8] * rightHandSide[3] + matrixEntries[9] * rightHandSide[7] + matrixEntries[10] * rightHandSide[11] + matrixEntries[11] * rightHandSide[15];

	resultEntries[12] = matrixEntries[12] * rightHandSide[0] + matrixEntries[13] * rightHandSide[4] + matrixEntries[14] * rightHandSide[8] + matrixEntries[15] * rightHandSide[12];
	resultEntries[13] = matrixEntries[12] * rightHandSide[1] + matrixEntries[13] * rightHandSide[5] + matrixEntries[14] * rightHandSide[9] + matrixEntries[15] * rightHandSide[13];
	resultEntries[14] = matrixEntries[12] * rightHandSide[2] + matrixEntries[13] * rightHandSide[6] + matrixEntries[14] * rightHandSide[10] + matrixEntries[15] * rightHandSide[14];
	resultEntries[15] = matrixEntries[12] * rightHandSide[3] + matrixEntries[13] * rightHandSide[7] + matrixEntries[14] * rightHandSide[11] + matrixEntries[15] * rightHandSide[15];

	return matrix4(resultEntries);
}

void engine::math::matrix4::rotate_using_degrees(float angle)
{
	engine::math::mathUtilities utility;

	rotate_z(utility.to_radians(angle));
}

void engine::math::matrix4::rotate_using_radians(float angle)
{
	rotate_z(angle);
}

engine::math::matrix4 engine::math::matrix4::operator/(matrix4 rightHandSide) {
	matrix4 result;
	matrix4 rightHandSideInverse;

	if (rightHandSide.get_inverse(rightHandSideInverse)) {
		result = *this * rightHandSideInverse;
	}

	return result;
}

engine::math::matrix4 engine::math::matrix4::look_at(vector3 currentPosition, vector3 newPosition)
{
	matrix4 result;
	vector3 up, forward, right, temporary(0.0, 1.0, 0.0);
	forward = currentPosition - newPosition;
	forward.normalize();
	right = temporary * forward;
	right.normalize();
	up = forward * right;

	result.get()[0] = right.x;
	result.get()[4] = right.y;
	result.get()[8] = right.z;
	result.get()[1] = up.x;
	result.get()[5] = up.y;
	result.get()[9] = up.z;
	result.get()[2] = forward.x;
	result.get()[6] = forward.y;
	result.get()[10] = forward.z;

	result.get()[3] = currentPosition.x;
	result.get()[7] = currentPosition.y;
	result.get()[11] = newPosition.z;

	return result;
}

void engine::math::matrix4::make_perspective_matrix(const float &angleOfView, const float &nearClippingPane, 
const float &farClippingPane, const float &imageAspectRatio)
{
	mathUtilities utility;

	float sceneScale = static_cast<float> (1.0f / std::tanf(utility.to_radians(angleOfView * 0.5f)));
	float deltaClippingPane = farClippingPane - nearClippingPane;
	float inverseDelta = 1.0f / deltaClippingPane;

	matrixEntries[0] = sceneScale * imageAspectRatio;
	matrixEntries[5] = sceneScale;
	matrixEntries[10] = -farClippingPane * inverseDelta;
	matrixEntries[11] = -1.0f;
	matrixEntries[14] = -farClippingPane * nearClippingPane * inverseDelta;
	matrixEntries[15] = 0;
}

void engine::math::matrix4::make_orthographic_matrix(float maxWidth, float minWidth, float maxHeight, float minHeight, float maxZ, float minZ)
{
	//https://www.scratchapixel.com/lessons/3d-basic-rendering/perspective-and-orthographic-projection-matrix/orthographic-projection-matrix
	matrixEntries[0] = 2.0f / (maxWidth - minWidth);
	matrixEntries[5] = 2.0f / (maxHeight - minHeight);
	matrixEntries[10] = -2.0f / (maxZ - minZ);
	matrixEntries[12] = -(maxWidth + minWidth) / (maxWidth - minWidth);
	matrixEntries[13] = -(maxHeight + minHeight) / maxHeight - minHeight;
	matrixEntries[14] = -(maxZ + minZ) / (maxZ - minZ);
}

void engine::math::matrix4::scale_matrix(float pX, float pY, float pZ)
{
	matrix4 scalingMatrix;
	scalingMatrix.matrixEntries[0] = pX;
	scalingMatrix.matrixEntries[5] = pY;
	scalingMatrix.matrixEntries[10] = pZ;

	*this = *this * scalingMatrix;
}

void engine::math::matrix4::set_matrix(float newMatrix[16])
{
	//First column
	newMatrix[0] = matrixEntries[0];
	newMatrix[1] = matrixEntries[1];
	newMatrix[2] = matrixEntries[2];
	newMatrix[3] = matrixEntries[3];

	//Second column
	newMatrix[4] = matrixEntries[4];
	newMatrix[5] = matrixEntries[5];
	newMatrix[6] = matrixEntries[6];
	newMatrix[7] = matrixEntries[7];

	//Third column
	newMatrix[8] = matrixEntries[8];
	newMatrix[9] = matrixEntries[9];
	newMatrix[10] = matrixEntries[10];
	newMatrix[11] = matrixEntries[11];

	//Fourth column
	newMatrix[12] = matrixEntries[12];
	newMatrix[13] = matrixEntries[13];
	newMatrix[14] = matrixEntries[14];
	newMatrix[15] = matrixEntries[15];
}
