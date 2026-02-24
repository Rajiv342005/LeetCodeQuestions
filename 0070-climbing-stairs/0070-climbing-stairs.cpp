class Solution {
public:
    int climbStairs(int n) {
        if(n<=2) return n;
        int first = 1;
        int second = 2;
        int final;
        for(int i=3;i<=n;i++){
            final = first+second;
            first = second;
            second = final;
        }
        return final;
    }
};