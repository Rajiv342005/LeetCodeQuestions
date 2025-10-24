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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>nums;
        if(root==NULL) return nums;
        deque<TreeNode*>q;
        int size =0;
        q.push_back(root);
        while(!q.empty()){
            nums.push_back(q.back()->val);
            size = q.size();
            while(size){
                TreeNode *temp = q.front();
                q.pop_front();
                size--;
                if(temp->left){
                    q.push_back(temp->left);
                }
                if(temp->right){
                    q.push_back(temp->right);
                }
            }   
        }
        return nums;
    }
};