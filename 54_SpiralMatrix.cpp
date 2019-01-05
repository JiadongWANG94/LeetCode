#include<vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int count=0;
        vector<int> ans={};
        int m =matrix.size();
        if (m==0) return ans;
        int n = matrix[0].size();
        if (n==0) return ans;
        int i_min=0;
        int i_max=m-1;
        int j_min=0;
        int j_max=n-1;
        int direct=1;
        //1: ->
        //2: down
        //3: <-
        //4: up
        while(count<m*n){
            if (direct==1){
                for (int j=j_min;j<=j_max;++j){
                    ans.push_back(matrix[i_min][j]);
                    count++;
                }
                i_min++;
                direct=2;
                continue;
            }
            if (direct==2){
                for (int i=i_min; i<=i_max;++i){
                    ans.push_back(matrix[i][j_max]);
                    count++;
                }
                j_max--;
                direct=3;
                continue;
            }
            if (direct==3){
                for (int j=j_max;j>=j_min;--j){
                    ans.push_back(matrix[i_max][j]);
                    count++;
                }
                i_max--;
                direct=4;
                continue;
            }
            if (direct==4){
                for (int i=i_max; i>=i_min;--i){
                    ans.push_back(matrix[i][j_min]);
                    count++;
                }
                j_min++;
                direct=1;
                continue;
            }
        }
        return ans;
    }
};