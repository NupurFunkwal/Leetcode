class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        // sub reps a binary form
        for(int sub = 0; sub < 1<<nums.size(); sub++){
            int num = sub;
            vector<int> temp;
            while(num){
                temp.emplace_back(nums[log2(num & ~(num-1))]);
                num = num & (num-1);
            }
            ans.emplace_back(temp);
        }
        return ans;
    }
};