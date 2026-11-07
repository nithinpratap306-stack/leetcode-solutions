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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        head=rev(head);
        if(n==1){
            head=head->next;
            return rev(head);
        }
        ListNode* t=head;
        for(int i=1;i<n-1;i++){
            t=t->next;
        }
        t->next=t->next->next;
        return rev(head);
    }
};
/*The algorithm reverses the list, removes the nth node from the (now reversed) list, and reverses back.

- Reversing a list takes O(L) time and O(1) extra space, where L is the length of the list.
- After the first reversal, it traverses up to n-1 nodes to locate the node before the target, which is O(n).
- Reversing back is another O(L) time, O(1) space.

Overall time complexity: O(L), since L dominates and the additional O(n) is bounded by L (n ≤ L).
Overall space complexity: O(1) extra space (in-place operations, no extra data structures).*/