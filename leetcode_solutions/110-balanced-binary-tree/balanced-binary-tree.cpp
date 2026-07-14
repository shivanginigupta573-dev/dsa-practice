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
  int depth(TreeNode* node)
  {
        if(node==nullptr)
        {
            return 0;
        }
        int ldepth=depth(node->left);
        int rdepth=depth(node->right);
        return max(ldepth,rdepth)+1;

  }
    bool isBalanced(TreeNode* root) {
      if(root ==nullptr)
      return true;
      int x=depth(root->left)-depth(root->right);
      if(x<-1 || x>1)
       return false;
       return isBalanced(root->left )&& isBalanced(root->right);      
    }
};