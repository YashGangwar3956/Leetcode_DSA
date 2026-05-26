/**
 * @param {string} word
 * @return {number}
 */
var numberOfSpecialChars = function(word) {
    const charArr = Array.from(new Set(word));
    let count = 0;

    for(let leftPointer = 0; leftPointer <= charArr.length - 1; leftPointer++) {
        if(charArr[leftPointer].charCodeAt(0) < 97) continue;
        if(charArr.includes(charArr[leftPointer].toUpperCase())) count++;
    }

    return count;
};