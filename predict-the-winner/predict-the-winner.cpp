class Solution {
public:
    int dp[20][20];
    
    int findmax(vector<int> &nums, int i, int j){
        if(i>j){
            return 0;
        }
        if(dp[i][j]==0){
            dp[i][j] = max(nums[i] + min(findmax(nums, i+2, j), findmax(nums, i+1, j-1)), nums[j] + min(findmax(nums, i+1, j-1), findmax(nums, i, j-2)));
        }
        
        return dp[i][j];
        
    }
    
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            for(int j=0; j<n;j++){
                dp[i][j]=0;
            }
        }
        
        int score = findmax(nums, 0, n-1);
        int total=0;
        for(int i=0;i<n;i++){
            total+= nums[i];
        }
        
        if(total-score > score){
            return false;
        }
        return true;
        
    }
};