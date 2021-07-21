class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int pos = n-2;
        while(pos>=0 && nums[pos]>=nums[pos+1]){
            pos--;
        }
        if(pos == -1){
            sort(nums.begin(), nums.end());
            return;
        }
        
        for(int i=n-1; i>pos; i--){
            if(nums[i]>nums[pos]){
                int temp = nums[pos];
                nums[pos] = nums[i];
                nums[i] = temp;
                break;
            }
        }
        
        sort(nums.begin()+pos+1,nums.end());
    }
};