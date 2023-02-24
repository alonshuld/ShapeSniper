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
