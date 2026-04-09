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
    TreeNode* addOneRow(TreeNode* root, int val, int d) {
        if(d==1){
            TreeNode*newNode = new TreeNode(val);
            newNode->left = root;
            return newNode;
        }
        int depth = 1;
        queue<TreeNode*>q;
        q.push(root);
        bool update = false; 
        while(!q.empty()){
            int size = q.size();
            while(size--){
                TreeNode* temp = q.front();
                q.pop();
                if((depth+1)==d){
                    update = true;
                    TreeNode* leftNode = new TreeNode(val);
                    TreeNode* rightNode = new TreeNode(val);
                    leftNode->left = temp->left;
                    rightNode->right = temp->right;
                    temp->left = leftNode;
                    temp->right = rightNode;
                }
                else{
                    if(temp->left){
                       q.push(temp->left);
                    }
                    if(temp->right){
                        q.push(temp->right);
                    }
                } 
            }
            if(update) return root;
            depth++;
        }
        return root;
    }
};