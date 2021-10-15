#include <iostream>
#include <cmath>
using namespace std;

int balancedBTs(int n) {
    // Write your code here

	// 1. Base Cases
	if(n <= 1){
		return 1;
	}


	// 2. Recursive Case

	/* 
		ans1 = ht(n-1) * ht(n-1)
		ans2 = ht(n-1) * ht(n-2)
		ans3 = ht(n-2) * ht(n-1)
		ans = ans1 + ans2 + ans3
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

	int mod = (int)(pow(10, 7)) + 7; 

	int x_1 = balancedBTs(n-1);
	int x_2 = balancedBTs(n-2);

	int intermediate_result_a = (int)(((long)x_1 * x_1) % mod);
	int intermediate_result_b = (int)(((long)x_1 * x_2) % mod);


	// 3. Current Problem
	int ans = intermediate_result_a + 2*intermediate_result_b;

	return ans;
}



int main(){

	cout << balancedBTs(6) << endl;

}