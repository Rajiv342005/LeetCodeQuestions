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
    void Number(TreeNode* &root,int current,int &sum){
        if(!root) return;
        current = current*10+root->val;
        if(!root->left && !root->right){
            sum+=current;
            return;
        }
        Number(root->left,current,sum);
        Number(root->right,current,sum);
    }
    int sumNumbers(TreeNode* root) {
        int sum =0;
        int current =0;
        Number(root,current,sum);
        return sum;
    }
};