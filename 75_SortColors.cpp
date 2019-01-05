class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        if (n>1) {
            int n0=0,n1=0;
            for (int i =0; i<n;i++){
                switch (nums[i]){
                    case 0:{
                        n0++;
                        break;
                    }
                    case 1:{
                        n1++;
                        break;
                    }
                }
            }
            for (int i=0;i<n0;++i){
                nums[i]=0;
            }
            for (int i=n0;i<n0+n1;++i){
                nums[i]=1;
            }
            for (int i=n0+n1;i<n;++i){
                nums[i]=2;
            }
        }
    }
};