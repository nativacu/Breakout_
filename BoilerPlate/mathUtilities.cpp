#include "mathUtilities.hpp"


mathUtilities::mathUtilities()
{
}

//Returns the value of x rounded downward
int mathUtilities::get_nearest_int(float x)
{
	return static_cast<int> (floorf(x));
}

//Gets the value of x rounded downward and returns (whatever it returns)
int mathUtilities::get_nearest_even_int(float x)
{
	int roundedX = static_cast<int> (floorf(x));

	if (roundedX % 2 != 0)
		return ++roundedX;
	else
		return roundedX;
}

//Determines if an number is a power of two
bool mathUtilities::is_power_of_two(int x)
{
	while ((x % 2 == 0) && x > 1)
		x /= 2;
	return (x == 1);
}
