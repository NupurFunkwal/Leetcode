class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int i=1;
        int count = 0;
        vector<vector<int>> ans(n, vector<int>(n,0));
        int x=0, y=0;
        int dir=0;
        int move[4][2] = {{0,1}, {1,0}, {0,-1},{-1,0}};
        
        while(count<n*n){
            ans[x][y]=i;
            i++;
            
            if(!(x+move[dir][0]>=0 && x+move[dir][0]<n && y+move[dir][1]>=0 && y+move[dir][1]<n && ans[x+move[dir][0]][y+move[dir][1]]==0)){
                dir = (dir+1)%4;
            }
            
            x+= move[dir][0];
            y+= move[dir][1];
            count++;
        }
        
        return ans;
    }
};