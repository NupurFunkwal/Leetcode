class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        
        int diff = INT_MAX;
        int ans;
        
        for(int i=0; i<nums.size()-2; i++){
            int j=i+1, k = nums.size()-1;
            
            while(j<k){
                int sum = nums[i]+nums[j]+nums[k];
                if(sum-target == 0){
                    return sum;
                }
                
                if(abs(sum-target)<diff){
                    diff = abs(sum-target);
                    ans = sum;
                }
                if(sum<target){
                    j++;
                }
                else{
                    k--;
                }
            }
        }
        return ans;
    }
};