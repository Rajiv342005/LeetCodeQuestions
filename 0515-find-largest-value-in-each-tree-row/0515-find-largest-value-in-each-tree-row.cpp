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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if(root==NULL) return ans;
        int Max = INT_MIN;
        queue<TreeNode*>q;
        int size =0;
        q.push(root);
        while(!q.empty()){
            size = q.size();
            while(size){
                TreeNode *temp = q.front();
                q.pop(); size--;
                if(temp->val>Max) Max = temp->val;
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
            ans.push_back(Max);
            Max = INT_MIN;
        }
        return ans;
    }
};