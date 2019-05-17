class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        if (A.size()<=1) return A.size();
        int index_1=0;
        int max_len=1;
        int test=0;
        while (A.size()-index_1>1){
            int index_2=index_1+1;
            //bool tmp=true;
            //long
            while (index_2<A.size()-1 && (A[index_2+1]>A[index_2] && A[index_2]<A[index_2-1]||A[index_2+1]<A[index_2] && A[index_2]>A[index_2-1])){  //(A[index_2+1]-A[index_2])*(A[index_2]-A[index_2-1])<0
                index_2++;
            }
            if (index_2-index_1+1>max_len) {
                max_len=index_2-index_1+1;
                test=index_1;
            }
            index_1=index_2;
            //index_1++;
        }
        return max_len;
    }
};