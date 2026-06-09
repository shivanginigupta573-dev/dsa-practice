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
    int good=0;
    void preorder(TreeNode* node,int path_maxm)
    {
        if(node==nullptr)//base case
        return ;
        if(node->val>=path_maxm)
        {
            good++;
        }
        int curr_max=max(path_maxm,node->val);
        //recurse left
        preorder(node->left,curr_max);
        //recurse right
        preorder(node->right,curr_max);

    }
    int goodNodes(TreeNode* root) {
        if(root==nullptr)
        return 0;
        preorder(root,root->val);
        return good;
        
    }
};