#include <iostream>
#include "13_17_code_BST_class.h"
using namespace std;

int main(){

    BST b;
	b.insert(10);
	b.insert(5);
	b.insert(20);
	b.insert(7);
	b.insert(3);
	b.insert(15);
	b.print();

    cout << "____________" << endl;

    b.remove(10);
    b.print();

    return 0;
}