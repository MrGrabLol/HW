#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int checkLength() {
	int len;
	do{
		cout << "Enter the number of rows and columns (rows = columns) of your matrix: ";
		cin >> len;
		cout << endl;
	} while (len <=1);
	
	return len;
}

void fillInMatrix(float **matrix, int len) {
	for (int i = 0; i < len; ++i) {
		for (int j = 0; j < len; ++j) {
			matrix[i][j] = 10 - rand() % 21;
		}
	}
}

void showMatrix(float **matrix, int len) {
	for (int i = 0; i < len; ++i) {
		for (int j = 0; j < len; ++j) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

bool countPosNeg (float **matrix, int len) {
	int counterPos = 0;
	int counterNeg = 0;
	for (int i = 0; i < len; ++i) {
		for (int j = 0; j < len; ++j) {
			if (matrix[i][j] >= 0) {
				counterPos++;
			} else {
				counterNeg++;
			}
		}
	}
	
	return counterNeg > counterPos? true : false;
}


float findAvg(float **matrix, int len) {
	float avg = 0;
	for (int i = 0; i < len; ++i) {
		for (int j = 0; j < len; ++j) {
			avg = avg + matrix[i][j];
		}
	}
	
	avg = avg / (len * len);
	
	return avg;
}

void changeMatrix(float **matrix, int len, float avg) {
	for (int i = 0; i < len; ++i) {
		for (int j = 0; j < len; ++j) {
			matrix[i][j] = matrix[i][j] + avg;
		}
	}
}


int main() {
	
	srand(time(NULL));
	
	int n = checkLength();
	
	float **matrix = new float*[n];
	for (int i = 0; i < n; ++i) {
		matrix[i] = new float[n];
	}
	
	fillInMatrix(matrix, n);
	
	showMatrix(matrix, n);
	
	float avg = findAvg(matrix, n);
	
	if (countPosNeg(matrix, n) == true) {
		changeMatrix(matrix, n, avg);
		cout << endl << "Here is modified matrix: " << endl << endl;
		showMatrix(matrix, n);
	} else {
		cout << endl << "No changes were made." << endl;
	}
	
	return 0;
}
