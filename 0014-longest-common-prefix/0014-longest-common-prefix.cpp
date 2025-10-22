class Solution {
public:
    string longestCommonPrefix(vector<string>& arr) {
       int num = 0;
        int index =0;
        string pref = "";
        int min = 1000;
        char c = 'c';
        for(int i=0;i<arr.size();i++){
            num = arr[i].size();
            if(num<min) min = num;
        }
        while(index<min){
            c = arr[0][index];
            for(int i=0;i<arr.size();i++){
                if(arr[i][index]!=c){
                    return pref;
                }
            }
            pref+=c;
            index++;
        }
        return pref; 
    }
};