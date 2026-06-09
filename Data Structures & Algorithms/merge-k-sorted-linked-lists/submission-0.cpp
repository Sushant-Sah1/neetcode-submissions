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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode*ans=NULL,*cur=NULL;
        int n=0;
        while(true){
            int maxi=INT_MAX;
            for(int j=0;j<lists.size();j++){
                if(lists[j]!=NULL){
                    maxi=min(maxi,lists[j]->val);
                }
            }
            if(maxi==INT_MAX){
                break;
            }
            for(int j=0;j<lists.size();j++){
                while(lists[j]!=NULL){
                    if(lists[j]->val==maxi){
                        if(cur==NULL){
                            cur= new ListNode(maxi);
                            ans=cur;
                        }else{
                            cur->next= new ListNode(maxi);
                            cur=cur->next;
                        }
                        n--;
                        lists[j]=lists[j]->next;
                    }else{
                        break;
                    }
                }
            }
        }
        return ans;
    }
};
