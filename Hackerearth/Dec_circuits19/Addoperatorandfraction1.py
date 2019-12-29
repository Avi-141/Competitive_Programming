
n, k = map(int,input().split())
     
stk = [((0, 1), (1, 2))]
     
if k == 1:
    print('0/1')
    stk = None
else:
    k = k -1
while stk:
    s0, t0 = stk.pop()
    a = s0[0] + t0[0]
    b = s0[1] + t0[1]
    pairs = (a, b)
    if b <= n:
        stk.append((pairs, t0))    
        stk.append((s0, pairs))
    else:
    #    print(t0)
        k = k - 1
    if k == 0:
        print('{}/{}'.format(t0[0], t0[1]))
        break