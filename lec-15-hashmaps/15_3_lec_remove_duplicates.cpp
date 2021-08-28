#include <iostream>
#include <unordered_map>	// For Hashmaps
#include <vector>
using namespace std;

vector<int> removeDuplicates(int* arr, int arr_size){

	unordered_map<int, bool> hashmap;
	vector<int> ans;

	// 1. Iterate through the input array and place new elements in the hashmap.
	for(int i = 0; i < arr_size; i++){
		if(hashmap.count(arr[i]) == 0){
			hashmap[arr[i]] = true;
			ans.push_back(arr[i]);
		}
	}

	return ans;
}


int main(){

	int a[] = {1,2,3,3,2,1,4,3,6,5,5};
	
	vector<int> output = removeDuplicates(a, 11);
	
	for (int i = 0; i < output.size(); i++) {
		cout << output[i] << endl;
	}
}