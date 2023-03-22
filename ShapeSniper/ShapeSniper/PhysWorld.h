#pragma once


#include <iostream>
#include <vector>
#include <random>


#define BLUE vector3(0, 0.3, 0.7)
#define RED vector3(0.5, 0, 0)
#define AMOUNT_OF_MISSES 4


class vector3
{
public:
	float x, y, z;
	vector3(const float _x, const float _y, const float _z);
	vector3();
	/*
	* This function returns the cords
	* Input: none
	* Output: list of cords
	*/
	float* getCord() const;
	vector3 operator +(const vector3& other) const;
	vector3 operator -(const vector3& other) const;
	vector3 operator *(const float other) const;
	vector3 operator /(const float other) const;
	void operator +=(const vector3& other);
	bool operator ==(const vector3& other) const;
};


/*
This function generates a position and a velocity to make unique movment each time
input: position vector and velocity vector
output: none
*/
void generatePosVel(vector3* pos, vector3* vel);


class Object
{
public:
	vector3 Position;	//x, y, z
	vector3 Velocity;	//x, y, z
	vector3 Force;		//x, y, z
	float Mass;
	vector3 Color;		//r, g, b
	bool Shot;
	Object(const vector3 _Position, const vector3 _Velocity, const vector3 _Force, const float _Mass, const vector3 _color);
	void virtual draw() = 0;
};


class PhysicalWorld
{
private:
	std::vector<Object*> m_objects;
	vector3 m_gravity = vector3(0, -10, 0);
	int counterMiss = 0;
	int counterShot = 0;
	int counterMax = 0;
public:
	/*
	* This function adds an object to the vector of the world
	* Input: object pointer
	* Output: none
	*/
	void AddObject(Object* object);
	/*
	* This function returns how many objects the user missed
	* Input: none
	* Output: counter of how many objects missed
	*/
	int getMiss() const;
	/*
	* This function returns how many objects the user shot
	* Input: none
	* Output: counter of how many objects shot
	*/
	int getShot() const;
	/*
	* This function returns the highest score game yet
	* Input: none
	* Output: amount of objects got shot in the best match
	*/
	int getMax() const;
	/*
	* This function removes an object from the list
	* Input: pointer to an object that we want to remove
	* Output: none
	*/
	void RecycleObject(Object* object);
	/*
	* This function changes each variable to show what represent what happend in dt milliseconds
	* Input: milliseconds
	* Output: none
	*/
	void Step(const float dt);
	/*
	* This function draws all the objects
	* Input: none
	* Output: none
	*/
	void drawWorld() const;
	/*
	* This function returns the object vector
	* Input: none
	* Output: a vector of object pointer
	*/
	std::vector<Object*> getObjects() const;
	/*
	* This function clears the object vector
	* Input: none
	* Output: none
	*/
	void clearObjects();
}; 