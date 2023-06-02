#include "Game.h"


std::vector<vector3> Game::generatePosVel()
{
	std::random_device rd;
	vector3 pos = vector3();
	vector3 vel = vector3();
	std::vector<vector3> posvel;
	std::uniform_real_distribution<float> distPos(-900, 900);
	std::uniform_real_distribution<float> distVolY(150, 190);
	std::uniform_real_distribution<float> distVolX(10, 100);
	pos.setX(distPos(rd));
	while (pos.getX() > -200 && pos.getX() < 200)
		pos.setX(distPos(rd));
	pos.setY(-1000);
	posvel.push_back(pos);

	vel.setX(distVolX(rd));
	if (pos.getX() > 0)
		vel.setX(-vel.getX());
	vel.setY(distVolY(rd));
	posvel.push_back(vel);
	return posvel;
}

void Game::addObject(Object* object)
{
	_objects.push_back(object);
}

int Game::getMiss() const
{
	return _miss;
}

int Game::getShot() const
{
	return _shot;
}

int Game::getMax() const
{
	return _max;
}

void Game::reposObj(Object* object)
{
	if (!object)
		return;

	std::vector<vector3> posvel = generatePosVel();

	object->_pos = posvel[0];
	object->_vel = posvel[1];
}

void Game::step(const float dt)
{
	for (Object* obj : _objects)
	{
		//objects that got shot
		if (obj->_shot)
		{
			obj->_shot = false; //reset flag
			if (obj->_color == GREY) //if shot red objects its bomb
				_miss++;
			else
				_shot++;
			reposObj(obj);
		}
		//clear objects that are out of screen and consider them as miss
		if (obj->_pos.getX() < -1000 || obj->_pos.getX() > 1000 || obj->_pos.getY() < -1000 || obj->_pos.getY() > 1000)
		{
			if (obj->_color != GREY)
				_miss++;
			reposObj(obj);
		}

		if (_miss >= AMOUNT_OF_MISSES)
		{
			if (_shot > _max)
				_max = _shot;
			end();
			break;
		}

		vector3 accel = (obj->_force + _gravity * obj->_mass) / obj->_mass;

		obj->_vel = obj->_vel + accel * dt;
		obj->_pos = obj->_pos + obj->_vel * dt + accel * 0.5 * dt * dt;
	}
}

void Game::drawWorld() const
{
	for (Object* obj : _objects)
		obj->draw();
}

std::vector<Object*> Game::getObjects() const
{
	return _objects;
}

void Game::start()
{
	std::vector<vector3> posvel = generatePosVel();

	_objects.push_back(new Torus(
		posvel[0],		//axis
		posvel[1],		//Velocity
		vector3(),		//Force
		0.000001,		//Mass
		BROWN,			//color
		30				//radius
	));

	posvel = generatePosVel();

	_objects.push_back(new Sphere(
		posvel[0],			//axis
		posvel[1],			//Velocity
		vector3(0, 0, 0),	//Force
		0.1,				//Mass
		GREY,				//color
		80
	));

	posvel = generatePosVel();

	_objects.push_back(new Cube(
		posvel[0],		//axis
		posvel[1],		//Velocity
		vector3(),		//Force
		0.000001,		//Mass
		GREEN,			//color
		100				//rib
	));

	posvel = generatePosVel();

	_objects.push_back(new Cone(
		posvel[0],		//axis
		posvel[1],		//Velocity
		vector3(),		//Force
		0.000001,		//Mass
		BLUE,			//color
		80, 80			//base, height
	));
}

void Game::end()
{
	for (Object* obj : _objects)
		delete obj;
	_objects.clear();
	_miss = 0;
	_shot = 0;
}
