#include <iostream>
#include <unordered_map>	// For Hashmaps
#include <algorithm>		// For sort()
using namespace std;

int pairSum(int *arr, int n) {
	// Write your code here

	unordered_map<int, int> hashmap;
	int count = 0;

	for(int i = 0; i < n; i++){

		// 1. Check if (-1*curr) exists in the HM.
		if(hashmap.count(-1 * arr[i]) == 1){
			// curr can make pairs with all previous (-1*curr) elements
			// Hence we are incrementing count by freq of (-1*curr)
			count += hashmap[-1 * arr[i]];	
		}

		// 2. Update the freq of curr in the HM.
		if(hashmap.count(arr[i]) == 1){
			hashmap[arr[i]] += 1;
		} else {
			hashmap[arr[i]] = 1;
		}
	}

	return count;
}

int main(){

	int arr[] = {2, 1, -2, 2, 3};
	int n = 5;

	cout << pairSum(arr, n) << endl;
	
	return 0;
}