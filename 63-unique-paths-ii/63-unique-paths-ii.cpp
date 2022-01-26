class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int r=obstacleGrid.size();
        int c=obstacleGrid[0].size();
        
        int dp[r][c];
        memset(dp, 0, sizeof(dp));
        int i=0;
        while(i<r){
            if(obstacleGrid[i][0]==1){
                break;
            }
            else{
                dp[i][0]=1;
                i++;
            }
        }
        
        int j=0;
        while(j<c){
            if(obstacleGrid[0][j]==1){
                break;
            }
            else{
                dp[0][j]=1;
                j++;
            }
        }
        
        for(i=1; i<r; i++){
            for(j=1; j<c; j++){
                if(obstacleGrid[i][j]==1){
                    continue;
                }
                else{
                    dp[i][j] = dp[i-1][j]+dp[i][j-1];
                }
            }
        }
        return dp[r-1][c-1];
    }
};