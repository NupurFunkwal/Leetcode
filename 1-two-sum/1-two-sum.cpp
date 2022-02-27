class Solution {
public:
    static bool custom(const pair<int,int> &a, const pair<int, int> &b){
        return a.second<b.second;
    }
    
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        vector<pair<int,int>> li;
        
        for(int i=0; i<nums.size(); i++){
            li.emplace_back(make_pair(i, nums[i]));
        }
        
        sort(li.begin(), li.end(), custom);
        
        int i=0, j=nums.size()-1;
        while(i<j){
            if(li[i].second+ li[j].second==target){
                ans.emplace_back(li[i].first);
                ans.emplace_back(li[j].first);
                return ans;
            }
            else if(li[i].second+li[j].second<target){
                i++;
            }
            else{
                j--;
            }
        }
        return ans;
    }
};