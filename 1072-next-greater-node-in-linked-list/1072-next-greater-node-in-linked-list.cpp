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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int>ans;
        int nextlarge =INT_MIN;
        ListNode*temp = head;
        ListNode*temp2 = nullptr;
        bool insert = false;
        while(temp){
            temp2 = temp->next;
            insert =false;
            while(temp2){
                if(temp2->val>temp->val){
                    ans.push_back(temp2->val);
                    insert = true;
                    break;
                }
                temp2 = temp2->next;
            }
            if(!insert) ans.push_back(0);
            temp = temp->next;
        }
        return ans;
    }
};