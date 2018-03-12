#include <cmath>

#include "vector2.hpp"

vector2 vector2::Origin = vector2();

/*Default constructor*/
vector2::vector2()
{
	x = 0.0f;
	y = 0.0f;
	length = 0.0f;
}

/*Parameterized constructor. Sets the x and y values to the specified ones*/
vector2::vector2(float xValue, float yValue)
{
	x = xValue;
	y = yValue;
	length = get_length();
}

/*Parameterized constructor. Sets the x and y values to the same specified value*/
vector2::vector2(float value)
{
	x = value;
	y = value;
	length = get_length();
}

/*Returns vector's length*/
float vector2::get_length() const
{
	return sqrt(x * x + y * y);
}

/*Returns length raised to the power of 2*/
float vector2::get_squared_length() const
{
	return (x * x + y * y);
}

/*Divides x and y values by vector's length*/
float vector2::normalize()
{
	float inverseScale = 1.0f / length;
	x *= inverseScale;
	y *= inverseScale;

	//Calculate new length
	length = get_length();

	return length;
}

vector2& vector2::operator=(const vector2& aVector2)
{
	//Prevent self assignment
	if (this == &aVector2)
		return *this;

	x = aVector2.x;
	y = aVector2.y;

	//Calculate new length
	length = get_length();

	return *this;
}

vector2& vector2::operator+=(const vector2& aVector2)
{
	x = x + aVector2.x;
	y = y + aVector2.y;

	//Calculate new length
	length = get_length();

	return *this;
}

vector2& vector2::operator-=(const vector2& aVector2)
{
	x = x - aVector2.x;
	y = y - aVector2.y;

	//Calculate new length
	length = get_length();

	return *this;
}

vector2& vector2::operator*=(const vector2& aVector2)
{
	x = x * aVector2.x;
	y = y * aVector2.y;

	//Calculate new length
	length = get_length();

	return *this;
}

vector2& vector2::operator/=(const vector2& aVector2)
{
	if (aVector2.x == 0) throw "Can't divide by zero";
	if (aVector2.y == 0) throw "Can't divide by zero";

	x = x / aVector2.x;
	y = y / aVector2.y;

	//Calculate new length
	length = get_length();

	return *this;
}

/*Calculates resulting coordinates of the addition and returns them as a new vector*/
vector2 vector2::operator+(const vector2& aVector2) const
{
	float resultingXvalue = x + aVector2.x;
	float resultingYvalue = y + aVector2.y;

	return vector2(resultingXvalue, resultingYvalue);
}

/*Calculates resulting coordinates of the subtraction and returns them as a new vector*/
vector2 vector2::operator-(const vector2& aVector2) const
{
	float resultingXvalue = x - aVector2.x;
	float resultingYvalue = y - aVector2.y;

	return vector2(resultingXvalue, resultingYvalue);
}

/*Calculates resulting coordinates of the multiplication and returns them as a new vector*/
vector2 vector2::operator*(const vector2& aVector2) const
{
	float resultingXvalue = x * aVector2.x;
	float resultingYvalue = y * aVector2.y;

	return vector2(resultingXvalue, resultingYvalue);
}

/*Calculates resulting coordinates of the division and returns them as a new vector*/
vector2 vector2::operator/(const vector2& aVector2) const
{
	if (aVector2.x == 0) throw "Can't divide by zero";
	if (aVector2.y == 0) throw "Can't divide by zero";

	float resultingXvalue = x / aVector2.x;
	float resultingYvalue = y / aVector2.y;

	return vector2(resultingXvalue, resultingYvalue);
}

bool vector2::operator==(const vector2& aVector2)const
{
	return x == aVector2.x && y == aVector2.y;
}

bool vector2::operator!=(const vector2& aVector2)const
{
	return x != aVector2.x || y != aVector2.y;
}

/*Calculates resulting coordinates of the multiplication by a value and returns them as a new vector*/
vector2 operator*(float value, const vector2& aVector2)
{
	float resultingXvalue = value * aVector2.x;
	float resultingYvalue = value * aVector2.y;

	return vector2(resultingXvalue, resultingYvalue);
}

/*Calculates resulting coordinates of the multiplication by a value and returns them as a new vector*/
vector2 operator*(const vector2& aVector2, float value)
{
	float resultingXvalue = value * aVector2.x;
	float resultingYvalue = value * aVector2.y;

	return vector2(resultingXvalue, resultingYvalue);
}