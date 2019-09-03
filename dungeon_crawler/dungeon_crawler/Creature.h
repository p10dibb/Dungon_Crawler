

#include "dungon_crawler.h"





class Creature {

private:
	int Health;
	int Level;
	int XP;
	string Name;

public:
	int getHealth();
	void setHealth(int h);
	int getLevel();
	void setLevel(int l);
	int getXP();
	void setXP(int x);
	string getName();
	void setName(string n);



};


