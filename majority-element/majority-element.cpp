class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int ans = nums[0];
        int count = 1;
        for(int i=1; i<n;){
            if(nums[i] == ans){
                count++;
                i++;
            }
            else{
                count--;
                if(count == 0){
                    ans = nums[i+1];
                    count = 1;
                    i = i+2;
                }
                else{
                    i = i+1;
                }
            }
        }
        return ans;
    }
};