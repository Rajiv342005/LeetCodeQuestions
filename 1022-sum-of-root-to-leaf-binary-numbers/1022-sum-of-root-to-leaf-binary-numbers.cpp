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
    int binaryToDeci(string s){
        int deci =0;
        for(int i=0;i<s.size();i++){
            deci = s[i]+ deci*2;
        }
        return deci;
    }
    void DFS(TreeNode*&root,string s,int &sum){
        if(!root) return;
        s+=root->val;
        if(!root->left && !root->right){
            sum+=binaryToDeci(s);
            return;
        }
        DFS(root->left,s,sum);
        DFS(root->right,s,sum);
        return;
    }
    int sumRootToLeaf(TreeNode* root) {
       if(!root) return 0;
       int sum =0;
       string s = "";
       DFS(root,s,sum);
       return sum; 
    }
};