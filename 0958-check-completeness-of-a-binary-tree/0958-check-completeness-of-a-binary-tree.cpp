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
    bool isCompleteTree(TreeNode* root) {
        if(!root) return true;
        queue<TreeNode*>q;
        q.push(root);
        bool flag = false;
        while(!q.empty()){
            TreeNode*temp = q.front();
            q.pop();
            if(temp->left && !flag){
                q.push(temp->left);
            }
            else{
                if(temp->left && flag) return false;
                else flag = true;
            }
            if(temp->right && !flag){
                q.push(temp->right);
            }
            else{
                if(temp->right && flag) return false;
                else flag = true;
            }
        }
        return true;
    }
};