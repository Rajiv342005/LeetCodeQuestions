class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minheap;
        int count;
        for(int i=0;i<mat.size();i++){
            count=0;
            for(int j=0;j<mat[i].size();j++){
                if(mat[i][j]) count++;
                else continue;
            }
            minheap.push(make_pair(count,i));
        }
        pair<int,int>p;
        vector<int>ans(k);
        count=0;
        // sort(minheap.begin(),minheap.end());
        while(!minheap.empty() && count<k){
            p = minheap.top();
            minheap.pop();
            ans[count++] = p.second;
        }
        return ans;
    }
};