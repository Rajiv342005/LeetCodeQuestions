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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL) return ans;
        vector<int>nums;
        queue<TreeNode*>q;
        bool revers = false;
        TreeNode*temp = nullptr;
        int size =0;
        q.push(root);
        while(!q.empty()){
            int size =q.size();
            while(size){
                temp = q.front();
                q.pop(); size--;
                nums.push_back(temp->val);
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
            if(revers){
                reverse(nums.begin(),nums.end());
            }
            revers = !revers;
            ans.push_back(nums);
            nums.clear();
        }
        return ans;
    }
};