class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        vector<int> ans;
        
        int i=0, j=0;
        int beg_r=0, end_r=r-1;
        int beg_c=0, end_c=c-1;
        
        while(beg_r<=end_r && beg_c<=end_c){
            //left to right
            i=beg_r;
            j=beg_c;
            
            while(j<=end_c){
                ans.emplace_back(matrix[i][j]);
                j++;
            }
            j = end_c;
            i++;
            beg_r++;
            
            //top to bottom
            while(i<=end_r){
                ans.emplace_back(matrix[i][j]);
                i++;
            }
            i = end_r;
            j--;
            end_c--;
            
            if(beg_r>end_r || beg_c>end_c){
                break;
            }
            
            //right to left
            while(j>=beg_c){
                ans.emplace_back(matrix[i][j]);
                j--;
            }
            j = beg_c;
            i--;
            end_r--;
            
            //bottom to top
            while(i>=beg_r){
                ans.emplace_back(matrix[i][j]);
                i--;
            }
            j++;
            i=beg_r;
            beg_c++;
            
        }
        return ans;
    }
};