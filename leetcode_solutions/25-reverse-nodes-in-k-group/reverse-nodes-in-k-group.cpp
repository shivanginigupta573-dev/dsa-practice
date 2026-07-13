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
    ListNode* reverseKGroup(ListNode* head, int k) {
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

        if (!head||k==1) 
        return head;
        
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        
        ListNode* prev=dummy;
        ListNode* cur=nullptr;
        ListNode* nxt=nullptr;
        ListNode* p=dummy;
        
        // Count nodes to determine total groups safely
        int cnt=0;
        while (p->next!=nullptr) 
        {
            p=p->next;
            cnt++;
        }
        
        // Reverse each group
        while (cnt>=k) 
        {
            cur=prev->next;
            nxt=cur->next;
            for (int i = 1; i < k; ++i) 
            {
                cur->next = nxt->next;
                nxt->next = prev->next;
                prev->next = nxt;
                nxt = cur->next;
            }
            prev = cur;
            cnt -= k;
        }
        
        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }
};
    
