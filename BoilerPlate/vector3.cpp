#include <cmath>

#include "vector2.hpp"
#include "vector3.hpp"

/*Default constructor*/
vector3::vector3()
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
	length = 0.0f;
}

/*Parameterized constructor. Sets the x, y and z values to the specified ones*/
vector3::vector3(float xValue, float yValue, float zValue)
{	
	x = xValue;
	y = yValue;
	z = zValue;
	length = get_length();
}

/*Parameterized constructor. Sets the x, y and z values to the same specified value*/
vector3::vector3(float value)
{
	x = value;
	y = value;
	z = value;
	length = get_length();
}

vector3::vector3(const vector2& vector2)
{
	x = vector2.x;
	y = vector2.y;
	z = 0.0f;
	length = get_length();
}

/*Returns vector's length*/
float vector3::get_length() const
{
	return sqrt(x * x + y * y + z * z);
}

/*Returns length raised to the power of 2*/
float vector3::get_squared_length() const
{
	return (x * x + y * y + z * z);
}

/*Divides x, y and z values by vector's length*/
float vector3::normalize()
{
	float inverseScale = 1.0f / length;
	x *= inverseScale;
	y *= inverseScale;
	z *= inverseScale;

	//Calculate new length
	length = get_length();

	return length;
}

vector3& vector3::operator=(const vector3& aVector3)
{
	//Prevent self assignment
	if (this == &aVector3)
		return *this;

	x = aVector3.x;
	y = aVector3.y;
	z = aVector3.z;

	//Calculate new length
	length = get_length();

	return *this;
}

vector3& vector3::operator+=(const vector3& aVector3)
{
	x = x + aVector3.x;
	y = y + aVector3.y;
	z = z + aVector3.z;

	//Calculate new length
	length = get_length();

	return *this;
}

vector3& vector3::operator-=(const vector3& aVector3)
{
	x = x - aVector3.x;
	y = y - aVector3.y;
	z = z - aVector3.z;

	//Calculate new length
	length = get_length();

	return *this;
}

vector3& vector3::operator*=(const vector3& aVector3)
{
	x = x * aVector3.x;
	y = y * aVector3.y;
	z = z * aVector3.z;

	//Calculate new length
	length = get_length();

	return *this;
}

vector3& vector3::operator/=(const vector3& aVector3)
{
	if (aVector3.x == 0) throw "Can't divide by zero";
	if (aVector3.y == 0) throw "Can't divide by zero";
	if (aVector3.z == 0) throw "Can't divide by zero";

	x = x / aVector3.x;
	y = y / aVector3.y;
	z = z / aVector3.z;

	//Calculate new length
	length = get_length();

	return *this;
}

/*Calculates resulting coordinates of the addition and returns them as a new vector*/
vector3 vector3::operator+(const vector3& aVector3) const
{
	float resultingXvalue = x + aVector3.x;
	float resultingYvalue = y + aVector3.y;
	float resultingZvalue = z + aVector3.z;

	return vector3(resultingXvalue, resultingYvalue, resultingZvalue);
}

/*Calculates resulting coordinates of the subtraction and returns them as a new vector*/
vector3 vector3::operator-(const vector3& aVector3) const
{
	float resultingXvalue = x - aVector3.x;
	float resultingYvalue = y - aVector3.y;
	float resultingZvalue = z - aVector3.z;

	return vector3(resultingXvalue, resultingYvalue, resultingZvalue);
}

/*Calculates resulting coordinates of the multiplication and returns them as a new vector*/
vector3 vector3::operator*(const vector3& aVector3) const
{
	float resultingXvalue = x * aVector3.x;
	float resultingYvalue = y * aVector3.y;
	float resultingZvalue = z * aVector3.z;

	return vector3(resultingXvalue, resultingYvalue, resultingZvalue);
}

/*Calculates resulting coordinates of the division and returns them as a new vector*/
vector3 vector3::operator/(const vector3& aVector3) const
{
	if (aVector3.x == 0) throw "Can't divide by zero";
	if (aVector3.y == 0) throw "Can't divide by zero";
	if (aVector3.z == 0) throw "Can't divide by zero";

	float resultingXvalue = x / aVector3.x;
	float resultingYvalue = y / aVector3.y;
	float resultingZvalue = z / aVector3.z;

	return vector3(resultingXvalue, resultingYvalue, resultingZvalue);
}

bool vector3::operator==(const vector3& aVector3)const
{
	return x == aVector3.x && y == aVector3.y && z == aVector3.z;
}

bool vector3::operator!=(const vector3& aVector3)const
{
	return x != aVector3.x || y != aVector3.y || z != aVector3.z;
}

/*Calculates resulting coordinates of the multiplication by a value and returns them as a new vector*/
vector3 operator*(float value, const vector3& aVector3)
{
	float resultingXvalue = value * aVector3.x;
	float resultingYvalue = value * aVector3.y;
	float resultingZvalue = value * aVector3.z;

	return vector3(resultingXvalue, resultingYvalue, resultingZvalue);
}

/*Calculates resulting coordinates of the multiplication by a value and returns them as a new vector*/
vector3 operator*(const vector3& aVector3, float value)
{
	float resultingXvalue = value * aVector3.x;
	float resultingYvalue = value * aVector3.y;
	float resultingZvalue = value * aVector3.z;

	return vector3(resultingXvalue, resultingYvalue, resultingZvalue);
}