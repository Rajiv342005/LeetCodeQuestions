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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==NULL) return nullptr;
        ListNode *temp = head;
        vector<int> data;
        while(temp){
            data.push_back(temp->val);
            temp = temp->next;
        }
        int index1 =left-1;
        int index2 = right-1;
        while(index1<index2){
            swap(data[index1++],data[index2--]);
        }
        temp = head;
        index1=0;
        while(temp){
            temp->val = data[index1++];
            temp = temp->next;
        }
        return head;    
    }
};