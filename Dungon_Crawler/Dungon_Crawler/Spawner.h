#include "Weapon.h"
#include "Armor.h"
#include "Zombie.h"


typedef struct lootDrop {
	int gold = 0;
	int xp = 0;
	Armor armour;
	Weapon weapon;
	//potion
	//other


}LootDrop;


////NOTE: I have all the multipliers as seperate ints just in case they need adjustment for balancing later


class Spawner {
private:

	//Zombie names for random generation
	string ZombieNames[8] = { "Zombie", "Ghoul", "Skeleton", "Corpse Eater", "Grave Walker", "Pale", "Rotter", "Resurected" };

	//Weapons++++++++++++++++++++++++++++++++++++++++++++++++++++
	//Descriptor names for random name generation by levell		0-6							8-14												15-24											25-39													40+		
	string WeaponDescriptors[5][5] = { {"Wooden","Weak","Plastic","Super Common","Pitiful"} ,{"Stone","Dull","Damaged","Rusted","Common"},{"Iron","Adaquate","Usable","Bronze", "Rare"},{"Steel","Good", "Strong","Vicious","Sharp"},{"Diamond","Amazing","Angelic","Legendary","God Like"} };
	//Sword names for random name generation
	string SwordNames[5] = { "Sword","Cutlass","Foil","Rapier","Scimitar" };
	//Dagger names for random name generation
	string DaggerNames[5] = { "Dagger", "Stilleto","Dirk","Bowie Knife","Cleaver" };
	

	
	//weak multiplier
	int Weak = 1;
	//avg multiplier
	int Medium = 2;
	//strong multiplier
	int Strong = 3;
	//+++++++++++++++++++++++++++++++++++++++++++++++++


	//Armor+++++++++++++++++++++++++++++++++++++++
	
	//Descriptor names for random name generation by levell		0-6							8-14												15-24											25-39													40+		
	string ArmorDescriptors[5][5] = { {"Cloth","Weak","Thread Bare","Super Common","Pitiful"} ,{"Leather","Shotty","Damaged","Warped","Common"},{"Iron","Adaquate","Usable","Bronze", "Rare"},{"Steel","Good", "Strong","Hardened","Resistant"},{"Diamond","Amazing","Angelic","Legendary","God Like"} };


	//multipliers for armour size
	int	small = 1; //Gloves,Helmet
	int Med = 2;//Pants,Boots
	int Large = 3;//Chest

	//multiplier for armour class
	//Heavy =3
	int H = 3;
	//Medium=2
	int M = 2;
	//Light=1
	int L = 1;


	//++++++++++++++++++++++++++++++++++++++++++++++

	

public:
	Spawner();
	Zombie CreateZombie(int playerLevel);
	LootDrop GenerateZombieLootDrop(Zombie zed);

	Weapon CreateClaws(int level);
	Weapon CreateSword(int level);
	Weapon CreateDagger(int level);
	Weapon CreateAxe(int level);
	Weapon CreateShield(int level);

	Armor CreateHelmet(int level, ArmorClass c);
	Armor CreateChest(int level, ArmorClass c);
	Armor CreateGloves(int level, ArmorClass c);
	Armor CreatePants(int level, ArmorClass c);
	Armor CreateBoots (int level, ArmorClass c);
};
