#include <iostream>
#include <stack>
using namespace std;

void reverseStack(stack<int> &input, stack<int> &extra) {
    //Write your code here
    /*
    Problem: Reverse the input stack using just one helper stack (extra stack).
    */

    // 1. Base Case
    if(input.empty() == true){
        return;
    }

    
    // 2. Current Problem
    int top_element = input.top();
    input.pop();

    
    // 3. Recursive Case
    // Except the top_element pass rest of the stack to recursion
    // Recursion will give you reversed sub stack in input_stack
    reverseStack(input, extra);

    // 2. Current Problem (contd.)
    // Put the reversed sub stack in input_stack into empty_stack
    while(input.empty() == false){
        extra.push(input.top());
        input.pop();
    }
    // Now input_stack is empty

    // Push the top_element in the empty input_stack
    input.push(top_element);

    // Push the elements from the empty_stack into input_stack
    while(extra.empty() == false){
        input.push(extra.top());
        extra.pop();
    }
}


int main(){

    stack<int> s_full;
    stack<int> s_empty;

    s_full.push(1);
    s_full.push(2);
    s_full.push(3);
    s_full.push(4);
    s_full.push(5);

    cout << s_full.top() << endl;

    reverseStack(s_full, s_empty);

    cout << s_full.top() << endl;

    return 0;
}