class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        if (nums.size()==0) return -1;
        if (nums.size()==1) return 0;
        int max1=0;
        int max2=0;
        int ind=0;
        for (int i=0;i<nums.size();++i){
            if (nums[i]>=max1){
                max2=max1;
                max1=nums[i];
                ind =i;
            }
            else if (nums[i]>=max2) max2=nums[i];
        }
        if (max1>=max2*2) return ind;
        else return -1;
    }
};