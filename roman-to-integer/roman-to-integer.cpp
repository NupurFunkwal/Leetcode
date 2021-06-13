class Solution {
public:
    int romanToInt(string s) {
        int n = s.length();
        int ans = 0 ;
    
        map<string, int> m;
        m["IV"] = 4;
        m["IX"] = 9;
        m["XL"] = 40;
        m["XC"] = 90;
        m["CD"] = 400;
        m["CM"] = 900;
        
        int p = 0, q = 1;
        while(p<n){
            if(m[s.substr(p,q-p+1)]){
                ans+= m[s.substr(p, q-p+1)];
                p = q+1;
                q = p+1;
            }
            else{
                switch(s[p]){
                    case 'I' : ans+=1;
                        break;
                    case 'V' : ans+=5;
                        break;
                    case 'X' : ans+=10;
                        break;
                    case 'L' : ans+=50;
                        break;
                    case 'C' : ans+=100;
                        break;
                    case 'D': ans+=500;
                        break;
                    case 'M': ans+=1000;
                        break;
                }
                p++;
                q++;
            }
            
        }
        
        return ans;
        
        
    }
};