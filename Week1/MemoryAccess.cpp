#include <time.h>
#include <iostream>
using namespace std;

const int n  = 750;
float testData[n][n][n];

double diffClock(clock_t clock1, clock_t clock2) {
	double diffticks = clock1 - clock2; 
	double diffms = (diffticks * 10) / CLOCKS_PER_SEC;
	return diffms;
}

void row_ordered() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				testData[i][j][k] = 1;
			}
		}
	}
}
void column_ordered() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				testData[k][j][i] = 2;
			}
		}
	}
}
int main() {
	clock_t begin = clock();
	row_ordered();
	clock_t end = clock();
	cout << "Time elapsed (row): " << diffClock(end, begin) << " ms" << endl;

	begin = clock();
	column_ordered();
	end = clock();
	cout << "Time elapsed (col): " << diffClock(end, begin) << " ms" << endl;
}