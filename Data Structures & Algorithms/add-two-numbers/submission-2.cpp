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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int c=0;
        ListNode*ans=NULL,*cur=NULL;
        while(true){
            if(l1!=NULL){
                c+=l1->val;
                l1=l1->next;
            }
            if(l2!=NULL){
                c+=l2->val;
                l2=l2->next;
            }
            if(c==0){
                if(ans==NULL){
                    ans=new ListNode(0);
                    return ans;
                }
                break;
            }else{
                int p=c%10;
                c=c/10;
                ListNode*t=new ListNode(p);
                if(cur==NULL){
                    cur=t;
                    ans=cur;
                }else{
                    cur->next=t;
                    cur=t;
                }
            }
        }
        return ans;
    }
};
