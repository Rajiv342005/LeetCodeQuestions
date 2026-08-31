class Solution {
    public boolean containsDuplicate(int[] nums) {
        HashMap<Integer,Integer>freqMap = new HashMap<>();
        for(int i=0;i<nums.length;i++){
            if(freqMap.containsKey(nums[i])) return true;
            freqMap.put(nums[i],1);
        }
        return false;
    }
}