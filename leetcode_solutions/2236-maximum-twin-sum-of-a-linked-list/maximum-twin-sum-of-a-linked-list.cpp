/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int>nums;
        ListNode * temp=head;
        while(temp!=nullptr)
        {
            nums.push_back(temp->val);
            temp=temp->next;
        }
        int n=nums.size();
        int l=0,r=n-1;
        int maxm=INT_MIN;
        while(l<r)
        {
             int sum=nums[l]+nums[r];
             maxm=max(sum,maxm);
             l++;
             r--;
        }
        return maxm;
    }
};