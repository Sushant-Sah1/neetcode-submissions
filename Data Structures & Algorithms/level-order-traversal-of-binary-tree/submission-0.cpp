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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        queue<pair<int,TreeNode*>>q;
        q.push({0,root});
        while(!q.empty()){
            auto [d,node]=q.front();
            q.pop();
            if(node!=NULL){
                if(ans.size()<(d+1)){
                    ans.push_back({});
                }
                ans[d].push_back(node->val);
                q.push({d+1,node->left});
                q.push({d+1,node->right});
            }
        }
        return ans;
    }
};
