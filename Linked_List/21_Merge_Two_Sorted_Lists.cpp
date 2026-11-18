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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL){
            return list2;
        }
        if(list2==NULL){
            return list1;
        }
        ListNode* head=NULL;
        ListNode* tail=NULL;
        ListNode* t1=list1;
        ListNode* t2=list2;
        while(t1||t2){
            if(t1==NULL){
                tail->next=t2;
                break;
            }
            if(t2==NULL){
                tail->next=t1;
                break;
            }
            if(t1->val>=t2->val){
                if(head==NULL){
                    head=t2;
                    tail=t2;
                    t2=t2->next;
                    continue;
                }
                tail->next=t2;
                t2=t2->next;
                tail=tail->next;
            }
            else{
                if(head==NULL){
                    head=t1;
                    tail=t1;
                    t1=t1->next;
                    continue;
                }
                tail->next=t1;
                t1=t1->next;
                tail=tail->next;
            }
        }
        return head;
    }
};
/*Time complexity: O(n + m), where n and m are the lengths of list1 and list2. Each node is visited exactly once.

Space complexity: O(1) auxiliary space (not counting the output list). The algorithm uses a constant number of pointers and rearranges nodes in place.*/