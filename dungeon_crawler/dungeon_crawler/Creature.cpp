#include "Creature.h"



class Creature {
	private : int Health;
	private : int Level;
	private: string Name;
	

public:int getHealth() {
	return this->Health;
}
public:void setHealth(int h) {
	this->Health = h;
}

};