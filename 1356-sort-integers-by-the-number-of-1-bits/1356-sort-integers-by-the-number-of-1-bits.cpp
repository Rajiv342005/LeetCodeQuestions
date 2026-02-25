class Solution {
public:
    int Binary1(int num){
        int count=0;
        while(num>0){
            if(num%2) count++;
            num  = num/2;
        }
        return count;
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minheap;
        for(int i=0;i<arr.size();i++){
            int count = Binary1(arr[i]);
            minheap.push({count,i});
        }
        vector<int>ans;
        while(!minheap.empty()){
            int index = minheap.top().second;
            ans.push_back(arr[index]);
            minheap.pop();
        }
        return ans;
        
    }
};