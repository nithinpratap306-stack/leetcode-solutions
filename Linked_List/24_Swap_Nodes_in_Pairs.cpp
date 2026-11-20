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
    ListNode* swapPairs(ListNode* head) {
        if(!head||!head->next) return head;
        ListNode* newh=head->next;
        ListNode* prev=NULL;
        ListNode* curr=head;
        while(curr&&curr->next){
            ListNode* scnd=curr->next;
            ListNode* nxtp=scnd->next;
            
            //swapping 
            scnd->next=curr;
            curr->next=nxtp;
            
            //connecting to previous
            if(prev){
                prev->next=scnd;
            }
            
            //moving pointers 
            prev=curr;
            curr=nxtp;
        }
        return newh;
    }
};
/*Time complexity: O(n), where n is the number of nodes in the list. Each node is visited a constant number of times during the single pass.
Space complexity: O(1) auxiliary space, since it uses a fixed number of pointers and does not allocate extra data structures. The changes are in-place.
*/