class Solution:
    def minOperations(self, nums: List[int]) -> int:
        n=len(nums)
        if n==1:
            return 0
        ind=nums.index(0)
        front=True
        back=True
        for i in range(1,n):
            if (nums[(ind+i)%n]!=i):
                front=False
                break
        for i in range(1,n):
            if(nums[(ind-i+n)%n]!=i):
                back=False
                break
        if not front and not back:
            return -1
        res=100000
        if front:
            if ind==0:
                res=0
            else:
                res=min(res,ind,n-ind+2)
        if back:
            res=min(res,n-ind,ind+2)
        return res