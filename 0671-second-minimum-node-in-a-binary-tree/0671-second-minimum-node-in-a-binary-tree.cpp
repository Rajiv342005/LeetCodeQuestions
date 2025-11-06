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
    void print(TreeNode*root,vector<int>&nums){
        if(!root) return;
        nums.push_back(root->val);
        print(root->left,nums);
        print(root->right,nums);
    }
    int findSecondMinimumValue(TreeNode* root) {
        vector<int>nums;
        print(root,nums);
        sort(nums.begin(),nums.end());
        int lower = nums[0];
        int index=0;
        while(index<nums.size() && nums[index]==lower){
            index++;
        }
        if(index>=nums.size()) return -1;
        else 
        return nums[index];
    }
};