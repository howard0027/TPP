// Zombie.h

#ifndef __ZOMBIE_H
#define __ZOMBIE_H 

// #include "Plant.h"

/*
 *
 * Zombie
 *
 */

class Zombie{
public:
	
	Zombie(); // Default, the position is always zero
	Zombie(const int); // Give the size of the map, then the player will randomly choose a land in the map
	~Zombie(); // Destructor
	
	int getID() const; // Returns this->id
	void move(const int); // Give the size of the map, then move on the map
	int getHP() const; // Get the current Health point
	int getAtk() const; // Get the current Attack value
	int getPos() const; // Get the current position
	// void attack(Plant &) ; // Give a plant, then zombie attacks it
	void print() const; // Print Zombie's Information ( Data Visualization )
	
	bool isDead() const; // If HP<=0, then this zombie dead.
	
	void lostHP(int); // this->HP -= delta.
	
	friend class Horn; // Because Plant may recude zombie's HP
	friend class Bomb; // Because Plant may recude zombie's HP
	
private:
	
	const static int GO_DOWN = 0; 
	const static int GO_UP = 1;
	
	const static int INIT_HP = 40;
	const static int INIT_ATK = 15;
	
	static int idCounter; // Init outside the class.
	
	int id = -1;
	
	int hp = Zombie::INIT_HP;
	int atk = Zombie::INIT_ATK;
	int pos = 0;
	int dir = Zombie::GO_DOWN;
	
	int myrand(const int, const int) const;
	int changeDir(const int) const;
	
};



#endif
