class Solution {
public:
    int trap(vector<int>& nums) {
        int n = nums.size();
        if(n<=2){
            return 0;
        }
        vector<int> left(n,-1);
        vector<int> right(n,-1);
        stack<int> s;
        s.push(nums[0]);
        
        //left tallest
        for(int i=1; i<n; i++){
            if(nums[i] >= s.top()){
                left[i] = -1;
                s.push(nums[i]);
            }
            else{
                left[i] = s.top();
            }
        }
        
        while(s.empty() == false){
            s.pop();
        }
        
        s.push(nums[n-1]);
        
        //right tallest
        for(int i=n-2; i>=0; i--){
            if(nums[i] >=s.top()){
                right[i] = -1;
                s.push(nums[i]);
            }
            else{
                right[i] = s.top();
            }
        }
        
        //calculating water
        int ans = 0;
        
        for(int i=0; i<n; i++){
            if(left[i] == -1 || right[i] == -1){
                continue;
            }
            else{
                ans += min(left[i], right[i]) - nums[i];
            }
        }
        
        return ans;
              
    }
};