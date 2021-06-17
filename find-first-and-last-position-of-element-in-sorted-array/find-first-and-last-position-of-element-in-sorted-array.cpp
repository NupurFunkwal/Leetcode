class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        if(nums.size() == 0 || nums.size()==1 && nums[0]!=target){
            return {-1,-1};
        }
        else if(nums.size() == 1 && nums[0] == target){
            return {0,0};
        }
        int beg = 0, end = nums.size()-1;
        while(beg<=end){
            int mid = beg + (end-beg)/2;
            if(nums[mid]>target){
                end = mid-1;
            }
            else if(nums[mid]<target){
                beg = mid+1;
            }
            else{
                if(mid-1 >=0 && nums[mid-1]!=target || mid == 0){
                    ans.push_back(mid);
                    break;
                }
                else{
                    end = mid-1;
                }
            }
        }
        
        if(ans.size() == 0){
            ans.emplace_back(-1);
        }
        
        beg = 0, end = nums.size()-1;
        
        while(beg<=end){
            int mid = beg + (end-beg)/2;
            if(nums[mid]>target){
                end = mid-1;
            }
            else if(nums[mid]<target){
                beg = mid+1;
            }
            else{
                if((mid+1<=nums.size()-1 && nums[mid+1]!=target) || mid == nums.size()-1){
                    ans.push_back(mid);
                    break;
                }
                else{
                    beg = mid+1;
                }
            }
        }
        
        if(ans.size() ==1){
            ans.emplace_back(-1);
        }
        return ans;
    }
};