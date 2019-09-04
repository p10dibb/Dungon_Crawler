#include "Weapon.h"
#include "Armor.h"
#include "Zombie.h"


class Spawner {


public:
	Zombie CreateZombie(int playerLevel);

	Weapon CreateClaws(int level);

};
