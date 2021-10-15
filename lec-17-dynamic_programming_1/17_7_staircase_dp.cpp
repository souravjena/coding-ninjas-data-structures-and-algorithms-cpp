// Leetcode #70: https://leetcode.com/problems/climbing-stairs/

class Solution {
public:
    /*
    - Dynamic Programming Approach
    
    - Base Cases
        - # ways to reach 1st-step from 0th-step = 1
        - # ways to reach 2nd-step
            - 1x 2-hop from 0th-step OR
            - 1x 1-hop from 1st-step
            - Therefore total ways = 2
    
    - Other Cases
        - # ways to reach 3rd-step
            - If we reach 2nd-step then we can make 1-hop to reach the 3rd-step
            - If we reach 1st tep then we can make 1x 2-hop to reach the 3rd-step
            - # ways to reach 3rd-step = # ways to reach 1st-step + # ways to reach 2nd-step
              because from these two steps we just need to do 1-hop or 2-hop.
    */
    
    int climbStairs(int n) {
        
        // Base Cases
        if(n == 1){
            return 1;
        }
        
        if(n == 2){
            return 2;
        }
        
        // DP
        int* arr_dp = new int[n+1];
        
        arr_dp[1] = 1;
        arr_dp[2] = 2;
        
        for(int i = 3; i <= n; i++){
            arr_dp[i] = arr_dp[i-1] + arr_dp[i-2];
        }
        
        return arr_dp[n];
    }
};