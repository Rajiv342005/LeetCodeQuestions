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
    void checkMax(TreeNode *&root,int MaxAnsc,int &MaxDiff,int MinAnsc){
        if(!root) return;
        if(abs(MaxAnsc-root->val)>MaxDiff) MaxDiff= abs(MaxAnsc-root->val);
        if(abs(MinAnsc-root->val)>MaxDiff) MaxDiff= abs(MinAnsc-root->val);
        MaxAnsc = max(MaxAnsc,root->val);
        MinAnsc = min(MinAnsc,root->val);
        checkMax(root->left,MaxAnsc,MaxDiff,MinAnsc);
        checkMax(root->right,MaxAnsc,MaxDiff,MinAnsc);
        return;
    }
    int maxAncestorDiff(TreeNode* root) {
        int MaxAnsc = root->val;
        int MinAnsc = root->val;
        int MaxDiff = INT_MIN;
        checkMax(root->left,MaxAnsc,MaxDiff,MinAnsc);
        checkMax(root->right,MaxAnsc,MaxDiff,MinAnsc);
        return MaxDiff;
    }
};