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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>a;
        postorder(root,a);
        return a;
        
    }
    void postorder(TreeNode* node,vector<int>&a)
    {
        if(node==nullptr)
        {
            return;
        }
            postorder(node->left,a);
            postorder(node->right,a);
            a.push_back(node->val);
        
    }
};