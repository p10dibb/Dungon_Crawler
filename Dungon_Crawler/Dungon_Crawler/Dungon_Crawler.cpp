#include "Dungon_Crawler.h"


void Run() {
	srand(time(NULL));


	Spawner s;
	Weapon w = s.CreateSword(7);
	w.DisplayDetails();
	cout << endl;
	w = s.CreateDagger(7);
	w.DisplayDetails();
	cout << endl;
	w = s.CreateAxe(7);
	w.DisplayDetails();
	cout << endl;
	w = s.CreateShield(7);
	w.DisplayDetails();
	cout << endl;

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