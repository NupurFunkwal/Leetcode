class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int min=0, sum=0, max_sum=INT_MIN, max=INT_MIN;
        
        for(int i=0; i<n; i++){
            if(sum+nums[i] <min){
                min = sum+nums[i];
            }
            
            sum+=nums[i];
            
            if(sum-min > max_sum){
                max_sum = sum-min;
            }
            
            if(max<nums[i]){
                max = nums[i];
            }
        }
        
        if(max_sum == 0){
            return max;
        }
        
        else return max_sum;
    }
};