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
    unordered_map<TreeNode*,int>dp;
    int dfs(TreeNode* node)
    {
        if(!node)
        return 0;
        if(dp.count(node))
         return dp[node];
         //rob this node;
         int rob=node->val;
         //rob;
         if(node->left)
         {
            rob+=dfs(node->left->left)+dfs(node->left->right);//because we cant take childreen
         }
         if(node->right)
         {
             rob+=dfs(node->right->left)+dfs(node->right->right);
         }
         //skip this node
         int  skip=dfs(node->left)+dfs(node->right);
         return dp[node]=max(rob,skip);
    }
    int rob(TreeNode* root) {
        return dfs(root);
    }
};