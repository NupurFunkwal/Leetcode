class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n);
        vector<int> ans(n);
        
        left[0] = 1;
        for(int i=1; i<n; i++){
            left[i] = left[i-1]* nums[i-1];
        }
        
        ans[n-1] = left[n-1];
        int prev = 1;
        for(int i=n-2; i>=0; i--){
            prev = prev*nums[i+1];
            ans[i] = left[i]*prev;      
        }
        
        return ans;
    }
};