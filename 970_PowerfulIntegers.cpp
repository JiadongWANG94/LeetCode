class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        int i_max,j_max;
        vector<int> ans;
        if (bound==0) return ans;
        if (bound==1) {
            return ans;
        }
        if (x!=1) i_max =log(bound)/log(x);
        else i_max=1;
        if (y!=1) j_max= log(bound)/log(y);
        else j_max=1;

        vector<int> tmp;
        for (int i=0;i<=i_max;i++){
            for (int j=0;j<=j_max;j++){
                if (pow(x,i)+pow(y,j)<=bound) tmp.push_back(pow(x,i)+pow(y,j));
            }
        }
        sort(tmp.begin(),tmp.end());
        ans.push_back(tmp[0]);
        for (int i=1;i<tmp.size();++i){
            if (tmp[i]!=tmp[i-1]) ans.push_back(tmp[i]);
        }
        return ans;
    }
};