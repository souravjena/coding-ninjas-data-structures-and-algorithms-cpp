// https://leetcode.com/problems/k-diff-pairs-in-an-array/

#include <iostream>
#include <unordered_map>	// For Hashmaps
using namespace std;

int getPairsWithDifferenceK(int *arr, int n, int k) {
	// Write your code here
    // ** My Approach **
    int count = 0;
	unordered_map<int, int> hashmap;
	unordered_map<int, int>::iterator it;	// Iterator for the hashmap

	// 1. Hash the array. <value, freq>
	for(int i = 0; i < n; i++){
		// If the element is already present.
		if(hashmap.count(arr[i]) == 1){
			// Update freq.
			hashmap[arr[i]] += 1;
		} else {
			hashmap[arr[i]] = 1;
		}
	}

	// 2. Iterate through the hashmap and find pairs.
	// Not iterating through the array because the array can have duplicate elements.
	// So taking account of that can be difficult.
	
	for(it = hashmap.begin(); it != hashmap.end(); it++){
		int num = it->first;
		int num_freq = it->second;
		int minus_num = num - k;

		// 2.1 Check minus_num in the hashmap
		if(hashmap.count(minus_num) == 1){
			int minus_num_freq = hashmap[minus_num];

			// 2.2 [#important] Update count
            if(minus_num == num){
                // nCr = (n * (n-1))/(1 * 2)
                count += (num_freq * (num_freq - 1))/2;
            } else {
              count += (num_freq * minus_num_freq);  
            }
			
		}

	}

	return count;
}


int main(){

	// int arr[] = {4, 4, 4, 4};
	// int n = 4;
	// int k = 0;

	int arr[] = {2, -1, 3, 5, 6, 0, -1, 2, 6};
	int n = 9;
	int k = 3;

	cout << getPairsWithDifferenceK(arr, n, k) << endl;

	return 0;
}