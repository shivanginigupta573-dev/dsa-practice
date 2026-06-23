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
  int cameras=0;
  int solve(TreeNode* node)
  {
        if(node==nullptr)
         return 2;
        int left=solve(node->left);
        int right=solve(node->right);
        if(left==0 || right==0){
            cameras++;//none children are having camera parent must have it
         return 1;
         
        }
         if(left==1||right ==1)
         {
            return 2;
         }
         return 0;
  }
    int minCameraCover(TreeNode* root) {
       if (solve(root) == 0) {
            cameras++;
        }
        
        return cameras;
        
    }
};