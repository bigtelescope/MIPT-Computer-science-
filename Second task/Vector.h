#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <typeinfo>
#include <cmath>
#include <string>

class Vector
{
	private:

		float x, y;

	public:

		Vector 		(float x1, float y1);
		float 		Len() const;
		float 		SquareLen() const;
		const float getX() const;
		const float getY() const;
		float & 	getRX();
		float & 	getRY();

		float 		operator*(const Vector& other) const;
		float 		operator^(const Vector& other) const;
		Vector 		operator+(const Vector& other) const;
		Vector 		operator-(const Vector& other) const;
		Vector 		operator-() const;
		Vector&		operator+=(const Vector& other);
		Vector&		operator-=(const Vector& other);
		Vector 		norm() const;
		Vector 		ortohonal() const;
		Vector& 	rotate(float angle);
		Vector 		getRotated(float angle) const;



	friend  std::ostream & operator<<(std::ostream& stream, const Vector & v);
	friend  std::istream & operator>>(std::istream& stream, Vector & v);

	friend	Vector operator*(const Vector& v, float k);
	friend	Vector operator*(float k, const Vector& v);
	friend	Vector operator/(const Vector& v, float k);

};

#endif
