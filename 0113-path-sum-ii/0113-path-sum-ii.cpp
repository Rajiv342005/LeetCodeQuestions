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
    void pathsum2(TreeNode* &root,int &target,int curr,vector<vector<int>>&ans,vector<int>nums){
        if(!root) return;
        curr = curr+root->val;
        nums.push_back(root->val);
        if(!root->left && !root->right){
            if(curr==target){
                ans.push_back(nums);
                return;
            }
            return;
        }
        pathsum2(root->left,target,curr,ans,nums);
        pathsum2(root->right,target,curr,ans,nums);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>nums;
        int curr=0;
        pathsum2(root,targetSum,curr,ans,nums);
        return ans;
    }
};