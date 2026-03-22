class Solution {
public:
    int HeightBalanceBT(TreeNode*root,bool &check){
        if(!root || !check) return 0;
        else if(!root->left && !root->right) return 1;
        int lh = HeightBalanceBT(root->left,check);
        int rh = HeightBalanceBT(root->right,check);
        if(abs(rh-lh)>1) check = false;
        return 1+max(lh,rh);
    }
    bool isBalanced(TreeNode* root) {
        bool check = true;
        HeightBalanceBT(root,check);
        return check;
    }
};