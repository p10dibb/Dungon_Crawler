#include "Player.h"


Player::Player() {
	Creature();
	this->ArmourRating = 5;
	this->AttackPower = 5;
	this->Speed = 5;
	this->DefensRating = 5;
	this->Stamina = 5;
	this->Strength = 5;

	this->Head =  Armor(0, 0, Helmet, Light);
	this->Head.setName("Hat");
	this->Torso = Armor(0, 0, Chest, Light);
	this->Torso.setName("Shirt");
	this->Legs = Armor(0, 0, Pants, Light);
	this->Legs.setName("Pants");
	this->Hands = Armor(0, 0, Gloves, Light);
	this->Hands.setName("Basic");
	this->Feet = Armor(0, 0, Boots, Light);
	this->Feet.setName("sandals");

	this->Right = Weapon(0, 0, false, 0, 0, 0);
	this->Right.setName("Fist");
	this->Left = Weapon(0, 0, false, 0, 0, 0);
	this->Left.setName("Fist");

	this->FreeSlots = 30;
	



}
int Player::getArmorRating() {
	return this->ArmourRating;
}
void Player::setArmorRating(int a) {
	this->ArmourRating = a;
}
int Player::getAttackPower() {
	return this->AttackPower;
}
void Player::setAttackPower(int a) {
	this->AttackPower = a;
}
int Player::getSpeed() {
	return this->Speed;
}
void Player::setSpeed(int s) {
	this->Speed = s;
}
int Player::getDefenseRating() {
	return this->DefensRating;
}
void Player::setDefenseRating(int d) {
	this->DefensRating = d;
}
int Player::getStamina() {
	return this->Stamina;
}
void Player::setStamina(int s) {
	this->Stamina = s;
}
int Player::getStrength() {
	return this->Strength;
}
void Player::setStrength(int s) {
	this->Strength = s;
}

Weapon Player::getLeft() {
	return this->Left;
}
int Player::setLeft(Weapon l) {
	if (l.getLevel() > this->getLevel()) {
		return 0;
	}
	this->Left = l;
	return 1;
}	
Weapon Player::getRight() {
	return this->Right;
}
int Player::setRight(Weapon l) {
	if (l.getLevel() > this->getLevel()) {
		return 0;
	}
	this->Right = l;
	return 1;
}

Armor Player::getHead() {
	return this->Head;
}
int Player::setHead(Armor h) {
	if (h.getType() == Helmet && h.getLevel() <= this->getLevel()) {
		this->Head = h;
		return 1;
	}
	return 0;
}
Armor Player::getTorso() {
	return this->Torso;
}
int Player::setTorso(Armor c) {
	if (c.getType() == Chest && c.getLevel() <= this->getLevel()) {
		this->Head = c;
		return 1;
	}
	return 0;
}

Armor Player::getHands() {
	return this->Hands;
}
int Player::setHands(Armor h) {
	if (h.getType() == Gloves && h.getLevel() <= this->getLevel()) {
		this->Head = h;
		return 1;
	}
	return 0;

}
Armor Player::getLegs() {
	return this->Legs;
}
int Player::setLegs(Armor p) {
	if (p.getType() ==Pants && p.getLevel() <= this->getLevel()) {
		this->Head = p;
		return 1;
	}
	return 0;
}
Armor Player::getFeet() {
	return this->Feet;
}
int Player::setFeet(Armor b) {
	if (b.getType() == Boots && b.getLevel() <= this->getLevel()) {
		this->Head = b;
		return 1;
	}
	return 0;
}

InventorySlot* Player::getInventory() {
	return this->Inventory;
}

void Player::setInventory(InventorySlot i[40]) {
	//this->Inventory = i;
	}
int Player::getFreeSlots() {
	return this->FreeSlots;
}
void Player::setFreeSlots(int f) {
	this->FreeSlots = f;
}

void Player::DisplayDetails() {
	cout << "Name: \t" << this->getName() << endl;
	cout << "Level: \t" << this->getLevel() << endl;
	cout << "XP: \t" << this->getXP() << endl;
	cout << "Health: \t" << this->getHealth() << endl;
	cout << "Stamina: \t" << this->getStamina() << endl;
	cout << "Attack: \t" << this->getAttackPower() << endl;
	cout << "Defense: \t" << this->getDefenseRating() << endl;
	cout << "Speed: \t" << this->getSpeed() << endl;
	cout << "Armor: \t" << endl;
	cout << "Head: \t" << this->getHead().getName() << endl;
	cout << "Torso: \t" << this->getTorso().getName() << endl;
	cout << "Hands: \t" << this->getHands().getName() << endl;
	cout << "Legs: \t" << this->getLegs().getName() << endl;
	cout << "Feet: \t" << this->getFeet().getName() << endl;
	cout << "Weapon: " << endl;
	cout << "Right: \t" << this->getRight().getName() << endl;
	cout << "Left: \t" << this->getLeft().getName() << endl;
}

