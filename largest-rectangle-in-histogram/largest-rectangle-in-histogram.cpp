class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        
        vector<int> left(n,-1);
        vector<int> right(n,n);
        
        stack<int> s;
        
        //left
        for(int i=0; i<n; i++){
            if(s.empty()){
                s.push(i);
                continue;
            }
            else{
                while(!s.empty() && heights[s.top()]>=heights[i]){
                    s.pop();
                }
                if(s.empty()==true){
                    s.push(i);
                }
                else{
                    left[i] = s.top();
                    s.push(i);
                }
            }
        }
        
        while(!s.empty()){
            s.pop();
        }
        
        //right
        
        for(int j=n-1; j>=0; j--){
            if(s.empty()){
                s.push(j);
                continue;
            }
            else{
                while(!s.empty() && heights[s.top()]>=heights[j]){
                    s.pop();
                }
                if(s.empty()==true){
                    s.push(j);
                }
                else{
                    right[j] = s.top();
                    s.push(j);
                }
            }
        }
        
        int ans=0;
        for(int i=0; i<n; i++){
            ans = max(ans, (right[i]-left[i]-1)*heights[i]);
        }
            
        return ans;
            
    }
};