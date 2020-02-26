/*
 * ManageInventory.cpp
 *
 *  Created on: Feb 24, 2020
 *      Author: Jack
 */
#include "ManageInventory.h"
//Default ManageInventory constructor
ManageInventory::ManageInventory(){
	size = MAX_SIZE;
	count = 0;
	p_pInventoryItems = new Item*[size];
}
//Overloaded ManageInventory constructor
ManageInventory::ManageInventory(int size){
	this->size = size;
	count = 0;
	p_pInventoryItems = new Item*[size];
}
//ManageInventory copy constructor
ManageInventory::ManageInventory(const ManageInventory& source){
	size = source.size;
	count = 0;
	p_pInventoryItems = new Item*[size];
	//Loop through each value in the original's array in order to make a deep copy
	for(int i = 0; i < source.count; i++){
		p_pInventoryItems[i] = new Item{name, quantity, cost};
		count++;
	}
}
//ManageInventory destructor
ManageInventory::~ManageInventory(){
	for(int i = 0; i < count; i++){
		delete p_pInventoryItems[i];
	}
	delete[] p_pInventoryItems;
}
//Function to add a new Item into the p_pInventoryItems array
void ManageInventory::addItem(string name, int quantity, float cost){
	p_pInventoryItems[count] = new Item{name, quantity, cost};
	count++;
}
//Print out the values of a ManageInventory object
void ManageInventory::print(){
	cout << "Name of equipment \tCost \tQuantity\n-----------------------------------------\n";
	for(int i = 0; i < this->count; i++){
		cout << this->p_pInventoryItems[i]->name << "\t";
		cout << this->p_pInventoryItems[i]->cost << "\t";
		cout << this->p_pInventoryItems[i]->quantity << endl;
	}
}
//Print the total cost before and after tax for a ManageInventory object
void ManageInventory::printCost(){
	double total = 0;
	for(int i = 0; i < count; i++){
		for(int j = 0; j < p_pInventoryItems[i]->quantity; j++){
			total += p_pInventoryItems[i]->cost;
		}
	}
	cout << "Total Cost Before Tax: " << total << endl;
	cout << "Total Cost After Tax: " << total + (total * GlobalVariables::TAX) << endl;
}
