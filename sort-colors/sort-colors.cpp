class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int pivot=1;
        int smaller=0, equal=0, larger=n;
        
        while(equal<larger){
            if(nums[equal]<pivot){
                swap(nums[equal++], nums[smaller++]);
            }
            else if(nums[equal]==pivot){
                equal++;
            }
            else{
                swap(nums[--larger], nums[equal]);
            }
        }
    }
};
