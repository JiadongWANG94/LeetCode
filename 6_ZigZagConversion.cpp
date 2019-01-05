class Solution {
public:
    string convert(string s, int numRows) {

        if (numRows==1) return s;
        int n=s.size();
        int N_period = n/(numRows*2-2);
        int N_back = n%(numRows*2-2);
        string ans="";
        
        for (int i=0;i<numRows;++i){
            for (int j=0;j<N_period+1;++j){
                if(i==0){
                    if(j*(numRows*2-2)<n)
                        ans+=s[j*(numRows*2-2)];
                }
                else if(i==numRows-1){
                    if(j*(numRows*2-2)+numRows-1<n)
                        ans+=s[j*(numRows*2-2)+numRows-1];
                }
                else{
                    if(i+j*(numRows*2-2)<n)
                        ans+=s[i+j*(numRows*2-2)];
                    if((j+1)*(numRows*2-2)-i<n)
                        ans+=s[(j+1)*(numRows*2-2)-i];
                }
                
            }            
        }
        
        return ans;
    }
};