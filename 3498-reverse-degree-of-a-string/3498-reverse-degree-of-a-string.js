/**
 * @param {string} s
 * @return {number}
 */
var reverseDegree = function(s) {
    let degree = 0;
    let index = 1;
    for(const ch of s){
        const contribute = 26 - (ch.charCodeAt(0)-97);
        degree += contribute*index;
        index = index+1;
    }
    return degree;
    
};