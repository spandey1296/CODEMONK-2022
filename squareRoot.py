# Python program to find square root of a number .
# for ex if input number is 4 then output will be 2 .

def findSquareRoot(n):
  lowerbound=0
  upperbound=n
  ans=-1
  while lowerbound<=upperbound:
    middle=(lowerbound+upperbound)//2
    square=middle*middle
    if square==n:
      return middle
    elif square<n:
      ans=middle
      lowerbound=middle+1
    else:
      upperbound=middle-1
  return ans

ans = findSquareRoot(5)
print(ans)