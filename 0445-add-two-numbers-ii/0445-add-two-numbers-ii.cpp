class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack <int>s1;
        stack <int>s2;
        stack <int> sf;
        int sum =0;
        int carry=0;
        int totalsum=0;
        ListNode *temp = l1;
        while(temp){
            s1.push(temp->val);
            temp = temp->next;
        }
        temp =l2;
        while(temp){
            s2.push(temp->val);
            temp = temp->next;
        }
        while(s1.size() && s2.size()){
            totalsum = s1.top()+s2.top()+carry;
            sum = totalsum%10;
            carry = totalsum/10;
            sf.push(sum);
            s1.pop(); s2.pop();
        }
        while(s1.size()){
            totalsum = s1.top()+carry;
            sum = totalsum%10;
            carry = totalsum/10;
            sf.push(sum);
            s1.pop();
        }
        while(s2.size()){
            totalsum = s2.top()+carry;
            sum = totalsum%10;
            carry = totalsum/10;
            sf.push(sum);
            s2.pop();
        }
        if(carry!=0){
            sf.push(carry);
            carry =0;
        }
        ListNode *head = new ListNode();
        temp =head;
        while(sf.size()){
            if(sf.size()>1){
                temp->val = sf.top();
                temp->next = new ListNode();
                temp = temp->next;
                sf.pop();
            }
            else{
                temp->val = sf.top();
                sf.pop();
            }
        }
        return head;
    }
};