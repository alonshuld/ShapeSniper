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
	: Object(pos, vel, force, mass, color), _width(width), _hieght(hieght), _depth(depth)
{
}

void Rectangle::draw()
{
	glPushMatrix();
	glTranslatef(_pos.getX(), _pos.getY(), _pos.getZ());

	rotator(2);
	drawPolygon();
	drawOutline(vector3(1, 1, 1)); //draws outline

	glPopMatrix();
}

void HalfSphere::rotator(const float rate)
{
	rotateHalfSphere.setX(rotateHalfSphere.getX() + rate);
	rotateHalfSphere.setY(rotateHalfSphere.getY() + rate);
	rotateHalfSphere.setZ(rotateHalfSphere.getZ() + rate);
	glRotatef(rotateHalfSphere.getX(), 1, 0, 0);
	glRotatef(rotateHalfSphere.getY(), 0, 1, 0);
	glRotatef(rotateHalfSphere.getZ(), 0, 0, 1);
}

HalfSphere::HalfSphere(const vector3 pos, const vector3 vel, const vector3 force, const float mass, const vector3 color, const int radius)
	: Object(pos, vel, force, mass, color), _radius(radius)
{
}

void HalfSphere::draw()
{
	float al, dzx, bt, dxy = PI / 30;
	
	glPushMatrix();
	glTranslatef(_pos.getX(), _pos.getY(), _pos.getZ());
	rotator(2);
	glColor3f(_color.getX(), _color.getY(), _color.getZ());
	glBegin(GL_POLYGON);


	//Half Sphere
	for (bt = 0; bt < PI / 2; bt += dxy)
	{
		dzx = PI / 30;
		for (al = 0; al < 2 * PI; al += dzx)
		{
			//first half of the sphere
			glVertex3f(_radius * cos(bt) * sin(al), _radius * sin(bt), _radius * cos(bt) * cos(al));
			glVertex3f(_radius * cos(bt) * sin(al + dzx), _radius * sin(bt), _radius * cos(bt) * cos(al + dzx));
			glVertex3f(_radius * cos(bt + dxy) * sin(al + dzx), _radius * sin(bt + dxy), _radius * cos(bt + dxy) * cos(al + dzx));
			glVertex3f(_radius * cos(bt + dxy) * sin(al), _radius * sin(bt + dxy), _radius * cos(bt + dxy) * cos(al));
		}
	}
	glEnd();
	glPopMatrix();
}
