class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size()==0)return -1;
        size_t i1=0,i2=nums.size()-1;
        while (i2-i1>1 and nums[(i1+i2)/2]!=target){
            if (nums[(i1+i2)/2]>target) i2=(i1+i2)/2;
            else i1=(i1+i2)/2;
        }
        if (nums[(i1+i2)/2]==target) return (i1+i2)/2;
        else if(nums[i2]==target) return i2;
        else return -1;
    }
};