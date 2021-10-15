#include <iostream>
#include <climits>
using namespace std;

int helperCountMinStepsToOne(int n, int* arr_ans){
		
		int a = INT_MAX;
        int b = INT_MAX;
        int c = INT_MAX;
        
        // 1. Base Case
        if(n == 1){
            return 1;
        }
        
        // 2. Memoization
        if(arr_ans[n] != -1){
            return arr_ans[n];
        }
        
        // 3. Recursive Case
        a = helperCountMinStepsToOne(n - 1, arr_ans);
        
        if(n%3 == 0){
            b = helperCountMinStepsToOne(n/3, arr_ans);
        }
        
        if(n%2 == 0){
            c = helperCountMinStepsToOne(n/2, arr_ans);
        }
        
        // 4. Current Problem
        arr_ans[n] = 1 + min(a, min(b, c));
        return (arr_ans[n]);
}

int countMinStepsToOne(int n){
	
	int* arr_ans = new int[n + 1];
        
	for(int i = 0; i <= n; i++){
		arr_ans[i] = -1;
	}
        
        
	return helperCountMinStepsToOne(n, arr_ans);

}


int main(){

	cout << countMinStepsToOne(7) << endl;

	return 0;
}