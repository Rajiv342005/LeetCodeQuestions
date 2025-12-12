class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> s(candyType.begin(), candyType.end());
        int uniqueTypes = s.size();
        int maxSheCanEat = candyType.size() / 2;
        return min(uniqueTypes, maxSheCanEat);
    }
};
