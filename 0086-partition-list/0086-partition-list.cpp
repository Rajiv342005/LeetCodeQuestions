/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        vector<int>ans;
        ListNode *temp = head;
        while(temp){
            if(temp->val<x) ans.push_back(temp->val);
            temp = temp->next;
        }
        temp = head;
        while(temp){
            if(temp->val>=x) ans.push_back(temp->val);
            temp = temp->next;
        }
        int index=0;
        temp = head;
        while(temp){
            temp->val=ans[index++];
            temp = temp->next;
        }
        return head;
    }
};