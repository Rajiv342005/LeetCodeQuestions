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
    void path(TreeNode*&root,string s,vector<string>&ans){
        if(!root) return;
        if(abs(root->val)!=root->val){
            s+="-";
            s+=to_string(abs(root->val));
        }
        else s+=to_string(abs(root->val));
        if(!root->left && !root->right){
            ans.push_back(s);
            return ;
        }
        s+="->";
        path(root->left,s,ans);
        path(root->right,s,ans);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string s="";
        vector<string>ans;
        path(root,s,ans);
        return ans;
    }
};