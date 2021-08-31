// https://leetcode.com/problems/subarray-sum-equals-k/

#include <iostream>
#include <unordered_map>	// For Hashmaps
using namespace std;

int lengthOfLongestSubsetWithZeroSum(int* arr, int n) {
    // Write your code here
	
	int cumm_sum = 0;
	int max_sub_arr_len = 0;
	unordered_map<int, int> hashmap;

	// 1. Hash cumm_sum and its index.
	// 2. If cumm_sum already exists then calculate max_sub_arr_len.
	for(int i = 0; i < n; i++){
		
		// 2.0 Compute cummulative sum.
		cumm_sum += arr[i];

		// 2.1 If cumm_sum is 0 then sub_arr is till this index.
		if(cumm_sum == 0){
			int len = i + 1;
			
			if(len > max_sub_arr_len){
				max_sub_arr_len = len;
			}
		
		} 
		// 2.2 If cumm_sum is not in the hashmap then add it.
		else if(hashmap.count(cumm_sum) == 0){
			hashmap[cumm_sum] = i;
		
		} 
		// 2.3 If its there then compute length of sub_arr and compare.
		else {
			int start_index = hashmap[cumm_sum];
			int len = i - start_index;

			if(len > max_sub_arr_len){
				max_sub_arr_len = len;
			}
		}

	}

    return max_sub_arr_len;
}

int main(){

	// int arr[] = {95, -97, -387, -435, -5, -70, 897, 127, 23, 284};
	// int n = 10;

	int arr[] = {2, -2, 0, -2, 2};
	int n = 5;

	cout << lengthOfLongestSubsetWithZeroSum(arr, n) << endl;

	return 0;
}