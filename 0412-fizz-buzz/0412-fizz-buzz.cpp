class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string>nums(n);
        int index=0;
        for(int i=1;i<=n;i++){
            if(i%3==0 && i%5==0){
                nums[index++] = "FizzBuzz";
            }
            else if(i%3==0){
                nums[index++] = "Fizz";
            }
            else if(i%5==0){
                nums[index++] = "Buzz";
            }
            else{
                nums[index++] = to_string(i);
            }
        }
        return nums;
    }
};