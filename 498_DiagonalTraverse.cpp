class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> ans={};
        if (matrix.size()==0) return ans;
        if (matrix[0].size()==0) return ans;
        int m=matrix.size();
        int n=matrix[0].size();
        for (int k =0; k<=m+n-2;++k)
        {
            if (k%2==0){
                for (int a=0;a<=k;++a){
                    int b = k-a;
                    if (b<=m-1 and a<=n-1) ans.push_back(matrix[b][a]);
                }
            }
            else{
                for (int a=0;a<=k;++a){
                    int b = k-a;
                    if (b<=n-1 and a<=m-1) ans.push_back(matrix[a][b]);
                }
            }
        }
        return ans;
    }
};