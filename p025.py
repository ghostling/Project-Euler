
prev2 = 1
prev1 = 1
fibList = [1, 1]

def Fibby(prev1, prev2):
    nextFib = prev1 + prev2
    if(nextFib < 4000000):
        fibList.append(nextFib)
        Fibby(prev2, nextFib)

Fibby(prev1,prev2)
answer = sum(filter(lambda x: x % 2 ==0 , fibList))
