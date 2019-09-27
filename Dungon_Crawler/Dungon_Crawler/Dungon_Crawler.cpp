	#include "Dungon_Crawler.h"
#include "DamageTypes.h"

void Run() {
	srand(time(NULL));
	/*Spawner s;
	Player player = createPlayer();
	Floor f;

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			f.createRoom(i, j);
		}
	}
	f.setPlayer(&player);
	f.NavigateFloor();*/

	DoubleLinkedList<DamageType> d;
	d.add(DamageType());
	d.add(DamageType(Fire, 20, 10));
	d.add(DamageType(Blunt, 15, 13));

	for (int i = 0; i < d.Size(); i++) {
		d.getNode(i)->Data.DisplayDetails();
	}


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

