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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL){
            return nullptr;
        }
        if(head->next==NULL){
            return head;
        }
        ListNode *pointer1 = head;
        ListNode *pointer2 = head->next;
        while(pointer2 && pointer1){
            int temp = pointer1->val;
            pointer1->val = pointer2->val;
            pointer2->val = temp;
            if(pointer1->next->next && pointer2->next->next){
                pointer1 = pointer1->next->next;
                pointer2 = pointer2->next->next;
            }
            else{
                break;
            }
        }
        return head;
    }
};