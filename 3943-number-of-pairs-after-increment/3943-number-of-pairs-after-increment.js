/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @param {number[][]} queries
 * @return {number[]}
 */
var numberOfPairs = function(nums1, nums2, queries) {
    let n = nums2.length;
    let B = Math.floor(Math.sqrt(n));
    let blocks = Math.floor((n + B - 1) / B);

    let lazy = Array(blocks).fill(0);
    let m = Array.from({ length: blocks }, () => new Map());

    let i = 0;
    while (i < n) {
        let b = Math.floor(i / B);
        m[b].set(nums2[i], (m[b].get(nums2[i]) || 0) + 1);
        i++;
    }

    let ans = [];

    for (let it of queries) {
        if (it[0] === 1) {
            let x = it[1];
            let y = it[2];
            let val = it[3];

            let start = Math.floor(x / B);
            let end = Math.floor(y / B);

            if (start === end) {
                i = x;
                while (i <= y) {
                    let b = Math.floor(i / B);

                    m[b].set(nums2[i], m[b].get(nums2[i]) - 1);

                    nums2[i] += val;

                    m[b].set(nums2[i], (m[b].get(nums2[i]) || 0) + 1);
                    i++;
                }
            } else {
                i = x;
                while (i < (start + 1) * B) {
                    let b = Math.floor(i / B);

                    m[b].set(nums2[i], m[b].get(nums2[i]) - 1);

                    nums2[i] += val;

                    m[b].set(nums2[i], (m[b].get(nums2[i]) || 0) + 1);
                    i++;
                }

                i = start + 1;
                while (i < end) {
                    lazy[i] += val;
                    i++;
                }

                i = end * B;
                while (i <= y) {
                    let b = Math.floor(i / B);

                    m[b].set(nums2[i], m[b].get(nums2[i]) - 1);

                    nums2[i] += val;

                    m[b].set(nums2[i], (m[b].get(nums2[i]) || 0) + 1);
                    i++;
                }
            }
        } else {
            let tot = it[1];
            let cur = 0;

            i = 0;
            while (i < nums1.length) {
                let tar = tot - nums1[i];

                let b = 0;
                while (b < blocks) {
                    let req = tar - lazy[b];
                    cur += (m[b].get(req) || 0);
                    b++;
                }

                i++;
            }

            ans.push(cur);
        }
    }

    return ans;
};