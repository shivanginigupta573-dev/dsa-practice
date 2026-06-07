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
TreeNode * lca(TreeNode* root,TreeNode* p,TreeNode* q)
{
    if (!root || root==p||root==q)
    {
        return root;
    }
    TreeNode* left=lca(root->left,p,q);
    TreeNode* right=lca(root->right,p,q);
    if(left && right)
    return root;
    return left?left:right;
}
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        queue<TreeNode*>q;
        vector<TreeNode*>level;
        q.push(root);
        while(!q.empty())
        {
           level.clear();
           int n=q.size();
           for(int i=0;i<n;i++)
           {
            TreeNode* node=q.front();
            q.pop();
            level.push_back(node);
            if(node->left)
            q.push(node->left);
            if(node->right)
            q.push(node->right);
           }
        }
        TreeNode* res=level[0];
        for(int i=1;i<level.size();i++)
        {
            res=lca(root,res,level[i]);
        }
       return res; 
    }
};