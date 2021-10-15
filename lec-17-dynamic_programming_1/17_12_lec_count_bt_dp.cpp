#include <iostream>
#include <cmath>
using namespace std;

int balancedBTs(int n) {
    // Write your code here

	// 1. Prepare DP array
	int* arr_dp = new int[n+1];
	

	// 2. 
	/* 
		count(h) = ans1 + ans2 + ans3

		ans1 = count(h-1) * count(h-2)
		ans2 = count(h-2) * count(h-2)
		ans3 = count(h-1) * count(h-1)
	*/

	/*
	arr_dp[0] = 0;
	arr_dp[1] = 1;
	arr_dp[2] = 3;

	for(int i = 3; i < n + 1; i++){

		int ans1 = arr_dp[i-1] * arr_dp[i-1];
		int ans2 = arr_dp[i-1] * arr_dp[i-2];
		int ans3 = arr_dp[i-2] * arr_dp[i-1];

		arr_dp[i] = ans1 + ans2 + ans3;
	}
	*/

	/*
		- The above solution won't work because the intermediate results of the multiplication will be
		  bigger than int that's why we will use modulo (10^9 +7).

		- (10^9 + 7 ) is a prime number. To be more precise, it is the first 10-digit prime number.

		- Printing your answer modulo (10^9 +7) ensures that it fits the maximum value your system 
		  is capable of storing in standard allotted space, preventing “integer overflow”, 
		  after which variables will begin to behave erratically, giving wrong answers. 
		  It is also consistent with the test code written by the question setter as well as case tester.
	*/

	arr_dp[0] = 0;
	arr_dp[1] = 1;
	arr_dp[2] = 3;

	int mod = (int)(pow(10, 7)) + 7; 

	for(int i = 3; i < n + 1; i++){

		int ans1 = (int)(((long) arr_dp[i-1] * arr_dp[i-1]) % mod);
		int ans2 = (int)(((long) arr_dp[i-1] * arr_dp[i-2]) % mod);
		int ans3 = (int)(((long) arr_dp[i-1] * arr_dp[i-2]) % mod);

		arr_dp[i] = ans1 + ans2 + ans3;
	}

	return arr_dp[n];
}



int main(){

	cout << balancedBTs(6) << endl;

}