#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void print_queue(queue<int> q){
  
  while (!q.empty()){
    cout << q.front() << "->";
    q.pop();
  }
  
  cout << "." << endl;

}


int buyTicket(int *arr, int n, int k) {
    // Write your code here

	queue<int> q;
	priority_queue<int> max_pq;
	int j;			// iterator
	int t = 0;		// time counter

	// 1. Push indexes of the elements in the queue
	// 2. Prepare max-pq also.
	for(int i = 0; i < n; i++){
		q.push(i);
		max_pq.push(arr[i]);
		// cout << i << "\t" << arr[i] << endl;
	}

	j = 0;
	while(1){

		// print_queue(q);
		// cout << arr[j] << "\t" << max_pq.top() << endl;
		
		if(arr[j] == max_pq.top()){
			max_pq.pop();
			q.pop();
			t++;
		
		} else {
			// Push the index to the back of the queue
			int temp = q.front();
			q.pop();
			q.push(temp);
		}

		if( (q.front() == k) && (arr[k] == max_pq.top()) ){
			t++;
			break;
		}

		j++;
		if(j == n){
			j = 0;
		}
	}

	// print_queue(q);

	return t;
}


int main(){

	int arr[] = {2, 3, 2, 2, 4};
	int n = 5;
	int k = 3;		// Your Index

	// int arr[] = {3, 9, 4};
	// int n = 3;
	// int k = 2;		// Your Index

	cout << buyTicket(arr, n, k) << endl;

	return 0;
}