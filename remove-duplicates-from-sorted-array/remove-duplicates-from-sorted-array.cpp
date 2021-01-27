class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n= nums.size();
        int p=0;
        int q=1;
        if(n==0){
            return 0;
        }
        if(n==1){
            return 1;
        }
        
        while(q<n){
            if(nums[p]==nums[q]){
                q++;
            }
            else{
                nums[p+1]=nums[q];
                p++;
                q++;
            }
        }
        return p+1;
    }
};