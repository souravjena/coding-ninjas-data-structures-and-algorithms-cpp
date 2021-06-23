#include <iostream>
using namespace std;
#include "code_10_1_StackLLClass.cpp"

int main(){

    Stack s;

    s.push(13);
    s.push(47);

    s.print_LL();

    // cout << s.getSize() << endl;
    // cout << s.isEmpty() << endl;
    cout << s.pop() << endl;
    // cout << s.top() << endl;

    s.print_LL();

    
}