/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int dfs(TreeNode* root,int&ans){
        if(root==NULL){
            return 0;
        }
        int l=dfs(root->left,ans);
        int r=dfs(root->right,ans);
        int tc=root->val;
        if(l>0){
            tc+=l;
        }
        if(r>0){
            tc+=r;
        }
        ans=max(ans,tc);
        return root->val+max(0,max(l,r));
    }
    int maxPathSum(TreeNode* root) {
        // THERE MIGHT BE SOME PATH FROM A NON ROOT AND NON LEAF TO SOME OTHER PART WHICH IS NON ROOT AND NON LEAF

        // LIKE ANY GENERIC DFS OF SUM , AT EACH NODE I CALCULATE THE MAXIMUM APTH SUM PASSING THORUGH CUR NODE WITH THIS CUR NODE AS HIGHEST PINT IN THE PATH

        // SO AT EACH NODE WHAT I CAN DO IS GET LENGHT OF THE MAXIMUM PATH FROM THIS TO ONE NODE IN CHILD (FOR BOH CHILDS)
        // THERE IS A POINT IN RETURN DFS WHERE I DECIDE TO GO WITH ONLY CURRENT NODE AND RETUN ITS VALUE 
        //  ==>>WHEN DO I DO THIS , WHEN THE CHILD VALUES REDUCE ANSWER THAT IS WHEN THEY R NEGATIVE
        
        //to get maximum ath sum with cur as heighiest node 
        // NOW NODE ENTRY CAN BE -VE AND TOTAL PATH SUM TO CUR ROOT MIGHT BE NEGATIVE , SO I WANNA EXCLUDE IT AND EITHER GO WITH MAXIMUM OF OTHER CHILD(MAXIMUM PATH FROM ONE NODE TO THIS CUR ROOT) 
        // OR IF BOTH R NEGATIVE , I WOULD LIKE TO EXCLUDE BOTH OF THEM AND ONLY 


        // inr returning , i can just send in this node value (compulsary) and maximum of maximum return value of the childs 
        //  NOTE IF BOTH R NEGATIVE , I CAN JUST RETURN CUR NODE VALUE (INCLUDING THE -VE WILL REDUCE THE ANSWER WHICH WE DONT WONT)
        int ans=INT_MIN;
        dfs(root,ans);
        return ans;
    }
};
