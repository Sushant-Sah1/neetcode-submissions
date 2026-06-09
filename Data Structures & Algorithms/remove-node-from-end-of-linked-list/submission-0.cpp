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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode*s=head,*f=head,*prev=NULL;
        for(int i=0;i<n;i++){
            f=f->next;
        }
        while(f!=NULL){
            f=f->next;
            prev=s;
            s=s->next;
        }
        if(prev==NULL){
            return head->next;
        }else{
            prev->next=s->next;
        }
        return head;

    }
};
