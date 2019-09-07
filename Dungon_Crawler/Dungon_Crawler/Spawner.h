#include "Weapon.h"
#include "Armor.h"
#include "Zombie.h"


class Spawner {
private:
	string WeaponDescriptors[5][5] = { {"Wooden","Weak","Plastic","Super Common","Pitiful"} ,{"Stone","Dull","Damaged","Rusted","Common"},{"Iron","Adaquate","Usable","Bronze", "Rare"},{"Steel","Good", "Strong","Vicious","Sharp"},{"Diamond","Amazing","Angelic","Legendary","God Like"} };

	string SwordNames[5] = { "Sword","Cutlass","Foil","Rapier","Scimitar" };
	string DaggerNames[5] = { "Dagger", "Stilleto","Dirk","Bowie Knife","Cleaver" };
	 int Weak = 1;
	int Medium = 2;
	int Strong = 3;

	

public:
	Spawner();
	Zombie CreateZombie(int playerLevel);

	Weapon CreateClaws(int level);
	Weapon CreateSword(int level);
	Weapon CreateDagger(int level);
	Weapon CreateAxe(int level);
	Weapon CreateShield(int level);
};
