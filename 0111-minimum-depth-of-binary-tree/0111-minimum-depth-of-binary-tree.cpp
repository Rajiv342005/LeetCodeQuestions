class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        if(!root->left && !root->right) return 1;
        int left = minDepth(root->left);
        int right = minDepth(root->right);
        if(left==0) return 1+right;
        else if(right ==0 ) return 1+left;
        return 1+min(left,right);
    }
};