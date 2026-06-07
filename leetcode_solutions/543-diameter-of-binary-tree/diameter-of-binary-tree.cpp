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
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==nullptr)
        {
            return 0;
        }
        int diam1=depth(root->left)+depth(root->right);
        int diam2=diameterOfBinaryTree(root->left);
         int diam3=diameterOfBinaryTree(root->right);
         return max({diam1,diam2,diam3});
        
    }
    int depth(TreeNode* node)
    {
        if(node==nullptr)
        return 0;
        int ldepth=depth(node->left);
        int rdepth=depth(node->right);
        return max(ldepth,rdepth)+1;
    }
};