class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if(n==0){
            return 0;
        }
        
        vector<int> hash_index(128, -1);
        int left =0, right =0;
        int ans = 0;
        
        while(right<n){
            int x = hash_index[s[right]];
            if(x!=-1 && x>=left && x<right){
                left = x+1;
            }
            ans = max( ans, right-left+1);
            hash_index[s[right]] = right;
            right++;      
        }
        
        return ans;
    }
};