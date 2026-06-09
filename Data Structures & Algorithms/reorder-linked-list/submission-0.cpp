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
        // ListNode*x=s;
        // while(x!=NULL){
        //     cout<<x->val<<endl;
        //     x=x->next;
        // }
        ListNode*p=NULL,*cur=s->next;
        s->next=NULL;
        while(cur!=NULL){
            ListNode*t=cur->next;
            cur->next=p;
            p=cur;
            cur=t;
        }
        // cout<<endl;
        // x=p;
        // while(x!=NULL){
        //     cout<<x->val<<endl;
        //     x=x->next;
        // }
        // cout<<endl;
        // x=head;
        // while(x!=NULL){
        //     cout<<x->val<<endl;
        //     x=x->next;
        // }
        cur=head;
        while(p!=NULL){
            // if(cur!=NULL){
            //     cout<<cur->val<<' ';
            // }
            // if(p!=NULL){
            //     cout<<p->val<<' ';
            // }
            // cout<<endl;
            ListNode*t=cur->next,*q=p->next;
            p->next=t;
            cur->next=p;
            cur=t;
            p=q;
        }
    }
};
