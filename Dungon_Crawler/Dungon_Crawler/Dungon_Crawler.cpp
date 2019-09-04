#include "Dungon_Crawler.h"


void Run() {
	srand(time(NULL));

	Player player = createPlayer();

	player.DisplayDetails();

	Spawner s;
	Zombie z=s.CreateZombie(player.getLevel());
	z.DisplayDetails();

	system("pause");
}

Player createPlayer() {
	Player ret;

	string name;
	cout << "choose a name:" << endl;
	cin>> name;

	ret.setName(name);

	return ret;
}