class Solution {
public:
    int minOperations(vector<string>& logs) {
        int operation=0;
        int index=0;
        while(index<logs.size()){
            if(logs[index]=="../"){
                if(operation>0)
                operation--;
            }
            else if(logs[index]=="./"){
                operation+=0;
            }
            else{
                operation++;
            }
            index++;
        }
        if(operation>=0) return operation;
        else return 0;
    }
};