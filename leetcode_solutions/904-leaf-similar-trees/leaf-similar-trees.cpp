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
   void getLeafNodesDFS(TreeNode* root, vector<int>& leaves) {
    if (!root) return;
    
    // Check if the node is a leaf
    if (!root->left && !root->right) {
        leaves.push_back(root->val);
        return ;
    }
    
    getLeafNodesDFS(root->left, leaves);
    getLeafNodesDFS(root->right, leaves);
}
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>a1,a2;

        getLeafNodesDFS(root1,a1);
        getLeafNodesDFS(root2,a2);
        return a1==a2;
        
    }
};