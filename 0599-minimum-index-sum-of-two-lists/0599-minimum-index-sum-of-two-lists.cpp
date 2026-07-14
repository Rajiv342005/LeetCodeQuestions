class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        int MIS = INT_MAX;
        unordered_map<string,int>used;
        for(int i=0;i<list1.size();i++){
            used[list1[i]] = i;
        }
        for(int i=0;i<list2.size();i++){
            if(used.find(list2[i])!=used.end()){
                MIS = min(MIS,used[list2[i]]+i);
            }
        }
        vector<string>ans;
        for(int i=0;i<list2.size();i++){
            if(used.find(list2[i])!=used.end()){
                if(MIS == used[list2[i]]+i){
                    ans.push_back(list2[i]);
                }
            }
        }
        return ans;
    }
};