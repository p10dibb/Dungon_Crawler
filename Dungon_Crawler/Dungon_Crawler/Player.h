#pragma once

#include "Spawner.h"

typedef struct inventorySlot {
	Item item;
	int amount;
}InventorySlot;

class Player : public Creature {


private:

	int AttackPower;
	int Speed;
	int DefensRating;
	int Stamina;
	int Strength;

	Weapon Left;
	Weapon Right;

	Armor Head;
	Armor Torso;
	Armor Hands;
	Armor Legs;
	Armor Feet;

	InventorySlot Inventory[40];
	int FreeSlots;

	int Money;

public:
	Player();


	int getAttackPower();
	void setAttackPower(int a);
	int getSpeed();
	void setSpeed(int s);
	int getDefenseRating();
	void setDefenseRating(int d);
	int getStamina();
	void setStamina(int s);
	int getStrength();
	void setStrength(int s);

	Weapon getLeft();
	int setLeft(Weapon l);
	Weapon getRight();
	int setRight(Weapon l);

	Armor getHead();
	int setHead(Armor h);
	Armor getTorso();
	int setTorso(Armor t);
	Armor getHands();
	int setHands(Armor h);
	Armor getLegs();
	int setLegs(Armor l);
	Armor getFeet();
	int setFeet(Armor f);

	InventorySlot* getInventory();
	void setInventory(InventorySlot i[40]);
	int getFreeSlots();
	void setFreeSlots(int f);

	int getMoney();
	void setMoney(int m);

	void DisplayDetails();

	//calculates the players actual speed
	int ActualSpeed();
	//calculates players Actual attack
	int ActualDamage();
	//calculates Players actual Defense
	int ActualDefense();

	//players attack
	int Attack();
	//damage recieved
	int RecieveDamage(int damage);


	

};
