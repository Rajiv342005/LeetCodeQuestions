class Solution {
public:
    int DiameterBT(TreeNode*&root,int &ans){
        if(!root) return 0;
        if(!root->left && !root->right) return 1;
        int left = DiameterBT(root->left,ans);
        int right = DiameterBT(root->right,ans);
        ans = max(ans,left+right);
        return 1+max(left,right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans =0;
        DiameterBT(root,ans);
        return ans;     
    }
};