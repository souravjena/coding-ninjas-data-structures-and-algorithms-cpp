#include <iostream>
#include <unordered_map>	// For Hashmaps
#include <vector>
#include <climits>
using namespace std;

int highestFrequency(int arr[], int n) {
    // Write your code here

	// <number, <1st-index, freq>>
	unordered_map<int, pair<int, int>> hashmap;
	int max_num = -1;
	int max_freq = -1;

	for(int i = 0; i < n; i++){

		// 1. If the current element exists in the Hashmap
		if(hashmap.count(arr[i]) == 1){
			// Update its freq.
			hashmap.at(arr[i]).second += 1;
		} 
		else {
			// 2. Else insert it and its index in the hashmap
			hashmap[arr[i]].second = 1;		// freq
			hashmap[arr[i]].first = i;		// index
		} 

		// 3. Compare current elements freq with current max-freq element.
		// 3.1 If two elements have same freq then select the element which occurs first in the array.
		if(hashmap.at(arr[i]).second == max_freq){
			if(hashmap.at(arr[i]).first < hashmap.at(max_num).first){
				max_num = arr[i];
			}
		}
		// 3.2 If freq of current element is greater then update max_num and max_freq
		else if(hashmap.at(arr[i]).second > max_freq){
			max_freq = hashmap.at(arr[i]).second;
			max_num = arr[i];
		}
	
	}

	return max_num;
}

int main(){

	int arr[] = {6, 2, 2, 12, 2, 11, 12, 2, 1, 2, 2, 11, 12, 2, 6, 6, 6, 6, 6, 6};
	int n = 20;

	// int arr[] = {1, 2, 2, 1};
	// int n = 4;
	
	cout << highestFrequency(arr, n) << endl;
}