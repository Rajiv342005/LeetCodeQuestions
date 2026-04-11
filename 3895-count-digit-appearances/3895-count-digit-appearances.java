class Solution {
    public int countDigitOccurrences(int[] nums, int digit) {
        int n = nums.length;
        int count = 0;
        for(int i = 0; i < n; i++){
            while(nums[i] > 0){
                int rem = nums[i] % 10;
                if(rem == digit){
                    count++;
                }
                nums[i] /= 10;
            }
        }
        return count;
    }
}