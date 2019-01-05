class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // find the tail T in descending order
        // find the number A right before the tail T
        // in the tail T, find the smallest number B larger than A
        // switch the position of A and B and sort the tail T in ascending order
        int n=nums.size();
        if (n>1){
            int t=n-1;
            while (t>=1 && nums[t-1]>=nums[t]) --t;
            if (t==0){
                //sort the vector in ascending order
                sort(nums.begin(),nums.end());
            }
            else{
                int A=nums[t-1];
                int B=nums[t];
                int b=t;
                for (int i=t;i<n;++i){
                    if (nums[i]>A){
                        b=i;
                        B=nums[i];
                    }
                    else break;
                }
                nums[t-1]=B;
                nums[b]=A;
                //sort T
                sort(nums.begin()+t,nums.end());
            }
     
        }

    }
};