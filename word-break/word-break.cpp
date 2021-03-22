class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> word_len(s.length(),-1);
        for(int i=0;i<s.length();i++){
            if(find(wordDict.begin(), wordDict.end(), s.substr(0, i+1)) != wordDict.end()){
                word_len[i] = i+1;
            }
            
            if(word_len[i] == -1){
                for(int j=0;j<i;j++){
                    if(word_len[j] != -1 && find(wordDict.begin(), wordDict.end(), s.substr(j+1, i-j)) != wordDict.end()){
                        word_len[i] = i-j;
                        break;
                    }
                }
            }    
        }
        
        if(word_len[s.length()-1] == -1){
            return false;
        }
        else return true;
    }
};