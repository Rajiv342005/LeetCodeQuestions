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
    int deepestLeavesSum(TreeNode* root) {
        int sum =0;
        int currlevel = 0;
        queue<TreeNode*>q;
        q.push(root);
        int size;
        while(!q.empty()){
            int n = q.size();
            currlevel = 0;
            while(n--){
                TreeNode*temp = q.front();
                q.pop();
                if(temp->left)
                q.push(temp->left);
                if(temp->right)
                q.push(temp->right);
                currlevel+=temp->val;
            }
            sum = currlevel;
        }
        return sum;
    }
};