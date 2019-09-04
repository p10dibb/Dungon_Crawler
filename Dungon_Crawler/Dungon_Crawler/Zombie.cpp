#include "Zombie.h"



Zombie::Zombie() {
	Creature();
	this->Damage = 0;
	this->Speed = 0;
	this->Defense = 0;
	this->Stamina = 0;
	this->weapon = Weapon();
	this->weapon.setName("Claws");
}
int Zombie::getDamage() {
	return this->Damage;
}
void Zombie::setDamage(int i) {
	if (i < 1) {
		i = 1;
	}
	this->Damage = i;
}
int Zombie::getSpeed() {
	return this->Speed;
}
void Zombie::setSpeed(int s) {
	if (s < 1) {
		s = 1;
	}
	this->Speed = s;
}
int Zombie::getStamina() {
	return this->Stamina;
}
void Zombie::setStamina(int s) {

	if (s < 1) {
		s = 1;
	}
	this->Stamina = s;
}
Weapon Zombie::getWeapon() {
	return this->weapon;
}
void Zombie::setWeapon(Weapon w) {
	this->weapon = w;
}

int Zombie::getDefense() {
	return this->Defense;
}
void Zombie::setDefense(int d) {
	if (d < 1) {
		d = 1;
	}
	this->Defense = d;
}

int Zombie::Attack() {
	return this->Damage+this->weapon.getDamage();
}


int Zombie::TakeDamage(int attack) {
	int health = this->getHealth();
	int damageTaken = 0;
	if ((attack - (this->Defense+this->weapon.getDefense())) < 0) {
		health = health - 1;
		damageTaken = 1;
	}
	else {
		damageTaken = attack - (this->Defense + this->weapon.getDefense());
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
	cout << "Damage: " << this->Damage << endl;
	cout << "Speed: " << this->Speed << endl;
	cout << "Defense: " << this->Defense << endl;
	cout << "Stamina: " << this->Stamina << endl;
	cout << "Weapon: " << endl;
	this->weapon.Display();
}	