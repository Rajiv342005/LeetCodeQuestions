class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int shrinkPointer = 0;
        int expandPointer = 0;
        int maxLength = 0;
        unordered_map<int,int>used;
        int n = fruits.size();
        int currdistinct = 0;
        while(expandPointer<n){
            used[fruits[expandPointer]]++;
            currdistinct = used.size();
            if(currdistinct<=2){
                maxLength = max(maxLength,expandPointer-shrinkPointer+1);
            }
            else{
                while(shrinkPointer<expandPointer && currdistinct>2){
                    if(used[fruits[shrinkPointer]]==1){
                        used.erase(fruits[shrinkPointer]);
                        currdistinct --;
                    }
                    else used[fruits[shrinkPointer]]--;
                    shrinkPointer++;
                }
            }
            expandPointer++;
        }
        return maxLength;
    }
};