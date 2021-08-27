#include <iostream>
#include <queue>
using namespace std;


void sortKSortedArray(int arr[], int n, int k){

	/*
	- If the input array is k-sorted then max size of max-priority-queue required will be k.
	- We can push first k element of the input array in this max-pq.
	- Then pop element from this max-pq to get biggest remaining element in the max-pq.
	- Place this popped element in its correct position in the input array.
	- Add next element from the input array in this max-pq and repeat the process till elements in max-pq are exhausted.
	*/

	priority_queue<int> max_pq;
	int sorted_arr_index;

	// 1. Populate the initial max_pq.
	/*
	- Inserting k elements in a heap/max-pq will take klog(k) time.
	- Inserting one element -> log(k) time.
	*/
	for(int i = 0; i < k; i++){
		max_pq.push(arr[i]);
	}

	// 2. Pop max element and place it at its correct position.
	// and add the next element in the max-pq till all the elements are added in the max_pq.
	/*
	- Total elements in the heap/pq = k
	- Popping one element -> log(k) time
	- Here we are popping (n - k) elements. So time complexity here = (n - k)log(k)
	*/
	sorted_arr_index = 0;
	for(int j = k; j < n; j++){

		arr[sorted_arr_index] = max_pq.top();

		max_pq.pop();

		max_pq.push(arr[j]);

		sorted_arr_index++;
	}

	// 3. Pop the remaining element from max_pq and place them in the sorted part of the input array.
	/*
	- Popping k elements here.
	- Time Complexity = (k)log(k)
	*/
	while(max_pq.empty() == false){
		arr[sorted_arr_index] = max_pq.top();
		max_pq.pop();
		sorted_arr_index++;
	}


	/*
	- Total time complexity = (n + k)log(k)
	- k is typically small compared to n. So, (n + k)log(k) ~= (n)log(k)
	- (n)log(k) < (n)log(n)
	- nlog(n) is the time complexity to sort a normal unsorted array using heap-sort.
	*/

}


int main(){

    int arr[] = {10, 12, 6, 7, 9};	// a k-sorted array with k=3
    int k = 3;
    int n = 5;

    sortKSortedArray(arr, n, k);

    for(int i = 0; i < n; i++){
        cout << arr[i] << endl;
    }

    return 0;
}