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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>nums;
        if(root==NULL) return nums;
        vector<int>nums2;
        queue<TreeNode*>q;
        int size =0;
        q.push(root);
        while(!q.empty()){
            size = q.size();
            while(size){
                TreeNode*temp = q.front();
                q.pop();
                size--;
                nums2.push_back(temp->val);
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
            nums.push_back(nums2);
            nums2.clear();
        }
        return nums;
    }
};