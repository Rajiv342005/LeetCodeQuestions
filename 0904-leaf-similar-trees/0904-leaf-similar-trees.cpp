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
    void Root1Leaf(TreeNode* &root,queue<int>&match){
        if(!root) return;
        if(!root->left && !root->right){
            match.push(root->val);
        }
        Root1Leaf(root->left,match);
        Root1Leaf(root->right,match);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        queue<int>match1;
        queue<int>match2;
        Root1Leaf(root1,match1);
        Root1Leaf(root2,match2);
        if(match1.size()!=match2.size()) return false;
        while(!match1.empty()){
            if(match1.front()==match2.front()){
                match1.pop();
                match2.pop();
            }
            else{
                return false;
            }
        }
        return true;
    }
};