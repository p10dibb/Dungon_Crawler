#include "Zombie.h"



Zombie::Zombie() {
	Humanoid();
	
	this->weapon = new Weapon();

}



Weapon* Zombie::getWeapon() {
	return this->weapon;
}
void Zombie::setWeapon(Weapon* w) {
	this->weapon = w;
}

int Zombie::Attack() {
	return this->getDamage()+this->weapon->getDamage();
}


int Zombie::TakeDamage(int attack) {
	int health = this->getHealth();
	int damageTaken = 0;
	if ((attack - (this->getDefense()+this->weapon->getDefense())) < 0) {
		health = health - 1;
		damageTaken = 1;
	}
	else {
		damageTaken = attack - (this->getDefense() + this->weapon->getDefense());
		health = health - damageTaken;
	}
	if (health < 0) {
		health = 0;
	}
	this->setHealth(health);
	return damageTaken;	
}


void Zombie:: DisplayDetails() {
	Display();
	cout << "Damage: " << this->getDamage() << endl;
	cout << "Speed: " << this->getSpeed() << endl;
	cout << "Defense: " << this->getDefense() << endl;
	cout << "Stamina: " << this->getStamina() << endl;
	cout << "Weapon: " << endl;
	this->weapon->DisplayDetails();
}	