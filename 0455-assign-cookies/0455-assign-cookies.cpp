class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int childleft = g.size();
        int cookiesleft = s.size();
        int Happychild = 0;
        while(childleft>0 && cookiesleft>0){
            if(g[childleft-1]<=s[cookiesleft-1]){
                Happychild++;
                childleft--;
                cookiesleft--;
            }
            else childleft--;
        }
        return Happychild;
    }
};