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
        ListNode*cur=NULL;
        ListNode*head=cur;
        while(list1!=NULL && list2!=NULL){
            ListNode*t;
            if(list1->val<list2->val){
                t=new ListNode(list1->val);
                list1=list1->next;
            }else{
                t=new ListNode(list2->val);
                list2=list2->next;
            }
            if(cur==NULL){
                cur=t;
                head=cur;
            }else{
                cur->next=t;
                cur=t;
            }
        }
        while(list1!=NULL){
            ListNode*t;
            t=new ListNode(list1->val);
            list1=list1->next;
            if(cur==NULL){
                cur=t;
                head=cur;
            }else{
                cur->next=t;
                cur=t;
            }
        }
        while(list2!=NULL){
            ListNode*t;
            t=new ListNode(list2->val);
            list2=list2->next;
            if(cur==NULL){
                cur=t;
                head=cur;
            }else{
                cur->next=t;
                cur=t;
            }
        }
        return head;
    }
};
