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
    ListNode* doubleIt(ListNode* head) {
        ListNode *temp = head;
        if(!temp->next && temp->val<5){
            temp->val = (temp->val)*2;
            return head;
        }
        string s="";
        stack<int> st;
        while(temp){
            s+=(temp->val+'0');
            temp= temp->next;
        }
        int index =s.size()-1;
        int totalsum=0;
        int carry=0;
        int sum =0;
        while(index>=0){
            totalsum = (s[index]-'0')*2+carry;
            carry = totalsum/10;
            sum = totalsum%10;
            st.push(sum);
            index--;
        }
        if(carry!=0) st.push(carry);
        ListNode*temp2 =new ListNode();
        temp = temp2;
        while(st.size()-1){
            temp->val = st.top(); st.pop();
            temp->next = new ListNode();
            temp = temp->next;
        }
        temp->val = st.top();st.pop();
        return temp2;
    }
};