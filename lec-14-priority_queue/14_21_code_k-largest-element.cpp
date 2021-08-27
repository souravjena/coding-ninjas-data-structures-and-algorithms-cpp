#include <iostream>
#include <queue>
#include <vector>
using namespace std;


vector<int> kLargest(int arr[], int n, int k) {

	vector<int> ans;
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


	while(min_pq.empty() == false){
		ans.push_back(min_pq.top());
		min_pq.pop();
	}

	return ans;
}



int main(){

    int arr[] = {10, 1, 9, 8, 2};
    int k = 3;
    int n = 5;
    vector<int> v;

    v = kLargest(arr, n, k);

    for(int i = 0; i < v.size(); i++){
        cout << v.at(i) << endl;
    }

    return 0;
}
