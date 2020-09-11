x, k, d = map(int, input().split())

ax = abs(x)
t = k * d

if t == ax:
    print(0)
elif t < ax:
    print(ax - t)
else:
    a = ax % d
    b = d - a
    f = ax // d

    if k % 2 == f % 2:
        print(a)
    else:
        print(b)
