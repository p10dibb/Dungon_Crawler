#include "Dungon_Crawler.h"


void Run() {
	Player player = createPlayer();

	player.DisplayDetails();
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