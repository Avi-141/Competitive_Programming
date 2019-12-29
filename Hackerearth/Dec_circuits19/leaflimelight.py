MOD=10**9+9

tc=int(input())
while tc:
	tc-=1
	n=int(input())
	res=0
	sum_n=n*(n+1)//2
	sumsquares=n*(2*n+1)*(n+1)//6
	dis1=sumsquares-sum_n+n
	dis2=0
	if n%2==1:
		dis2=sumsquares+(n-1)//2
		res=(dis2+dis1-1)%MOD
	else:
		dis2=sumsquares+n//2
		res=(dis2+dis1)%MOD
	#res=(dis2+dis1)%MOD
	print(res)
