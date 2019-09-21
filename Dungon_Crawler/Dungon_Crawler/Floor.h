#include "Room.h"

class Floor  {

private:
	array<array<Room,10>,10> FloorMap;
	Player *player;

	array<int, 2> currentRoom;



public:
	Floor();

	array<array<Room, 10>, 10> getFloorMap();
	void setFloormap(array<array<Room, 10>, 10> f);

	void setRoom(Room r, int x, int y);

	Room getRoom( int x, int y);

	void setPlayer(Player *p);
	Player* getPlayer();

	void setCurrentRoom(array<int, 2> c);
	array<int, 2> getCurrentRoom();

	int NavigateFloor();

};