class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        unordered_set<int>filledbucket;
        int Unplacedfruit = 0;
        int placed = false;
        for(int i=0;i<fruits.size();i++){
            placed = false;
            for(int j=0;j<baskets.size();j++){
                if(filledbucket.count(j)) continue;
                if(fruits[i]<=baskets[j]){
                    placed = true;
                    filledbucket.insert(j);
                    break;
                }
            }
            if(!placed) Unplacedfruit++;
        }
        return Unplacedfruit;
    }
};