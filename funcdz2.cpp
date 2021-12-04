#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void searchMinElements(int n, int m, int **matrix, int *array) {
	int min = matrix[0][0];
	for (int j = 0; j < m; j++) {
		for (int i = 0; i < n; i++) {
			if (matrix[i][j] < min) {
				min = matrix[i][j];
			}
		}
		array[j] = min;
		min = matrix[0][j+1];
	}
}

int main() {
	
	srand(time(NULL));
	
	int rows, cols;
	
	do{
		cout << "Enter the number of rows of your matrix: ";
 		cin >> rows;
		cout << endl;
	} while (rows <= 1);
	
	do{
		cout << "Enter the number of columns of your matrix: ";
 		cin >> cols;
		cout << endl;
	} while (cols <= 1);
	 
	int** matrix = new int*[rows];
	for (int i = 0; i < rows; ++i) {
		matrix[i] = new int[cols];
	}
	 
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			matrix[i][j] = rand() % 11;
		}
	}
	
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	
	cout << endl << endl;
	
	int* array = new int[cols];
	
	searchMinElements(rows, cols, matrix, array);
	
	for (int i = 0; i < cols; ++i) {
		cout << array[i] << " ";
	}
	
	cout<<endl;
	
	return 0;
}
