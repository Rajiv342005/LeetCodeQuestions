class Solution {
public:
    bool canReach(vector<int>& nums, int start) {
        vector<bool>visited(nums.size(),0);
        queue<int>q;
        q.push(start);
        visited[start] =1;
        while(!q.empty()){
            int idxNode = q.front();
            q.pop();
            if(nums[idxNode]==0) return true;
            if((idxNode-nums[idxNode])>=0 && visited[idxNode-nums[idxNode]]==0){
                q.push(idxNode-nums[idxNode]);
                visited[idxNode-nums[idxNode]]=1;
            }
            if((idxNode+nums[idxNode])<nums.size() && visited[idxNode+nums[idxNode]]==0){
                q.push(idxNode+nums[idxNode]);
                visited[idxNode+nums[idxNode]]=1;
            }
        }
        return false;
    }
};