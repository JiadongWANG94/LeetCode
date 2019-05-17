class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> ans={};
        if (A.size()==0) return ans;
        for (int i=0;i<A.size();i++){
            ans.push_back(pow(A[i],2));
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};