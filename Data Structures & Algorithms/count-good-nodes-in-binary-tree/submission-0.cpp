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
    void dfs(TreeNode*root,int&ans,int maxi){
        if(root==NULL){
            return;
        }
        if(root->val>=maxi){
            ans++;
        }
        maxi=max(maxi,root->val);
        dfs(root->left,ans,maxi);
        dfs(root->right,ans,maxi);
    }
    int goodNodes(TreeNode* root) {
        int ans=0;
        dfs(root,ans,-200);
        return ans;
    }
};
