class Solution {
public:
    bool check(vector<vector<char>> &board, int s_row, int e_row, int s_col, int e_col){
        bool count[9] = {false};
        for(int i=s_row; i<e_row; i++){
            for(int j=s_col; j<e_col; j++){
                if(board[i][j] != '.'){
                    if(count[board[i][j]-'1'] == true){
                        return false;
                    }
                    else{
                        count[board[i][j]-'1'] = true;
                    }
                }
            }
        }
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        //check rows
        for(int i=0; i<9; i++){
            if (check(board, i, i+1, 0, 9) == false){
                return false;
            }
        }
        
        //check cols
        for(int j=0; j<9; j++){
            if(check(board, 0, 9, j, j+1) == false){
                return false;
            }
        }
        
        //check blocks
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if(check(board, i*3, (i+1)*3, j*3, (j+1)*3) == false){
                    return false;
                }
            }
        }
        return true;
    }
        
};