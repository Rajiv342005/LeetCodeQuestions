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
    void TwoSumChecker(TreeNode*root,unordered_map<int,int>&m,int target,bool &ans){
        if(!root || ans) return;
        int find = target-root->val;
        if(m.count(find)){
            ans = true;
        }
        else{
            m[root->val]++;
        }
        TwoSumChecker(root->left,m,target,ans);
        TwoSumChecker(root->right,m,target,ans);
    }
    bool findTarget(TreeNode* root, int target) {
        unordered_map<int,int>m;
        bool ans = false;
        TwoSumChecker(root,m,target,ans);
        return ans;
    }
};