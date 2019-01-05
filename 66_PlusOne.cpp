class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool jud=true;
        for (int i=0;i<digits.size();++i){
            if (digits[i]!=9) {
                jud=false;
                break;
            }
        }
        if (jud){
            vector<int> ans(digits.size()+1,0);
            ans[0]=1;
            return ans;
        }
        digits[digits.size()-1]++;
        int ind = digits.size()-1;
        while(digits[ind]==10){
            digits[ind]=0;
            ind--;
            digits[ind]++;
        }
        return digits;
    }
    
};