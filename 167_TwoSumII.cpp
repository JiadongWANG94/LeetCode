class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int front=0;
        int back=numbers.size()-1;
        int sum=numbers[front]+numbers[back];
        while (sum!=target){
            if (sum>target) back--;
            else front++;
            sum = numbers[front]+numbers[back];
        }
        vector<int> ans={front+1,back+1};
        return ans;
    }
};