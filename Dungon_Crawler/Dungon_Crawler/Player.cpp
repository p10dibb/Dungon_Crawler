#include "Player.h"


Player::Player() {
	Creature();
	
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

	this->Right = Weapon(0, 0, false, 0, 0, 0,None);
	this->Right.setName("Fist");
	this->Left = Weapon(0, 0, false, 0, 0, 0,None);
	this->Left.setName("Fist");

	this->FreeSlots = 30;
	



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


int Player::getMoney() {
	return this->Money;

}
void Player::setMoney(int m) {
	this->Money = m;

}

//calculates the players actual speed
int Player::ActualSpeed() {
	int speed = 0;
	int ArmorWeight = this->Head.getWeight() + this->Torso.getWeight() + this->Hands.getWeight + this->Legs.getWeight() + this->Feet.getWeight();
	
	if (this->Left.getType() == None) {
		speed = this->Speed + this->Right.getSpeed() - (ArmorWeight / (this->Strength / 2));
	}else if(this->Right.getType() == None) {
		speed = this->Speed + this->Left.getSpeed() - (ArmorWeight / (this->Strength / 2));
	}
	else {
		//two weapons being used 2/3 the speed of both weapons added together so dual wielding is slower but has higher attack and defense
		speed = this->Speed +( (this->Left.getSpeed()+this->Right.getSpeed())/3 )- (ArmorWeight / (this->Strength / 2));
	}

	return speed;

}
//calculates players Actual attack
int Player::ActualDamage() {
	int attack = 0;

	//total of all damage items +actual attack power
	attack = this->Left.getDamage() + Right.getDamage() + this->AttackPower;

}
//calculates Players actual Defense
int Player::ActualDefense() {
	//total of all defensive items
	return this->DefensRating + this->Head.getDefense() + this->Torso.getDefense() + this->Hands.getDefense() + this->Legs.getDefense() + this->Feet.getDefense() + this->Right.getDefense() + this->Left.getDefense();

}

//players attack
int Player::Attack() {

	//currently just actual damage  may change later.
	return this->ActualDamage();
}
//damage recieved
int Player:: RecieveDamage(int damage) {

	int taken = damage - this->ActualDefense();
	if (taken < 1) {
		taken = 1;
	}

	this->setHealth(this->getHealth() - taken);
	return taken;

}