def genEven(n):
    return n / 2

def genOdd(n):
    return (3*n) + 1

longest = 0
num = 0

for i in range(1, 1000001):
    chain = []
    icp = i
    while (icp != 1):
        if icp % 2 == 0:
            chain.append(genEven(icp))
        else:
            chain.append(genOdd(icp))
        icp = chain[-1]

    if len(chain) >= longest:
        longest = len(chain)
        num = i

print longest
print num
