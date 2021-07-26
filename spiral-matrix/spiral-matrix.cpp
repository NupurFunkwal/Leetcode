class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        int dir = 0;
        int x = 0, y = 0;
        int move[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<int> ans;
        
        int i = 0;
        while( i < r*c){
            ans.emplace_back(matrix[x][y]);
            matrix[x][y] = 0;
            
            if (!( x+move[dir][0] >= 0 && x+move[dir][0] < r && y+move[dir][1] >= 0 && y+move[dir][1] < c && matrix[x+move[dir][0]][y+move[dir][1]] != 0)){
                dir = (dir+1)%4;
            }
            
            x += move[dir][0];
            y += move[dir][1];
            i++;
        }
        
        return ans;
    }
};