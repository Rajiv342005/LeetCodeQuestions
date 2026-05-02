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
    int find(vector<int>inorder,int target,int start,int end){
        for(int i=start;i<=end;i++){
            if(inorder[i]==target) 
            return i;
        }
        return -1;
    }
    TreeNode*BT(vector<int>preorder,vector<int>inorder,int start,int end,int index){
        if(start>end) return nullptr;
        TreeNode*root = new TreeNode(preorder[index]);
        int idx = find(inorder,preorder[index],start,end);
        root->left = BT(preorder,inorder,start,idx-1,index+1);
        root->right = BT(preorder,inorder,idx+1,end,index+(idx-start)+1);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode*root = BT(preorder,inorder,0,preorder.size()-1,0);
        return root;
    }
};