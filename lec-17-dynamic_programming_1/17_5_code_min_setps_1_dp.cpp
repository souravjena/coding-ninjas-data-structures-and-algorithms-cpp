class Solution {
public:
    /*
    ** Dynamic Programming Approach
    */

    int minDays(int n) {
        
        // 1. Handle Edge Cases
        switch(n){
            case 1: return 1;
            case 2: return 2;
            case 3: return 2;
        };
        
        // 2. Create DP Array
        int* arr_ans = new int[n + 1];
        
        // 3. Store Initial Values
        // arr_ans[0] = 0;
        arr_ans[1] = 1;
        arr_ans[2] = 2;
        arr_ans[3] = 2;
        
        // 4. Bottom Up
        for(int i = 4; i <= n; i++){
            
            int a = INT_MAX;
            int b = INT_MAX;
            int c = INT_MAX;
            
            a = arr_ans[i-1];
            
            if(i%3 == 0){
                b = arr_ans[i/3];
            }
            
            if(i%2 == 0){
                c = arr_ans[i/2];
            }
            
            arr_ans[i] = 1 + min(a, min(b, c));    
        }
        
        return arr_ans[n];
        
    }
};