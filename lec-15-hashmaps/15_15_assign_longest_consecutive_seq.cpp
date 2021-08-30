// https://leetcode.com/problems/longest-consecutive-sequence/

#include <iostream>
#include <unordered_map>	// For Hashmaps
#include <vector>
using namespace std;

vector<int> longestConsecutiveIncreasingSequence(int *arr, int n) {
    // Your Code goes here

	unordered_map<int, int> hashmap;
	vector<int> ans = {0, 0, 0}; 

	// 1. Hash your array.
	for(int i = 0; i < n; i++){
		hashmap[arr[i]] = 1;
	}

	// 2. Iterate through array and check if consecutive numbers are present or not.
	for(int j = 0; j < n; j++){
		
		int k = arr[j]+1;
		int count = 0;
		while(hashmap.count(k) == 1){
			count++;
			k++;
		}

		if(count > ans.at(1)){
			ans.at(1) = count;
            ans.at(0) = arr[j];
			ans.at(2) = k - 1;
		}
	}

	return ans;
}

int main(){

	int arr[] = {2, 12, 9, 16, 10, 5, 3, 20, 25, 11, 1, 8, 6};
	int n = 13;

	vector<int> ans = longestConsecutiveIncreasingSequence(arr, n);

	cout << ans.at(0) << " " << ans.at(2) << "\t count: " << ans.at(1) <<endl;

	return 0;
}