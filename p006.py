# problem 6

numbers = range(1,101)

sumOfSquares = sum(map(lambda x: x*x, numbers))

squareOfSum = sum(numbers) * sum(numbers)

print "Sum of Squares: " + str(sumOfSquares)
print "Square of Sum: " + str(squareOfSum)

print "Answer: " + str(squareOfSum - sumOfSquares)
