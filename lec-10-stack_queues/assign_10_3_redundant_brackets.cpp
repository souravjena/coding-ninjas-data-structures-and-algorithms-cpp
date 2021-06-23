#include <iostream>
#include <stack>
using namespace std;

bool checkRedundantBrackets(string expression) {
	// Write your code here
    stack<char> s;
    unsigned int count_char = 0;

    for(int i = 0; i < expression.size(); i++){

        if(expression[i] != ')'){
            // cout << "Pushing: " << expression[i] << endl;
            s.push(expression[i]);
        
        } else {
            // If Closing Bracket is encountered.

            // Pop elements in the stack and check for valid expression between ( )
            while(s.empty() == false){
                
                /*
                    - Top is Opening Bracket -> Expression is complete
                    - a + (b): Redundant -> hence if char in the exp == 0  or 1 then return true.
                */
                if( (s.top() == '(') && (count_char <= 1) ){
                    return true;
                        
                } 
                
                /*
                    - Top is Opening Bracket -> Expression is complete
                    - If expression is complete then reset count_char
                */
                else if ( (s.top() == '(') && (count_char != 0) ){
                    count_char = 0;
                    // cout << "expression complete " << count_char << endl;

                } 
                
                /*
                    - Top is NOT Opening Bracket -> Count characters of the expression
                */
                else {
                    count_char++;
                }

                // cout << "Popping: " << s.top() << "\t" << count_char << endl;
                s.pop();
            }
        }
    }

    return false;
}

int main(){

    string exp = "a + (b + e) + c";

    cout << exp << endl;
    cout << checkRedundantBrackets(exp) << endl;

    return 0;
}