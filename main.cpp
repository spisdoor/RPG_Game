#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <fstream>
using namespace std;
#include "Map.h"
#include "Monster.h"
#include "RpgCreature.h"
#include "RpgPerson.h"
#include "Job.h"

void play(RpgPerson& rp, int c1, string name, string op, string nextMapName, string mapName, vector<Map> cmap, int num, vector <save> save1);	

void directFight(string name, int c1, int &temp, vector<Map> cmap, RpgPerson& rp, RpgCreature& rc) {
	rp.attack(rc);
	if (rc.isDead()) {
		rp.addCoins(rc.getCoins());
		cout << "You beat " << rc.getName() << ", add " << rc.getExperience() << " exp." << endl;
		rp.raiseExperience(rc.getExperience());
		if (rp.checkLevelUp()) {
			rp.levelUp();
			rp.statusUp();
		}
		rc.recoverHp();
		temp = 1;
		return;
	}
	rc.attack(rp);
	if (rp.isDead()) {
		int minusExp = 0;
		minusExp += rand() % 2 + 1;
		cout << "Your hero is dead. Lost " << minusExp << " exp." << endl;
		rp.minusExperience(minusExp);
		rp.recoverHp();
		cout << "Hp recovered." << endl;
		rc.recoverHp();
		temp = 1;
		return;
	}
}

void escapeFight(string name, int c1, int &temp, vector<Map> cmap, RpgPerson& rp, RpgCreature& rc) {
	rc.attack(rp);
	if (rp.isDead()) {
		int minusExp = 0;
		minusExp += rand() % 2 + 1;
		cout << "Your hero is dead. Lost " << minusExp << " exp." << endl;
		rp.minusExperience(minusExp);
		rp.recoverHp();
		cout << "Hp recovered." << endl;
		rc.recoverHp();
		temp = 1;
		return;
	}
	rp.attack(rc);
	if (rc.isDead()) {
		rp.addCoins(rc.getCoins());
		cout << "You beat " << rc.getName() << ", add " << rc.getExperience() << " exp." << endl;
		rp.raiseExperience(rc.getExperience());
		if (rp.checkLevelUp()) {
			rp.levelUp();
			rp.statusUp();
		}
		rc.recoverHp();
		temp = 1;
		return;
	}
}

int main(int argc, char *argv[]) {
	string name, mapName, nextMapName, op /*operation*/, choice;
	int mapX, mapY, mapWidth, mapHeight, job;
	cout << "-----------------------------------" << endl;
	cout << "| Welcome to oop assignment4 rpg. |" << endl;
	cout << "-----------------------------------" << endl;
	cout << "| 1. New game                     |" << endl;        
	cout << "| 2. Load game                    |" << endl;     
	cout << "| 3. Exit                         |" << endl;     
	cout << "-----------------------------------" << endl;
	cout << "Enter your choice:" << endl;
	cin >> choice;

	vector <save> save1;
	vector <string> monsterType;
	vector <string> map;
	Map t;
	vector <Map> cmap; //current map
	int c = 0;
	ifstream fin("map.txt");
	while (fin >> mapName >> nextMapName >> mapX >> mapY >> mapWidth >> mapHeight) {
		string s;
		for (int k = 0; k < mapHeight; k++) {
			fin >> s;
			map.push_back(s);
		}
		for (int i = 0; i < mapHeight; i++) {
			for (int j = 0; j < mapWidth; j++) {
				if (map[i][j] == '0')
					map[i][j]=' ';
			}
		}
		string m;
		while (fin >> m) {
			if (m == "---") {
				break;
			}
			monsterType.push_back(m);
		}
		t = Map(mapName, nextMapName, mapX, mapY, mapWidth, mapHeight, map, monsterType);
		cmap.push_back(t);
		map.clear();
		monsterType.clear();
		c++;
	} //while

	int num = 0;
	string name1, job1, map1;
	int level1, currentHp1, maxHp1, strength1, defence1, crits1, coins1, experience1, mapX1, mapY1;
	ifstream in("save.txt");
	while (in >> name1 >> level1 >> job1 >> currentHp1 >> maxHp1 >> strength1 >> defence1 >> crits1 >> coins1 >> experience1 >> map1 >> mapX1 >> mapY1) {
		save tt = save(name1, level1, job1, currentHp1, maxHp1, strength1, defence1, crits1, coins1, experience1, map1, mapX1, mapY1);
		save1.push_back(tt);
		num++;
	} //while

	if (choice == "3") {
		return 0;
	}

	else if (choice == "2") {
		cout << "You have " << num << " records." << endl;
		for (int num1 = 1; num1 <= num; num1++) {
			cout << "-----record " << num1 << "-----" << endl;
			save1[num1-1].print();
			cout << "------------------" << endl;
		}
		cout << "Load record(Enter 1,2, ...):" << endl;
		int c1 = 0;
		int num3;
		cin >> num3;
		num3--;
		for (c1 = 0; c1 < cmap.size(); c1++) {
			if (save1[num3].getMapName() == cmap[c1].getName())
				break;
		}
		if (save1[num3].job == "SwordMan") {
			swordMan rp(save1[num3].getName(), save1[num3].getLevel(), save1[num3].getMaxHp(), save1[num3].getStrength(), save1[num3].getDefence(), save1[num3].getX(), save1[num3].getY(), save1[num3].getCrits(), save1[num3].getCoins(), save1[num3].getExperience(), save1[num3].getCurrentHp());
			play(rp, c1, name, op, nextMapName, mapName, cmap, num, save1);
		}
		else if (save1[num3].job == "Thief") {
			Thief rp(save1[num3].getName(), save1[num3].getLevel(), save1[num3].getMaxHp(), save1[num3].getStrength(), save1[num3].getDefence(), save1[num3].getX(), save1[num3].getY(), save1[num3].getCrits(), save1[num3].getCoins(), save1[num3].getExperience(), save1[num3].getCurrentHp());
			play(rp, c1, name, op, nextMapName, mapName, cmap, num, save1);
		}
		else if (save1[num3].job == "Magicion" || save1[num3].job == "Magician" ) {
			Magicion rp(save1[num3].getName(), save1[num3].getLevel(), save1[num3].getMaxHp(), save1[num3].getStrength(), save1[num3].getDefence(), save1[num3].getX(), save1[num3].getY(), save1[num3].getCrits(), save1[num3].getCoins(), save1[num3].getExperience(), save1[num3].getCurrentHp());
			play(rp, c1, name, op, nextMapName, mapName, cmap, num, save1);
		}
	} //choice 2

	else if (choice == "1") {
		cout << "Enter your name:" << endl;
		cin >> name;
		cout << "Enter your job(1-3):(1.SwordMan 2.Thief 3.Magicion)" << endl;
		cin >> job;
		int c1 = 0;
		if (job == 1) {
			swordMan rp(name, 1, 100, 7, 2, cmap[c1].getinitialPositionX(), cmap[c1].getinitialPositionY(), 20, 0, 0, 100);
			play(rp, c1, name, op, nextMapName, mapName, cmap, num, save1);
		}
		else if (job == 2) {
			Thief rp(name, 1, 100, 7, 2, cmap[c1].getinitialPositionX(), cmap[c1].getinitialPositionY(), 20, 0, 0, 100);
			play(rp, c1, name, op, nextMapName, mapName, cmap, num, save1);
		}
		else if (job == 3) {
			Magicion rp(name, 1, 100, 7, 2, cmap[c1].getinitialPositionX(), cmap[c1].getinitialPositionY(), 20, 0, 0, 100);
			play(rp, c1, name, op, nextMapName, mapName, cmap, num, save1);
		}
	} // choice 1
	return 0;
} //main

void play(RpgPerson& rp, int c1, string name, string op, string nextMapName, string MapName, vector<Map> cmap, int num, vector <save> save1) {
	cmap[c1].addPlayer(rp);
	cmap[c1].printMap();

	cout << "*****" << endl;
	cout << "Use w/s/a/d to move up/down/left/right." << endl;
	cout << "Enter i to show your status." << endl;
	cout << "Enter h to recover your hp (need 5 coins)." << endl;
	cout << "Enter save to save game." << endl;
	cout << "Enter exit to leave game." << endl;
	cout << "*****" << endl;

	while (cin >> op) {
		static int temp = 0;
		if (op == "exit") {
			break;
		}
		else if(op == "w") {
			if (cmap[c1].canMove(rp.getY() - 1, rp.getX())) {
				if (cmap[c1].getMapData(rp.getY() - 1, rp.getX()) == '@') {
					cmap[c1].removePlayer();
					for (int k = 0; k < 3; k++) {
						if (cmap[c1].getNextMapName() == cmap[k].getName()) {
							c1 = k;
							break;
						}
					}
					rp.setPosition(cmap[c1].getinitialPositionX(), cmap[c1].getinitialPositionY());
					cmap[c1].addPlayer(rp);
				}
				else {
					cmap[c1].removePlayer();
					rp.moveUp();
					cmap[c1].addPlayer(rp);
				}
				int meetMonster = 0;
				meetMonster += rand() % 100 + 1;
				if (meetMonster >= 1 && meetMonster <= 25) {
					int selectMonster = 0;
					selectMonster += rand() % cmap[c1].monsterType.size();
					Monster *rc = NULL;
					if (cmap[c1].monsterType[selectMonster] == "Slime") {
						cout << "You meet a Slime!!! The fight starts!!!" << endl;
						rc = new Monster("Slime", 30, 10, 3, 20, 1, 2, 30);
					}
					else if (cmap[c1].monsterType[selectMonster] == "Dragon") {
						rc = new Monster("Dragon", 150, 20, 30, 1, 15, 25, 150);
						cout << "You meet a Dragon!!! The fight starts!!!" << endl;
					}
					else if (cmap[c1].monsterType[selectMonster] == "Troll") {
						rc = new Monster("Troll", 35, 20, 5, 35, 5, 10, 35);
						cout << "You meet a Troll!!! The fight starts!!!" << endl;
					}

					cout << "-----" << endl;
					cout << "Enter '1' to attack, '2' to use skill, '3' to escape." << endl;
					cout << "-----" << endl;
					string opAttack;
					while (cin >> opAttack) {
						if (opAttack == "1") {
							directFight(name, c1, temp, cmap, rp, *rc);
						}
						else if (opAttack == "2") {
							rp.printSkill();
							int c;
							cin >> c;
							rp.useSkill(c, *rc, rp, rp.getLevel());
							if (rc->isDead()) {
								rp.addCoins(rc->getCoins());
								cout << "You beat " << rc->getName() << ", add " << rc->getExperience() << " exp." << endl;
								rp.raiseExperience(rc->getExperience());
								if (rp.checkLevelUp()) {
									rp.levelUp();
									rp.statusUp();
								}
								rc->recoverHp();
								break;
							}
							else {
								rc->attack(rp);
								if (rp.isDead()) {
									int minusExp = 0;
									minusExp += rand() % 2 + 1;
									cout << "Your hero is dead. Lost " << minusExp << " exp." << endl;
									rp.minusExperience(minusExp);
									rp.recoverHp();
									cout << "Hp recovered." << endl;
									rc->recoverHp();
									break;
								}
							}
						}
						else if (opAttack == "3") {
							int escape = 0;
							escape += rand() % 100 + 1;
							if (escape >= 1 && escape <= 30) {
								cout << "You successfully escaped from the fight!" << endl;
								rc->recoverHp();
								break;
							}
							else {
								cout << "Escape failed!!!" << endl;
								escapeFight(name, c1, temp, cmap, rp, *rc);
							}
						}
						else {
							cout << "Wrong input!" << endl;
						}
						if (temp == 1) {
							break;
						}
					}
				}
			}
			else {
				cout << "Can't move up, try another direction." << endl;
			}
		} //w
		else if (op == "s") {
			if (cmap[c1].canMove(rp.getY() + 1, rp.getX())) {
				if (cmap[c1].getMapData(rp.getY() + 1, rp.getX()) == '@') {
					cmap[c1].removePlayer();
					for (int k = 0; k < 3; k++) {
						if (cmap[c1].getNextMapName() == cmap[k].getName()) {
							c1 = k;
							break;
						}
					}
					rp.setPosition(cmap[c1].getinitialPositionX(), cmap[c1].getinitialPositionY());
					cmap[c1].addPlayer(rp);
				}
				else {
					cmap[c1].removePlayer();
					rp.moveDown();
					cmap[c1].addPlayer(rp);
				}
				int meetMonster = 0;
				meetMonster += rand() % 100 + 1;
				if (meetMonster >= 1 && meetMonster <= 25) {
					int selectMonster = 0;
					selectMonster += rand() % cmap[c1].monsterType.size();
					Monster *rc = NULL;
					if (cmap[c1].monsterType[selectMonster] == "Slime") {
						rc = new Monster("Slime", 30, 10, 3, 20, 1, 2, 30);
						cout << "You meet a Slime!!! The fight starts!!!" << endl;
					}
					else if (cmap[c1].monsterType[selectMonster] == "Dragon") {
						rc = new Monster("Dragon", 150, 20, 30, 1, 15, 25, 150);
						cout << "You meet a Dragon!!! The fight starts!!!" << endl;
					}
					else if (cmap[c1].monsterType[selectMonster] == "Troll") {
						rc = new Monster("Troll", 35, 20, 5, 35, 5, 10, 35);
						cout << "You meet a Troll!!! The fight starts!!!" << endl;
					}
					cout << "-----" << endl;
					cout << "Enter '1' to attack, '2' to use skill, '3' to escape." << endl;
					cout << "-----" << endl;
					string opAttack;
					while (cin >> opAttack) {
						if (opAttack == "1") {
							directFight(name, c1, temp, cmap, rp, *rc);
						}
						else if (opAttack == "2") {
							rp.printSkill();
							int c;
							cin >> c;
							rp.useSkill(c, *rc, rp, rp.getLevel());
							if (rc->isDead()) {
								rp.addCoins(rc->getCoins());
								cout << "You beat " << rc->getName() << ", add " << rc->getExperience() << " exp." << endl;
								rp.raiseExperience(rc->getExperience());
								if (rp.checkLevelUp()) {
									rp.levelUp();
									rp.statusUp();
								}
								rc->recoverHp();
								break;
							}
							else {
								rc->attack(rp);
								if (rp.isDead()) {
									int minusExp = 0;
									minusExp += rand() % 2 + 1;
									cout << "Your hero is dead. Lost " << minusExp << " exp." << endl;
									rp.minusExperience(minusExp);
									rp.recoverHp();
									cout << "Hp recovered." << endl;
									rc->recoverHp();
									break;
								}
							}
						}
						else if (opAttack == "3") {
							int escape = 0;
							escape += rand() % 100 + 1;
							if (escape >= 1 && escape <= 30) {
								cout << "You successfully escaped from the fight!" << endl;
								rc->recoverHp();
								break;
							}
							else {
								cout << "Escape failed!!!" << endl;
								escapeFight(name, c1, temp, cmap, rp, *rc);
							}
						}
						else {
							cout << "Wrong input!" << endl;
						}
						if (temp == 1) {
							break;
						}
					} //while
				}
			}
			else {
				cout << "Can't move up, try another direction." << endl;
			}
		} //s
		else if (op == "a") {
			if (cmap[c1].canMove(rp.getY(), rp.getX()-1)) {
				if(cmap[c1].getMapData(rp.getY(), rp.getX()-1) == '@') {
					cmap[c1].removePlayer();
					for (int k = 0; k < 3; k++) {
						if (cmap[c1].getNextMapName() == cmap[k].getName()) {
							c1 = k;
							break;
						}
					}
					rp.setPosition(cmap[c1].getinitialPositionX(), cmap[c1].getinitialPositionY());
					cmap[c1].addPlayer(rp);
				}
				else {
					cmap[c1].removePlayer();
					rp.moveLeft();
					cmap[c1].addPlayer(rp);
				}
				int meetMonster = 0;
				meetMonster += rand() % 100 + 1;
				if (meetMonster >= 1 && meetMonster <= 25) {
					int selectMonster = 0;
					selectMonster += rand() % cmap[c1].monsterType.size();
					Monster *rc = NULL;
					if (cmap[c1].monsterType[selectMonster] == "Slime") {
						rc = new Monster("Slime", 30, 10, 3, 20, 1, 2, 30);
						cout << "You meet a Slime!!! The fight starts!!!" << endl;
					}
					else if (cmap[c1].monsterType[selectMonster] == "Dragon") {
						rc = new Monster("Dragon", 150, 20, 30, 1, 15, 25, 150);
						cout << "You meet a Dragon!!! The fight starts!!!" << endl;
					}
					else if (cmap[c1].monsterType[selectMonster] == "Troll") {
						rc = new Monster("Troll", 35, 20, 5, 35, 5, 10, 35);
						cout << "You meet a Troll!!! The fight starts!!!" << endl;
					}
					cout << "-----" << endl;
					cout << "Enter '1' to attack, '2' to use skill, '3' to escape." << endl;
					cout << "-----" << endl;
					string opAttack;
					while (cin >> opAttack) {
						if (opAttack == "1") {
							directFight(name, c1, temp, cmap, rp, *rc);
						}
						else if (opAttack == "2") {
							rp.printSkill();
							int c;
							cin >> c;
							rp.useSkill(c, *rc, rp, rp.getLevel());
							if (rc->isDead()) {
								rp.addCoins(rc->getCoins());
								cout << "You beat " << rc->getName() << ", add " << rc->getExperience() << " exp." << endl;
								rp.raiseExperience(rc->getExperience());
								if (rp.checkLevelUp()) {
									rp.levelUp();
									rp.statusUp();
								}
								rc->recoverHp();
								break;
							}
							else {
								rc->attack(rp);
								if (rp.isDead()) {
									int minusExp = 0;
									minusExp += rand() % 2 + 1;
									cout << "Your hero is dead. Lost " << minusExp << " exp." << endl;
									rp.minusExperience(minusExp);
									rp.recoverHp();
									cout << "Hp recovered." << endl;
									rc->recoverHp();
									break;
								}
							}
						}
						else if (opAttack == "3") {
							int escape = 0;
							escape += rand() % 100 + 1;
							if (escape >= 1 && escape <= 30) {
								cout << "You successfully escaped from the fight!" << endl;
								rc->recoverHp();
								break;
							}
							else {
								cout << "Escape failed!!!" << endl;
								escapeFight(name, c1, temp, cmap, rp, *rc);
							}
						}
						else {
							cout << "Wrong input!" << endl;
						}
						if (temp == 1) {
							break;
						}
					} //while
				}
			}
			else {
				cout << "Can't move up, try another direction." << endl;
			}
		} //a
		else if (op == "d") {
			if (cmap[c1].canMove(rp.getY(), rp.getX() + 1)) {
				if (cmap[c1].getMapData(rp.getY(), rp.getX() + 1) == '@') {
					cmap[c1].removePlayer();
					for (int k = 0; k < 3; k++) {
						if (cmap[c1].getNextMapName() == cmap[k].getName()) {
							c1 = k;
							break;
						}
					}
					rp.setPosition(cmap[c1].getinitialPositionX(), cmap[c1].getinitialPositionY());
					cmap[c1].addPlayer(rp);
				}
				else {
					cmap[c1].removePlayer();
					rp.moveRight();
					cmap[c1].addPlayer(rp);
				}
				int meetMonster = 0;
				meetMonster += rand() % 100 + 1;
				if (meetMonster >= 1 && meetMonster <= 25) {
					int selectMonster = 0;
					selectMonster += rand() % cmap[c1].monsterType.size();
					Monster *rc = NULL;
					if (cmap[c1].monsterType[selectMonster] == "Slime") {
						rc = new Monster("Slime", 30, 10, 3, 20, 1, 2, 30);
						cout << "You meet a Slime!!! The fight starts!!!" << endl;
					}
					else if (cmap[c1].monsterType[selectMonster] == "Dragon") {
						rc = new Monster("Dragon", 150, 20, 30, 1, 15, 25, 150);
						cout << "You meet a Dragon!!! The fight starts!!!" << endl;
					}
					else if (cmap[c1].monsterType[selectMonster] == "Troll") {
						rc = new Monster("Troll", 35, 20, 5, 35, 5, 10, 35);
						cout << "You meet a Troll!!! The fight starts!!!" << endl;
					}
					cout << "-----" << endl;
					cout << "Enter '1' to attack, '2' to use skill, '3' to escape." << endl;
					cout << "-----" << endl;
					string opAttack;
					while (cin >> opAttack) {
						if (opAttack == "1") {
							directFight(name, c1, temp, cmap, rp, *rc);
						}
						else if (opAttack == "2") {
							rp.printSkill();
							int c;
							cin >> c;
							rp.useSkill(c, *rc, rp, rp.getLevel());
							if (rc->isDead()) {
								rp.addCoins(rc->getCoins());
								cout << "You beat " << rc->getName() << ", add " << rc->getExperience() << " exp." << endl;
								rp.raiseExperience(rc->getExperience());
								if (rp.checkLevelUp()) {
									rp.levelUp();
									rp.statusUp();
								}
								rc->recoverHp();
								break;
							}		
							else {
								rc->attack(rp);
								if (rp.isDead()) {
									int minusExp = 0;
									minusExp += rand() % 2 + 1;
									cout << "Your hero is dead. Lost " << minusExp << " exp." << endl;
									rp.minusExperience(minusExp);
									rp.recoverHp();
									cout << "Hp recovered." << endl;
									rc->recoverHp();
									break;
								}
							}
						}
						else if (opAttack == "3") {
							int escape = 0;
							escape += rand() % 100 + 1;
							if (escape >= 1 && escape <= 30) {
								cout << "You successfully escaped from the fight!" << endl;
								rc->recoverHp();
								break;
							}
							else {
								cout << "Escape failed!!!" << endl;
								escapeFight(name, c1, temp, cmap, rp, *rc);
							}
						}
						else {
							cout << "Wrong input!" << endl;
						}
						if (temp == 1) {
							break;
						}
					} //while
				}
			}
			else {
				cout << "Can't move up, try another direction." << endl;
			}
		} //d
		else if (op == "i") {
			rp.printStatus();
			cout << "Map: " << cmap[c1].getName() << endl;
		}
		else if (op == "h") {
			cout << "Use 5 coins to recover your hp. (yes/no)" << endl;
			string h;
			cin >> h;
			if (h == "yes") {
				if (rp.getCoins() >= 5) {
					cout << "Hp recovered." << endl;
					rp.useCoins();
					rp.recoverHp();
				}
				else {
					cout << "You don't have enough coins. (" << rp.getCoins() << "/5)" << endl;
				}
			}
			else if (h == "no") {}
		}
		else if (op == "save") {
			int num4;
			cout << "You have " << save1.size() << " records." << endl;
			for (int num1 = 1; num1 <= num; num1++) {
				cout << "-----record " << num1 << "-----" << endl;
				save1[num1 - 1].print();
				cout << "------------------" << endl;
			}
			cout << "Save record(Enter 1,2, ...):" << endl;
			cin >> num4;
			save s1 = save(rp.getName(), rp.getLevel(), rp.job, rp.getCurrentHp(), rp.getMaxHp(), rp.getStrength(), rp.getDefence(), rp.getCrits(), rp.getCoins(), rp.getExperience(), cmap[c1].getName(), rp.getX(), rp.getY());

			if (num4 >= save1.size() + 1) {
				save1.push_back(s1);
				cout << "Save to record " << num4 << endl;
			}
			else {
				string ss;
				cout << "Overwrite record " << num4 << "?(yes/no)" << endl;
				cin >> ss;
				if (ss == "yes") {
					save1[num4 - 1] = s1;
				}
				else if (ss == "no") {}
			}
			ofstream fout("save.txt");
			for (int j = 0; j < save1.size(); j++) {
				fout << save1[j].getName() << endl;
				fout << save1[j].getLevel() << endl;
				fout << save1[j].job << endl;
				fout << save1[j].getCurrentHp() << endl;
				fout << save1[j].getMaxHp() << endl;
				fout << save1[j].getStrength() << endl;
				fout << save1[j].getDefence() << endl;
				fout << save1[j].getCrits() << endl;
				fout << save1[j].getCoins() << endl;
				fout << save1[j].getExperience() << endl;
				fout << save1[j].getMapName() << endl;
				fout << save1[j].getX() << endl;
				if (j == save1.size() - 1)
					fout << save1[j].getY();
				else
					fout << save1[j].getY() << endl;
			}
			fout.close();
		} //save
		else {
			continue;
		}
		temp = 0;
		cmap[c1].printMap();

		cout << "*****" << endl;
		cout << "Use w/s/a/d to move up/down/left/right." << endl;
		cout << "Enter i to show your status." << endl;
		cout << "Enter h to recover your hp (need 5 coins)." << endl;
		cout << "Enter save to save game." << endl;
		cout << "Enter exit to leave game." << endl;
		cout << "*****" << endl;

	} //while
} //play function
