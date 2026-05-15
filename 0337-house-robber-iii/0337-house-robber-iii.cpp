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
    void InsertNode(TreeNode*root,unordered_map<TreeNode*,vector<int>>&dp){
        if(!root) return;
        dp[root] = vector<int>(2,-1);
        InsertNode(root->left,dp);
        InsertNode(root->right,dp);
    }
    int HouseRobberIII(TreeNode*root,bool take,unordered_map<TreeNode*,vector<int>>&dp){
        if(!root) return 0;
        if(dp[root][take]!=-1) return dp[root][take];
        if(take){
            dp[root][take] = max(root->val+HouseRobberIII(root->left,false,dp)+HouseRobberIII(root->right,false,dp),
            HouseRobberIII(root->left,true,dp)+HouseRobberIII(root->right,true,dp));
        }
        else{
            dp[root][take] = HouseRobberIII(root->left,true,dp)+HouseRobberIII(root->right,true,dp);
        }
        return dp[root][take];
    }
    int rob(TreeNode* root) {
        unordered_map<TreeNode*,vector<int>>dp;
        InsertNode(root,dp);
        return HouseRobberIII(root,true,dp);  
    }
};