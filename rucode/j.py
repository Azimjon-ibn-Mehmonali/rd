f = input()
q = list(f.split(','))
di = {}

for s in q:
    e, r = s.split(':')
    di[e] = int(r)

f = input()
q = list(f.split('|'))
jv = 1e18
for s in q:
    e = list(s.split('&'))
    
    h = -1
    for r in e:
        h = max(h, di[r])
    
    jv = min(jv, h)

print(jv)
