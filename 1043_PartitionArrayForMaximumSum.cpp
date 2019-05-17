class Solution {
private:
    map<int,int> memory;
public:
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        if (A.size()==0) return 0;

        if (K>=A.size()){
            //find max
            int max=0;
            for (vector<int>::iterator ite=A.begin();ite!=A.end();ite++){
                if (*ite>max){
                    max=*ite;
                }
            }
            memory[A.size()]=A.size()*max;
            return A.size()*max;
        }
        
        int max=A[0];
        vector<int> AtmpKeep;

        for (int i=1;i<=K;++i){
            int maxLocal=0;
            for (vector<int>::iterator ite=A.begin();ite<A.begin()+i;ite++){
                if(*ite>maxLocal) maxLocal=*ite;
            }
            vector<int> Atmp(A.begin()+i,A.end());
            int tmp;
            if (memory.find(Atmp.size())!=memory.end()){
                //memory[A.size()]=maxLocal*i+memory[Atmp.size()];
                tmp= maxLocal*i+memory[Atmp.size()];
                
            }
            else{ tmp=maxLocal*i+maxSumAfterPartitioning(Atmp,K);}
            if (tmp>max){
                max=tmp;
                AtmpKeep=Atmp;
            }
            
        }
        memory[A.size()]=max;
        return max;
    }
};