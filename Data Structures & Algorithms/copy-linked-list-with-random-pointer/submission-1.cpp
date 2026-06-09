/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL) return NULL;
        unordered_map<Node*,Node*>mp;
        Node*p=head,*cur=NULL;
        Node*ans;
        while(p!=NULL){
            Node*t=new Node(p->val);
            mp[p]=t;
            if(cur==NULL){
                cur=t;
                ans=cur;
            }else{
                cur->next=t;
                cur=t;
            }
            p=p->next;
        }
        p=head;
        cur=ans;
        while(p!=NULL){
            cur->random=mp[p->random];
            p=p->next;
            cur=cur->next;
        }
        return ans;
    }
};
