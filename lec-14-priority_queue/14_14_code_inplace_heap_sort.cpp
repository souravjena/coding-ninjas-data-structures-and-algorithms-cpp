#include<iostream>
using namespace std;

int* create_min_order_tree(int arr[], int n) {
    // Write your code
    
    /*
    - (I) Rearrange the input array so that 
    - (a) CBT property is satisfied.
    - (b) Heap Order property is satisfied.
    */
    
    int parentIndex, childIndex;
    
    /*
    - Element at i=0 is in heap.
    - Insert element from i=1 onwards in this heap.
    */
    parentIndex = 0;
    
    for(int i = 1; i < n; i++){
    	
        childIndex = i;
        parentIndex = (childIndex - 1)/2;
		
        while(childIndex > 0){
            
            if(arr[parentIndex] > arr[childIndex]){
                // Swap
                int temp = arr[parentIndex];
                arr[parentIndex] = arr[childIndex];
                arr[childIndex] = temp;   
            } else {
                break;
            }

            childIndex = parentIndex;
            parentIndex = (childIndex - 1)/2;
        }
        
        
    }
    
    return arr;
}


int* sort_min_order_tree(int arr[], int n){

    int lastIndex = n - 1;

    // for(int i = 0; i < n; i++){
    //     cout << arr[i] << " ";
    // }
    // cout << endl;

    while(lastIndex > 0){

        // 1. Swap 1st (min) element with last element.
        int temp = arr[lastIndex];
        arr[lastIndex] = arr[0];
        arr[0] = temp;

        
        // 2. "Remove" last element now i.e the min-element.
        lastIndex -= 1;


        // 3. Rearrange elements in the new tree so that 
        // heap order property is maintained.
        // Move the new root element to its correct position in the tree.

        int parentIndex = 0;
        int leftChildIndex = 1;
        int rightChildIndex = 2;
        int minIndex = parentIndex;

        while(leftChildIndex <= lastIndex){

            // cout << "before: ";
            // for(int i = 0; i < n; i++){
            //     cout << arr[i] << " ";
            // }
            // cout << endl;


            minIndex = parentIndex;

            if(arr[leftChildIndex] < arr[minIndex]){
                minIndex = leftChildIndex;
            }

            if(rightChildIndex <= lastIndex){
                if(arr[rightChildIndex] < arr[minIndex]){
                    minIndex = rightChildIndex;
                }
            }

            if(parentIndex == minIndex){
                // element at its correct position in the tree.
                break;
            }

            // Swap
            int temp = arr[minIndex];
            arr[minIndex] = arr[parentIndex];
            arr[parentIndex] = temp;

            parentIndex = minIndex;
            leftChildIndex = (2*parentIndex) + 1;
            rightChildIndex = (2*parentIndex) + 2;

            // cout << "after: ";
            // for(int i = 0; i < n; i++){
            //     cout << arr[i] << " ";
            // }
            // cout << endl;


        }


    }

    return arr;
}


void heapSort(int arr[], int n) {

    arr = create_min_order_tree(arr, n);

    arr = sort_min_order_tree(arr, n);
}

int main(){

    int arr[] = {10, 5, 8, 1, 4};
    int n = 5;

    heapSort(arr, n);

    for(int i = 0; i < n; i++){
        cout << arr[i] << endl;
    }

    return 0;
}