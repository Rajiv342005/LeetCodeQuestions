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
    void InsertNode(TreeNode*&root,vector<int>&nums){
        if(!root) return;
        InsertNode(root->left,nums);
        nums.push_back(root->val);
        InsertNode(root->right,nums);
    }
    void BST(TreeNode*&root,vector<int>&nums,int &index){
        if(!root) return;
        BST(root->left,nums,index);
        root->val = nums[index++];
        BST(root->right,nums,index);
    }
    void recoverTree(TreeNode* root) {
        vector<int>nums;
        int index=0;
        InsertNode(root,nums);
        sort(nums.begin(),nums.end());
        BST(root,nums,index);
        return;
    }
};