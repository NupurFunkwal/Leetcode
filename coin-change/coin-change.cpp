class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        //unbounded knapsack
        
        int dp[n+1][amount+1];
        
        //initialization
        for(int i=0;i<=n;i++){
            dp[i][0] = 0;
        }
        for(int j=0;j<=amount;j++){
            dp[0][j] = INT_MAX;
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=amount;j++){
                if(coins[i-1]<=j){
                    if(dp[i][j-coins[i-1]]==INT_MAX){
                        dp[i][j] = dp[i-1][j];
                    }
                    else{
                        dp[i][j] = min(1+dp[i][j-coins[i-1]],dp[i-1][j]);
                    }
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        if(dp[n][amount]==INT_MAX){
            return -1;
        }
        else{
            return dp[n][amount];
        }
    }
};