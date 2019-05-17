class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {
        int n=A.size();
        vector<int> ans;
        for(int i=n;i>0;--i){
            // localize i
            int j=0;
            while (A[j]!=i){
                j++;
            }
            if (j!=i-1){
                if (j!=0){
                    Reverse(A,0,j);
                    ans.push_back(j+1);
                }
                Reverse(A,0,i-1);
                ans.push_back(i);
            }
        }
        return ans;
    }
    
    vector<int> Reverse(vector<int>& A, int i1, int i2){
        while (i1<i2){
            int tmp=A[i1];
            A[i1]=A[i2];
            A[i2]=tmp;
            ++i1;
            --i2;
        }
        return A;
    }
};