#include "Creature.h"
#include "Armor.h"
#include "Weapon.h"


//Base Class for all humanoid creatures like Player,Zombie,...
class Humanoid : public Creature {

private:
	int Damage;
	int Defense;
	int Speed;
	int Stamina;
	int Strength;

	Armor* Head;
	Armor* Torso;
	Armor* Hands;
	Armor* Legs;
	Armor* Feet;



public:

	Humanoid();

	int getDamage();
	void setDamage(int i);
	int getDefense();
	void setDefense(int d);
	int getSpeed();
	void setSpeed(int s);
	int getStamina();
	void setStamina(int s);
	Armor* getHead();
	int setHead(Armor* h);
	Armor* getTorso();
	int setTorso(Armor* t);
	Armor* getHands();
	int setHands(Armor* h);
	Armor* getLegs();
	int setLegs(Armor* l);
	Armor* getFeet();
	int setFeet(Armor* f);

	int getStrength();
	void setStrength(int s);


	int Attack();

	int TakeDamage(int attack);







};