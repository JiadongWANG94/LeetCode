class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        if(nums.size()!=0 and k!=0){
            k=k%nums.size();
            vector<int> tmp(nums.end()-k,nums.end());
            for (int i=nums.size()-1; i>k-1;--i){
                nums[i]=nums[constraint(nums.size(),i-k)];
            }
            for (int i=0;i<k;++i){
                nums[i]=tmp[i];
            }
        }

    }
private:
    int constraint(int max, int n){
        if (n>=0 and n<=max) return n;
        if (n<0) return max+n;
        if (n>max) return n-max;
    }
};