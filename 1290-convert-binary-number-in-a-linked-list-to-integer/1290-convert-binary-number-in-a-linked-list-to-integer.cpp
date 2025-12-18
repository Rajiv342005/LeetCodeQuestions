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
    int getDecimalValue(ListNode* head) {
        ListNode*temp = head;
        int num=1; 
        int Num=0;
        while(temp){
            num*=2;
            temp = temp->next;
        }
        temp = head;
        num/=2;
        while(temp){
            Num+=temp->val*num;
            num/=2;
            temp = temp->next;
        }
        return Num;    
    }
};