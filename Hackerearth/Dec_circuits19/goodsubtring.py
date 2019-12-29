n,k,m=map(int,input().split())
lst=list(input())
result=0
count=0

for i in range(0,k):
	if lst[i]=='1':
		count+=1
		if count<=m:
			continue
		else:
			count=m
			lst[i]='0'
			result+=1

for i in range(1,n-k+1):
	if lst[i-1]=='1':
		count-=1
	if lst[k+i-1]=='1':
		count+=1
		if count>m:
			count=m
			lst[k+i-1]='0'
			result+=1

strs="".join(lst)
print(result)
print(strs)