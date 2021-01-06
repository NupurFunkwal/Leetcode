class Solution {
public:
    bool subset_sum(int N, vector<int> A, int W){
        int dp[N+1][W+1];
        
        for(int i=0;i<=N;i++){
            for(int j=0;j<=W;j++){
                if(i==0){
                    dp[i][j]=0;
                }
                if(j==0){
                    dp[i][j]=1;
                }
            }
        }
        
        for(int i=1;i<=N;i++){
            for(int j=1;j<=W;j++){
                if(A[i-1]<=j){
                    dp[i][j]= (dp[i-1][j] || dp[i-1][j-A[i-1]]);
                }
                else{
                    dp[i][j]= dp[i-1][j];
                }
            }
        }
        
        return dp[N][W];
    }
    
    bool canPartition(vector<int>& nums) {
        int N=nums.size();
        
        int sum=0;
        for(int i=0;i<N;i++){
            sum+=nums[i];
        }
        
        if(sum%2==1){
            return 0;
        }
        else{
            return subset_sum(N, nums, sum/2);
        }
            
    }
};
