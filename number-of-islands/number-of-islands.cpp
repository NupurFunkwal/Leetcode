class Solution {
public:
    int row[4] = {0,0,-1,1};
    int col[4] = {-1,1,0,0};
    
    void dfs(vector<vector<char>> &grid, int i, int j){
        int r= grid.size();
        int c= grid[0].size();
        grid[i][j] = '0';
        for(int x=0; x<4; x++){
            if( i+row[x]>=0 && i+row[x]<r && j+col[x]>=0 && j+col[x]<c && grid[i+row[x]][j+col[x]]=='1'){
                dfs(grid, i+row[x], j+col[x]);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>> visited;
        int r= grid.size();
        int c= grid[0].size();
        
        int count=0;
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(grid[i][j] == '1'){
                    count++;
                    dfs(grid, i, j);
                }
            }
        }
        // for(int i=0; i<r; i++){
        //     for(int j=0; j<c; j++){
        //         if(grid[i][j] == '1'){
        //             count++;
        //             dfs(grid, i, j);
        //             break;
        //         }
        //     }
        // }
        
        return count;
    }
};