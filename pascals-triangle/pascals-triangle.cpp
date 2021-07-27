class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        if(numRows == 0){
            return ans;
        }
        
        vector<int> temp;
        temp.emplace_back(1);
        ans.emplace_back(temp);
        if(numRows == 1){
            return ans;
        }
        
        for(int i=2; i<=numRows; i++){
            temp.clear();
            for(int j=0; j<i; j++){
                if(j==0 || j==i-1){
                    temp.emplace_back(1);
                }
                else{
                    int val = ans[i-2][j] + ans[i-2][j-1];
                    temp.emplace_back(val);
                }
            }
            ans.emplace_back(temp);
        }
        return ans;
    }
};