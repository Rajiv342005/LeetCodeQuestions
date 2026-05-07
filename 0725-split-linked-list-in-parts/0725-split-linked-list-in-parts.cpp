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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*>nums(k);
        ListNode*temp = head;
        int size =0;
        while(temp){
            temp = temp->next;
            size++;
        }
        int interval = size/k;
        int extra = size%k;
        temp = head;
        int idx =0;
        ListNode*currNode = new ListNode(0);
        ListNode*node = currNode;
        int currsize =0;
        while(temp){
            currNode->next = new ListNode(temp->val);
            currNode = currNode->next;
            currsize++;
            if(extra){
                if(currsize==interval+1){
                    nums[idx++] = node->next;
                    currNode = new ListNode(0);
                    node = currNode;
                    currsize =0;
                    extra--;   
                }
            }
            else{
                if(currsize==interval){
                    nums[idx++] = node->next;
                    currNode = new ListNode(0);
                    node = currNode; 
                    currsize =0;   
                }
            }
            temp = temp->next;
        }
        return nums;
    }
};