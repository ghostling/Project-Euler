f = open('p013.in', 'r')
lines = f.readlines()
chopped = []

length = len(lines[0])

for l in lines:
    chopped.append(int(l[:length]))

print sum(chopped)
