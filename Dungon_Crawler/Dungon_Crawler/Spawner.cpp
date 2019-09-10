#include"Spawner.h"

Spawner::Spawner() {
	
}

//creates a Zombie based on the level inputed. should be the players level
Zombie Spawner::CreateZombie(int playerLevel) {
	Zombie ret;
	
	//ransdomly sets name
	ret.setName(this->ZombieNames[rand() % this->ZombieNames->length()]);

	//sets level to range between playerlevel-3 and playerlevel+3
	ret.setLevel(( (playerLevel - 3)) + (rand() % 6));

	//sets health and max health to 10 times its level
	ret.setHealth(10 * ret.getLevel());
	ret.setMaxHealth(10 * ret.getLevel());
		
	//sets base damage, defense, speed and stamina based on its level
	ret.setDamage((ret.getLevel()+1 / 2) + rand() % ret.getLevel());
	ret.setDefense((ret.getLevel()+1 / 4) + rand() % (ret.getLevel()+1 / 2));
	ret.setSpeed((ret.getLevel()+1 / 2) + rand() % ret.getLevel());
	ret.setStamina(rand() % 5);

	//sets weapon
	Weapon w = CreateClaws(ret.getLevel());
	ret.setWeapon( w);

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
Weapon Spawner::CreateClaws(int level ) {
	Weapon ret;
	ret.setName("Claws");
	ret.setType(Claw);

	//sets level to range between level-3 and level+3
		ret.setLevel( (level - 3) + rand() % 6);
	

	
		//sets damage to medium, speed to strong, sets defense to extra weak
	ret.setDamage( ret.getLevel() + rand() % (ret.getLevel() * Medium));
	ret.setSpeed(ret.getLevel() + rand() % (ret.getLevel() * Strong));
	ret.setDefense((ret.getLevel()/2) + rand() % ret.getLevel()*Weak);
	ret.setRange(Weak);
	ret.setStackSize(1);
	ret.setTwoHanded(false);
	ret.setWeight((rand() % 3) + 1);

	ret.setValue((ret.getLevel() / 2) + (ret.getDamage() / 4) + (ret.getDefense() / 4) + (ret.getSpeed() / 4));


		return ret;
}


//creates a sword based on the level inputed. should be the creatures level
Weapon Spawner::CreateSword(int level) {
	Weapon ret;

	ret.setType(Sword);

	//sets level to range between level-3 and level+3
	ret.setLevel((level - 3) + rand() % 6);

	//random name generation
	string name = "";
	if (ret.getLevel() < 7) {
		name = name + this->WeaponDescriptors[0][rand() % WeaponDescriptors[0]->length()] + " " + this->SwordNames[rand() % SwordNames->length()];
	}
	else if (ret.getLevel() < 15) {
		name = name + this->WeaponDescriptors[1][rand() % WeaponDescriptors[1]->length()] + " " + this->SwordNames[rand() % SwordNames->length()];
	}
	else if (ret.getLevel() < 25) {
		name = name + this->WeaponDescriptors[2][rand() % WeaponDescriptors[2]->length()] + " " + this->SwordNames[rand() % SwordNames->length()];
	}
	else if (ret.getLevel() < 40) {
		name = name + this->WeaponDescriptors[3][rand() % WeaponDescriptors[3]->length()] + " " + this->SwordNames[rand() % SwordNames->length()];
	}
	else if (ret.getLevel() > 40) {
		name = name + this->WeaponDescriptors[4][rand() % WeaponDescriptors[4]->length()] +" "+ this->SwordNames[rand() % SwordNames->length()];
	}

	ret.setName(name);

	//sets damage to medium, speed to medium, defense to extra medium
	ret.setDamage(ret.getLevel() + rand() % (ret.getLevel() * Medium));
	ret.setSpeed(ret.getLevel() + rand() % (ret.getLevel() * Medium));
	ret.setDefense((ret.getLevel() / 2) + rand() % (ret.getLevel() * Medium));
	ret.setRange(Medium);
	ret.setStackSize(1);
	ret.setTwoHanded(false);
	ret.setWeight((rand() % 3) + 2);

	ret.setValue((ret.getLevel() / 2) + (ret.getDamage() / 4) + (ret.getDefense() / 4) + (ret.getSpeed() / 4));

	return ret;

}

//creates a Dagger based on the level inputed. should be the creatures level
Weapon Spawner::CreateDagger(int level) {
	Weapon ret;

	//sets level to range between level-3 and level+3
	ret.setLevel( (level - 3) + rand() % 6);

	
	ret.setType(Dagger);
	//random name generation
	string name = "";
	if (ret.getLevel() < 7) {
		name = name + this->WeaponDescriptors[0][rand() % WeaponDescriptors[0]->length() ]+ " " + this->DaggerNames[rand() % DaggerNames->length()];
	}
	else if (ret.getLevel() < 15) {
		name = name + this->WeaponDescriptors[1][rand() % WeaponDescriptors[1]->length()] + " " + this->DaggerNames[rand() % DaggerNames->length()];
	}
	else if (ret.getLevel() < 25) {
		name = name + this->WeaponDescriptors[2][rand() % WeaponDescriptors[2]->length()] + " " + this->DaggerNames[rand() % DaggerNames->length()];
	}
	else if (ret.getLevel() < 40) {
		name = name + this->WeaponDescriptors[3][rand() % WeaponDescriptors[3]->length()] + " " + this->DaggerNames[rand() % DaggerNames->length()];
	}
	else if (ret.getLevel() > 40) {
		name = name + this->WeaponDescriptors[4][rand() % WeaponDescriptors[4]->length()] + " " + this->DaggerNames[rand() % DaggerNames->length()];
	}



	ret.setName(name);

	//sets damage to med, speed to strong, defense to extra weak
	ret.setDamage(ret.getLevel() + rand() % (ret.getLevel() * Medium));
	ret.setSpeed(ret.getLevel() + rand() % (ret.getLevel() * Strong));
	ret.setDefense((ret.getLevel() / 2) + rand() % ret.getLevel()*Weak);
	ret.setRange(Weak);
	ret.setStackSize(1);
	ret.setTwoHanded(false);
	ret.setWeight((rand() % 3) + 1);

	ret.setValue((ret.getLevel() / 2) + (ret.getDamage() / 4) + (ret.getDefense() / 4) + (ret.getSpeed() / 4));


	return ret;
}

//creates a Axe based on the level inputed. should be the creatures level
Weapon Spawner::CreateAxe(int level) {
	Weapon ret;

	//sets level to range between level-3 and level+3
	ret.setLevel( (level - 3) + rand() % 6);


	ret.setType(Axe);

	//random generation 
	string name = "";
	if (ret.getLevel() < 7) {
		name = name + this->WeaponDescriptors[0][rand() % WeaponDescriptors[0]->length()] + " Axe";
	}
	else if (ret.getLevel() < 15) {
		name = name + this->WeaponDescriptors[1][rand() % WeaponDescriptors[1]->length()] + " Axe";
	}
	else if (ret.getLevel() < 25) {
		name = name + this->WeaponDescriptors[2][rand() % WeaponDescriptors[2]->length()] + " Axe";
	}
	else if (ret.getLevel() < 40) {
		name = name + this->WeaponDescriptors[3][rand() % WeaponDescriptors[3]->length()] + " Axe";
	}
	else if (ret.getLevel() > 40) {
		name = name + this->WeaponDescriptors[4][rand() % WeaponDescriptors[4]->length()] + " Axe";
	}

	ret.setName(name);

	//sets damage to strong, speed to weak, defense to extra medium
	ret.setDamage(ret.getLevel() + rand() % (ret.getLevel() * Strong));
	ret.setSpeed(ret.getLevel() + rand() % (ret.getLevel() * Weak));
	ret.setDefense((ret.getLevel() / 2) + rand() % ret.getLevel()*Medium);
	ret.setRange(Weak);
	ret.setStackSize(1);
	ret.setTwoHanded(false);
	ret.setWeight((rand() % 3) + 1);

	ret.setValue((ret.getLevel() / 2) + (ret.getDamage() / 4) + (ret.getDefense() / 4) + (ret.getSpeed() / 4));


	return ret;


}

//creates a shield based on the level inputed. should be the creatures level
Weapon Spawner::CreateShield(int level) {
	Weapon ret;

	//random
	ret.setLevel( (level - 3) + rand() % 6);


	ret.setType(Axe);

	//random name generation
	string name = "";
	if (ret.getLevel() < 7) {
		name = name + this->WeaponDescriptors[0][rand() % WeaponDescriptors[0]->length()] + " Shield";
	}
	else if (ret.getLevel() < 15) {
		name = name + this->WeaponDescriptors[1][rand() % WeaponDescriptors[1]->length()] + " Shield";
	}
	else if (ret.getLevel() < 25) {
		name = name + this->WeaponDescriptors[2][rand() % WeaponDescriptors[2]->length()] + " Shield";
	}
	else if (ret.getLevel() < 40) {
		name = name + this->WeaponDescriptors[3][rand() % WeaponDescriptors[3]->length()] + " Shield";
	}
	else if (ret.getLevel() > 40) {
		name = name + this->WeaponDescriptors[4][rand() % WeaponDescriptors[4]->length()] + " Shield";
	}


	ret.setName(name);

	//sets damage to extra weak ,speed to medium and defense to extra strong
	ret.setDamage(ret.getLevel()/2 + rand() % (ret.getLevel() * Weak));
	ret.setSpeed(ret.getLevel() + rand() % (ret.getLevel() * Medium));
	ret.setDefense((ret.getLevel() ) + rand() % ret.getLevel()*Strong);
	ret.setRange(Weak);
	ret.setStackSize(1);
	ret.setTwoHanded(false);
	ret.setWeight((rand() % 3) + 1);

	ret.setValue((ret.getLevel() / 2) + (ret.getDamage() / 4) + (ret.getDefense() / 4) + (ret.getSpeed() / 4));


	return ret;
}

