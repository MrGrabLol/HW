#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
	
	srand(time(NULL));
	
	int n;
	do{
		cin >> n;
	} while (n <= 1);
	
	int** matrix = new int*[n];
	for (int i = 0; i < n; i++) {
		matrix[i] = new int[n];
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			matrix[i][j] = 10 - (rand() % 21);
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout<<matrix[i][j]<<" ";
		}
		cout << endl;
	}
	
	cout << endl << "---------" << endl << endl;
	
	int counterZero = 0;
	int counterPos = 0;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		if (matrix[i][0] > 1) {
			for (int j = 0; j < n; j++) {
				sum = sum + matrix[i][j];
				if (matrix[i][j] > 0) {
					counterPos++;
				} else if (matrix[i][j] == 0) {
					counterZero++;
				}
			}	
		}
	}
	
	if (counterPos == 0) {
		cout << "No positive elements have been found." << endl;
	} else {
		cout << "Number of positive elements: " << counterPos << endl;
	}
	if (counterZero == 0) {
		cout << "No elemets equal to zero have been found." << endl;
	} else {
		cout << "Number of zeros: " << counterZero << endl;
	}
	if (sum == 0) {
		cout << "There are no strings whose first element is greater than 1." << endl;
	} else {
		cout << "Total sum of all elements in strings that begin with >1: " << sum << endl;	
	}
	
	return 0;
}
