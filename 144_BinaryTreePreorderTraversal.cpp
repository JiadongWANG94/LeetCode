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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans={};
        if (root==nullptr) return ans;
        ans.push_back(root->val);
        if (root->left !=NULL){
            vector<int> pre=preorderTraversal(root->left);
            for (int i=0;i<pre.size();++i){
                ans.push_back(pre[i]);
            }            
        }
        if (root->right !=NULL){
            vector<int> pre=preorderTraversal(root->right);
            for (int i=0;i<pre.size();++i){
                ans.push_back(pre[i]);
            }            
        }
        return ans;
    }
};