class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if(n <2){
            return n;
        }
        int dp[n];
        for(int i=0; i<n; i++){
            dp[i] = 1;
        }
        dp[0] = 1;
        if(nums[0]== nums[1]){
            dp[1] = -1;
            if(n==2){
                return 1;
            }
        }
        else{
            if(n==2){
                return 2;
            }
            dp[1] = nums[0]-nums[1]>0? 2:-2;
        }
        
        int ans = 1;
        
        
        for(int i=2; i<n; i++){
            for(int j=i-1; j>=0; j--){
                if(nums[j]-nums[i]>0 && dp[j]<0){
                    if(abs(dp[i])<abs(dp[j])+1){
                        dp[i] = abs(dp[j])+1;
                    }         
                }
                else if(nums[j]-nums[i]<0 && dp[j]>0){
                    if(abs(dp[i])<abs(dp[j])+1){
                        dp[i] = -(abs(dp[j])+1);
                    }
                }
            }
        }
        for(int i=0; i<n;i++){
            ans= max(ans, abs(dp[i]));
        }
        return ans;
        
        
    }
};