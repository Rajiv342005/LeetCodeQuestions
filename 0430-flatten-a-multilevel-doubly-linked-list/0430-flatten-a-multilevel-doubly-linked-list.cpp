/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    void NodeTraversal(Node* &root,vector<int>&store){
        if(!root) return;
        store.push_back(root->val);
        NodeTraversal(root->child,store);
        NodeTraversal(root->next,store);
    }
    Node* flatten(Node* head) {
        vector<int>store;
        NodeTraversal(head,store);
        Node *newList = new Node(0);
        Node*temp = newList;
        Node*prevNode = nullptr;
        for(int i=0;i<store.size();i++){
            temp->next = new Node(store[i]);
            temp =  temp->next;
            temp->prev = prevNode;
            prevNode = temp;
        }
        return newList->next;
    }
};