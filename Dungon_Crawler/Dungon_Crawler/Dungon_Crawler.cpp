#include "Dungon_Crawler.h"


void Run() {
	srand(time(NULL));
	Spawner s;
	Player player = createPlayer();
	Weapon w = s.CreateAxe(1);

	Item i = Item("potion", 1, 1, 10);
	player.addToInventory(w);
	player.addToInventory(i);
	player.addToInventory(w);
	player.addToInventory(i);
	player.DisplayInventory();



	//while (w.getLevel() != 1) {
	//	w = s.CreateAxe(1);
	//}
	//player.setRight(w);
	//
	//w = s.CreateDagger(1);
	//while (w.getLevel() != 1) {
	//	w = s.CreateDagger(1);
	//}
	//player.setLeft(w);

	//
	//player.DisplayDetails();
	//cout << endl;
	system("pause");

	//

	//player.DisplayDetails();




	//Zombie z = s.CreateZombie(1);
	//z.DisplayDetails();
	//system("pause");
	//cout << endl;

	//PlayerVsZombieCombat(&player, z);
	//cout << endl;

	//system("pause");
}

Player createPlayer() {
	Player ret;

	string name;
	cout << "choose a name:" << endl;
	cin>> name;

	ret.setName(name);

	return ret;
}

//player fighting zombie
int PlayerVsZombieCombat(Player* player,Zombie zed) {

	//speed totals who ever has the higher number gets to attack
	int playerSpeedTot=player->ActualSpeed();
	int ZombieSpeedTot=zed.getSpeed();


	int Damage = 0;
	int round = 1;
	while (1) {
		cout << "round: " << round << " zed health:" << zed.getHealth() << " Player health:" << player->getHealth() << endl;;
		; round++;
		if (ZombieSpeedTot > playerSpeedTot) {
			cout << zed.getName() << " is attacking" << endl;

			//incriment player speed to see if player gets a turn
			playerSpeedTot += player->ActualSpeed();

			Damage=player->TakeDamage(zed.Attack());
			cout << player->getName() << " takes " << Damage << "damage" << endl;
		}
		else {
			cout << player->getName()<< " is attacking" << endl;

			//incriment the zombie speed to see if they get thier turn
			ZombieSpeedTot += zed.getSpeed();
		
			Damage = zed.TakeDamage(zed.Attack());
			cout << zed.getName() << " takes " << Damage << " damage" << endl;
			
		}

		if (player->getHealth() <= 0) {
			cout << "Player Died" << endl;
			return 0;
		}
		else if (zed.getHealth() <= 0) {
			cout << zed.getName() << "Died. Player wins" << endl;
			return 1;
		}




	}


}