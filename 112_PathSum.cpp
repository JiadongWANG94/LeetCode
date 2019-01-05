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
    bool hasPathSum(TreeNode* root, int sum) {
        if (root==nullptr) return false;
        if (root->left==nullptr and root->right==nullptr) {
            if (sum-root->val==0) return true;
            else return false;
        }
        bool ans=false;
        if (root->left !=nullptr){
            ans = hasPathSum(root->left, sum-root->val);
        }
        if (root->right !=nullptr){
            ans = ans || hasPathSum(root->right, sum-root->val);
        }        
        return ans;
    }
};