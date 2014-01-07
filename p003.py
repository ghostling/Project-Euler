import math
## Python 3

def FindFactors(n):
    i = 2
    factors = []
    while( i <= math.pow(n, 0.5) ):
        if( n % i == 0 ):
            factors.append(i)
            factors.append(n//i)
        i += 1
    return factors

def PrimeFactorFinder(factors):
    primeFactors = []
    for j in factors:
        if(len(FindFactors(j)) == 0):
            primeFactors.append(j)
    return primeFactors


allF = FindFactors(600851475143)
primes = PrimeFactorFinder(allF)

#print("The prime factors are: ")
#print(primes)
print("The highest prime factor is %d" % primes[-1])
