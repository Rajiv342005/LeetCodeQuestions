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
    int find(vector<int>nums,int target,int start,int end){
        for(int i=start;i<=end;i++){
            if(nums[i]==target) return i;
        }
        return -1;
    }
    TreeNode* BT(vector<int>inorder,vector<int>postorder,int start,int end,int index){
        if(start>end) return nullptr;
        TreeNode*root = new TreeNode(postorder[index]);
        int idx = find(inorder,postorder[index],start,end);
        root->left = BT(inorder,postorder,start,idx-1,index-(end-idx+1));
        root->right = BT(inorder,postorder,idx+1,end,index-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        TreeNode*root = BT(inorder,postorder,0,postorder.size()-1,postorder.size()-1);
        return root;
    }
};