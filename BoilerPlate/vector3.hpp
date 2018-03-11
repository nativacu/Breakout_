#pragma once
#ifndef VECTOR3
#define VECTOR3

struct vector2;

struct vector3
{
	/*STATIC*/
	static vector3 Origin;

	/*MEMBERS*/
	float x;
	float y;
	float z;
	float length;

	/*CTOR*/
	vector3();
	vector3(float, float, float);
	vector3(float);
	vector3(const vector2&);

	/*PUBLIC FUNCTIONS*/
	float get_length()			const;
	float get_squared_length()	const;
	float normalize();

	/*OPERATORS*/
	vector3&			operator=	(const vector3&);
	vector3&			operator+=	(const vector3&);
	vector3&			operator-=	(const vector3&);
	vector3&			operator*=	(const vector3&);
	vector3&			operator/=	(const vector3&);
	vector3			operator+	(const vector3&)const;
	vector3			operator-	(const vector3&)const;
	vector3			operator*	(const vector3&)const;
	vector3			operator/	(const vector3&)const;
	bool				operator==	(const vector3&)const;
	bool				operator!=	(const vector3&)const;
	friend vector3	operator*	(float, const vector3&);
	friend vector3	operator*	(const vector3&, float);
};

#endif