
long long maxAlternatingSum(int* nums, int numsSize){
    long long o = 0, e = 0;

    for(int i = 0; i < numsSize; i++){
        long long pe = e, po = o;

        e = pe > po + nums[i] ? pe : po + nums[i];
        o = po > pe - nums[i] ? po : pe - nums[i];
    }

    return e;
}

