#include <iostream>
#include <climits>
using namespace std;

int minCostPath(int **input, int m, int n){

	// 1. Create a 2D DP array
	int** arr_dp = new int*[n];
	for(int row = 0; row < m; row++){
		arr_dp[row] = new int[n];
	}

	// 2. End-cell value in DP arr will be same as
	// end-cell value in the input array
	arr_dp[m-1][n-1] = input[m-1][n-1];


	// 3. Start filling the 2D DP array

	// 3.1 Last row right to left (end-cell to first-cell of the last row)
	for(int col = (n - 1) - 1; col >= 0; col--){
		arr_dp[m-1][col] = arr_dp[m-1][col+1] + input[m-1][col];
	}

	// 3.2 Last col, bottom to top (end-cell to first-cell of the last col)
	for(int row = (m - 1) - 1; row >= 0; row--){
		arr_dp[row][n-1] = arr_dp[row+1][n-1] + input[row][n-1];
	}

	// 3.3 Remaining cells (right to left row-wise)
	for(int row = (m - 1) - 1; row >= 0; row--){
		for(int col = (n - 1) - 1; col >= 0; col--){
			arr_dp[row][col] = min(arr_dp[row][col+1], min(arr_dp[row+1][col], arr_dp[row+1][col+1])) + input[row][col];
		}
	}


	return arr_dp[0][0];
	
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