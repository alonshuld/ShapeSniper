#pragma once


class vector3
{
public:
	float _x, _y, _z;
	vector3(const float x, const float y, const float z);
	vector3();
	vector3 operator +(const vector3& other) const;
	vector3 operator -(const vector3& other) const;
	vector3 operator *(const float scalar) const;
	vector3 operator /(const float scalar) const;
	bool operator ==(const vector3& other) const;
	bool operator !=(const vector3& other) const;
};


class Object
{
public:
	vector3 _pos;		//x, y, z
	vector3 _vel;		//x, y, z
	vector3 _force;		//x, y, z
	float _mass;
	vector3 _color;		//r, g, b
	bool _shot;
	Object(const vector3 pos, const vector3 vel, const vector3 force, const float mass, const vector3 color);
	void virtual draw() = 0;
};
