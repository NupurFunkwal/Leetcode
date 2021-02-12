class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int min_sum=0, max_sum=0, sum=0;
        for(int i=0;i<n;i++){
            if(sum+nums[i]<min_sum){
                min_sum = sum+nums[i];
            }
            sum+=nums[i];
            if(max_sum<sum-min_sum){
                max_sum = sum-min_sum;
            }
        }
        if(max_sum==0){
            max_sum=INT_MIN;
            for(int i=0;i<n;i++){
                if(nums[i]>max_sum){
                    max_sum=nums[i];
                }
            }
        }
        return max_sum;
    }
};