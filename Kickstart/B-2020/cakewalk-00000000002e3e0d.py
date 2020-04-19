import sys
readline = sys.stdin.readline
flush = sys.stdout.flush

import scipy.stats

T = int(readline().strip())

for t in range(1, T+1):
	W, H, L, U, R, D = [int(_) for _ in readline().split()]
	
	ans = 0.
	if D != H:
		#D downs before L-1 rights
		#D downs within D+L-2 tosses
		#>= D downs in D+L-2 tosses
		#<= L-2 rights in D+L-2 tosses
		
		ans += scipy.stats.binom.cdf(L-2, D+L-2, 0.5)
	
	if R != W:
		#R rights before U-1 downs
		#R rights within R+U-2 tosses
		#>= R rights in R+U-2 tosses
		#<= U-2 downs in R+U-2 tosses
		
		ans += scipy.stats.binom.cdf(U-2, R+U-2, 0.5)
		
	print("Case #%d: %f" % (t, ans))
