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
    bool isSame(TreeNode* root, TreeNode* subRoot){
        if(root==NULL && subRoot==NULL){
            return true;
        }else if(root!=NULL && subRoot!=NULL){
            if(root->val!=subRoot->val){
                return false;
            }else{
                return isSame(root->left,subRoot->left) && isSame(root->right,subRoot->right);
            }
        }
        return false;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // n*m
        if(root==NULL){
            return false;
        }
        bool l=isSubtree(root->left,subRoot);
        bool r=isSubtree(root->right,subRoot);
        bool c=isSame(root,subRoot);
        return l||r||c;
    }
};
