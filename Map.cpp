// Map.cpp

#include "Map.h"
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

bool Map::checkStatus() const
{
	
	return this->plantAmount > 0;
}
