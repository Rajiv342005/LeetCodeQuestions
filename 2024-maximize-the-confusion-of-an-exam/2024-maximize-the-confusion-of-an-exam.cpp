class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int maxLength,totalTrue,totalFalse,expandPointer,shrinkPointer,currOperation;
        maxLength=totalTrue=totalFalse=expandPointer=shrinkPointer=currOperation=0;
        while(expandPointer<answerKey.size()){
            if(answerKey[expandPointer]=='T') totalTrue++;
            else totalFalse++;
            currOperation = min(totalTrue,totalFalse);
            if(currOperation<=k){
                maxLength = max(maxLength,totalTrue+totalFalse);
            }
            else{
                while(shrinkPointer<expandPointer && currOperation>k){
                    if(answerKey[shrinkPointer]=='T') totalTrue--;
                    else totalFalse--;
                    shrinkPointer++;
                    currOperation = min(totalTrue,totalFalse);
                }
            }
            expandPointer++;
        }
        return maxLength;
    }
};