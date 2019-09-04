#pragma once
#include "Item.h"



Item::Item() {
	this->Name = "";
	this->Value = 0;
	this->Weight = 1;
	this->StackSize = 1;
}


Item::Item(string name, int val, int weight, int stacksize) {
	this->Name = name;
	this->Value = val;
	this->Weight = weight;
	this->StackSize = stacksize;
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


void Item::Display() {
	cout << "Name: " << this->Name << endl << "Value: " << this->Value << endl << "Weight: " << this->Weight << endl << "StackSize: " << this->StackSize << endl;
}