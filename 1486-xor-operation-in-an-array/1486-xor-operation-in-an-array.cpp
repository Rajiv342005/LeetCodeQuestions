class Solution {
public:
    int xorOperation(int n, int start) {
        int xorResult = start;
        for(int i=1;i<n;i++){
            xorResult = xorResult^(start+2*i);
        }
        return xorResult;     
    }
};