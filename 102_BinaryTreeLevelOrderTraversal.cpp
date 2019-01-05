/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <queue>
#include <pair>

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<pair<TreeNode*,int>> Q;
        if (root==nullptr) return ans;
        Q.push(pair<TreeNode*,int>(root,0));
        int layer_index=0;
        vector<int> layer={};
        while (Q.size()>0){
            pair<TreeNode*,int> tmp=Q.front();
            if (tmp.second==layer_index)
                layer.push_back(tmp.first->val);
            else{
                ans.push_back(layer);
                layer.clear();
                layer_index=tmp.second;   
                layer.push_back(tmp.first->val);
            }
            if (tmp.first->left !=nullptr) {
                Q.push(pair<TreeNode*,int>(tmp.first->left, tmp.second+1));
            }
            if (tmp.first->right !=nullptr) {
                Q.push(pair<TreeNode*,int>(tmp.first->right, tmp.second+1));
            }
            Q.pop();
        }
        ans.push_back(layer);
        return ans;
    }
};