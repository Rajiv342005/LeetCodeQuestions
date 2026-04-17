class Solution {
public:
    int reverse(int num){
        int num2 = 0;
        while(num>0){
            num2 = num2*10+(num%10);
            num = num/10;
        }
        return num2;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int,int>used;
        int mindist = INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(used.count(nums[i])){
                mindist = min(mindist,i-used[nums[i]]);
            }
            int rnum = reverse(nums[i]);
            used[rnum] = i;
        }
        if(mindist==INT_MAX) return -1;
        return mindist;
    }
};