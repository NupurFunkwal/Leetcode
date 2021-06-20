class Solution {
public:
    int climbStairs(int n) {
        if(n == 0 || n==1){
            return n;
        }
        
        //int dp[n+1];
        int a = 1, b = 1;
        for(int i=2; i<=n; i++){
            int temp = a;
            a = b;
            b = b + temp;
        }
        
        return b;
    }
};