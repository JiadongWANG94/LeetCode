class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string comm="";
        int n = strs.size();
        if (n==0) return comm;
        if (n==1) return strs[0];
        string tmp=strs[0];
        for (int i=1;i<n;++i){
            tmp = CommonPrefix(strs[i],tmp);
            if (tmp.size()==0) return tmp;
        }
        return tmp;
        
    }
private:
    string CommonPrefix(string a, string b) {
        if(a.size()==0 or b.size()==0) return "";
        int len=min(a.size(),b.size());
        string ans="";
        for (int i=0;i<len;i++){
            if(a[i]==b[i]) ans+=a[i];
            else {
                return ans;
            }
        }
            return ans;
    }   
};