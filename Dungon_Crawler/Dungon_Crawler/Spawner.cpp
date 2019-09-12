#include"Spawner.h"

Spawner::Spawner() {
	
}

//creates a Zombie based on the level inputed. should be the players level
Zombie Spawner::CreateZombie(int level, bool forceLevel = false) {
	Zombie ret;
	
	//ransdomly sets name
	ret.setName(this->ZombieNames[rand() % this->ZombieNames.size()]);

	//sets level to range between playerlevel-3 and playerlevel+3
	if (forceLevel) {
		ret.setLevel(level);
	}
	else {
		ret.setLevel((level - 3) + rand() % 6);
	}
	//sets health and max health to 10 times its level
	ret.setHealth(10 * ret.getLevel());
	ret.setMaxHealth(10 * ret.getLevel());
		
	//sets base damage, defense, speed and stamina based on its level
	ret.setDamage((ret.getLevel()+1 / 2) + rand() % ret.getLevel());
	ret.setDefense((ret.getLevel()+1 / 4) + rand() % (ret.getLevel()+1 / 2));
	ret.setSpeed((ret.getLevel()+1 / 2) + rand() % ret.getLevel());
	ret.setStamina(rand() % 5);

	//sets weapon
	ret.setWeapon(CreateClaws(ret.getLevel(), true));

	//sets xp drop
	ret.setXP(ret.getLevel() + (ret.getDamage() + ret.getDefense()+ ret.getSpeed())/3);

	
	return ret;


}


//creates the zombies lootdrop
LootDrop Spawner::GenerateZombieLootDrop(Zombie zed) {

	LootDrop ret;
	//100% chance of xp drop
	ret.xp = zed.getXP();
	ret.gold = 0;
	//50% chance of gold drop
	if (rand() % 2 == 0) {
		//gold drop is minimum of 5 and can have upto 5+the amount calculated for xp
		ret.gold = (rand() % zed.getXP()) + 5;
	}
	//1% chance of weapon drop
	if (rand() % 100 == 0) {
		ret.weapon = zed.getWeapon();
	}
	//other drops when added
	return ret;
}

//creates a Claws based on the level inputed. should be the creatures level
Weapon* Spawner::CreateClaws(int level , bool forceLevel = false) {
	Weapon* ret= new Weapon();
	ret->setName("Claws");
	ret->setType(Claw);

	//sets level to range between level-3 and level+3
	if (forceLevel) {
		ret->setLevel(level);
	}
	else {
		ret->setLevel((level - 3) + rand() % 6);
	}
	
	

	
		//sets damage to medium, speed to strong, sets defense to extra weak
	ret->setDamage( ret->getLevel() + rand() % (ret->getLevel() * Medium));
	ret->setSpeed(ret->getLevel() + rand() % (ret->getLevel() * Strong));
	ret->setDefense((ret->getLevel()/2) + rand() % ret->getLevel()*Weak);
	ret->setRange(Weak);
	ret->setStackSize(1);
	ret->setTwoHanded(false);
	ret->setWeight((rand() % 3) + 1);

	ret->setValue((ret->getLevel() / 2) + (ret->getDamage() / 4) + (ret->getDefense() / 4) + (ret->getSpeed() / 4));


		return ret;
}


//creates a sword based on the level inputed. should be the creatures level
Weapon* Spawner::CreateSword(int level, bool forceLevel = false) {
	Weapon* ret = new Weapon();

	ret->setType(Sword);

	//sets level to range between level-3 and level+3
	if (forceLevel) {
		ret->setLevel(level);
	}
	else {
		ret->setLevel((level - 3) + rand() % 6);
	}

	//random name generation
	string name = "";
	if (ret->getLevel() < 7) {
		name = name + this->WeaponDescriptors[0][rand() % WeaponDescriptors[0].size()] + " " + this->SwordNames[rand() % SwordNames.size()];
	}
	else if (ret->getLevel() < 15) {
		name = name + this->WeaponDescriptors[1][rand() % WeaponDescriptors[1].size()] + " " + this->SwordNames[rand() % SwordNames.size()];
	}
	else if (ret->getLevel() < 25) {
		name = name + this->WeaponDescriptors[2][rand() % WeaponDescriptors[2].size()] + " " + this->SwordNames[rand() % SwordNames.size()];
	}
	else if (ret->getLevel() < 40) {
		name = name + this->WeaponDescriptors[3][rand() % WeaponDescriptors[3].size()] + " " + this->SwordNames[rand() % SwordNames.size()];
	}
	else if (ret->getLevel() > 40) {
		name = name + this->WeaponDescriptors[4][rand() % WeaponDescriptors[4].size()] +" "+ this->SwordNames[rand() % SwordNames.size()];
	}

	ret->setName(name);

	//sets damage to medium, speed to medium, defense to extra medium
	ret->setDamage(ret->getLevel() + rand() % (ret->getLevel() * Medium));
	ret->setSpeed(ret->getLevel() + rand() % (ret->getLevel() * Medium));
	ret->setDefense((ret->getLevel() / 2) + rand() % (ret->getLevel() * Medium));
	ret->setRange(Medium);
	ret->setStackSize(1);
	ret->setTwoHanded(false);
	ret->setWeight((rand() % 3) + 2);

	ret->setValue((ret->getLevel() / 2) + (ret->getDamage() / 4) + (ret->getDefense() / 4) + (ret->getSpeed() / 4));

	return ret;

}

//creates a Dagger based on the level inputed. should be the creatures level
Weapon* Spawner::CreateDagger(int level, bool forceLevel = false) {
	Weapon* ret=new Weapon();

	//sets level to range between level-3 and level+3
	if (forceLevel) {
		ret->setLevel(level);
	}
	else {
		ret->setLevel((level - 3) + rand() % 6);
	}

	
	ret->setType(Dagger);
	//random name generation
	string name = "";
	if (ret->getLevel() < 7) {
		name = name + this->WeaponDescriptors[0][rand() % (WeaponDescriptors[0].size() )]+ " " + this->DaggerNames[rand() % (DaggerNames.size()-1)];
	}
	else if (ret->getLevel() < 15) {
		name = name + this->WeaponDescriptors[1][rand() % WeaponDescriptors[1].size()] + " " + this->DaggerNames[rand() % DaggerNames.size()];
	}
	else if (ret->getLevel() < 25) {
		name = name + this->WeaponDescriptors[2][rand() % WeaponDescriptors[2].size()] + " " + this->DaggerNames[rand() % DaggerNames.size()];
	}
	else if (ret->getLevel() < 40) {
		name = name + this->WeaponDescriptors[3][rand() % WeaponDescriptors[3].size()] + " " + this->DaggerNames[rand() % DaggerNames.size()];
	}
	else if (ret->getLevel() > 40) {
		name = name + this->WeaponDescriptors[4][rand() % WeaponDescriptors[4].size()] + " " + this->DaggerNames[rand() % DaggerNames.size()];
	}



	ret->setName(name);

	//sets damage to med, speed to strong, defense to extra weak
	ret->setDamage(ret->getLevel() + rand() % (ret->getLevel() * Medium));
	ret->setSpeed(ret->getLevel() + rand() % (ret->getLevel() * Strong));
	ret->setDefense((ret->getLevel() / 2) + rand() % ret->getLevel()*Weak);
	ret->setRange(Weak);
	ret->setStackSize(1);
	ret->setTwoHanded(false);
	ret->setWeight((rand() % 3) + 1);

	ret->setValue((ret->getLevel() / 2) + (ret->getDamage() / 4) + (ret->getDefense() / 4) + (ret->getSpeed() / 4));


	return ret;
}

//creates a Axe based on the level inputed. should be the creatures level
Weapon* Spawner::CreateAxe(int level, bool forceLevel) {
	Weapon* ret = new Weapon();

	//sets level to range between level-3 and level+3
	if (forceLevel) {
		ret->setLevel(level);
	}
	else {
		ret->setLevel((level - 3) + rand() % 6);
	}


	ret->setType(Axe);

	//random generation 
	string name = "";
	if (ret->getLevel() < 7) {
		name = name + this->WeaponDescriptors[0][rand() % WeaponDescriptors[0].size()] + " Axe";
	}
	else if (ret->getLevel() < 15) {
		name = name + this->WeaponDescriptors[1][rand() % WeaponDescriptors[1].size()] + " Axe";
	}
	else if (ret->getLevel() < 25) {
		name = name + this->WeaponDescriptors[2][rand() % WeaponDescriptors[2].size()] + " Axe";
	}
	else if (ret->getLevel() < 40) {
		name = name + this->WeaponDescriptors[3][rand() % WeaponDescriptors[3].size()] + " Axe";
	}
	else if (ret->getLevel() > 40) {
		name = name + this->WeaponDescriptors[4][rand() % WeaponDescriptors[4].size()] + " Axe";
	}

	ret->setName(name);

	//sets damage to strong, speed to weak, defense to extra medium
	ret->setDamage(ret->getLevel() + rand() % (ret->getLevel() * Strong));
	ret->setSpeed(ret->getLevel() + rand() % (ret->getLevel() * Weak));
	ret->setDefense((ret->getLevel() / 2) + rand() % ret->getLevel()*Medium);
	ret->setRange(Weak);
	ret->setStackSize(1);
	ret->setTwoHanded(false);
	ret->setWeight((rand() % 3) + 1);

	ret->setValue((ret->getLevel() / 2) + (ret->getDamage() / 4) + (ret->getDefense() / 4) + (ret->getSpeed() / 4));


	return ret;


}

//creates a shield based on the level inputed. should be the creatures level
Weapon* Spawner::CreateShield(int level, bool forceLevel = false) {
	Weapon* ret=new Weapon();

	//random
	if (forceLevel) {
		ret->setLevel(level);
	}
	else {
		ret->setLevel((level - 3) + rand() % 6);
	}

	ret->setType(Axe);

	//random name generation
	string name = "";
	if (ret->getLevel() < 7) {
		name = name + this->WeaponDescriptors[0][rand() % WeaponDescriptors[0].size()] + " Shield";
	}
	else if (ret->getLevel() < 15) {
		name = name + this->WeaponDescriptors[1][rand() % WeaponDescriptors[1].size()] + " Shield";
	}
	else if (ret->getLevel() < 25) {
		name = name + this->WeaponDescriptors[2][rand() % WeaponDescriptors[2].size()] + " Shield";
	}
	else if (ret->getLevel() < 40) {
		name = name + this->WeaponDescriptors[3][rand() % WeaponDescriptors[3].size()] + " Shield";
	}
	else if (ret->getLevel() > 40) {
		name = name + this->WeaponDescriptors[4][rand() % WeaponDescriptors[4].size()] + " Shield";
	}


	ret->setName(name);

	//sets damage to extra weak ,speed to medium and defense to extra strong
	ret->setDamage(ret->getLevel()/2 + rand() % (ret->getLevel() * Weak));
	ret->setSpeed(ret->getLevel() + rand() % (ret->getLevel() * Medium));
	ret->setDefense((ret->getLevel() ) + rand() % ret->getLevel()*Strong);
	ret->setRange(Weak);
	ret->setStackSize(1);
	ret->setTwoHanded(false);
	ret->setWeight((rand() % 3) + 1);

	ret->setValue((ret->getLevel() / 2) + (ret->getDamage() / 4) + (ret->getDefense() / 4) + (ret->getSpeed() / 4));


	return ret;
}



Armor* Spawner::CreateHelmet(int level, ArmorClass c,bool forceLevel = false) {
	int classMultiplier = 1;
	string classType = "";
	Armor* ret= new Armor();

	
	if (forceLevel) {
		ret->setLevel(level);
	}
	else {
		//+ or - 3 levels
		ret->setLevel((level - 3) + rand() % 6);
	}


	switch (c)
	{
	case Light: classMultiplier = this->L; classType = " Light";

		break;
	case Normal: classMultiplier = this->M; classType = " Normal";
		break;
	case Heavy: classMultiplier = this->H; classType = " Heavy";
		break;
	default:
		break;
	}
	ret->setType(Helmet);

	string name = "";
	if (ret->getLevel() < 7) {
		name = name + this->ArmorDescriptors[0][rand() % WeaponDescriptors[0].size()] +classType +" Helmet";
	}
	else if (ret->getLevel() < 15) {
		name = name + this->ArmorDescriptors[1][rand() % WeaponDescriptors[1].size()] + classType + " Helmet";
	}
	else if (ret->getLevel() < 25) {
		name = name + this->ArmorDescriptors[2][rand() % WeaponDescriptors[2].size()] + classType + " Helmet";
	}
	else if (ret->getLevel() < 40) {
		name = name + this->ArmorDescriptors[3][rand() % WeaponDescriptors[3].size()] + classType + " Helmet";
	}
	else if (ret->getLevel() > 40) {
		name = name + this->ArmorDescriptors[4][rand() % WeaponDescriptors[4].size()] + classType + " Helmet";
	}

	ret->setName(name);

	
	ret->setWeight(this->small*classMultiplier+rand()%classMultiplier);

	ret->setDefense(ret->getLevel()*(classMultiplier*this->small) + rand() % ret->getLevel());
	ret->setStackSize(1);
	ret->setValue(ret->getLevel() + (ret->getDefense() / ret->getWeight()));

	return ret;





}
Armor* Spawner::CreateChest(int level, ArmorClass c, bool forceLevel = false) {
	int classMultiplier = 1;
	string classType = "";
	Armor* ret=new Armor;


	if (forceLevel) {
		ret->setLevel(level);
	}
	else {
		//+ or - 3 levels
		ret->setLevel((level - 3) + rand() % 6);
	}


	switch (c)
	{
	case Light: classMultiplier = this->L; classType = " Light";

		break;
	case Normal: classMultiplier = this->M; classType = " Normal";
		break;
	case Heavy: classMultiplier = this->H; classType = " Heavy";
		break;
	default:
		break;
	}
	ret->setType(Chest);

	string name = "";
	if (ret->getLevel() < 7) {
		name = name + this->ArmorDescriptors[0][rand() % WeaponDescriptors[0].size()] + classType + " Chest";
	}
	else if (ret->getLevel() < 15) {
		name = name + this->ArmorDescriptors[1][rand() % WeaponDescriptors[1].size()] + classType + " Chest";
	}
	else if (ret->getLevel() < 25) {
		name = name + this->ArmorDescriptors[2][rand() % WeaponDescriptors[2].size()] + classType + " Chest";
	}
	else if (ret->getLevel() < 40) {
		name = name + this->ArmorDescriptors[3][rand() % WeaponDescriptors[3].size()] + classType + " Chest";
	}
	else if (ret->getLevel() > 40) {
		name = name + this->ArmorDescriptors[4][rand() % WeaponDescriptors[4].size()] + classType + " Chest";
	}

	ret->setName(name);



	ret->setWeight(this->Large*classMultiplier + rand() % (classMultiplier));

	ret->setDefense(ret->getLevel()*(classMultiplier*this->Large) + rand() % ret->getLevel());
	ret->setStackSize(1);
	ret->setValue(ret->getLevel() + (ret->getDefense() / ret->getWeight()));

	return ret;
}
Armor* Spawner::CreateGloves(int level, ArmorClass c, bool forceLevel = false) {
	int classMultiplier = 1;
	string classType = "";
	Armor* ret=new Armor();


	if (forceLevel) {
		ret->setLevel(level);
	}
	else {
		//+ or - 3 levels
		ret->setLevel((level - 3) + rand() % 6);
	}


	switch (c)
	{
	case Light: classMultiplier = this->L; classType = " Light";

		break;
	case Normal: classMultiplier = this->M; classType = " Normal";
		break;
	case Heavy: classMultiplier = this->H; classType = " Heavy";
		break;
	default:
		break;
	}
	ret->setType(Gloves);

	string name = "";
	if (ret->getLevel() < 7) {
		name = name + this->ArmorDescriptors[0][rand() % WeaponDescriptors[0].size()] + classType + " Gloves";
	}
	else if (ret->getLevel() < 15) {
		name = name + this->ArmorDescriptors[1][rand() % WeaponDescriptors[1].size()] + classType + " Gloves";
	}
	else if (ret->getLevel() < 25) {
		name = name + this->ArmorDescriptors[2][rand() % WeaponDescriptors[2].size()] + classType + " Gloves";
	}
	else if (ret->getLevel() < 40) {
		name = name + this->ArmorDescriptors[3][rand() % WeaponDescriptors[3].size()] + classType + " Gloves";
	}
	else if (ret->getLevel() > 40) {
		name = name + this->ArmorDescriptors[4][rand() % WeaponDescriptors[4].size()] + classType + " Gloves";
	}

	ret->setName(name);


	ret->setWeight(this->small*classMultiplier + rand() % classMultiplier);

	ret->setDefense(ret->getLevel()*(classMultiplier*this->small) + rand() % ret->getLevel());
	ret->setStackSize(1);
	ret->setValue(ret->getLevel() + (ret->getDefense() / ret->getWeight()));

	return ret;


}
Armor* Spawner::CreatePants(int level, ArmorClass c, bool forceLevel = false) {
	int classMultiplier = 1;
	string classType = "";
	Armor* ret=new Armor();


	if (forceLevel) {
		ret->setLevel(level);
	}
	else {
		//+ or - 3 levels
		ret->setLevel((level - 3) + rand() % 6);
	}


	switch (c)
	{
	case Light: classMultiplier = this->L; classType = " Light";

		break;
	case Normal: classMultiplier = this->M; classType = " Normal";
		break;
	case Heavy: classMultiplier = this->H; classType = " Heavy";
		break;
	default:
		break;
	}
	ret->setType(Pants);

	string name = "";
	if (ret->getLevel() < 7) {
		name = name + this->ArmorDescriptors[0][rand() % WeaponDescriptors[0].size()] + classType + " Pants";
	}
	else if (ret->getLevel() < 15) {
		name = name + this->ArmorDescriptors[1][rand() % WeaponDescriptors[1].size()] + classType + " Pants";
	}
	else if (ret->getLevel() < 25) {
		name = name + this->ArmorDescriptors[2][rand() % WeaponDescriptors[2].size()] + classType + " Pants";
	}
	else if (ret->getLevel() < 40) {
		name = name + this->ArmorDescriptors[3][rand() % WeaponDescriptors[3].size()] + classType + " Pants";
	}
	else if (ret->getLevel() > 40) {
		name = name + this->ArmorDescriptors[4][rand() % WeaponDescriptors[4].size()] + classType + " Pants";
	}

	ret->setName(name);


	ret->setWeight(this->Med*classMultiplier + rand() % classMultiplier);

	ret->setDefense(ret->getLevel()*(classMultiplier*this->Med) + rand() % ret->getLevel());
	ret->setStackSize(1);
	ret->setValue(ret->getLevel() + (ret->getDefense() / ret->getWeight()));

	return ret;


}
Armor* Spawner::CreateBoots(int level, ArmorClass c, bool forceLevel = false) {
	int classMultiplier = 1;
	string classType = "";
	Armor* ret=new Armor();


	if (forceLevel) {
		ret->setLevel(level);
	}
	else {
		//+ or - 3 levels
		ret->setLevel((level - 3) + rand() % 6);
	}


	switch (c)
	{
	case Light: classMultiplier = this->L; classType = " Light";

		break;
	case Normal: classMultiplier = this->M; classType = " Normal";
		break;
	case Heavy: classMultiplier = this->H; classType = " Heavy";
		break;
	default:
		break;
	}
	ret->setType(Boots);

	string name = "";
	if (ret->getLevel() < 7) {
		name = name + this->ArmorDescriptors[0][rand() % WeaponDescriptors[0].size()] + classType + " Boots";
	}
	else if (ret->getLevel() < 15) {
		name = name + this->ArmorDescriptors[1][rand() % WeaponDescriptors[1].size()] + classType + " Boots";
	}
	else if (ret->getLevel() < 25) {
		name = name + this->ArmorDescriptors[2][rand() % WeaponDescriptors[2].size()] + classType + " Boots";
	}
	else if (ret->getLevel() < 40) {
		name = name + this->ArmorDescriptors[3][rand() % WeaponDescriptors[3].size()] + classType + " Boots";
	}
	else if (ret->getLevel() > 40) {
		name = name + this->ArmorDescriptors[4][rand() % WeaponDescriptors[4].size()] + classType + " Boots";
	}
	ret->setName(name);



	ret->setWeight(this->Med*classMultiplier + rand() % classMultiplier);

	ret->setDefense(ret->getLevel()*(classMultiplier*this->Med) + rand() % ret->getLevel());
	ret->setStackSize(1);
	ret->setValue(ret->getLevel() + (ret->getDefense() / ret->getWeight()));

	return ret;

}



//if random is true it will randomly assign a tier based on the level input else it will make it with the inputed tier
Potion* Spawner::CreateHealthPotion(bool random = false, int level = 1, int Tier = 1) {
	Potion * ret = new Potion();



	return ret;
}

//if random is true it will randomly assign a tier based on the level input else it will make it with the inputed tier
Potion* Spawner::CreateSpeedPotion(bool random = false, int level = 1, int Tier = 1) {
	Potion * ret = new Potion();

	return ret;
}

//if random is true it will randomly assign a tier based on the level input else it will make it with the inputed tier
Potion* Spawner::CreateStaminaPotion(bool random = false, int level = 1, int Tier = 1) {
	Potion * ret = new Potion();

	return ret;
}




