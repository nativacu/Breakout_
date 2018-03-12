#pragma once
#pragma once
#ifndef VECTOR2
#define VECTOR2

struct vector2
{
	/*STATIC*/
	static vector2 Origin;

	/*MEMBERS*/
	float x;
	float y;
	float length;

	/*CTOR*/
	vector2();
	vector2(float, float);
	vector2(float);

	/*PUBLIC FUNCTIONS*/
	float get_length() const;
	float get_squared_length() const;
	float normalize();

	/*OPERATORS*/
	vector2&			operator =	(const vector2&);
	vector2&			operator += (const vector2&);
	vector2&			operator -= (const vector2&);
	vector2&			operator *= (const vector2&);
	vector2&			operator/=	(const vector2&);
	vector2			operator+	(const vector2&)const;
	vector2			operator-	(const vector2&)const;
	vector2			operator*	(const vector2&)const;
	vector2			operator/	(const vector2&)const;
	bool				operator==	(const vector2&)const;
	bool				operator!=	(const vector2&)const;
	friend vector2	operator*	(float, const vector2&);
	friend vector2	operator*	(const vector2&, float);
};

#endif
