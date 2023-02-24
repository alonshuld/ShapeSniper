#include "ObjectTypes.h"

#define PI 3.14159265358979323846

vector3 rotateRec = vector3(0, 0, 0);
vector3 rotateHalfSphere = vector3(0, 0, 0);

void Rectangle::drawOutline(vector3 color)
{
	glColor3f(color.x, color.y, color.z);

	glBegin(GL_LINE_LOOP); //close rec
	glVertex3f(+width / 2, +hieght / 2, +depth / 2); //top right closer corner
	glVertex3f(-width / 2, +hieght / 2, +depth / 2); //top left closer corner
	glVertex3f(-width / 2, -hieght / 2, +depth / 2); //bottom left closer corner
	glVertex3f(+width / 2, -hieght / 2, +depth / 2); //bottom right closer corner
	glEnd();

	glBegin(GL_LINE_LOOP); //outer rec
	glVertex3f(+width / 2, -hieght / 2, -depth / 2); //bottom right outer corner
	glVertex3f(+width / 2, +hieght / 2, -depth / 2); //top right outer corner
	glVertex3f(-width / 2, +hieght / 2, -depth / 2); //top left outer corner
	glVertex3f(-width / 2, -hieght / 2, -depth / 2); //bottom left outer corner
	glEnd();

	glBegin(GL_LINE_LOOP); //top rec
	glVertex3f(+width / 2, +hieght / 2, +depth / 2);
	glVertex3f(+width / 2, +hieght / 2, -depth / 2);
	glVertex3f(-width / 2, +hieght / 2, -depth / 2);
	glVertex3f(-width / 2, +hieght / 2, +depth / 2);
	glEnd();

	glBegin(GL_LINE_LOOP); //bottom rec
	glVertex3f(+width / 2, -hieght / 2, +depth / 2);
	glVertex3f(+width / 2, -hieght / 2, -depth / 2);
	glVertex3f(-width / 2, -hieght / 2, -depth / 2);
	glVertex3f(-width / 2, -hieght / 2, +depth / 2);
	glEnd();

	glBegin(GL_LINE_LOOP); //left rec
	glVertex3f(-width / 2, +hieght / 2, +depth / 2);
	glVertex3f(-width / 2, +hieght / 2, -depth / 2);
	glVertex3f(-width / 2, -hieght / 2, -depth / 2);
	glVertex3f(-width / 2, -hieght / 2, +depth / 2);
	glEnd();

	glBegin(GL_LINE_LOOP); //right rec
	glVertex3f(+width / 2, +hieght / 2, +depth / 2);
	glVertex3f(+width / 2, +hieght / 2, -depth / 2);
	glVertex3f(+width / 2, -hieght / 2, -depth / 2);
	glVertex3f(+width / 2, -hieght / 2, +depth / 2);
	glEnd();
}

void Rectangle::drawPolygon()
{
	glColor3f(Color.x, Color.y, Color.z);
	glBegin(GL_POLYGON); //close rec
	glVertex3f(+width / 2, +hieght / 2, +depth / 2); //top right closer corner
	glVertex3f(-width / 2, +hieght / 2, +depth / 2); //top left closer corner
	glVertex3f(-width / 2, -hieght / 2, +depth / 2); //bottom left closer corner
	glVertex3f(+width / 2, -hieght / 2, +depth / 2); //bottom right closer corner
	glEnd();

	glBegin(GL_POLYGON); //outer rec
	glVertex3f(+width / 2, -hieght / 2, -depth / 2); //bottom right outer corner
	glVertex3f(+width / 2, +hieght / 2, -depth / 2); //top right outer corner
	glVertex3f(-width / 2, +hieght / 2, -depth / 2); //top left outer corner
	glVertex3f(-width / 2, -hieght / 2, -depth / 2); //bottom left outer corner
	glEnd();

	glBegin(GL_POLYGON); //top rec
	glVertex3f(+width / 2, +hieght / 2, +depth / 2);
	glVertex3f(+width / 2, +hieght / 2, -depth / 2);
	glVertex3f(-width / 2, +hieght / 2, -depth / 2);
	glVertex3f(-width / 2, +hieght / 2, +depth / 2);
	glEnd();

	glBegin(GL_POLYGON); //bottom rec
	glVertex3f(+width / 2, -hieght / 2, +depth / 2);
	glVertex3f(+width / 2, -hieght / 2, -depth / 2);
	glVertex3f(-width / 2, -hieght / 2, -depth / 2);
	glVertex3f(-width / 2, -hieght / 2, +depth / 2);
	glEnd();

	glBegin(GL_POLYGON); //left rec
	glVertex3f(-width / 2, +hieght / 2, +depth / 2);
	glVertex3f(-width / 2, +hieght / 2, -depth / 2);
	glVertex3f(-width / 2, -hieght / 2, -depth / 2);
	glVertex3f(-width / 2, -hieght / 2, +depth / 2);
	glEnd();

	glBegin(GL_POLYGON); //right rec
	glVertex3f(+width / 2, +hieght / 2, +depth / 2);
	glVertex3f(+width / 2, +hieght / 2, -depth / 2);
	glVertex3f(+width / 2, -hieght / 2, -depth / 2);
	glVertex3f(+width / 2, -hieght / 2, +depth / 2);
	glEnd();
}

void Rectangle::rotator(float rate)
{
	rotateRec.x += rate;
	rotateRec.y += rate;
	rotateRec.z += rate;
	glRotatef(rotateRec.x, 1, 0, 0);
	glRotatef(rotateRec.y, 0, 1, 0);
	glRotatef(rotateRec.z, 0, 0, 1);
}

Rectangle::Rectangle(vector3 Position, vector3 Velocity, vector3 Force, float Mass, vector3 Color, float _width, float _hieght, float _depth)
	: Object(Position, Velocity, Force, Mass, Color), width(_width), hieght(_hieght), depth(_depth)
{
}

void Rectangle::draw()
{
	glPushMatrix();
	glTranslatef(this->Position.x, this->Position.y, this->Position.z);

	rotator(2);
	drawPolygon();
	drawOutline(vector3(1, 1, 1));//draws outline

	glPopMatrix();
}
