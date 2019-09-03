#include "dungon_crawler.h"

class Item {

private:
string Name;
int Value;
int Weight;
int StackSize;


public:
	Item();
	string getName();
	void setName(string n);
	int getValue();
	void setValue(int v);
	int getWeight();
	void setWeight(int w);
	int getStackSize();
	void setStackSize(int s);


};