class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> q;
        vector<int> ans;
        
        if(k>=n){
            int val=INT_MIN;
            for(int i=0; i<n; i++){
                val = max(val, nums[i]);
            }
            ans.emplace_back(val);
            return ans;
        }
        
        for(int i=0; i<k; i++){
            while(!q.empty() && nums[i]>=nums[q.back()]){
                q.pop_back();
            }
            
            q.push_back(i);
        }
        
        ans.push_back(nums[q.front()]);
        
        for(int i=k; i<n; i++){
            while(!q.empty() && nums[i]>=nums[q.back()]){
                q.pop_back();
            }
            
            while(!q.empty() && q.front()<=i-k){
                q.pop_front();
            }
            
            q.push_back(i);
            ans.push_back(nums[q.front()]);
        }
        
        return ans;
    }
};