for m in xrange(2,10000):
  for n in xrange(1,m):
    c = m**2 + n**2
    if c**.5 == int(c**.5):
       a = m**2 - n**2
       b = 2*m*n

       A = a*b /2.

       if A/6. == A/6 and A/28 == A/28.ç:
         print "bingo",m,n,a,b,c
       else:
         print "oops",m,n,a,b,c
