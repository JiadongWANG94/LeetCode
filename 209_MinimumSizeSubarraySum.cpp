class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.size()==0) return 0;
        int front=0;
        int back=0;
        int sum=nums[0];
        int ans=100000;
        while(front<nums.size()){
            if (sum>=s){
                if (ans>front-back+1) ans=front-back+1;
                if (front>back) {
                    back++;
                    sum=sum-nums[back-1];
                }
                else{
                    front++;
                    sum+=nums[front];
                    sum-=nums[back];
                    back++;
                }
            }
            else {
                front++;
                sum+=nums[front];
            }
        }
        if (ans==100000) return 0;
        return ans;
    }
};