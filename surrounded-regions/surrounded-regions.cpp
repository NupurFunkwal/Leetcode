class Solution {
public:
    class Coord{
        public:
        int x;
        int y;
        Coord(int a, int b){
            x = a;
            y = b;
        }
    };
    
    bool visited[200][200];
    
    bool isValid(vector<vector<char>>& board, int x, int y){
        int r = board.size();
        int c = board[0].size();
        
        if( x>=0 && x<r && y>=0 && y<c && board[x][y] == 'O' && !visited[x][y]){
            return true;
        }
        return false;
    }
    
    void bfs(int x, int y, vector<vector<char>>& board){
        visited[x][y] = true;
        Coord temp(x,y);
        queue<Coord> q;
        q.emplace(temp);
        
        int row[4] = {0,0,-1,1};
        int col[4] = {-1,1,0,0};
        
        while(q.empty() == false){
            Coord p = q.front();
            q.pop();
            
            for(int i=0; i<4;i++){
                if( isValid(board, p.x+row[i], p.y+col[i])){
                    Coord new_v(p.x+row[i], p.y+col[i]);
                    q.emplace(new_v);
                    visited[p.x+row[i]][p.y+col[i]] = true;
                }
            }
        }
    }
    
    void solve(vector<vector<char>>& board) {
        int r = board.size();
        int c = board[0].size();
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                visited[i][j] = false;
            }
        }
        
        //first and last col
        for(int i=0; i<r; i++){
            if(board[i][0] == 'O' && !visited[i][0]){
                bfs(i, 0, board);
            }
            if(board[i][c-1] == 'O' && !visited[i][c-1]){
                bfs(i, c-1, board);
            }
        }
        //first and last row
        for(int j=0; j<c; j++){
            if(board[0][j] == 'O' && !visited[0][j]){
                bfs(0, j, board);
            }
            if(board[r-1][j] == 'O' && !visited[r-1][j]){
                bfs(r-1, j, board);
            }
        }
        
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(board[i][j] == 'O' && !visited[i][j]){
                    board[i][j] = 'X';
                }
            }
        }
    }
};