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
    void PreOrderTraversal(TreeNode*&root ,string &s){
        if(!root) return;
        string data = to_string(root->val);
        s+=("("+data);
        if(!root->left && root->right){
            s+="()";
        }
        PreOrderTraversal(root->left,s);
        PreOrderTraversal(root->right,s);
        s+=")";
        return;
    }
    string tree2str(TreeNode* root) {
        string s="";
        PreOrderTraversal(root,s);
        s = s.substr(1,s.size()-2);
        return s;  
    }
};