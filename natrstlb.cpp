#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
	
	srand(time(NULL));
	
	int row, col;
	do{
		cin>>row>>col;
	} while (row < 1 && col < 1);
	
	int** matrix = new int*[row];
	for (int i = 0; i < row; ++i) {
		matrix[i] = new int[col];
	}
	
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			matrix[i][j] = 10 - rand() % 21;
		}
	}
	
	cout << endl << "------" << endl << endl;
	
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	
	cout << endl << "------" << endl << endl;
	
	int sumRow = 0;
	for (int i = 0; i < row; ++i) {
		if(matrix[i][0] >= 0) {
			for (int j = 0; j < col; ++j) {
				sumRow = sumRow + matrix[i][j];	
			}
			cout << "Sum of #" << i + 1 << " row is: " << sumRow << endl;
			sumRow = 0;		
		} else {
			for (int j = 0; j < col; ++j) {
				sumRow = sumRow - matrix[i][j];
			}
			cout << "Difference of #" << i + 1 << " row is: " << sumRow << endl;
			sumRow = 0;
		}
	}
	
	return 0;
}
