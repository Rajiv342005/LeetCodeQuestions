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
    int maxLevelSum(TreeNode* root) {
        int Maxlevel = 0;
        int Maxsum =INT_MIN;
        int currsum =0;
        int currlevel =1;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            currsum =0;
            while(size--){
                TreeNode*temp = q.front();
                currsum+=temp->val;
                q.pop();
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
            if(currsum>Maxsum){
                Maxsum = currsum;
                Maxlevel = currlevel;
            }
            currlevel++;
        }
        return Maxlevel;    
    }
};