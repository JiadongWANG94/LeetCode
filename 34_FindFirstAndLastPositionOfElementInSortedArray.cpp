class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        //vector<int>::iterator left=nums.begin(), right=nums.end();
        int left=0, right=nums.size()-1;
        
        while (left<=right){
            int mid=(left+right)/2;
            if (nums[mid]==target){
                int head=mid,tail=mid;
                while(head-1!=-1 && nums[head-1]==target) head--;
                while(tail+1!=nums.size() && nums[tail+1]==target) tail++;
                return vector<int>{head,tail};
            }
            else if(nums[mid]<target){
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
        return vector<int>{-1,-1};
    }
};