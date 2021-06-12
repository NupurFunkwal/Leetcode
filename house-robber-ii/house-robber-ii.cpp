class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return nums[0];
        }
        else if(n == 2){
            return max(nums[0], nums[1]);
        }
        int a = 0;
        int b = nums[0];
        int ans1, ans2;
        
        for(int i=2; i<n; i++){
            ans1 = max(b, nums[i-1]+a);
            a = b;
            b = ans1;
        }
        
        a = 0;
        b = nums[1];
        
        for(int i=3; i<=n; i++){
            ans2 = max(b, nums[i-1]+a);
            a = b;
            b = ans2;
        }
            
        return max(ans1, ans2);
    }
};