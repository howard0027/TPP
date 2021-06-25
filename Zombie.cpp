// Zombie.cpp

#include "Zombie.h"
//#include "Plant.h"
#include <iostream>
#include <cassert>
#include <cstdlib>
#include <ctime>

int Zombie::idCounter = 0;

Zombie::Zombie()
{
	this->pos = 0;
	this->dir =  Zombie::GO_DOWN;
	
	this->id = Zombie::idCounter;
	Zombie::idCounter += 1;
}

Zombie::Zombie(const int sz)
{
	this->hp = Zombie::INIT_HP;
	this->atk = Zombie::INIT_ATK;
	this->pos = rand() % sz;
	this->dir = Zombie::GO_DOWN;
	
	this->id = Zombie::idCounter;
	Zombie::idCounter += 1;
}

Zombie::~Zombie()
{
	
}

int Zombie::getID() const
{
	return this->id;
}

void Zombie::move(const int sz)
{
	int step = this->myrand(1, sz);
	
	if(this->dir == Zombie::GO_DOWN)
	{
		this->pos += step;
		if(this->pos >= sz)
		{
			this->pos -= sz;
			this->dir = this->changeDir(dir);
		}
	}
	else if(this->dir == Zombie::GO_UP)
	{
		this->pos -= step;
		if(this->pos < 0)
		{
			this->pos += sz;
			this->dir = this->changeDir(dir);
		}
	}
	else
	{
		assert(0);
	}
	return;
}

int Zombie::getHP() const
{
	return this->hp;
}

int Zombie::getAtk() const
{
	return this->atk;
}

int Zombie::getPos() const
{
	return this->pos;
}
/*
void Zombie::attack(Plant &plant) 
{
	plant.zombieAct(*this);
	return;
}
*/
void Zombie::print() const
{
	std::cout << "Demage: " << this->getAtk() << " ";
	std::cout << "HP:";
	
	for(int i = 0; i < this->getHP(); ++i)
	{
		std::cout << "*";
	}
	return;
}

int Zombie::myrand(const int lb, const int ub) const
{
	assert(lb <= ub);
	
	return rand()%(ub-lb+1)+lb;
}

int Zombie::changeDir(const int originalDir) const
{
	if(originalDir == Zombie::GO_UP) return Zombie::GO_DOWN;
	if(originalDir == Zombie::GO_DOWN) return Zombie::GO_UP;
	assert(0); // error condition
	const int ERR = -1;
	return ERR;
}

void Zombie::lostHP(int delta)
{
	this->hp -= delta;
	return;
}

bool Zombie::isDead() const
{
	return this->getHP()<=0;
}

