#include <iostream>
#include <queue>
using namespace std;

void reverseQueue(queue<int> &input) {
	// Write your code here

    /*
    ** Reverse a Queue without using any other data structure. **
    */

    // 1. Base Case
    if(input.empty() == true){
        return;
    }

    // 2. Recursive Case
    int front_element = input.front();
    input.pop();

    reverseQueue(input);

    // 3. Current Problem
    input.push(front_element);

}

void print_queue(queue<int> q){
  
  while (!q.empty()){
    cout << q.front() << "->";
    q.pop();
  }
  
  cout << "." << endl;

}


int main(){

    queue<int> q;

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    print_queue(q);

    reverseQueue(q);

    print_queue(q);
}