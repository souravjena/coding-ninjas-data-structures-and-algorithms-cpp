#include <iostream>
#include <stack>
using namespace std;

void PrintStack(stack<int> s)
{
    stack<int> temp;
    while (s.empty() == false)
    {
        temp.push(s.top());
        s.pop();
    }  
 
    while (temp.empty() == false)
    {
        int t = temp.top();
        cout << t << " ";
        temp.pop();
 
        // To restore contents of
        // the original stack.
        s.push(t); 
    }
}


// ** IMPORTANT **
// Check My Notes for Explanation
// My solution is very verbose for less verbose solution: https://www.geeksforgeeks.org/the-stock-span-problem/
int* stockSpan(int *price, int size)  {
	// Write your code here
    stack<int> s_element;
    stack<int> s_index;
    int *arr_span = new int[size];

    for(int i = 0; i < size; i++){
        
        int curr = price[i];

        if(s_element.empty() == false){

            if( curr < s_element.top() ){
                
                arr_span[i] = i - s_index.top();

                s_element.push(curr);
                s_index.push(i);
            
            } else {

                while( (s_element.empty() == false) && (curr > s_element.top()) ){
                    
                    s_element.pop();
                    s_index.pop();
                }

                if(s_element.empty() == false){
                    arr_span[i] = i - s_index.top();
                
                } else {
                    arr_span[i] = i + 1;
                }

                s_element.push(curr);
                s_index.push(i);

            } 

        
        } else {

            s_element.push(curr);
            s_index.push(i);

            arr_span[i] = 1;
        
        }

    }

    return arr_span;
}


int main(){

    int *ptr_arr_span = new int[7];
    // int arr_prices[7] = {100, 80, 60, 70, 60, 75, 85};
    // int size = 7;

    // 60 70 80 100 90 75 80 120
    int arr_prices[8] = {60, 70, 80, 100, 90, 75, 80, 120};
    int size = 8;

    ptr_arr_span = stockSpan(arr_prices, size);

    for(int i = 0; i < size; i++){
        cout << ptr_arr_span[i] << " ";
    }

    cout << endl;

    return 0;
}