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
            temp.emplace_back(-s);
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
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        
        if(nums.size()<3){
            return result;
        }
        
        map<int, bool> m;
        set<vector<int>> res;
        
        for(int i=0; i<nums.size()-2; i++){
            if(m[nums[i]]!=true){
                m[nums[i]] = true;
            }
            else{
                continue;
            }
            int j = i+1, k = nums.size()-1;
            twosum(nums, j, k, -nums[i], res);
            
        }
        
        set<vector<int>> :: iterator it2;
        for( it2=res.begin(); it2!=res.end(); it2++){
            result.emplace_back(*it2);
        }
        return result;
        
       
    }
};
