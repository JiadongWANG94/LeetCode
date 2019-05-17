class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int n = time.size();
        int ans = 0;
        for (int i=0;i<n;++i){
            time[i] = time[i] % 60;
        }
        sort(time.begin(),time.end());
        map<int,int> numbers;
        vector<int> time_single;
        int count = 1;
        for (int i=1;i<n;++i){
            if (time[i]==time[i-1]) count++;
            else {
                numbers[time[i-1]]=count;
                time_single.push_back(time[i-1]);
                count=1;
            }
        }

        numbers[time[n-1]]=count;
        time_single.push_back(time[n-1]);         

        for (int i=0;i<time_single.size();++i){
            for (int j=i+1;j<time_single.size();++j){
                if ((time_single[i] + time_single[j] == 0)||(time_single[i]+time_single[j] == 60)) ans+=numbers[time_single[i]]*numbers[time_single[j]];
            }
        }

        if (numbers[30]>1){
            ans+=numbers[30]*(numbers[30]-1)/2;
        }
        if (numbers[0]>1){
            ans+=numbers[0]*(numbers[0]-1)/2;
        }
        return ans;
    }
};