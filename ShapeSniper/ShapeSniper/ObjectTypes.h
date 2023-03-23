#pragma once


#include "Source.h"
#include <stdlib.h>
#include <glut.h>
#include <cmath>


class Rectangle : public Object
{
private:
	float _width;
	float _hieght;
	float _depth;
	/*
	* This function draws outline to the rectangle
	* Input: vector3 in: r, g, b format
	* Output: none
	*/
	void drawOutline(const vector3 color) const;
	/*
	* This function draws the polygon
	* Input: vector3 in: r, g, b format
	* Output: none
	*/
	void drawPolygon() const;
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
	Rectangle(const vector3 pos, const vector3 vel, const vector3 force, const float mass, const vector3 color, const float width, const float hieght, const float depth);
	void draw();
};

class HalfSphere : public Object
{
private:
	float _radius;
	/*
	This function rotates the rectangle
	Input: rotation rate
	Output: none
	*/
	void rotator(const float rate);
public:
	/*
	This function initializes half sphere
	Input: all the variebles for object and sphere
	Output: none
	*/
	HalfSphere(const vector3 pos, const vector3 const vel, const vector3 force, const float mass, const vector3 color, const int radius);
	/*
	This function draws the half sphere
	Input: none
	Output: none
	*/
	void draw();
};
