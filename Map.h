// Map.h

#ifndef __MAP_H
#define __MAP_H

#include "Plant.h"
#include <vector>

// class Plant;

/*
 *
 * Map
 *
 */

class Map{
public:
	
	Map(const int); // Constructor, give the size of the map
	
	Plant * getPlantByIndexOfLand(const int) const; // get plantList[idx]
	
	void planting(const int, Plant *); // Planting in idx land
	bool checkStatus(); // call updateStatus(). Then it will return TRUE if plantAmount > 0
	
private:
	int numOfLands = 0;
	std::vector<Plant*> plantList; // the length is the number of lands. If there is no plant in a land, then it is nullptr.
	int plantAmount = 0; // Number of plants
	
	void updateStatus(); // To check how many alive plants ?
	
};

#endif
