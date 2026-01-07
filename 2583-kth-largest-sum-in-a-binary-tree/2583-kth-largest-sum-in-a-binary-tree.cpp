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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<long long>maxheap;
        queue<TreeNode*>q;
        long long currsum =0;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            currsum =0;
            while(size--){
                TreeNode*temp = q.front();
                q.pop();
                currsum+=temp->val;
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
            maxheap.push(currsum);
        }
        if(k>maxheap.size()) return -1;
        for(int i=1; i<k;i++){
            maxheap.pop();
        }
        return maxheap.top();
    }
};