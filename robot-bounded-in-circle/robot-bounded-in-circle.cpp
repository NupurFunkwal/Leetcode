class Solution {
public:
    bool isRobotBounded(string instructions) {
        int n = instructions.length();
        int x=0, y=0;
        int dir = 0; //north
        
        int move[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        
        for(int i=0; i<n; i++){
            if(instructions[i] == 'R'){
                dir = (dir+1)%4;
            }
            else if(instructions[i] == 'L'){
                dir = (dir+3)%4;
            }
            else{
                x += move[dir][0];
                y += move[dir][1];
            }
        }
        
        if((x==0 && y==0) || dir!=0) {
            return true;
        }
        return false;
    }
};