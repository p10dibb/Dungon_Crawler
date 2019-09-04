#include"Spawner.h"

Zombie Spawner::CreateZombie(int playerLevel) {
	Zombie ret;
	

	ret.setName(ret.Names[rand() % ret.Names->length()]);
	ret.setLevel((rand() % (playerLevel - 3)) + (rand() % 6));
	ret.setHealth(10 * ret.getLevel());
		
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
	

	

	ret.setDamage( ret.getLevel() + rand() % (ret.getLevel() * 2));
	ret.setSpeed(ret.getLevel() + rand() % (ret.getLevel() * 3));
	ret.setDefense((ret.getLevel() / 2) + rand() % ret.getLevel());
	ret.setRange(1);
	ret.setStackSize(1);
	ret.setTwoHanded(false);
	ret.setWeight((rand() % 3) + 1);

	ret.setValue((ret.getLevel() / 2) + (ret.getDamage() / 4) + (ret.getDefense() / 4) + (ret.getSpeed() / 4));


		return ret;
}