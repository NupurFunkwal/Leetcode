class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxi = nums[0];
        int ans = nums[0];
        int mini = nums[0];
        for(int i=1; i<n; i++){
            int temp = maxi;
            maxi = max(nums[i], max(maxi*nums[i], mini*nums[i]));
            mini = min(nums[i], min(temp*nums[i], mini*nums[i]));
            if(maxi>ans){
                ans = maxi;
            }
        }
        
        return ans;
    }
};