#include<string>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string ans="";
        if (num>=1000)
        {
            int tmp = num/1000;
            for (int i=0;i<tmp; ++i)
                ans += "M";
            num = num% 1000;
        }
        ans += subStep(num, 100, "D", "C", "M");
        ans += subStep(num, 10, "L", "X","C");
        ans += subStep(num,1,"V","I","X");
        return ans;
        
            
            
    }
private:    
    string subStep(int& subnum, int scale, string five, string one, string ten){
        string ret="";
        int tmp = subnum/scale;
        subnum = subnum% scale;
        if (tmp==9)
        {
            ret+=one +ten;
            return ret;
        }
        if (tmp==4)
        {
            ret+=one +five;
            return ret;
        }
        if ((tmp<9) and(tmp>=5))
        {
            ret+=five;
            tmp =tmp-5;
        }
        for (int i=0;i<tmp;++i)
            ret+=one;
        return ret;
    }
};