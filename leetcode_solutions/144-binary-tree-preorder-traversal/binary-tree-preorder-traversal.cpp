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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>a;
       preorder(root,a);
       return a;
           }
    void preorder(TreeNode* node,vector<int> &a)
    {
        if(node==nullptr)
        return ;
        a.push_back(node->val);
        preorder(node->left,a);
        preorder(node->right,a);

    }
};