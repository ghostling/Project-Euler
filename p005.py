## Python 2.7

## Problem 5:
## 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
## What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?


# Idea: Loop from 1 to 20 and add them to a list of uniques if they aren't divisisble by anything already in that list

import math

bucket = []
numbers = range(20,0,-1)

def primeFac(X):
    i = 2.0
    while i <= X:
        if X % i == 0:
            X /= i
            factors.append(i)
        else:
            i += 1
    return factors

for i in numbers:
    fac = primeFac(i)
    for j in fac:
        times = fac.count(j) - bucket.count(j)
        while times > 0:
            bucket.append(j)
            times -= 1
result = 1.0

for i in bucket:
    result *= i

print result
