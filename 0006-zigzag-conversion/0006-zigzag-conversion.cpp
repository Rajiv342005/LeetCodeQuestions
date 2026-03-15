class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1) return s;
        vector<vector<char>>nums(numRows);
        bool asc =false;
        int currRow =0;
        for(int i=0;i<s.size();i++){
            if(asc){
                nums[currRow].push_back(s[i]);
                currRow--;
                if(currRow==-1){
                    currRow+=2;
                    asc = !asc;
                }
            }
            else{
                nums[currRow].push_back(s[i]);
                currRow++;
                if(currRow==numRows){
                    currRow-=2;
                    asc = !asc;
                }
            }
        }
        string s1 ="";
        for(auto &it:nums){
            for(auto &ch:it){
                s1+=ch;
            }
        }
        return s1;
    }
};