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
    bool func(TreeNode* root, TreeNode* p, TreeNode* q,TreeNode*&ans){
        if(root==NULL){
            return false;
        }
        bool cur=false;
        if(root==p ||root==q){
            cur=true;
        }
        bool l=func(root->left,p,q,ans);
        bool r=func(root->right,p,q,ans);
        if((l&&r) || (l&&cur) || (r&&cur)){
            ans=root;
        }
        return (cur||l||r);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode*ans=NULL;
        func(root,p,q,ans);
        return ans;
    }
};
