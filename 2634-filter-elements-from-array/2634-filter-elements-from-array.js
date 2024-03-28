/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
    const a = []
    let idx =0;
    for(let i = 0  ; i < arr.length ; i++){
        if(fn(arr[i] , i)){
            a[idx] = arr[i]
            idx++
        }
    }
    return a
};