class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        int flag = 0;
        int i=0, j=0;
        while(s[i] == ' '){
            i++;
        }
        while(s[i]!='\0' && i<n){
            if(s[i] == ' ' && flag==1){
                i++;
            }
            else if(s[i] == ' ' && flag == 0){
                flag =1;
                s[j] = s[i];
                i++;
                j++;
            }
            else if(s[i]!=' '){
                flag = 0;
                s[j] = s[i];
                i++;
                j++;
            }
                
            
        }
        
        if(s[j-1] == ' '){
            j = j-1;
        }
        s[j] = '\0';
        
        reverse(s.begin(), s.begin()+j);
        
        int k=0;
        for(int i=0; i<j; i++){
            if(s[i] == ' '){
                reverse(s.begin()+k, s.begin()+i);
                k = i+1;
            }
        }
        
        reverse(s.begin()+k, s.begin()+j);
        
        return s.substr(0,j);
    }
};