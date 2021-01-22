class Solution {
public:
    string multiply(string num1, string num2) {
        int n=num1.size();
        int m=num2.size();
        
        vector<char> ans(n+m,'0');
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                int temp= ans[i+j+1]-'0';
                temp+= (num1[i]-'0')*(num2[j]-'0');
                int temp2= ans[i+j]-'0';
                temp2+=(temp/10);
                temp=temp%10;
                ans[i+j]= temp2+'0';
                ans[i+j+1]=temp+'0';
            }
        }
              
        int flag=0;
        int index=-1;
        for(int i=0;i<n+m;i++){
            if(ans[i]!='0'){
                flag=1;
                index=i;
                break;
            }
        }
        
        if(index==-1){
            return "0";
        }
        else{
            string res="";
            for(int i=index;i<n+m;i++){
                res+=ans[i];
            }
            return res;
        }
        
    }
};
