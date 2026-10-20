class Solution {
public:
    void RemoveNonPrime(vector<bool>&isPrime,int num, int n){
        for(int i=num ; i<n ; i+=num){
            isPrime[i] = 0;
        }
        return;     
    }
    int countPrimes(int n) {
        vector<bool>isPrime(n,1);
        int count = 0;
        for(int i=2;i<n;i++){
            if(isPrime[i]){
                count++;
                RemoveNonPrime(isPrime,i,n);
            }
        }
        return count;
    }
};