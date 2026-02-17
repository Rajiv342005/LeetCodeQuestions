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
    TreeNode* MBT(vector<int>&nums,int start,int end){
        if(start>=end) return nullptr;
        int max =start;
        for(int i=start;i<end;i++){
            if(nums[i]>nums[max]) max = i;
        }
        TreeNode* root = new TreeNode(nums[max]);
        root->left = MBT(nums,start,max);
        root->right =MBT(nums,max+1,end);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return MBT(nums,0,nums.size());
    }
};