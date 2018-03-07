#include "Map.h"
Map::Map() {}
Map::Map(std::string name1, std::string nextMapName1, int initialPositionX1, int initialPositionY1, int width1, int height1, std::vector<std::string> mapData1, std::vector<std::string> monsterType1): name(name1), nextMapName(nextMapName1), initialPositionX(initialPositionX1), initialPositionY(initialPositionY1), width(width1), height(height1), mapData(mapData1), monsterType(monsterType1) {
}
Map::~Map() {}
std::string Map::getName() {
	return name;
}
std::string Map::getNextMapName() {
	return nextMapName;
}
int Map::getWidth() {
	return width;
}
int Map::getHeight() {
	return height;
}
int Map::getinitialPositionX() {
	return initialPositionX;
}
int Map::getinitialPositionY() {
	return initialPositionY;
}
char Map::getMapData(int x, int y) {
	return mapData[x][y];
}
bool Map::canMove(int x, int y) {
	if(getMapData(x, y) != '1')
		return true;
	else
		return false;
}
void Map::printMap() {
	for (int i = 0; i < mapData.size(); i++) {
		std::cout << mapData[i] << std::endl;
	}
}
void Map::addPlayer(RpgPerson& player) {
	this->player = &player;
	mapData[this->player->getY()][this->player->getX()] = '#';
}
void Map::removePlayer() {
	mapData[this->player->getY()][this->player->getX()] = ' ';
	this->player = NULL;
}
