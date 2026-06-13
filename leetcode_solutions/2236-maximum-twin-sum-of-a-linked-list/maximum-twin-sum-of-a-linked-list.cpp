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
        //previous one was a naive approach nd a sin
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=nullptr && fast->next!=nullptr)
        {
            slow=slow->next;
            fast=fast->next->next;
            //slow will point to the mid point
        }
         //reverse the linkedlist inplace
         ListNode* prev,*curr;
         curr=slow;
         //curr is the head of the second half that needs to be reversed
         while(curr!=nullptr)
         {
            ListNode* next_node=curr->next;
            curr->next=prev;              
            prev=curr;                   
            curr=next_node;
         }
        ListNode* p1=head;
        ListNode* p2=prev;
        int max_sum=0;
        
        while (p2!=nullptr) {
            max_sum=max(max_sum,p1->val+p2->val);
            p1=p1->next;
            p2=p2->next;
        }
        
        return max_sum;
    }
};