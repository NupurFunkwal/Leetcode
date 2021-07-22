class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum=0;
        int zeros = 0;
        for(int i=0; i<n; i++){
            sum += nums[i];
            if(nums[i] == 0){
                zeros++;
            }
        }
        
        if(target > sum || target<-sum){
            return 0;
        }
        
        int w = target+sum;
        if(w%2 != 0){
            return 0;
        }
        w = w/2;
        
        int dp[n+1][w+1];
        for(int i=0; i<=w; i++){
            dp[0][i] = 0;
        }
        
        for(int i=0; i<=n; i++){
            dp[i][0] = 1;
        }
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=w; j++){
                if(nums[i-1] == 0){
                    dp[i][j] = dp[i-1][j];
                }
                else if(nums[i-1] > j){
                    dp[i][j] = dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]];
                }
            }
        }
        
        return dp[n][w]*pow(2,zeros);
        
    }
};