#include <vector>

using namespace std;


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //step 1: find the corresponding row
        if (matrix.empty())
            return false;
        if (matrix[0].empty())
            return false;
        int n_r = matrix.size();
        int n_c = matrix[0].size();

        if (n_r==1)
            return binarySearch(matrix[0],target);
        for (int i=0;i<n_r-1;++i )
        {
            if ((matrix[i][0]<=target) and (matrix[i+1][0]>target))
            {
                return binarySearch(matrix[i],target);
            }
        }
        return binarySearch(matrix[n_r-1],target);
    }
    bool binarySearch(vector<int> list, int target){
        bool result =false;
        int n = list.size();
        int l = 0;
        int r = n-1;
        while (r>l+1)
        {
            int middle = (l+r)/2;
            if (list[middle]==target)
                return true;
            if (list[middle]<target)
                l=middle;
            else
                r=middle;
        }
        if (list[l]==target or list[r]==target)
            return true;
        return false;
    }
};