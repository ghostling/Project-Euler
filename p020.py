def Factorial(n):
    if n == 1:
        return 1
    else:
        return n * Factorial(n - 1)

digits = list(str(Factorial(100)))
answer = 0

for i in digits:
    answer += int(i)
print digits
print answer
