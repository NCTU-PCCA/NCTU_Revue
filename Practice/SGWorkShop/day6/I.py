def fpow(a, n):
    mod = 1000000007
    n %= mod - 1;
    ret = 1
    now = 2
    while n != 0:
        if n & 1:
            ret *= now
            ret %= mod
        now *= now
        now %= mod
        n >>= 1
    return ret

n = int(input())
print(fpow(2, n - 1))
