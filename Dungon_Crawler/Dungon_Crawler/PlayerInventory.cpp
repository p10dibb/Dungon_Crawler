#include "Player.h"

//adds an Item to the players inventory;
bool Player::addToInventory(Item *i) {
	if (FreeSlots != 0) {

		//checks if there is already a stack of said item and if there is room in the stack for another one
		for (int j = 0; j < this->getInventorySize(); j++) {

			//checks if names are same then if max stack size is reached
			if ((*this->Inventory[j].item).getName() == i->getName() && (*this->Inventory[j].item).getStackSize() > this->Inventory[j].amount) {
				this->Inventory[j].amount += 1;

				this->setCurrentWeight(this->getCurrentWeight() + i->getWeight());

				this->setOverWeighted(this->getMaxWeight() < this->getCurrentWeight());

				return true;
			}
		}
		//if not already a stack find next empty slot and add new stack
		for (int k = 0; k < this->getInventorySize(); k++) {
			//checks if inventory slot is empty
			if (this->Inventory[k].amount == 0) {
				this->Inventory[k].amount = 1;
				this->Inventory[k].item = i;
				this->setOverWeighted(this->getMaxWeight() < this->getCurrentWeight());
				return true;
			}
		}

	}
	else {
		cout << "inventory Full" << endl;
		return false;
	}


	return false;

}


//Displays whole inventory
void Player::DisplayInventory() {
	cout << "#\tItemName\tamount\t" << endl;
	for (int i = 0; i < this->InventorySize / 2; i++) {
		cout << i << "\t" << this->Inventory[i].item->getName() << "\t" << this->Inventory[i].amount << "\t" << i + this->InventorySize / 2 << "\t" << this->Inventory[i + this->InventorySize / 2].item->getName() << "\t" << this->Inventory[i + this->InventorySize / 2].amount << endl;

	}
}


//Displays inventory and all of the options
int Player::InventoryDialogue() {
	array<string,5> functions = { "view","equip","use", "move","exit" };
	int slot = -1;
	string func = "";
	int funcNum = -1;


	while (1) {
		cout << "Enter an option and a position" << endl;
		cout << "List of Options:[";
		for (int i = 0; i < functions.size(); i++) {
			cout << functions[i] << "| ";
		}
		cout << "]" << endl;

		cout << "Inventory Slots: " << endl;
		this->DisplayInventory();

		cout << endl << "Input:";
		cin >> func;
		funcNum = getFuncInventory(func);
		if (funcNum == -1) {
			cout << endl << "Not a valid option type" << endl;

		}
		else if (funcNum == 4) {
			cout << "Exiting inventory" << endl;
			return 0;
		}
		else {
			cin >> slot;
			if (slot > this->InventorySize || slot < 0) {
				cout << "Not a valid inventory slot" << endl;
			}
			else {


				switch (funcNum)
				{

				case 0: this->ViewInventory(slot);
					break;
				case 1:this->EquipInventory(slot);
					break;
				case 2: this->UseInventory(slot);
					break;
				case 3: this->MoveInventory(slot);
					break;


				}
			}
		}






	}
}


//takes a string and returns a number corelating to the functions name
int Player::getFuncInventory(string s) {
	array<string, 5> functions = { "view","equip","use","move","exit" };

	for (int i = 0; i < functions.size(); i++) {
		if (functions[i] == s) {
			return i;
		}
	}
	return -1;

}

//gets item from inventory slot checks its type and displays info
int Player::ViewInventory(int pos) {

	if (this->Inventory[pos].amount == 0) {
		cout << "Slot " << pos << " is empty" << endl;
		return -1;
	}
	else {
		if (typeid(*this->Inventory[pos].item) == typeid(Weapon)) {

			Weapon* w = dynamic_cast<Weapon*>(this->Inventory[pos].item);
			w->DisplayDetails();
		}
		else if ((typeid(*this->Inventory[pos].item) == typeid(Armor))) {
			Armor* a = dynamic_cast<Armor*>(this->Inventory[pos].item);
			a->DisplayDetails();
		}
		else if ((typeid(*this->Inventory[pos].item) == typeid(Potion))) {
			Potion* a = dynamic_cast<Potion*>(this->Inventory[pos].item);
			a->DisplayDetails();
		}
		system("pause");

		return 0;
	}


}

// equips an item from inventory
int Player::EquipInventory(int pos) {

	if (typeid(*this->Inventory[pos].item) == typeid(Weapon)) {
		this->DisplayEquiped();
		Weapon* w = dynamic_cast<Weapon*>(this->Inventory[pos].item);
		int input = 0;
		cout << "wold you like to equip right(1) left(2):";
		cin >> input;
		if (input == 1) {
		 this->Inventory[pos].item=this->Right;
		 if (!this->setRight(w)) {
			 cout << "Failed to equip" << endl;
			 this->Inventory[pos].item = w;
		}
		 return 0;
		}
		else if(input==2) {
			this->Inventory[pos].item = this->Left;
			if (!this->setLeft(w)) {
				cout << "Failed to equip" << endl;
				this->Inventory[pos].item = w;
			}
			return 0;
		}
		else {
			cout << "not valid input" << endl;
			return -1;
		}


	}
	else if ((typeid(*this->Inventory[pos].item) == typeid(Armor))) {
		
		Armor* a = dynamic_cast<Armor*>(this->Inventory[pos].item);
		if (a->getType() == Helmet) {
			this->Inventory[pos].item = this->getHead();
			if (!this->setHead(a)) {
				cout << "Failed to equip" << endl;
				this->Inventory[pos].item = a;
			}
		}
		else if (a->getType() == Chest) {
			this->Inventory[pos].item = this->getTorso();
			if (!this->setTorso(a)) {
				cout << "Failed to equip" << endl;
				this->Inventory[pos].item = a;
			}
		}
		else if (a->getType() == Gloves) {
			this->Inventory[pos].item = this->getHands();
			if (!this->setHands(a)) {
				cout << "Failed to equip" << endl;
				this->Inventory[pos].item = a;
			}
		}
		else if (a->getType() == Pants) {
			this->Inventory[pos].item = this->getLegs();
			if (!this->setLegs(a)) {
				cout << "Failed to equip" << endl;
				this->Inventory[pos].item = a;
			}
		}
		else if (a->getType() == Boots) {
			this->Inventory[pos].item = this->getFeet();
			if (!this->setFeet(a)) {
				cout << "Failed to equip" << endl;
				this->Inventory[pos].item = a;
			}
		}
	}



	return 0;
}

//use item in slot pos
int Player::UseInventory(int pos) {
	//checker for if an item was used 
	bool used = false;
	if  (this->Inventory[pos].amount==0){
		cout << "slot " << to_string(pos) << "is empty" << endl;
		return -1;

	}
	 if ((typeid(*this->Inventory[pos].item) == typeid(Potion))) {
	Potion* a = dynamic_cast<Potion*>(this->Inventory[pos].item);
	a->Use(this);
	used = true;

		}
	 else {
		 cout << "not a useable item" << endl;
	 }

	 //decrements inventory
	 if (used) {
		 this->Inventory[pos].amount--;
		 if (this->Inventory[pos].amount == 0) {
			 this->Inventory[pos].item = new Item();
		 }
	 }
	 
	
	



	return 0;
}

//Moves an item from one slot to another.
int Player::MoveInventory(int pos) {
	if (this->Inventory[pos].amount == 0) {
		cout << "slot " << pos << "is empty" << endl;
		return -1;
	}
	int newPos = -1;
	InventorySlot temp = this->Inventory[pos];

	cout << "which slot would you like to move it to? :" << endl;
	cin >> newPos;
	cout << endl;

	if (newPos<0 || newPos>this->InventorySize) {
		cout << newPos << " is not a valid position." << endl;
		return -1;
	}
	this->Inventory[pos] = this->Inventory[newPos];
	this->Inventory[newPos] = temp;


	return 0;
}


void Player::DisplayEquiped() {
	cout <<"\t" <<this->getName() << endl;
	cout << "Health: " << this->getHealth() << "/" << this->getMaxHealth()<<endl;
	cout << "Level: " << this->getLevel() << endl;
	cout << "XP: " << this->getXP() << "/" << this->getLevelUp() << endl;
	
	cout << "Armor:" << endl;
	cout << "Head:\t" << this->getHead()->getName() << "\t" << "Level: " << this->getHead()->getLevel()<<endl;
	cout << "Torso:\t" << this->getTorso()->getName() << "\t" << "Level: " << this->getTorso()->getLevel()<<endl;
	cout << "Hands:\t" << this->getHands()->getName() << "\t" << "Level: " << this->getHands()->getLevel()<<endl;
	cout << "Legs:\t" << this->getLegs()->getName() << "\t" << "Level: " << this->getLegs()->getLevel()<<endl;
	cout << "Boots:\t" << this->getHead()->getName() << "\t" << "Level: " << this->getHead()->getLevel()<<endl;
	cout << endl << "Weapons: " << endl;
	cout << "Right Hand:\t" << this->getRight()->getName() << "\tLevel: " << this->getRight()->getLevel() << endl;
	cout << "Left Hand:\t" << this->getLeft()->getName() << "\tLevel: " << this->getLeft()->getLevel() << endl;

}



int Player::EquipedDialogue() {
	array<string, 8> commands = { "right","left","head","torso","hands","legs","feet","exit" };
	string input = "";
	while (1) {
		system("clear");
		this->DisplayEquiped();
		cout << "what would you like to see more info on |";
		for (int i = 0; i < commands.size(); i++) {
			cout << commands[i] << "| ";
		}
		cout << ":"<<endl;

		cin >> input;
		input = toLower(input);	

		if (input == commands[0]) {
			this->Right->DisplayDetails();
		}
		else if (input == commands[1]) {
				this->Left->DisplayDetails();
			}
		else if (input == commands[2]) {
			this->getHead()->DisplayDetails();
		}
		else if (input == commands[3]) {
			this->getTorso()->DisplayDetails();
		}
		else if (input == commands[4]) {
			this->getHands()->DisplayDetails();
		}
		else if (input == commands[5]) {
			this->getLegs()->DisplayDetails();
		}
		else if (input == commands[6]) {
			this->getFeet()->DisplayDetails();
		}
		else if (input == commands[7]) {
			return 0;
		}

		system("pause");
		}
	}


