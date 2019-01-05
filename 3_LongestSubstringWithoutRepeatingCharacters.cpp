#include<string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        if (n<=1) return n;
        size_t head=0,tail=0;
        int length=0;
        int ans=0;
        while (tail<n){
            tail++;
            string tmp_s(1,s[tail]);
            const char* tmp_c=tmp_s.c_str();
            size_t tmp=s.find(tmp_c,head); 
            if (tmp!=string::npos && tmp<tail) head=tmp+1;
            length=tail-head+1;
            if (length>ans) ans=length;
        }
        return ans;
    }
};