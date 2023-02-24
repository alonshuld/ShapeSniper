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
