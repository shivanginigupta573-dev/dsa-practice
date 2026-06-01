/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==nullptr)
        return false;
        //if leaf node sum==taget
        if(root->left==nullptr && root->right==nullptr)
        return targetSum==root->val;
        //recurse 
        int target=targetSum-root->val;
        return hasPathSum(root->left,target)|| hasPathSum(root->right,target);
        
    }
};