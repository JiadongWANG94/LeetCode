class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max=0;
        int current =0;
        if (nums.size()==0) return 0;
        for (int i=0;i<nums.size();++i){
            if (nums[i]==1){
                current++;
                if (current>max) max=current;
                
            }
            else{
                current=0;
            }
        }
        return max;
    }
};