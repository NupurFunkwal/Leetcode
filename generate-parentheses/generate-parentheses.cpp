class Solution {
public:
    void generate(int left, int right, string s, vector<string> &result){
        if(left == 0 && right ==0){
            result.emplace_back(s);
            return;
        }
        
        if(left>0){
            generate(left-1, right, s+'(', result);
        }
        
        if(left<right){
            generate(left, right-1, s+')', result);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string s = "";
        generate(n, n, s, result);
        return result;
    }
};