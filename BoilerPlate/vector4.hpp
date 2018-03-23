#pragma once
#ifndef VECTOR4
#define VECTOR4

 namespace engine 
 {
	 namespace math 
	 {
		struct vector2;
		struct vector3;
		struct vector4
		{
			/*STATIC*/
			static vector4 Origin;

			/*MEMBERS*/
			float x;
			float y;
			float z;
			float w;
			float length;

			/*CTOR*/
			vector4();
			vector4(float, float, float, float);
			vector4(float);
			vector4(const vector2&);
			vector4(const vector3&);

			/*PUBLIC FUNCTIONS*/
			float get_length() const;
			float get_squared_length() const;
			float normalize();

			/*OPERATORS*/
			vector4&			operator=	(const vector4&);
			vector4&			operator+=	(const vector4&);
			vector4&			operator-=	(const vector4&);
			vector4&			operator*=	(const vector4&);
			vector4&			operator/=	(const vector4&);
			vector4			operator+	(const vector4&)const;
			vector4			operator-	(const vector4&)const;
			vector4			operator*	(const vector4&)const;
			vector4			operator/	(const vector4&)const;
			bool				operator==	(const vector4&)const;
			bool				operator!=	(const vector4&)const;
			friend vector4	operator*	(float, const vector4&);
			friend vector4	operator*	(const vector4&, float);
		};
	}
}
#endif
