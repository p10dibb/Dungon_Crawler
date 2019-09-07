#include"Spawner.h"

Spawner::Spawner() {
	
}

Zombie Spawner::CreateZombie(int playerLevel) {
	Zombie ret;
	

	ret.setName(ret.Names[rand() % ret.Names->length()]);
	ret.setLevel((rand() % (playerLevel - 3)) + (rand() % 6));
	ret.setHealth(10 * ret.getLevel());
	ret.setMaxHealth(10 * ret.getLevel());
		
	ret.setDamage((ret.getLevel() / 2) + rand() % ret.getLevel());
	ret.setDefense((ret.getLevel() / 4) + rand() % (ret.getLevel() / 2));
	ret.setSpeed((ret.getLevel() / 2) + rand() % ret.getLevel());
	ret.setStamina(rand() % 5);

	Weapon w = CreateClaws(ret.getLevel());

	return ret;


}

Weapon Spawner::CreateClaws(int level ) {
	Weapon ret;
	ret.setName("Claws");
	ret.setType(Claw);


		ret.setLevel(rand() % (level - 3) + rand() % 6);
	

	

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

Weapon Spawner::CreateSword(int level) {
	Weapon ret;

	ret.setType(Sword);
	ret.setLevel(rand() % (level - 3) + rand() % 6);
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

Weapon Spawner::CreateDagger(int level) {
	Weapon ret;

	ret.setLevel(rand() % (level - 3) + rand() % 6);

	
	ret.setType(Dagger);

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

Weapon Spawner::CreateAxe(int level) {
	Weapon ret;

	ret.setLevel(rand() % (level - 3) + rand() % 6);


	ret.setType(Axe);

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


Weapon Spawner::CreateShield(int level) {
	Weapon ret;

	ret.setLevel(rand() % (level - 3) + rand() % 6);


	ret.setType(Axe);

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