#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void printRunningMedian(int *arr, int n) {
    // Write your code here

	// Leetcode 295 - Hard
    // https://leetcode.com/problems/find-median-from-data-stream/
    
    priority_queue<int, vector<int>, greater<int>> min_pq;
	priority_queue<int> max_pq;
	
    // Handle Edge Case
    if(n == 0){
        return;
    }
    
	max_pq.push(arr[0]);
	// cout << "Median #0: " << max_pq.top() << endl << endl;
    cout << max_pq.top() << " ";

	for(int i = 1; i < n; i++){

		if(arr[i] > max_pq.top()){
				// cout << "pushing in min-heap: " << arr[i] << endl;
				min_pq.push(arr[i]);
			} else {
				// cout << "pushing in max-heap: " << arr[i] << endl;
				max_pq.push(arr[i]);
		}

		if( ((i+1) % 2) == 0 ){
			// Even # elements in the stream
			if(max_pq.size() - min_pq.size() != 0){
				// reshuffle
				if(max_pq.size() > min_pq.size()){
					min_pq.push(max_pq.top());
					max_pq.pop();
					// cout << "even min-heap top: " << min_pq.top() << endl;
				} else {
					max_pq.push(min_pq.top());
					min_pq.pop();
					// cout << "even max-heap top: " << max_pq.top() << endl;
				}
			}
			
			// cout << "Median #" << i << ": " << (max_pq.top() + min_pq.top())/2 << endl << endl;
            cout << (max_pq.top() + min_pq.top())/2 << " ";

		} else {
			// Odd # elements in the stream
			if( (max_pq.size() - min_pq.size() != 1) || (min_pq.size() - max_pq.size() != 1)){
				// reshuffle
				if(max_pq.size() > min_pq.size()){
					min_pq.push(max_pq.top());
					max_pq.pop();
					// cout << "odd min-heap top: " << min_pq.top() << endl;
				} else {
					max_pq.push(min_pq.top());
					min_pq.pop();
					// cout << "odd max-heap top: " << max_pq.top() << endl;
				}
			}

			if(max_pq.size() > min_pq.size()){
				// cout << "Median #" << i << ": " << max_pq.top() << endl << endl;
                cout << max_pq.top() << " ";
			} else {
				// cout << "Median #" << i << ": " << min_pq.top() << endl << endl;
                cout << min_pq.top() << " ";
			}
		}
	}
	
}


int main(){

	// int arr[] = {7, 2, 8, 3, 1, 5};
	int arr[] = {6, 2, 1, 3, 7, 5};
	int n = 6;

	printRunningMedian(arr, n);

	return 0;
}