class Solution {
public:
    string multiply(string num1, string num2) {
        string ans="";
        int n1=num1.size();
        int n2=num2.size();
        int tmp=0;
        for (int i=n1-1;i>=0;--i){  ///
            for(int j=n2-1;j>=0;--j){
                int mul=(int)(num1[i]-'0')*(int)(num2[j]-'0');
                if (n1+n2-1-i-j>ans.size()){
                    
                    ans = to_string((mul+tmp)%10)+ans;   
                    tmp =(int)((mul+tmp)/10); 
                }
                else{
                    int tmp2=ans[ans.size()-(n1+n2-1-i-j)]-'0';
                    ans[ans.size()-(n1+n2-1-i-j)]=((ans[ans.size()-(n1+n2-1-i-j)]-'0')+mul+tmp)%10+'0';
                    tmp=(tmp2+mul+tmp)/10;
                }
                if(j==0 && tmp!=0){
                    if (n1+n2-i>ans.size()){
                        ans = to_string(tmp)+ans;     
                    }
                    else{
                        ans[ans.size()-(n1+n2-1-i-j)]=((ans[ans.size()-(n1+n2-1-i-j)]-'0')+tmp)%10+'0';
                    }    
                    tmp=0;
                }

            }
        }
        if (ans.size()>1){
            int n_zero=0;
            while (ans[n_zero]=='0' && n_zero<ans.size()-1){
                n_zero++;
            }
            string ans2(ans.begin()+n_zero,ans.end());
            return ans2;
        }
        return ans;
    }
};