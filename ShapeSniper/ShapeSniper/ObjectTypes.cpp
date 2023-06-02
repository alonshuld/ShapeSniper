#include "ObjectTypes.h"

#define PI 3.14159265358979323846

GLfloat angle = 0.0f;

void Cube::rotator(const float rate)
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
	// Set light source properties
	GLfloat lightPos[] = { 1.0f, 1.0f, 1.0f, 0.0f };
	GLfloat lightAmbient[] = { 0.2f, 0.2f, 0.2f, 1.0f };
	GLfloat lightDiffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };
	GLfloat lightSpecular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	// Set material properties
	GLfloat matAmbient[] = { 0.2f, 0.2f, 0.2f, 1.0f };
	GLfloat matDiffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };
	GLfloat matSpecular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat matShininess[] = { 100.0f };

	glEnable(GL_DEPTH_TEST); // Enable depth testing
	glEnable(GL_LIGHTING); // Enable lighting
	glEnable(GL_LIGHT0); // Enable light source 0
	glEnable(GL_COLOR_MATERIAL); // Enable coloring of materials

	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
	glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmbient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpecular);

	glMaterialfv(GL_FRONT, GL_AMBIENT, matAmbient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, matDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, matSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, matShininess);

	glPushMatrix();

	glTranslatef(_pos.getX(), _pos.getY(), _pos.getZ());
	glColor3f(_color.getX(), _color.getY(), _color.getZ());

	rotator(1);

	glBegin(GL_POLYGON);
	glutSolidCube(_rib);

	glEnd();
	glDisable(GL_LIGHTING);
	glPopMatrix();
}

Sphere::Sphere(const vector3 pos, const vector3 vel, const vector3 force, const float mass, const vector3 color, const int radius)
	: Object(pos, vel, force, mass, color), _radius(radius) {}

void Sphere::draw()
{
	glPushMatrix();
	glTranslatef(_pos.getX(), _pos.getY(), _pos.getZ());
	glColor3f(_color.getX(), _color.getY(), _color.getZ());

	
	glEnable(GL_DEPTH_TEST); // Enable depth testing
	glEnable(GL_LIGHTING); // Enable lighting
	glEnable(GL_LIGHT0); // Enable light source 0
	glEnable(GL_COLOR_MATERIAL); // Enable coloring of materials

	// Set light source properties
	GLfloat lightPos[] = { 1.0f, 1.0f, 1.0f, 0.0f };
	GLfloat lightAmbient[] = { 0.2f, 0.2f, 0.2f, 1.0f };
	GLfloat lightDiffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };
	GLfloat lightSpecular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	// Set material properties
	GLfloat matAmbient[] = { 0.2f, 0.2f, 0.2f, 1.0f };
	GLfloat matDiffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };
	GLfloat matSpecular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat matShininess[] = { 100.0f };

	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
	glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmbient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpecular);

	glMaterialfv(GL_FRONT, GL_AMBIENT, matAmbient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, matDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, matSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, matShininess);
	


	glBegin(GL_POLYGON);
	glutSolidSphere(_radius, 50, 50);

	glEnd();
	glDisable(GL_LIGHTING);
	glPopMatrix();
}
