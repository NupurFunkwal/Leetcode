class Solution {
public:
    void generate(int index, string s, vector<string> &temp, vector<vector<string>> &ans){
        if(index == s.length()){
            ans.emplace_back(temp);
            return;
        }
        
        for(int i=index+1; i<=s.length(); i++){
            temp.emplace_back(s.substr(index, i-index));
            if(isPalin(s.substr(index,i-index)) == true){
                generate(i, s, temp, ans);
            }
            temp.pop_back();
        }
        
    }
    
    bool isPalin(string s){
        int n = s.length();
        for(int i=0, j=n-1; i<=j; i++, j--){
            if(s[i]!=s[j]){
                return false;
            }
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        generate(0, s, temp, ans);
        return ans;
        
    }
};