class Solution {
public:
    void twosum(vector<int> &nums, int &j, int &k, int s, set<vector<int>> &ans){
        if(j>=k){
            return;
        }
        if(nums[j]+nums[k] == s){
            vector<int> temp;
            temp.emplace_back(nums[j]);
            temp.emplace_back(nums[k]);
            ans.insert(temp);
            twosum(nums, ++j, k, s, ans);
            twosum(nums, j, --k, s, ans);         
        }
        else if(nums[j]+nums[k] < s){
            twosum(nums, ++j, k, s, ans);
        }
        else{
            twosum(nums, j, --k, s, ans);
        }
    }
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> ans;
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        
        if(nums.size()<3){
            return result;
        }
        
        map<int, bool> m;
        
        for(int i=0; i<nums.size()-2; i++){
            if(m[nums[i]]!=true){
                m[nums[i]] = true;
            }
            else{
                continue;
            }
            int j = i+1, k = nums.size()-1;
            set<vector<int>> res;
            twosum(nums, j, k, -nums[i], res);
            if(res.size() == 0){
                continue;
            }
            else{
                set<vector<int>> :: iterator it;
                for(it= res.begin(); it!= res.end(); it++){
                    vector<int> tempo = *it;
                    tempo.emplace_back(nums[i]);
                    ans.insert(tempo);
                }
            }
        }
        
        set<vector<int>> :: iterator it2;
        for( it2=ans.begin(); it2!=ans.end(); it2++){
            result.emplace_back(*it2);
        }
        return result;
        
       
    }
};