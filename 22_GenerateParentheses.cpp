class Solution {
public:
    vector<string> generateParenthesis(int n) {
        return subGeneration(n,n,"");
    }
    
    vector<string> subGeneration(int r_pre, int r_post, string original){
        vector<string> ans;
        if (r_pre==0 and r_post==0) {
            ans.push_back("");
        }
        else if (r_pre==0 and r_post==1){
            ans.push_back(original+")");
        }
        else if (r_pre==r_post){
            vector<string> tmp1=subGeneration(r_pre-1,r_post,original+"(");
            ans.insert(ans.end(),tmp1.begin(),tmp1.end());
        } 
        else {
            if (r_pre>0){
                vector<string> tmp1=subGeneration(r_pre-1,r_post,original+"(");
                ans.insert(ans.end(),tmp1.begin(),tmp1.end());
            }
            if (r_post>0){
                vector<string> tmp2=subGeneration(r_pre,r_post-1,original+")");
                ans.insert(ans.end(),tmp2.begin(),tmp2.end());                     
            }
        }
        return ans;
    }
};