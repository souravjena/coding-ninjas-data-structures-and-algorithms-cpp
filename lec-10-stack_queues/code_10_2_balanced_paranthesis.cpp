#include <iostream>
#include <stack>
using namespace std;

bool isBalanced(string expression) {
    // Write your code here
    
    stack<char> s;
    int size = expression.size();

    if(size % 2 != 0){
        return false;
    }
    

    for(int i = 0; i < size; i++){

        // Push Opening Brackets
        if(expression[i] == '('){
            s.push(expression[i]);
        }

        // Compare if Closing Bracket is encountered
        else if (expression[i] == ')') {
            
            // If a closing bracket without any opening bracket in stack
            if(s.empty() == 1){
                return false;
            }

            else{

                if(s.top() != '('){
                    return false;
                } else if (s.top() == '('){
                    s.pop();
                }

            }

        }
    }

    if(s.empty() == true){
        return true;
    } else {
        return false;
    }

}

int main(){

    string str = "(()(";
    // string str = "())(()";
    // string str = ")()()(";
    // string str = "))((";

    cout << isBalanced(str) << endl;

}