//============================================================================
// Name        : hw07.cpp
// Author      : Jack Schmid
// Version     :
// Copyright   : Your copyright notice
// Description : Practice with double pointers, new and delete, and Dynamic Arrays, Ansi-style
//============================================================================

#include "hw07.h"

int main() {


	//Creating the receipt for Mark
	ManageInventory * preceipt = new ManageInventory(100);
	preceipt->addItem("Nike basketball shoes", 2, 145.99);
	preceipt->addItem("Under Armour T-shirt", 3, 29.99);
	preceipt->addItem("Nike shorts", 4, 45.77);
	preceipt->addItem("Brooks running shoes", 1, 111.44);
	//Calculating and printing the receipt for Mark
	preceipt->print();
	preceipt->printCost();
	cout << endl;

	//Instantiate manage inventory obj
	ManageInventory * pinv = new ManageInventory(100);
	//Add 5 items to manage inventory obj
	pinv->addItem("Nike basketball shoes", 22, 145.99);
	pinv->addItem("Under Armour T-shirt", 33, 29.99);
	pinv->addItem("Brooks running shoes", 11, 111.44);
	pinv->addItem("Asics running shoes", 20, 165.88);
	pinv->addItem("Nike shorts", 77, 45.77);

	//Inventory before Mark's purchase
	cout << "Inventory before Mark's purchase" << endl;
	pinv->print();
	cout << endl;
	//Adjust the inventory
	adjustInventory(*pinv, *preceipt);
	//Inventory after Mark's purchase
	cout << "Inventory after Mark's purchase" << endl;
	pinv->print();
	cout << endl;


	cout << "Original Inventory" << endl;
	pinv->print();
	cout << endl;
	//Copy pinv object
	ManageInventory * pinv2 = new ManageInventory(*pinv);
	cout << "Copied Inventory" << endl;
	pinv2->print();
	cout << endl;

	return 0;
}

//Declared as a friend function in ManageInventory.h so it can access ManageInventory private data
void adjustInventory(ManageInventory& source, ManageInventory& inv2){
	for(int i = 0; i < inv2.count; i++){
		for(int j = 0; j < source.count; j++){
			if(source.p_pInventoryItems[j]->name == inv2.p_pInventoryItems[i]->name){
				source.p_pInventoryItems[j]->quantity -= inv2.p_pInventoryItems[i]->quantity;
			}
		}
	}
}
