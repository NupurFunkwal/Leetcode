class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int r= obstacleGrid.size();
        int c= obstacleGrid[0].size();
        int dp[r][c];
        int xflag=0, yflag=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(obstacleGrid[i][j]==1){
                    dp[i][j]=0;
                    if(i==0){
                        xflag=1;
                    }
                    if(j==0){
                        yflag=1;
                    }
                }
                else{
                    if(i==0){
                        if(xflag==1){
                            dp[i][j]=0;
                        }
                        else{
                            dp[i][j]=1;
                        }
                    }
                    else if(j==0){
                        if(yflag==1){
                            dp[i][j]=0;
                        }
                        else{
                            dp[i][j]=1;
                        }
                    }
                    else{
                        if(dp[i-1][j]==0 && dp[i][j-1]==0){
                            dp[i][j]=0;
                        }
                        else if(dp[i-1][j]==0 && dp[i][j-1]!=0){
                            dp[i][j]=dp[i][j-1];
                        }
                        else if(dp[i-1][j]!=0 && dp[i][j-1]==0){
                            dp[i][j]=dp[i-1][j];
                        }
                        else{
                            dp[i][j]=dp[i-1][j]+dp[i][j-1];
                        }
                    }
                }
            }
        }
        return dp[r-1][c-1];
        
    }
};