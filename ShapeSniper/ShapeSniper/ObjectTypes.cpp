#include "ObjectTypes.h"

#define PI 3.14159265358979323846

vector3 rotateRec = vector3(0, 0, 0);
vector3 rotateHalfSphere = vector3(0, 0, 0);

void Rectangle::drawOutline(const vector3 color) const
{
	glColor3f(color.getX(), color.getY(), color.getZ());

	glBegin(GL_LINE_LOOP); //close rec
	glVertex3f(+_width / 2, +_hieght / 2, +_depth / 2); //top right closer corner
	glVertex3f(-_width / 2, +_hieght / 2, +_depth / 2); //top left closer corner
	glVertex3f(-_width / 2, -_hieght / 2, +_depth / 2); //bottom left closer corner
	glVertex3f(+_width / 2, -_hieght / 2, +_depth / 2); //bottom right closer corner
	glEnd();

	glBegin(GL_LINE_LOOP); //outer rec
	glVertex3f(+_width / 2, -_hieght / 2, -_depth / 2); //bottom right outer corner
	glVertex3f(+_width / 2, +_hieght / 2, -_depth / 2); //top right outer corner
	glVertex3f(-_width / 2, +_hieght / 2, -_depth / 2); //top left outer corner
	glVertex3f(-_width / 2, -_hieght / 2, -_depth / 2); //bottom left outer corner
	glEnd();

	glBegin(GL_LINE_LOOP); //top rec
	glVertex3f(+_width / 2, +_hieght / 2, +_depth / 2);
	glVertex3f(+_width / 2, +_hieght / 2, -_depth / 2);
	glVertex3f(-_width / 2, +_hieght / 2, -_depth / 2);
	glVertex3f(-_width / 2, +_hieght / 2, +_depth / 2);
	glEnd();

	glBegin(GL_LINE_LOOP); //bottom rec
	glVertex3f(+_width / 2, -_hieght / 2, +_depth / 2);
	glVertex3f(+_width / 2, -_hieght / 2, -_depth / 2);
	glVertex3f(-_width / 2, -_hieght / 2, -_depth / 2);
	glVertex3f(-_width / 2, -_hieght / 2, +_depth / 2);
	glEnd();

	glBegin(GL_LINE_LOOP); //left rec
	glVertex3f(-_width / 2, +_hieght / 2, +_depth / 2);
	glVertex3f(-_width / 2, +_hieght / 2, -_depth / 2);
	glVertex3f(-_width / 2, -_hieght / 2, -_depth / 2);
	glVertex3f(-_width / 2, -_hieght / 2, +_depth / 2);
	glEnd();

	glBegin(GL_LINE_LOOP); //right rec
	glVertex3f(+_width / 2, +_hieght / 2, +_depth / 2);
	glVertex3f(+_width / 2, +_hieght / 2, -_depth / 2);
	glVertex3f(+_width / 2, -_hieght / 2, -_depth / 2);
	glVertex3f(+_width / 2, -_hieght / 2, +_depth / 2);
	glEnd();
}

void Rectangle::drawPolygon() const
{
	glColor3f(_color.getX(), _color.getY(), _color.getZ());
	glBegin(GL_POLYGON); //close rec
	glVertex3f(+_width / 2, +_hieght / 2, +_depth / 2); //top right closer corner
	glVertex3f(-_width / 2, +_hieght / 2, +_depth / 2); //top left closer corner
	glVertex3f(-_width / 2, -_hieght / 2, +_depth / 2); //bottom left closer corner
	glVertex3f(+_width / 2, -_hieght / 2, +_depth / 2); //bottom right closer corner
	glEnd();

	glBegin(GL_POLYGON); //outer rec
	glVertex3f(+_width / 2, -_hieght / 2, -_depth / 2); //bottom right outer corner
	glVertex3f(+_width / 2, +_hieght / 2, -_depth / 2); //top right outer corner
	glVertex3f(-_width / 2, +_hieght / 2, -_depth / 2); //top left outer corner
	glVertex3f(-_width / 2, -_hieght / 2, -_depth / 2); //bottom left outer corner
	glEnd();

	glBegin(GL_POLYGON); //top rec
	glVertex3f(+_width / 2, +_hieght / 2, +_depth / 2);
	glVertex3f(+_width / 2, +_hieght / 2, -_depth / 2);
	glVertex3f(-_width / 2, +_hieght / 2, -_depth / 2);
	glVertex3f(-_width / 2, +_hieght / 2, +_depth / 2);
	glEnd();

	glBegin(GL_POLYGON); //bottom rec
	glVertex3f(+_width / 2, -_hieght / 2, +_depth / 2);
	glVertex3f(+_width / 2, -_hieght / 2, -_depth / 2);
	glVertex3f(-_width / 2, -_hieght / 2, -_depth / 2);
	glVertex3f(-_width / 2, -_hieght / 2, +_depth / 2);
	glEnd();

	glBegin(GL_POLYGON); //left rec
	glVertex3f(-_width / 2, +_hieght / 2, +_depth / 2);
	glVertex3f(-_width / 2, +_hieght / 2, -_depth / 2);
	glVertex3f(-_width / 2, -_hieght / 2, -_depth / 2);
	glVertex3f(-_width / 2, -_hieght / 2, +_depth / 2);
	glEnd();

	glBegin(GL_POLYGON); //right rec
	glVertex3f(+_width / 2, +_hieght / 2, +_depth / 2);
	glVertex3f(+_width / 2, +_hieght / 2, -_depth / 2);
	glVertex3f(+_width / 2, -_hieght / 2, -_depth / 2);
	glVertex3f(+_width / 2, -_hieght / 2, +_depth / 2);
	glEnd();
}

void Rectangle::rotator(const float rate)
{
	rotateRec.setX(rotateRec.getX() + rate);
	rotateRec.setY(rotateRec.getY() + rate);
	rotateRec.setZ(rotateRec.getZ() + rate);
	glRotatef(rotateRec.getX(), 1, 0, 0);
	glRotatef(rotateRec.getY(), 0, 1, 0);
	glRotatef(rotateRec.getZ(), 0, 0, 1);
}

Rectangle::Rectangle(const vector3 pos, const vector3 vel, const vector3 force, const float mass, const vector3 color, const float width, const float hieght, const float depth)
	: Object(pos, vel, force, mass, color), _width(width), _hieght(hieght), _depth(depth) {}

void Rectangle::draw()
{
	glPushMatrix();
	glTranslatef(_pos.getX(), _pos.getY(), _pos.getZ());

	rotator(2);
	drawPolygon();
	drawOutline(vector3(1, 1, 1)); //draws outline

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
