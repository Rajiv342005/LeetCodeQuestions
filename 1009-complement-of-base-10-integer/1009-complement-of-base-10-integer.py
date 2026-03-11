class Solution:
    def bitwiseComplement(self, n: int) -> int:
        if n==0:
            return 1
        counter = 0
        exp = 0
        while n>0:
            rem = n%2
            if rem==0:
                counter += 2**exp
            n = n//2
            exp+=1
        return counter
        