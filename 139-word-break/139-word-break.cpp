class Solution {
public:
    unordered_map<string, bool> m;
    bool wordBreak(string s, vector<string>& wordDict) {
        //base case 
        if(find(wordDict.begin(), wordDict.end(), s)!=wordDict.end()){
            return true;
        }
        
        if(s.length()==1){
            return false;
        }
        
        int n = s.length();
        if(m.find(s)!=m.end()){
            return m[s];
        }
        
        for(int k=1; k<n; k++){
            bool c1 = wordBreak(s.substr(0,k), wordDict);
            bool c2 = wordBreak(s.substr(k,n-k), wordDict);
            
            if(c1 && c2){
                return m[s]=true;
            }
        }
        
        return m[s]=false;
    }
};