class Solution {
public:
    int dp[101][10001];
    
    int solve(int k, int n) {
        //base case 
        if(n==1 || n==0){
            return n;
        }
        
        if(k==1){
            return n;
        }
        
        if(dp[k][n]!=-1){
            return dp[k][n];
        }
        
        int mini = INT_MAX;
        
        int beg=1, end=n;
        while(beg<=end){
            int i = beg+(end-beg)/2;
            
            int low = dp[k-1][i-1]!=-1 ? dp[k-1][i-1] : solve(k-1,i-1);
            int high = dp[k][n-i]!= -1 ? dp[k][n-i] : solve(k, n-i);
            
            int temp = 1+max(low, high);
            mini = min(mini, temp);
            
            if(low<high){
                beg = i+1;
            }
            else{
                end = i-1;
            }
        }
        return dp[k][n] = mini;
    }
    
    int superEggDrop(int k, int n){
        memset(dp, -1, sizeof(dp));
        return solve(k,n);
    }
};