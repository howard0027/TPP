// Player.cpp

#include "Player.h"
#include <cassert>
#include <ctime>
#include <cstdlib>


Player::Player()
{
	this->pos = 0;
	this->dir = Player::GO_DOWN;
	this->coin = Player::INIT_COIN;
}

Player::Player(const int sz)
{
	this->pos = rand() % sz;
	this->dir = Player::GO_DOWN;
	this->coin = Player::INIT_COIN;
}

void Player::move(const int sz)
{
	int step = this->myrand(1, sz);
	
	if(this->dir == Player::GO_DOWN)
	{
		this->pos += step;
		if(this->pos >= sz)
		{
			this->pos -= sz;
			this->dir = this->changeDir(dir);
		}
	}
	else if(this->dir == Player::GO_UP)
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

int Player::getPos() const
{
	return this->pos;
}

void Player::addCoin(const int delta)
{
	this->coin += delta;
	return;
}

int Player::getCoin() const
{
	return this->coin;
}

int Player::myrand(const int lb, const int ub) const
{
	assert(lb <= ub);
	
	return rand() % (ub-lb+1) + lb;
}

int Player::changeDir(const int originalDir) const
{
	if(originalDir == Player::GO_UP) return Player::GO_DOWN;
	if(originalDir == Player::GO_DOWN) return Player::GO_UP;
	assert(0); // error condition
	const int ERR = -1;
	return ERR;
}

