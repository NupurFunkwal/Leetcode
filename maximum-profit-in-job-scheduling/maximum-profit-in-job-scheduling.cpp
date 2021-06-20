class Solution {
public:
    struct Job{
        int start;
        int end;
        int profit;
        
        Job(int s, int e, int p){
            start = s;
            end = e;
            profit = p;
        }
    };
    
    static bool custom(Job const& a, Job const& b){
        if(a.end <= b.end){
            return true;
        }
        else return false;
    }
    
    int find(vector<Job> jobs, int i){
        int beg = 0, end = i-1;
        while(beg<=end){
            int mid = beg + (end-beg)/2;
            if(jobs[mid].end <= jobs[i].start){
                if(jobs[mid+1].end <= jobs[i].start){
                    beg = mid+1;
                }
                else return mid;
            }
            else{
                end = mid-1;
            }
        }
        return -1;
    }
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = profit.size();
        vector<Job> jobs;
        
        for(int i=0; i<n; i++){
            jobs.emplace_back(Job(startTime[i], endTime[i], profit[i]));
        }
        
        sort(jobs.begin(), jobs.end(), custom);
        sort(endTime.begin(), endTime.end());
        
        int dp[n];
        dp[0] = jobs[0].profit;
        
        for(int i=1; i<n; i++){
            vector<int>::iterator up;
            up = upper_bound(endTime.begin(), endTime.begin() + i, jobs[i].start);
            int prev_index = up - endTime.begin();
            
            if(prev_index == 0){
                dp[i] = max(dp[i-1], jobs[i].profit);
            }
            else{
                dp[i] = max(dp[i-1], jobs[i].profit + dp[prev_index-1]);
            }
        }
        return dp[n-1];

    }
};