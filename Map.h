#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

#include "RpgPerson.h"
class Map {
	private:
		std::string name;
		std::string nextMapName;
		int width;
		int height;
		int initialPositionX;
		int initialPositionY;
		std::vector<std::string> mapData;
		RpgPerson* player;

	public:
		std::vector<std::string> monsterType;
		Map();
		Map(std::string name, std::string nextMapName, int initialPositionX, int initialPositionY, int width, int height, std::vector<std::string> mapData, std::vector<std::string> monsterType);
		~Map();
		std::string getName();
		std::string getNextMapName();
		int getWidth();
		int getHeight();
		int getinitialPositionX();
		int getinitialPositionY();
		char getMapData(int x, int y);
		bool canMove(int x, int y);
		void printMap();
		void addPlayer(RpgPerson& player);
		void removePlayer();
};
#endif // MAP_H_INCLUDED
