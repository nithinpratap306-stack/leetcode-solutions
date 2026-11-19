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
    ListNode* merge(ListNode*l1,ListNode* l2){
        if(!l1) return l2;
        if(!l2) return l1;
        ListNode* head=NULL;
        ListNode* tail=NULL;
        while(l1||l2){
            if(!l1){
                tail->next=l2;
                break;
            }
            if(!l2){
                tail->next=l1;
                break;
            }
            if(l1->val<=l2->val){
                if(!head){
                    head=tail=l1;
                    l1=l1->next;
                    continue;
                }
                tail->next=l1;
                tail=l1;
                l1=l1->next;
            }
            else{
                if(!head){
                    head=tail=l2;
                    l2=l2->next;
                    continue;
                }
                tail->next=l2;
                tail=l2;
                l2=l2->next;
            }
        }
        return head;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return NULL;
        while(lists.size()>1){
            vector<ListNode*>merged;
            for(int i=0;i<lists.size();i+=2){
                ListNode* l1=lists[i];
                ListNode* l2=(i+1<lists.size())?lists[i+1]:NULL;
                merged.push_back(merge(l1,l2));
            }
            lists=merged;
        }
        return lists[0];
    }
}; 
/*- Time complexity: O(N log k), where N is the total number of nodes across all lists and k is the initial number of lists. At each pass, every node is processed once during a merge, and there are O(log k) passes because the number of lists halves each time.
- Space complexity: O(1) auxiliary space beyond the output list pointers, since the merge is done iteratively and in-place, aside from the new head/tail pointers used during merging. The recursion depth is not used here, so there is no extra call stack.*/