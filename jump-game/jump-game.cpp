class Solution {
public:
    bool canJump(vector<int>& nums) {
        int last_index= nums.size()-1;
        int max_index=0;
        for(int i=0; i<=max_index && max_index<last_index; i++){
            max_index= max(max_index, nums[i]+i);
        }
        return max_index>=last_index;
        
    }
};
