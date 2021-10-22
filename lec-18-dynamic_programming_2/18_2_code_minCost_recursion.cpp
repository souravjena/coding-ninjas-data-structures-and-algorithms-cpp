#include <iostream>
#include <climits>
using namespace std;


int helper_minCostPath(int **input, int m, int n, int start_row, int start_col){
	//Write your code here
	
	// 1. Base Case
	// If we reach the end-cell, we can directly return
	if(start_row == (m-1) && start_col == (n-1)){
		return input[start_row][start_col];
	}

	// If we go to a cell which is outside the 2D array
	if(start_row >= m || start_col >= n){
		return INT_MAX;
	}
	

	// 2. Recursive Case
	int from_right = helper_minCostPath(input, m, n, start_row, start_col + 1);
	int from_dig = helper_minCostPath(input, m, n, start_row + 1, start_col + 1);
	int from_down = helper_minCostPath(input, m, n, start_row + 1, start_col);


	// 3. Current Problem
	int ans = input[start_row][start_col] + min(from_right, min(from_dig, from_down));


	return ans;
}


int minCostPath(int **input, int m, int n){
	//Write your code here
	return helper_minCostPath(input, m, n, 0, 0);
}




int main() {
	int m, n;
	cin >> m >> n;
	int **input = new int*[m];
	for(int i = 0; i < m; i++) {
		input[i] = new int[n];
		for(int j = 0; j < n; j++) {
			cin >> input[i][j];
		}	
	}
	cout << minCostPath(input, m, n) << endl;
}