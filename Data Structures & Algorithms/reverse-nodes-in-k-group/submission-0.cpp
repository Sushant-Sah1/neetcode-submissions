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
        ListNode* s=head,*f=head,*ans=new ListNode(-1),*prev=ans;;
        while(true){
            for(int i=0;i<k-1;i++){
                if(f==NULL){
                    break;
                }
                f=f->next;
            }
            if(!f){
                break;
            }
            ListNode*nextn=f->next;
            ListNode*x=s,*l=nextn;
            while(true){
                ListNode*t=s->next;
                s->next=l;
                l=s;
                s=t;
                if(s==nextn){
                    break;
                }
            }
            prev->next=l;
            prev=x;
            f=nextn;
            s=nextn;
        }
        return ans->next;
    }
};
