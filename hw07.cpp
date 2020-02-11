//============================================================================
// Name        : Hw7.cpp
// Author      : Jack Schmid
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "Hw7.h"

int Sum(int **p, int r, int c){
	int i, j, sum = 0;
	for(i = 0; i < r; i++){
		for(j = 0; j < c; ++j){
			sum += *( *(p+i) + j);
		}
	}
	return sum;
}

int main() {
	char *name;
	name = new char[8];
	strcpy(name, "Tas A"); // Need to #include <string.h>
	cout << name;
	delete [] name;
	int **A;
	A = new int *[5];
	for(int i = 0; i < 8; i ++){
		A[i] = new int[8];
	}
	int s = Sum(A, 5, 8);
	cout << s;
	for(int i = 0; i < 5; i++){
		delete [] A[i];
	}
	delete [] A;
	return 0;
}
