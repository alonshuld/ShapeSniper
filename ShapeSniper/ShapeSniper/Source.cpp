#include "Source.h"

vector3::vector3(const float x, const float y, const float z)
	: _x(x), _y(y), _z(z) {}

vector3::vector3()
	: _x(0), _y(0), _z(0) {}

vector3 vector3::operator+(const vector3& other) const
{
	return vector3(_x + other._x, _y + other._y, _z + other._z);
}

vector3 vector3::operator-(const vector3& other) const
{
	return vector3(_x - other._x, _y - other._y, _z - other._z);
}

vector3 vector3::operator*(const float scalar) const
{
	return vector3(_x * scalar, _y * scalar, _z * scalar);
}

vector3 vector3::operator/(const float scalar) const
{
	return vector3(_x / scalar, _y / scalar, _z / scalar);
}

bool vector3::operator==(const vector3& other) const
{
	return (_x == other._x && _y == other._y && _z == other._z);
}

bool vector3::operator!=(const vector3& other) const
{
	return (_x != other._x || _y != other._y || _z != other._z);
}

Object::Object(const vector3 pos, const vector3 vel, const vector3 force, const float mass, const vector3 color)
	: _pos(pos), _vel(vel), _force(force), _mass(mass), _color(color), _shot(false) {}