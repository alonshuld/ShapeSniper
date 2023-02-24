#pragma once


#include <iostream>
#include <vector>
#include <random>


int counterMiss = 0;


class vector3
{
public:
	float x, y, z;
	vector3(float _x, float _y, float _z);
	vector3();
	float* getCord() const;
	vector3 operator +(const vector3& other);
	vector3 operator -(const vector3& other);
	vector3 operator *(float other);
	vector3 operator /(float other);
	void operator +=(const vector3& other);
};


/*
* This function generates a position and a velocity to make unique movment each time
* input: position vector and velocity vector
* output: none
*/
void generatePosVel(vector3& pos, vector3& vel);


class Object
{
public:
	vector3 Position; //x, y, z
	vector3 Velocity;
	vector3 Force;
	float Mass;
	vector3 Color;
	Object(vector3 _Position, vector3 _Velocity, vector3 _Force, float _Mass, vector3 _color);
	void virtual draw() = 0;
};


class PhysicalWorld
{
private:
	std::vector<Object*> m_objects;
	vector3 m_gravity = vector3(0, -10, 0);
public:
	void AddObject(Object* object);
	void RemoveObject(Object* object);
	void Step(const float dt);
	void drawWorld();
}; 