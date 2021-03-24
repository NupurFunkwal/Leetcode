class Solution {
public:
    bool isValid(vector<int> &config){
        int n = config.size()-1;
        for(int i=0; i<n; i++){
            if(config[n]-config[i] == 0 || abs(config[n]-config[i]) == n-i){
                return false;
            }
        }
        return true;
    }
    
    void util(int n, int row, vector<int> &config, vector<vector<int>> &ans){
        if(row == n){
            ans.emplace_back(config);
            return;
        }
        else{
            for(int i=0; i<n; i++){
                config.emplace_back(i);
                if(isValid(config) == true){
                    util(n, row+1, config, ans);
                }
                config.pop_back();
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        
        vector<vector<int>> ans;
        vector<int> config;
        util(n, 0, config, ans);
        vector<vector<string>> result;
        
        if(n==2 || n==3){
            result.clear();
            return result;
        }
        
        int r= ans.size();
        int c= ans[0].size();
        for(int i=0; i<r; i++){
            vector<string> line;
            for(int j=0; j<c; j++){
                string temp = "";
                for(int k=0; k<n; k++){
                    if(ans[i][j] == k){
                        temp+= "Q";
                    }
                    else{
                        temp+=".";
                    }
                }
                line.emplace_back(temp);
            }
            result.emplace_back(line);
        }
        return result;
    }
};