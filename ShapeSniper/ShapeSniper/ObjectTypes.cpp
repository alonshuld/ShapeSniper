#include "ObjectTypes.h"

void Rectangle::drawOutline(vector3 color)
{
}

void Rectangle::drawPolygon()
{
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

void HalfSphere::rotator(float rate)
{
	rotateHalfSphere.x += rate;
	rotateHalfSphere.y += rate;
	rotateHalfSphere.z += rate;
	glRotatef(rotateHalfSphere.x, 1, 0, 0);
	glRotatef(rotateHalfSphere.y, 0, 1, 0);
	glRotatef(rotateHalfSphere.z, 0, 0, 1);
}

HalfSphere::HalfSphere(vector3 Position, vector3 Velocity, vector3 Force, float Mass, vector3 Color, int _radius)
	: Object(Position, Velocity, Force, Mass, Color), radius(_radius)
{
}

void HalfSphere::draw()
{
	glPushMatrix();
	glTranslatef(this->Position.x, this->Position.y, this->Position.z);

	float al, dzx, bt, dxy = PI / 30;

	rotator(2);

	//Sphere
	for (bt = 0; bt < PI / 2; bt += dxy)
	{
		dzx = PI / 30;
		for (al = 0; al < 2 * PI; al += dzx)
		{
			//first half of the sphere
			glBegin(GL_POLYGON);
			glColor3f(this->Color.x, this->Color.y, this->Color.z);
			glVertex3f(this->radius * cos(bt) * sin(al), this->radius * sin(bt), this->radius * cos(bt) * cos(al));
			glVertex3f(this->radius * cos(bt) * sin(al + dzx), this->radius * sin(bt), this->radius * cos(bt) * cos(al + dzx));
			glVertex3f(this->radius * cos(bt + dxy) * sin(al + dzx), this->radius * sin(bt + dxy), this->radius * cos(bt + dxy) * cos(al + dzx));
			glVertex3f(this->radius * cos(bt + dxy) * sin(al), this->radius * sin(bt + dxy), this->radius * cos(bt + dxy) * cos(al));
		}
	}
	glEnd();
	glPopMatrix();
}
