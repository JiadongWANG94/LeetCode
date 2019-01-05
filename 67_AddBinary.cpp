class Solution {
public:
    string addBinary(string a, string b) {
        //return toBinary(toTen(a)+toTen(b));
        int l1=a.size();
        int l2=b.size();
        string ans="";
        int arr[max(l1,l2)]={0};
        for (int i =0;i<l1;++i){
            arr[i]+=(a[l1-i-1]-'0');
        }
        for (int i =0;i<l2;++i){
            arr[i]+=(b[l2-i-1]-'0');
        }
        
        int tmp=0;
        for (int i=0;i<max(l1,l2);++i){
            arr[i]+=tmp;
            switch (arr[i]){
                case 0:{
                    ans="0"+ans;
                    tmp=0;
                    break;
                }
                case 1:{
                    ans="1"+ans;
                    tmp=0;    
                    break;
                }
                case 2:{
                    ans="0"+ans;
                    tmp=1;
                    break;
                }
                default:{
                    ans="1"+ans;
                    tmp=1;
                    break;
                }
            }
        }
        if (tmp==1)
            ans="1"+ans;
        return ans;
    }
private:
    long long toTen(string a){
        long long ans=0;
        long long n=a.size();
        for (long long i=0;i<n;++i){
            ans+=((a[i]-'0')*pow(2,n-1-i));
        }
        return ans;
    }
    string toBinary(long long n){
        string ans="";
        while (n>=2){
            ans = to_string(n%2)+ans;;
            n = n/2;
        }
        ans = to_string(n)+ans;;
        return ans;
    }
};