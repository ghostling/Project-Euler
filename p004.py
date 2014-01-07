
## Python 3
numbers = list(range(100,1000))
products = []
palindromes = []

def IsPalindrome(n):
    _n = str(n)
    return _n == _n[::-1]

for i in numbers:
    j = 0
    while(j < len(numbers)):
        products.append(i*numbers[j])
        j += 1

for k in products:
   if IsPalindrome(k):
      palindromes.append(k)

palindromes.sort()
print("The largest palindrome made from the product of two 3-digit numbers is %d" % palindromes[-1])
