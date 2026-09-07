class Solution {
public:
    bool checkSymmetric(TreeNode*firstNode,TreeNode*secondNode){
        if(!firstNode && !secondNode) return true;
        if(!firstNode || !secondNode) return false;
        if(firstNode->val != secondNode->val) return false;
        return checkSymmetric(firstNode->left,secondNode->right) &&
        checkSymmetric(firstNode->right,secondNode->left);
    }
    bool isSymmetric(TreeNode* root) {
        return checkSymmetric(root->left,root->right);    
    }
};