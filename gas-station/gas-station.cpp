class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int x =0;
        for(int i=0; i<n; i++){
            x = x+gas[i]-cost[i];
        }
        
        if(x<0){
            return -1;
        }
        
        int g=gas[0];
        int min = INT_MAX;
        int indices = -1;
        
        for(int i=1; i<n; i++){
            if(g -cost[i-1]<min){
                min = g-cost[i-1];
                indices = i;
            }
            g = g + gas[i]-cost[i-1];
            //cout<<"g="<<g<<endl;
        }
        
        if(g - cost[n-1]<min){
            indices = 0;
        }
        
        return indices;
        
    }
};