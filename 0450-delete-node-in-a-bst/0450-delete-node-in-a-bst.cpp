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
    TreeNode* MinValue(TreeNode*root){
        TreeNode*current = root;
        while(current && current->left){
            current = current->left;
        }
        return current;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return nullptr;
        if(root->val==key){
            //0-children
            if(!root->left && !root->right){
                delete root;
                return nullptr;
            }
            //1-children-leftpresent
            else if(!root->right && root->left){
                TreeNode*temp = root->left;
                delete root;
                return temp;
            }
            //1-children-rightpresent
            else if(!root->left && root->right){
                TreeNode*temp = root->right;
                delete root;
                return temp;
            }
            //2-children
            else{
                TreeNode*temp = MinValue(root->right);
                root->val = temp->val;
                root->right = deleteNode(root->right,temp->val);
                return root;
            }
        }
        else if(root->val>key){
            root->left = deleteNode(root->left,key);
        }
        else root->right = deleteNode(root->right,key);
        return root;   
    }
};