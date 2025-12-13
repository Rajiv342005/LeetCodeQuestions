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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int>used(nums.begin(),nums.end());
        ListNode*temp = head;
        ListNode*curr = new ListNode();
        ListNode *ans = curr;
        while(temp){
            if(used.count(temp->val)) temp = temp->next;
            else{
                curr->next = new ListNode(temp->val);
                curr = curr->next;
                temp = temp->next;
            }
        }
        return ans->next;    
    }
};