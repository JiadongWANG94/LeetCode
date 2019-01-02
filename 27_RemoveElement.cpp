class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n=nums.size();
        if (n==0) return 0;
        int front =0;
        int second =0;
        while (front<n){
            if (nums[front]==val){
                front++;
                continue;
            }
            else{
                nums[second]=nums[front];
                front++;
                second++;
            }
        }
        return second;
    }
};