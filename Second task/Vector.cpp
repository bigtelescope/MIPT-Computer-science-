#include "Vector.h"

Vector::Vector(float x1, float y1):
	x 	(x1),
	y 	(y1)
{}

float Vector::Len() const
{
	return sqrt(x * x + y * y);
}

float Vector::SquareLen() const
{
	return (x * x + y * y);
}

const float Vector::getX() const
{
	return this->x;
}

const float Vector::getY() const
{
	return this->y;
}

float & Vector::getRX()
{
	return this->x;
}

float & Vector::getRY()
{
	return this->y;
}

float Vector::operator*(const Vector & other) const
{
	return x * other.x + y * other.y;
}

float Vector::operator^(const Vector & other) const
{
	return fabs(x * other.y - y * other.x);
}

Vector Vector::operator+(const Vector & other) const
{
	return Vector(x + other.x, y + other.y);
}

Vector Vector::operator-(const Vector & other) const
{
	return Vector(x - other.x, y - other.y);
}

Vector Vector::operator-() const
{
	return Vector(-x, -y);
}

Vector & Vector::operator+=(const Vector & other)
{
	x += other.x;
	y += other.y;
	return *this;
}

Vector & Vector::operator-=(const Vector & other)
{
	x -= other.x;
	y -= other.y;
	return *this;
}

Vector Vector::norm() const
{
	return Vector(x / Len(), y / Len());
}

Vector Vector::ortohonal() const
{
	return Vector(y, -x);
}

Vector & Vector::rotate(float angle)
{
	x = x * cos(angle) - y * sin(angle);
	y = x * sin(angle) + y * cos(angle);
	return *this;
}

Vector Vector::getRotated(float angle) const
{
	return Vector(x * cos(angle) - y * sin(angle), x * sin(angle) + y * cos(angle));
}

Vector operator*(const Vector & v, float k)
{
	return Vector((v.getX()) * k, (v.getY()) * k);
}

Vector operator*(float k, const Vector & v)
{
	return Vector((v.getX()) * k, (v.getY()) * k);
}

Vector operator/(const Vector & v, float k)
{
	return Vector((v.getX()) / k, (v.getY()) / k);
}

std::ostream & operator<<(std::ostream& stream, const Vector & v)
{
	return stream << "(" << v.getX() << ", " << v.getY() << ")" ;
}

std::istream & operator>>(std::istream& stream, Vector & v)
{
	return stream >> v.getRX() >> v.getRY();
}

