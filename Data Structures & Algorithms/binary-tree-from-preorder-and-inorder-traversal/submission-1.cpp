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
    TreeNode*dfs(vector<int>& preorder,unordered_map<int,int>&mp,int l,int r,int&pidx){
        if(l>r){
            return NULL;
        }
        int idx=0;
        // if(pidx<preorder.size()){
        idx=mp[preorder[pidx]];
        // }else{
        //     return NULL;
        // }
        TreeNode*temp=new TreeNode(preorder[pidx]);
        pidx++;
        temp->left=dfs(preorder,mp,l,idx-1,pidx);
        temp->right=dfs(preorder,mp,idx+1,r,pidx);
        return temp;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        int pidx=0;
        return dfs(preorder,mp,0,inorder.size()-1,pidx);
        // return NULL;
    }
};
