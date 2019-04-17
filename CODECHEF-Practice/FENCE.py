t=int(input())
for p in range(t):
    r,c,k=map(int,raw_input().split())
    l=set()
    list1=()
    a=4*k
    for i in range(k):
        list1=tuple(map(int,raw_input().split()))
        l.add(list1)
        list1=()
    for i in l:
        j=i[0]
        k=i[1]
        if (j+1,k) in l:
            a-=1
        if (j-1,k) in l:
            a-=1
        if (j,k-1) in l:
            a-=1
        if (j,k+1) in l:
            a-=1
    print a
