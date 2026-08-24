class Solution {
public:
    void InsertPrimefactor(int n,unordered_map<int,int>&freq){
        for(int i=2;i*i<=n;i++){
            while(n%i==0){
                freq[i]++;
                n /= i;
            }
        }
        if(n>1) freq[n]++;
        return;
    }
    void RemovePrimefactor(int n,unordered_map<int,int>&freq){
        for(int i=2;i*i<=n;i++){
            while(n%i==0){
                if(freq[i]==1) freq.erase(i);
                else freq[i]--;
                n /= i;
            }
        }
        if(n>1){
            if(freq[n]==1){
                freq.erase(n);
            }
            else{
                freq[n]--;
            }
        }
    }
    int longestSubarray(vector<int>& nums, int k) {
        int longestsubarray = 0;
        unordered_map<int,int>freq;
        int first = 0;
        int second = 0;
        while(second<nums.size()){
            InsertPrimefactor(nums[second],freq);
            if(freq.size()>k){
                while(first<=second && freq.size()>k){
                    RemovePrimefactor(nums[first],freq);
                    first++;
                }
            }
            if(freq.size()>0)
            longestsubarray = max(longestsubarray,second-first+1);
            second++;
        }
        return longestsubarray;
    }
};