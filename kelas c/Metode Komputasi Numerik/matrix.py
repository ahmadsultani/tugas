import numpy as np

A = np.array([[1, 2], [3, 4]])

print(np.dot(A, A.T))
print(np.dot(A.T, A))
