#pragma once


class vector3
{
protected:
	float _x, _y, _z;
public:
	vector3(const float x, const float y, const float z);
	vector3();
	void setX(const float x);
	void setY(const float y);
	void setZ(const float z);
	float getX() const;
	float getY() const;
	float getZ() const;
	vector3 operator +(const vector3& other) const;
	vector3 operator -(const vector3& other) const;
	vector3 operator *(const float scalar) const;
	vector3 operator /(const float scalar) const;
	void operator +=(const vector3& other);
	bool operator ==(const vector3& other) const;
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
