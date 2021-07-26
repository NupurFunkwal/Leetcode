class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        for(int i=0; i< n/2; i++){
            for(int j=0; j< (n+1)/2; j++){
                int temp = matrix[n-1-i][j];
                matrix[n-1-i][j] = matrix[n-1-j][n-1-i];
                matrix[n-1-j][n-1-i] = matrix[i][n-1-j];
                matrix[i][n-1-j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
    }
};