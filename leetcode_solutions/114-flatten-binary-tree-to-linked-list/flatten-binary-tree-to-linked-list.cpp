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
    TreeNode* dfs(TreeNode* node)
    {
        if(node==nullptr)
         return node;
        TreeNode* leftTail=dfs(node->left);
        TreeNode* rightTail=dfs(node->right);
        if(leftTail)
        {
            leftTail->right=node->right; //3->4
            node->right=node->left; //node->right=null node->left =>3->4 2-3-4
            node->left=nullptr;
        }
        if (rightTail)
        {
            return rightTail;
        }
        if(leftTail)
         return leftTail;
        return node;

    }
    void flatten(TreeNode* root) {
         dfs(root);

        
    }
};