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
    void IsPresent(TreeNode*&root,int curr,int &target,bool &ans){
        if(!root || ans) return;
        curr = curr+root->val;
        if(!root->left && !root->right){
            if(curr==target){
                ans=true;
                return;
            }
        }
        IsPresent(root->left,curr,target,ans);
        IsPresent(root->right,curr,target,ans);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool ans =false;
        IsPresent(root,0,targetSum,ans);
        return ans;
    }
};