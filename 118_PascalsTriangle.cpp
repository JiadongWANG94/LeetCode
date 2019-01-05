class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans={};
        if (numRows==0) return ans;
        vector<int> first={1};
        vector<int> second={1,1};
        ans.push_back(first);
        if (numRows==1) return ans;
        ans.push_back(second);
        if (numRows==2) return ans;
        for (int i=2;i<numRows;i++){
            vector<int> line={1};
            for (int j=1;j<i;j++)
                line.push_back(ans[i-1][j-1]+ans[i-1][j]);
            line.push_back(1);
            ans.push_back(line);
        }
        return ans;
    }
};