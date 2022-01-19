class Solution {
public:
    map<string, bool> m;
    
    string makeKey(string s1, string s2){
        string ans = ""; 
        ans += s1+"_"+s2;
        return ans;
    }
    bool isScramble(string s1, string s2) {
        //base cases
        if(s1.length()!=s2.length()){
            return false;
        }
        
        if(s1.compare(s2)==0){
            return true;
        }
        
        if(s1.length()==1){
            return false;
        }
        
        string key = makeKey(s1,s2);
        if(m.find(key)!=m.end()){
            return m[key];
        }
        
        int n = s1.length();
        
        for(int k=1; k<n; k++){
            //case 1: swapped at k
            bool c1 = isScramble(s1.substr(0,k), s2.substr(n-k,k)) && isScramble(s1.substr(k, n-k), s2.substr(0,n-k));
            
            //case 2: not swapped
            bool c2 = isScramble(s1.substr(0,k), s2.substr(0,k)) && isScramble(s1.substr(k, n-k), s2.substr(k, n-k));
            
            if(c1 || c2){
                return m[key]=true;
            }
        }
        
        return m[key]=false;
    }
};