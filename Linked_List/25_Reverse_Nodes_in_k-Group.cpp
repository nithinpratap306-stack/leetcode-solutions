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
    ListNode* rev(ListNode* head){
        ListNode* curr=head;
        ListNode* prev=NULL;
        while(curr){
            ListNode* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head||!head->next)return head;
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* curr=head;
        ListNode* prev=dummy;
        while(curr){
            ListNode* st=curr;
            int count=1;
            while(curr&&count<k){
                curr=curr->next;
                count++;
            }
            if(!curr) break;

            ListNode* end=curr;
            curr=curr->next;
            end->next=NULL;
            
            prev->next=rev(st);
            st->next=curr;
            prev=st;
        }
        return dummy->next;
    }
};
/*Time complexity: O(n), where n is the number of nodes in the list. Each node is visited a constant number of times: once to locate the end of a k-group, and once during the reversal of that group.
Space complexity: O(1) extra space (ignoring the recursion stack, since the reversal is iterative). The algorithm uses a few pointers only, and no additional data structures proportional to n.*/