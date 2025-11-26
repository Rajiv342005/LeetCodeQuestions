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
    ListNode* removeNodes(ListNode* head) {
        stack<int>st;
        ListNode*temp = head;
        while(temp){
            if(st.empty()){
                st.push(temp->val);
            }
            else{
                if(temp->val<st.top()){
                    st.push(temp->val);
                }
                else {
                    while(!st.empty() && temp->val>st.top()){
                        st.pop();
                    }
                    st.push(temp->val);
                }
            }
            temp = temp->next;
        }
        ListNode*prev = nullptr;
        ListNode*curr = nullptr;
        while(!st.empty()){
            curr = new ListNode(st.top());
            st.pop();
            curr->next = prev;
            prev = curr;
            curr =  nullptr;
        }
        return prev;
    }
};