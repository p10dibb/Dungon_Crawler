#include "Player.h"


//Default constructor
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

	this->FreeSlots = 40;

	this->InventorySize = 40;

	
	this->LevelUp = 10;

	this->MaxWeight = 50;
	this->CurrentWeight = 0;
	this->OverWeighted = false;



}


//Displays all data for character
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


//calculates the players actual speed
int Player::ActualSpeed() {
	int speed = 0;
	int ArmorWeight = this->Head.getWeight() + this->Torso.getWeight() + this->Hands.getWeight() + this->Legs.getWeight() + this->Feet.getWeight();
	
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
	return this->Left.getDamage() + Right.getDamage() + this->AttackPower;
	
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
int Player:: TakeDamage(int damage) {

	int taken = damage - this->ActualDefense();
	if (taken < 1) {
		taken = 1;
	}

	this->setHealth(this->getHealth() - taken);
	return taken;

}

//player recieves lootdrop from enemy
void Player::RecieveLootDrop(lootDrop loot) {

	cout << "You recieved: " << endl << "XP: " << loot.xp << endl;
	this->setXP(this->getXP() + loot.xp);

	if (loot.gold != 0) {
		cout << "Gold: " << loot.gold << endl;
		this->Money += loot.gold;
	}

	if (loot.weapon.getType() != None) {
		cout << "Weapon: " << loot.weapon.getName()<<endl;
		this->addToInventory(loot.weapon);
	}

	if (loot.weapon.getType() != Nill) {
		cout << "Armor: " << loot.armour.getName();
		this->addToInventory(loot.armour);
	}

	if (this->getXP() <= this->getLevelUp()) {
		this->NextLevel();
	}


}

//level up dialogue for player
void Player::NextLevel() {
	//get 3 upgrade points when you level up
	int points = 3;
	int input = 0;

	this->setMaxHealth(this->getMaxHealth() + 10);
	this->setHealth(this->getMaxHealth());
	cout << "Congrats you leveled up!! \nMax Health is now: " << this->getMaxHealth() << endl;


	while (points != 0)
	{
		cout << "you have " << points << " remaining what would you like to upgrade?" << endl;
		cout << "#\tstat\tcurrent level\tDescription" << endl;
		cout << "1\tMaxHealth\t" << this->getMaxHealth() <<"\tMaximum Health of the player"<< endl;
		cout << "2\tStrength\t" << this->Strength <<"\tIncreases Carrying capacity and lessens handicap of speed for heavy armour"<< endl;
		cout << "3\tSpeed\t" << this->Speed << "\tIncreases speed in combat"<<endl;
		cout << "4\tBase Attack\t" << this->AttackPower <<"\tIncreases Base Damage"<< endl;
		cout << "5\tBase Defense\t" << this->DefensRating <<"\tIncreases Base Defense"<< endl;
		cout << "6\tStamina\t" << this->Stamina << "\tCurrently Does nothing"<<endl;
		cout << "Choice: ";
		cin >> input;
		if (input == 1) {

			this->setMaxHealth(this->getMaxHealth() + 10);
			this->setHealth(this->getMaxHealth());

		}
		else if (input == 2) {
			this->Strength += 1;
			this->MaxWeight = this->Strength * 10;
			
			this->setOverWeighted(this->MaxWeight < this->CurrentWeight);			
		}
		else if (input == 3) {
			this->Speed += 1;
		}
		else if (input == 4) {
			this->AttackPower += 1;
		}
		else if (input == 5) {
			this->DefensRating += 1;
		}
		else {
			cout << "Not a valid choice:" << endl;
			points++;
		}


		points--;

	}

	this->setLevelUp(this->getLevelUp() * 2);
}

//adds an Item to the players inventory;
bool Player::addToInventory(Item i) {

	


	if (FreeSlots != 0) {

		//checks if there is already a stack of said item and if there is room in the stack for another one
		for (int j = 0; j < this->getInventorySize(); j++) {
			if (this->Inventory[j].item.getName() == i.getName() && this->Inventory[j].item.getStackSize() > this->Inventory->amount) {
				this->Inventory[j].amount += 1;

				this->setCurrentWeight(this->getCurrentWeight() + i.getWeight());
				
				this->setOverWeighted(this->getMaxWeight() < this->getCurrentWeight());
				
				return true;
			}
		}
		//if not already a stack find next empty slot and add new stack
		for (int j = 0; j < this->getInventorySize(); j++) {
			if (this->Inventory[j].amount ==0) {
				this->Inventory[j].amount = 1;
				this->Inventory[j].item = i;
				this->setOverWeighted(this->getMaxWeight() < this->getCurrentWeight());
				return true;
			}
		}

	}
	else {
		cout << "inventory Full" << endl;
		return false;
	}




}


void Player::DisplayInventory() {
	cout << "#\tItemName\tamount\t" << endl;
	for (int i = 0; i < this->InventorySize/2; i++) {
		cout << i << "\t" << this->Inventory[i].item.getName() << "\t" << this->Inventory[i].amount << "\t" << i + this->InventorySize / 2 << "\t" << this->Inventory[i + this->InventorySize / 2].item.getName() << "\t" << this->Inventory[i + this->InventorySize / 2].amount << endl;

	}
}