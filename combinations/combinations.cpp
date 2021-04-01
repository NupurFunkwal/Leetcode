class Solution {
public:
    void util(int index, int k, int n, vector<vector<int>> &ans, vector<int> &temp){
        if(temp.size() == k){
            ans.emplace_back(temp);
            return;
        }
        
        if(index>n){
            return;
        }
        //add index
        temp.emplace_back(index);
        util(index+1, k, n, ans, temp);
        temp.pop_back();
        util(index+1, k, n, ans, temp);
        
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> temp;
        util(1, k, n, ans, temp);
        return ans;
        
    }
};