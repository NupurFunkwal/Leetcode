class Solution {
public:
    void util(int index, int time, vector<int> &manager, vector<int> &informTime, int &ans){
        if(index ==-1){
            ans = max(time,ans);
            return;
        }
        
        time+= informTime[index];
        util(manager[index], time, manager, informTime, ans);
    }
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        int ans=0;
        
        for(int i=0; i<n; i++){
            if(informTime[i]==0){
                util(i, 0, manager, informTime, ans);
            }
        }
        return ans;
    }
};