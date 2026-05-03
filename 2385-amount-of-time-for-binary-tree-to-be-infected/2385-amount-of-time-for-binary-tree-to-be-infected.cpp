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
    void CheckNode(TreeNode*root,int target,TreeNode*&temp){
        if(!root || temp) return;
        if(root->val==target){
            temp = root;
            return;
        }
        CheckNode(root->left,target,temp);
        CheckNode(root->right,target,temp);
        return;
    }
    int InfectTree(TreeNode*root,int target,int &timer){
        if(!root) return 0;
        if(root->val==target) return -1;
        int left = InfectTree(root->left,target,timer);
        int right = InfectTree(root->right,target,timer);
        if(left>=0 && right>=0) return 1+max(left,right);
        else if(left<0){
            timer = max(timer,abs(left)+right);
            return left-1;
        }
        else{
            timer = max(timer,abs(right)+left);
            return right-1;
        }
    }
    int getHeight(TreeNode*root){
        if(!root) return 0;
        return 1+max(getHeight(root->left),getHeight(root->right));
    }
    int amountOfTime(TreeNode* root, int target) {
        int timer =0;
        InfectTree(root,target,timer);
        TreeNode*temp = NULL;
        CheckNode(root,target,temp);
        int height = getHeight(temp);
        return max(timer,height-1);
    }
};