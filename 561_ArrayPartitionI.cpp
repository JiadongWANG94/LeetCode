class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        if (nums.size()==0) return 0;
        sort(nums.begin(),nums.end());
        int first=0;
        int ans = 0;
        while (first<nums.size()-1){
            ans+=nums[first];
            first+=2;
        }
        return ans;
    }
};