#include <iostream>
#include <queue>
#include <vector>
using namespace std;


vector<int> kSmallestElements(int arr[], int n, int k) {

	vector<int> ans;
	priority_queue<int> max_pq;

	for(int i = 0; i < k; i++){
		max_pq.push(arr[i]);
	}


	for(int j = k; j < n; j++){

		if(arr[j] < max_pq.top()){
			max_pq.pop();
			max_pq.push(arr[j]);
		}
	}


	while(max_pq.empty() == false){
		ans.push_back(max_pq.top());
		max_pq.pop();
	}

	return ans;
}



int main(){

    int arr[] = {10, 1, 9, 8, 2};
    int k = 3;
    int n = 5;
    vector<int> v;

    v = kSmallestElements(arr, n, k);

    for(int i = 0; i < v.size(); i++){
        cout << v.at(i) << endl;
    }

    return 0;
}
