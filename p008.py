#problem 8

f = open('./p008.txt', 'r')
f = f.read().replace("\n", "")

digits = []

for i in f:
    digits.append(int(i))

j = 0
MAX = 1

while j < len(digits):
    m = reduce(lambda x,y: x*y, digits[j:j+5])
    if m > MAX:
        MAX = m
    j += 1

print MAX
