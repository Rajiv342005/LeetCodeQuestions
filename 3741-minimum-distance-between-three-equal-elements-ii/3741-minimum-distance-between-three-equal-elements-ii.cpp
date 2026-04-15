class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int,queue<int>>used;
        int mindist = INT_MAX;
        int first,second,third;
        for(int i=0;i<nums.size();i++){
            used[nums[i]].push(i);
            if(used[nums[i]].size()==3){
                first = used[nums[i]].front(); used[nums[i]].pop();
                second = used[nums[i]].front(); used[nums[i]].pop();
                third = used[nums[i]].front(); used[nums[i]].pop();
                mindist = min(mindist,abs(first-second)+abs(second-third)+abs(third-first));
                used[nums[i]].push(first);
                used[nums[i]].push(second);
                used[nums[i]].push(third);
            }
            else if(used[nums[i]].size()>=3){
                used[nums[i]].pop();
                first = used[nums[i]].front(); used[nums[i]].pop();
                second = used[nums[i]].front(); used[nums[i]].pop();
                third = used[nums[i]].front(); used[nums[i]].pop();
                mindist = min(mindist,abs(first-second)+abs(second-third)+abs(third-first));
                used[nums[i]].push(first);
                used[nums[i]].push(second);
                used[nums[i]].push(third);
            }
            else continue;
        }
        if(mindist==INT_MAX) return -1;
        return mindist;
    }
};