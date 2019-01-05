class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        if (k>n)
            return ans;
        if (n<1)
            return ans;
        float f_comb = 1.;
        for (int i =1;i<=k;i++)
            f_comb=f_comb*(n-i+1)/i;
        int n_comb=f_comb;
        int ind[k];
        for (int i =0;i<k;i++)
            ind[i]=i+1;
        for (int i=0;i<n_comb;i++)
        {
            vector<int> comb{};
            for (int j=0;j<k;j++)
                comb.push_back(ind[j]);
            ans.push_back(comb);
            if (ind[k-1]!=n)
            {
                ind[k-1]++;
                continue;
            }
            else{
                for (int j=k-2;j>=0;j--){
                    if (ind[j]+1<ind[j+1]){
                        ind[j]++;
                        for (int m=j+1;m<k;m++)
                            ind[m]=ind[j]+m-j;
                        break;
                    }
                }
            }
        }

        return ans;
    }
    
private:

};