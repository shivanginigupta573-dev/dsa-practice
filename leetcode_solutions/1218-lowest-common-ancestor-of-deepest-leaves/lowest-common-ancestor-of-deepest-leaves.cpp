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
TreeNode* lca(TreeNode* root,TreeNode* p,TreeNode* q)
{
    if(!root || root==p || root==q)
    return root;
    TreeNode *left=lca(root->left,p,q);
    TreeNode *right=lca(root->right,p,q);
    if(left && right )return root;
    return left ?left:right;

}
void findDeepest(TreeNode* node, int depth, int& maxDepth, vector<TreeNode*>& leaves) {
        if (!node) return;
        if (!node->left &&!node->right) { // leaf
            if (depth > maxDepth) {
                maxDepth = depth;
                leaves = {node}; // new deepest level, reset
            } else if (depth == maxDepth) {
                leaves.push_back(node); // same level, add
            }
            return;
        }
        findDeepest(node->left, depth + 1, maxDepth, leaves);
        findDeepest(node->right, depth + 1, maxDepth, leaves);
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        //here we find the deepest leaf nodes nd then pass it to lca
         if (!root) return nullptr;

        vector<TreeNode*> deepestLeaves;
        int maxDepth = 0;
        findDeepest(root, 0, maxDepth, deepestLeaves);

        // Reduce all deepest leaves to one LCA
        TreeNode* res = deepestLeaves[0];
        for (int i = 1; i < deepestLeaves.size(); i++) {
            res = lca(root, res, deepestLeaves[i]);
        }
        return res;
        
    }
};