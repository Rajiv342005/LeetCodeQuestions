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
    void Insertion(TreeNode*&root,vector<int>&nums){
        if(!root) return;
        Insertion(root->left,nums);
        nums.push_back(root->val);
        Insertion(root->right,nums);
    }
    int minDiffInBST(TreeNode* root) {
        vector<int>nums;
        Insertion(root,nums);
        int MinDiff = INT_MAX;
        for(int i=1;i<nums.size();i++){
            if(nums[i]-nums[i-1]<MinDiff){
                MinDiff = nums[i]-nums[i-1];
            }
        }
        return MinDiff;
    }
};