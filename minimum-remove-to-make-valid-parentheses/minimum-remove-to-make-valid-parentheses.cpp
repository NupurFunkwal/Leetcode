class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.length();
        string ans = "";
        vector<int> pos;
        
        stack<int> st;
        for(int i=0; i<n; i++){
            if(s[i] == '('){
                st.push(i);
            }
            else if(s[i] == ')'){
                if(st.empty()){
                    pos.emplace_back(i);
                }
                else{
                    st.pop();
                }
            }
            else{
                continue;
            }
        }
        
        if(!st.empty()){
            while(!st.empty()){
                pos.emplace_back(st.top());
                st.pop();
            }   
        }
        sort(pos.begin(), pos.end());
        int j =0;
        for(int i=0; i<n; i++){
            if(j<pos.size() && i == pos[j]){
                j++;
                continue;
            }
            else{
                ans+= s[i];
            }
        }
        return ans;
    }
};