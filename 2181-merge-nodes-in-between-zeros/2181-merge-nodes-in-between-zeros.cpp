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
    ListNode* mergeNodes(ListNode* head) {
        ListNode*temp = head->next;
        int sum = 0;
        ListNode*sumLL = new ListNode(0);
        ListNode*ans = sumLL;
        while(temp){
            if(temp->val==0){
                sumLL->next = new ListNode(sum);
                sumLL = sumLL->next;
                sum=0;
            }
            sum+=temp->val;
            temp = temp->next;
        }
        return ans->next;
    }
};