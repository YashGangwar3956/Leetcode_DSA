class Solution(object):
    def minElement(self, nums):
        a=[]
        for i in nums:
            s=0
            while i>0:
                n=i%10
                s+=n
                i//=10
            a.append(s)  
        return min(a)