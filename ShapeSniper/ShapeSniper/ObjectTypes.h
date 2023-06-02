#pragma once


#include "Source.h"
#include <stdlib.h>
#include <glut.h>
#include <cmath>

// Set light source properties
const GLfloat lightPos[] = { 1.0f, 1.0f, 1.0f, 0.0f };
const GLfloat lightAmbient[] = { 0.2f, 0.2f, 0.2f, 1.0f };
const GLfloat lightDiffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat lightSpecular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
// Set material properties
const GLfloat matAmbient[] = { 0.2f, 0.2f, 0.2f, 1.0f };
const GLfloat matDiffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat matSpecular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat matShininess[] = { 100.0f };

/*
* this function rotates the cube
* Input: rotation rate
* Output: none
*/
void rotator(const float rate);

class Cube : public Object
{
private:
	float _rib;
public:
	/*
	This function draws the cube
	Input: none
	output: none
	*/
	Cube(const vector3 pos, const vector3 vel, const vector3 force, const float mass, const vector3 color, const float _rib);
	/*
	This function draws the Cube
	Input: none
	Output: none
	*/
	void draw();
};

class Sphere : public Object
{
private:
	float _radius;
public:
	/*
	This function initializes sphere
	Input: all the variebles for object sphere
	Output: none
	*/
	Sphere(const vector3 pos, const vector3 vel, const vector3 force, const float mass, const vector3 color, const int radius);
	/*
	This function draws the sphere
	Input: none
	Output: none
	*/
	void draw();
};

class Torus : public Object
{
private:
	float _radius;
public:
	/*
	This function initializes torus
	Input: all the variebles for object torus
	Output: none
	*/
	Torus(const vector3 pos, const vector3 vel, const vector3 force, const float mass, const vector3 color, const int radius);
	/*
	This function draws the sphere
	Input: none
	Output: none
	*/
	void draw();
};

class Cone : public Object
{
private:
	float _base;
	float _height;
public:
	/*
	This function initializes Cone
	Input: all the variebles for object Cone
	Output: none
	*/
	Cone(const vector3 pos, const vector3 vel, const vector3 force, const float mass, const vector3 color, const int base, const int height);
	/*
	This function draws the Cone
	Input: none
	Output: none
	*/
	void draw();
};
