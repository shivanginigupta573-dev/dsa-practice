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
    TreeNode* findMin(TreeNode* node) {
        while(node->left) 
        {
         node=node->left;
        }
        return node;
    }

    TreeNode* deleteNode(TreeNode* root,int key) {
        //base case
        // we will use recursion
        //cases node has no children nodde has 1 child node has 2 child
        if(root==nullptr )
        return nullptr;
        // if(root->val==key)
        // {
        //   //one chile
        //   //no child //2 child
        // }
        if(key>root->val)
        {
            root->right=deleteNode(root->right,key);
        }
        else if(key<root->val)
        {
            root->left=deleteNode(root->left,key);
        }
         else { // root->val == key, delete this node
            //  no child
            if(!root->left &&!root->right) {
                return nullptr;
            }
            // one child
            else if(!root->left) {
                TreeNode* temp=root->right;
                delete root;
                return temp;
            }
            else if(!root->right) {
                TreeNode* temp=root->left;
                delete root;
                return temp;
            }
            //  two children
            else {
                TreeNode* scr = findMin(root->right);
                root->val=scr->val;
                root->right=deleteNode(root->right,scr->val);
            }
        }
        return root; 
        
    }
};