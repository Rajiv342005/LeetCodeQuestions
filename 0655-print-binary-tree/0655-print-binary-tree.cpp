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
    int BTHeight(TreeNode*root){
        if(!root) return 0;
        if(!root->left && !root->right) return 0;
        return 1+max(BTHeight(root->left),BTHeight(root->right));
    }
    void InsertNode(TreeNode*&root,vector<vector<string>>&ans,int r,int c){
        if(!root) return;
        ans[r][c]+=to_string(root->val);
        int exp = ans.size()-r-2;
        int pow = (exp >= 0) ? (1 << exp) : 0; 
        int rightcol = c+pow;
        int leftcol = c-pow;
        InsertNode(root->left,ans,r+1,leftcol);
        InsertNode(root->right,ans,r+1,rightcol);
    }
    vector<vector<string>> printTree(TreeNode* root) {
        int height = BTHeight(root);
        int row = height+1;
        int col = pow(2,row)-1;
        vector<vector<string>>ans(row,vector<string>(col,""));
        int r  =0;
        int c = (col-1)/2; 
        InsertNode(root,ans,r,c);
        return ans;
    }
};