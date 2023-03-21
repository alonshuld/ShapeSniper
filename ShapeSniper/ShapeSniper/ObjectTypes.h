#pragma once


#include "PhysWorld.h"
#include <glut.h>
#include <cmath>


class Rectangle : public Object
{
private:
	float width;
	float hieght;
	float depth;
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
	Rectangle(const vector3 Position, const vector3 Velocity, const vector3 Force, const float Mass, const vector3 Color, const float _width, const float _hieght, const float _depth);
	void draw();
};

class HalfSphere : public Object
{
private:
	float radius;
	/*
	* this function rotates the rectangle
	* Input: rotation rate
	* Output: none
	*/
	void rotator(const float rate);
public:
	HalfSphere(const vector3 Position, const vector3 const Velocity, const vector3 Force, const float Mass, const vector3 Color, const int _radius);
	void draw();
};
