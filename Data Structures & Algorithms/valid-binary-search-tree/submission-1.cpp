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
    pair<int,int>dfs(TreeNode* root){
        if(root->left==NULL && root->right==NULL){
            return {root->val,root->val};
        }else if(root->left!=NULL && root->right==NULL){
            auto [lmin,lmax]=dfs(root->left);
            if(lmax==INT_MAX){
                return {INT_MAX,INT_MAX};
            }
            if(lmax>=root->val){
                return {INT_MAX,INT_MAX};
            }
            return {lmin,root->val};
        }else if(root->left==NULL && root->right!=NULL){
            auto [rmin,rmax]=dfs(root->right);
            if(rmax==INT_MAX){
                return {INT_MAX,INT_MAX};
            }
            if(rmin<=root->val){
                return {INT_MAX,INT_MAX};
            }
            return {root->val,rmax};
        }
        auto [lmin,lmax]=dfs(root->left);
        if(lmax==INT_MAX){
            return {INT_MAX,INT_MAX};
        }
        auto [rmin,rmax]=dfs(root->right);
        if(rmax==INT_MAX){
            return {INT_MAX,INT_MAX};
        }
        if(!(root->val>lmax && root->val<rmin)){
            return {INT_MAX,INT_MAX};
        }
        return {lmin,rmax};

    }
    bool isValidBST(TreeNode* root) {
        auto [x,y]=dfs(root);
        return x!=INT_MAX;
    }
};
