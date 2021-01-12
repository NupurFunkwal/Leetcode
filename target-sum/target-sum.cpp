class Solution {
public:
    
    int subset_sum(vector<int> arr, int n, int W){
        int dp[n+1][W+1];   //storing count of subsets with given sum
        
        //initialization
        for(int j=0;j<=W;j++){
            dp[0][j]=0;
        }
        for(int i=0;i<=n;i++){
            dp[i][0]=1;
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=W;j++){
                if(arr[i-1]==0){
                    dp[i][j]= dp[i-1][j];
                }
                else if(arr[i-1]<=j){
                    dp[i][j]= dp[i-1][j] + dp[i-1][j-arr[i-1]];
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        
        return dp[n][W];
        
    }
    
    int findTargetSumWays(vector<int>& nums, int S) {
        int n=nums.size();
        
        int sum= 0;
        int zero=0;
        for(int i=0;i<n;i++){
            sum+= nums[i];
            if(nums[i]==0){
                zero++;
            }
        }
        
        if(S>sum || S<-sum){
            return 0;
        }
        
        if((S+sum)%2!=0){
            return 0;
        }
        int s_val= (S+sum)/2;
        return pow(2,zero)*subset_sum(nums, n, s_val);
               
    }
};
