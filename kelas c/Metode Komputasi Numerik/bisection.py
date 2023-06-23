import math
# Modify the function below to fit your equation
# x as mass
def f(x):
  return math.cos(x)

errorTolerance = 0.1
lowerBound = float(input('Lower Bound: '))
upperBound = float(input('Upper Bound: '))

Ea = 1
iter = 1
mPrev = lowerBound

print(f'Lower bound guess: {lowerBound}')
print(f'Upper bound guess: {upperBound}')
print('='*(50+6))
print(f"\n| {'iterasi':^10}|{'lower':^10}|{'upper':^10}|{'m':^10}|{'Ea':^10}|\n")
print('='*(50+6))

while Ea > errorTolerance:
  fl = f(lowerBound)
  m = (lowerBound + upperBound) / 2
  fm = f(m)
  Ea = abs(m - mPrev)
  mPrev = m
  if (fl * fm) == 0:
      break
  elif (fl * fm) < 0:
    upperBound = m
  else:
    lowerBound = m
  print(f"\n| {iter:^10}|{lowerBound:^10.5f}|{upperBound:^10.5f}|{m:^10.5f}|{Ea:^10.5f}|\n")
  iter += 1
print('='*(50+6))
print(f'Root: {m:.5f}')
