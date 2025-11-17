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
    void insert(TreeNode*&root,vector<int>&ans){
        if(!root) return;
        insert(root->left,ans);
        ans.push_back(root->val);
        insert(root->right,ans);
    }
    TreeNode* increasingBST(TreeNode* root) {
        vector<int>ans;
        insert(root,ans);
        TreeNode *t =new TreeNode(ans[0]);
        TreeNode *temp = t;
        for(int i=1;i<ans.size();i++){
            temp->right = new TreeNode(ans[i]);
            temp = temp->right;
        }
        return t;
    }
};