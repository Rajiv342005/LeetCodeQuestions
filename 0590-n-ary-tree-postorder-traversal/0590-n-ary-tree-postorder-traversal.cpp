/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void PostOrderTraversal(Node*root,vector<int>&post){
        if(!root)  return;
        vector<Node*>child = root->children;
        if(!child.size()){
            post.push_back(root->val);
            return;
        }
        else{
            for(int i=0;i<child.size();i++){
                PostOrderTraversal(child[i],post);
            }
            post.push_back(root->val);
            return;
        }
    }
    vector<int> postorder(Node* root) {
        if(!root) return {};
        vector<int>post;
        PostOrderTraversal(root,post);
        return post;    
    }
};