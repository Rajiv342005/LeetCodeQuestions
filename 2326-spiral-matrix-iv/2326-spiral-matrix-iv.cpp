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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>>SM(m,vector<int>(n,-1));
        int rowstart =1;
        int colstart =0;
        int row =0;
        int col =0;
        char currdir = 'R';
        while(head){
            if(currdir=='R'){
                SM[row][col] = head->val;
                if(col==n-1){
                    currdir = 'D';
                    row++;
                    n--;
                }
                else col++;
            }
            else if(currdir=='D'){
                SM[row][col] = head->val;
                if(row==m-1){
                    currdir = 'L';
                    col--;
                    m--;
                }
                else row++;
            }
            else if(currdir=='L'){
                SM[row][col] = head->val;
                if(col==colstart){
                    currdir = 'U';
                    row--;
                    colstart++;
                }
                else col--;
            }
            else{
                SM[row][col] = head->val;
                if(row==rowstart){
                    currdir = 'R';
                    col++;
                    rowstart++;
                }
                else row--;
            }
            head = head->next;
        }
        return SM;
    }
};