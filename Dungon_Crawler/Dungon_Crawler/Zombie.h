#include "Humanoid.h"



class Zombie : public Humanoid {
private:
	

	Weapon* weapon;


public:
	
	Zombie();
	
	Weapon* getWeapon();
	void setWeapon(Weapon* w);

	int Attack();

	int TakeDamage(int attack);


	void DisplayDetails();
	


};