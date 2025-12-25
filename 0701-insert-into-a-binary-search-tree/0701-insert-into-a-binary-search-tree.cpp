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
    TreeNode* InsertNode(TreeNode*&root,TreeNode*&key){
        if(!root) return key;
        if(root->val>key->val){
            root->left = InsertNode(root->left,key);
        }
        else{
            root->right = InsertNode(root->right,key);
        }
        return root;
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode*key = new TreeNode(val);
        if(!root) return key;
        InsertNode(root,key);
        return root;    
    }
};