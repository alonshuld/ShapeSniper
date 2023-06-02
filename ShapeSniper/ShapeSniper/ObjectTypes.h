#pragma once


#include "Source.h"
#include <stdlib.h>
#include <glut.h>
#include <cmath>


class Cube : public Object
{
private:
	float _rib;
	/*
	* this function rotates the rectangle
	* Input: rotation rate
	* Output: none
	*/
	void rotator(const float rate);
public:
	/*
	This function draws the rectangle
	Input: none
	output: none
	*/
	Cube(const vector3 pos, const vector3 vel, const vector3 force, const float mass, const vector3 color, const float _rib);
	void draw();
};

class Sphere : public Object
{
private:
	float _radius;
public:
	/*
	This function initializes half sphere
	Input: all the variebles for object and sphere
	Output: none
	*/
	Sphere(const vector3 pos, const vector3 vel, const vector3 force, const float mass, const vector3 color, const int radius);
	/*
	This function draws the half sphere
	Input: none
	Output: none
	*/
	void draw();
};
