from sys import maxsize

def kadane(arr,n,i,j):
	max_so_far=0
	max_end=0
	for it in range(n):
		curr=it
		if it>=i-1 and it < j:
			curr=j-it + i-2
		max_end+=arr[curr]
		if max_end<0:
			max_end=0
		elif max_so_far<max_end:
			max_so_far=max_end
	return max_so_far



if __name__=="__main__":
	#inp=(int,input().split(" "))
	n,q=map(int,input().split(" "))
	arr=list(map(int,input().split(" ")))
	maxx=max(arr)
	minn=min(arr)

	for _ in range(q):
		L,R=map(int,input().split(" "))
		if maxx<=0:
			print(maxx)
		elif minn>=0:
			print(sum(arr))
		else:
			print(kadane(arr,n,L,R))
