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
    int dfs(TreeNode* node,long long sum,int target)
    {
        if(node==nullptr)
         return 0;
        sum+=node->val;
        int cnt=sum==target?1:0;
        cnt+=dfs(node->left,sum,target);
        cnt+=dfs(node->right,sum,target);
        return cnt;
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        if(!root)
        return 0;
        return dfs(root,0,targetSum)+pathSum(root->left,targetSum)+pathSum(root->right,targetSum);
    }
};