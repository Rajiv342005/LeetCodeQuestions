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
    // Pair<SumofallSubtree,NoOfNodes>
    pair<int,int> CountavgSubtree(TreeNode*&root,int &ans){
        if(!root) return {0,0};
        pair<int,int>left,right;
        left = CountavgSubtree(root->left,ans);
        right = CountavgSubtree(root->right,ans); 
        int sum = left.first + right.first;
        int node = left.second+right.second;
        int avg = (root->val+sum)/(node+1);
        if(avg==root->val) ans++;
        return {sum+root->val,node+1};
    }
    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        CountavgSubtree(root,ans);
        return ans;
    }
};