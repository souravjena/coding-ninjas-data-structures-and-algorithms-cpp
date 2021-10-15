#include <iostream>
#include <cmath>
using namespace std;

int minCount_resursive(int n){
	//Write your code here

	// Create a DP array
	int* dp = new int[n + 1];
	
	// Initialize the DP Array
	for(int i = 0; i < n + 1; i++){
		// Max steps to reach n is n; 1^2 + 1^2 .... n-times
		dp[i] = i;
	}
	
	
	// Compute min-steps to reach n
	for(int i = 1; i < (n + 1); i++){
			
		for(int j = 1; j <= sqrt(i); j++){
			dp[i] = min(dp[i], 1 + dp[i - (j*j)]);
			
		}
		
	}
	
	return dp[n];
    
}


int main(){

	cout << minCount_resursive(10) << endl;

	return 0;
}