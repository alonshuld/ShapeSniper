#include "ObjectTypes.h"

#define PI 3.14159265358979323846

GLfloat angle = 0.0f;

void rotator(const float rate)
{
	angle += 1.0f; // Increment the rotation angle
	if (angle > 360.0f)
		angle -= 360.0f;
	glRotatef(angle, 1, 1, 1);
}

Cube::Cube(const vector3 pos, const vector3 vel, const vector3 force, const float mass, const vector3 color, const float rib)
	: Object(pos, vel, force, mass, color), _rib(rib) {}

void Cube::draw()
{
	glPushMatrix();

	glTranslatef(_pos.getX(), _pos.getY(), _pos.getZ());
	glColor3f(_color.getX(), _color.getY(), _color.getZ());
	rotator(1);

	glBegin(GL_POLYGON);
	
	glutSolidCube(_rib);
	
	glEnd();
	
	glPopMatrix();
}

Sphere::Sphere(const vector3 pos, const vector3 vel, const vector3 force, const float mass, const vector3 color, const int radius)
	: Object(pos, vel, force, mass, color), _radius(radius) {}

void Sphere::draw()
{
	glPushMatrix();

	glTranslatef(_pos.getX(), _pos.getY(), _pos.getZ());
	glColor3f(_color.getX(), _color.getY(), _color.getZ());

	glBegin(GL_POLYGON);

	glutSolidSphere(_radius, 50, 50);

	glEnd();

	glPopMatrix();
}

Torus::Torus(const vector3 pos, const vector3 vel, const vector3 force, const float mass, const vector3 color, const int radius)
	: Object(pos, vel, force, mass, color), _radius(radius) {}

void Torus::draw()
{
	glPushMatrix();

	glTranslatef(_pos.getX(), _pos.getY(), _pos.getZ());
	glColor3f(_color.getX(), _color.getY(), _color.getZ());
	rotator(1);

	glBegin(GL_POLYGON);

	glutSolidTorus(_radius, _radius + 20, 50, 50);

	glEnd();

	glPopMatrix();
}

Cone::Cone(const vector3 pos, const vector3 vel, const vector3 force, const float mass, const vector3 color, const int base, const int height)
	: Object(pos, vel, force, mass, color), _base(base), _height(height) {}

void Cone::draw()
{
	glPushMatrix();
	 
	glTranslatef(_pos.getX(), _pos.getY(), _pos.getZ());
	glColor3f(_color.getX(), _color.getY(), _color.getZ());
	rotator(2);

	glBegin(GL_POLYGON);

	glutSolidCone(_base, _height, 50, 50);

	glEnd();

	glPopMatrix();
}
