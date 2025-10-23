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
    int Balanced(TreeNode*&root,bool &ans){
        if(!root) return 0;
        int left = Balanced(root->left,ans);
        int right = Balanced(root->right,ans);
        if(abs(right-left)>1) ans =false;
        return 1+max(left,right);
    }
    bool isBalanced(TreeNode* root) {
       bool ans =true;
       Balanced(root,ans);
       return ans; 
    }
};