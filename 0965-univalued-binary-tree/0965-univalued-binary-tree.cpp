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
    bool CheckUniValued(TreeNode*&root,int val){
        if(!root) return true;
        if(!root->left && !root->right) return root->val==val;
        bool left = CheckUniValued(root->left,val);
        bool right = CheckUniValued(root->right,val);
        return left&&right&&root->val==val;
    }
    bool isUnivalTree(TreeNode* root) {
        if(!root) return 1;
        int val = root->val;
        return CheckUniValued(root,val);
    }
};