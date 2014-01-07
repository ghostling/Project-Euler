from p005 import primeFac

primes = []

i = 1

while len(primes) < 10001:
    if len(primeFac(i)) == 1:
        primes.append(i)
    i += 1

print primes[-1]
