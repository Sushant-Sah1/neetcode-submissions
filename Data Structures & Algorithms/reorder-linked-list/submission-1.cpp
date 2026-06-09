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
    void reorderList(ListNode* head) {
        // find middle. separate 2 parts.
        // reverse latter part
        // merge the 2 parts (after 1 node of first, put 1 part of second)

        ListNode*s=head;
        ListNode*f=head;
        while(true){
            if(f->next==NULL){
                break;
            }
            if(f->next->next==NULL){
                break;
            }
            s=s->next;
            f=f->next->next;
        }
        ListNode*p=NULL,*cur=s->next;
        s->next=NULL;
        while(cur!=NULL){
            ListNode*t=cur->next;
            cur->next=p;
            p=cur;
            cur=t;
        }
        cur=head;
        while(p!=NULL){
            ListNode*t=cur->next,*q=p->next;
            p->next=t;
            cur->next=p;
            cur=t;
            p=q;
        }
    }
};
