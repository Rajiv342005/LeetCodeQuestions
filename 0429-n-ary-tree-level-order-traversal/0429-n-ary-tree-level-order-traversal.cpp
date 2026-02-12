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
    vector<vector<int>> levelOrder(Node* root) {
        if(!root) return {};
        vector<vector<int>>ans;
        vector<int>nums;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            while(size--){
                Node*temp = q.front();
                nums.push_back(temp->val);
                q.pop();
                vector<Node*>child = temp->children;
                for(int i=0;i<child.size();i++){
                    q.push(child[i]);
                }
            }
            ans.push_back(nums);
            nums.clear();    
        }
        return ans;    
    }
};