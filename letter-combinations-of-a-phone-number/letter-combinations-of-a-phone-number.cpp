class Solution {
public:
    void gen(map<int, string> m, string digits, int index, vector<string> &ans, string temp){
        if(index == digits.length()){
            ans.emplace_back(temp);
            return;
        }
        
        
        string x = m[digits[index]-'0'];
     
        for(int i=0; i<x.length(); i++){
            temp = temp + x[i];
            gen(m, digits, index+1, ans, temp);
            temp.pop_back();
        }
        
    }
    
    vector<string> letterCombinations(string digits) {
        map<int,string> m;
        m[2] =  "abc";
        m[3] = "def";
        m[4] = "ghi";
        m[5] = "jkl";
        m[6] = "mno";
        m[7] = "pqrs";
        m[8] = "tuv";
        m[9] = "wxyz";
        
        vector<string> ans;
        string temp = "";
        if(digits.length() == 0){
            return ans;
        }
        
        gen(m, digits, 0, ans, temp);
        return ans;
    }
};