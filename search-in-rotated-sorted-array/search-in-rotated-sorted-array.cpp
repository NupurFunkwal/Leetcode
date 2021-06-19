class Solution {
public:
    int search(vector<int>& nums, int target) {
        int beg=0, end = nums.size()-1;
        if(nums.size() == 1){
            if(nums[0] == target){
                return 0;
            }
            else return -1;
        }
        
        while(beg<=end){
            int mid = beg + (end-beg)/2;
            
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] >= nums[beg]){
                if (nums[mid] > target && target >= nums[beg]){
                    end = mid-1;
                }
                else{
                    beg = mid+1;
                }
            }
            else if( nums[mid] < nums[beg]){
                if(nums[mid] < target && target <= nums[end]){
                    beg = mid+1;
                }
                else{
                    end = mid-1;
                }
            }
        }
        
        return -1;
    }
};