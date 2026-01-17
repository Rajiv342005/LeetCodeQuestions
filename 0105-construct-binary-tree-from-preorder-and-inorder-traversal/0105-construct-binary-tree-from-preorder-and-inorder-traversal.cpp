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
    int Search(vector<int>&inorder,int start,int end,int key){
        for(int i=start;i<=end;i++){
            if(inorder[i]==key) return i;
        }
        return -1;
    }
    TreeNode* BinaryTree(vector<int>&preorder,vector<int>&inorder,int start,int end,int &pre){
        if(start>end) return nullptr;
        int curr = preorder[pre++];
        TreeNode*root = new TreeNode(curr);
        if(start==end) return root;
        int pos = Search(inorder,start,end,curr);
        root->left = BinaryTree(preorder,inorder,start,pos-1,pre);
        root->right = BinaryTree(preorder,inorder,pos+1,end,pre);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int end = preorder.size()-1;
        int pre = 0;
        TreeNode*BT = BinaryTree(preorder,inorder,0,end,pre);
        return BT;    
    }
};