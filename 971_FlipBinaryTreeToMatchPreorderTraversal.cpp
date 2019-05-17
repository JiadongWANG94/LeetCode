/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        vector<int> ans;

        if (voyage[0]!=root->val){
            ans.clear();
            ans.push_back(-1);
            return ans;            
        }
        vector<int> tmp_l,tmp_r;
        if (root->left==NULL && root->right==NULL){
            if (voyage.size()==1) return ans;
            else{
                ans.clear();
                ans.push_back(-1);
                return ans;
            }
        }
        if (root->left==NULL && root->right!=NULL){
            if (voyage.size()==1){
                ans.clear();
                ans.push_back(-1);
                return ans;                  
            }
            vector<int> voy_r(voyage.begin()+1,voyage.end());
            tmp_r=flipMatchVoyage(root->right,voy_r);
            if (tmp_r.size()>0 && tmp_r[0]==-1){
                ans.clear();
                ans.push_back(-1);
                return ans;                   
            }
            else{
                ans.insert(ans.end(),tmp_r.begin(),tmp_r.end());
                return ans;
            }
        }
        if (root->left!=NULL && root->right==NULL){
            if (voyage.size()==1){
                ans.clear();
                ans.push_back(-1);
                return ans;                  
            }
            vector<int> voy_l(voyage.begin()+1,voyage.end());
            tmp_l=flipMatchVoyage(root->left,voy_l);
            if (tmp_l.size()>0 && tmp_l[0]==-1){
                ans.clear();
                ans.push_back(-1);
                return ans;                   
            }
            else{
                ans.insert(ans.end(),tmp_l.begin(),tmp_l.end());
                return ans;
            }
        }
        if (voyage[1]!=root->left->val && voyage[1]!=root->right->val){
            ans.clear();
            ans.push_back(-1);
            return ans;               
        }
        if (voyage[1]==root->right->val){
            ans.push_back(root->val);
            flip(root);               
        }
        int loca=1;
        while(voyage[loca]!=root->right->val && loca<voyage.size()) loca++;
        if (loca==voyage.size()){
            ans.clear();
            ans.push_back(-1);
            return ans;      
        }
        else{
            vector<int> voy_l(voyage.begin()+1,voyage.begin()+loca); //
            vector<int> voy_r(voyage.begin()+loca,voyage.end());
            
            tmp_l=flipMatchVoyage(root->left,voy_l);
            tmp_r=flipMatchVoyage(root->right,voy_r);
            
            if (tmp_l.size()>0 && tmp_l[0]==-1){
                ans.clear();
                ans.push_back(-1);
                return ans;                   
            }
            else{
                ans.insert(ans.end(),tmp_l.begin(),tmp_l.end());
            }
            if (tmp_r.size()>0 && tmp_r[0]==-1){
                ans.clear();
                ans.push_back(-1);
                return ans;                   
            }
            else{
                ans.insert(ans.end(),tmp_r.begin(),tmp_r.end());
            }
            return ans;
        }
        

        
        
    }
    
    void flip(TreeNode* root){
        TreeNode* tmp=root->left;
        root->left=root->right;
        root->right=tmp;
    }
};