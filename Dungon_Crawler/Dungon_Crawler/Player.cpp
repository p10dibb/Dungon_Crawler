#include "Player.h"


//Default constructor
Player::Player() {
	Humanoid();
	
	this->setDamage(5) ;
	this->setSpeed( 5);
	this->setDefense(5);
	this->setStamina(5);
	this->setStrength(5);

	

	this->Right = new Weapon(0, 0, false, 0, 0, 0,None);
	this->Right->setName("Fist");
	this->Left = new Weapon(0, 0, false, 0, 0, 0,None);
	this->Left->setName("Fist");

	this->FreeSlots = 40;

	this->InventorySize = 40;

	
	this->LevelUp = 10;

	this->MaxWeight = 50;
	this->CurrentWeight = 0;
	this->OverWeighted = false;

	this->LevelUp = 10;
	this->Inventory;
	
	for (int i = 0; i < this->InventorySize; i++) {
		this->Inventory[i].item = new Item();
	}
}


//Displays all data for character
void Player::DisplayDetails() {
	cout << "Name: \t" << this->getName() << endl;
	cout << "Level: \t" << this->getLevel() << endl;
	cout << "XP: \t" << this->getXP() << endl;
	cout << "Health: \t" << this->getHealth() << endl;
	cout << "Stamina: \t" << this->getStamina() << endl;
	cout << "Attack: \t" << this->getDamage() << endl;
	cout << "Defense: \t" << this->getDefense() << endl;
	cout << "Speed: \t" << this->getSpeed() << endl;
	cout << "Armor: \t" << endl;
	cout << "Head: \t" << this->getHead()->getName() << endl;
	cout << "Torso: \t" << this->getTorso()->getName() << endl;
	cout << "Hands: \t" << this->getHands()->getName() << endl;
	cout << "Legs: \t" << this->getLegs()->getName() << endl;
	cout << "Feet: \t" << this->getFeet()->getName() << endl;
	cout << "Weapon: " << endl;
	cout << "Right: \t" << this->getRight()->getName() << endl;
	cout << "Left: \t" << this->getLeft()->getName() << endl;
}


//calculates the players actual speed
int Player::ActualSpeed() {
	int speed = 0;
	int ArmorWeight = this->getHead()->getWeight() + this->getTorso()->getWeight() + this->getHands()->getWeight() + this->getLegs()->getWeight() + this->getFeet()->getWeight();
	
	//if onehanded else dual wielding
	if (this->Left->getType() == None) {
		speed = this->getSpeed() + this->Right->getSpeed() - (ArmorWeight / (this->getStrength() / 2));
	}
	else if(this->Right->getType() == None) {
		speed = this->getSpeed() + this->Left->getSpeed() - (ArmorWeight / (this->getStrength() / 2));
	}
	else {
		//two weapons being used 2/3 the speed of both weapons added together so dual wielding is slower but has higher attack and defense
		speed = this->getSpeed() +( (this->Left->getSpeed()+this->Right->getSpeed())/3 )- (ArmorWeight / (this->getStrength() / 2));
	}

	return speed;

}
//calculates players Actual attack
int Player::ActualDamage() {
	int attack = 0;

	//total of all damage items +actual attack power
	return this->Left->getDamage() + Right->getDamage() + this->getDamage();
	
}
//calculates Players actual Defense
int Player::ActualDefense() {
	//total of all defensive items
	return this->getDefense() + this->getHead()->getDefense() + this->getTorso()->getDefense() + this->getHands()->getDefense() + this->getLegs()->getDefense() + this->getFeet()->getDefense() + this->Right->getDefense() + this->Left->getDefense();

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

	if (loot.weapon->getType() != None) {
		cout << "Weapon: " << loot.weapon->getName()<<endl;
		this->addToInventory(loot.weapon);
	}

	if (loot.armour.getType() != Nill) {
		cout << "Armor: " << loot.armour.getName();
		this->addToInventory(&loot.armour);
	}

	if (this->getXP() >= this->getLevelUp()) {
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
		cout << "2\tStrength\t" << this->getStrength() <<"\tIncreases Carrying capacity and lessens handicap of speed for heavy armour"<< endl;
		cout << "3\tSpeed\t" << this->getSpeed() << "\tIncreases speed in combat"<<endl;
		cout << "4\tBase Attack\t" << this->getDamage() <<"\tIncreases Base Damage"<< endl;
		cout << "5\tBase Defense\t" << this->getDefense() <<"\tIncreases Base Defense"<< endl;
		cout << "6\tStamina\t" << this->getStamina() << "\tCurrently Does nothing"<<endl;
		cout << "Choice: ";
		cin >> input;
		if (input == 1) {

			this->setMaxHealth(this->getMaxHealth() + 10);
			this->setHealth(this->getMaxHealth());

		}
		else if (input == 2) {
			this->setStrength(this->getStrength()+1);
			this->MaxWeight = this->getStrength() * 10;
			
			this->setOverWeighted(this->MaxWeight < this->CurrentWeight);			
		}
		else if (input == 3) {
			this->setSpeed(this->getSpeed() + 1);
		}
		else if (input == 4) {
			this->setDamage(this->getDamage()+1);
		}
		else if (input == 5) {
			this->setDefense(this->getDefense()+1);
		}
		else {
			cout << "Not a valid choice:" << endl;
			points++;
		}


		points--;

	}

	this->setLevelUp(this->getLevelUp() * 2);
}

