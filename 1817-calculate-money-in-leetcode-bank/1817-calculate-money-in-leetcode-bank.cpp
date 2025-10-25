class Solution {
public:
    int totalMoney(int n) {
        if(n<=7) return n*(n+1)/2;
        int rem = n%7;
        int count = n/7;
        int ans = count*28 +(count*(count-1)/2)*7+rem*(rem+1)/2+count*rem;
        return ans;
    }
};