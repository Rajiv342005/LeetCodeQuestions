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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* prevNode = nullptr;
        ListNode* currNode = head;
        ListNode* nextNode = head->next;
        int counter = 0;
        vector<int>CriticalIdx;
        while(currNode->next){
            if(!prevNode){
                prevNode = currNode;
                currNode = nextNode;
                nextNode = nextNode->next;
            }
            else{
                // Check for critical point.
                if(currNode->val>prevNode->val && currNode->val>nextNode->val){
                    CriticalIdx.push_back(counter);
                }
                else if(currNode->val<prevNode->val && currNode->val<nextNode->val){
                    CriticalIdx.push_back(counter);
                }
                prevNode = currNode;
                currNode = nextNode;
                nextNode = nextNode->next;
            }
            counter++;
        }
        int minDiff = INT_MAX;
        int maxDiff = INT_MIN;
        if(CriticalIdx.size()<2) return {-1,-1};
        for(int i=0;i<CriticalIdx.size()-1;i++){
            minDiff = min(minDiff,CriticalIdx[i+1]-CriticalIdx[i]);
        }
        maxDiff = CriticalIdx.back()-CriticalIdx[0];
        return {minDiff,maxDiff};
    }
};