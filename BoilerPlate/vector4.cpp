#include <cmath>

#include "vector2.hpp"
#include "vector3.hpp"
#include "vector4.hpp"

/*Default constructor*/
vector4::vector4()
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
	w = 0.0f;
	length = 0.0f;
}

/*Parameterized constructor. Sets the x, y, z and values to the specified ones*/
vector4::vector4(float xValue, float yValue, float zValue, float wValue)
{
	x = xValue;
	y = yValue;
	z = zValue;
	w = wValue;
	length = get_length();
}

/*Parameterized constructor. Sets the x, y, z and w values to the same specified value*/
vector4::vector4(float value)
{
	x = value;
	y = value;
	z = value;
	w = value;
	length = get_length();
}

vector4::vector4(const vector2& vector2)
{
	x = vector2.x;
	y = vector2.y;
	z = 0.0f;
	w = 0.0f;
	length = get_length();
}

vector4::vector4(const vector3& vector3)
{
	x = vector3.x;
	y = vector3.y;
	z = vector3.z;
	w = 0.0f;
	length = get_length();
}

/*Returns vector's length*/
float vector4::get_length() const
{
	return sqrt(x * x + y * y + z * z + w * w);
}

/*Returns length raised to the power of 2*/
float vector4::get_squared_length() const
{
	return (x * x + y * y + z * z + w * w);
}

/*Divides x, y and z values by vector's length*/
float vector4::normalize()
{
	float inverseScale = 1.0f / length;
	x *= inverseScale;
	y *= inverseScale;
	z *= inverseScale;
	w *= inverseScale;

	//Calculate new length
	length = get_length();

	return length;
}

vector4& vector4::operator=(const vector4& aVector4)
{
	//Prevent self assignment
	if (this == &aVector4)
		return *this;

	x = aVector4.x;
	y = aVector4.y;
	z = aVector4.z;
	w = aVector4.w;

	//Calculate new length
	length = get_length();

	return *this;
}

vector4& vector4::operator+=(const vector4& aVector4)
{
	x = x + aVector4.x;
	y = y + aVector4.y;
	z = z + aVector4.z;
	w = w + aVector4.w;

	//Calculate new length
	length = get_length();

	return *this;
}

vector4& vector4::operator-=(const vector4& aVector4)
{
	x = x - aVector4.x;
	y = y - aVector4.y;
	z = z - aVector4.z;
	w = w - aVector4.w;

	//Calculate new length
	length = get_length();

	return *this;
}

vector4& vector4::operator*=(const vector4& aVector4)
{
	x = x * aVector4.x;
	y = y * aVector4.y;
	z = z * aVector4.z;
	w = w * aVector4.w;

	//Calculate new length
	length = get_length();

	return *this;
}

vector4& vector4::operator/=(const vector4& aVector4)
{
	if (aVector4.x == 0) throw "Can't divide by zero";
	if (aVector4.y == 0) throw "Can't divide by zero";
	if (aVector4.z == 0) throw "Can't divide by zero";
	if (aVector4.w == 0) throw "Can't divide by zero";

	x = x / aVector4.x;
	y = y / aVector4.y;
	z = z / aVector4.z;
	w = w / aVector4.w;

	//Calculate new length
	length = get_length();

	return *this;
}

/*Calculates resulting coordinates of the addition and returns them as a new vector*/
vector4 vector4::operator+(const vector4& aVector4) const
{
	float resultingXvalue = x + aVector4.x;
	float resultingYvalue = y + aVector4.y;
	float resultingZvalue = z + aVector4.z;
	float resultingWvalue = w + aVector4.w;

	return vector4(resultingXvalue, resultingYvalue, resultingZvalue, resultingWvalue);
}

/*Calculates resulting coordinates of the subtraction and returns them as a new vector*/
vector4 vector4::operator-(const vector4& aVector4) const
{
	float resultingXvalue = x - aVector4.x;
	float resultingYvalue = y - aVector4.y;
	float resultingZvalue = z - aVector4.z;
	float resultingWvalue = w - aVector4.w;

	return vector4(resultingXvalue, resultingYvalue, resultingZvalue, resultingWvalue);
}

/*Calculates resulting coordinates of the multiplication and returns them as a new vector*/
vector4 vector4::operator*(const vector4& aVector4) const
{
	float resultingXvalue = x * aVector4.x;
	float resultingYvalue = y * aVector4.y;
	float resultingZvalue = z * aVector4.z;
	float resultingWvalue = w * aVector4.w;

	return vector4(resultingXvalue, resultingYvalue, resultingZvalue, resultingWvalue);
}

/*Calculates resulting coordinates of the division and returns them as a new vector*/
vector4 vector4::operator/(const vector4& aVector4) const
{
	if (aVector4.x == 0) throw "Can't divide by zero";
	if (aVector4.y == 0) throw "Can't divide by zero";
	if (aVector4.z == 0) throw "Can't divide by zero";
	if (aVector4.w == 0) throw "Can't divide by zero";

	float resultingXvalue = x / aVector4.x;
	float resultingYvalue = y / aVector4.y;
	float resultingZvalue = z / aVector4.z;
	float resultingWvalue = w / aVector4.w;

	return vector4(resultingXvalue, resultingYvalue, resultingZvalue, resultingWvalue);
}

bool vector4::operator==(const vector4& aVector4)const
{
	return x == aVector4.x && y == aVector4.y && z == aVector4.z && w == aVector4.z;
}

bool vector4::operator!=(const vector4& aVector4)const
{
	return x != aVector4.x || y != aVector4.y || z != aVector4.z || w != aVector4.w;
}

/*Calculates resulting coordinates of the multiplication by a value and returns them as a new vector*/
vector4 operator*(float value, const vector4& aVector4)
{
	float resultingXvalue = value * aVector4.x;
	float resultingYvalue = value * aVector4.y;
	float resultingZvalue = value * aVector4.z;
	float resultingWvalue = value * aVector4.w;

	return vector4(resultingXvalue, resultingYvalue, resultingZvalue, resultingWvalue);
}

/*Calculates resulting coordinates of the multiplication by a value and returns them as a new vector*/
vector4 operator*(const vector4& aVector4, float value)
{
	float resultingXvalue = value * aVector4.x;
	float resultingYvalue = value * aVector4.y;
	float resultingZvalue = value * aVector4.z;
	float resultingWvalue = value * aVector4.w;

	return vector4(resultingXvalue, resultingYvalue, resultingZvalue, resultingWvalue);
}