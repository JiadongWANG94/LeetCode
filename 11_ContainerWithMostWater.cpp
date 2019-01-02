#include <vector>
#include <math.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans =0;
        int n = height.size();
        for (int i =0; i<n-1; ++i)
        {
            for (int j =i+1; j<n; ++j)
            {
                int volum = (j-i)* min(height[i],height[j]);
                if (volum>ans)
                    ans =volum;
            }
        }
        return ans;
    }
};