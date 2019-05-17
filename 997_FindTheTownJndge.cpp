class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<bool> trust_sb_else(N,false);
        vector<int> trusted_by(N,0);
        if (N==1){
            if(trust.size()==0)
                return 1;
            else
                return -1;            
        }

        for (int i=0; i<trust.size();++i){
            trust_sb_else[trust[i][0]-1]=true;
            trusted_by[trust[i][1]-1]++;
        }
        for (int i=0;i<N;++i){
            if ((trusted_by[i]==N-1)&&(!trust_sb_else[i])) return i+1;
        }
        return -1;
    }
};