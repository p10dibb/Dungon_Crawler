#include "Player.h"


//All the getters and setter for player


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
	if (p.getType() == Pants && p.getLevel() <= this->getLevel()) {
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


int Player::getMoney() {
	return this->Money;

}
void Player::setMoney(int m) {
	this->Money = m;

}


int Player::getLevelUp() {
	return this->LevelUp;
}

void Player::setLevelUp(int l) {
	if (l < 1) {
		l = 1;
	}
	this->LevelUp = l;
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


int Player::getMaxWeight() {
	return this->MaxWeight;
}
void Player::setMaxWeight(int w) {
	if (w < 1) {
		w = 1;
	}
	this->MaxWeight = w;
}

int Player::getCurrentWeight() {
	return this->CurrentWeight;
}
void Player::setCurrentWeight(int w) {
	if (w < 0) {
		w = 0;
	}
	this->CurrentWeight = w;
}

bool Player::getOverWeighted() {
	return this->OverWeighted;
}
void Player::setOverWeighted(bool w) {
	this->OverWeighted = w;
}


int Player::getInventorySize() {
	return this->InventorySize;
}
void Player::setInventorySize(int i) {
	this->InventorySize = i;
}