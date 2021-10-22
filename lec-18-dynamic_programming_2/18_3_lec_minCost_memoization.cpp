#include <iostream>
#include <climits>
using namespace std;


int helper_minCostPath(int **arr_mem, int **input, int m, int n, int start_row, int start_col){
	//Write your code here
	
	int ans;

	// 1. Base Case
	// If we reach the end-cell, we can directly return
	if(start_row == (m-1) && start_col == (n-1)){
		return input[start_row][start_col];
	}

	// If we go to a cell which is outside the 2D array
	if(start_row >= m || start_col >= n){
		return INT_MAX;
	}
	

	// Memoization
	if(arr_mem[start_row][start_col] != -1){
		ans = arr_mem[start_row][start_col];
	
	} else {
		// Find the answer using recursion
		
		// 2. Recursive Case
		int from_right = helper_minCostPath(arr_mem, input, m, n, start_row, start_col + 1);
		int from_dig = helper_minCostPath(arr_mem, input, m, n, start_row + 1, start_col + 1);
		int from_down = helper_minCostPath(arr_mem, input, m, n, start_row + 1, start_col);

		// 3. Current Problem
		ans = input[start_row][start_col] + min(from_right, min(from_dig, from_down));

		arr_mem[start_row][start_col] = ans;
	}

	return ans;
}


int minCostPath(int **input, int m, int n){
	//Write your code here

	// Create a 2D mem array dynamically
	int** arr_mem = new int*[m];
	for(int i = 0; i < m; i++){
		arr_mem[i] = new int[n];
	}

	// Initilize it with -1
	for(int row = 0; row < m; row++){
		for(int col = 0; col < n; col++){
			arr_mem[row][col] = -1;
		}
	}

	return helper_minCostPath(arr_mem, input, m, n, 0, 0);
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