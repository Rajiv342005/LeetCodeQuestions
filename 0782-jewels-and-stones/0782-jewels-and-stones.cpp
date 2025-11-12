class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        vector<int>ans(256,0);
        int count=0;
        int index=0;
        while(index<stones.size()){
            ans[stones[index]]++;
            index++;
        }
        index=0;
        while(index<jewels.size()){
            if(ans[jewels[index]]>0){
                count+=ans[jewels[index]];
                ans[jewels[index]]=0;
            }
            index++;
        }
        return count;
    }
};