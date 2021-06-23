#include <iostream>
#include <queue>
using namespace std;


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

    cout << q.front() << endl;
    cout << q.size() << endl;


    q.pop();
    print_queue(q);

    q.pop();
    print_queue(q);

    q.pop();
    print_queue(q);

}