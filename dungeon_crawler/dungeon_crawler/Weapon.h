#include "Item.h"


class Weapon :Item {
private: 
	int Damage;
	int Defense;
	bool TwoHanded;
	int Speed;
	int Level;
	int Range;
public:
	Weapon();
	Weapon(int Dam, int Def, bool TH, int Sp, int Lvl, int Rng);
	int getDamage();
	void setDamage(int d);
	int getDefense();
	void setDefense(int d);
	bool getTwoHanded();
	void setTwoHanded(bool t);
	int getSpeed();
	void setSpeed(int s);
	int getLevel();
	void setLevel(int l);
	int getRange();
	void setRange(int r);

};