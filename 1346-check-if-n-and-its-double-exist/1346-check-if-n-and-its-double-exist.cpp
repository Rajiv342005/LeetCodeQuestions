class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<double>used;
        for(int i=0;i<arr.size();i++){
            double find1 = arr[i]*2;
            double find2 = arr[i]/2.0;
            if(used.count(find1) || used.count(find2)) return true;
            used.insert(arr[i]);
        }
        return false;
    }
};