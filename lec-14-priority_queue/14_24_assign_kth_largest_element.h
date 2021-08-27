#include <queue>

int kthLargest(int* arr, int n, int k) {
    // Write your code here
    
    // vector<int> ans;
    int ans;
	priority_queue<int, vector<int>, greater<int>> min_pq;

	for(int i = 0; i < k; i++){
		min_pq.push(arr[i]);
	}


	for(int j = k; j < n; j++){

		if(arr[j] > min_pq.top()){
			min_pq.pop();
			min_pq.push(arr[j]);
		}
	}

	ans = min_pq.top();

	return ans;
}