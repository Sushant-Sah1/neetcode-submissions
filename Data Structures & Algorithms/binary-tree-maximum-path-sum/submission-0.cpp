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
        int ans=INT_MIN;
        dfs(root,ans);
        return ans;
    }
};
