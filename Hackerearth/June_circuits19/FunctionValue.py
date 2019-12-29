import sys
sys.setrecursionlimit(100000)
 
# define f recursively -> f1
memoize = {1:1, 2:1}
def f1(n):
    if n not in memoize:
        if n % 2 == 1:
            solution = 3 * f1(n - 2)
        else:
            solution = 2 * f1(n - 1) - f1(n - 2) + 2
        memoize[n] = solution
    return memoize[n]
 
# define f analytically -> f2
def f2(n):
    if n % 2 == 1:
        u = 3 ** (n // 2)
    else:
        if (n // 2) % 2 == 0:
            # n = 4*m
            '''
            u = 0
            for i in range(n // 2):
                u += ((-1) ** (i + 1)) * (3 ** i)
            u = 2 * u + 3
            '''
            m = n // 4
            u = (3 ** (2 * m) + 5) // 2
        else:
            # n = 4*m + 1
            '''
            u = 0
            for i in range(i // 2):
                u += ((-1) ** i) * (3 ** i)
            u = 2 * u - 1
            '''
            m = n // 4
            u = (3 ** (2 * m + 1) - 1) // 2
    return u
 
# clean version of f2 -> f3
def f3(n):
    m = n // 2
    if n % 2 == 1:
        # n = 4*k + 1 or n = 4*k + 3
        u = 3 ** m
    else:
        if m % 2 == 0:
            # n = 4*k (so m = 2*k)
            u = (3 ** m + 5) // 2
        else:
            # n = 4*k + 2 (so m = 2*k + 1)
            u = (3 ** m - 1) // 2
    return u
 
# check that it works...
def check():
    for i in range(1, 10):
        print (i, f3(i), f1(i) - f3(i))
    print()

 
def f(n, P):
    m = n // 2
    if n % 2 == 1:
        #u = 3 ** m
        u = pow(3, m, P)
    else:
        if m % 2 == 0:
            #u = (3 ** m + 5) // 2
            u = (pow(3, m, 2 * P) + 5) // 2
        else:
            #u = (3 ** m - 1) // 2
            u = (pow(3, m, 2 * P) - 1) // 2
    return u % P
 
def sumf(N, P):
    # sum of full blocks of 4:
    # 4*k+1, 4*k+2, 4*k+3, 4*k+4
    # for k in 0...N//4-1
    if N == 0:
        return 0
    n = N // 4 - 1
    if n >= 0:
        '''
        # sum of 4*k + 1 and 4*k + 3 (<= 4*n+4)
        sum1 = (9 ** (n + 1) - 1) // 2
        # sum of 4*k + 2 (<= 4*n+4)
        sum2 = (3 * 9 ** (n + 1) - 8 * n - 11) // 16
        # sum of 4*k+4 (<= 4*n+4)
        sum3 = (9 ** (n + 2) + 40 * n + 31) // 16
        sum1 = sum1 + sum2 + sum3
        '''
        #sum1 = (20 * 9 ** (n + 1) + 32 * n + 12) // 16
        sum1 = (20 * pow(9, n + 1, 16 * P) + 32 * n + 12) // 16
    else:
        sum1 = 0
    # sum from 4*n+5 to N
    sum2 = 0
    for i in range(4 * n + 5, N + 1):
        sum2 += f(i, P)
    return (sum1 + sum2) % P
 
def solve(L, R, P):
    return (sumf(R, P) + P - sumf(L - 1, P)) % P
 
if __name__ == "__main__":
    #check()
    T, P = list(map(int, input().strip().split()))
    for problem in range(1, T + 1):
        L, R = list(map(int, input().strip().split()))
        print(solve(L, R, P))