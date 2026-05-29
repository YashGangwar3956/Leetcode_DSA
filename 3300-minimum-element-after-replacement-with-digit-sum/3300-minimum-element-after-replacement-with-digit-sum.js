/**
 * @param {number[]} nums
 * @return {number}
 */
var minElement = function(nums) {
    const digitSum = (num) => {
        let sum = 0;
        while (num > 0) {
            sum += num % 10;
            num = Math.floor(num / 10);
        }
        return sum;
    };

    let minVal = Infinity;

    for (let num of nums) {
        minVal = Math.min(minVal, digitSum(num));
    }

    return minVal;
};