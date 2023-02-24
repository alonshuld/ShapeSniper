#include "PhysWorld.h"

vector3::vector3(float _x, float _y, float _z) : x(_x), y(_y), z(_z)
{
}

vector3::vector3() : x(0), y(0), z(0)
{
}

float* vector3::getCord() const
{
	float temp[3] = { x, y, z };
	return temp;
}

vector3 vector3::operator +(const vector3& other)
{
	return vector3(this->x + other.x, this->y + other.y, this->z + other.z);
}

vector3 vector3::operator -(const vector3& other)
{
	return vector3(this->x - other.x, this->y - other.y, this->z - other.z);
}

vector3 vector3::operator *(float other)
{
	return vector3(this->x * other, this->y * other, this->z * other);
}

vector3 vector3::operator /(float other)
{
	return vector3(this->x / other, this->y / other, this->z / other);
}

void vector3::operator +=(const vector3& other)
{
	this->x += other.x;
	this->y += other.y;
	this->z += other.z;
}

void generatePosVel(vector3& pos, vector3& vel)
{
	std::random_device rd;
	std::uniform_int_distribution<> distPos(-900, 900);
	std::uniform_int_distribution<> distVolY(150, 190);
	std::uniform_int_distribution<> distVolX(10, 100);
	pos.x = distPos(rd);
	while (pos.x > -200 && pos.x < 200)
		pos.x = distPos(rd);
	pos.y = -1000;
	pos.z = 0;

	vel.x = distVolX(rd);
	if (pos.x > 0)
		vel.x = -vel.x;
	vel.y = distVolY(rd);
	vel.z = 0;
}

Object::Object(vector3 _Position, vector3 _Velocity, vector3 _Force, float _Mass, vector3 _color) : Position(_Position), Velocity(_Velocity), Force(_Force), Mass(_Mass), Color(_color)
{
}

void PhysicalWorld::AddObject(Object* object)
{
	this->m_objects.push_back(object);
}

void PhysicalWorld::RemoveObject(Object* object)
{
	if (!object)
		return;
	auto it = std::find(this->m_objects.begin(), this->m_objects.end(), object);
	if (it == m_objects.end())
		return;

	//this->m_objects.erase(it); //removes the object completely

	//i will "recycle" him and give him new cords
	vector3 pos = vector3();
	vector3 vel = vector3();
	generatePosVel(pos, vel);
	object->Position = pos;
	object->Velocity = vel;
}

void PhysicalWorld::Step(const float dt)
{
	for (Object* obj : m_objects)
	{
		//clear objects that are out of screen
		if (obj->Position.x < -1000 || obj->Position.x > 1000 || obj->Position.y < -1000 || obj->Position.y > 1000)
		{
			counterMiss++;
			this->RemoveObject(obj);
			break;
		}

		obj->Velocity += (obj->Force + m_gravity * obj->Mass) / obj->Mass * dt;
		obj->Position += obj->Velocity * dt;
	}
}

void PhysicalWorld::drawWorld()
{
	for (Object* obj : m_objects)
	{
		obj->draw();
	}
}