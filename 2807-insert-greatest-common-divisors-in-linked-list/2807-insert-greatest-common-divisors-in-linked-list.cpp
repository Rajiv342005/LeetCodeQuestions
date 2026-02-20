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
    int GCD(int first,int second){
        int end = min(first,second);
        int gcd = 1;
        for(int i=1;i<=end;i++){
            if(first%i==0 && second%i==0){
                gcd = i;
            }
        }
        return gcd;
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode*temp = head;
        while(temp && temp->next){
            int first = temp->val;
            int second = temp->next->val;
            int gcd = GCD(first,second);
            ListNode*newNode = new ListNode(gcd,temp->next);
            temp->next = newNode;
            temp = newNode;
            temp = temp->next;
        }
        return head;
    }
};