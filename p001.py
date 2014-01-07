## Python 3

answer = sum(filter(lambda x: x % 3 == 0 or x % 5 == 0, list(range(1000))))

print("The answer is %d" % answer)
