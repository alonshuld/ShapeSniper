#pragma once


#include "ObjectTypes.h"
#include <iostream>
#include <vector>
#include <random>


#define BLUE vector3(0, 0.3, 0.7)
#define RED vector3(0.5, 0, 0)
#define BROWN vector3(0.5, 0.4, 0)
#define GREY vector3(0.1, 0.1, 0.1)
#define AMOUNT_OF_MISSES 5


class Game
{
private:
	std::vector<Object*> _objects;
	vector3 _gravity = vector3(0, -10, 0);
	int _miss = 0;
	int _shot = 0;
	int _max = 0;
	std::vector<vector3> generatePosVel();
public:
	/*
	* This function adds an object to the vector of the world
	* Input: object pointer
	* Output: none
	*/
	void addObject(Object* object);
	/*
	* This function returns how many objects the user missed
	* Input: none
	* Output: counter of how many objects missed
	*/
	int getMiss() const;
	/*
	* This function returns how many objects the user shot
	* Input: none
	* Output: counter of how many objects shot
	*/
	int getShot() const;
	/*
	* This function returns the highest score game yet
	* Input: none
	* Output: amount of objects got shot in the best match
	*/
	int getMax() const;
	/*
	* This function removes an object from the list
	* Input: pointer to an object that we want to remove
	* Output: none
	*/
	void reposObj(Object* object);
	/*
	* This function changes each variable to show what represent what happend in dt milliseconds
	* Input: milliseconds
	* Output: none
	*/
	void step(const float dt);
	/*
	* This function draws all the objects
	* Input: none
	* Output: none
	*/
	void drawWorld() const;
	/*
	* This function returns the object vector
	* Input: none
	* Output: a vector of object pointer
	*/
	std::vector<Object*> getObjects() const;
	/*
	* This function initializes the game, the objects and there position
	* Input: none
	* Output: none
	*/
	void start();
	/*
	* This function clears the object vector
	* Input: none
	* Output: none
	*/
	void end();
};