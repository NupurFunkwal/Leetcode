class Solution {
public:
    int count = 0;
    bool isValid(vector<int> temp){
        int n = temp.size();
        for(int i=0; i<n-1; i++){
            if( abs(temp[i] - temp[n-1]) == (n-i-1) || temp[i]==temp[n-1]) {
                return false;
            }
        }
        return true;
    }
        
    void util(vector<int> &temp, int n){
        if(temp.size() == n){
            count++;
            return;
        }
        
        for(int j=0; j<n; j++){
            temp.emplace_back(j);
            if(isValid(temp) == true){
                util(temp, n);
            }
            temp.pop_back();
        }
    }
    
    int totalNQueens(int n) {
        vector<int> temp;
        util(temp, n);
        return count;
    }
};