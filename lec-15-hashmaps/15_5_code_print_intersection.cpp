#include <iostream>
#include <unordered_map>	// For Hashmaps
#include <algorithm>		// For sort()
using namespace std;

void printIntersection(int arr1[], int arr2[], int n, int m) {
    // Write your code here

	// 1. Sort arr1, as it is required by the problem.
	sort(arr1, arr1 + n);

	// 2. Put elements of arr2 and their freq in a hashmap.
	unordered_map<int, int> hashmap;

	for(int i = 0; i < m; i++){
		if(hashmap.count(arr2[i]) == 1){
			hashmap[arr2[i]] += 1;
		} else {
			hashmap[arr2[i]] = 1;
		}
	}


	// 3. Now iterate through sorted arr1 and check if it exists in the arr2-hashmap or not.
	// Decrease the freq of element by 1 in the arr2-hashmap once it is printed.
	// This is done so that multiple occurance of common elements can handled.
	// If an element is common and its freq is not 0 then print it.

	for(int j = 0; j < n; j++){

		if(hashmap[arr1[j]] > 0){
			cout << arr1[j] << endl;
			hashmap[arr1[j]] -= 1;
		}

	}

}

int main(){

	int arr1[] = {2, 6, 1, 2};
	int n1 = 4;

	int arr2[] = {1, 2, 3, 4, 2};
	int n2 = 5;

	printIntersection(arr1, arr2, n1, n2);
	
	return 0;
}