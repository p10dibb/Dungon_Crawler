#include "Player.h"


Player::Player() {
	Creature();
	this->ArmourRating = 0;
	this->AttackPower = 0;
	this->Speed = 0;
	this->DefensRating = 0;
	this->Stamina = 0;
	this->Strength = 0;

	this->Head =  Armor(0, 0, Helmet, Light);
	this->Torso = Armor(0, 0, Chest, Light);
	this->Legs = Armor(0, 0, Pants, Light);
	this->Hands = Armor(0, 0, Gloves, Light);
	this->Feet = Armor(0, 0, Boots, Light);

	this->Right = Weapon(0, 0, false, 0, 0, 0);
	this->Left = Weapon(0, 0, false, 0, 0, 0);

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
	this->Speed;
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
	if (h.getType() == Helmet && h.getLevel <= this->getLevel()) {
		this->Head = h;
		return 1;
	}
	return 0;
}
Armor Player::getTorso() {
	return this->Torso;
}
int Player::setTorso(Armor c) {
	if (c.getType() == Chest && c.getLevel <= this->getLevel()) {
		this->Head = c;
		return 1;
	}
	return 0;
}

Armor Player::getHands() {
	return this->Hands;
}
int Player::setHands(Armor h) {
	if (h.getType() == Gloves && h.getLevel <= this->getLevel()) {
		this->Head = h;
		return 1;
	}
	return 0;

}
Armor Player::getLegs() {
	return this->Legs;
}
int Player::setLegs(Armor p) {
	if (p.getType() ==Pants && p.getLevel <= this->getLevel()) {
		this->Head = p;
		return 1;
	}
	return 0;
}
Armor Player::getFeet() {
	return this->Feet;
}
int Player::setFeet(Armor b) {
	if (b.getType() == Boots && b.getLevel <= this->getLevel()) {
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