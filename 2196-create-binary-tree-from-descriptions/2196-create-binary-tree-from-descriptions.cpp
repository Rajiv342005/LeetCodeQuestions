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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*>mp;
        unordered_map<int,bool>par;
        for(auto desc: descriptions){
            int parent = desc[0];
            int child = desc[1];
            int isleft = desc[2];
            if(!par.count(parent)){
                par[parent] = false;
            }
            par[child] = true; 
            TreeNode*Parent = new TreeNode(parent);
            TreeNode*Children = new TreeNode(child);
            if(mp.count(parent)){
                Parent = mp[parent];
            }
            if(mp.count(child)){
                Children = mp[child];
            }
            if(isleft){
                Parent->left = Children;
            }
            else Parent->right = Children;
            mp[parent] = Parent;
            mp[child] = Children;
        }
        for(auto node:par){
            if(node.second==false){
                return mp[node.first];
            }
        }
        return nullptr;
    }
};