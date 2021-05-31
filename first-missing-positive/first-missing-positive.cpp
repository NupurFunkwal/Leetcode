class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        int i=0;
        
        while(i<n){
            if(nums[i]<=0 || nums[i]>n){
                i++;
            }
            else{
                if(nums[i] != i+1 && nums[i]!=nums[nums[i]-1]){
                    //swap
                    int temp = nums[nums[i]-1];
                    nums[nums[i]-1] = nums[i];
                    nums[i] = temp;
                }
                else{
                    i++;
                }
            }
        }
        
        for(int j=0; j<n; j++){
            if(nums[j]!= j+1){
                return j+1;
            }
        }
        return n+1;
    }
};