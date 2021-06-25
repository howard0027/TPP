// Map.cpp

#include "Map.h"
#include "Plant.h"
#include <cassert>
#include <vector>


Map::Map(const int numOfLands)
{
	this->numOfLands = numOfLands;
	
	this->plantList.resize(this->numOfLands);
	for(int i = 0; i < this->numOfLands; ++i)
	{
		this->plantList[i] = nullptr;
	}
}

Plant * Map::getPlantByIndexOfLand(const int idx) const
{
	assert(idx>=0 && idx<this->plantList.size());
	
	return this->plantList[idx];
	
}

void Map::planting(const int idx, Plant *plant)
{
	assert(0<=idx && idx<this->numOfLands);
	assert(this->plantList[idx]==nullptr);
	
	++this->plantAmount;
	this->plantList[idx] = plant;
	
	return;
}

void Map::updateStatus()
{
	const int DEAD = 0;
	
	for(std::size_t i = 0; i < this->plantList.size(); ++i)
	{
		Plant *plant = this->plantList[i];
		
		if(plant == nullptr) continue;
		
		if(plant->returnHp() <= DEAD)
		{
			delete this->plantList[i];
			this->plantList[i] = nullptr;
			
			this->plantAmount -= 1; // decrease amount
		}
		
	}
	
	return;
}

bool Map::checkStatus()
{
	this->updateStatus();
	return this->plantAmount > 0;
}

