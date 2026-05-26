class Solution(object):
    def numberOfSpecialChars(self, word):
        x=[]
        for i in word:
            x.append(i)
        y=set(x)
        z=list(y)
        a=0
        for i in z:
            if i.swapcase() in x:
                a+=1
        return a//2
        