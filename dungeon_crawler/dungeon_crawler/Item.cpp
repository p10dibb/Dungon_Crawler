#include "Item.h"



Item::Item() {
	this->Name = "";
	this->Value = 0;
	this->Weight = 1;
	this->StackSize = 1;
}

string Item::getName() {
	return this->Name;
}

void Item::setName(string n) {
	this->Name = n;
}
int Item::getValue() {
	return this->Value;
}

void Item::setValue(int v) {
	this->Value = v;
}
	   
int Item::getWeight() {
	return this->Weight;
}

void Item::setWeight(int w) {
	this->Weight = w;
}

int Item::getStackSize() {
	return this->StackSize;
}

void Item::setStackSize(int s) {
	this->StackSize = s;
}


