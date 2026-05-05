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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL){
            return nullptr;
        }
        ListNode *temp = head;
        ListNode *temp2 = head;
        int count =0;
        while(temp){
            count++;
            temp = temp->next;
        }
        if(k>=count){
            k = k%count;
        }
        while(k!=0){
            temp=temp2;
            for(int j=2;j<count;j++){
                temp= temp->next;
            }
            if(temp->next){
                temp->next->next = temp2;
                temp2 = temp->next;
                temp->next = NULL;
            }
            k--;
        }
        return temp2;
    }
};