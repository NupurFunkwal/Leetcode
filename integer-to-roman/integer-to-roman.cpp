class Solution {
public:
    string gen(int n, map<int, string> &m){
        vector<int> val = {1,5,10,50,100,500,1000};
        int d = 6;
        string ans="";
        
        while(n){
            if(val[d]>n){
                d--;
            }
            else{
                ans+=m[val[d]];
                n = n-val[d];
            }
        }
        return ans;
    }
    
    string intToRoman(int num) {
        string ans = "";
        map<int,string> m;
        m[1] = "I";
        m[4] = "IV";
        m[5] = "V";
        m[9] = "IX";
        m[10] = "X";
        m[40] = "XL";
        m[50] = "L";
        m[90] = "XC";
        m[100] = "C";
        m[400] = "CD";
        m[500] = "D";
        m[900] = "CM";
        m[1000] = "M";
        
        int pow = 1;
        
        while(num){
            int rem = num%10 *pow;
            if(m[rem]!=""){
                ans = m[rem]+ans;
            }
            else{
                ans = gen(rem,m)+ans;
            }
            pow*=10;
            num/=10;
        }
        
        return ans;
    }
};