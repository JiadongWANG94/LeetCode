class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum=0;
        if (nums.size()==0) return -1;
        for (int i =0;i<nums.size();++i) sum+=nums[i];
        int sum_l=0;
        int sum_r=sum-sum_l-nums[0];
        int ind =0;
        while ((sum_r!=sum_l)and (ind<nums.size())){
            sum_l+=nums[ind];
            ind++;
            sum_r-=nums[ind];   
        }
        if (sum_r==sum_l) return ind;
        else return -1;
    }
};