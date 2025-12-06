class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int,int>>p;
        for(int i=0;i<score.size();i++){
            p.push(make_pair(score[i],i));
        }
        vector<string>ans(score.size());
        pair<int,int>data;
        int count=0;
        int rank;
        while(!p.empty()){
            count++;
            data = p.top();
            rank = data.second;
            p.pop();
            if(count==1) ans[rank] = "Gold Medal";
            else if(count==2) ans[rank] = "Silver Medal";
            else if(count==3) ans[rank] = "Bronze Medal";
            else ans[rank] = to_string(count);   
        }
        return ans;
    }
};