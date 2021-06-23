#include <iostream>
#include <stack>
using namespace std;

void PrintStack(stack<char> s)
{
    stack<char> temp;
    while (s.empty() == false)
    {
        temp.push(s.top());
        s.pop();
    }  
 
    while (temp.empty() == false)
    {
        char t = temp.top();
        cout << t << " ";
        temp.pop();
 
        // To restore contents of
        // the original stack.
        s.push(t); 
    }

    cout << endl;
}

int countBracketReversals(string input) {
	// Write your code here
    stack<char> s;
    unsigned int count_flips = 0;

    // 1. If len == odd return -1
    if(input.size() % 2 != 0){
        return -1;
    }

    // 2. Remove Balanced {} from the expression and push unbalanced {}
    for(int i = 0; i < input.size(); i++){

        if(s.empty() == false){

            // Remove Balanced {}
            if( (s.top() == '{') && (input[i] == '}') ){
                s.pop();
            
            } 
            // Push Unbalanced
            else {
                s.push(input[i]);
            }

        } else {
            s.push(input[i]);
        }

    }

    // 3. Now keep popping top 2 elements of unbalanced expression stack and see how many flips are required
    while(s.empty() == false){

        char b1 = s.top();
        s.pop();

        char b2 = s.top();
        s.pop();

        // {, { or }, } then 1 flip is required
        if(b1 == b2){
            count_flips += 1;
        } 
        
        // else you will have }{ which will required 2 flips.
        // Note: You can't have {} since it was removed in Step#2
        //       hence just an else is enough
        else {
            count_flips += 2;
        }

    }
    

    return count_flips;
}

int main(){

    string exp = "}}}{{{";

    cout << countBracketReversals(exp) << endl;

    return 0;
}