class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        if (n<=1) return s;
        int type=1;
        int middle=0;
        int max_len=1;
        //type1: aba
		for (int i = 0;i < n ;++i) {
			if ((n - 1 - i) * 2 + 1 <= max_len) break;
			int before = i;
			int after = i;
			while (before > 0 && after < n - 1 && s[before - 1] == s[after + 1]) {
				before--;
				after++;
			}
			if (after - before + 1 > max_len) {
				type = 1;
				middle = i;
				max_len = after - before + 1;
			}
		}
		//type2: abba
		for (int i = 0;i < n;++i) {
			if ((n - 1 - i) * 2 <= max_len) break;
			int before = i;
			int after = i + 1;
            if (s[before] != s[after]) continue;
			while (before > 0 && after < n - 1 && s[before - 1] == s[after + 1]) {
				before--;
				after++;
			}
			if (after - before + 1 > max_len) {
				type = 2;
				middle = i;
				max_len = after - before + 1;
			}
		}
        string ans;
        if (type==1){
            ans=s.substr(middle-(max_len-1)/2,max_len);
        }
        if (type==2){
            ans=s.substr(middle-max_len/2+1,max_len);
        }     
        return ans;
    }
};