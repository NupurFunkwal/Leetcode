class Solution {
public:
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        stack<vector<int>> s;
        s.push(intervals[0]);
        
        for(int i=1; i<n; i++){
            vector<int> temp = s.top();
            if(intervals[i][0] <= temp[1]){
                s.pop();
                temp[1] = max(intervals[i][1], temp[1]);
                s.push(temp);
            }
            else{
                s.push(intervals[i]);
            }
        }
        
        vector<vector<int>> ans;
        while(!s.empty()){
            vector<int> t = s.top();
            s.pop();
            ans.emplace_back(t);
        }
        
        return ans;
    }
};