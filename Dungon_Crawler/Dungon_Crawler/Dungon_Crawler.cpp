#include "Dungon_Crawler.h"


void Run() {
	srand(time(NULL));
	Spawner s;
	Player player = createPlayer();

	Room r;

	DoubleLinkedList<Zombie> z;
	DoubleLinkedList<Zombie> z1;
	DoubleLinkedList<Zombie> z2;
	Zombie ze = s.CreateZombie(1);
	Floor f;
	ze.setPosition({ 1,2 });

	z.add(ze);

	z1.add(s.CreateZombie(3));
	z1.add(s.CreateZombie(1));
	z1.add(s.CreateZombie(1));

	z.add(s.CreateZombie(1));
	r.setZeds(z);

	f.setPlayer(&player);
	f.setRoom(r, 0, 0);
	r.setZeds(z1);
	f.setRoom(r,1, 1);
	f.NavigateFloor();







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

