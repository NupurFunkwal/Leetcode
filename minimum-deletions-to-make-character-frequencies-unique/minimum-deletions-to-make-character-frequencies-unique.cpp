class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26,0);
        for(int i=0; i<s.length(); i++){
            freq[s[i]-'a']++;
        }

        map<int,int> m;
        for(int i=0; i<26; i++){
            if(freq[i]){
                m[freq[i]]++;
            }
        }
        int ans=0;
        
        for(auto it=m.rbegin(); it!=m.rend(); it++){
            if(it->first == 0){
                continue;
            }
            if(it->second>1){
                int num = (it->second)-1;
                it->second = 1;
                m[it->first-1] += num;
                ans += num;
            }
        }
        return ans;
    }
};