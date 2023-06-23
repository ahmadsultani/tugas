import numpy as np

a = np.array([[2, 1],
              [1, 1]])

# check reducible
p = a@a
print(p)

w, v = np.linalg.eig(a)
print('E-value:', w)
print('E-vector')
print(v)
