class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_set<int>used1;
        unordered_set<int>used2;
        int counter =0;
        vector<int>nums(A.size());
        for(int i=0;i<A.size();i++){
            used1.insert(A[i]);
            used2.insert(B[i]);
            if(A[i]==B[i]) counter++;
            else{
                if(used1.count(B[i])) counter++;
                if(used2.count(A[i])) counter++;
            }
            nums[i] = counter;
        }
        return nums;
    }
};