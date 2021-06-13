class Solution {
public:
    void gen(string s, string temp, int index, vector<string> &ans, int times){
        
        if(s.length()-index>=4 && times ==0 || index>=s.length()){
            return;
        }
        
        cout<<temp<<index<<times<<endl;
        if(times == 0){
            if(s[index] == '0' && index+1<s.length()){
                return;
            }
            int x = stoi(s.substr(index, s.length()-index));
            if(x>=0 && x<=255){
                temp+=s.substr(index, s.length()-index);
                ans.emplace_back(temp);
                return;
            }
            else{
                return;
            }
        }
        
        
        for(int i = index; i<index+3; i++){
            if(s[index] == '0' && i>index){
                break;
            }
            
            int x = stoi(s.substr(index, i-index+1));
            if(x>=0 && x<=255){
                temp +=s.substr(index, i-index+1);
                temp+=".";
                gen(s, temp, i+1, ans, times-1);
                int t = i-index+2;
                while(t--){
                    temp.pop_back();
                }     
            }
        }
        
    }
    
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        if(s.length()<4){
            return ans;
        }
        string temp ="";
        int times = 2;
        
        for(int i=0; i<=2; i++){
            if(s[0] == '0' && i!=0){
                break;
            }
            int x = stoi(s.substr(0, i+1));
            
            if(x>=0 && x<=255){
                temp += s.substr(0,i+1);
                temp+=".";
                gen(s, temp, i+1, ans, times);
                temp.clear();
            }   
        }
        return ans;
    }
};