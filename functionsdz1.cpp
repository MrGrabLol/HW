#include <iostream>
#include <math.h>
#include <ctime>
#include <cstdlib>

using namespace std;

int changeAllNegative(int array[], int size) {
	int counter = 0;
	for (int i = 0; i < size; ++i) {
		if (array[i] < 0) {
			counter++;
			array[i] = abs(array[i]);
		}
	}
	return counter;
}

int main() {
	
	srand(time(NULL));
	
	int n, m;
	
	do{
		cout << "Enter the length of array 1: ";
		cin>>n;
		cout << endl;
	} while (n <= 1);
	
	do{
		cout << "Enter the length of array 2: ";
		cin>>m;
		cout << endl;
	} while (m <= 1);
	
	int* array1 = new int[n];
	int* array2 = new int[m];
	
	for (int i = 0; i < n; ++i) {
		array1[i] = 10 - rand() % 21;
	}
	
	for (int i = 0; i < m; ++i) {
		array2[i] = 10 - rand() % 21;
	}
	
	for (int i = 0; i < n; ++i) {
		cout << array1[i] << " ";
	}
	
	cout << endl << endl;
	
	for (int i = 0; i < m; ++i) {
		cout << array2[i] << " ";
	}
	
	int counter1 = changeAllNegative(array1, n);
	int counter2 = changeAllNegative(array2, m);
	
	cout << endl << endl << "---------" << endl << endl;
	cout << "Number of changes in array #1 is: " << counter1 << endl << endl;
	cout << "Number of changes in array #2 is: " << counter2 << endl << endl;
	cout << "---------" << endl << endl;
	
	for (int i = 0; i < n; ++i) {
		cout << array1[i] << " ";
	}
	
	cout << endl << endl;
	
	for (int i = 0; i < m; ++i) {
		cout << array2[i] << " ";
	}
	
	if (n == counter1) {
		cout << endl << endl << "The number of changes in array #1 is equal to its size." << endl;
	}
	
	if (m == counter2) {
		cout << endl << endl <<"The number of changes in array #2 is equal to its size." << endl;
	}
	
	if (counter1 == 0 && counter2 == 0) {
		cout << endl << endl << "There were no changes in given arrays." << endl;
	}
	return 0;
}
