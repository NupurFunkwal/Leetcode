class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        vector<int> ans;
        
        int s_row = 0, e_row = r-1, s_col = 0, e_col = c-1;
        
        while(s_row <= e_row && s_col <= e_col){
            //left to right
            for(int j = s_col; j <= e_col; j++){
                ans.emplace_back(matrix[s_row][j]);
            }        
            s_row++;
            
            if(s_row > e_row){
                break;
            }
            
            //top to bottom
            for(int i = s_row; i <= e_row; i++){
                ans.emplace_back(matrix[i][e_col]);
            }
            e_col--;
            
            if(e_col < s_col){
                break;
            }
            
            //right to left
            for(int j = e_col; j >= s_col; j--){
                ans.emplace_back(matrix[e_row][j]);
            }
            e_row--;
            
            if(e_row < s_row){
                break;
            }
            
            //bottom to top
            for(int i = e_row; i >= s_row; i--){
                ans.emplace_back(matrix[i][s_col]);
            }
            s_col++;
        }
        
        return ans;
    }
};