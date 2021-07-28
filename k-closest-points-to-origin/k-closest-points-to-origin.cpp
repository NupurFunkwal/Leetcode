class Solution {
public:
    static double distance(int x, int y){
        return sqrt(pow(x,2) + pow(y,2));
    }
    
    struct Comp{
        bool operator()(const vector<int> &a, const vector<int> &b){
            return distance(a[0],a[1]) < distance(b[0],b[1]);
        }
    };
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        priority_queue<vector<int>, vector<vector<int>>, Comp> pq;
        
        int i=0;
        while(i<k && i<n){
            pq.emplace(points[i]);
            i++;
        }
        
        while(i<n){
            vector<int> temp = pq.top();
            if(distance(temp[0], temp[1]) > distance(points[i][0], points[i][1])){
                pq.pop();
                pq.emplace(points[i]);
            }
            i++;
        }
        
        vector<vector<int>> ans;
        while(!pq.empty()){
            ans.emplace_back(pq.top());
            pq.pop();
        }
        
        return ans;
    }
};