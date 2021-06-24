//Player.h

#ifndef __PLAYER_H
#define __PLAYER_H

/*
 *
 * Player
 *
 */

static const int GO_DOWN = 0; // This const value can only be called by this file.
static const int GO_UP = 1; // This const value can only be called by this file.

class Player{
public:
	
	Player(); // Default, the position is always zero
	Player(const int); // Give the size of the map, then the player will randomly choose a land in the map
	
	void move(const int); // Give the size of the map, then returns new position
	int getPos() const; // Give the current position of the player
	void addCoin(const int); // Give the money, then updates the balance
	int getCoin() const; // Give the current Coin(balance) of the player
	
private:
	
	const static int INIT_COIN = 150;
	
	int pos = 0;
	int dir = GO_DOWN;
	int coin = Player::INIT_COIN;
	
	int myrand(const int, const int) const;
	int changeDir(const int) const;
	
};

#endif
