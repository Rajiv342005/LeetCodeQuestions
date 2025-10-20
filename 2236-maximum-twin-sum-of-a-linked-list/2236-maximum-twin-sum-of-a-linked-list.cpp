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
    int pairSum(ListNode* head) {
        ListNode *temp = head;
        int pointer1=0;
        int pointer2 =-1;
        vector<int>nums;
        int currentsum =0;
        int maxsum = 0;
        while(temp){
            pointer2++;
            nums.push_back(temp->val);
            temp = temp->next;
        }
        while(pointer1<pointer2){
            currentsum = nums[pointer1]+nums[pointer2];
            if(currentsum>maxsum) maxsum=currentsum;
            pointer1++;
            pointer2--;
        }
        return maxsum;    
    }
};