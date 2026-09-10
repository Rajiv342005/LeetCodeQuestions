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
    pair<int,int> AverageSubtreeCheck(TreeNode* &root,int &count){
        if(!root) return {0,0};
        pair<int,int>left,right;
        left  = AverageSubtreeCheck(root->left,count); 
        right = AverageSubtreeCheck(root->right,count);
        int totalsum = left.first + right.first + root->val;
        int totalNode = left.second + right.second + 1;
        int avg = totalsum/totalNode;
        if(avg == root->val) count++;
        return {totalsum,totalNode};
    }
    int averageOfSubtree(TreeNode* root) {
        int count = 0;
        AverageSubtreeCheck(root,count);
        return count;
    }
};