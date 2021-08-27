#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool isMaxHeap(int arr[], int n) {
    // Write your code here

	// max-heap Parent > Left Child, Right Child

    int parentIndex, leftChildIndex, rightChildIndex;
    int i = 0;
    parentIndex = i;
    leftChildIndex = 2*parentIndex + 1;
    rightChildIndex = 2*parentIndex + 2;

    while(leftChildIndex < n){

    	cout << "p: " << arr[parentIndex] << "\tl: " << arr[leftChildIndex] << "\tr: " << arr[rightChildIndex] << endl;

    	if( arr[parentIndex] < arr[leftChildIndex] ){
    		return false;
    	} 

    	if(rightChildIndex < n){
    		if(arr[parentIndex] < arr[rightChildIndex]){
    			return false;
    		}
    	}

    	i++;
    	parentIndex = i;
    	leftChildIndex = 2*parentIndex + 1;
    	rightChildIndex = 2*parentIndex + 2;
    }

    return true;
}


int main(){

    int arr[] = {42, 20, 18, 6, 14, 11, 9, 4};
    int n = 8;

    cout << isMaxHeap(arr, n) << endl;

    return 0;
}