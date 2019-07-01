def nextnum(num,num2):
    strnum=str(num)
    m = max(strnum)
    combos = []
    count=0
    count2=0
    pos=0
    n = min(strnum)
    for i in range(int(str(n) * len(strnum)), int(str(m) * len(strnum)) + 1):
         if sorted(str(i)) == sorted(strnum):
             if  i>num2:
                pos=i
                count=count+1
                combos.append(i)
                break
    if(len(combos)==0):
      return -1
    else :
      nexthighest = combos.index(pos)
      return combos[nexthighest]
   # print(combos)
  
    #if count>count2:
     # return -1
    #else : 
    #return(combos[nexthighest])

store=nextnum(273548,273548)
print(store)
store=nextnum(459,500)
print(store)
store=nextnum(2,27)
print(store)


