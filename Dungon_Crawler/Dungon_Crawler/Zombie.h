#include "Creature.h"
#include "Weapon.h"



class Zombie : public Creature {
private:
	
	int Damage;
	int Defense;
	int Speed;
	int Stamina;

	Weapon weapon;


public:
	string Names[8] = { "Zombie", "Ghoul", "Skeleton", "Corpse Eater", "Grave Walker", "Pale", "Rotter", "Resurected" };

	Zombie();
	int getDamage();
	void setDamage(int i);
	int getDefense();
	void setDefense(int d);
	int getSpeed();
	void setSpeed(int s);
	int getStamina();
	void setStamina(int s);
	Weapon getWeapon();
	void setWeapon(Weapon w);

	int Attack();

	int TakeDamage(int attack);


	void DisplayDetails();
	


};