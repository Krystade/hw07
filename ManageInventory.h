/*
 * ManageInventory.h
 *
 *  Created on: Feb 24, 2020
 *      Author: Jack
 */

#ifndef MANAGEINVENTORY_H_
#define MANAGEINVENTORY_H_

#include <iostream>
using namespace std;
//User Defined namespace
namespace GlobalVariables{
	// 8.25% Sales Tax
	const double TAX = 0.0825;
}

struct Item
{
	string name;
	int quantity;
	float cost;
};

const int MAX_SIZE = 50;

class ManageInventory{
	//Declared as a friend function so it can access ManageInventory private data
	friend void adjustInventory(ManageInventory& inv1, ManageInventory& inv2);
	public:
	ManageInventory();
	ManageInventory(int size);
	ManageInventory(const ManageInventory&);
	~ManageInventory();
	void addItem(string name, int quantity, float cost);
	double calcCost();
	void print();
	void printCost();

	private:
	int size;
	int count;
	Item ** p_pInventoryItems;
};

#endif /* MANAGEINVENTORY_H_ */
