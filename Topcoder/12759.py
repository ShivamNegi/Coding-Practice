from itertools import permutations as pm

class LittleElephantAndPermutationDiv2:
    def fac(self, n):
        res = 1
        for i in xrange(2, n + 1):
            res = res * i
            res = res % (10 ** 9 + 9)
        return res

    def getNumber(self, N, K):
        # max_val = N * (N + 1) / 2
        fac_n = self.fac(N)
        res = 0
        for nos in pm(range(1, N + 1)):
            local = 0
            for (key, value) in enumerate(nos):
                if key + 1 > value:
                    local = local + key + 1
                else:
                    local = local + value
            if local >= K:
                res = (res + fac_n) % (10 ** 9 + 7)
        return res
