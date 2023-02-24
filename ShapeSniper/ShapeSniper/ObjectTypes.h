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
	void drawOutline(vector3 color);
	/*
	* This function draws the polygon
	* Input: vector3 in: r, g, b format
	* Output: none
	*/
	void drawPolygon();
	/*
	* this function rotates the rectangle
	* Input: rotation rate
	* Output: none
	*/
	void rotator(float rate);
public:
	Rectangle(vector3 Position, vector3 Velocity, vector3 Force, float Mass, vector3 Color, float _width, float _hieght, float _depth);
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
	void rotator(float rate);
public:
	HalfSphere(vector3 Position, vector3 Velocity, vector3 Force, float Mass, vector3 Color, int _radius);
	void draw();
};
