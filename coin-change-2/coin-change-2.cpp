class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n= coins.size();
        //unbounded knapsack
        int dp[amount+1];
        
        for(int j=0;j<=amount;j++){
            dp[j] = 0;
        }
        dp[0]=1;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=amount;j++){
                if(coins[i-1]<=j){
                    dp[j] = dp[j] + dp[j-coins[i-1]];
                }
                else{
                    dp[j] = dp[j];
                }
            }
        }
        return dp[amount];
    }
};