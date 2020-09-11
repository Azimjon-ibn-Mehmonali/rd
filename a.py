import math
n = int(input())

def mum(x, n):
    return x * (x + 1) // 2 >= n

d = 1000000000000000000
x = 0
while d > 0:
    while not mum(x + d, n):
       x += d
    d = d // 2

print(x + 1)
