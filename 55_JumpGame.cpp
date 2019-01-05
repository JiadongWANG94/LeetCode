class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size()==0) return false;
        if (nums.size()==1) return true;
        if (nums.size()==2)
            if (nums[0]==0) return false;
            else return true;
        int n=nums.size();
        int tmp=nums[0];
        for (int i=1;i<n-1;++i){
            if (tmp==0)
                return false;
            tmp =max(tmp-1,nums[i]);
        }
        if (tmp>0) return true;
        else return false;
    }
};