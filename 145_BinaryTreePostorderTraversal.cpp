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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans={};
        if (root==nullptr) return ans;
        if (root->left !=NULL){
            vector<int> pre=postorderTraversal(root->left);
            for (int i=0;i<pre.size();++i){
                ans.push_back(pre[i]);
            }            
        }
        if (root->right !=NULL){
            vector<int> post=postorderTraversal(root->right);
            for (int i=0;i<post.size();++i){
                ans.push_back(post[i]);
            }            
        }
        ans.push_back(root->val);
        return ans;        
    }
};