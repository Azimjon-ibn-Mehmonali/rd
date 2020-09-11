def matrix_mult(A, B):
	C = [[0, 0, 0], [0, 0, 0], [0, 0, 0]]
	for i in range(3):
		for j in range(3):
			for k in range(3):
				C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % 1000000007
	return C

def fast_exponentiation(A, n):
	if n <= 1:
		return A
	else:
		if n % 2 == 0:
		    A1 = fast_exponentiation(A, n/2)
		    return matrix_mult(A1, A1)
		else:
		    return matrix_mult(A, fast_exponentiation(A, n - 1))

def solve(n):
    A = [[1,2,3],[0,0,1],[0,1,0]]
    A_n = fast_exponentiation(A,n - 1)
	return A_n[0][0] + A_n[0][1] + A_n[0][2] * 2
	    
def f(n):
	if n < 4:
		return 1
	
	return f(n - 1) + 2 * f(n - 2) + 3 * f(n - 3)

#if __name__ == 'main':
for i in range(11):
	print(f(i), end=' ')
print('\n')
for i in range(11):
	print(solve(i), end=' ')