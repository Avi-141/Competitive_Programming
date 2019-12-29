from math import floor
from fractions import Fraction
 
 
# References 
# [1] Computing Order Statistics in the Farey Sequence. Patrascu, C. and 
#     Patrascu, M.
#     http://citeseerx.ist.psu.edu/viewdoc/download?doi=10.1.1.208.718&rep=rep1&type=pdf
#
# [2] Editorial on "Farey Sequence" on csacademy.com
#     https://csacademy.com/contest/algorithms-2018-07-22-6/task/farey_sequence/solution/
#
# [3] Wikipedia page "Farey Sequence"
 
 
# From [1]:
# rank(x) = sum of A_q from q=1 to n
# where A_q = floor(x * q) - sum A_d for all d that are d<q and d|q
# (Formula 1 on p. 3)
# 
# Also from [1]:
# The section 3. Improving the Running Time implies that the use
# of dynamic programming can increase the speed of rank(x)
def rank(a, b, n):
    "Return the rank of the fraction x=a/b in F_n."
    A = [a * q // b for q in range(0, n+1)]
    for q in range(1, n+1):
        for i in range(q + q, n + 1, q):
            A[i] -= A[q]
    return sum(A)
 
 
# From [3]:
# Given the previous two terms a/b and c/d the next term in the
# Farey Sequence F_n is p/q where
# p = floor((n+b)/d)*c-a
# q = floor((n+b)/d)*d-b
def next_term(f1, f2, n):
    "Return next term in Farey Sequence F_n"
    t = (n + f1.denominator) // f2.denominator
    p = t * f2.numerator - f1.numerator
    q = t * f2.denominator - f1.denominator
    return Fraction(p, q)
 
 
def solve(n, k):
    
    if k == 1:
        return (0, 1)
    
    # A floating point error occurs when k is small relative to n.  
    # This causes the algorithm from [1] to fail.
    # All series begin with 0/1, 1/n, 1/(n-1), 1/(n-2), ...
    # This can be used to avoid this floating point error and failure.
    cutoff = n // 2
    if n % 2:
        cutoff += 1
    cutoff_posn = 2 + n - cutoff
    if k <= cutoff_posn:
        return (1, n - k + 2)
 
    # From [2]:
    # Determine a number X such that the answer is between X/n and X+1/n.
    # This can be done using a binary search in the range [1,n] where we
    # search for X/n with rank(X/n) < k and rank((X+1)/n) > k.
    # That is, the maximum mid with a rank less than k.
    low, high = 0, n
    X = 0
    R = 0
    while low < high:
        mid = (low + high) // 2
        r0 = rank(mid, n, n)
        # We are looking for the kth term. Rank returns the 
        # number of terms to the left of mid.  So, the kth
        # term will have a rank of k - 1.
        if r0 == k - 1:
            X = mid
            R = r0
            break
        if r0 > k - 1:
            high = mid - 1
        else:
            X = mid
            R = r0
            low = mid + 1
 
    # assert(rank(X, n, n) == R)
    x0 = Fraction(X, n)
    if R == k - 1:
        return (x0.numerator, x0.denominator)
 
    # From [2], Section 2, p. 3-4
    # There is at most one fraction in the interval [j/n, j+1/n] for any 
    # denominator less than n.  For any denominator q, the numerator must be:
    # floor(((j+1)*(q-1))/n).
    # Generate fractions in range using all possible denominators q < n
    # and retain the smallest fraction strictly greater than j/n.
    # We can then use the constant time algorithm to compute the next
    # fraction in the Farey Sequence from the previous two.
    j = X
    x1 = Fraction(1, 1)
    for q in range(1, n+1):
        p = ((j+1) * q - 1) // n
        g = Fraction(p, q)
        if g > x0:
            x1 = min(x1, g)
    
    # Given the previous previous fraction determined above as x0 with
    # a rank of R and the previous fraction prev_t, we can now just 
    # proceed through the terms until we reach the necessary rank
    if R == k:
        return (x1.numerator, x1.denominator)
    for _ in range(R + 2, k):
        x0, x1 = x1, next_term(x0, x1, n)
    return (x1.numerator, x1.denominator)
 
 
def main():
    "Main program."
    import sys
    n, k = (int(i) for i in sys.stdin.readline().split())
    soln = solve(n, k)
    print("{}/{}".format(*soln))
 
 
if __name__ == '__main__':
    main()