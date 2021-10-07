#include <iostream>
using namespace std;


int helper_fib_memoization(int n, int* arr){

	int a, b, ans;

	// 1. Base Case
	if(n == 0 || n == 1){
		return n;
	}

	// 2. Memoization
	if(arr[n] != -1){
		return (arr[n]);
	}

	// 3. Recursive Calls
	// If answer doesnot exist get answer for fib(x) and
	// store it in the arr
	a = helper_fib_memoization(n-1, arr);
	b = helper_fib_memoization(n-2, arr);

	arr[n] = a + b;

	return arr[n];
}


int fib_memoization(int n){

	// 1. Create an array to store all the results of fib(x).
	int* arr_mem = new int[n + 1];

	// 2. Remove the garbage values form the array and
	// set the values as -1 to indicate that we don't yet know fib(x) for that index.
	for(int i = 0; i < n + 1; i++){
		arr_mem[i] = -1;
	}

	// 3. Call the helper function.
	return helper_fib_memoization(n, arr_mem);
}



int fib_recursion(int n){

	int a, b, ans;

	// 1. Base Case
	if(n == 0 || n == 1){
		return n;
	}

	// 2. Recursive Case
	a = fib_recursion(n-1);
	b = fib_recursion(n-2);

	// 3. Current Problem
	ans = a + b;

	return ans;
}


int main(){

	cout << fib_recursion(6) << endl << endl;
	
	cout << fib_memoization(0) << endl;
	cout << fib_memoization(1) << endl;
	cout << fib_memoization(2) << endl;
	cout << fib_memoization(3) << endl;
	cout << fib_memoization(4) << endl;
	cout << fib_memoization(5) << endl;
	cout << fib_memoization(6) << endl;

	return 0;
}