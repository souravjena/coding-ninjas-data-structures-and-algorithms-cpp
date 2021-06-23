#include <iostream>
using namespace std;
#include "lec_10_12_QueueArrayClass.h"

int main() {
	QueueUsingArray<int> q(5);

	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	q.enqueue(40);
	q.enqueue(50);
	q.enqueue(60);


	cout << q.front() << endl;
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;

	cout << q.getSize() << endl;
	cout << q.isEmpty() << endl << endl << endl;



	QueueUsingArray<int> q2(5);

	q2.enqueue_dyn(10);
	q2.enqueue_dyn(20);
	q2.enqueue_dyn(30);
	q2.enqueue_dyn(40);
	q2.enqueue_dyn(50);
	q2.enqueue_dyn(60);


	cout << q2.front() << endl;
	cout << q2.dequeue() << endl;
	cout << q2.dequeue() << endl;
	cout << q2.dequeue() << endl;

	cout << q2.getSize() << endl;
	cout << q2.isEmpty() << endl;
}

