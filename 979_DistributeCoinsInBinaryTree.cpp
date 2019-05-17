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
    int distributeCoins(TreeNode* root) {
        return distrib(root).first;
    }
    
    pair<int,int> distrib(TreeNode* root){
        if (root->left==NULL && root->right==NULL) return pair<int,int>(0,root->val-1);
        if (root->left==NULL){
            pair<int,int> tmp=distrib(root->right);
            return pair<int,int>(tmp.first+abs(tmp.second),root->val+tmp.second-1);
        }
        if (root->right==NULL){
            pair<int,int> tmp=distrib(root->left);
            return pair<int,int>(tmp.first+abs(tmp.second),root->val+tmp.second-1);
        }      
        pair<int,int> tmp_r=distrib(root->right);
        pair<int,int> tmp_l=distrib(root->left);
        return pair<int,int>(tmp_r.first+tmp_l.first+abs(tmp_r.second)+abs(tmp_l.second),root->val+tmp_l.second+tmp_r.second-1);
    }
};