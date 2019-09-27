#include <iostream>
 
using namespace::std;
//enumeration of types of damage
enum Damagetype { Basic, Fire, Stabbing, Blunt };

//class of Damage types
class DamageType {
private:

	Damagetype Type;

	//odds of it happening in percent
	int Chance;
	int Damage;

public:
	//sets Normal, 100%, 0 damage
	DamageType();

	//sets Normal, 100% , specify damage
	DamageType(int damage);

	//specify damage type, chance, and damage
	DamageType(Damagetype type, int chance, int damage);

	Damagetype getType();
	void setType(Damagetype t);

	int getChance();
	void setchance(int c);

	int getDamage();
	void setDamage(int d);

	void DisplayDetails();


};