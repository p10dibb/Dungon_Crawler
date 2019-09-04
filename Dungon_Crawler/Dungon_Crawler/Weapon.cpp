#pragma once
#include "Weapon.h"

Weapon::Weapon() {
	Item();
	this->Damage = 0;
	this->Defense = 0;
	this->TwoHanded = false;
	this->Speed = 0;
	this->Level = 0;
	this->Range = 0;
}
Weapon::Weapon(int Dam, int Def, bool TH, int Sp, int Lvl, int Rng) {
	Item();
	this->Damage = Dam;
	this->Defense = Def;
	this->TwoHanded = TH;
	this->Speed = Sp;
	this->Level = Lvl;
	this->Range = Rng;
}
int Weapon::getDamage() {
	return this->Damage;
}
void Weapon::setDamage(int d) {
	this->Damage = d;
}
int Weapon::getDefense() {
	return this->Defense;

}
void Weapon::setDefense(int d) {
	this->Defense = d;
}
bool Weapon::getTwoHanded() {
	return this->TwoHanded;
}
void Weapon::setTwoHanded(bool t) {
	this->TwoHanded = t;
}
int Weapon::getSpeed() {
	return this->Speed;
}
void Weapon::setSpeed(int s) {
	this->Speed = s;
}
int Weapon::getLevel() {
	return this->Level;
}
void Weapon::setLevel(int l) {
	this->Level = l;
}
int Weapon::getRange() {
	return this->Range;
}
void Weapon::setRange(int r) {
	this->Range = r;
};