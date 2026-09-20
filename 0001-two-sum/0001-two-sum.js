/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    let index = 0
    let mp = new Map();
    for(const val of nums){
        const find = target - val;
        if(mp.has(find)){
            return [mp.get(find),index];
        }
        else mp.set(val,index);
        index++;
    }
    return [-1,-1];
};