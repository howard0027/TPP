// Zombie.h

#ifndef __ZOMBIE_H
#define __ZOMBIE_H 

#include "Plant.h"

static const int GO_DOWN = 0; // This const value can only be called by this file.
static const int GO_UP = 1; // This const value can only be called by this file.

/*
 *
 * Zombie
 *
 */

class Zombie{
public:
	
	Zombie(); // Default, the position is always zero
	Zombie(const int); // Give the size of the map, then the player will randomly choose a land in the map
	void move(const int); // Give the size of the map, then move on the map
	int getHP() const; // Get the current Health point
	int getAtk() const; // Get the current Attack value
	int getPos() const; // Get the current position
	void attack(Plant &) const; // Give a plant, then zombie attacks it
	void print() const; // Print Zombie's Information ( Data Visualization )
private:
	
	const static int INIT_HP = 40;
	const static int INIT_ATK = 15;
	
	int hp = Zombie::INIT_HP;
	int atk = Zombie::INIT_ATK;
	int pos = 0;
	int dir = GO_DOWN;
	
	int myrand(const int, const int) const;
	int changeDir(const int) const;
	
};

#endif
