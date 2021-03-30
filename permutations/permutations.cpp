class Solution {
public:
    bool isValid(vector<int> &temp){
        if(temp.size() <= 1){
            return true;
        }
        int x = temp.size()-1;
        for(int i=0; i<x; i++){
            if(temp[i] == temp[x]){
                return false;
            }
        }
        return true;
    }
    void util(vector<vector<int>> &ans, vector<int> &nums, vector<int> &temp){
        if(temp.size() == nums.size()){
            ans.emplace_back(temp);
            return;
        }
        for(int i=0; i<nums.size(); i++){
            temp.emplace_back(nums[i]);
            if( isValid(temp) == true){
                util(ans, nums, temp);
            }
            temp.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        util(ans, nums, temp);
        return ans;
    }
};