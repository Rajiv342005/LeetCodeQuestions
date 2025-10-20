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
    void reorderList(ListNode* head) {
        if(head->next==NULL) return;
        ListNode *temp = head;
        vector<int> nums;
        stack<int> st;
        while(temp){
            nums.push_back(temp->val);
            st.push(temp->val);
            temp = temp->next;
        }
        temp = head;
        int count =0; int i=0;
        while(temp){
            if(count==0){
                temp->val = nums[i++];
            }
            else{
                temp->val = st.top();
                st.pop();
            }
            count = (count+1)%2;
            temp = temp->next;
        }
        return;
    }
};