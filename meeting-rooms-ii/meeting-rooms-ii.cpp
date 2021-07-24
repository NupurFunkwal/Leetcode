class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> start, end;
        for(int i=0; i<intervals.size(); i++){
            start.emplace_back(intervals[i][0]);
            end.emplace_back(intervals[i][1]);
        }
        
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        
        int count = 0, ans = 0;
        
        int i=0, j=0;
        
        while(i != n){
            if(start[i]<end[j]){
                count++;
                ans = max(count, ans);
                i++;
            }
            else{
                count--;
                ans = max(count, ans);
                j++;
            }
        }
        
        return ans;
    }
};