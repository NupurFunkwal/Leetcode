class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return 1;
        }
        
        int prevdiff = nums[1] - nums[0];
        int len = prevdiff != 0? 2 : 1;
        
        for(int i=2; i<n; i++){
            int diff = nums[i] - nums[i-1];
            if(prevdiff <= 0 && diff >0 || prevdiff>=0 && diff<0){
                len++;
                prevdiff = diff;
            }
        }
        return len;
    }
};