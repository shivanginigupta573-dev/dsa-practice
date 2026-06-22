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
    pair<int,int> solve(TreeNode* node,int & res)
    {
        if(node==nullptr)
         return {-1,-1};
         //longest zigzag if we go left
         pair<int,int>left=solve(node->left,res);
         //longest zigzag if we go right
         pair<int,int> right=solve(node->right,res);
         int l=left.second+1;
         int r=right.first+1;
         pair<int,int> temp={l,r};
         int ans=max(l,r);
         res=max(ans,res);
         return temp;

    }
    int longestZigZag(TreeNode* root) {
        int res=0;
        solve(root,res);
        return res;
    }
};