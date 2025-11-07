class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int currwealth=0;
        int Maxwealth=0;
        for(int i=0;i<accounts.size();i++){
            for(int j=0;j<accounts[i].size();j++){
                currwealth+=accounts[i][j];
            }
            if(currwealth>Maxwealth) Maxwealth=currwealth;
            currwealth=0;
        }
        return Maxwealth;
    }
};