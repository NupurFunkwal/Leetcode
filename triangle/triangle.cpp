class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int row = n-1;
        
        while(row>0){
            int col = triangle[row].size();
            for(int i=0; i<col-1; i++){
                triangle[row-1][i] += min(triangle[row][i], triangle[row][i+1]);
            }
            row--;
        }
        return triangle[0][0];
    }
};