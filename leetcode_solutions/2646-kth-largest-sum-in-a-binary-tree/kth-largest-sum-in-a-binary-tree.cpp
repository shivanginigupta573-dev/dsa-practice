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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long>sumarr;
        queue<TreeNode*>q;
        if(root==nullptr)
        return 0;
        q.push(root);
        while(!q.empty())
        {
            int n=q.size();
            //l finding sum level wise
            long long sum=0;
            for(long long  i=0;i<n;i++)
            {
                TreeNode * node=q.front();
                q.pop();
                sum+=node->val;
                if(node->left)
                q.push(node->left);
                if(node->right)
                q.push(node->right);
        
            }
           sumarr.push_back(sum);
        }
        if(sumarr.size()<k)
        return -1;
        sort(sumarr.begin(),sumarr.end(),greater<long long>());
        return sumarr[k-1];
    }
};