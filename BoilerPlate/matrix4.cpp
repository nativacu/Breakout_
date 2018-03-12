#include "matrix4.hpp"
#include <math.h>

matrix4::matrix4()
{
	identity();
}

matrix4::matrix4(float entry0, float entry1, float entry2, float entry3, float entry4,
	float entry5, float entry6, float entry7, float entry8, float entry9, float entry10, 
	float entry11, float entry12, float entry13, float entry14, float entry15)
{
	//First column
	matrixEntries[0][0] = entry0;
	matrixEntries[1][0] = entry1;
	matrixEntries[2][0] = entry2;
	matrixEntries[3][0] = entry3;

	//Second column
	matrixEntries[0][1] = entry4;
	matrixEntries[1][1] = entry5;
	matrixEntries[2][1] = entry6;
	matrixEntries[3][1] = entry7;

	//Third column
	matrixEntries[0][2] = entry8;
	matrixEntries[1][2] = entry9;
	matrixEntries[2][2] = entry10;
	matrixEntries[3][2] = entry11;

	//Fourth column
	matrixEntries[0][3] = entry12;
	matrixEntries[1][3] = entry13;
	matrixEntries[2][3] = entry14;
	matrixEntries[3][3] = entry15;
}

matrix4::matrix4(float inputEntries[16])
{
	//First column
	matrixEntries[0][0] = inputEntries[0];
	matrixEntries[1][0] = inputEntries[1];
	matrixEntries[2][0] = inputEntries[2];
	matrixEntries[3][0] = inputEntries[3];

	//Second column
	matrixEntries[0][1] = inputEntries[4];
	matrixEntries[1][1] = inputEntries[5];
	matrixEntries[2][1] = inputEntries[6];
	matrixEntries[3][1] = inputEntries[7];

	//Third column
	matrixEntries[0][2] = inputEntries[8];
	matrixEntries[1][2] = inputEntries[9];
	matrixEntries[2][2] = inputEntries[10];
	matrixEntries[3][2] = inputEntries[11];

	//Fourth column
	matrixEntries[0][3] = inputEntries[12];
	matrixEntries[1][3] = inputEntries[13];
	matrixEntries[2][3] = inputEntries[14];
	matrixEntries[3][3] = inputEntries[15];
}

float * matrix4::get()
{
	return *matrixEntries;
}

float matrix4::get_entry(int row, int column)
{
	return matrixEntries[row][column];
}

void matrix4::identity()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (i == j)
				matrixEntries[i][j] = 1.0f;
			else
				matrixEntries[i][j] = 0.0f;
		}
	}
}

matrix4 matrix4::get_transpose()
{
	matrix4 transpose;

	//Set first column using original's first row
	transpose.matrixEntries[0][0] = matrixEntries[0][0];
	transpose.matrixEntries[1][0] = matrixEntries[0][1];
	transpose.matrixEntries[2][0] = matrixEntries[0][2];
	transpose.matrixEntries[3][0] = matrixEntries[0][3];

	//Set second column using original's second row
	transpose.matrixEntries[0][1] = matrixEntries[1][0];
	transpose.matrixEntries[1][1] = matrixEntries[1][1];
	transpose.matrixEntries[2][1] = matrixEntries[1][2];
	transpose.matrixEntries[3][1] = matrixEntries[1][3];

	//Set third column using original's third row
	transpose.matrixEntries[0][2] = matrixEntries[2][0];
	transpose.matrixEntries[1][2] = matrixEntries[2][1];
	transpose.matrixEntries[2][2] = matrixEntries[2][2];
	transpose.matrixEntries[3][2] = matrixEntries[2][3];

	//Set fourth column using original's fourth row
	transpose.matrixEntries[0][3] = matrixEntries[3][0];
	transpose.matrixEntries[1][3] = matrixEntries[3][1];
	transpose.matrixEntries[2][3] = matrixEntries[3][2];
	transpose.matrixEntries[3][3] = matrixEntries[3][3];

	return transpose;
}

vector3 matrix4::get_angle(float& yaw, float& pitch, float& roll)
{
	vector3 angles;
	if (matrixEntries[1][1] == 1.0f || matrixEntries[1][1] == -1.0f) {
		yaw = atan2f(matrixEntries[1][3], matrixEntries[3][4]);
		pitch = 0.0f;
		roll = 0.0f;
	}

	else {
		yaw = atan2f(-matrixEntries[3][1], matrixEntries[1][1]);
		pitch = asinf(matrixEntries[2][1]);
		roll = atan2f(-matrixEntries[2][3], matrixEntries[2][2]);
	}

	angles.x = yaw;
	angles.y = pitch;
	angles.z = roll;
	
	return angles;
}

float * matrix4::get_row(int rowIndex)
{
	float retrievedRow[4];

	for (int i = 0; i < 4; i++)
	{
		retrievedRow[i] = matrixEntries[rowIndex][i];
	}

	return retrievedRow;
}

float * matrix4::get_column(int columnIndex)
{
	float retrievedColumn[4];

	for (int i = 0; i < 4; i++)
	{
		retrievedColumn[i] = matrixEntries[i][columnIndex];
	}

	return retrievedColumn;
}

std::ostream& operator<<(std::ostream& ostream, const matrix4& matrix)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			ostream << matrix.matrixEntries[i][j] << " ";
		}
		ostream << std::endl;
	}

	return ostream;
}

float matrix4::operator[](float desiredEntry) {
	bool finished = false;
	int counter = 0;
	int row = 0;
	int column = 0;
	float entry;

	while (!finished) {
		entry = matrixEntries[row][column];
		row++;
		counter++;
		if (row == 4) {
			row = 0;
			column++;
		}
		finished = (counter == desiredEntry);
	}
	return entry;
}

matrix4 matrix4::rotate_x(float angle)
{
	matrix4 xRotationMatrix;

	xRotationMatrix.matrixEntries[1][1] = std::cosf(-angle);
	xRotationMatrix.matrixEntries[2][1] = -std::sinf(-angle);
	xRotationMatrix.matrixEntries[1][2] = std::sinf(-angle);
	xRotationMatrix.matrixEntries[2][2] = std::cosf(-angle);

	return xRotationMatrix;
}

matrix4 matrix4::rotate_y(float angle)
{
	matrix4 yRotationMatrix;

	yRotationMatrix.matrixEntries[0][0] = std::cosf(-angle);
	yRotationMatrix.matrixEntries[2][0] = std::sinf(-angle);
	yRotationMatrix.matrixEntries[0][2] = -std::sinf(-angle);
	yRotationMatrix.matrixEntries[2][2] = std::cosf(-angle);

	return yRotationMatrix;
}

matrix4 matrix4::rotate_z(float angle)
{
	matrix4 zRotationMatrix;

	zRotationMatrix.matrixEntries[0][0] = std::cosf(-angle);
	zRotationMatrix.matrixEntries[1][0] = -std::sinf(-angle);
	zRotationMatrix.matrixEntries[0][2] = std::sinf(-angle);
	zRotationMatrix.matrixEntries[1][1] = std::cosf(-angle);

	return zRotationMatrix;
}

matrix4 matrix4::get_translate_matrix(vector4 vector)
{
	matrix4 translated;

	translated.matrixEntries[0][3] = vector.x;
	translated.matrixEntries[1][3] = vector.y;
	translated.matrixEntries[2][3] = vector.z;


	return translated;
}


matrix4 matrix4::operator+(matrix4 rhs) {
	matrix4 result;
	for (int i = 0; i<4; i++) {
		for (int j = 0; j < 4; j++) {
			result.matrixEntries[i][j] = get_entry(i, j) + rhs.get_entry(i, j);
		}
	}
	return result;
}

matrix4 matrix4::operator-(matrix4 rhs) {
	matrix4 result;
	for (int i = 0; i<4; i++) {
		for (int j = 0; j < 4; j++) {
			result.matrixEntries[i][j] = get_entry(i, j) - rhs.get_entry(i, j);
		}
	}
	return result;
}

matrix4 matrix4::operator*(matrix4 rhs) {
	matrix4 result;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				result.matrixEntries[i][j] += matrixEntries[i][j] * rhs.matrixEntries[i][j];
			}
		}
	}
	return result;
}

void matrix4::get_cofactor(int temp[4][4], int p, int q, int n)
{
	int i = 0, j = 0;
	for (int row = 0; row < n; row++)
	{
		for (int col = 0; col < n; col++)
		{
			if (row != p && col != q)
			{
				temp[i][j++] = matrixEntries[row][col];
				if (j == n - 1)
				{
					j = 0;
					i++;
				}
			}
		}
	}
}

int matrix4::get_determinant(int a[4][4], int n)
{
	int D = 0; 
	if (n == 1)
		return a[0][0];

	int temp[4][4];

	int sign = 1;  
	for (int f = 0; f < n; f++)
	{
		get_cofactor(temp, 0, f, n);
		D += sign * a[0][f] * get_determinant(temp, n - 1);
		sign = -sign;
	}

	return D;
}

int matrix4::get_determinant(int n) {
	int D = 0;
	if (n == 1)
		return matrixEntries[0][0];

	int temp[4][4];

	int sign = 1;
	for (int f = 0; f < n; f++)
	{
		get_cofactor(temp, 0, f, n);
		D += sign * matrixEntries[0][f] * get_determinant(temp, n - 1);
		sign = -sign;
	}

	return D;
}

void matrix4::get_adjoint(int adj[4][4])
{
	int sign = 1, temp[4][4];

	for (int i = 0; i<4; i++)
	{
		for (int j = 0; j<4; j++)
		{
			get_cofactor(temp, i, j, 4);
			sign = ((i + j) % 2 == 0) ? 1 : -1;
			adj[j][i] = (sign)*(get_determinant(temp, 3));
		}
	}
}

bool matrix4::get_inverse(float inverse[4][4])
{
	int det = get_determinant(4);
	if (det == 0)
	{
		return false;
	}

	int adj[4][4];
	get_adjoint(adj);
	for (int i = 0; i<4; i++)
		for (int j = 0; j<4; j++)
			inverse[i][j] = adj[i][j] / float(det);

	return true;
}
