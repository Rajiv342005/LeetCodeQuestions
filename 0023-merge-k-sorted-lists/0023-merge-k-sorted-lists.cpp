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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // if(lists.size()==0) return nullptr;
        ListNode*temp = nullptr;
        vector<int>ans;
        for(int i=0;i<lists.size();i++){
            temp = lists[i];
            if(temp==NULL) continue;
            else{
            while(temp){
                ans.push_back(temp->val);
                temp = temp->next;
            }
            }
        }
        sort(ans.begin(),ans.end());
        if(ans.size()==0) return nullptr;
        ListNode*list = new ListNode(ans[0]);
        temp = list;
        for(int i=1;i<ans.size();i++){
            temp->next = new ListNode(ans[i]);
            temp = temp->next;
        }
        return list;  
    }
};