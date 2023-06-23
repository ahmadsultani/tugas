import numpy as np

A = np.array([[1, 9, 81],
              [1, 6, 36],
              [1, 12, 144]],
              dtype=float)

B = np.array([174, 236, 308])

n = A.shape[0] # banyaknya ordo matriks A

U = np.copy(A)
# mengubah matriks A menjadi matriks segitiga atas U
for i in range(n):
    # Lakukan operasi baris elemenator untuk membuat 0 di bawah diagonal utama
    for j in range(i+1, n):
        m = U[j,i] / U[i,i]
        U[j,:] = U[j,:] - m*U[i,:]
print(U)

L = np.copy(A)
# mengubah matriks A menjadi matriks segitiga bawah L
for i in range(n-1, -1, -1):
        if L[i][i] != 1:
            div = L[i][i]
            for j in range(i+1):
                L[i][j] /= div
        for k in range(i-1, -1, -1):
            if L[k][i] != 0:
                factor = L[k][i]
                for j in range(i, -1, -1):
                    L[k][j] -= factor * L[i][j]
print(L)


# L y = B
y0 = B[0] / L[0][0]
y1 = (B[1] - L[1][0] * y0) / L[1][1]
y2 = (B[2] - L[2][0] * y0 - L[2][1] * y1) / L[2][2]

# U a = y
a2 = y2 / U[2][2]
a1 = (y1 - L[1][2] * a2) / L[1][1]
a0 = (y0 - L[0][1] * a1 - L[0][2] * a2) / L[0][0]


# persamaan v(t)
def v(t):
    return a0 + a1*t + a2*t**2

# hubungan antara kecepatan dan waktu dalam rentang 6-12 detik
for t in range(6, 13):
    print(f"kecepatan pada t={t} detik: {v(t)} m/s")
