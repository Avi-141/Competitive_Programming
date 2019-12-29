from math import log
class Node(object):
   def __init__(self, start, end):
       self.start = start
       self.end = end
       self.total = 0
       self.left = None
       self.right = None

  class NumArray(object):
   def __init__(self, nums):
       def createTree(nums, l, r):
           if l > r:
               return None
           if l == r:
               n = Node(l, r)
               n.total = nums[l]
               return n
           mid = (l + r) // 2
           root = Node(l, r)
           root.left = createTree(nums, l, mid)
           root.right = createTree(nums, mid+1, r)
           root.total = root.left.total + root.right.total         
           return root
        self.root = createTree(nums, 0, len(nums)-1)

      def update(self, i, val):
       def updateVal(root, i, val):
           if root.start == root.end:
               root.total = val
               return val            mid = (root.start + root.end) // 2
           if i <= mid:
               updateVal(root.left, i, val)
           else:
               updateVal(root.right, i, val)
           root.total = root.left.total + root.right.total
           return root.total        return updateVal(self.root, i, val)   
      def sumRange(self, i, j):
       def rangeSum(root, i, j):
           if root.start == i and root.end == j:
               return root.total            mid = (root.start + root.end) // 2
           if j <= mid:
               return rangeSum(root.left, i, j)
           elif i >= mid + 1:
               return rangeSum(root.right, i, j)
           else:
            return rangeSum(root.left, i, mid) + rangeSum(root.right, mid+1, j)      
      return rangeSum(self.root, i, j)
  def solve(l,r):
   abs_min=abs(tree.sumRange(0,0)-tree.sumRange(1,n-1))
   min_pos=0
   while l <= r:
       mid =(l+r)/2
       if abs_min>abs(tree.sumRange(0,mid)-tree.sumRange(mid+1,n-1)):
           abs_min=abs(tree.sumRange(0,mid)-tree.sumRange(mid+1,n-1))
           min_pos=mid
       elif abs_min==abs(tree.sumRange(0,mid)-tree.sumRange(mid+1,n-1)):
           min_pos=min(mid,min_pos)
       if tree.sumRange(0,mid)-tree.sumRange(mid+1,n-1) < 0:
           l = mid + 1
       else:
           r = mid - 1
       #(min_pos,mid)
   #print('#################')
   return min_pos
n,q=map(int,raw_input().split())
arr=list(map(int,raw_input().split()))
new_arr=list((map(lambda x:log(x,10),arr)))
tree=NumArray(new_arr)
#print(tree.sumRange(0,4))
while q>0:
   q-=1
   query=list(map(int,raw_input().split()))
   if len(query)==3:
       tree.update(query[1]-1,new_arr[query[1]-1]+log(query[2],10))
       new_arr[query[1]-1]=new_arr[query[1]-1]+log(query[2],10)
   else:
       if n!=1:
           print(solve(0,n-1)+1)
       else:
           print(1)