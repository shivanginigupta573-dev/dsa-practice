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
   int solve(TreeNode* node,int &res)
   {
        if(node==nullptr)
          return 0;
        int l=solve(node->left,res);
        int r=solve(node->right,res);
        int temp=max(l,r)+1;
        int ans=l+r;//include root nd not including root
        res=max(res,ans);
        return temp;
   }
    int diameterOfBinaryTree(TreeNode* root) {
        int res=0;
        solve(root,res);
        return res;
    }
};