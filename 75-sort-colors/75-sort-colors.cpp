class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int beg=0, mid=0, last=n;
        
        while(mid<last){
            if(nums[mid]<1){
                swap(nums[beg++],nums[mid++]);
            }
            else if(nums[mid]>1){
                swap(nums[--last], nums[mid]);
            }
            else{
                mid++;
            }
        }
    
    }
};