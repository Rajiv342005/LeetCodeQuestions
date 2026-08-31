class Solution {
    public boolean uniqueOccurrences(int[] arr) {
        HashMap<Integer,Integer>freqTable = new HashMap<>();
        for(int i=0;i<arr.length;i++){
            if(freqTable.containsKey(arr[i])){
                freqTable.put(arr[i],freqTable.get(arr[i])+1);
            }
            else{
                freqTable.put(arr[i],1);
            }
        }
        HashMap<Integer,Integer>freq = new HashMap<>();
        for(Map.Entry<Integer,Integer> it: freqTable.entrySet()){
            if(freq.containsKey(it.getValue())) return false;
            else{
                freq.put(it.getValue(),100);
            }
        }
        return true;
    }
}