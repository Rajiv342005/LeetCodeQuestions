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
    void InorderedTraversal(TreeNode*root,vector<int>&nums){
        if(!root) return;
        InorderedTraversal(root->left,nums);
        nums.push_back(root->val);
        InorderedTraversal(root->right,nums);
    }
    TreeNode* BBST(vector<int>&nums,int start,int end){
        if(start>end) return nullptr;
        int mid = (start+end)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = BBST(nums,start,mid-1);
        root->right = BBST(nums,mid+1,end);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>nums;
        InorderedTraversal(root,nums);
        return BBST(nums,0,nums.size()-1);
    }
};