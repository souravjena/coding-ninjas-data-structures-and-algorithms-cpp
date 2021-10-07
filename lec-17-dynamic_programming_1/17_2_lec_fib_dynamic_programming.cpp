#include <iostream>
using namespace std;

int fib_dynamic_programming(int n){

	// 1. Create an array to store previous answers.
	int* ans = new int[n + 1];

	// 2. Store initial previous answers.
	ans[0] = 0;
	ans[1] = 1;

	// 3. Compute & store next answers
	for(int i = 2; i <= n; i++){
		ans[i] = ans[i-1] + ans[i-2];
	}

	return ans[n];
}

int main(){

	cout << fib_dynamic_programming(0) << endl;
	cout << fib_dynamic_programming(1) << endl;
	cout << fib_dynamic_programming(2) << endl;
	cout << fib_dynamic_programming(3) << endl;
	cout << fib_dynamic_programming(4) << endl;
	cout << fib_dynamic_programming(5) << endl;
	cout << fib_dynamic_programming(6) << endl;

	return 0;
}